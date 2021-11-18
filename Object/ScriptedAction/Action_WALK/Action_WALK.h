// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_WALK.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_WALK : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_WALK();

	bool InitActionFor(UScriptedController* C);
};
