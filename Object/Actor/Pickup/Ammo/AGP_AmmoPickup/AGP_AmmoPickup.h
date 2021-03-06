// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/Ammo/Ammo.h"
#include "AGP_AmmoPickup.generated.h"

UCLASS()
class AAGP_AmmoPickup : public AAmmo
{
	GENERATED_BODY()
public:
	AAGP_AmmoPickup();

	float BotDesireability(APawn* Bot);
};
