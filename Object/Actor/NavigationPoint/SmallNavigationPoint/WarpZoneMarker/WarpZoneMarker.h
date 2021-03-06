// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/SmallNavigationPoint.h"
#include "WarpZoneMarker.generated.h"

class AWarpZoneInfo;

UCLASS()
class AWarpZoneMarker : public ASmallNavigationPoint
{
	GENERATED_BODY()
public:
	AWarpZoneMarker();

	UPROPERTY()				AWarpZoneInfo*	markedWarpZone;			//var WarpZoneInfo markedWarpZone;
	UPROPERTY()				AActor*			TriggerActor;			//var Actor TriggerActor;
	UPROPERTY()				AActor*			TriggerActor2;			//var Actor TriggerActor2;

	void PostBeginPlay();
	void FindTriggerActor();
	AActor* SpecialHandling(APawn* Other);
};
