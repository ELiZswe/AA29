// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/SequenceManager/SequenceManager.h"
#include "AA29/Object/Actor/Triggers/Trigger/SequenceTrigger/SequenceTrigger.h"
#include "AA29/Object/ScriptObject/ScriptObject.h"

ASequenceManager::ASequenceManager()
{
	bSequenceInitiallyActive = true;
}

void ASequenceManager::PostBeginPlay()
{
	ASequenceTrigger* S = nullptr;
	ASequenceTrigger* Last = nullptr;
	bool bFoundStart = false;
	bool bFoundFinish = false;
	/*
	ForEach DynamicActors(ASequenceTrigger::StaticClass(), S, SequenceTag)
	{
		if (S.bStart)
		{
			bFoundStart = true;
		}
		if (S.bFinish)
		{
			bFoundFinish = true;
		}
		S.SetManager(this);
		if (_list == nullptr)
		{
			_list = S;
		}
		else
		{
			Last.nextInList = S;
		}
		Last = S;
	}
	*/
	if ((!bFoundStart) || (!bFoundFinish))
	{
		//DebugLog(DEBUG_Warn, "SequenceManager::PostBeginPlay()	This sequence failed to find both a start and finish! " + FString::FromInt(this) @ FString::FromInt(SequenceTag) @ FString::FromInt(bFoundStart) @ FString::FromInt(bFoundFinish));
	}
	if (!bSequenceInitiallyActive)
	{
		DisableSequence();
	}
}

void ASequenceManager::EnableSequence()
{
	ASequenceTrigger* S = nullptr;
	for (S = _list; S != nullptr; S = S->nextInList)
	{
		S->Activate();
	}
}

void ASequenceManager::DisableSequence()
{
	ASequenceTrigger* S = nullptr;
	for (S = _list; S != nullptr; S = S->nextInList)
	{
		S->Deactivate();
	}
}

void ASequenceManager::SetOutOfOrderMonitor(UScriptObject* mon)
{
	_OutOfOrderMonitor = mon;
}

void ASequenceManager::SetInOrderMonitor(UScriptObject* mon)
{
	_InOrderMonitor = mon;
}

void ASequenceManager::SetStartMonitor(UScriptObject* mon)
{
	_StartMonitor = mon;
}

void ASequenceManager::SetFinishMonitor(UScriptObject* mon)
{
	_FinishMonitor = mon;
}

void ASequenceManager::SequenceStart(ASequenceTrigger* starter, APawn* aInstigator)
{
	//TriggerEvent(Event_ManagerStart, this, aInstigator);
	if (_StartMonitor != nullptr)
	{
		_StartMonitor->Notify();
	}
}

void ASequenceManager::SequenceFinish(ASequenceTrigger* finisher, APawn* aInstigator)
{
	//TriggerEvent(Event_ManagerFinish, this, aInstigator);
	if (_FinishMonitor != nullptr)
	{
		_FinishMonitor->Notify();
	}
}

void ASequenceManager::SequenceOutOfOrder(ASequenceTrigger* outoforder, APawn* aInstigator)
{
	//TriggerEvent(Event_ManagerOutOfOrder, this, aInstigator);
	if (_OutOfOrderMonitor != nullptr)
	{
		_OutOfOrderMonitor->Notify();
	}
}

void ASequenceManager::SequenceInOrder(ASequenceTrigger* outoforder, APawn* aInstigator)
{
	//TriggerEvent(Event_ManagerInOrder, this, aInstigator);
	if (_InOrderMonitor != nullptr)
	{
		_InOrderMonitor->Notify();
	}
}
