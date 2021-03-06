// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "ACTION_Freeze.generated.h"

class AScriptedController;
UCLASS()
class UACTION_Freeze : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_Freeze();

	bool InitActionFor(AScriptedController* C);
};
