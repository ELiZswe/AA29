// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenTimerEnds/Cond_WhenTimerEnds.h"
#include "AA29/Object/Actor/AGP_Timer/AGP_Timer.h"

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
		Log("Cond_WhenTimerEnds::ConditionStart(): " @ FString::FromInt(TimerTag));
	}
	_timer.SetTarget(this);
	*/
}

void UCond_WhenTimerEnds::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenTimerEnds::ConditionFinish(): " @ FString::FromInt(TimerTag));
	}
	_timer.SetTarget(nullptr);
	*/
}

bool UCond_WhenTimerEnds::ProcessParams()
{
	/*
	TimerTag = FString::FromInt(GetParam(0));
	_timer = AGP_Timer(_ParentScreenplay.GetActorByTag(TimerTag));
	if (_timer == nullptr)
	{
		if (_bDebug)
		{
			Log("Cond_WhenTimerEnds::ProcessParams() - could not get AGP_Timer with tag " + FString::FromInt(TimerTag));
		}
		return false;
	}
	*/
	return true;
}

