// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "Action_WAITFORTIMER.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_WAITFORTIMER : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UAction_WAITFORTIMER();



	UPROPERTY(EditAnywhere, Category = "Action")					float PauseTime;						//var(Action) float PauseTime;


	bool InitActionFor(UScriptedController* C);
	bool CompleteWhenTriggered();
	bool CompleteWhenTimer();

	FString GetActionString();
};
