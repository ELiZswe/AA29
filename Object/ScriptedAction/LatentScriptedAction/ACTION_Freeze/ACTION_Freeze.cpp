// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/LatentScriptedAction/ACTION_Freeze/ACTION_Freeze.h"

UACTION_Freeze::UACTION_Freeze()
{
	ActionString = "Freeze";
}


bool UACTION_Freeze::InitActionFor(UScriptedController* C)
{
	/*
	if (C.Pawn != None)
	{
		C.Pawn.bPhysicsAnimUpdate = False;
		C.Pawn.StopAnimating();
		C.Pawn.SetPhysics(0);
	}
	C.CurrentAction = Self;
	*/
	return true;
}