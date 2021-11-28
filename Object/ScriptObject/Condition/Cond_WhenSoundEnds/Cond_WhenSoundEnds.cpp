// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenSoundEnds/Cond_WhenSoundEnds.h"

UCond_WhenSoundEnds::UCond_WhenSoundEnds()
{
	bSupportsMP = true;
	_nNumParamsDefined = 1;
}

void UCond_WhenSoundEnds::Destroyed()
{
	Super::Destroyed();
	_Sound = nullptr;
}

void UCond_WhenSoundEnds::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenSoundEnds::ConditionStart()");
	}
	_Sound.SetTarget(Self);
	*/
}

void UCond_WhenSoundEnds::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenSoundEnds::ConditionFinish()");
	}
	_Sound.SetTarget(None);
	*/
}

bool UCond_WhenSoundEnds::ProcessParams()
{
	/*
	_Sound = AGP_Sound(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_Sound == None)
	{
		if (_bDebug)
		{
			Log("Cond_WhenSoundEnds::ProcessParams() - could not find AGP_Sound with tag " $ GetParam(0));
		}
		return false;
	}
	*/
	return true;
}

