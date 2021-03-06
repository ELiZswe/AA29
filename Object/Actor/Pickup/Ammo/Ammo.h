// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "Ammo.generated.h"

class AInventory;
class AAA2_HUD;

UCLASS()
class AAmmo : public APickup
{
	GENERATED_BODY()
public:
	AAmmo();

	UPROPERTY(EditAnywhere)			int32	AmmoAmount;				//var() int32 AmmoAmount;

	void UpdateHUD(AAA2_HUD* H);
	float DetourWeight(APawn*, float PathWeight);
	float BotDesireability(APawn* Bot);
	AInventory* SpawnCopy(APawn* Other, bool bRealInventory);
};
