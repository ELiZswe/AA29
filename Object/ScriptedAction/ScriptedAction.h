// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ScriptedAction.generated.h"

class AScriptedSequence;
class AScriptedController;

UCLASS()
class AA29_API UScriptedAction : public UObject
{
	GENERATED_BODY()
public:
	UScriptedAction();

	UPROPERTY()						bool bValidForTrigger;						//var bool bValidForTrigger;
	UPROPERTY()						FString ActionString;						//var localized string ActionString;

	void ActionCompleted();
	void PostBeginPlay(AScriptedSequence* SS);
	void Reset();
	bool InitActionFor(AScriptedController* C);
	bool EndsSection();
	bool StartsSection();
	AScriptedSequence* GetScript(AScriptedSequence* S);
	void ProceedToNextAction(AScriptedController* C);
	void ProceedToSectionEnd(AScriptedController* C);
	FString GetActionString();
};
