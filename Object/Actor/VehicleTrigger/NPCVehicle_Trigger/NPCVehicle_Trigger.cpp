// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleTrigger/NPCVehicle_Trigger/NPCVehicle_Trigger.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"

ANPCVehicle_Trigger::ANPCVehicle_Trigger()
{
	//bHidden = true;
}

void Trigger(AActor* Other, APawn* EventInstigator)
{
	AAGP_Vehicle* CurrentVehicle = nullptr;
	APawn* p = nullptr;
	/*
	Log(string(Self) $ " AGPVehicle Trigger triggered");
	ForEach AllActors(Class'Pawn', p)
	{
		if (p.IsA("AGP_Vehicle") && (p.Tag == VehicleTag))
		{
			Log(string(Self) $ " Match found for " $ string(p));
			if ((p.Health > 0) && (NPCBasePreCrewedVehicleController(p.Controller) != nullptr))
			{
				Log(string(Self) $ " CurrentVehicle is now " $ string(p));
				CurrentVehicle = AGP_Vehicle(p);
				NPCBasePreCrewedVehicleController(p.Controller).ForcedDestinationDelay = MoveDelay;
				NPCBasePreCrewedVehicleController(p.Controller).ForceMoveTo(DestinationTag);
			}
		}
	}
	*/
}
