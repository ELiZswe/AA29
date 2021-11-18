// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/Keypoint.h"
#include "NPCItemOfInterest.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPCItemOfInterest : public AKeypoint
{
	GENERATED_BODY()
public:
	ANPCItemOfInterest(const FObjectInitializer& objectInitializer);

	UPROPERTY()										APawn* pawnTargetToShoot;					//var Pawn pawnTargetToShoot;
	UPROPERTY(EditAnywhere)						FName nameTargetPawn;						//var() name nameTargetPawn;
	UPROPERTY(EditAnywhere)						bool bIsShootableTarget;					//var() bool bIsShootableTarget;
	UPROPERTY(EditAnywhere)						float fpLikelihoodItemWillBeNoticed;		//var() float fpLikelihoodItemWillBeNoticed;
	UPROPERTY(EditAnywhere)						float fpTimeToWaitHere;						//var() float fpTimeToWaitHere;
	UPROPERTY(EditAnywhere)						float  fpMaxDistanceToNotice;				//var() float fpMaxDistanceToNotice;
	UPROPERTY(EditAnywhere)						USoundBase* sndToPlay;						//var() Sound sndToPlay;
	UPROPERTY(EditAnywhere)						FName nameNPCAnimation;						//var() name nameNPCAnimation;
};
