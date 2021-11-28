// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetPlayerInventory/Dir_SetPlayerInventory.h"

UDir_SetPlayerInventory::UDir_SetPlayerInventory()
{
	_nNumParamsDefined = 1;
}

void UDir_SetPlayerInventory::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
	//_InvMod = nullptr;
}

void UDir_SetPlayerInventory::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetInventory::DirectionStart()");
	}
	if (_InvMod != None)
	{
		if ((_HumanController != None) && (_HumanController.Pawn != None))
		{
			_InvMod.Run(_HumanController.Pawn);
		}
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_SetInventory::DirectionStart() - _InvMod == None");
		}
	}
	*/
}

void UDir_SetPlayerInventory::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetInventory::DirectionFinish()");
	}
	*/
}

bool UDir_SetPlayerInventory::ProcessParams()
{
	/*
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_InvMod = AGP_InventoryModifier(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_InvMod == None)
	{
		Log("Dir_SetPlayerInventory::ProcessParams() - could not find AGP_InventoryModifier with tag " $ GetParam(0));
		return false;
	}
	*/
	return true;
}
