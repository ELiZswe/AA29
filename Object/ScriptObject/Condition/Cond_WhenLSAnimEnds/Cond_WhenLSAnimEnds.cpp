// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenLSAnimEnds/Cond_WhenLSAnimEnds.h"

UCond_WhenLSAnimEnds::UCond_WhenLSAnimEnds()
{
	_bDebug = true;
	bSupportsMP = true;
	_nNumParamsDefined = 1;
}

void UCond_WhenLSAnimEnds::Destroyed()
{
	Super::Destroyed();
}

void UCond_WhenLSAnimEnds::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenLSAnimEnds::ConditionStart()");
	}
	TargetActor.SetTarget(this);
	*/
}

void UCond_WhenLSAnimEnds::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenLSAnimEnds::ConditionFinish()");
	}
	TargetActor.SetTarget(nullptr);
	*/
}

bool UCond_WhenLSAnimEnds::ProcessParams()
{
	/*
	ActorTag = FString::FromInt(GetParam(0));
	TargetActor = _ParentScreenplay.GetActorByTag(ActorTag);
	if (TargetActor == nullptr)
	{
		if (_bDebug)
		{
			Log("Cond_WhenLSAnimEnds::ProcessParams() - could not get Actor with tag " + FString::FromInt(ActorTag));
		}
		return false;
	}
	*/
	return true;
}

