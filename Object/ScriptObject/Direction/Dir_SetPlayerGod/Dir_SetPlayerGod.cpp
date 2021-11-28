// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetPlayerGod/Dir_SetPlayerGod.h"

UDir_SetPlayerGod::UDir_SetPlayerGod()
{
	_nNumParamsDefined = 1;
}

void UDir_SetPlayerGod::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_SetPlayerGod::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetPlayerGod::DirectionStart()");
	}
	if (_HumanController != None)
	{
		_HumanController.bGodMode = _bGod;
	}
	*/
}

void UDir_SetPlayerGod::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetPlayerGod::DirectionFinish()");
	}
	*/
}

bool UDir_SetPlayerGod::ProcessParams()
{
	/*
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_bGod = bool(GetParam(0));
	*/
	return true;
}