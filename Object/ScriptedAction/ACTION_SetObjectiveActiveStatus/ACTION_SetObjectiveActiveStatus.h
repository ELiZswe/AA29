// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_SetObjectiveActiveStatus.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_SetObjectiveActiveStatus : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_SetObjectiveActiveStatus();

	UPROPERTY(EditAnywhere, Category = "Action")			bool bActive;					//var(Action) bool bActive;
	UPROPERTY(EditAnywhere, Category = "Action")			FName ObjectiveTag;				//var(Action) name ObjectiveTag;

	bool InitActionFor(UScriptedController* C);
	FString GetActionString();

};
