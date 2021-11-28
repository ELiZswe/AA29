// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SceneJumpRemembered/Dir_SceneJumpRemembered.h"

UDir_SceneJumpRemembered::UDir_SceneJumpRemembered()
{
	bSupportsMP = true;
	_nNumParamsDefined = 1;
}

void UDir_SceneJumpRemembered::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SceneJumpRemembered::DirectionStart()");
	}
	if (_ParentScreenplay != None)
	{
		_ParentScreenplay.SceneJump(_ParentScreenplay.GetRememberedScene(SceneIndex));
	}
	*/
}

bool UDir_SceneJumpRemembered::ProcessParams()
{
	//SceneIndex = int(GetParam(0));
	return true;
}
