// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_SetPlayerNoRoll/Dir_SetPlayerNoRoll.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UDir_SetPlayerNoRoll::UDir_SetPlayerNoRoll()
{
	_nNumParamsDefined = 1;
}

void UDir_SetPlayerNoRoll::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_SetPlayerNoRoll::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetPlayerNoRoll::DirectionStart()");
	}
	if (_HumanController != nullptr)
	{
		_HumanController.bNoRoll = _bNoRoll;
	}
	*/
}

void UDir_SetPlayerNoRoll::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetPlayerNoRoll::DirectionFinish()");
	}
	*/
}

bool UDir_SetPlayerNoRoll::ProcessParams()
{
	/*
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	_bNoRoll = bool(GetParam(0));
	*/
	return true;
}
