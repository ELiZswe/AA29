// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/Marker/Marker.h"
#include "NoiseMarker.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANoiseMarker : public AMarker
{
	GENERATED_BODY()
public:
	ANoiseMarker(const FObjectInitializer& objectInitializer);

	void SetDestroyTimer(float Life);
	void Timer();
	void Destroyed();

};
