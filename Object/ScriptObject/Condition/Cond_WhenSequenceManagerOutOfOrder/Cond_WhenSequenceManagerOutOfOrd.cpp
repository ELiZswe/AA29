// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenSequenceManagerOutOfOrder/Cond_WhenSequenceManagerOutOfOrd.h"

UCond_WhenSequenceManagerOutOfOrd::UCond_WhenSequenceManagerOutOfOrd()
{
	_nNumParamsDefined = 1;
}

void UCond_WhenSequenceManagerOutOfOrd::Destroyed()
{
	Super::Destroyed();
	_SequenceManager = nullptr;
}

void UCond_WhenSequenceManagerOutOfOrd::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenSequenceManagerOutOfOrder::ConditionStart()");
	}
	_SequenceManager.SetOutOfOrderMonitor(Self);
	*/
}

void UCond_WhenSequenceManagerOutOfOrd::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenSequenceManagerOutOfOrder::ConditionFinish()");
	}
	_SequenceManager.SetOutOfOrderMonitor(None);
	*/
}

bool UCond_WhenSequenceManagerOutOfOrd::ProcessParams()
{
	/*
	_SequenceManager = SequenceManager(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_SequenceManager == None)
	{
		if (_bDebug)
		{
			Log("Cond_WhenSequenceManagerOutOfOrder::ProcessParams() - could not find SequenceManager with tag " $ GetParam(0));
		}
		return false;
	}
	*/
	return true;
}

