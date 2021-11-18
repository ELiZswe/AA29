// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "ACTION_Freeze.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_Freeze : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_Freeze();

	bool InitActionFor(UScriptedController* C);
};
