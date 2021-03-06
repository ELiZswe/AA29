// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_SetObjectiveActiveStatus.generated.h"

class AScriptedController;
UCLASS()
class UACTION_SetObjectiveActiveStatus : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_SetObjectiveActiveStatus();

	UPROPERTY(EditAnywhere, Category = "Action")			bool bActive;					//var(Action) bool bActive;
	UPROPERTY(EditAnywhere, Category = "Action")			FName ObjectiveTag;				//var(Action) name ObjectiveTag;

	bool InitActionFor(AScriptedController* C);
	FString GetActionString();

};
