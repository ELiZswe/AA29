// All the original content belonged to the US Army


#include "Ammo_556mm_10_Mag.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_556mm_10_Mag.h"
AAmmo_556mm_10_Mag::AAmmo_556mm_10_Mag()
{
	MaxAmmo       = 10;
	AmmoAmount    = 10;
	PickupClass   = APickupAmmo_556mm_10_Mag::StaticClass();
	IconMaterial  = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m16_02.hud_ammo_m16_02"), NULL, LOAD_None, NULL);
	ItemName      = FString("M16 10-shot magazine");
}