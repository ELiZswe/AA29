// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/BTR80_Gunner/BTR80_Gunner.h"

ABTR80_Gunner::ABTR80_Gunner()
{
	//GunClass = class'AGP_Vehicles.BTR80_Turret';
	bDrawDriverInTP = false;
	BaseEyeHeight = 100;
}




void ABTR80_Gunner::FindEntryVehicle(APawn* p)
{
	//Return None;
}

bool ABTR80_Gunner::TryToDrive(APawn* p)
{
	/*
	if (HumanController(p.Controller) != None)
	{
		Return False;
	}
	else
	{
		Return TryToDrive(p);
	}
	*/

	return false;     //FAKE   /ELiZ
}