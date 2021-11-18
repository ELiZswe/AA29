// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/VehiclePhysicalEffect/VehiclePhysicalEffect.h"
#include "VPE_TireFlat.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UVPE_TireFlat : public UVehiclePhysicalEffect
{
	GENERATED_BODY()
public:
	UVPE_TireFlat();

	void Activate(AAGP_Vehicle* V, int32 ZoneNum, int32 StateNum);
};
