// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/LatentScriptedAction/ACTION_Freeze/ACTION_Freeze.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_Freeze::UACTION_Freeze()
{
	ActionString = "Freeze";
}

bool UACTION_Freeze::InitActionFor(AScriptedController* C)
{
	/*
	if (C.Pawn != nullptr)
	{
		C.Pawn.bPhysicsAnimUpdate = false;
		C.Pawn.StopAnimating();
		C.Pawn.SetPhysics(0);
	}
	C.CurrentAction = this;
	*/
	return true;
}
