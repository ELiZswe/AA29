// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_StartSimpleTimer/Dir_StartSimpleTimer.h"

UDir_StartSimpleTimer::UDir_StartSimpleTimer()
{
	bSupportsMP = true;
	_nNumParamsDefined = 3;
}

void UDir_StartSimpleTimer::Destroyed()
{
	//Super::Destroyed();
}

void UDir_StartSimpleTimer::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_StartSimpleTimer::DirectionStart()");
	}
	if (_timer != None)
	{
		if (TimerSound == None)
		{
			_timer.Delay = Delay;
			_timer.Start(Delay);
		}
		else
		{
			_timer.Delay = (_ParentScreenplay.GetSoundDuration(TimerSound) + 0.25);
			_timer.Start(_timer.Delay);
		}
	}
	else
	{
		Log("Dir_StartSimpleTimer::DirectionStart(): Error: _Timer is None for tag: " $ string(TimerTag));
	}
	*/
}

void UDir_StartSimpleTimer::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_StartSimpleTimer::DirectionStart()");
	}
	if (_timer != None)
	{
		_timer.Finish();
	}
	*/
}

bool UDir_StartSimpleTimer::ProcessParams()
{
	/*
	if (_bDebug)
	{
		Log("Dir_StartSimpleTimer::ProcessParams()");
	}
	TimerTag = string(GetParam(0));
	Delay = float(GetParam(1));
	TimerSound = Sound(DynamicLoadObject(GetParam(2), Class'Sound'));
	_timer = AGP_Timer(_ParentScreenplay.GetActorByTag(TimerTag));
	if (_timer == None)
	{
		_timer = _ParentScreenplay.Spawn(Class'AGP_Gameplay.AGP_Timer', , TimerTag);
	}
	if (_timer == None)
	{
		Log("Dir_StartSimpleTimer::DirectionStart(): Error: Could not spawn AGP_Timer");
		return false;
	}
	*/
	return true;
}