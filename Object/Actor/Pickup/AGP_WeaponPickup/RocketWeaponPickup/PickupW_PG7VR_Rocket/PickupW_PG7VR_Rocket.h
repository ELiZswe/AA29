// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/RocketWeaponPickup/RocketWeaponPickup.h"
#include "PickupW_PG7VR_Rocket.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APickupW_PG7VR_Rocket : public ARocketWeaponPickup
{
	GENERATED_BODY()
public:
	APickupW_PG7VR_Rocket();

	void BeginPlay();
};
