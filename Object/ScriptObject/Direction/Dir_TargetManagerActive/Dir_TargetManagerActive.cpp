// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_TargetManagerActive/Dir_TargetManagerActive.h"
#include "AA29/Object/Actor/Triggers/RandomDispatcher/TargetManager/TargetManager.h"

UDir_TargetManagerActive::UDir_TargetManagerActive()
{
	_nNumParamsDefined = 2;
}

void UDir_TargetManagerActive::Destroyed()
{
	/*
	Super::Destroyed();
	_TargetManager = nullptr;
	*/
}

void UDir_TargetManagerActive::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_TargetManagerActive::DirectionStart() " + FString::FromInt(_bActive));
	}
	if (_TargetManager != nullptr)
	{
		if (_bActive)
		{
			_TargetManager.Trigger(_ParentScreenplay, None);
		}
		else
		{
			_TargetManager.UnTrigger(_ParentScreenplay, None);
		}
	}
	*/
}

bool UDir_TargetManagerActive::ProcessParams()
{
	/*
	_TargetManager = Cast<ATargetManager>(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	_bActive = bool(GetParam(1));
	*/
	return true;
}
