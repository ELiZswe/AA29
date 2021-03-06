// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_ChargeCROWS/ACTION_ChargeCROWS.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/CROWS_Gunner/CROWS_Gunner.h"

UACTION_ChargeCROWS::UACTION_ChargeCROWS()
{
	ActionString = "Charge CROWS";
}

bool UACTION_ChargeCROWS::InitActionFor(AScriptedController* C)
{
	if (Cast<ACROWS_Gunner>(C->GetPawn()) != nullptr)
	{
		Cast<ACROWS_Gunner>(C->GetPawn())->ChargeWeapon();
	}
	return true;
}
