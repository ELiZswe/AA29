// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/Action/Action.h"
#include "ActionIdle.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AActionIdle : public AAction
{
	GENERATED_BODY()
public:
	AActionIdle();

	float evaluateAction();
	void executeAction();

};
