// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_SetPlayerInventory/Dir_SetPlayerInventory.h"
#include "AA29/Object/Actor/Triggers/Trigger/AGP_InventoryModifier/AGP_InventoryModifier.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

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
	if (_InvMod != nullptr)
	{
		if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
		{
			_InvMod.Run(_HumanController.Pawn);
		}
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_SetInventory::DirectionStart() - _InvMod == nullptr");
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
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	_InvMod = Cast<AAGP_InventoryModifier>(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_InvMod == nullptr)
	{
		Log("Dir_SetPlayerInventory::ProcessParams() - could not find AGP_InventoryModifier with tag " + GetParam(0));
		return false;
	}
	*/
	return true;
}
