// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/BaseContactEmitter.h"
#include "em_bt_door_breach_explosion.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API Aem_bt_door_breach_explosion : public ABaseContactEmitter
{
	GENERATED_BODY()
public:
	Aem_bt_door_breach_explosion();

	void PostBeginPlay();
	void SpawnLight();
	void BeginPlay();
};
