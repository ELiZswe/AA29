// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDCompassPoint/UIHUDCompassPoint.h"
#include "UIHUDCompassPointV.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIHUDCompassPointV : public UUIHUDCompassPoint
{
	GENERATED_BODY()
public:
	UUIHUDCompassPointV();

	UPROPERTY()										FVector _TrackingLocation;							//var Object.Vector _TrackingLocation;

	void setVector(FVector pTrack);
	FVector GetLocation();

};
