// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_CHANGELEVEL.generated.h"

class AScriptedController;
UCLASS()
class UAction_CHANGELEVEL : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_CHANGELEVEL();

	UPROPERTY(EditAnywhere, Category = "Action")		bool bShowLoadingMessage;		//var(Action) bool bShowLoadingMessage;
	UPROPERTY(EditAnywhere, Category = "Action")		FString URL;					//var(Action) string URL;

	bool InitActionFor(AScriptedController* C);
	FString GetActionString();
};
