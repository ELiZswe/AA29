// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetLocation/Dir_SetLocation.h"

UDir_SetLocation::UDir_SetLocation()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}

void UDir_SetLocation::Destroyed()
{
	Super::Destroyed();
	_Location = nullptr;
	_Actor = nullptr;
}

void UDir_SetLocation::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetLocation::DirectionStart()");
	}
	if (_Location != None)
	{
		_Location.Start(_Actor);
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_SetLocation::DirectionStart() - _Location == None");
		}
	}
	*/
}

void UDir_SetLocation::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetLocation::DirectionFinish()");
	}
	*/
}

bool UDir_SetLocation::ProcessParams()
{
	/*
	_Location = AGP_Location(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	_Actor = _ParentScreenplay.GetActorByTag(string(GetParam(1)));
	*/
	return true;
}

void UDir_SetLocation::SetLocation(AAGP_Location* Location)
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetLocation::SetLocation()");
	}
	_Location = Location;
	*/
}

void UDir_SetLocation::SetActor(AActor* Actor)
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetLocation::SetActor()");
	}
	_Actor = Actor;
	*/
}