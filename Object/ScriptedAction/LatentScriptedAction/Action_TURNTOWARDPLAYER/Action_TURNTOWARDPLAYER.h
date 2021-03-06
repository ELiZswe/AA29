// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "Action_TURNTOWARDPLAYER.generated.h"

class AScriptedController;
UCLASS()
class UAction_TURNTOWARDPLAYER : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UAction_TURNTOWARDPLAYER();

	bool InitActionFor(AScriptedController* C);
	bool TurnToGoal();
	AActor* GetMoveTargetFor(AScriptedController* C);
};
