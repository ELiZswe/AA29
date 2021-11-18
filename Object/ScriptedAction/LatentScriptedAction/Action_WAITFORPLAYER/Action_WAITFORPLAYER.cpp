// All the original content belonged to the US Army


#include "AA29/Object/ScriptedAction/LatentScriptedAction/Action_WAITFORPLAYER/Action_WAITFORPLAYER.h"

UAction_WAITFORPLAYER::UAction_WAITFORPLAYER()
{
	Distance = 150;
	ActionString = "Wait for player";
	bValidForTrigger = false;
}


bool UAction_WAITFORPLAYER::InitActionFor(UScriptedController* C)
{
	/*
	if (C.CheckIfNearPlayer(Distance))
	{
		Return False;
	}
	C.CurrentAction = Self;
	C.SetTimer(0.1, True);
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