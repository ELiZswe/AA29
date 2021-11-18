// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/NavigationPoint/NavigationPoint.h"
#include "LiftCenter.generated.h"

class ATrigger;
class AMover;


UCLASS()
class AA29_API ALiftCenter : public ANavigationPoint
{
	GENERATED_BODY()
public:
	ALiftCenter();


	UPROPERTY()													FVector LiftOffset;							//var Object.Vector LiftOffset;
	UPROPERTY()													float MaxDist2D;							//var float MaxDist2D;
	UPROPERTY()													ATrigger* RecommendedTrigger;				//var Trigger RecommendedTrigger;
	UPROPERTY(EditAnywhere)										FName LiftTrigger;							//var() name LiftTrigger;
	UPROPERTY()													AMover* MyLift;								//var Mover MyLift;
	UPROPERTY(EditAnywhere)										FName LiftTag;								//var() name LiftTag;

	void PostBeginPlay();
	void SpecialHandling(APawn* Other);
	bool SuggestMovePreparation(APawn* Other);
	bool ProceedWithMove(APawn* Other);
};
