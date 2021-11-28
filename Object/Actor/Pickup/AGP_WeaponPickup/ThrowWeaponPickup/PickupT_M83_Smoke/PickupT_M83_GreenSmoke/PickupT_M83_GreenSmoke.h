// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M83_Smoke/PickupT_M83_Smoke.h"
#include "PickupT_M83_GreenSmoke.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APickupT_M83_GreenSmoke : public APickupT_M83_Smoke
{
	GENERATED_BODY()
public:
	APickupT_M83_GreenSmoke();

	void SpawnSmokeEmitter(AThrowWeapon* W);
};
