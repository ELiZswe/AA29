// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/xEmitter/xEmitter.h"
#include "WillowWhisp.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWillowWhisp : public AxEmitter
{
	GENERATED_BODY()
public:
	AWillowWhisp();

	UPROPERTY()								float LifeLeft;						//var float LifeLeft;
	UPROPERTY()								bool bHeadedRight;					//var bool bHeadedRight;
	UPROPERTY()								FVector Destination;				//var FVector Destination;
	UPROPERTY()								int32 Position;						//var int Position;
	UPROPERTY()								int32 NumPoints;					//var int NumPoints;
	UPROPERTY()								FVector WayPoints;					//var FVector WayPoints;

	void PostBeginPlay();
	void PostNetBeginPlay();
	void StartNextPath();


};
