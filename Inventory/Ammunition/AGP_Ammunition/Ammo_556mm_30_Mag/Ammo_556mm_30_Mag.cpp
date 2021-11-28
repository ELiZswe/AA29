// All the original content belonged to the US Army


#include "Ammo_556mm_30_Mag.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage556mm.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_556mm_30_Mag.h"




AAmmo_556mm_30_Mag::AAmmo_556mm_30_Mag()
{
	MaxAmmo       = 30;
	AmmoAmount    = 30;
	MyDamageType  = UProjectileDamage556mm::StaticClass();
	PickupClass   = APickupAmmo_556mm_30_Mag::StaticClass();
	_bLarge       = false;
	fWeight       = 0.5;
	IconMaterial  = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m16_01.hud_ammo_m16_01"), NULL, LOAD_None, NULL);
	ItemName      = FString("M16 30-shot clip");
}