// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenSequenceManagerStart/Cond_WhenSequenceManagerStart.h"
#include "AA29/Object/Actor/Triggers/SequenceManager/SequenceManager.h"

UCond_WhenSequenceManagerStart::UCond_WhenSequenceManagerStart()
{
	_nNumParamsDefined = 1;
}

void UCond_WhenSequenceManagerStart::Destroyed()
{
	Super::Destroyed();
	_SequenceManager = nullptr;
}

void UCond_WhenSequenceManagerStart::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenSequenceManagerStart::ConditionStart()");
	}
	_SequenceManager.SetStartMonitor(this);
	*/
}

void UCond_WhenSequenceManagerStart::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenSequenceManagerStart::ConditionFinish()");
	}
	_SequenceManager.SetStartMonitor(nullptr);
	*/
}

bool UCond_WhenSequenceManagerStart::ProcessParams()
{
	/*
	_SequenceManager = SequenceManager(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_SequenceManager == nullptr)
	{
		if (_bDebug)
		{
			Log("Cond_WhenSequenceManagerStart::ProcessParams() - could not find SequenceManager with tag " + GetParam(0));
		}
		return false;
	}
	*/
	return true;
}

