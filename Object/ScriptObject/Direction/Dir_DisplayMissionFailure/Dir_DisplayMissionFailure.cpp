// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_DisplayMissionFailure/Dir_DisplayMissionFailure.h"

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
	if (_HumanController != None)
	{
		_HumanController.DisplayMissionFailure(_sTexture, _szText, _szText2, _iUSize, _iVSize, _iRenderStyle, _nReplayScene);
	}
	if (((_ParentScreenplay.Level.Game.Stats != None) && (_HumanController != None)) && (_HumanController.PlayerStatsIndex >= 0))
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
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_sTexture = GetParam(0);
	_szText = GetParam(1);
	_szText2 = GetParam(2);
	_iUSize = int(GetParam(3));
	_iVSize = int(GetParam(4));
	_iRenderStyle = int(GetParam(5));
	_nReplayScene = string(GetParam(6));
	*/
	return true;
}
