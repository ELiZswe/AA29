// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "BDMMuzzleFlash.generated.h"

UCLASS()
class ABDMMuzzleFlash : public ABaseMuzzleFlashEmitter
{
	GENERATED_BODY()
public:
	ABDMMuzzleFlash();

	void SpawnLight();
};
