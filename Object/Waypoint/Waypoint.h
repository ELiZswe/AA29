// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Waypoint.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UWaypoint : public UObject
{
	GENERATED_BODY()
public:
	UWaypoint();

	UPROPERTY()										UWaypoint* NextWaypoint;			//var Waypoint NextWaypoint;
	UPROPERTY()										FVector Location;					//var Object.Vector Location;

};
