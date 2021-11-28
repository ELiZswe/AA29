// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Patrol/CircularPatrol/CircularPatrol.h"
#include "LinearPatrol.generated.h"

class ANavigationPoint;
class APawn;

UCLASS()
class AA29_API ALinearPatrol : public ACircularPatrol
{
	GENERATED_BODY()
public:
	ALinearPatrol();

	UPROPERTY()			bool bBackNodes;				//var bool bBackNodes;

	ANavigationPoint* GetNextNode(ANavigationPoint* CurrentNode, APawn* Bot);
};
