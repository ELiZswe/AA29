// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_ConsoleCommand.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_ConsoleCommand : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_ConsoleCommand();

	UPROPERTY(EditAnywhere, Category = "Action")		FString CommandStr;		//var(Action) string CommandStr;

	bool InitActionFor(UScriptedController* C);
	FString GetActionString();
};
