// All the original content belonged to the US Army


#include "Ammo_Flare_1_Gren.h"
#include "AA29/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_FlareGren/Proj_FlareGren.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_Flare_1_Gren.h"
AAmmo_Flare_1_Gren::AAmmo_Flare_1_Gren()
{
	Damage             = 0;
	MomentumTransfer   = 20000;
	MaxAmmo            = 1;
	AmmoAmount         = 1;
	bInstantHit        = false;
	ProjectileClass    = AProj_FlareGren::StaticClass();
	//MyDamageType = class'None'
	PickupClass        = APickupAmmo_Flare_1_Gren::StaticClass();
	_bLarge            = false;
	fWeight            = 0.5;
	IconMaterial       = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m203_flare.hud_ammo_m203_flare"), NULL, LOAD_None, NULL);
	ItemName           = FString("Flare Grenade");
}