// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_KeepCurrentRotation/ACTION_KeepCurrentRotation.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_KeepCurrentRotation::UACTION_KeepCurrentRotation()
{
	ActionString = "keep current rotation";
}

bool UACTION_KeepCurrentRotation::InitActionFor(AScriptedController* C)
{
	//C.bUseScriptFacing = false;
	return false;
}
