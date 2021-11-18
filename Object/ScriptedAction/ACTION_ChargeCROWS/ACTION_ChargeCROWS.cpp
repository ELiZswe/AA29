// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/ACTION_ChargeCROWS/ACTION_ChargeCROWS.h"

UACTION_ChargeCROWS::UACTION_ChargeCROWS()
{
	ActionString = "Charge CROWS";
}


bool UACTION_ChargeCROWS::InitActionFor(UScriptedController* C)
{
	/*
	if (CROWS_Gunner(C.Pawn) != None)
	{
		CROWS_Gunner(C.Pawn).ChargeWeapon();
	}
	*/
	return true;
}