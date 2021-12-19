// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/BMP1_Gunner/BMP1_Gunner.h"

ABMP1_Gunner::ABMP1_Gunner()
{
	//GunClass = class'AGP_Vehicles.BMP1_Turret';
	bDrawDriverInTP = false;
}

void ABMP1_Gunner::FindEntryVehicle(APawn* p)
{
	//Return None;
}

void ABMP1_Gunner::TryToDrive(APawn* p)
{
	/*
	if (HumanController(p.Controller) != None)
	{
		return false;
	}
	else
	{
		return TryToDrive(p);
	}
	*/
}