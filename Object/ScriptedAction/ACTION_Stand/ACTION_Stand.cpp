// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_Stand/ACTION_Stand.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_Stand::UACTION_Stand()
{
	ActionString = "Stand";
	bValidForTrigger = false;
}

bool UACTION_Stand::InitActionFor(AScriptedController* C)
{
	//C.Pawn.ShouldStand(true);
	return false;
}
