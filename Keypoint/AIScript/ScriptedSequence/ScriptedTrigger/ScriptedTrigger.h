// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"
#include "ScriptedTrigger.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AScriptedTrigger : public AScriptedSequence
{
	GENERATED_BODY()
public:
	AScriptedTrigger(const FObjectInitializer& objectInitializer);

	//UPROPERTY()			AScriptedTriggerController* TriggerController;							//var ScriptedTriggerController TriggerController;


	void PostBeginPlay();
	void NextNeededEvent();
	void TriggersEvent(FName E);
	void ValidAction(int32 N);
	void Reset();

};
