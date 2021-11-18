// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/TraceWeapon.h"
#include "FSTS_Trainer_Weapon_M2_HMG.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_Trainer_Weapon_M2_HMG : public ATraceWeapon
{
	GENERATED_BODY()
public:
	AFSTS_Trainer_Weapon_M2_HMG();

	void GiveTo(APawn* Other, APickup* Pickup);
};
