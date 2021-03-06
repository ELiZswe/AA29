// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_12gauge_7_Rounds/Ammo_12gauge_7_Rounds.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762Sniper.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_12gauge_7_Rounds.h"
AAmmo_12gauge_7_Rounds::AAmmo_12gauge_7_Rounds()
{
	MomentumTransfer	= 20000;
	MaxAmmo				= 7;
	AmmoAmount			= 7;
	MyDamageType		= UProjectileDamage762Sniper::StaticClass();
	PickupClass			= APickupAmmo_12gauge_7_Rounds::StaticClass();
	_bLarge				= false;
	fWeight				= 0.5;
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m870_01_Mat.hud_ammo_m870_01_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= "7 Rounds for the M870";
}
