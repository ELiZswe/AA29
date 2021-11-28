// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_StartTimer/Dir_StartTimer.h"

UDir_StartTimer::UDir_StartTimer()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}


void UDir_StartTimer::Destroyed()
{
	/*
	Super::Destroyed();
	_timer = None;
	*/
}

void UDir_StartTimer::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_StartTimer::DirectionStart()");
	}
	if (_timer != None)
	{
		_timer.Start(_Timeout);
	}
	*/
}

void UDir_StartTimer::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_StartTimer::DirectionStart()");
	}
	if (_timer != None)
	{
		_timer.Finish();
	}
	*/
}

bool UDir_StartTimer::ProcessParams()
{
	FName TimerTag = "";
	/*
	if (_bDebug)
	{
		Log("Dir_StartTimer::ProcessParams()");
	}
	TimerTag = string(GetParam(0));
	_Timeout = float(GetParam(1));
	_timer = AGP_Timer(_ParentScreenplay.GetActorByTag(TimerTag));
	if (_timer == None)
	{
		Log("Dir_StartTimer::ProcessParams() - could not get AGP_Timer with tag " $ GetParam(0));
		return false;
	}
	*/
	return true;
}