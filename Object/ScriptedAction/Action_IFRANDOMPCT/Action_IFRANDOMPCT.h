// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_IFRANDOMPCT.generated.h"

class AScriptedController;
UCLASS()
class UAction_IFRANDOMPCT : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_IFRANDOMPCT();

	UPROPERTY(EditAnywhere, Category = "Action")		float Probability;						//var(Action) float Probability;

	void ProceedToNextAction(AScriptedController* C);
	bool StartsSection();
};
