// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_WALK.generated.h"

class AScriptedController;
UCLASS()
class UAction_WALK : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_WALK();

	bool InitActionFor(AScriptedController* C);
};
