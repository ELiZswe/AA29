// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"
#include "T62_MainGunner.generated.h"

class AVehicle;
UCLASS()
class AT62_MainGunner : public AVehiclePosition
{
	GENERATED_BODY()
public:
	AT62_MainGunner();

	AVehicle* FindEntryVehicle(APawn* p);
	bool TryToDrive(APawn* p);
};
