// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_ChargeCROWS/ACTION_ChargeCROWS.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_ChargeCROWS::UACTION_ChargeCROWS()
{
	ActionString = "Charge CROWS";
}

bool UACTION_ChargeCROWS::InitActionFor(AScriptedController* C)
{
	/*
	if (CROWS_Gunner(C.Pawn) != nullptr)
	{
		CROWS_Gunner(C.Pawn).ChargeWeapon();
	}
	*/
	return true;
}
