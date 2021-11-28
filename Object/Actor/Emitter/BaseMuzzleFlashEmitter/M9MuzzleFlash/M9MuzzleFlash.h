// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "M9MuzzleFlash.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AM9MuzzleFlash : public ABaseMuzzleFlashEmitter
{
	GENERATED_BODY()
public:
	AM9MuzzleFlash();

	void BeginPlay();
};
