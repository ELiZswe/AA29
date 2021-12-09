// All the original content belonged to the US Army


#include "FSTS_Weapon_M9_Pistol.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/PickupW_FSTS_Trainer_M9_Pistol/PickupW_FSTS_Trainer_M9_Pistol.h"

AFSTS_Weapon_M9_Pistol::AFSTS_Weapon_M9_Pistol()
{
	iMisFire     = 0;
	PickupClass  = APickupW_FSTS_Trainer_M9_Pistol::StaticClass();
}