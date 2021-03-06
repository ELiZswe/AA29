// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_5_Rounds/Ammo_762mm_5_Rounds.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762Sniper.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_762mm_5_Rounds.h"
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
	IconMaterial = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m24_01_Mat.hud_ammo_m24_01_Mat'"), NULL, LOAD_None, NULL);
	ItemName          = FString("5 Rounds for the M24");
}
