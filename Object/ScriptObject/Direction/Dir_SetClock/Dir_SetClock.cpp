// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetClock/Dir_SetClock.h"

UDir_SetClock::UDir_SetClock()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}


void UDir_SetClock::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetClock::DirectionStart()");
	}
	if (_bCountdown)
	{
		_ParentScreenplay.Level.Game.GameReplicationInfo.TimeLimit = 10000;
		_ParentScreenplay.Level.Game.GameReplicationInfo.RemainingTime = int(_fTime);
		_ParentScreenplay.Level.Game.GameReplicationInfo.bStopCountDown = false;
	}
	else
	{
		_ParentScreenplay.Level.Game.GameReplicationInfo.TimeLimit = -1;
		_ParentScreenplay.Level.Game.GameReplicationInfo.RemainingTime = int(_fTime);
		_ParentScreenplay.Level.Game.GameReplicationInfo.bStopCountDown = true;
	}
	*/
}

void UDir_SetClock::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetClock::DirectionFinish()");
	}
	*/
}

bool UDir_SetClock::ProcessParams()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetClock::ProcessParams()");
	}
	_fTime = float(GetParam(0));
	_bCountdown = bool(GetParam(1));
	*/
	return true;
}