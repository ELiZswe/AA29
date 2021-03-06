// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/FSTS_WeaponPickup/FSTS_WeaponPickup.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
AFSTS_WeaponPickup::AFSTS_WeaponPickup()
{
	bAllowPickup			= true;
	PickupAmmo				= -1;
	LandedRotationOffset	= FRotator(0, 0, 0);
	bUseActionIcon			= true;
	ActionIcon				= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_UI/HUD/T_UI_HUD_USE_ICON.T_UI_HUD_USE_ICON"), NULL, LOAD_None, NULL);
}

/*
auto State Pickup
{
	Function bool ReadyToPickup(float MaxWait)
	{
		return bAllowPickup;
	}
}
*/

void AFSTS_WeaponPickup::SetAllowPickup(bool bAllow)
{
	bAllowPickup = bAllow;
	bUseActionIcon = bAllow;
}

void AFSTS_WeaponPickup::SetupCopy(AInventory* Copy, APawn* Other)
{
	/*
	if (Cast<AAGP_Weapon>(Copy) != nullptr && PickupAmmo >= 0)
	{
		Cast<AAGP_Weapon>(Copy).PickupAmmoCount = PickupAmmo;
	}
	*/
}
