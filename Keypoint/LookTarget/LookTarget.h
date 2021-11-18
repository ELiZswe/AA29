// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/Keypoint.h"
#include "LookTarget.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ALookTarget : public AKeypoint
{
	GENERATED_BODY()
public:
	ALookTarget(const FObjectInitializer& objectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)			int32 Sequence;			//var() int Sequence;

};
