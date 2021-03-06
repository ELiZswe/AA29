// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_SetPlayerLocation/Dir_SetPlayerLocation.h"
#include "AA29/Object/Actor/AGP_Location/AGP_Location.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

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
	if (_Location != nullptr)
	{
		if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
		{
			_Location.Start(_HumanController.Pawn);
		}
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_SetPlayerLocation::DirectionStart() - _Location == nullptr");
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
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	_Location = Cast<AAGP_Location>(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_Location == nullptr)
	{
		Log("Dir_SetPlayerLocation::ProcessParams() - could not find AGP_Location with tag " + GetParam(0));
		return false;
	}
	*/
	return true;
}
