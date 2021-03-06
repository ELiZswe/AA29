// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_SetRandomLocation/Dir_SetRandomLocation.h"
#include "AA29/Object/Actor/AGP_LocationList/AGP_LocationList.h"
#include "AA29/Object/Actor/AGP_Location/AGP_Location.h"

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
	AAGP_Location* loc = nullptr;
	/*
	if (_bDebug)
	{
		Log("Dir_SetRandomLocation::DirectionStart()");
	}
	if (_LocationList != nullptr)
	{
		loc = _LocationList.GetRandomLocation();
		if (loc != nullptr)
		{
			loc.Start(_Actor);
		}
		else
		{
			if (_bDebug)
			{
				Log("Dir_SetRandomLocation::DirectionStart() - _LocationList.GetRandomLocation() == nullptr");
			}
		}
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_SetRandomLocation::DirectionStart() - _LocationList == nullptr");
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
