// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "m2a2MuzzleFlash.generated.h"

UCLASS()
class Am2a2MuzzleFlash : public ABaseMuzzleFlashEmitter
{
	GENERATED_BODY()
public:
	Am2a2MuzzleFlash();



	UPROPERTY()								AEmitter* smokeemitter;								//var Emitter smokeemitter;
	UPROPERTY()								AEmitter* smokeclass;								//var class<Emitter> smokeclass;

	void DynamicFlash();
};
