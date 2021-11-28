// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_StopClock/Dir_StopClock.h"

UDir_StopClock::UDir_StopClock()
{
	bSupportsMP = true;
}

void UDir_StopClock::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_StopClock::DirectionStart()");
	}
	_ParentScreenplay.Level.Game.GameReplicationInfo.bStopCountDown = true;
	*/
}

void UDir_StopClock::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_StopClock::DirectionFinish()");
	}
	*/
}

bool UDir_StopClock::ProcessParams()
{
	/*
	if (_bDebug)
	{
		Log("Dir_StopClock::ProcessParams()");
	}
	*/
	return true;
}
