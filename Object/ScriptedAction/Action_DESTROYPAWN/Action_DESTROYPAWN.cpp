// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_DESTROYPAWN/Action_DESTROYPAWN.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_DESTROYPAWN::UAction_DESTROYPAWN()
{
	ActionString = "destroy pawn";
	bValidForTrigger = false;
}

bool UAction_DESTROYPAWN::InitActionFor(AScriptedController* C)
{
	//C.DestroyPawn();
	return true;
}
