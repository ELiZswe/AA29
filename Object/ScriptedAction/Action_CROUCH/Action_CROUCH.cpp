// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_CROUCH/Action_CROUCH.h"

UAction_CROUCH::UAction_CROUCH()
{
	ActionString = "crouch";
	bValidForTrigger = false;
}

bool UAction_CROUCH::InitActionFor(UScriptedController* C)
{
	//C.Pawn.ShouldCrouch(True);
	return false;
}