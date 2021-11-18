// All the original content belonged to the US Army


#include "Ammo_762mm_30_Mag.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762mm.h"
#include "AA29/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_762mm_30_Mag.h"

AAmmo_762mm_30_Mag::AAmmo_762mm_30_Mag()
{
	Damage        = 45;
	MaxAmmo       = 30;
	AmmoAmount    = 30;
	MyDamageType  = UProjectileDamage762mm::StaticClass();
	PickupClass   = APickupAmmo_762mm_30_Mag::StaticClass();
	_bLarge       = false;
	fWeight       = 0.5;
	IconMaterial  = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_ak47_01.hud_ammo_ak47_01"), NULL, LOAD_None, NULL);
	ItemName      = FString("AK-47 30-shot banana clip");
}