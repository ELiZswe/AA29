// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_KeepCurrentRotation.generated.h"

class AScriptedController;
UCLASS()
class UACTION_KeepCurrentRotation : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_KeepCurrentRotation();

	bool InitActionFor(AScriptedController* C);
};
