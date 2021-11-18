// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Sound/Sound.h"
#include "ProceduralSound.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UProceduralSound : public USound
{
	GENERATED_BODY()
public:
	UProceduralSound();

	UPROPERTY()											float RenderedVolumeModification;				//var transient float RenderedVolumeModification;
	UPROPERTY()											float RenderedPitchModification;				//var transient float RenderedPitchModification;
	UPROPERTY(EditAnywhere, Category = "Sound")			float VolumeVariance;							//var(Sound) float VolumeVariance;
	UPROPERTY(EditAnywhere, Category = "Sound")			float PitchVariance;							//var(Sound) float PitchVariance;
	UPROPERTY(EditAnywhere, Category = "Sound")			float VolumeModification;						//var(Sound) float VolumeModification;
	UPROPERTY(EditAnywhere, Category = "Sound")			float PitchModification;						//var(Sound) float PitchModification;
	UPROPERTY(EditAnywhere, Category = "Sound")			USoundBase* BaseSound;							//var(Sound) Sound BaseSound;
};
