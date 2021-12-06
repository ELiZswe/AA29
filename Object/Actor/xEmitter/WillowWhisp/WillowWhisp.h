// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/xEmitter/xEmitter.h"
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
	
	UPROPERTY()								TArray<FVector>	WayPoints;					//var FVector WayPoints;
	UPROPERTY()								int32			NumPoints;					//var int NumPoints;
	UPROPERTY()								int32			Position;					//var int Position;
	UPROPERTY()								FVector			Destination;				//var FVector Destination;
	UPROPERTY()								bool			bHeadedRight;				//var bool bHeadedRight;
	UPROPERTY()								float			LifeLeft;					//var float LifeLeft;

	void PostBeginPlay();
	void PostNetBeginPlay();
	void StartNextPath();
};
