// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedTrigger/ScriptedTrigger.h"

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
void AScriptedTrigger::NextNeededEvent()
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
			Return Action_WAITFOREVENT(Actions[i]).ExternalEvent;
		}
	}
	Return 'None';
	*/
}
void AScriptedTrigger::TriggersEvent(FName E)
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
			Return True;
		}
	}
	Return False;
	*/
}
void AScriptedTrigger::ValidAction(int32 N)
{
	//Return Actions[N].bValidForTrigger;
}
void AScriptedTrigger::Reset()
{
	/*
	Super::Reset();
	if (TriggerController == None)
	{
		TriggerController = Spawn('ScriptedTriggerController');
	}
	if (TriggerController != None)
	{
		TriggerController.InitializeFor(Self);
	}
	*/
}