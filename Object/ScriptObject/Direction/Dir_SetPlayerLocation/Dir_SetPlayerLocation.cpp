// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetPlayerLocation/Dir_SetPlayerLocation.h"

UDir_SetPlayerLocation::UDir_SetPlayerLocation()
{
	_nNumParamsDefined = 1;
}

void UDir_SetPlayerLocation::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
	_Location = nullptr;
}

void UDir_SetPlayerLocation::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetPlayerLocation::DirectionStart()");
	}
	if (_Location != None)
	{
		if ((_HumanController != None) && (_HumanController.Pawn != None))
		{
			_Location.Start(_HumanController.Pawn);
		}
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_SetPlayerLocation::DirectionStart() - _Location == None");
		}
	}
	*/
}

void UDir_SetPlayerLocation::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetPlayerLocation::DirectionFinish()");
	}
	*/
}

bool UDir_SetPlayerLocation::ProcessParams()
{
	/*
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_Location = AGP_Location(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_Location == None)
	{
		Log("Dir_SetPlayerLocation::ProcessParams() - could not find AGP_Location with tag " $ GetParam(0));
		return false;
	}
	*/
	return true;
}
