// All the original content belonged to the US Army


#include "Ammo_Incendiary_1_Gren.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_IncendiaryGren/Proj_IncendiaryGren.h"
#include "AA29/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_Incendiary_1_Gren.h"
AAmmo_Incendiary_1_Gren::AAmmo_Incendiary_1_Gren()
{
	Damage            = 0;
	MomentumTransfer  = 20000;
	MaxAmmo           = 1;
	AmmoAmount        = 1;
	bInstantHit       = false;
	ProjectileClass   = AProj_IncendiaryGren::StaticClass();
	//MyDamageType = class'None'
	PickupClass       = APickupAmmo_Incendiary_1_Gren::StaticClass();
	_bLarge           = false;
	fWeight           = 0.5;
	IconMaterial      = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_gren_incendiary_01.hud_gren_incendiary_01"), NULL, LOAD_None, NULL);
	ItemName          = FString("Incendiary Grenade");
}