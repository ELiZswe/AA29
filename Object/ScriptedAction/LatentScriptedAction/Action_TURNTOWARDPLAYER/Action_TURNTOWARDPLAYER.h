// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "Action_TURNTOWARDPLAYER.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_TURNTOWARDPLAYER : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UAction_TURNTOWARDPLAYER();

	bool InitActionFor(UScriptedController* C);
	bool TurnToGoal();
	void GetMoveTargetFor(UScriptedController* C);

};
