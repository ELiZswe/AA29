// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_DESTROYPAWN.generated.h"

class AScriptedController;
UCLASS()
class UAction_DESTROYPAWN : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_DESTROYPAWN();

	bool InitActionFor(AScriptedController* C);
};
