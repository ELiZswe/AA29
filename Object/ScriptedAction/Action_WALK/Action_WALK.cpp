// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_WALK/Action_WALK.h"

UAction_WALK::UAction_WALK()
{
	ActionString = "walk";
	bValidForTrigger = false;
}

bool UAction_WALK::InitActionFor(UScriptedController* C)
{
	/*
	C.Pawn.ShouldCrouch(False);
	C.Pawn.SetWalking(True);
	*/
	return false;
}