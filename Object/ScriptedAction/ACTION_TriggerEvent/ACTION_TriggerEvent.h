// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_TriggerEvent.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_TriggerEvent : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_TriggerEvent();


	UPROPERTY(EditAnywhere, Category ="Action")						FName Event;						//var(Action) name Event;

	bool InitActionFor(UScriptedController* C);
	FString GetActionString();

};
