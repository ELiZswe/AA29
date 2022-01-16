// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/T62_MainGunner/T62_MainGunner.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/VehicleWeapon/T62_Turret/T62_Turret.h"

AT62_MainGunner::AT62_MainGunner()
{
	//GunClass = AT62_Turret::StaticClass();
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
	if (Cast<AHumanController>(p->Controller) != nullptr)
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
