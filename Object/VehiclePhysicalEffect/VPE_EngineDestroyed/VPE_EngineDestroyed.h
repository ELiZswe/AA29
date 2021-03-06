// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/VehiclePhysicalEffect/VehiclePhysicalEffect.h"
#include "AA29/AA29.h"
#include "VPE_EngineDestroyed.generated.h"

class AAGP_Vehicle;
UCLASS()
class UVPE_EngineDestroyed : public UVehiclePhysicalEffect
{
	GENERATED_BODY()
public:
	UVPE_EngineDestroyed();

	UPROPERTY()		FAA2_InterpCurve	NoTorque;

	void Activate(AAGP_Vehicle* V, int32 ZoneNum, int32 StateNum);
};
