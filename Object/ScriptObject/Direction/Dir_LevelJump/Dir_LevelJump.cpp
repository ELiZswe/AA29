// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_LevelJump/Dir_LevelJump.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UDir_LevelJump::UDir_LevelJump()
{
	_nNumParamsDefined = 1;
}

void UDir_LevelJump::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_LevelJump::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_LevelJump::DirectionStart()");
	}
	if (_HumanController != nullptr)
	{
		AGP_HUD(_HumanController.myHUD).OpenMap(_sLevel);
	}
	*/
}

bool UDir_LevelJump::ProcessParams()
{
	/*
	_sLevel = GetParam(0);
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	*/
	return true;
}
