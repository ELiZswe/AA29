// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/Keypoint.h"
#include "InterpolationPoint.generated.h"

class ASceneManager;

UCLASS()
class AA29_API AInterpolationPoint : public AKeypoint
{
	GENERATED_BODY()
public:
	AInterpolationPoint(const FObjectInitializer& objectInitializer);

	void PointReached(ASceneManager* Scene);
};
