// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_RememberScene/Dir_RememberScene.h"

UDir_RememberScene::UDir_RememberScene()
{
	_bDebug = true;
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}

void UDir_RememberScene::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_RememberScene::DirectionStart()");
	}
	if (_ParentScreenplay != nullptr)
	{
		_ParentScreenplay.SetRememberedScene(SceneName, SceneIndex);
		if (_bDebug)
		{
			Log("Dir_RememberScene::DirectionStart(): " + FString::FromInt(SceneName) + " set to index " + FString::FromInt(SceneIndex));
		}
	}
	else
	{
		Log("Dir_RememberScene::DirectionStart(): Error: No Parent Screenplay");
	}
	*/
}

bool UDir_RememberScene::ProcessParams()
{
	/*
	SceneName = FString::FromInt(GetParam(0));
	SceneIndex = int(GetParam(1));
	*/
	return true;
}
