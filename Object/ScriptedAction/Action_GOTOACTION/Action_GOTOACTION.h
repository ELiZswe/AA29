// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_GOTOACTION.generated.h"

class AScriptedController;
UCLASS()
class UAction_GOTOACTION : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_GOTOACTION();

	UPROPERTY(EditAnywhere, Category = "Action")		int32 ActionNumber;			//var(Action) int ActionNumber;

	void ProceedToNextAction(AScriptedController* C);
	FString GetActionString();

};
