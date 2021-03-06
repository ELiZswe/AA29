// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenSequenceManagerInOrder/Cond_WhenSequenceManagerInOrder.h"
#include "AA29/Object/Actor/Triggers/SequenceManager/SequenceManager.h"

UCond_WhenSequenceManagerInOrder::UCond_WhenSequenceManagerInOrder()
{
	_nNumParamsDefined = 1;
}

void UCond_WhenSequenceManagerInOrder::Destroyed()
{
	Super::Destroyed();
	_SequenceManager = nullptr;
}

void UCond_WhenSequenceManagerInOrder::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenSequenceManagerInOrder::ConditionStart()");
	}
	_SequenceManager.SetInOrderMonitor(this);
	*/
}

void UCond_WhenSequenceManagerInOrder::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenSequenceManagerInOrder::ConditionFinish()");
	}
	_SequenceManager.SetInOrderMonitor(nullptr);
	*/
}

bool UCond_WhenSequenceManagerInOrder::ProcessParams()
{
	/*
	_SequenceManager = SequenceManager(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_SequenceManager == nullptr)
	{
		if (_bDebug)
		{
			Log("Cond_WhenSequenceManagerInOrder::ProcessParams() - could not find SequenceManager with tag " + GetParam(0));
		}
		return false;
	}
	*/
	return true;
}

