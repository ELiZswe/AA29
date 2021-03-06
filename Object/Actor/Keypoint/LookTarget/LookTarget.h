// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/Keypoint.h"
#include "LookTarget.generated.h"

UCLASS()
class ALookTarget : public AKeypoint
{
	GENERATED_BODY()
public:
	ALookTarget(const FObjectInitializer& objectInitializer);

	UPROPERTY(EditAnywhere)			int32 Sequence;			//var() int Sequence;

};
