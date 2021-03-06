// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"
#include "ScriptedTrigger.generated.h"

class AScriptedTriggerController;

UCLASS()
class AScriptedTrigger : public AScriptedSequence
{
	GENERATED_BODY()
public:
	AScriptedTrigger(const FObjectInitializer& objectInitializer);

	UPROPERTY()			AScriptedTriggerController* TriggerController;							//var ScriptedTriggerController TriggerController;

	void PostBeginPlay();
	FName NextNeededEvent();
	bool TriggersEvent(FName E);
	bool ValidAction(int32 N);
	void Reset();
};
