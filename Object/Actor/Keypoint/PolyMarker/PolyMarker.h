// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/Keypoint.h"
#include "PolyMarker.generated.h"

UCLASS()
class APolyMarker : public AKeypoint
{
	GENERATED_BODY()
public:
	APolyMarker(const FObjectInitializer& objectInitializer);
};
