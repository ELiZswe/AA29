// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_CROUCH/Action_CROUCH.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_CROUCH::UAction_CROUCH()
{
	ActionString = "crouch";
	bValidForTrigger = false;
}

bool UAction_CROUCH::InitActionFor(AScriptedController* C)
{
	//C.Pawn.ShouldCrouch(true);
	return false;
}
