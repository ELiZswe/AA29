// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_PlayLSAnim/Dir_PlayLSAnim.h"

UDir_PlayLSAnim::UDir_PlayLSAnim()
{
	_bDebug = true;
	_nNumParamsDefined = 5;
}

void UDir_PlayLSAnim::Destroyed()
{
	Super::Destroyed();
	TargetActor = nullptr;
}

void UDir_PlayLSAnim::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_PlayLSAnim::DirectionStart()");
	}
	if (TargetActor != None)
	{
		if (LSVOlume == 0)
		{
			LSVOlume = 96;
		}
		if (LSRadius == 0)
		{
			LSRadius = 128;
		}
		if (LSPitch == 0)
		{
			LSPitch = 1;
		}
		if (_bDebug)
		{
			Log("Dir_PlayLSAnim::DirectionStart() - Sound values: " $ string(LSVOlume) $ " " $ string(LSRadius) $ " " $ string(LSPitch));
		}
		TargetActor.PlayLIPSincAnim(LSAnimation, LSVOlume, LSRadius, LSPitch);
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_PlayLSAnim::DirectionStart() - TargetActor is None");
		}
	}
	*/
}

void UDir_PlayLSAnim::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_PlayLSAnim::DirectionFinish()");
	}
*/
}

bool UDir_PlayLSAnim::ProcessParams()
{
	/*
	LSAnimation = string(GetParam(0));
	ActorTag = string(GetParam(1));
	LSVOlume = float(GetParam(2));
	LSRadius = float(GetParam(3));
	LSPitch = float(GetParam(4));
	TargetActor = _ParentScreenplay.GetActorByTag(ActorTag);
	if (TargetActor == None)
	{
		Log("Dir_PlayLSAnim::ProcessParams(): Error: Actor with tag not found: " @ string(ActorTag));
		return false;
	}
	*/
	return true;
}
