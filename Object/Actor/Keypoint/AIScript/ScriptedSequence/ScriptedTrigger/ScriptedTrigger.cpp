// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedTrigger/ScriptedTrigger.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"

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
	if (TriggerController != None)
	{
		TriggerController.InitializeFor(Self);
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
	local int i;
	local int Start;
	if (TriggerController != None)
	{
		Start = TriggerController.ActionNum;
	}
	for (i = Start; i < Actions.Length; i++)
	{
		if (Action_WAITFOREVENT(Actions[i]) != None)
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
	local int i;
	local int Start;
	if (TriggerController != None)
	{
		Start = TriggerController.ActionNum;
	}
	for (i = Start; i < Actions.Length; i++)
	{
		if (ACTION_TriggerEvent(Actions[i]) != None && ACTION_TriggerEvent(Actions[i]).Event == E)
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
	if (TriggerController != None)
	{
		TriggerController.InitializeFor(Self);
	}
	*/
}