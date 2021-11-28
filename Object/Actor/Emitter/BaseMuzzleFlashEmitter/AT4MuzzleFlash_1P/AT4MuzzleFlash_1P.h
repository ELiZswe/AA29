// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "AT4MuzzleFlash_1P.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAT4MuzzleFlash_1P : public ABaseMuzzleFlashEmitter
{
	GENERATED_BODY()
public:
	AAT4MuzzleFlash_1P();

	void SpawnLight();
};
