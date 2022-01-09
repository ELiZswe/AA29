// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_DisableThisScript/ACTION_DisableThisScript.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_DisableThisScript::UACTION_DisableThisScript()
{
	ActionString = "disable this script";
}

bool UACTION_DisableThisScript::InitActionFor(AScriptedController* C)
{
	/*
	if (AGP_ScriptedSequence(C.SequenceScript) != nullptr)
	{
		AGP_ScriptedSequence(C.SequenceScript).bDisabled = true;
	}
	*/
	return false;
}
