// All the original content belonged to the US Army


#include "Ammo_762mm_5_Rounds.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762Sniper.h"
#include "AA29/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_762mm_5_Rounds.h"
AAmmo_762mm_5_Rounds::AAmmo_762mm_5_Rounds()
{
	Damage            = 70;
	MomentumTransfer  = 20000;
	MaxAmmo           = 5;
	AmmoAmount        = 5;
	MyDamageType      = UProjectileDamage762Sniper::StaticClass();
	PickupClass       = APickupAmmo_762mm_5_Rounds::StaticClass();
	_bLarge           = false;
	fWeight           = 0.5;
	IconMaterial      = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m24_01.hud_ammo_m24_01"), NULL, LOAD_None, NULL);
	ItemName          = FString("5 Rounds for the M24");
}