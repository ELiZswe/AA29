// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "AA29/MyStructs.h"
#include "Action_SETALERTNESS.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_SETALERTNESS : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_SETALERTNESS();

	UPROPERTY(EditAnywhere, Category = "Action")			EAlertnessType Alertness;			//var(Action) EAlertnessType Alertness;

	bool InitActionFor(UScriptedController* C);
	FString GetActionString();

};
