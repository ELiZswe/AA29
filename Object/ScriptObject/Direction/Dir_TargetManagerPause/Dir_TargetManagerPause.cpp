// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_TargetManagerPause/Dir_TargetManagerPause.h"
#include "AA29/Object/Actor/Triggers/RandomDispatcher/TargetManager/TargetManager.h"

UDir_TargetManagerPause::UDir_TargetManagerPause()
{
	_nNumParamsDefined = 2;
}

void UDir_TargetManagerPause::Destroyed()
{
	/*
	Super::Destroyed();
	_TargetManager = nullptr;
	*/
}

void UDir_TargetManagerPause::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_TargetManagerPause::DirectionStart() " + FString::FromInt(_bPause));
	}
	if (_TargetManager != nullptr)
	{
		_TargetManager.bPaused = _bPause;
	}
	*/
}

bool UDir_TargetManagerPause::ProcessParams()
{
	/*
	_TargetManager = Cast<ATargetManager>(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	_bPause = bool(GetParam(1));
	*/
	return true;
}
