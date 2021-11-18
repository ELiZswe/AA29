// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_ActivateCROWS.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_ActivateCROWS : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_ActivateCROWS();

	bool InitActionFor(UScriptedController* C);
};
