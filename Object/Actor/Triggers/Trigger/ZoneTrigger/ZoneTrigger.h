// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "ZoneTrigger.generated.h"

UCLASS()
class AZoneTrigger : public ATrigger
{
	GENERATED_BODY()
public:
	AZoneTrigger();

	void Touch(AActor* Other);
	void UnTouch(AActor* Other);
};
