// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "AK74suMuzzleFlash.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAK74suMuzzleFlash : public ABaseMuzzleFlashEmitter
{
	GENERATED_BODY()
public:
	AAK74suMuzzleFlash();

	void BeginPlay();
};
