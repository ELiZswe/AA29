// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetRifleRangeRating/Dir_SetRifleRangeRating.h"

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
	if (_HumanController == None)
	{
		Log("ERROR: Dir_SetRifleRangeRating::DirectionStart() - _HumanController == None");
		return;
	}
	if (_TargetManager == None)
	{
		Log("ERROR: Dir_SetRifleRangeRating::DirectionStart() - _TargetManager == None");
		return;
	}
	if (_ParentScreenplay == None)
	{
		Log("ERROR: Dir_SetRifleRangeRating::DirectionStart() - _ParentScreenplay == None");
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
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_TargetManager = TargetManager(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	*/
	return true;
}