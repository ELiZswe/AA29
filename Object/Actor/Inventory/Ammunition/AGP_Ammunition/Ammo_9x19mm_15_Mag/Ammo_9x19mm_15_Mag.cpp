// All the original content belonged to the US Army


#include "Ammo_9x19mm_15_Mag.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_9x19mm_15_Mag.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage9x19mm.h"
AAmmo_9x19mm_15_Mag::AAmmo_9x19mm_15_Mag()
{
	MaxAmmo       = 15;
	AmmoAmount    = 15;
	MyDamageType  = UProjectileDamage9x19mm::StaticClass();
	PickupClass   = APickupAmmo_9x19mm_15_Mag::StaticClass();
	_bLarge       = false;
	fWeight       = 0.5;
	IconMaterial  = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m9.hud_ammo_m9"), NULL, LOAD_None, NULL);
	ItemName      = FString("M9 15-shot magazine");
}