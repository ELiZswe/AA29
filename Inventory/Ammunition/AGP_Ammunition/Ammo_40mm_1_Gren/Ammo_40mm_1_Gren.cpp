// All the original content belonged to the US Army


#include "Ammo_40mm_1_Gren.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_40Gren/Proj_40Gren.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_40mm_1_Gren.h"
AAmmo_40mm_1_Gren::AAmmo_40mm_1_Gren()
{
	Damage            = 90;
	MomentumTransfer  = 20000;
	MaxAmmo           = 1;
	AmmoAmount        = 1;
	bInstantHit       = false;
	ProjectileClass   = AProj_40Gren::StaticClass();
	MyDamageType      = UProjectileDamageLargeArms::StaticClass();
	PickupClass       = APickupAmmo_40mm_1_Gren::StaticClass();
	_bLarge           = false;
	fWeight           = 0.5;
	IconMaterial      = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m203_01.hud_ammo_m203_01"), NULL, LOAD_None, NULL);
	ItemName          = FString("40mm Grenade");
}