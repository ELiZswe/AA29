// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "Ammo.generated.h"

UCLASS()
class AAmmo : public APickup
{
	GENERATED_BODY()
public:
	AAmmo();

	UPROPERTY(EditAnywhere)			int32	AmmoAmount;				//var() int32 AmmoAmount;

	void UpdateHUD(AHUD* H);
	float DetourWeight(APawn*, float PathWeight);
	float BotDesireability(APawn* Bot);
	AInventory* SpawnCopy(APawn* Other, bool bRealInventory);
};
