// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Waypoint.generated.h"

UCLASS()
class UWaypoint : public UObject
{
	GENERATED_BODY()
public:
	UWaypoint();

	UPROPERTY()				FVector			Location;
	UPROPERTY()				UWaypoint*		NextWaypoint;
};
