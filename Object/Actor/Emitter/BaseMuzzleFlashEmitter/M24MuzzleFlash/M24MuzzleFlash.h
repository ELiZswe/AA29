// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "M24MuzzleFlash.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AM24MuzzleFlash : public ABaseMuzzleFlashEmitter
{
	GENERATED_BODY()
public:
	AM24MuzzleFlash();

	void BeginPlay();
};
