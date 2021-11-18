// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/VehiclePosition.h"
#include "CROWS_GunnerSeat.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ACROWS_GunnerSeat : public AVehiclePosition
{
	GENERATED_BODY()
public:
	ACROWS_GunnerSeat();

	UPROPERTY()						bool		bPower;									//var bool bPower;

	bool PlaceExitingDriver();
	void ToggleGunView();
	void Tick(float DeltaTime);

};
