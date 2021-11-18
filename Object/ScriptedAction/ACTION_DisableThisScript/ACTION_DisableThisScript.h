// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_DisableThisScript.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_DisableThisScript : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_DisableThisScript();

	bool InitActionFor(UScriptedController* C);
};
