// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_SetTargetManagerScoreKeeper/Dir_SetTargetManagerScoreKeeper.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Triggers/RandomDispatcher/TargetManager/TargetManager.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"

UDir_SetTargetManagerScoreKeeper::UDir_SetTargetManagerScoreKeeper()
{
	_nNumParamsDefined = 1;
}

void UDir_SetTargetManagerScoreKeeper::Destroyed()
{
	/*
	Super::Destroyed();
	_TargetManager = nullptr;
	_HumanController = nullptr;
	*/
}

void UDir_SetTargetManagerScoreKeeper::DirectionStart()
{
	/*
	if (_HumanController != nullptr)
	{
		if (Cast<AAGP_HUD>(_HumanController.myHUD) != nullptr)
		{
			if (Cast<AAGP_HUD>(_HumanController.myHUD).mrFrame != nullptr)
			{
				Cast<AAGP_HUD>(_HumanController.myHUD).mrFrame.SetScoreKeeper(_TargetManager.getScoreKeeper());
			}
		}
	}
	*/
}

bool UDir_SetTargetManagerScoreKeeper::ProcessParams()
{
	/*
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	_TargetManager = Cast<ATargetManager>(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_TargetManager == nullptr)
	{
		Log("Dir_SetTargetManagerScoreKeeper::ProcessParams() - could not find TargetManager with tag " + GetParam(0));
		return false;
	}
	*/
	return true;
}
