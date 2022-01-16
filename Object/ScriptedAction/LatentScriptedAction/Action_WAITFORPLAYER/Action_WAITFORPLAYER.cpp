// All the original content belonged to the US Army

#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_WAITFORPLAYER/Action_WAITFORPLAYER.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"

UAction_WAITFORPLAYER::UAction_WAITFORPLAYER()
{
	Distance = 150;
	ActionString = "Wait for player";
	bValidForTrigger = false;
}

bool UAction_WAITFORPLAYER::InitActionFor(AScriptedController* C)
{
	/*
	if (C.CheckIfNearPlayer(Distance))
	{
		return false;
	}
	C.CurrentAction = this;
	C.SetTimer(0.1, true);
	*/
	return true;
}
float UAction_WAITFORPLAYER::GetDistance()
{
	return Distance;
}
bool UAction_WAITFORPLAYER::WaitForPlayer()
{
	return true;
}
