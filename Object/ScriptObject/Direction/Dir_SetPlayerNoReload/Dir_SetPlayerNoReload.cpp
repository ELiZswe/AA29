// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetPlayerNoReload/Dir_SetPlayerNoReload.h"

UDir_SetPlayerNoReload::UDir_SetPlayerNoReload()
{
	_nNumParamsDefined = 1;
}

void UDir_SetPlayerNoReload::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_SetPlayerNoReload::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetPlayerNoReload::DirectionStart()");
	}
	if (_HumanController != None)
	{
		_HumanController.bNoReload = _bNoReload;
	}
	*/
}

void UDir_SetPlayerNoReload::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetPlayerNoReload::DirectionFinish()");
	}
	*/
}

bool UDir_SetPlayerNoReload::ProcessParams()
{
	/*
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_bNoReload = bool(GetParam(0));
	*/
	return true;
}
