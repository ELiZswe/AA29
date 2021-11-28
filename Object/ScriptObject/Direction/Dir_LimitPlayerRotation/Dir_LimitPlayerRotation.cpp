// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_LimitPlayerRotation/Dir_LimitPlayerRotation.h"

UDir_LimitPlayerRotation::UDir_LimitPlayerRotation()
{
	_nNumParamsDefined = 4;
}

void UDir_LimitPlayerRotation::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_LimitPlayerRotation::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_LimitPlayerRotation::DirectionStart()");
	}
	if (_HumanController != None)
	{
		Log("Dir_LimitPlayerRotation::_bLimit" @ string(_bLimit));
		_HumanController.LimitPawnRotation(_bLimit, _rRotator);
	}
	*/
}

bool UDir_LimitPlayerRotation::ProcessParams()
{
	/*
	_bLimit = bool(GetParam(0));
	_rRotator.Pitch = int(GetParam(1));
	_rRotator.Yaw = int(GetParam(2));
	_rRotator.Roll = int(GetParam(3));
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	*/
	return true;
}
