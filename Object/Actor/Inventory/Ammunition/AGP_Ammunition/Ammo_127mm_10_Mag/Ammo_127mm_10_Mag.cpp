// All the original content belonged to the US Army

#include "Ammo_127mm_10_Mag.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage127Sniper.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_127mm_10_Mag.h"

AAmmo_127mm_10_Mag::AAmmo_127mm_10_Mag()
{
	Damage				= 100;
	MomentumTransfer	= 20000;
	MaxAmmo				= 10;
	AmmoAmount			= 10;
	MyDamageType		= UProjectileDamage127Sniper::StaticClass();
	PickupClass			= APickupAmmo_127mm_10_Mag::StaticClass();
	_bLarge				= false;
	fWeight				= 0.5;
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m82a1_01_Mat.hud_ammo_m82a1_01_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= "Barrett Clip";
}
