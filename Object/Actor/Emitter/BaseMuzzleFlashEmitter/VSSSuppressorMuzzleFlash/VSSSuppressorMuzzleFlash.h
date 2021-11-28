// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "VSSSuppressorMuzzleFlash.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AVSSSuppressorMuzzleFlash : public ABaseMuzzleFlashEmitter
{
	GENERATED_BODY()
public:
	AVSSSuppressorMuzzleFlash();

	void BeginPlay();
};
