// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_ActivateCROWS/ACTION_ActivateCROWS.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_ActivateCROWS::UACTION_ActivateCROWS()
{
	ActionString = "Activate CROWS";
}

bool UACTION_ActivateCROWS::InitActionFor(AScriptedController* C)
{
	/*
	if (CROWS_Gunner(C.Pawn) != nullptr)
	{
		CROWS_Gunner(C.Pawn).ActivateCrows();
	}
	CROWS_Base(CROWS_Gunner(C.Pawn).Gun).HideGun(false);
	*/
	return true;
}
