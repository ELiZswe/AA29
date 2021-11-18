// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "ACTION_SetCorona.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UACTION_SetCorona : public UScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_SetCorona();

	UPROPERTY(EditAnywhere, Category = "Action")			FName HideActorTag;			//var(Action) name HideActorTag;
	UPROPERTY(EditAnywhere, Category = "Action")			bool bCorona;				//var(Action) bool bCorona;

	bool InitActionFor(UScriptedController* C);
};
