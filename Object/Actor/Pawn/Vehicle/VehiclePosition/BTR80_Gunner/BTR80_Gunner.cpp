// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/BTR80_Gunner/BTR80_Gunner.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

ABTR80_Gunner::ABTR80_Gunner()
{
	//GunClass = class'AGP_Vehicles.BTR80_Turret';
	bDrawDriverInTP = false;
	BaseEyeHeight = 100;
}

AVehicle* ABTR80_Gunner::FindEntryVehicle(APawn* p)
{
	return nullptr;
}

bool ABTR80_Gunner::TryToDrive(APawn* p)
{
	/*
	if (HumanController(p.Controller) != nullptr)
	{
		return false;
	}
	else
	{
		return TryToDrive(p);
	}
	*/

	return false;     //FAKE   /ELiZ
}
