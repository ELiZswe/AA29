// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/T62_MainGunner/T62_MainGunner.h"

AT62_MainGunner::AT62_MainGunner()
{
	//GunClass = class'AGP_Vehicles.T62_Turret';
	bDrawDriverInTP = false;
	BaseEyeHeight = 130;
}

AVehicle* AT62_MainGunner::FindEntryVehicle(APawn* p)
{
	return nullptr;
}

bool AT62_MainGunner::TryToDrive(APawn* p)
{
	/*
	if (HumanController(p.Controller) != None)
	{
		return false;
	}
	else
	{
		return Super::TryToDrive(p);
	}
	*/

	return false;     //FAKE    /ELiZ
}
