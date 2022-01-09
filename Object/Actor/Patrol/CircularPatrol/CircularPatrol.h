// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Patrol/Patrol.h"
#include "CircularPatrol.generated.h"

class ANavigationPoint;
class APawn;

UCLASS()
class ACircularPatrol : public APatrol
{
	GENERATED_BODY()
public:
	ACircularPatrol();



	UPROPERTY(EditAnywhere, Category = "Patrol")			TArray<ANavigationPoint*> PatrolNodes;				//var(Patrol) edfindable TArray<NavigationPoint> PatrolNodes;

	ANavigationPoint* GetNextNode(ANavigationPoint* CurrentNode, APawn* Bot);
	ANavigationPoint* GetNode(FVector Location, APawn* Bot);

};
