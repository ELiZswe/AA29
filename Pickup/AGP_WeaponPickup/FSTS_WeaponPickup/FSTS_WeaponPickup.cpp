// All the original content belonged to the US Army


#include "FSTS_WeaponPickup.h"
AFSTS_WeaponPickup::AFSTS_WeaponPickup()
{
	bAllowPickup			= true;
	PickupAmmo				= -1;
	LandedRotationOffset	= FRotator(0, 0, 0);
	bUseActionIcon			= true;
	ActionIcon				= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_UI/HUD/T_UI_HUD_USE_ICON.T_UI_HUD_USE_ICON"), NULL, LOAD_None, NULL);
}



void AFSTS_WeaponPickup::SetAllowPickup(bool bAllow)
{
	bAllowPickup = bAllow;
	bUseActionIcon = bAllow;
}
void AFSTS_WeaponPickup::SetupCopy(AInventory* Copy, APawn* Other)
{
	/*
	if (AGP_Weapon(Copy) != None && PickupAmmo >= 0)
	{
		AGP_Weapon(Copy).PickupAmmoCount = PickupAmmo;
	}
	*/
}
