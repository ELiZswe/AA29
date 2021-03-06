// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/Keypoint.h"
#include "Marker.generated.h"

UCLASS()
class AMarker : public AKeypoint
{
	GENERATED_BODY()
public:
	AMarker(const FObjectInitializer& objectInitializer);

};
