// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/VehicleTrigger/VehicleTrigger.h"
#include "NPCVehicle_Trigger.generated.h"

UCLASS()
class ANPCVehicle_Trigger : public AVehicleTrigger
{
	GENERATED_BODY()
public:
	ANPCVehicle_Trigger();
	
	UPROPERTY(EditAnywhere)				bool	bMoveToDestination;			//var() bool bMoveToDestination;
	UPROPERTY(EditAnywhere)				FName	DestinationTag;				//var() FName DestinationTag;
	UPROPERTY(EditAnywhere)				bool	bIgnoreIfFighting;			//var() bool bIgnoreIfFighting;
	UPROPERTY(EditAnywhere)				FName	VehicleTag;					//var() FName VehicleTag;
	UPROPERTY(EditAnywhere)				float	MoveDelay;					//var() float MoveDelay;

	void Trigger(AActor* Other, APawn* EventInstigator);
};
