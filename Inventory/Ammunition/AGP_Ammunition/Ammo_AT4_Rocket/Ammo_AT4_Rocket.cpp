// All the original content belonged to the US Army


#include "Ammo_AT4_Rocket.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Pickup/AGP_WeaponPickup/RocketWeaponPickup/PickupW_AT4_Rocket/PickupW_AT4_Rocket.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/RocketProjectile/Proj_AT4_Explosive/Proj_AT4_Explosive.h"

AAmmo_AT4_Rocket::AAmmo_AT4_Rocket()
{
	Damage            = 90;
	MomentumTransfer  = 20000;
	MaxAmmo           = 1;
	AmmoAmount        = 1;
	bInstantHit       = false;
	ProjectileClass   = AProj_AT4_Explosive::StaticClass();
	MyDamageType      = UProjectileDamageLargeArms::StaticClass();
	PickupClass       = APickupW_AT4_Rocket::StaticClass();
	_bLarge           = false;
	fWeight           = 0.5;
	IconMaterial      = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_at4.hud_ammo_at4"), NULL, LOAD_None, NULL);
	ItemName          = FString("AT4");
}