// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "Action_MOVETOPLAYER.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAction_MOVETOPLAYER : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UAction_MOVETOPLAYER();

	bool MoveToGoal();
	void GetMoveTargetFor(UScriptedController* C);


};
