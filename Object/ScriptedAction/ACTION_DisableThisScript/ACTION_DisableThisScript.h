// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_DisableThisScript.generated.h"

class AScriptedController;
UCLASS()
class UACTION_DisableThisScript : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_DisableThisScript();

	bool InitActionFor(AScriptedController* C);
};
