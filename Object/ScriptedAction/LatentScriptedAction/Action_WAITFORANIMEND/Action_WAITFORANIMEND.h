// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "Action_WAITFORANIMEND.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_WAITFORANIMEND : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UAction_WAITFORANIMEND();


	UPROPERTY(EditAnywhere, Category = "Action")					int32 Channel;						//var(Action) int Channel;

	bool CompleteOnAnim(int32 Num);
};
