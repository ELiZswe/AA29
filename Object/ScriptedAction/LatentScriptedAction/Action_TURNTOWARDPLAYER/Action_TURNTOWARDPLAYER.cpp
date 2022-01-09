// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_TURNTOWARDPLAYER/Action_TURNTOWARDPLAYER.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_TURNTOWARDPLAYER::UAction_TURNTOWARDPLAYER()
{
	ActionString = "Turn toward player";
	bValidForTrigger = false;
}

bool UAction_TURNTOWARDPLAYER::InitActionFor(AScriptedController* C)
{
	/*
	C.ScriptedFocus = C.GetMyPlayer();
	C.CurrentAction = this;
	*/
	return true;
}
bool UAction_TURNTOWARDPLAYER::TurnToGoal()
{
	return true;
}

AActor* UAction_TURNTOWARDPLAYER::GetMoveTargetFor(AScriptedController* C)
{
	//return C.GetMyPlayer();
	return nullptr;    //FAKE   /EliZ
}
