// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/AGP_WeaponPickup.h"
#include "PickupW_M870_Shotgun.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APickupW_M870_Shotgun : public AAGP_WeaponPickup
{
	GENERATED_BODY()
public:
	APickupW_M870_Shotgun();

	//void StaticPrecache(LevelInfo L);
};
