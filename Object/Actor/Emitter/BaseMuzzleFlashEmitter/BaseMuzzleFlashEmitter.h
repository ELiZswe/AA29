// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "BaseMuzzleFlashEmitter.generated.h"

class ALight;

UCLASS()
class AA29_API ABaseMuzzleFlashEmitter : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	ABaseMuzzleFlashEmitter();

	UPROPERTY()		ALight* MuzzleFlashLight;								//var class<Light> MuzzleFlashLight;

	void DynamicFlash();
};
