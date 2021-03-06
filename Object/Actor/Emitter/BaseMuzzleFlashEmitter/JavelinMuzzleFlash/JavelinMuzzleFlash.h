// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "JavelinMuzzleFlash.generated.h"

UCLASS()
class AJavelinMuzzleFlash : public ABaseMuzzleFlashEmitter
{
	GENERATED_BODY()
public:
	AJavelinMuzzleFlash();

	void BeginPlay();
	void DynamicFlash();
};
