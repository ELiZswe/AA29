// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "RPG7MuzzleFlash.generated.h"

UCLASS()
class ARPG7MuzzleFlash : public ABaseMuzzleFlashEmitter
{
	GENERATED_BODY()
public:
	ARPG7MuzzleFlash();

	void DynamicFlash();
};
