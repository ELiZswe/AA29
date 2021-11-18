// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "BMP1_Turret.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABMP1_Turret : public AVehicleWeapon
{
	GENERATED_BODY()
public:
	ABMP1_Turret();

	UPROPERTY()							int32						ShotCount;										//var int ShotCount;

};
