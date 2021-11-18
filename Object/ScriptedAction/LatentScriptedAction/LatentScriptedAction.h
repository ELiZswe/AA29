// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptedAction/ScriptedAction.h"
#include "LatentScriptedAction.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ULatentScriptedAction : public UScriptedAction
{
	GENERATED_BODY()
public:
	ULatentScriptedAction();


	void DisplayDebug(UCanvas* Canvas, float& YL, float& YPos);
	bool InitActionFor(UScriptedController* C);
	bool CompleteWhenTriggered();
	bool CompleteOnAnim(int32 Channel);
	bool CompleteOnLIPSincAnim();
	bool CompleteWhenTimer();
	bool WaitForPlayer();
	bool TickedAction();
	bool StillTicking(UScriptedController* C, float DeltaTime);
	bool MoveToGoal();
	bool TurnToGoal();
	void GetMoveTargetFor(UScriptedController* C);
	int32 GetDistance();
};
