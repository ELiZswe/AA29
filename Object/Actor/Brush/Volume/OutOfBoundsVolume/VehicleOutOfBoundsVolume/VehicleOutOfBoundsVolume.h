// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Brush/Volume/OutOfBoundsVolume/OutOfBoundsVolume.h"
#include "VehicleOutOfBoundsVolume.generated.h"

UCLASS()
class AVehicleOutOfBoundsVolume : public AOutOfBoundsVolume
{
	GENERATED_BODY()
public:
	AVehicleOutOfBoundsVolume();

	UPROPERTY(EditAnywhere, Category = "CountDown")			float TimeToKillVehicle;			//var(CountDown) float TimeToKillVehicle;

	void Touch(AActor* Other);
	void UnTouch(AActor* Other);
};
