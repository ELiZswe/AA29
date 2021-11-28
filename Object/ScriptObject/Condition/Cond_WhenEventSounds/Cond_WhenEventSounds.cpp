// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenEventSounds/Cond_WhenEventSounds.h"

UCond_WhenEventSounds::UCond_WhenEventSounds()
{
	bSupportsMP = true;
	_nNumParamsDefined = 1;
}

void UCond_WhenEventSounds::Destroyed()
{
	Super::Destroyed();
	_EventSound = nullptr;
}

void UCond_WhenEventSounds::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenEventSounds::ConditionStart()");
	}
	_EventSound.SetTarget(Self);
	*/
}

void UCond_WhenEventSounds::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenEventSounds::ConditionFinish()");
	}
	_EventSound.SetTarget(None);
	*/
}

bool UCond_WhenEventSounds::ProcessParams()
{
	/*
	_EventSound = EventSound(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_EventSound == None)
	{
		if (_bDebug)
		{
			Log("Cond_WhenEventSounds::ProcessParams() - could not find EventSound with tag " $ GetParam(0));
		}
		return false;
	}
	*/
	return true;
}

