// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_SetTargetManagerPracticeMode/Dir_SetTargetManagerPracticeMode.h"
#include "AA29/Object/Actor/Triggers/RandomDispatcher/TargetManager/TargetManager.h"

UDir_SetTargetManagerPracticeMode::UDir_SetTargetManagerPracticeMode()
{
	_nNumParamsDefined = 2;
}

void UDir_SetTargetManagerPracticeMode::Destroyed()
{
	/*
	Super::Destroyed();
	_TargetManager = nullptr;
	*/
}

void UDir_SetTargetManagerPracticeMode::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetTargetManagerPracticeMode::DirectionStart() " + FString::FromInt(_bPractice));
	}
	if (_TargetManager != nullptr)
	{
		_TargetManager.SetTargetPractice(_bPractice);
	}
	*/
}

bool UDir_SetTargetManagerPracticeMode::ProcessParams()
{
	/*
	_TargetManager = Cast<ATargetManager>(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	_bPractice = bool(GetParam(1));
	if (_TargetManager == nullptr)
	{
		Log("Dir_SetTargetManagerPracticeMode::ProcessParams() - could not find TargetManager with tag " + GetParam(0));
		return false;
	}
	*/
	return true;
}
