// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_LEAVESEQUENCE.generated.h"

class AScriptedSequence;
UCLASS()
class UAction_LEAVESEQUENCE : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_LEAVESEQUENCE();

	AScriptedSequence* GetScript(AScriptedSequence* S);
};
