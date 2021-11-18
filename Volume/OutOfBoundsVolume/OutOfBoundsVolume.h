// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "OutOfBoundsVolume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AOutOfBoundsVolume : public AVolume
{
	GENERATED_BODY()
public:

	AOutOfBoundsVolume();

	UPROPERTY(EditAnywhere, Category = "OutOfBoundsInfo")			bool bIsTrainingVolume;			//var(OutOfBoundsInfo) bool bIsTrainingVolume;
	UPROPERTY(EditAnywhere, Category = "OutOfBoundsInfo")			float TimeToKillPlayer;			//var(OutOfBoundsInfo) float TimeToKillPlayer;

	void Touch(AActor* Other);
	void UnTouch(AActor* Other);
};
