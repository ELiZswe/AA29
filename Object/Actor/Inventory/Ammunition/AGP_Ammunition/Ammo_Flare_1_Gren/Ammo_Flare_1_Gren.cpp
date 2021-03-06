// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_Flare_1_Gren/Ammo_Flare_1_Gren.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_FlareGren/Proj_FlareGren.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_Flare_1_Gren.h"
AAmmo_Flare_1_Gren::AAmmo_Flare_1_Gren()
{
	Damage				= 0;
	MomentumTransfer	= 20000;
	MaxAmmo				= 1;
	AmmoAmount			= 1;
	bInstantHit			= false;
	ProjectileClass		= AProj_FlareGren::StaticClass();
	MyDamageType		= nullptr;
	PickupClass			= APickupAmmo_Flare_1_Gren::StaticClass();
	_bLarge				= false;
	fWeight				= 0.5;
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m203_flare_Mat.hud_ammo_m203_flare_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= FString("Flare Grenade");
}
