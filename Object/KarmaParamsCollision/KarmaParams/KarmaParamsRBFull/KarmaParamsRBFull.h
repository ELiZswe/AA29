// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParams.h"
#include "KarmaParamsRBFull.generated.h"

UCLASS()
class AA29_API UKarmaParamsRBFull : public UKarmaParams
{
	GENERATED_BODY()
public:
	UKarmaParamsRBFull();

	UPROPERTY(EditAnywhere)				TArray<float> KInertiaTensor;			//var() float KInertiaTensor[6];
	UPROPERTY(EditAnywhere)				FVector KCOMOffset;						//var() Vector KCOMOffset;
};
