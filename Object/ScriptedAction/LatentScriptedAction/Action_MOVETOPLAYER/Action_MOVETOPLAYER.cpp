// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_MOVETOPLAYER/Action_MOVETOPLAYER.h"

UAction_MOVETOPLAYER::UAction_MOVETOPLAYER()
{
	
	ActionString = "Move to player";
	bValidForTrigger = false;
}



bool UAction_MOVETOPLAYER::MoveToGoal()
{
	return true;
}
void UAction_MOVETOPLAYER::GetMoveTargetFor(UScriptedController* C)
{
	//Return C.GetMyPlayer();
}