// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_RUN.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_RUN : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_RUN();

	bool InitActionFor(UScriptedController* C);
};
