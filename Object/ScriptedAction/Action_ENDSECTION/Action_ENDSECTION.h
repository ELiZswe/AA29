// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_ENDSECTION.generated.h"

class AScriptedController;
UCLASS()
class UAction_ENDSECTION : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_ENDSECTION();

	void ProceedToNextAction(AScriptedController* C);
	bool EndsSection();
};
