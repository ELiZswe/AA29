// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_KeepCurrentRotation/ACTION_KeepCurrentRotation.h"

UACTION_KeepCurrentRotation::UACTION_KeepCurrentRotation()
{
	ActionString = "keep current rotation";
}


bool UACTION_KeepCurrentRotation::InitActionFor(UScriptedController* C)
{
	//C.bUseScriptFacing = False;
	return false;
}