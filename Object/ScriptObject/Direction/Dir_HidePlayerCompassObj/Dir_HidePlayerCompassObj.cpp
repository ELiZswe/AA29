// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_HidePlayerCompassObj/Dir_HidePlayerCompassObj.h"

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
	if (_HumanController != None)
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
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_bHide = bool(GetParam(0));
	*/
	return true;
}
