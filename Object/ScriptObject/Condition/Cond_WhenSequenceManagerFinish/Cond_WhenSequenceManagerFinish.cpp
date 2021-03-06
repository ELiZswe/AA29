// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenSequenceManagerFinish/Cond_WhenSequenceManagerFinish.h"
#include "AA29/Object/Actor/Triggers/SequenceManager/SequenceManager.h"

UCond_WhenSequenceManagerFinish::UCond_WhenSequenceManagerFinish()
{
	_nNumParamsDefined = 1;
}

void UCond_WhenSequenceManagerFinish::Destroyed()
{
	Super::Destroyed();
	_SequenceManager = nullptr;
}

void UCond_WhenSequenceManagerFinish::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenSequenceManagerFinish::ConditionStart()");
	}
	_SequenceManager.SetFinishMonitor(this);
	*/
}

void UCond_WhenSequenceManagerFinish::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenSequenceManagerFinish::ConditionFinish()");
	}
	_SequenceManager.SetFinishMonitor(nullptr);
	*/
}

bool UCond_WhenSequenceManagerFinish::ProcessParams()
{
	/*
	_SequenceManager = SequenceManager(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_SequenceManager == nullptr)
	{
		if (_bDebug)
		{
			Log("Cond_WhenSequenceManagerFinish::ProcessParams() - could not find SequenceManager with tag " + GetParam(0));
		}
		return false;
	}
	*/
	return true;
}
