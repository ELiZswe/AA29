// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "MaterialTrigger.generated.h"

UCLASS()
class AMaterialTrigger : public ATriggers
{
	GENERATED_BODY()
public:
	AMaterialTrigger();
	
	UPROPERTY(EditAnywhere)		TArray<UMaterialInstance*>		MaterialsToTrigger;			//var() TArray<Material> MaterialsToTrigger;

	void PostBeginPlay();
	void Trigger(AActor* Other, APawn* EventInstigator);
};
