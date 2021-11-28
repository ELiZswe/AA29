// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetRandomLocation/Dir_SetRandomLocation.h"

UDir_SetRandomLocation::UDir_SetRandomLocation()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}

void UDir_SetRandomLocation::Destroyed()
{
	Super::Destroyed();
	_LocationList = nullptr;
	_Actor = nullptr;
}

void UDir_SetRandomLocation::DirectionStart()
{
	/*
	local AGP_Gameplay.AGP_Location loc;
	if (_bDebug)
	{
		Log("Dir_SetRandomLocation::DirectionStart()");
	}
	if (_LocationList != None)
	{
		loc = _LocationList.GetRandomLocation();
		if (loc != None)
		{
			loc.Start(_Actor);
		}
		else
		{
			if (_bDebug)
			{
				Log("Dir_SetRandomLocation::DirectionStart() - _LocationList.GetRandomLocation() == None");
			}
		}
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_SetRandomLocation::DirectionStart() - _LocationList == None");
		}
	}
	*/
}

void UDir_SetRandomLocation::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetRandomLocation::DirectionFinish()");
	}
	*/
}

bool UDir_SetRandomLocation::ProcessParams()
{
	/*
	_LocationList = AGP_LocationList(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	_Actor = _ParentScreenplay.GetActorByTag(string(GetParam(1)));
	*/
	return true;
}

void UDir_SetRandomLocation::SetLocationList(AAGP_LocationList* LocationList)
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetRandomLocation::SetLocationList()");
	}
	_LocationList = LocationList;
	*/
}

void UDir_SetRandomLocation::SetActor(AActor* Actor)
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetRandomLocation::SetActor()");
	}
	_Actor = Actor;
	*/
}