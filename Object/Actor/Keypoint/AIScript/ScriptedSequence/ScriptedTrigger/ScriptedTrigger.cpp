// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedTrigger/ScriptedTrigger.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedTriggerController/ScriptedTriggerController.h"
#include "AA29/Object/ScriptedAction/ACTION_TriggerEvent/ACTION_TriggerEvent.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_WAITFOREVENT/Action_WAITFOREVENT.h"

AScriptedTrigger::AScriptedTrigger(const FObjectInitializer& objectInitializer)	: Super(objectInitializer)
{
	bNavigate = false;
	//Texture = Texture'GamePlay.S_SpecialEvent';
}

void AScriptedTrigger::PostBeginPlay()
{
	/*
	PostBeginPlay();
	TriggerController = Spawn('ScriptedTriggerController');
	if (TriggerController != nullptr)
	{
		TriggerController.InitializeFor(this);
	}
	else
	{
		Log("ScriptedTrigger::PostBeginPlay - Couldn't Spawn ScriptedTriggerController");
	}
	*/
}

FName AScriptedTrigger::NextNeededEvent()
{
	/*
	int32 i = 0;
	int32 Start;
	if (TriggerController != nullptr)
	{
		Start = TriggerController.ActionNum;
	}
	for (i = Start; i < Actions.Num(); i++)
	{
		if (Cast<UAction_WAITFOREVENT>(Actions[i]) != nullptr)
		{
			return Action_WAITFOREVENT(Actions[i]).ExternalEvent;
		}
	}
	*/
	return "None";
}

bool AScriptedTrigger::TriggersEvent(FName E)
{
	/*
	int32 i = 0;
	int32 Start;
	if (TriggerController != nullptr)
	{
		Start = TriggerController.ActionNum;
	}
	for (i = Start; i < Actions.Num(); i++)
	{
		if (Cast<UACTION_TriggerEvent>(Actions[i]) != nullptr && ACTION_TriggerEvent(Actions[i]).Event == E)
		{
			return true;
		}
	}
	*/
	return false;
}

bool AScriptedTrigger::ValidAction(int32 N)
{
	return Actions[N]->bValidForTrigger;
}

void AScriptedTrigger::Reset()
{
	/*
	Super::Reset();
	if (TriggerController == nullptr)
	{
		TriggerController = Spawn('ScriptedTriggerController');
	}
	if (TriggerController != nullptr)
	{
		TriggerController.InitializeFor(this);
	}
	*/
}
