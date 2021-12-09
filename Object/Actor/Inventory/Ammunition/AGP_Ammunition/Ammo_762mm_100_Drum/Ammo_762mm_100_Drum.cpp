// All the original content belonged to the US Army


#include "Ammo_762mm_100_Drum.h"
#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762mm_RPK.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_762mm_100_Drum.h"

AAmmo_762mm_100_Drum::AAmmo_762mm_100_Drum()
{
	Damage         = 45;
		//_cTracerClass = Class'AGP.GreenTracer'
	_iTracerCount  = 5;
	MaxAmmo        = 75;
	AmmoAmount     = 75;
	MyDamageType   = UProjectileDamage762mm_RPK::StaticClass();
	PickupClass    = APickupAmmo_762mm_100_Drum::StaticClass();
	_bLarge        = false;
	fWeight        = 0.4;
	IconMaterial   = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_rpk_01.hud_ammo_rpk_01"), NULL, LOAD_None, NULL);
	ItemName       = FString("RPK 75-round magazine");
}