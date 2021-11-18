// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "Sound/AmbientSound.h"
#include "EventSound.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AEventSound : public AAmbientSound
{
	GENERATED_BODY()
public:
	AEventSound();


	UPROPERTY()						float _timer;							//var float _timer;
	UPROPERTY(EditAnywhere)			bool bInstantNotify;					//var() bool bInstantNotify;
	UPROPERTY(EditAnywhere)			bool bPlayLocal;						//var() bool bPlayLocal;
	UPROPERTY(EditAnywhere)			USoundBase* MySound;					//var() Sound MySound;


	void Trigger(AActor* Other, APawn* EventInstigator);
	void Timer();

};
