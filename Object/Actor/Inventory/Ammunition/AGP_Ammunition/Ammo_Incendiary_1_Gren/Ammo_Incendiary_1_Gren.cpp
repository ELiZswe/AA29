// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_Incendiary_1_Gren/Ammo_Incendiary_1_Gren.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_IncendiaryGren/Proj_IncendiaryGren.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_Incendiary_1_Gren.h"

AAmmo_Incendiary_1_Gren::AAmmo_Incendiary_1_Gren()
{
	Damage				= 0;
	MomentumTransfer	= 20000;
	MaxAmmo				= 1;
	AmmoAmount			= 1;
	bInstantHit			= false;
	ProjectileClass		= AProj_IncendiaryGren::StaticClass();
	MyDamageType		= nullptr;
	PickupClass			= APickupAmmo_Incendiary_1_Gren::StaticClass();
	_bLarge				= false;
	fWeight				= 0.5;
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_gren_incendiary_01_Mat.hud_gren_incendiary_01_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= "Incendiary Grenade";
}
