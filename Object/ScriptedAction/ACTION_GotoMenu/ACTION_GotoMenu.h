// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_GotoMenu.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_GotoMenu : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_GotoMenu();

	UPROPERTY(EditAnywhere, Category = "Action")		bool bDisconnect;			//var(Action) bool bDisconnect;
	UPROPERTY(EditAnywhere, Category = "Action")		FString MenuName;			//var(Action) config string MenuName;

	bool InitActionFor(UScriptedController* C);
	FString GetMenuName();
	FString GetActionString();

};
