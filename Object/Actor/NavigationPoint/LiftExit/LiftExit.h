// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "LiftExit.generated.h"

class AMover;

UCLASS()
class ALiftExit : public ANavigationPoint
{
	GENERATED_BODY()
public:
	ALiftExit();

	UPROPERTY(EditAnywhere, Category = "LiftJump")				bool		bNoDoubleJump;			//var(LiftJump) bool bNoDoubleJump;
	UPROPERTY(EditAnywhere, Category = "LiftJump")				bool		bLiftJumpExit;			//var(LiftJump) bool bLiftJumpExit;
	UPROPERTY()													uint8		KeyFrame;				//var byte KeyFrame;
	UPROPERTY(EditAnywhere)										uint8		SuggestedKeyFrame;		//var() byte SuggestedKeyFrame;
	UPROPERTY()													AMover*		MyLift;					//var Mover MyLift;
	UPROPERTY(EditAnywhere)										FName		LiftTag;				//var() name LiftTag;

	void PostBeginPlay();
	bool CanBeReachedFromLiftBy(APawn* Other);
	bool SuggestMovePreparation(APawn* Other);
};
