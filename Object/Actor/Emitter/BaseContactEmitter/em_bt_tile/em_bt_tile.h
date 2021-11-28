// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/BaseContactEmitter.h"
#include "em_bt_tile.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API Aem_bt_tile : public ABaseContactEmitter
{
	GENERATED_BODY()
public:
	Aem_bt_tile();

	void BeginPlay();
};
