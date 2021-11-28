// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/BaseContactEmitter.h"
#include "em_bt_grass.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API Aem_bt_grass : public ABaseContactEmitter
{
	GENERATED_BODY()
public:
	Aem_bt_grass();

	void BeginPlay();
};
