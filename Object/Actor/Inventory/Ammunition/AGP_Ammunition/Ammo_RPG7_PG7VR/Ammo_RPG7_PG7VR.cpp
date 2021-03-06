// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_RPG7_PG7VR/Ammo_RPG7_PG7VR.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_30Gren/Proj_30Gren.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_RPG7_PG7VR.h"

AAmmo_RPG7_PG7VR::AAmmo_RPG7_PG7VR()
{
	Damage				= 90;
	MomentumTransfer	= 20000;
	MaxAmmo				= 1;
	AmmoAmount			= 1;
	bInstantHit			= false;
	ProjectileClass		= AProj_30Gren::StaticClass();
	MyDamageType		= UProjectileDamageLargeArms::StaticClass();
	PickupClass			= APickupAmmo_RPG7_PG7VR::StaticClass();
	_bLarge				= false;
	fWeight				= 0.5;
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m24_01_Mat.hud_ammo_m24_01_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= FString("1 Round for the RPG7");
}
