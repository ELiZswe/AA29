// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "Action_MOVETOPLAYER.generated.h"

class AScriptedController;
UCLASS()
class UAction_MOVETOPLAYER : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UAction_MOVETOPLAYER();

	bool MoveToGoal();
	AActor* GetMoveTargetFor(AScriptedController* C);
};
