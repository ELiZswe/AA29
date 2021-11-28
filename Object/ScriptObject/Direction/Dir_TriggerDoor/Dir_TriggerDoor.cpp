// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_TriggerDoor/Dir_TriggerDoor.h"

UDir_TriggerDoor::UDir_TriggerDoor()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}

void UDir_TriggerDoor::Destroyed()
{
	/*
	Super::Destroyed();
	Door = None;
	*/
}

void UDir_TriggerDoor::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_TriggerDoor::DirectionStart()");
	}
	if (Door != None)
	{
		if (Door.IsOpen() != bOpen)
		{
			Door.ToggleOpen();
		}
	}
	else
	{
		Log("Dir_TriggerDoor::DirectionStart(): Error: Door is None");
	}
	*/
}

void UDir_TriggerDoor::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_TriggerDoor::DirectionStart()");
	}
	*/
}

bool UDir_TriggerDoor::ProcessParams()
{
	/*
	if (_bDebug)
	{
		Log("Dir_TriggerDoor::ProcessParams()");
	}
	DoorTag = string(GetParam(0));
	Door = DoorTrigger(_ParentScreenplay.GetActorByTag(DoorTag));
	bOpen = bool(GetParam(1));
	if (Door == None)
	{
		Log("Dir_TriggerDoor::DirectionStart(): Error: Could not get DoorTrigger with tag" @ string(DoorTag));
		return false;
	}
	*/
	return true;
}