// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Pickup/Pickup.h"
#include "Ammo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAmmo : public APickup
{
	GENERATED_BODY()
public:
	AAmmo();

	//var() int AmmoAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 AmmoAmount;



	//void UpdateHUD(HUD H);
	void DetourWeight(APawn*, float PathWeight);
	void BotDesireability(APawn* Bot);
	void SpawnCopy(APawn* Other, bool bRealInventory);

};
