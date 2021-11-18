// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/MatObject/MatObject.h"
#include "AA29/Object/MatObject/MatSubAction/MatSubAction.h"
#include "MatAction.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UMatAction : public UMatObject
{
	GENERATED_BODY()
public:
	UMatAction();


	UPROPERTY()												float PctDuration;							//var transient float PctDuration;
	UPROPERTY()												float PctEnding;							//var transient float PctEnding;
	UPROPERTY()												float PctStarting;							//var transient float PctStarting;
	UPROPERTY()												TArray<FVector> SampleLocations;			//var transient array<Vector> SampleLocations;
	UPROPERTY()												float PathLength;							//var float PathLength;
	UPROPERTY(EditAnywhere, Category = "Path")				float PathVelocity;							//var(Path) float PathVelocity;
	UPROPERTY(EditAnywhere, Category = "Path")				bool bConstantPathVelocity;					//var(Path) bool bConstantPathVelocity;
	UPROPERTY(EditAnywhere, Category = "Path")				FVector EndControlPoint;					//var(Path) FVector EndControlPoint;
	UPROPERTY(EditAnywhere, Category = "Path")				FVector StartControlPoint;					//var(Path) FVector StartControlPoint;
	UPROPERTY(EditAnywhere, Category = "Path")				bool bSmoothCorner;							//var(Path) bool bSmoothCorner;
	UPROPERTY(EditAnywhere, Category = "Sub")				TArray<UMatSubAction*> SubActions;			//var(Sub) array<MatSubAction> SubActions;
	UPROPERTY(EditAnywhere, Category = "Time")				float Duration;								//var(Time) float Duration;
	UPROPERTY(EditAnywhere)									FString Comment;							//var() string Comment;
	UPROPERTY(EditAnywhere)									AInterpolationPoint* IntPoint;				//var() InterpolationPoint IntPoint;

};
