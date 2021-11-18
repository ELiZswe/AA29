// All the original content belonged to the US Army


#include "Ammo_PG7VR_Rocket.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_PG7VR_Demolition/Proj_PG7VR_Demolition.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_RPG7_PG7VR.h"
AAmmo_PG7VR_Rocket::AAmmo_PG7VR_Rocket()
{
	Damage            = 100;
	MomentumTransfer  = 20000;
	MaxAmmo           = 1;
	AmmoAmount        = 1;
	bInstantHit       = false;
	ProjectileClass   = AProj_PG7VR_Demolition::StaticClass();
	MyDamageType      = UProjectileDamageLargeArms::StaticClass();
	PickupClass       = APickupAmmo_RPG7_PG7VR::StaticClass();
	_bLarge           = false;
	fWeight           = 0.5;
	IconMaterial      = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_rgp_pg7b.hud_ammo_rgp_pg7b"), NULL, LOAD_None, NULL);
	ItemName          = FString("1 Round for the RPG7_PG7VR");
}