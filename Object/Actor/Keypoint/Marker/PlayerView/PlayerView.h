// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/Marker/Marker.h"
#include "PlayerView.generated.h"

UCLASS()
class APlayerView : public AMarker
{
	GENERATED_BODY()
public:
	APlayerView(const FObjectInitializer& objectInitializer);
	void PreBeginPlay();

};
