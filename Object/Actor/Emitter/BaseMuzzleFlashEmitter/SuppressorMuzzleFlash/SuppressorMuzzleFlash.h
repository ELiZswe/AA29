// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "SuppressorMuzzleFlash.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ASuppressorMuzzleFlash : public ABaseMuzzleFlashEmitter
{
	GENERATED_BODY()
public:
	ASuppressorMuzzleFlash();

	void BeginPlay();
};
