// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_PlayerLockMovement/Dir_PlayerLockMovement.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UDir_PlayerLockMovement::UDir_PlayerLockMovement()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}

void UDir_PlayerLockMovement::DirectionStart()
{
	/*
	AController* C = nullptr;
	if (_bDebug)
	{
		Log("Dir_PlayerLockMovement::DirectionStart() with movement=" + FString::FromInt(_bLockMovement) + " and rot=" + FString::FromInt(_bLockRotation));
	}
	C = _ParentScreenplay.GetControllerList();
	if (C != nullptr)
	{
		if (C != nullptr)
		{
			if (C->IsA(AHumanController::StaticClass()))
			{
				Cast<AHumanController>(C).LockPlayer(_bLockMovement, _bLockRotation);
				if (_bDebug)
				{
					Log("Dir_PlayerLockMovement::DirectionStart() locking controller: " + FString::FromInt(C));
				}
			}
			C = C.nextController;
		}
	}
	else
	{
		Log("Dir_PlayerLockMovement::DirectionStart found no controller!");
	}
	*/
}

bool UDir_PlayerLockMovement::ProcessParams()
{
	/*
	_bLockMovement = bool(GetParam(0));
	_bLockRotation = bool(GetParam(1));
	if (_bDebug)
	{
		Log("Dir_PlayerLockMovement::DirectionStart() created with movement=" + FString::FromInt(_bLockMovement) + " and rot=" + FString::FromInt(_bLockRotation));
	}
	*/
	return true;
}
