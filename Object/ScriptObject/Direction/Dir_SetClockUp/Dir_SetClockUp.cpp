// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetClockUp/Dir_SetClockUp.h"

UDir_SetClockUp::UDir_SetClockUp()
{
	bSupportsMP = true;
	_nNumParamsDefined = 1;
}

void UDir_SetClockUp::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetClockUp::DirectionStart()");
	}
	_ParentScreenplay.Level.Game.GameReplicationInfo.TimeLimit = 10000;
	_ParentScreenplay.Level.Game.GameReplicationInfo.RemainingTime = int(_fTime);
	_ParentScreenplay.Level.Game.GameReplicationInfo.bStopCountDown = false;
	_ParentScreenplay.Level.Game.GameReplicationInfo.bCountUp = true;
	*/
}

void UDir_SetClockUp::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetClockUp::DirectionFinish()");
	}
	*/
}

bool UDir_SetClockUp::ProcessParams()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetClockUp::ProcessParams()");
	}
	_fTime = float(GetParam(0));
	*/
	return true;
}