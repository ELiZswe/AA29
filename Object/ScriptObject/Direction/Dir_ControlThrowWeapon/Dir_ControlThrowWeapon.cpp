// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_ControlThrowWeapon/Dir_ControlThrowWeapon.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UDir_ControlThrowWeapon::UDir_ControlThrowWeapon()
{
	bSupportsMP = true;
	_nNumParamsDefined = 1;
}

void UDir_ControlThrowWeapon::DirectionStart()
{
	/*
	AController* C = nullptr;
	if (_bDebug)
	{
		Log("Dir_ControlThrowWeapon::DirectionStart() with throw=" + FString::FromInt(_bThrow));
	}
	C = _ParentScreenplay.GetControllerList();
	if (C != nullptr)
	{
		if (C != nullptr)
		{
			if (C->IsA(AHumanController::StaticClass()))
			{
				Cast<AHumanController>(C).bNoThrowWeapon = _bThrow;
				if (_bDebug)
				{
					Log("Dir_ControlThrowWeapon::DirectionStart() setting throw for controller: " + FString::FromInt(C));
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
		Log("Dir_ControlThrowWeapon::DirectionStart() created with throw=" + FString::FromInt(_bThrow));
	}
	*/
	return true;
}
