// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/BTR80_Gunner/BTR80_Gunner.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/VehicleWeapon/BTR80_Turret/BTR80_Turret.h"

ABTR80_Gunner::ABTR80_Gunner()
{
	//GunClass = ABTR80_Turret::StaticClass();
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
	if (Cast<AHumanController>(p->Controller) != nullptr)
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
