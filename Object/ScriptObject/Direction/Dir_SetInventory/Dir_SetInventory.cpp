// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetInventory/Dir_SetInventory.h"

UDir_SetInventory::UDir_SetInventory()
{
	_nNumParamsDefined = 3;
}

void UDir_SetInventory::Destroyed()
{
	Super::Destroyed();
	//_InvMod = nullptr;
	_Pawn = nullptr;
	_Actor = nullptr;
}

void UDir_SetInventory::DirectionStart()
{
	/*
	if (_Pawn == None)
	{
		Log("Dir_SetInventory::DirectionStart() - _Pawn == None");
		if (_Actor != None)
		{
			Log("Dir_SetInventory::DirectionStart() - _Actor != None");
			if (_Actor.IsA('HumanController'))
			{
				Log("Dir_SetInventory::DirectionStart() - _Actor.IsA('HumanController')");
				_Pawn = AGP_Pawn(HumanController(_Actor).Pawn);
			}
			if (_Actor.IsA('AGP_Pawn'))
			{
				Log("Dir_SetInventory::DirectionStart() - _Actor != _Actor.IsA('AGP_Pawn')");
				_Pawn = AGP_Pawn(_Actor);
			}
		}
	}
	if (_bDebug)
	{
		Log("Dir_SetInventory::DirectionStart()");
	}
	if ((_InvMod != None) && (_Pawn != None))
	{
		_InvMod.Run(_Pawn);
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_SetInventory::DirectionStart() - _InvMod == " $ string(_InvMod) $ " and _Pawn == " $ string(_Pawn));
		}
	}
	*/
}

void UDir_SetInventory::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetInventory::DirectionFinish()");
	}
	*/
}

bool UDir_SetInventory::ProcessParams()
{
	/*
	_InvMod = AGP_InventoryModifier(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (GetParam(1) != "")
	{
		_Actor = _ParentScreenplay.GetActorByTag(string(GetParam(1)));
	}
	_Pawn = AGP_Pawn(_ParentScreenplay.GetActorByTag(string(GetParam(2))));
	*/
	return true;
}


void UDir_SetInventory::SetInventoryModifier(AAGP_InventoryModifier* invmod)
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetInventory::SetInventoryModifier()");
	}
	_InvMod = invmod;
	*/
}


void UDir_SetInventory::SetPawn(AAGP_Pawn* Pawn)
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetInventory::SetPawn()");
	}
	_Pawn = Pawn;
	*/
}

void UDir_SetInventory::SetActor(AActor* Actor)
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetInventory::SetActor()");
	}
	_Actor = Actor;
	*/
}
