// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_WALK/Action_WALK.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_WALK::UAction_WALK()
{
	ActionString = "walk";
	bValidForTrigger = false;
}

bool UAction_WALK::InitActionFor(AScriptedController* C)
{
	/*
	C.Pawn.ShouldCrouch(false);
	C.Pawn.SetWalking(true);
	*/
	return false;
}
