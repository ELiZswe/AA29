// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetTargetManagerScoreKeeper/Dir_SetTargetManagerScoreKeeper.h"

UDir_SetTargetManagerScoreKeeper::UDir_SetTargetManagerScoreKeeper()
{
	_nNumParamsDefined = 1;
}

void UDir_SetTargetManagerScoreKeeper::Destroyed()
{
	/*
	Super::Destroyed();
	_TargetManager = None;
	_HumanController = None;
	*/
}

void UDir_SetTargetManagerScoreKeeper::DirectionStart()
{
	/*
	if (_HumanController != None)
	{
		if (AGP_HUD(_HumanController.myHUD) != None)
		{
			if (AGP_HUD(_HumanController.myHUD).mrFrame != None)
			{
				AGP_HUD(_HumanController.myHUD).mrFrame.SetScoreKeeper(_TargetManager.getScoreKeeper());
			}
		}
	}
	*/
}

bool UDir_SetTargetManagerScoreKeeper::ProcessParams()
{
	/*
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_TargetManager = TargetManager(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_TargetManager == None)
	{
		Log("Dir_SetTargetManagerScoreKeeper::ProcessParams() - could not find TargetManager with tag " $ GetParam(0));
		return false;
	}
	*/
	return true;
}