// All the original content belonged to the US Army


#include "Ammo_556mm_20_Mag_SPR.h"
#include "AA29/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage556mm_SPR.h"
AAmmo_556mm_20_Mag_SPR::AAmmo_556mm_20_Mag_SPR()
{
	MaxAmmo        = 20;
	AmmoAmount     = 20;
	MyDamageType   = UProjectileDamage556mm_SPR::StaticClass();
	//PickupClass    = class'None'
	IconMaterial   = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_spr.hud_ammo_spr"), NULL, LOAD_None, NULL);
	ItemName       = FString("SPR 20-shot magazine");
}