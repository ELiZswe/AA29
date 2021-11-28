// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SceneEnd/Dir_SceneEnd.h"

UDir_SceneEnd::UDir_SceneEnd()
{
	bSupportsMP = true;
}

void UDir_SceneEnd::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SceneEnd::DirectionStart()");
	}
	if (_ParentScreenplay != None)
	{
		_ParentScreenplay.SceneEnd();
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_SceneEnd::DirectionStart() - _ParentScreenplay == None");
		}
	}
	*/
}

bool UDir_SceneEnd::ProcessParams()
{
	return true;
}