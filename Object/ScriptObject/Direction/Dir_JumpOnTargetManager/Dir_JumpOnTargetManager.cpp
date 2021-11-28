// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_JumpOnTargetManager/Dir_JumpOnTargetManager.h"

UDir_JumpOnTargetManager::UDir_JumpOnTargetManager()
{
	bSupportsMP = true;
	_nNumParamsDefined = 4;
}

void UDir_JumpOnTargetManager::Destroyed()
{
	Super::Destroyed();
	_TargetManager = nullptr;
}

void UDir_JumpOnTargetManager::DirectionStart()
{
	/*
	int32 Value = 0;
	if (_bDebug)
	{
		Log("Dir_JumpOnTargetManager::DirectionStart()");
	}
	if (_TargetManager == None)
	{
		Log("ERROR: Dir_JumpOnTargetManager::DirectionStart() - _TargetManager == None");
		return;
	}
	if (_ParentScreenplay == None)
	{
		Log("ERROR: Dir_JumpOnTargetManager::DirectionStart() - _ParentScreenplay == None");
		return;
	}
	Value = _TargetManager._ScoreKeeper.TotalScore.nShot;
	if ((Value >= _Min) && (Value <= _Max))
	{
		if (_bDebug)
		{
			Log("Dir_JumpOnTargetManager::DirectionStart() in range, jumping.");
		}
		_ParentScreenplay.SceneJump(_JumpScene);
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_JumpOnTargetManager::DirectionStart() not in range.");
		}
	}
	*/
}

void UDir_JumpOnTargetManager::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_JumpOnTargetManager::DirectionFinish()");
	}
	*/
}

bool UDir_JumpOnTargetManager::ProcessParams()
{
	/*
	if (_bDebug)
	{
		Log("Dir_JumpOnTargetManager::ProcessParams()");
	}
	_TargetManager = TargetManager(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	_Min = int(GetParam(1));
	_Max = int(GetParam(2));
	_JumpScene = string(GetParam(3));
	*/
	return true;
}
