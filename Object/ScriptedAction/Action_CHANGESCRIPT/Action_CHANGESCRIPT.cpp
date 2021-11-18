// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_CHANGESCRIPT/Action_CHANGESCRIPT.h"

UAction_CHANGESCRIPT::UAction_CHANGESCRIPT()
{
	ActionString = "Change script";
	bValidForTrigger = false;
}

AScriptedSequence* UAction_CHANGESCRIPT::GetScript(AScriptedSequence* S)
{
	/*
	if (NextScript == None && NextScriptTag != 'None')
	{
		ForEach S.AllActors('ScriptedSequence', NextScript, NextScriptTag)
		{
		}
		if (NextScript == None)
		{
			Warn("No Next script found for " $ Self $ " in " $ S);
			Return S;
		}
	}
	*/
	return NextScript;
}
bool UAction_CHANGESCRIPT::InitActionFor(UScriptedController* C)
{
	//C.bBroken = true;
	return true;
}