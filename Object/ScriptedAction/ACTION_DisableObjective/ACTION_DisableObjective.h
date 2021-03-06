// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_DisableObjective.generated.h"

class AGameObjective;

class AScriptedController;
class AScriptedSequence;
UCLASS()
class UACTION_DisableObjective : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_DisableObjective();

	UPROPERTY()											AGameObjective* GO;						//var GameObjective GO;
	UPROPERTY(EditAnywhere, Category = "Action")		bool bTriggerObjectiveInstantly;		//var(Action) bool bTriggerObjectiveInstantly;
	UPROPERTY(EditAnywhere, Category = "Action")		bool bClearInstigator;					//var(Action) bool bClearInstigator;
	UPROPERTY(EditAnywhere, Category = "Action")		FName ObjectiveTag;						//var(Action) name ObjectiveTag;


	void PostBeginPlay(AScriptedSequence* SS);
	bool InitActionFor(AScriptedController* C);
	FString GetActionString();
};
