// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_DESTROYPAWN/Action_DESTROYPAWN.h"

UAction_DESTROYPAWN::UAction_DESTROYPAWN()
{
	ActionString = "destroy pawn";
	bValidForTrigger = false;
}



bool UAction_DESTROYPAWN::InitActionFor(UScriptedController* C)
{
	//C.DestroyPawn();
	return true;
}