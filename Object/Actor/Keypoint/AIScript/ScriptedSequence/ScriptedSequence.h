// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Keypoint/AIScript/AIScript.h"
#include "ScriptedSequence.generated.h"

class UScriptedAction;
class AScriptedController;

UCLASS()
class AScriptedSequence : public AAIScript
{
	GENERATED_BODY()
public:
	AScriptedSequence(const FObjectInitializer& objectInitializer);

	UPROPERTY()											AScriptedController*		ScriptControllerClass;				//var class<ScriptedController> ScriptControllerClass;
	UPROPERTY(EditAnywhere, Category = "AIScript")		TArray<UScriptedAction*>	Actions;							//var(AIScript) array<ScriptedAction> Actions;

	void PostBeginPlay();
	void Reset();
	void SpawnControllerFor(APawn* p);
	void CheckForErrors();
	void TakeOver(APawn* p);
	bool ValidAction(int32 N);
	void SetActions(AScriptedController* C);
};
