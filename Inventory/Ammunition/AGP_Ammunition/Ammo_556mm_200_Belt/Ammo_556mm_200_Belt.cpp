// All the original content belonged to the US Army


#include "Ammo_556mm_200_Belt.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage556mm_SAW.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_556mm_200_Belt.h"
AAmmo_556mm_200_Belt::AAmmo_556mm_200_Belt()
{
	_iTracerCount   = 5;
	MaxAmmo         = 200;
	AmmoAmount      = 200;
	MyDamageType    = UProjectileDamage556mm_SAW::StaticClass();
	PickupClass     = APickupAmmo_556mm_200_Belt::StaticClass();
	_bLarge         = false;
	fWeight         = 2;
	IconMaterial    = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m249_01.hud_ammo_m249_01"), NULL, LOAD_None, NULL);
	ItemName        = FString("M249 200-shot box");
}