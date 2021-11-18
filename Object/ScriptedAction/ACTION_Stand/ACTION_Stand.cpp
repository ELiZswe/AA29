// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_Stand/ACTION_Stand.h"

UACTION_Stand::UACTION_Stand()
{
	ActionString = "Stand";
	bValidForTrigger = false;
}

bool UACTION_Stand::InitActionFor(UScriptedController* C)
{
	//C.Pawn.ShouldStand(True);
	return false;
}