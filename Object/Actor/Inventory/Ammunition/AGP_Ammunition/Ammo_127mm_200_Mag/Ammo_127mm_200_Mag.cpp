// All the original content belonged to the US Army


#include "Ammo_127mm_200_Mag.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage127HMG.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_127mm_200_Mag.h"
AAmmo_127mm_200_Mag::AAmmo_127mm_200_Mag()
{
	Damage            = 200;
	MomentumTransfer  = 20000;
	_iTracerCount     = 4;
	MaxAmmo           = 200;
	AmmoAmount        = 200;
	MyDamageType      = UProjectileDamage127HMG::StaticClass();
	PickupClass       = APickupAmmo_127mm_200_Mag::StaticClass();
	_bLarge           = false;
	fWeight           = 0.5;
	IconMaterial      = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m82a1_01.hud_ammo_m82a1_01"), NULL, LOAD_None, NULL);
	ItemName          = FString("M2 Ammo Box");
}