// All the original content belonged to the US Army


#include "Ammo_12gauge_7_Rounds.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762Sniper.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_12gauge_7_Rounds.h"
AAmmo_12gauge_7_Rounds::AAmmo_12gauge_7_Rounds()
{
	MomentumTransfer  = 20000;
	MaxAmmo           = 7;
	AmmoAmount        = 7;
	MyDamageType      = UProjectileDamage762Sniper::StaticClass();
	PickupClass       = APickupAmmo_12gauge_7_Rounds::StaticClass();
	_bLarge           = false;
	fWeight           = 0.5;
	IconMaterial      = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m870_01.hud_ammo_m870_01"), NULL, LOAD_None, NULL);
	ItemName          = FString("7 Rounds for the M870");
}