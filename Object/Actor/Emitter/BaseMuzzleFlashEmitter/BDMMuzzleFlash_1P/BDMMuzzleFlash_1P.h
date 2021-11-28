// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "BDMMuzzleFlash_1P.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABDMMuzzleFlash_1P : public ABaseMuzzleFlashEmitter
{
	GENERATED_BODY()
public:
	ABDMMuzzleFlash_1P();

	void SpawnLight();
};
