// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_TargetManagerPause/Dir_TargetManagerPause.h"

UDir_TargetManagerPause::UDir_TargetManagerPause()
{
	_nNumParamsDefined = 2;
}

void UDir_TargetManagerPause::Destroyed()
{
	/*
	Super::Destroyed();
	_TargetManager = None;
	*/
}

void UDir_TargetManagerPause::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_TargetManagerPause::DirectionStart() " $ string(_bPause));
	}
	if (_TargetManager != None)
	{
		_TargetManager.bPaused = _bPause;
	}
	*/
}

bool UDir_TargetManagerPause::ProcessParams()
{
	/*
	_TargetManager = TargetManager(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	_bPause = bool(GetParam(1));
	*/
	return true;
}