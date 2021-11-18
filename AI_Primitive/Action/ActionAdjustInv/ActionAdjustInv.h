// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/Action/Action.h"
#include "ActionAdjustInv.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AActionAdjustInv : public AAction
{
	GENERATED_BODY()
public:
	AActionAdjustInv();

	float evaluateAction();
	void executeAction();

};
