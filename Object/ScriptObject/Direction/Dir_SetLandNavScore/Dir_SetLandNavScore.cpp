// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetLandNavScore/Dir_SetLandNavScore.h"

UDir_SetLandNavScore::UDir_SetLandNavScore()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}

void UDir_SetLandNavScore::Destroyed()
{
	Super::Destroyed();
	Scm = nullptr;
}

void UDir_SetLandNavScore::DirectionStart()
{
	/*
	int32 Time = 0;
	if (_bDebug)
	{
		Log("Dir_SetLandNavScore::DirectionStart()");
	}
	if (Scm != None)
	{
		Time = _ParentScreenplay.Level.Game.GameReplicationInfo.RemainingTime;
		Scm.SetObjectiveTime((Index - 1), Time);
	}
	*/
}

void UDir_SetLandNavScore::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetLandNavScore::DirectionFinish()");
	}
	*/
}

bool UDir_SetLandNavScore::ProcessParams()
{
	/*
	FName ScmTag = "";
	if (_bDebug)
	{
		Log("Dir_SetLandNavScore::ProcessParams()");
	}
	ScmTag = string(GetParam(0));
	Index = int(GetParam(1));
	Scm = LandNavScoreManager(_ParentScreenplay.GetActorByTag(ScmTag));
	if (Scm == None)
	{
		Log("Dir_SetLandNavScore::ProcessParams() - could not get LandNavScoreManager with tag " $ GetParam(0));
		return false;
	}
	*/
	return true;
}