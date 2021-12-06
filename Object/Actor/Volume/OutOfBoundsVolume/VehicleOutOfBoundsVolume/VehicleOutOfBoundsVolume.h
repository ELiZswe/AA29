// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Volume/OutOfBoundsVolume/OutOfBoundsVolume.h"
#include "VehicleOutOfBoundsVolume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AVehicleOutOfBoundsVolume : public AOutOfBoundsVolume
{
	GENERATED_BODY()
public:
	AVehicleOutOfBoundsVolume();

	UPROPERTY(EditAnywhere, Category = "CountDown")			float TimeToKillVehicle;			//var(CountDown) float TimeToKillVehicle;
};
