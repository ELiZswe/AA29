// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/BaseContactEmitter.h"
#include "em_bt_glasspane.generated.h"

UCLASS()
class Aem_bt_glasspane : public ABaseContactEmitter
{
	GENERATED_BODY()
public:
	Aem_bt_glasspane();

	TSubclassOf<class AActor> MyItemBlueprint;

	void Trigger(AActor* Other, APawn* EventInstigator);
};
