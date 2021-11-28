// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_PlayerLockMovement/Dir_PlayerLockMovement.h"

UDir_PlayerLockMovement::UDir_PlayerLockMovement()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}

void UDir_PlayerLockMovement::DirectionStart()
{
	/*
	local Controller C;
	if (_bDebug)
	{
		Log("Dir_PlayerLockMovement::DirectionStart() with movement=" $ string(_bLockMovement) $ " and rot=" $ string(_bLockRotation));
	}
	C = _ParentScreenplay.GetControllerList();
	if (C != None)
	{
		if (C != None)
		{
			if (C.IsA('HumanController'))
			{
				HumanController(C).LockPlayer(_bLockMovement, _bLockRotation);
				if (_bDebug)
				{
					Log("Dir_PlayerLockMovement::DirectionStart() locking controller: " $ string(C));
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
		Log("Dir_PlayerLockMovement::DirectionStart() created with movement=" $ string(_bLockMovement) $ " and rot=" $ string(_bLockRotation));
	}
	*/
	return true;
}