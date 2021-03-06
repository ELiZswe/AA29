// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "LatentScriptedAction.generated.h"

class AScriptedController;
UCLASS()
class ULatentScriptedAction : public UScriptedAction
{
	GENERATED_BODY()
public:
	ULatentScriptedAction();

	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	bool InitActionFor(AScriptedController* C);
	bool CompleteWhenTriggered();
	bool CompleteOnAnim(int32 Channel);
	bool CompleteOnLIPSincAnim();
	bool CompleteWhenTimer();
	bool WaitForPlayer();
	bool TickedAction();
	bool StillTicking(AScriptedController* C, float DeltaTime);
	bool MoveToGoal();
	bool TurnToGoal();
	AActor* GetMoveTargetFor(AScriptedController* C);
	float GetDistance();
};
