// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/BaseContactEmitter.h"
#include "em_bt_grenexplosionB.generated.h"

UCLASS()
class Aem_bt_grenexplosionB : public ABaseContactEmitter
{
	GENERATED_BODY()
public:
	Aem_bt_grenexplosionB();

	void PostBeginPlay();
	void SpawnLight();
	void BeginPlay();
};
