// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_ConsoleCommand.generated.h"

class AScriptedController;
UCLASS()
class UACTION_ConsoleCommand : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_ConsoleCommand();

	UPROPERTY(EditAnywhere, Category = "Action")		FString CommandStr;		//var(Action) string CommandStr;

	bool InitActionFor(AScriptedController* C);
	FString GetActionString();
};
