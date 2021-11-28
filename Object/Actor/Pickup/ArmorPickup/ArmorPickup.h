// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "ArmorPickup.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AArmorPickup : public APickup
{
	GENERATED_BODY()
public:
	AArmorPickup();

	void BotDesireability(APawn* Bot);
};
