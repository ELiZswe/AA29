// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SceneJump/Dir_SceneJump.h"

UDir_SceneJump::UDir_SceneJump()
{
	bSupportsMP = true;
	_nNumParamsDefined = 1;
}

void UDir_SceneJump::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SceneJump::DirectionStart()");
	}
	if (_ParentScreenplay != None)
	{
		_ParentScreenplay.SceneJump(_SceneTag);
	}
	*/
}

bool UDir_SceneJump::ProcessParams()
{
	//_SceneTag = string(GetParam(0));
	return true;
}
