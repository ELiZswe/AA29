// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Pickup/AGP_WeaponPickup/RocketWeaponPickup/PickupW_RPG7_Rocket/PickupW_RPG7_Rocket.h"
#include "PickupW_Guerilla_RPG7_Rocket.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APickupW_Guerilla_RPG7_Rocket : public APickupW_RPG7_Rocket
{
	GENERATED_BODY()
public:
	APickupW_Guerilla_RPG7_Rocket();

	void BeginPlay();
};
