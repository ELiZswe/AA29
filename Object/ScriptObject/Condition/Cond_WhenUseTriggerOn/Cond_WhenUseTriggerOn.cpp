// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenUseTriggerOn/Cond_WhenUseTriggerOn.h"

UCond_WhenUseTriggerOn::UCond_WhenUseTriggerOn()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}

void UCond_WhenUseTriggerOn::Destroyed()
{
	Super::Destroyed();
	UseTrigger = nullptr;
}

void UCond_WhenUseTriggerOn::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenUseTriggerOn::ConditionStart()");
	}
	if (UseTrigger.IsSwitched() == bSwitched)
	{
		Notify();
	}
	*/
}

void UCond_WhenUseTriggerOn::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenUseTriggerOn::ConditionFinish()");
	}
	*/
}

bool UCond_WhenUseTriggerOn::ProcessParams()
{
	/*
	UseTrigger = AGP_UseTrigger(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	bSwitched = bool(GetParam(1));
	if (UseTrigger == None)
	{
		if (_bDebug)
		{
			Log("Cond_WhenUseTriggerOn::ProcessParams() - could not find AGP_UseTrigger with tag " $ GetParam(0));
		}
		return false;
	}
	*/
	return true;
}
