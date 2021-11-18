// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "BTR80_Turret.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABTR80_Turret : public AVehicleWeapon
{
	GENERATED_BODY()
public:
	ABTR80_Turret();

	void InitEffects();

};
