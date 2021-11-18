// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"
#include "BMP1_Gunner.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABMP1_Gunner : public AVehiclePosition
{
	GENERATED_BODY()
public:
	ABMP1_Gunner();

	void FindEntryVehicle(APawn* p);
	void TryToDrive(APawn* p);
};
