// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"
#include "BTR80_Gunner.generated.h"

class AVehicle;
UCLASS()
class ABTR80_Gunner : public AVehiclePosition
{
	GENERATED_BODY()
public:
	ABTR80_Gunner();

	AVehicle* FindEntryVehicle(APawn* p);
	bool TryToDrive(APawn* p);
};
