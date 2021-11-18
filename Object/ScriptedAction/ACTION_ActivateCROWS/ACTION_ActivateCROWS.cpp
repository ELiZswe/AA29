// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_ActivateCROWS/ACTION_ActivateCROWS.h"

UACTION_ActivateCROWS::UACTION_ActivateCROWS()
{
	ActionString = "Activate CROWS";
}

bool UACTION_ActivateCROWS::InitActionFor(UScriptedController* C)
{
	/*
	if (CROWS_Gunner(C.Pawn) != None)
	{
		CROWS_Gunner(C.Pawn).ActivateCrows();
	}
	CROWS_Base(CROWS_Gunner(C.Pawn).Gun).HideGun(False);
	*/
	return true;
}