// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/ACTION_StartCROWSVehicle/ACTION_StartCROWSVehicle.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UACTION_StartCROWSVehicle::UACTION_StartCROWSVehicle()
{
	DesiredSpeed = 200;
	MaxDesiredSpeed = 450;
	ActionString = "Start CROWS Vehicle";
}

bool UACTION_StartCROWSVehicle::InitActionFor(AScriptedController* C)
{
	/*
	if (CROWS_HMMWV(C.Pawn) != nullptr)
	{
		CROWS_HMMWV(C.Pawn).Ignition();
		CROWS_HMMWV(C.Pawn).Shifter = 1;
		CROWS_HMMWV(C.Pawn).bIsInHighGear = false;
		if (Vehicle(C.Pawn).Driver == nullptr)
		{
			Vehicle(C.Pawn).Driver = C.Pawn;
		}
		C.Pawn.DesiredSpeed = DesiredSpeed;
		C.Pawn.MaxDesiredSpeed = MaxDesiredSpeed;
	}
	*/
	return true;
}
