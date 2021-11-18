// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VehiclePhysicalEffect.generated.h"

class AAGP_Vehicle;

UCLASS()
class AA29_API UVehiclePhysicalEffect : public UObject
{
	GENERATED_BODY()
public:
	UVehiclePhysicalEffect();

	void Activate(AAGP_Vehicle* V, int32 ZoneNum, int32 StateNum);
	void Deactivate(AAGP_Vehicle* V);

};
