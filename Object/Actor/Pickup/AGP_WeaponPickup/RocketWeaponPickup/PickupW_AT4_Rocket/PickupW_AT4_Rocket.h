// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/RocketWeaponPickup/RocketWeaponPickup.h"
#include "PickupW_AT4_Rocket.generated.h"

UCLASS()
class APickupW_AT4_Rocket : public ARocketWeaponPickup
{
	GENERATED_BODY()
public:
	APickupW_AT4_Rocket();


	//void StaticPrecache(LevelInfo L);
	void BeginPlay();

};
