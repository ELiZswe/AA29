// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_Javelin/Pickup_Javelin_LF_CLU/Pickup_Javelin_LF_CLU.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/Javelin_LF_CLU/Javelin_LF_CLU.h"

APickup_Javelin_LF_CLU::APickup_Javelin_LF_CLU()
{
	InventoryType	= AJavelin_LF_CLU::StaticClass();
	Rotation		= FRotator(0, -90, 0);
}
