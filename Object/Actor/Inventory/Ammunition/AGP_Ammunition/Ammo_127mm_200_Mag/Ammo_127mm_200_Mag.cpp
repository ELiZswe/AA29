// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_127mm_200_Mag/Ammo_127mm_200_Mag.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage127HMG.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_127mm_200_Mag.h"
AAmmo_127mm_200_Mag::AAmmo_127mm_200_Mag()
{
	Damage				= 200;
	MomentumTransfer	= 20000;
	_iTracerCount		= 4;
	MaxAmmo				= 200;
	AmmoAmount			= 200;
	MyDamageType		= UProjectileDamage127HMG::StaticClass();
	PickupClass			= APickupAmmo_127mm_200_Mag::StaticClass();
	_bLarge				= false;
	fWeight				= 0.5;
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m82a1_01_Mat.hud_ammo_m82a1_01_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= "M2 Ammo Box";
}
