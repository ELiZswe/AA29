// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/BMP1_Gunner/BMP1_Gunner.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/VehicleWeapon/BMP1_Turret/BMP1_Turret.h"

ABMP1_Gunner::ABMP1_Gunner()
{
	//GunClass = ABMP1_Turret::StaticClass();
	bDrawDriverInTP = false;
}

AVehicle* ABMP1_Gunner::FindEntryVehicle(APawn* p)
{
	return nullptr;
}

bool ABMP1_Gunner::TryToDrive(APawn* p)
{
	/*
	if (Cast<AHumanController>(p->Controller) != nullptr)
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
