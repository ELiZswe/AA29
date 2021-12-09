// All the original content belonged to the US Army


#include "Ammo_556mm_20_Mag.h"
#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_556mm_20_Mag.h"
AAmmo_556mm_20_Mag::AAmmo_556mm_20_Mag()
{
	MaxAmmo       = 20;
	AmmoAmount    = 20;
	PickupClass   = APickupAmmo_556mm_20_Mag::StaticClass();
	IconMaterial  = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_ammo_m16_02.hud_ammo_m16_02"), NULL, LOAD_None, NULL);
	ItemName      = FString("M16 20-shot magazine");
}