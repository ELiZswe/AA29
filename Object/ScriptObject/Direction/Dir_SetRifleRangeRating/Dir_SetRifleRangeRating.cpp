// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_SetRifleRangeRating/Dir_SetRifleRangeRating.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Triggers/RandomDispatcher/TargetManager/TargetManager.h"

UDir_SetRifleRangeRating::UDir_SetRifleRangeRating()
{
	_nNumParamsDefined = 1;
}

void UDir_SetRifleRangeRating::Destroyed()
{
	Super::Destroyed();
	_TargetManager = nullptr;
	_HumanController = nullptr;
}

void UDir_SetRifleRangeRating::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetRifleRangeRating::DirectionStart()");
	}
	if (_HumanController == nullptr)
	{
		Log("ERROR: Dir_SetRifleRangeRating::DirectionStart() - _HumanController == nullptr");
		return;
	}
	if (_TargetManager == nullptr)
	{
		Log("ERROR: Dir_SetRifleRangeRating::DirectionStart() - _TargetManager == nullptr");
		return;
	}
	if (_ParentScreenplay == nullptr)
	{
		Log("ERROR: Dir_SetRifleRangeRating::DirectionStart() - _ParentScreenplay == nullptr");
		return;
	}
	_HumanController.iRifleRangeRating = _TargetManager._ScoreKeeper.TotalScore.nShot;
	if (_bDebug)
	{
		Log("Dir_SetRifleRangeRating::DirectionStart() FAILED");
	}
	*/
}

bool UDir_SetRifleRangeRating::ProcessParams()
{
	/*
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	_TargetManager = Cast<ATargetManager>(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	*/
	return true;
}
