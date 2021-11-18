// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AGP_Trigger/AGP_Trigger.h"
#include "ArraySound.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AArraySound : public AAGP_Trigger
{
	GENERATED_BODY()
public:
	AArraySound();

	UPROPERTY(EditAnywhere)				TArray<USoundBase*> Sounds;			//var() array<Sound> Sounds;
	UPROPERTY(EditAnywhere)				ESoundSlot SoundSlot;				//var() Object.ESoundSlot SoundSlot;
	UPROPERTY(EditAnywhere)				uint8 SoundIndex;					//var() byte SoundIndex;
	UPROPERTY(EditAnywhere)				bool bPlayRandom;					//var() bool bPlayRandom;
	UPROPERTY(EditAnywhere)				bool bPlayerSource;					//var() bool bPlayerSource;



	void Trigger(AActor* Other, APawn* EventInstigator);
	void UnTrigger(AActor* Other, APawn* EventInstigator);
	void PlayRandomSound();
	void PlaySequentialSound();
	void PlayMySound(USoundBase* MySound);
	void SetSoundIndex();

};
