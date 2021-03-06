// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_ActivateCROWS/ACTION_ActivateCROWS.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/VehicleWeapon/CROWS_Base/CROWS_Base.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/CROWS_Gunner/CROWS_Gunner.h"

UACTION_ActivateCROWS::UACTION_ActivateCROWS()
{
	ActionString = "Activate CROWS";
}

bool UACTION_ActivateCROWS::InitActionFor(AScriptedController* C)
{
	if (Cast<ACROWS_Gunner>(C->GetPawn()) != nullptr)
	{
		Cast<ACROWS_Gunner>(C->GetPawn())->ActivateCrows();
	}
	Cast<ACROWS_Base>(Cast<ACROWS_Gunner>(C->GetPawn())->Gun)->HideGun(false);
	return true;
}
