// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenTargetManagerComplete/Cond_WhenTargetManagerComplete.h"

UCond_WhenTargetManagerComplete::UCond_WhenTargetManagerComplete()
{
	_nNumParamsDefined = 1;
}

void UCond_WhenTargetManagerComplete::Destroyed()
{
	Super::Destroyed();
	_TargetManager = nullptr;
}

void UCond_WhenTargetManagerComplete::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenTargetManagerComplete::ConditionStart()");
	}
	_TargetManager.SetTarget(Self);
	*/
}

void UCond_WhenTargetManagerComplete::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenTargetManagerComplete::ConditionFinish()");
	}
	_TargetManager.SetTarget(None);
	*/
}

bool UCond_WhenTargetManagerComplete::ProcessParams()
{
	/*
	_TargetManager = TargetManager(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_TargetManager == None)
	{
		if (_bDebug)
		{
			Log("Cond_WhenTargetManagerComplete::ProcessParams() - could not find TargetManager with tag " $ GetParam(0));
		}
		return false;
	}
	*/
	return true;
}
