// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetNoCheats/Dir_SetNoCheats.h"

UDir_SetNoCheats::UDir_SetNoCheats()
{

}

void UDir_SetNoCheats::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_SetNoCheats::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetNoCheats::DirectionStart()");
	}
	if (_HumanController != None)
	{
		Log("Dir_SetNoCheats :: Killing Cheats!!!");
		_HumanController.KillCheats();
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_SetNoCheats::DirectionStart() - _Location == None");
		}
	}
	*/
}

void UDir_SetNoCheats::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetNoCheats::DirectionFinish()");
	}
	*/
}

bool UDir_SetNoCheats::ProcessParams()
{
	//_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	return true;
}

