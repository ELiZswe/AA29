// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "PickupT_M84_Stun.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APickupT_M84_Stun : public AThrowWeaponPickup
{
	GENERATED_BODY()
public:
	APickupT_M84_Stun();

	//void StaticPrecache(LevelInfo L);
};
