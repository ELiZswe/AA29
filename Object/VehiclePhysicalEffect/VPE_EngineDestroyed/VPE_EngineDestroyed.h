// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/VehiclePhysicalEffect/VehiclePhysicalEffect.h"
#include "VPE_EngineDestroyed.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UVPE_EngineDestroyed : public UVehiclePhysicalEffect
{
	GENERATED_BODY()
public:
	UVPE_EngineDestroyed();

	//UPROPERTY()										FInterpCurve	NoTorque;					////var Object.InterpCurve NoTorque;

	void Activate(AAGP_Vehicle* V, int32 ZoneNum, int32 StateNum);
};
