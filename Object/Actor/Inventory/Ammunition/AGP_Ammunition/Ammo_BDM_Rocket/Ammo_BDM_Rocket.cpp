// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_BDM_Rocket/Ammo_BDM_Rocket.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/RocketWeaponPickup/PickupW_BDM_Rocket/PickupW_BDM_Rocket.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_BDM_Demolition/Proj_BDM_Demolition.h"
AAmmo_BDM_Rocket::AAmmo_BDM_Rocket()
{
	Damage				= 90;
	MomentumTransfer	= 20000;
	MaxAmmo				= 1;
	AmmoAmount			= 1;
	bInstantHit			= false;
	ProjectileClass		= AProj_BDM_Demolition::StaticClass();
	MyDamageType		= UProjectileDamageLargeArms::StaticClass();
	PickupClass			= APickupW_BDM_Rocket::StaticClass();
	_bLarge				= false;
	fWeight				= 0.5;
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_at4_Mat.hud_ammo_at4_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= FString("BDM");
}
