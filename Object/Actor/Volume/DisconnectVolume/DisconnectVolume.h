// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Volume/AA2_Volume.h"
#include "DisconnectVolume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ADisconnectVolume : public AAA2_Volume
{
	GENERATED_BODY()
public:
	ADisconnectVolume();


	UPROPERTY(EditAnywhere)		float					FadeTime;			//var() float FadeTime;
	UPROPERTY()					APlayerController*		PC;			//var FadeTime PC;

	void Touch(AActor* Other);
	void Timer();
};
