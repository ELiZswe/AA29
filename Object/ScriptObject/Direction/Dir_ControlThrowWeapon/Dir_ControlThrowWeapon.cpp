// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_ControlThrowWeapon/Dir_ControlThrowWeapon.h"

UDir_ControlThrowWeapon::UDir_ControlThrowWeapon()
{
	bSupportsMP = true;
	_nNumParamsDefined = 1;
}

void UDir_ControlThrowWeapon::DirectionStart()
{
	/*
	local Controller C;
	if (_bDebug)
	{
		Log("Dir_ControlThrowWeapon::DirectionStart() with throw=" $ string(_bThrow));
	}
	C = _ParentScreenplay.GetControllerList();
	if (C != None)
	{
		if (C != None)
		{
			if (C.IsA('HumanController'))
			{
				HumanController(C).bNoThrowWeapon = _bThrow;
				if (_bDebug)
				{
					Log("Dir_ControlThrowWeapon::DirectionStart() setting throw for controller: " $ string(C));
				}
			}
			C = C.nextController;
		}
	}
	else
	{
		Log("Dir_ControlThrowWeapon::DirectionStart found no controllers!");
	}
	*/
}

bool UDir_ControlThrowWeapon::ProcessParams()
{
	/*
	_bThrow = bool(GetParam(0));
	if (_bDebug)
	{
		Log("Dir_ControlThrowWeapon::DirectionStart() created with throw=" $ string(_bThrow));
	}
	*/
	return true;
}
