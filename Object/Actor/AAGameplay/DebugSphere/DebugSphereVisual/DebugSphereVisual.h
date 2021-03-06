// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AAGameplay/DebugSphere/DebugSphere.h"
#include "DebugSphereVisual.generated.h"

UCLASS()
class ADebugSphereVisual : public ADebugSphere
{
	GENERATED_BODY()
public:
	ADebugSphereVisual();

	UPROPERTY()								UMaterialInstance* textSphere;							//var FinalBlend textSphere;
	UPROPERTY()								float YawRate;								//var float YawRate;

	void PostBeginPlay();
};
