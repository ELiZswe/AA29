// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_SetInventory/Dir_SetInventory.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Triggers/Trigger/AGP_InventoryModifier/AGP_InventoryModifier.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

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
	if (_Pawn == nullptr)
	{
		//Log("Dir_SetInventory::DirectionStart() - _Pawn == nullptr");
		if (_Actor != nullptr)
		{
			//Log("Dir_SetInventory::DirectionStart() - _Actor != nullptr");
			if (_Actor->IsA(AHumanController::StaticClass()))
			{
				//Log("Dir_SetInventory::DirectionStart() - _Actor->IsA(AHumanController::StaticClass())");
				_Pawn = Cast<AAGP_Pawn>(Cast<AHumanController>(_Actor)->GetPawn());
			}
			if (_Actor->IsA(AAGP_Pawn::StaticClass()))
			{
				//Log("Dir_SetInventory::DirectionStart() - _Actor != _Actor->IsA(AAGP_Pawn::StaticClass())");
				_Pawn = Cast<AAGP_Pawn>(_Actor);
			}
		}
	}
	if (_bDebug)
	{
		//Log("Dir_SetInventory::DirectionStart()");
	}
	if ((_InvMod != nullptr) && (_Pawn != nullptr))
	{
		_InvMod->Run(_Pawn);
	}
	else
	{
		if (_bDebug)
		{
			//Log("Dir_SetInventory::DirectionStart() - _InvMod == " + FString::FromInt(_InvMod) + " and _Pawn == " + FString::FromInt(_Pawn));
		}
	}
}

void UDir_SetInventory::DirectionFinish()
{
	if (_bDebug)
	{
		//Log("Dir_SetInventory::DirectionFinish()");
	}
}

bool UDir_SetInventory::ProcessParams()
{
	//_InvMod = Cast<AAGP_InventoryModifier>(_ParentScreenplay->GetActorByTag(GetParam(0)));
	if (GetParam(1) != "")
	{
		//_Actor = _ParentScreenplay->GetActorByTag(GetParam(1));
	}
	//_Pawn = Cast<AAGP_Pawn>(_ParentScreenplay->GetActorByTag(GetParam(2)));
	return true;
}

void UDir_SetInventory::SetInventoryModifier(AAGP_InventoryModifier* invmod)
{
	if (_bDebug)
	{
		//Log("Dir_SetInventory::SetInventoryModifier()");
	}
	_InvMod = invmod;
}

void UDir_SetInventory::SetPawn(AAGP_Pawn* Pawn)
{
	if (_bDebug)
	{
		//Log("Dir_SetInventory::SetPawn()");
	}
	_Pawn = Pawn;
}

void UDir_SetInventory::SetActor(AActor* Actor)
{
	if (_bDebug)
	{
		//Log("Dir_SetInventory::SetActor()");
	}
	_Actor = Actor;
}
