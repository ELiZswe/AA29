// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/BaseContactEmitter.h"
#include "aux_em_mortar.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API Aaux_em_mortar : public ABaseContactEmitter
{
	GENERATED_BODY()
public:
	Aaux_em_mortar();
		
	void PostBeginPlay();
	void SpawnLight();
};
