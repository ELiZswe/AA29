// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Volume/AA2_Volume.h"
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

	UPROPERTY()							APlayerController* PC;					//var PlayerController PC;
	UPROPERTY(EditAnywhere)				float FadeTime;							//var() float FadeTime;
};
