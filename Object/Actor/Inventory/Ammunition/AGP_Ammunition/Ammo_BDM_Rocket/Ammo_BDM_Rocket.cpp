// All the original content belonged to the US Army


#include "Ammo_BDM_Rocket.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/RocketWeaponPickup/PickupW_BDM_Rocket/PickupW_BDM_Rocket.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_BDM_Demolition/Proj_BDM_Demolition.h"
AAmmo_BDM_Rocket::AAmmo_BDM_Rocket()
{
	Damage            = 90;
	MomentumTransfer  = 20000;
	MaxAmmo           = 1;
	AmmoAmount        = 1;
	bInstantHit       = false;
	ProjectileClass   = AProj_BDM_Demolition::StaticClass();
	MyDamageType      = UProjectileDamageLargeArms::StaticClass();
	PickupClass       = APickupW_BDM_Rocket::StaticClass();
	_bLarge           = false;
	fWeight           = 0.5;
	IconMaterial      = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_at4.hud_ammo_at4"), NULL, LOAD_None, NULL);
	ItemName          = FString("BDM");
}