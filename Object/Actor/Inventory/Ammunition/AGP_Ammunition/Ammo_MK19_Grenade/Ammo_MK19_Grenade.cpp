// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_MK19_Grenade/Ammo_MK19_Grenade.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_MK19Gren/Proj_MK19Gren.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/RocketWeaponPickup/PickupW_AT4_Rocket/PickupW_AT4_Rocket.h"
AAmmo_MK19_Grenade::AAmmo_MK19_Grenade()
{
	Damage				= 90;
	MomentumTransfer	= 20000;
	MaxAmmo				= 100;
	AmmoAmount			= 32;
	bInstantHit			= false;
	ProjectileClass		= AProj_MK19Gren::StaticClass();
	MyDamageType		= UProjectileDamageLargeArms::StaticClass();
	PickupClass			= APickupW_AT4_Rocket::StaticClass();
	_bLarge				= false;
	fWeight				= 0.5;
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_at4_Mat.hud_ammo_at4_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= "AT4";
}
