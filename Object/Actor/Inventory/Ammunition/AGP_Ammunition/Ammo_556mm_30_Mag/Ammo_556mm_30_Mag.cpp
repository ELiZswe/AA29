// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_30_Mag.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage556mm.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_556mm_30_Mag.h"

AAmmo_556mm_30_Mag::AAmmo_556mm_30_Mag()
{
	MaxAmmo			= 30;
	AmmoAmount		= 30;
	MyDamageType	= UProjectileDamage556mm::StaticClass();
	PickupClass		= APickupAmmo_556mm_30_Mag::StaticClass();
	_bLarge			= false;
	fWeight			= 0.5;
	IconMaterial	= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m16_01_Mat.hud_ammo_m16_01_Mat'"), NULL, LOAD_None, NULL);
	ItemName		= FString("M16 30-shot clip");
}
