// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"
#include "BTR80_Gunner.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABTR80_Gunner : public AVehiclePosition
{
	GENERATED_BODY()
public:
	ABTR80_Gunner();

	void FindEntryVehicle(APawn* p);
	bool TryToDrive(APawn* p);

};
