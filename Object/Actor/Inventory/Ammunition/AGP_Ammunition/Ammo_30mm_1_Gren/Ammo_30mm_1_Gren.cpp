// All the original content belonged to the US Army

#include "Ammo_30mm_1_Gren.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_30Gren/Proj_30Gren.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_30mm_1_Gren.h"

AAmmo_30mm_1_Gren::AAmmo_30mm_1_Gren()
{
	Damage				= 90;
	MomentumTransfer	= 20000;
	MaxAmmo				= 1;
	AmmoAmount			= 1;
	bInstantHit			= false;
	ProjectileClass		= AProj_30Gren::StaticClass();
	MyDamageType		= UProjectileDamageLargeArms::StaticClass();
	PickupClass			= APickupAmmo_30mm_1_Gren::StaticClass();
	_bLarge				= false;
	fWeight				= 0.5;
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_gp30_01_Mat.hud_ammo_gp30_01_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= "30mm Grenade";
}
