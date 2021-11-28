// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SceneRestart/Dir_SceneRestart.h"

UDir_SceneRestart::UDir_SceneRestart()
{
	bSupportsMP = true;
	_nNumParamsDefined = 1;

}

void UDir_SceneRestart::DirectionStart()
{
	/*
	if (_ParentScreenplay != None)
	{
		_ParentScreenplay.SceneRestart();
	}
	*/
}

bool UDir_SceneRestart::ProcessParams()
{
	return true;
}
