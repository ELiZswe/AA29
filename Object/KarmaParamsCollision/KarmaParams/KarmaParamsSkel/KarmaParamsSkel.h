// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/KarmaParamsCollision/KarmaParams/KarmaParams.h"
#include "KarmaParamsSkel.generated.h"

UCLASS()
class AA29_API UKarmaParamsSkel : public UKarmaParams
{
	GENERATED_BODY()
public:
	UKarmaParamsSkel();

	UPROPERTY(EditAnywhere)							FString		KSkeleton;						//var() FString KSkeleton;
	UPROPERTY(EditAnywhere)							bool		bKDoConvulsions;				//var() bool bKDoConvulsions;
	UPROPERTY(EditAnywhere)							bool		bRubbery;						//var() bool bRubbery;
	UPROPERTY(EditAnywhere)							FRange		KConvulseSpacing;				//var() Range KConvulseSpacing;
	UPROPERTY()										FVector		KShotStart;						//var transient Vector KShotStart;
	UPROPERTY()										FVector		KShotEnd;						//var transient Vector KShotEnd;
	UPROPERTY()										float		KShotStrength;					//var transient float KShotStrength;
	UPROPERTY()										bool		bKImportantRagdoll;				//var transient bool bKImportantRagdoll;
};
