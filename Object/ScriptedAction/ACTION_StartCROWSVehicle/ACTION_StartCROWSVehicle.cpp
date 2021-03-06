// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_StartCROWSVehicle/ACTION_StartCROWSVehicle.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/CROWS_HMMWV/CROWS_HMMWV.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

UACTION_StartCROWSVehicle::UACTION_StartCROWSVehicle()
{
	DesiredSpeed = 200;
	MaxDesiredSpeed = 450;
	ActionString = "Start CROWS Vehicle";
}

bool UACTION_StartCROWSVehicle::InitActionFor(AScriptedController* C)
{
	if (Cast<ACROWS_HMMWV>(C->GetPawn()) != nullptr)
	{
		Cast<ACROWS_HMMWV>(C->GetPawn())->Ignition();
		Cast<ACROWS_HMMWV>(C->GetPawn())->Shifter = EeShifterState::SS_Drive;
		Cast<ACROWS_HMMWV>(C->GetPawn())->bIsInHighGear = false;
		/*
		if (Cast<AVehicle>(C->GetPawn())->Driver == nullptr)
		{
			Cast<AVehicle>(C->GetPawn())->Driver = C->GetPawn();
		}
		C->GetPawn()->DesiredSpeed = DesiredSpeed;
		C->GetPawn()->MaxDesiredSpeed = MaxDesiredSpeed;
		*/
	}
	return true;
}
