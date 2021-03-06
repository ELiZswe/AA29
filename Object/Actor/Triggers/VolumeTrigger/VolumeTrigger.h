// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "VolumeTrigger.generated.h"

UCLASS()
class AVolumeTrigger : public ATriggers
{
	GENERATED_BODY()
public:
	AVolumeTrigger();
	
	void Trigger(AActor* Other, APawn* EventInstigator);
};
