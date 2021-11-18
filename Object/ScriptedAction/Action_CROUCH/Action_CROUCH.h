// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_CROUCH.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_CROUCH : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_CROUCH();
	bool InitActionFor(UScriptedController* C);
};
