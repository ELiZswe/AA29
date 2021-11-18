// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_TURNTOWARDPLAYER/Action_TURNTOWARDPLAYER.h"

UAction_TURNTOWARDPLAYER::UAction_TURNTOWARDPLAYER()
{
	ActionString = "Turn toward player";
	bValidForTrigger = false;
}


bool UAction_TURNTOWARDPLAYER::InitActionFor(UScriptedController* C)
{
	/*
	C.ScriptedFocus = C.GetMyPlayer();
	C.CurrentAction = Self;
	*/
	return true;
}
bool UAction_TURNTOWARDPLAYER::TurnToGoal()
{
	return true;
}
void UAction_TURNTOWARDPLAYER::GetMoveTargetFor(UScriptedController* C)
{
	//return C.GetMyPlayer();
}
