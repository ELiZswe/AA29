// All the original content belonged to the US Army


#include "Ammo.h"

AAmmo::AAmmo()
{
	MaxDesireability  = 0.2;
	RespawnTime       = 30;
	PickupMessage     = FString("You picked up some ammo.");
	CullDistance      = 4000;
	Texture           = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/Engine/S_Ammo.S_Ammo"), NULL, LOAD_None, NULL);
	AmbientGlow       = 128;
}
/*
void AAmmo::UpdateHUD(HUD H)
{
	H.LastPickupTime = H.GetWorld()->GetTimeSeconds();
	H.LastAmmoPickupTime = H.LastPickupTime;
}
*/
void AAmmo::DetourWeight(APawn* , float PathWeight)
{
	/*
	Return 0;
	*/
}
void AAmmo::BotDesireability(APawn* Bot)
{
	/*
	Return 0.25 * MaxDesireability;
	*/
}
void AAmmo::SpawnCopy(APawn* Other, bool bRealInventory)
{
	/*
	local Inventory Copy;
	Copy = SpawnCopy(Other);
	Ammunition(Copy).AmmoAmount = AmmoAmount;
	Return Copy;
	*/
}