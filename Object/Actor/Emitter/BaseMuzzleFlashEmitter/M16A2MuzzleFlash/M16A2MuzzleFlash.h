// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "M16A2MuzzleFlash.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AM16A2MuzzleFlash : public ABaseMuzzleFlashEmitter
{
	GENERATED_BODY()
public:
	AM16A2MuzzleFlash();

	void BeginPlay();
};
