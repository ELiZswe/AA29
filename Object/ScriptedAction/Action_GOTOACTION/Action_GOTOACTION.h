// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_GOTOACTION.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_GOTOACTION : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_GOTOACTION();

	UPROPERTY(EditAnywhere, Category = "Action")		int32 ActionNumber;			//var(Action) int ActionNumber;

	void ProceedToNextAction(UScriptedController* C);
	FString GetActionString();

};
