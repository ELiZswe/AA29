// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "Action_WAITFORPLAYER.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_WAITFORPLAYER : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UAction_WAITFORPLAYER();

	UPROPERTY(EditAnywhere, Category = "Action")					float Distance;						//var(Action) float Distance;

	bool InitActionFor(UScriptedController* C);
	float GetDistance();
	bool WaitForPlayer();

};
