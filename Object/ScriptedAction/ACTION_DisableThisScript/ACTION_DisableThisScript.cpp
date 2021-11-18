// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_DisableThisScript/ACTION_DisableThisScript.h"

UACTION_DisableThisScript::UACTION_DisableThisScript()
{
	ActionString = "disable this script";
}


bool UACTION_DisableThisScript::InitActionFor(UScriptedController* C)
{
	/*
	if (AGP_ScriptedSequence(C.SequenceScript) != None)
	{
		AGP_ScriptedSequence(C.SequenceScript).bDisabled = true;
	}
	*/
	return false;
}