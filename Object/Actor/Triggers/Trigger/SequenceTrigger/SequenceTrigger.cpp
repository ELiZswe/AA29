// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Trigger/SequenceTrigger/SequenceTrigger.h"
#include "AA29/Object/Actor/Triggers/SequenceManager/SequenceManager.h"

ASequenceTrigger::ASequenceTrigger()
{
	Sequence_Next = -1;
	bUseManagerFlags = true;
}

void ASequenceTrigger::PostBeginPlay()
{
	PreBeginPlay();
	if (bStart && bFinish)
	{
		//DebugLog(DEBUG_Warn, "SequenceTrigger::PreBeginPlay()	Found a SequenceTrigger with bStart=true AND bFinish=true" @ string(Tag) @ string(SequenceNumber));
	}
	if (Sequence_Next == -1)
	{
		Sequence_Next = (SequenceNumber + 1);
	}
	ResetTrigger();
}

void ASequenceTrigger::ResetTrigger()
{
	//DebugLog(DEBUG_Trig, "SequenceTrigger::ResetTrigger()	" @ string(Tag) @ string(SequenceNumber));
	bOutOfOrder = (!bStart);
	bActive = bStart;
	bCurrent = false;
}

void ASequenceTrigger::doFinish()
{
	//DebugLog(DEBUG_Trig, "SequenceTrigger::doFinish()" @ string(Tag) @ string(SequenceNumber));
	if (bFlag_ResetWhenFinished)
	{
		ResetTrigger();
	}
	if (bFlag_TurnOffWhenFinished)
	{
		bActive = false;
	}
}

void ASequenceTrigger::doOutOfOrder()
{
	//DebugLog(DEBUG_Trig, "SequenceTrigger::doOutOfOrder()" @ string(Tag) @ string(SequenceNumber));
	if (bFlag_ResetWhenOutOfOrder)
	{
		ResetTrigger();
	}
}

bool ASequenceTrigger::exist(FName N)
{
	return ((N != "None") && (N != "None"));
}

void ASequenceTrigger::DoTouch(AActor* Other)
{
	/*
	Super::DoTouch(Other);
	DebugLog(DEBUG_Trig, "SequenceTrigger::DoTouch()	----------------------- " $ string(this) @ string(SequenceNumber));
	if (bCurrent || (!bActive))
	{
		return;
	}
	DebugLog(DEBUG_Trig, "SequenceTrigger::DoTouch()	Got touched " $ string(this) @ string(SequenceNumber) @ string(bStart) @ string(bFinish) @ string(bOutOfOrder));
	TriggerEvent(Tag, this, nullptr);
	if (bOutOfOrder)
	{
		DebugLog(DEBUG_Trig, "SequenceTrigger::DoTouch()	OUT OF ORDER" @ string(Tag) @ string(SequenceNumber));
		ReportToManager(2, Other.Instigator);
		doOutOfOrder();
		TriggerEvent(Event_OutOfOrder, Other, Other.Instigator);
		return;
	}
	ReportToManager(3, Other.Instigator);
	TriggerEvent(Event_InOrder, Other, Other.Instigator);
	if (bFinish)
	{
		ReportToManager(1, Other.Instigator);
		doFinish();
		TriggerEvent(Event_Finish, Other, Other.Instigator);
		DebugLog(DEBUG_Trig, "SequenceTrigger::DoTouch()	FINISH" @ string(Tag) @ string(SequenceNumber));
	}
	else
	{
		if (bStart)
		{
			ReportToManager(0, Other.Instigator);
			TriggerEvent(Event_Start, Other, Other.Instigator);
			DebugLog(DEBUG_Trig, "SequenceTrigger::DoTouch()	START" @ string(Tag) @ string(SequenceNumber));
		}
	}
	*/
	bCurrent = true;
	bOutOfOrder = true;
}

void ASequenceTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	ASequenceTrigger* trig = nullptr;
	trig = Cast<ASequenceTrigger>(Other);
	if ((trig == nullptr) || (trig == this))
	{
		return;
	}
	if (trig->bOutOfOrder)
	{
		doOutOfOrder();
		return;
	}
	bCurrent = false;
	if (trig->bStart)
	{
		bActive = true;
	}
	if (trig->bFinish)
	{
		doFinish();
	}
	else
	{
		if (SequenceNumber == trig->Sequence_Next)
		{
			//DebugLog(DEBUG_Trig, "SequenceTrigger::Trigger()	Turning on " $ string(this) @ string(SequenceNumber));
			bOutOfOrder = false;
		}
		else
		{
			if (SequenceNumber == trig->SequenceNumber)
			{
				//DebugLog(DEBUG_Trig, "SequenceTrigger::Trigger()	Turning off " $ string(this) @ string(SequenceNumber));
				bOutOfOrder = true;
			}
		}
	}
}

void ASequenceTrigger::Activate()
{
	//DebugLog(DEBUG_Trig, "SequenceTrigger::Activate()	" @ string(Tag) @ string(SequenceNumber));
	ResetTrigger();
}

void ASequenceTrigger::Deactivate()
{
	//DebugLog(DEBUG_Trig, "SequenceTrigger::DeActivate()	" @ string(Tag) @ string(SequenceNumber));
	bActive = false;
}

void ASequenceTrigger::SetManager(ASequenceManager* new_manager)
{
	my_manager = new_manager;
	if (bUseManagerFlags)
	{
		bFlag_ResetWhenOutOfOrder = my_manager->bFlag_ResetWhenOutOfOrder;
		bFlag_ResetWhenFinished = my_manager->bFlag_ResetWhenFinished;
		bFlag_TurnOffWhenFinished = my_manager->bFlag_TurnOffWhenFinished;
	}
}

void ASequenceTrigger::ReportToManager(ESequenceStep Step, APawn* aInstigator)
{
	if (my_manager == nullptr)
	{
		return;
	}
	switch (Step)
	{
		case ESequenceStep::SEQUENCE_Start:
			my_manager->SequenceStart(this, aInstigator);
			break;
		case ESequenceStep::SEQUENCE_Finish:
			my_manager->SequenceFinish(this, aInstigator);
			break;
		case ESequenceStep::SEQUENCE_OutOfOrder:
			my_manager->SequenceOutOfOrder(this, aInstigator);
			break;
		case ESequenceStep::SEQUENCE_InOrder:
			my_manager->SequenceInOrder(this, aInstigator);
			break;
		default:
			break;
	}
}
