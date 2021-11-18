// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AAGameplay/DebugSphere/DebugSphere.h"
#include "DebugSphereVisual.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ADebugSphereVisual : public ADebugSphere
{
	GENERATED_BODY()
public:
	ADebugSphereVisual();

	UPROPERTY()								UMaterialInstance* textSphere;							//var FinalBlend textSphere;
	UPROPERTY()								float YawRate;								//var float YawRate;

	void PostBeginPlay();
};
