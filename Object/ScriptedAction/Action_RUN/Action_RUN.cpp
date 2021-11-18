// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/Action_RUN/Action_RUN.h"

UAction_RUN::UAction_RUN()
{
	ActionString = "Run";
	bValidForTrigger = false;
}

bool UAction_RUN::InitActionFor(UScriptedController* C)
{
	//C.Pawn.ShouldCrouch(False);
	//C.Pawn.SetWalking(False);
	return false;
}