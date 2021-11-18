// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/NavigationPoint/SmallNavigationPoint/SmallNavigationPoint.h"
#include "Teleporter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATeleporter : public ASmallNavigationPoint
{
	GENERATED_BODY()
public:
	ATeleporter();

	UPROPERTY(EditAnywhere)													FString URL;								//var() string URL;
	UPROPERTY(EditAnywhere)													FName ProductRequired;						//var() name ProductRequired;
	UPROPERTY(EditAnywhere)													bool bChangesVelocity;						//var() bool bChangesVelocity;
	UPROPERTY(EditAnywhere)													bool bChangesYaw;							//var() bool bChangesYaw;
	UPROPERTY(EditAnywhere)													bool bReversesX;							//var() bool bReversesX;
	UPROPERTY(EditAnywhere)													bool bReversesY;							//var() bool bReversesY;
	UPROPERTY(EditAnywhere)													bool bReversesZ;							//var() bool bReversesZ;
	UPROPERTY(EditAnywhere)													bool bEnabled;								//var() bool bEnabled;
	UPROPERTY(EditAnywhere)													FVector TargetVelocity;						//var() FVector TargetVelocity;
	UPROPERTY()																AActor* TriggerActor;						//var Actor TriggerActor;
	UPROPERTY()																AActor* TriggerActor2;						//var Actor TriggerActor2;
	UPROPERTY()																float LastFired;							//var float LastFired;
};
