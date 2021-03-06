// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_HidePlayerCompassObj/Dir_HidePlayerCompassObj.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UDir_HidePlayerCompassObj::UDir_HidePlayerCompassObj()
{
	_nNumParamsDefined = 1;
}

void UDir_HidePlayerCompassObj::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_HidePlayerCompassObj::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_HidePlayerCompassObj::DirectionStart()");
	}
	if (_HumanController != nullptr)
	{
		_HumanController.HideCompassObjPoints(_bHide);
	}
	*/
}

void UDir_HidePlayerCompassObj::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_HidePlayerCompassObj::DirectionFinish()");
	}
	*/
}

bool UDir_HidePlayerCompassObj::ProcessParams()
{
	/*
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	_bHide = bool(GetParam(0));
	*/
	return true;
}
