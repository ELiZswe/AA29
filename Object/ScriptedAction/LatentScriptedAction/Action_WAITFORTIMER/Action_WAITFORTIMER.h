// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "Action_WAITFORTIMER.generated.h"

class AScriptedController;
UCLASS()
class UAction_WAITFORTIMER : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UAction_WAITFORTIMER();



	UPROPERTY(EditAnywhere, Category = "Action")					float PauseTime;						//var(Action) float PauseTime;


	bool InitActionFor(AScriptedController* C);
	bool CompleteWhenTriggered();
	bool CompleteWhenTimer();

	FString GetActionString();
};
