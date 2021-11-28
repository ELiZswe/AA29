// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "RPG7MuzzleFlash_1P.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ARPG7MuzzleFlash_1P : public ABaseMuzzleFlashEmitter
{
	GENERATED_BODY()
public:
	ARPG7MuzzleFlash_1P();

	void DynamicFlash();
};
