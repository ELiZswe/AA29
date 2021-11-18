// All the original content belonged to the US Army


#include "Ammo_RPG7_PG7VR.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_30Gren/Proj_30Gren.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_RPG7_PG7VR.h"

AAmmo_RPG7_PG7VR::AAmmo_RPG7_PG7VR()
{
	Damage            = 90;
	MomentumTransfer  = 20000;
	MaxAmmo           = 1;
	AmmoAmount        = 1;
	bInstantHit       = false;
	ProjectileClass   = AProj_30Gren::StaticClass();
	MyDamageType      = UProjectileDamageLargeArms::StaticClass();
	PickupClass       = APickupAmmo_RPG7_PG7VR::StaticClass();
	_bLarge           = false;
	fWeight           = 0.5;
	IconMaterial      = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m24_01.hud_ammo_m24_01"), NULL, LOAD_None, NULL);
	ItemName          = FString("1 Round for the RPG7");
}