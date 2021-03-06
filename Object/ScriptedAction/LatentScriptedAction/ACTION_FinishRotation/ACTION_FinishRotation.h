// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "ACTION_FinishRotation.generated.h"

UCLASS()
class UACTION_FinishRotation : public ULatentScriptedAction
{
	GENERATED_BODY()
public:
	UACTION_FinishRotation();

	bool TurnToGoal();
};
