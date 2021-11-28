// All the original content belonged to the US Army


#include "Ammo_BS1_30mm_1_Gren.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_BS1_30Gren/Proj_BS1_30Gren.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageLargeArms.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_BS1_30mm_1_Gren.h"


AAmmo_BS1_30mm_1_Gren::AAmmo_BS1_30mm_1_Gren()
{
	Damage            = 90;
	MomentumTransfer  = 20000;
	MaxAmmo           = 1;
	AmmoAmount        = 1;
	bInstantHit       = false;
	ProjectileClass   = AProj_BS1_30Gren::StaticClass();
	MyDamageType      = UProjectileDamageLargeArms::StaticClass();
	PickupClass       = APickupAmmo_BS1_30mm_1_Gren::StaticClass();
	_bLarge           = false;
	fWeight           = 0.5;
	IconMaterial      = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_gp30_01.hud_ammo_gp30_01"), NULL, LOAD_None, NULL);
	ItemName          = FString("30mm VOG-T Grenade");
}