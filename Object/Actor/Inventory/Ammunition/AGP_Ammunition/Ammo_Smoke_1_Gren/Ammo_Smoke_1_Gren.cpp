// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_Smoke_1_Gren/Ammo_Smoke_1_Gren.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_40Gren/Proj_SmokeGren/Proj_SmokeGren.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_Smoke_1_Gren.h"
AAmmo_Smoke_1_Gren::AAmmo_Smoke_1_Gren(const FObjectInitializer& ObjectInitializer)
{
	Damage				= 0;
	MomentumTransfer	= 20000;
	MaxAmmo				= 1;
	AmmoAmount			= 1;
	bInstantHit			= false;
	ProjectileClass		= AProj_SmokeGren::StaticClass();
	//MyDamageType		= nullptr
	PickupClass			= APickupAmmo_Smoke_1_Gren::StaticClass();
	_bLarge				= false;
	fWeight				= 0.5;
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_gren_smoke_01_Mat.hud_gren_smoke_01_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= FString("Flare Grenade");
}
