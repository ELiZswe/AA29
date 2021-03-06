// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_20_Mag_SPR/Ammo_556mm_20_Mag_SPR.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage556mm_SPR.h"
AAmmo_556mm_20_Mag_SPR::AAmmo_556mm_20_Mag_SPR()
{
	MaxAmmo			= 20;
	AmmoAmount		= 20;
	MyDamageType	= UProjectileDamage556mm_SPR::StaticClass();
	PickupClass		= nullptr;
	IconMaterial	= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_spr_Mat.hud_ammo_spr_Mat'"), NULL, LOAD_None, NULL);
	ItemName		= FString("SPR 20-shot magazine");
}
