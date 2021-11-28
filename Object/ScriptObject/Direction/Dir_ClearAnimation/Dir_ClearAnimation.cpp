// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_ClearAnimation/Dir_ClearAnimation.h"

UDir_ClearAnimation::UDir_ClearAnimation()
{
	_nNumParamsDefined = 1;
}

void UDir_ClearAnimation::Destroyed()
{
	Super::Destroyed();
	_Controller = nullptr;
}

void UDir_ClearAnimation::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_ClearAnimation::DirectionStart()");
	}
	if (_Controller != None)
	{
		_Controller.FlushInstructions();
	}
	*/
}

bool UDir_ClearAnimation::ProcessParams()
{
	/*
	_Controller = AnimationController(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_Controller == None)
	{
		if (_bDebug)
		{
			Log("Dir_ClearAnimation::ProcessParams() - could not find actor with tag " $ GetParam(0));
		}
		return false;
	}
	*/
	return true;
}
