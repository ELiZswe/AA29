// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_DisplayMissionFailure/Dir_DisplayMissionFailure.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UDir_DisplayMissionFailure::UDir_DisplayMissionFailure()
{
	_nNumParamsDefined = 7;
}

void UDir_DisplayMissionFailure::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_DisplayMissionFailure::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_DisplayMissionFailure::DirectionStart()");
	}
	if (_HumanController != nullptr)
	{
		_HumanController.DisplayMissionFailure(_sTexture, _szText, _szText2, _iUSize, _iVSize, _iRenderStyle, _nReplayScene);
	}
	if (((_ParentScreenplay.Level.Game.Stats != nullptr) && (_HumanController != nullptr)) && (_HumanController.PlayerStatsIndex >= 0))
	{
		_ParentScreenplay.Level.Game.Stats.PlayerStats[_HumanController.PlayerStatsIndex].StatEvent_TrainingMissionFailure();
	}
	if (_bDebug)
	{
		Log("Dir_DisplayMissionFailure::DirectionStart() FAILED");
	}
	*/
}

bool UDir_DisplayMissionFailure::ProcessParams()
{
	/*
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	_sTexture = GetParam(0);
	_szText = GetParam(1);
	_szText2 = GetParam(2);
	_iUSize = int(GetParam(3));
	_iVSize = int(GetParam(4));
	_iRenderStyle = int(GetParam(5));
	_nReplayScene = FString::FromInt(GetParam(6));
	*/
	return true;
}
