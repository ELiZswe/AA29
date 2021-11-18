// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Pickup/AGP_WeaponPickup/RocketWeaponPickup/RocketWeaponPickup.h"
#include "PickupW_BDM_Rocket.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APickupW_BDM_Rocket : public ARocketWeaponPickup
{
	GENERATED_BODY()
public:
	APickupW_BDM_Rocket();

	void BeginPlay();
};
