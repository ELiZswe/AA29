// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_SetMissionResultDisplay/Dir_SetMissionResultDisplay.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UDir_SetMissionResultDisplay::UDir_SetMissionResultDisplay()
{
	_nNumParamsDefined = 1;
}

void UDir_SetMissionResultDisplay::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_SetMissionResultDisplay::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetMissionResultDisplay::DirectionStart()");
	}
	if (_HumanController != nullptr)
	{
		if (AGP_HUD(_HumanController.myHUD) != nullptr)
		{
			if (AGP_HUD(_HumanController.myHUD).mrFrame != nullptr)
			{
				AGP_HUD(_HumanController.myHUD).mrFrame.SetMissionResultDisplay(_sMRD);
				return;
			}
		}
	}
	Log("Dir_SetMissionResultDisplay::DirectionStart() FAILED");
	*/
}

bool UDir_SetMissionResultDisplay::ProcessParams()
{
	/*
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_sMRD = GetParam(0);
	if (_sMRD == "")
	{
		Log("Dir_SetMissionResultDisplay::ProcessParams() - _sMRD is empty");
		return false;
	}
	*/
	return true;
}
