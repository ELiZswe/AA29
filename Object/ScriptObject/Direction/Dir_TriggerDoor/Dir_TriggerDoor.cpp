// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_TriggerDoor/Dir_TriggerDoor.h"
#include "AA29/Object/Actor/AGP_UseTrigger/DoorTrigger/DoorTrigger.h"

UDir_TriggerDoor::UDir_TriggerDoor()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}

void UDir_TriggerDoor::Destroyed()
{
	/*
	Super::Destroyed();
	Door = nullptr;
	*/
}

void UDir_TriggerDoor::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_TriggerDoor::DirectionStart()");
	}
	if (Door != nullptr)
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
	DoorTag = FString::FromInt(GetParam(0));
	Door = Cast<ADoorTrigger>(_ParentScreenplay.GetActorByTag(DoorTag));
	bOpen = bool(GetParam(1));
	if (Door == nullptr)
	{
		Log("Dir_TriggerDoor::DirectionStart(): Error: Could not get DoorTrigger with tag" @ FString::FromInt(DoorTag));
		return false;
	}
	*/
	return true;
}
