// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/Ammo/Ammo.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/HUD/AA2_HUD.h"

AAmmo::AAmmo()
{
	MaxDesireability  = 0.2;
	RespawnTime       = 30;
	PickupMessage     = "You picked up some ammo.";
	CullDistance      = 4000;
	Texture           = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/Engine/S_Ammo.S_Ammo"), NULL, LOAD_None, NULL);
	AmbientGlow       = 128;
}

void AAmmo::UpdateHUD(AAA2_HUD* H)
{
	//H->LastPickupTime = H->Level->TimeSeconds;
	//H->LastAmmoPickupTime = H->LastPickupTime;
}

float AAmmo::DetourWeight(APawn* Other, float PathWeight)
{
	return 0;
}

float AAmmo::BotDesireability(APawn* Bot)
{
	return (0.25 * MaxDesireability);
}

AInventory* AAmmo::SpawnCopy(APawn* Other, bool bRealInventory)
{
	AInventory* Copy = nullptr;
	Copy = Super::SpawnCopy(Other,false);
	Cast<AAmmunition>(Copy)->AmmoAmount = AmmoAmount;
	return Copy;
}
