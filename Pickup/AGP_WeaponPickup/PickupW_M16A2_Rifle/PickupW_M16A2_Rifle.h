// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Pickup/AGP_WeaponPickup/AGP_WeaponPickup.h"
#include "PickupW_M16A2_Rifle.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APickupW_M16A2_Rifle : public AAGP_WeaponPickup
{
	GENERATED_BODY()
public:
	APickupW_M16A2_Rifle();

	//void StaticPrecache(LevelInfo L);
};
