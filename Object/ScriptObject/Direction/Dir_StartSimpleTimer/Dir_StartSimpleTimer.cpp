// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_StartSimpleTimer/Dir_StartSimpleTimer.h"
#include "AA29/Object/Actor/AGP_Timer/AGP_Timer.h"
#include "AA29/Object/Sound/Sound.h"

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
	if (_timer != nullptr)
	{
		if (TimerSound == nullptr)
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
		Log("Dir_StartSimpleTimer::DirectionStart(): Error: _Timer is None for tag: " + FString::FromInt(TimerTag));
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
	if (_timer != nullptr)
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
	TimerTag = FString::FromInt(GetParam(0));
	Delay = float(GetParam(1));
	TimerSound = Sound(DynamicLoadObject(GetParam(2), USound::StaticClass()));
	_timer = AGP_Timer(_ParentScreenplay.GetActorByTag(TimerTag));
	if (_timer == nullptr)
	{
		_timer = _ParentScreenplay.Spawn(AAGP_Timer::StaticClass(), , TimerTag);
	}
	if (_timer == nullptr)
	{
		Log("Dir_StartSimpleTimer::DirectionStart(): Error: Could not spawn AGP_Timer");
		return false;
	}
	*/
	return true;
}
