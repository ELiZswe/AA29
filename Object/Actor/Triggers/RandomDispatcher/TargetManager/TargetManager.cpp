// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/RandomDispatcher/TargetManager/TargetManager.h"
#include "AA29/Object/Actor/ScoreKeeper/ScoreKeeper.h"

ATargetManager::ATargetManager()
{
	TargetGroupLabel.SetNum(8);
	TargetGroupLabel = { "","" ,"" ,"" ,"" ,"" ,"" ,"" };
}

bool ATargetManager::isActivelyTesting()
{
	return bActive && !bTargetPractice;
}

void ATargetManager::BeginPlay()
{
	UWorld* const World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();
		_ScoreKeeper = World->SpawnActor<AScoreKeeper>(AScoreKeeper::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	}
	for (i = 0; i < TargetGroupLabel.Num(); i++) 
	{
		_ScoreKeeper->setGroupLabel(i, TargetGroupLabel[i]);
	}
	_ScoreKeeper->SetLabel(TargetScoreLabel);
	Super::BeginPlay();
}

void ATargetManager::Trigger(AActor* Other, APawn* EventInstigator)
{
	bActive = true;
	if (bTargetPractice)
	{
		StartPractice();
	}
	else
	{
		StartDispatch();
		Super::Trigger(Other, EventInstigator);
	}
}

void ATargetManager::UnTrigger(AActor* Other, APawn* EventInstigator)
{
	bActive = false;
	if (bTargetPractice)
	{
		EndPractice();
	}
	else
	{
		//if (GetStateName() == 'Dispatch')
		//{
		//	EndDispatch();
		//}
	}
}

void ATargetManager::SetTargetPractice(bool new_practice)
{
	bTargetPractice = new_practice;
	if (bTargetPractice == false)
	{
		EndPractice();
	}
}

AScoreKeeper* ATargetManager::getScoreKeeper()
{
	return _ScoreKeeper;
}

void ATargetManager::DispatchComplete()
{
	/*
	if (_Target != nullptr)
	{
		_Target->Notify();
	}
	if (EventLab != nullptr)
	{
		EventLab->ActorNotify(this, 29);
	}
	*/
	_ScoreKeeper->printTargetGroups();
	bActive = false;
}

void ATargetManager::ResetScores()
{
	_ScoreKeeper->ResetScores();
}

void ATargetManager::StartDispatch()
{
	ResetScores();
	bSkipTargets = false;
}

void ATargetManager::EndDispatch()
{
	int32 total = 0;
	int32 Index = 0;
	/*
	if (iTotalPending > 0)
	{
		doPending();
	}
	bSkipTargets = true;
	for (total = 0; total < iTotalAvailable; total++)
	{
		for (Index = 0; Index < AvailableCounter[total]; Index++)
		{
			TriggerEvent(AvailableEvent[total], this, Instigator);
		}
		AvailableCounter[total] = 0;
	}
	bSkipTargets = false;
	DispatchComplete();
	*/
}
void ATargetManager::StartPractice()
{
	int32 Index = 0;
	FName currentevent = "";
	/*
	for (Index = 0; Index < 32; Index++)
	{
		currentevent = EventList[Index].Event;
		if (currentevent == "None" || currentevent == "None")
		{
		}
		if (EventList[Index].Counter > 0)
		{
			TriggerEvent(currentevent, this, Instigator);
		}
	}
	*/
}

void ATargetManager::EndPractice()
{
	int32 Index = 0;
	FName currentevent = "";
	bTargetPractice = false;
	/*
	for (Index = 0; Index < 32; Index++)
	{
		currentevent = EventList[Index].Event;
		if (currentevent == "None" || currentevent == "None")
		{
		}
		UntriggerEvent(currentevent, this, Instigator);
		Log("TargetManager::EndPractice()	UnTrigger " + currentevent);
	}
	bActive = false;
	*/
}
bool ATargetManager::groupNotUsed(int32 group_number)
{
	if (group_number < 0 || group_number > 7)
	{
		return true;
	}
	return false;
}
void ATargetManager::ReportTargetUp(int32 group_number)
{
	if (groupNotUsed(group_number))
	{
		return;
	}
	_ScoreKeeper->incrementTotal(group_number);
}
void ATargetManager::ReportTargetDown(int32 group_number, bool bShot)
{
	if (groupNotUsed(group_number))
	{
		return;
	}
	if (bShot)
	{
		_ScoreKeeper->incrementShot(group_number);
	}
	else
	{
		_ScoreKeeper->incrementMissed(group_number);
	}
}
void ATargetManager::ReportTargetSkipped(int32 group_number)
{
	if (groupNotUsed(group_number))
	{
		return;
	}
	_ScoreKeeper->incrementTotal(group_number);
	_ScoreKeeper->incrementMissed(group_number);
}
