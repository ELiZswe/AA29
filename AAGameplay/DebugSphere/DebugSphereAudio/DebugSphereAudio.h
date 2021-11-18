// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AAGameplay/DebugSphere/DebugSphere.h"
#include "DebugSphereAudio.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ADebugSphereAudio : public ADebugSphere
{
	GENERATED_BODY()
public:
	ADebugSphereAudio();


	UPROPERTY()								UMaterialInstance* textSphere;				//var FinalBlend textSphere;
	UPROPERTY()								float YawRate;								//var float YawRate;

	void PostBeginPlay();
};
