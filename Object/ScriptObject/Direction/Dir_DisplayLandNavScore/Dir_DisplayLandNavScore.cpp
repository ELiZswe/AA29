// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_DisplayLandNavScore/Dir_DisplayLandNavScore.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/LandNavScoreManager/LandNavScoreManager.h"

UDir_DisplayLandNavScore::UDir_DisplayLandNavScore()
{
	bSupportsMP = true;
	_nNumParamsDefined = 1;
}

void UDir_DisplayLandNavScore::Destroyed()
{
	Super::Destroyed();
	Scm = nullptr;
}

void UDir_DisplayLandNavScore::DirectionStart()
{
	/*
	FString sFile = "";
	if (_bDebug)
	{
		Log("Dir_DisplayLandNavScore::DirectionStart()");
	}
	if (Scm != nullptr)
	{
		if (_HumanController != nullptr)
		{
			_HumanController.DisplayLandNavScore("Bag 1: " + Scm.FormatTime(Scm.GetObjectiveTime(0)), "Bag 2: " + Scm.FormatTime(Scm.GetObjectiveTime(1)), "Bag 3: " + Scm.FormatTime(Scm.GetObjectiveTime(2)), "Bag 4: " + Scm.FormatTime(Scm.GetObjectiveTime(3)), "Bag 5: " + Scm.FormatTime(Scm.GetObjectiveTime(4)), "Bag 6: " + Scm.FormatTime(Scm.GetObjectiveTime(5)), "Start: " + Scm.FormatTime(Scm.GetObjectiveTime(6)), "TOTAL TIME: " + Scm.FormatTime(Scm.GetObjectiveTime(6)));
			sFile = "save\\" + "WP_LandNavScore.txt";
			if (!FOpenWrite(sFile))
			{
				Log("Dir_DisplayLandNavScore: ERROR: Failed opening for write " + sFile);
			}
			else
			{
				FWriteLine(Scm.FormatTime(Scm.GetObjectiveTime(0)));
				FWriteLine(Scm.FormatTime(Scm.GetObjectiveTime(1)));
				FWriteLine(Scm.FormatTime(Scm.GetObjectiveTime(2)));
				FWriteLine(Scm.FormatTime(Scm.GetObjectiveTime(3)));
				FWriteLine(Scm.FormatTime(Scm.GetObjectiveTime(4)));
				FWriteLine(Scm.FormatTime(Scm.GetObjectiveTime(5)));
				FWriteLine(Scm.FormatTime(Scm.GetObjectiveTime(6)));
				FClose();
			}
		}
	}
	*/
}

void UDir_DisplayLandNavScore::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_DisplayLandNavScore::DirectionFinish()");
	}
	*/
}

bool UDir_DisplayLandNavScore::ProcessParams()
{
	/*
	FName ScmTag = "";
	if (_bDebug)
	{
		Log("Dir_DisplayLandNavScore::ProcessParams()");
	}
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	ScmTag = FString::FromInt(GetParam(0));
	Scm = LandNavScoreManager(_ParentScreenplay.GetActorByTag(ScmTag));
	if (Scm == nullptr)
	{
		Log("Dir_DisplayLandNavScore::ProcessParams() - could not get LandNavScoreManager with tag " + GetParam(0));
		return false;
	}
	*/
	return true;
}
