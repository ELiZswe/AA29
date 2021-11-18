// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ScriptedAction.generated.h"

class AScriptedSequence;
class UScriptedController;

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
	bool InitActionFor(UScriptedController* C);
	bool EndsSection();
	bool StartsSection();
	AScriptedSequence* GetScript(AScriptedSequence* S);
	void ProceedToNextAction(UScriptedController* C);
	void ProceedToSectionEnd(UScriptedController* C);
	FString GetActionString();
};
