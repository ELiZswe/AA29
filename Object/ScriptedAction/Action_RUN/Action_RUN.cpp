// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/Action_RUN/Action_RUN.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_RUN::UAction_RUN()
{
	ActionString = "Run";
	bValidForTrigger = false;
}

bool UAction_RUN::InitActionFor(AScriptedController* C)
{
	//C.Pawn.ShouldCrouch(false);
	//C.Pawn.SetWalking(false);
	return false;
}
