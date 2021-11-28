// All the original content belonged to the US Army


#include "Ammo_RPG7_PG7B.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_PG7B/Proj_PG7B.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_RPG7_PG7b.h"
AAmmo_RPG7_PG7B::AAmmo_RPG7_PG7B()
{
	Damage				= 90;
	MomentumTransfer	= 20000;
	MaxAmmo				= 1;
	AmmoAmount          = 1;
	bInstantHit         = false;
	ProjectileClass     = AProj_PG7B::StaticClass();
	MyDamageType        = UProjectileDamageLargeArms::StaticClass();
	PickupClass         = APickupAmmo_RPG7_PG7b::StaticClass();
	_bLarge             = false;
	fWeight             = 0.5;
	IconMaterial        = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_rgp_pg7b.hud_ammo_rgp_pg7b"), NULL, LOAD_None, NULL);
	ItemName            = FString("1 Round for the RPG7");
}