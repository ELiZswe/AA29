// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AAGameplay/DebugSphere/DebugSphere.h"
#include "DebugSphereAudio.generated.h"

UCLASS()
class ADebugSphereAudio : public ADebugSphere
{
	GENERATED_BODY()
public:
	ADebugSphereAudio();


	UPROPERTY()								UMaterialInstance* textSphere;				//var FinalBlend textSphere;
	UPROPERTY()								float YawRate;								//var float YawRate;

	void PostBeginPlay();
};
