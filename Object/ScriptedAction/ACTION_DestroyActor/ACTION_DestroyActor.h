// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_DestroyActor.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_DestroyActor : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_DestroyActor();

	UPROPERTY(EditAnywhere, Category = "Action")		FName DestroyTag;						//var(Action) name DestroyTag;

	bool InitActionFor(UScriptedController* C);
};
