// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehicleTrigger/NPCVehicle_Trigger/NPCVehicle_Trigger.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBasePreCrewedVehicleController/NPCBasePreCrewedVehicleControlle.h"

ANPCVehicle_Trigger::ANPCVehicle_Trigger()
{
	//bHidden = true;
}

void ANPCVehicle_Trigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	AAGP_Vehicle* CurrentVehicle = nullptr;
	APawn* p = nullptr;
	/*
	Log(string(this) $ " AGPVehicle Trigger triggered");
	ForEach AllActors(Class'Pawn', p)
	{
		if (p->isA(AAGP_Vehicle::StaticClass()) && (p.Tag == VehicleTag))
		{
			Log(string(this) $ " Match found for " $ string(p));
			if ((p.Health > 0) && (Cast<ANPCBasePreCrewedVehicleControlle>(p.Controller) != nullptr))
			{
				Log(string(this) $ " CurrentVehicle is now " $ string(p));
				CurrentVehicle = Cast<AAGP_Vehicle>(p);
				NPCBasePreCrewedVehicleController(p.Controller).ForcedDestinationDelay = MoveDelay;
				NPCBasePreCrewedVehicleController(p.Controller).ForceMoveTo(DestinationTag);
			}
		}
	}
	*/
}
