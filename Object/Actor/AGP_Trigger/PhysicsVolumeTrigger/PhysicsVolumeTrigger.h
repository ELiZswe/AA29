// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AGP_Trigger/AGP_Trigger.h"
#include "PhysicsVolumeTrigger.generated.h"

UCLASS()
class APhysicsVolumeTrigger : public AAGP_Trigger
{
	GENERATED_BODY()
public:
	APhysicsVolumeTrigger();

	void Trigger(AActor* Other, APawn* EventInstigator);
};
