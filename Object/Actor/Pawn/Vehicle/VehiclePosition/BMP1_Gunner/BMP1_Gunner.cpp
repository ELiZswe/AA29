// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/BMP1_Gunner/BMP1_Gunner.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

ABMP1_Gunner::ABMP1_Gunner()
{
	//GunClass = class'AGP_Vehicles.BMP1_Turret';
	bDrawDriverInTP = false;
}

AVehicle* ABMP1_Gunner::FindEntryVehicle(APawn* p)
{
	return nullptr;
}

bool ABMP1_Gunner::TryToDrive(APawn* p)
{
	/*
	if (HumanController(p.Controller) != nullptr)
	{
		return false;
	}
	else
	{
		return Super::TryToDrive(p);
	}
	*/
	return false;    //FAKE   /ELiZ
}
