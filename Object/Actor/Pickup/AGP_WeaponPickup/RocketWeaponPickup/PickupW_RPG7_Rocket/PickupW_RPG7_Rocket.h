// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/RocketWeaponPickup/RocketWeaponPickup.h"
#include "PickupW_RPG7_Rocket.generated.h"

UCLASS()
class APickupW_RPG7_Rocket : public ARocketWeaponPickup
{
	GENERATED_BODY()
public:
	APickupW_RPG7_Rocket();

	void BeginPlay();
};
