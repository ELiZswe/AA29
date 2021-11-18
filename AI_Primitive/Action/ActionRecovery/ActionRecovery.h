// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/Action/Action.h"
#include "ActionRecovery.generated.h"

/**
 * 
 */
class APickup;

UCLASS()
class AA29_API AActionRecovery : public AAction
{
	GENERATED_BODY()
public:
	AActionRecovery();

	UPROPERTY()																			APickup* recovery_pickup;					//var Pickup recovery_pickup;

	float evaluateAction();
	void executeAction();
};
