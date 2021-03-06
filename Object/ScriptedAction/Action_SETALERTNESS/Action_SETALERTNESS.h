// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "AA29/MyEnums.h"
#include "Action_SETALERTNESS.generated.h"

class AScriptedController;
UCLASS()
class UAction_SETALERTNESS : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_SETALERTNESS();

	UPROPERTY(EditAnywhere, Category = "Action")			EAlertnessType Alertness;			//var(Action) EAlertnessType Alertness;

	bool InitActionFor(AScriptedController* C);
	FString GetActionString();

};
