// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "Action_WAITFOREVENT.generated.h"

//class ATriggeredCondition;

UCLASS()
class AA29_API UAction_WAITFOREVENT : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UAction_WAITFOREVENT();


	//UPROPERTY()														ATriggeredCondition* t;						//var TriggeredCondition t;
	UPROPERTY(EditAnywhere, Category = "Action")					FName ExternalEvent;						//var(Action) name ExternalEvent;

	bool InitActionFor(UScriptedController* C);
	bool CompleteWhenTriggered();
	FString GetActionString();
};
