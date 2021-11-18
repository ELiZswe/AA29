// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/NavigationPoint/NavigationPoint.h"
#include "Ambushpoint.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAmbushpoint : public ANavigationPoint
{
	GENERATED_BODY()
public:
	AAmbushpoint();

	UPROPERTY(EditAnywhere)										bool bSniping;									//var() bool bSniping;
	UPROPERTY(EditAnywhere)										float SightRadius;								//var() float SightRadius;
	UPROPERTY()													uint8 survivecount;								//var byte survivecount;
	UPROPERTY()													FVector LookDir;								//var Object.Vector LookDir;

	void PreBeginPlay();
};
