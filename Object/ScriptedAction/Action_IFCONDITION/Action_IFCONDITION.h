// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_IFCONDITION.generated.h"

//class ATriggeredCondition;

UCLASS()
class AA29_API UAction_IFCONDITION : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_IFCONDITION();


	//UPROPERTY()											ATriggeredCondition* t;						//var TriggeredCondition t;
	UPROPERTY(EditAnywhere, Category = "Action")		FName TriggeredConditionTag;				//var(Action) name TriggeredConditionTag;

	void ProceedToNextAction(AScriptedController* C);
	bool StartsSection();
	FString GetActionString();

};
