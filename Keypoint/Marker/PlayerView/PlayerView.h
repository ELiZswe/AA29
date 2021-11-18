// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/Marker/Marker.h"
#include "PlayerView.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APlayerView : public AMarker
{
	GENERATED_BODY()
public:
	APlayerView(const FObjectInitializer& objectInitializer);
	void PreBeginPlay();

};
