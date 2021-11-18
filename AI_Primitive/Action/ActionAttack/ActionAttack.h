// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/Action/Action.h"
#include "ActionAttack.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AActionAttack : public AAction
{
	GENERATED_BODY()
public:
	AActionAttack();

	float evaluateAction();
	void executeAction();

};
