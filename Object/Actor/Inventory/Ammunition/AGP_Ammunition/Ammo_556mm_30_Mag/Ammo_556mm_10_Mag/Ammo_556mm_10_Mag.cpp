// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_10_Mag/Ammo_556mm_10_Mag.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_556mm_10_Mag.h"
AAmmo_556mm_10_Mag::AAmmo_556mm_10_Mag()
{
	MaxAmmo			= 10;
	AmmoAmount		= 10;
	PickupClass		= APickupAmmo_556mm_10_Mag::StaticClass();
	IconMaterial	= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m16_02_Mat.hud_ammo_m16_02_Mat'"), NULL, LOAD_None, NULL);
	ItemName		= "M16 10-shot magazine";
}
