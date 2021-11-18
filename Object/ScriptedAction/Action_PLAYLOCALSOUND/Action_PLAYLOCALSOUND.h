// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "Action_PLAYLOCALSOUND.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_PLAYLOCALSOUND : public UScriptedAction
{
	GENERATED_BODY()
public:
	UAction_PLAYLOCALSOUND();

	UPROPERTY(EditAnywhere, Category = "Action")			USoundBase* Sound;				//var(Action) Sound Sound;

	bool InitActionFor(UScriptedController* C);
	FString GetActionString();

};
