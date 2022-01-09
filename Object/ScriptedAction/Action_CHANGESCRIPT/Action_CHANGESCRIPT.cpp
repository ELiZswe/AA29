// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_CHANGESCRIPT/Action_CHANGESCRIPT.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"

UAction_CHANGESCRIPT::UAction_CHANGESCRIPT()
{
	ActionString = "Change script";
	bValidForTrigger = false;
}

AScriptedSequence* UAction_CHANGESCRIPT::GetScript(AScriptedSequence* S)
{
	/*
	if (NextScript == nullptr && NextScriptTag != "None")
	{
		ForEach S.AllActors('ScriptedSequence', NextScript, NextScriptTag)
		{
		}
		if (NextScript == nullptr)
		{
			Warn("No Next script found for " $ Self $ " in " $ S);
			return S;
		}
	}
	*/
	return NextScript;
}
bool UAction_CHANGESCRIPT::InitActionFor(AScriptedController* C)
{
	//C.bBroken = true;
	return true;
}
