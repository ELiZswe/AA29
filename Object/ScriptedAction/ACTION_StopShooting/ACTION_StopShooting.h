// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_StopShooting.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_StopShooting : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_StopShooting();

	bool InitActionFor(UScriptedController* C);
};
