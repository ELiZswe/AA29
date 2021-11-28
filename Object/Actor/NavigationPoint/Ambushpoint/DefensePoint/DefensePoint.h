// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/Ambushpoint/Ambushpoint.h"
#include "DefensePoint.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ADefensePoint : public AAmbushpoint
{
	GENERATED_BODY()
public:
	ADefensePoint();

	UPROPERTY(EditAnywhere)										FName FortTag;								//var() name FortTag;
	UPROPERTY(EditAnywhere)										uint8 Priority;								//var() byte Priority;
	UPROPERTY(EditAnywhere)										uint8 Team;									//var() byte Team;
};
