// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenTimerEnds/Cond_WhenTimerEnds.h"

UCond_WhenTimerEnds::UCond_WhenTimerEnds()
{
	_bDebug = true;
	bSupportsMP = true;
	_nNumParamsDefined = 1;
}

void UCond_WhenTimerEnds::Destroyed()
{
	Super::Destroyed();
	_timer = nullptr;
}

void UCond_WhenTimerEnds::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenTimerEnds::ConditionStart(): " @ string(TimerTag));
	}
	_timer.SetTarget(Self);
	*/
}

void UCond_WhenTimerEnds::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenTimerEnds::ConditionFinish(): " @ string(TimerTag));
	}
	_timer.SetTarget(None);
	*/
}

bool UCond_WhenTimerEnds::ProcessParams()
{
	/*
	TimerTag = string(GetParam(0));
	_timer = AGP_Timer(_ParentScreenplay.GetActorByTag(TimerTag));
	if (_timer == None)
	{
		if (_bDebug)
		{
			Log("Cond_WhenTimerEnds::ProcessParams() - could not get AGP_Timer with tag " $ string(TimerTag));
		}
		return false;
	}
	*/
	return true;
}

