// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AGP_Trigger/AGP_Trigger.h"
#include "NoiseTrigger.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANoiseTrigger : public AAGP_Trigger
{
	GENERATED_BODY()
public:
	ANoiseTrigger();

	UPROPERTY()							USoundBase* CurrentSound;			//var Sound CurrentSound;
	UPROPERTY(EditAnywhere)				float MaxVelocity;					//var() float MaxVelocity;
	UPROPERTY(EditAnywhere)				float ScriptVolume;					//var() float ScriptVolume;
	UPROPERTY(EditAnywhere)				float NoiseRadius;					//var() float NoiseRadius;
	UPROPERTY(EditAnywhere)				float NoiseVolume;					//var() float NoiseVolume;
	UPROPERTY(EditAnywhere)				TArray<USoundBase*> Noises;			//var() array<Sound> Noises;
	UPROPERTY(EditAnywhere)				float NOTIFYDELAY;					//var() float NOTIFYDELAY;
	UPROPERTY(EditAnywhere)				bool bTriggerOnce;					//var() bool bTriggerOnce;


	void Touch(AActor* Other);
	void Timer();
	void UnTouch(AActor* Other);
	void Tick(float DeltaTime);

};
