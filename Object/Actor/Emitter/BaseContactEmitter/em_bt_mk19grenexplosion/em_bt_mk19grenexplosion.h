// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/BaseContactEmitter.h"
#include "em_bt_mk19grenexplosion.generated.h"

UCLASS()
class Aem_bt_mk19grenexplosion : public ABaseContactEmitter
{
	GENERATED_BODY()
public:
	Aem_bt_mk19grenexplosion();

	void BeginPlay();
};
