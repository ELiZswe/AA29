// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_STOPANIMATION.generated.h"

class AScriptedController;
UCLASS()
class UAction_STOPANIMATION : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_STOPANIMATION();

	bool InitActionFor(AScriptedController* C);
};
