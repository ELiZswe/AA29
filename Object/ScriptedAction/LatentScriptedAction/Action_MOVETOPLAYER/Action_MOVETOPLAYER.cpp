// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_MOVETOPLAYER/Action_MOVETOPLAYER.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_MOVETOPLAYER::UAction_MOVETOPLAYER()
{
	
	ActionString = "Move to player";
	bValidForTrigger = false;
}

bool UAction_MOVETOPLAYER::MoveToGoal()
{
	return true;
}

AActor* UAction_MOVETOPLAYER::GetMoveTargetFor(AScriptedController* C)
{
	return C->GetMyPlayer();
}
