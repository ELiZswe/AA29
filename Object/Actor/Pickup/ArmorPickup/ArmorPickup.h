// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "ArmorPickup.generated.h"

UCLASS()
class AArmorPickup : public APickup
{
	GENERATED_BODY()
public:
	AArmorPickup();

	float BotDesireability(APawn* Bot);
};
