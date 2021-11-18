// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_CHANGESCRIPT.generated.h"

class AScriptedSequence;

UCLASS()
class AA29_API UAction_CHANGESCRIPT : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_CHANGESCRIPT();

	UPROPERTY()											AScriptedSequence* NextScript;		//var ScriptedSequence NextScript;
	UPROPERTY(EditAnywhere, Category = "Action")		FName NextScriptTag;				//var(Action) name NextScriptTag;

	AScriptedSequence* GetScript(AScriptedSequence* S);
	bool InitActionFor(UScriptedController* C);

};
