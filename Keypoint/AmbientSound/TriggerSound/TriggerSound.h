// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "Sound/AmbientSound.h"
#include "TriggerSound.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATriggerSound : public AAmbientSound
{
	GENERATED_BODY()
public:
	ATriggerSound();

	UPROPERTY()						float SoundDuration;				//var float SoundDuration;
	UPROPERTY()						USoundBase* SoundTemp;				//var Sound SoundTemp;
	UPROPERTY(EditAnywhere)			int32 nNumLoops;					//var() int nNumLoops;
	UPROPERTY(EditAnywhere)			bool bToggle;						//var() bool bToggle;
	UPROPERTY(EditAnywhere)			bool bStartOn;						//var() bool bStartOn;
	UPROPERTY(EditAnywhere)			bool bLoopInfinite;					//var() bool bLoopInfinite;

	void PreBeginPlay();
	void BeginPlay();
	void MatchStarting();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void Timer();

};
