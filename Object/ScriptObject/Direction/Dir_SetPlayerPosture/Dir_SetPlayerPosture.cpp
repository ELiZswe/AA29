// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_SetPlayerPosture/Dir_SetPlayerPosture.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UDir_SetPlayerPosture::UDir_SetPlayerPosture()
{
	_nNumParamsDefined = 1;
}

void UDir_SetPlayerPosture::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_SetPlayerPosture::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetPlayerPosture::DirectionStart()");
	}
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		if (_iPosture == 0)
		{
			_HumanController.Pawn.ShouldStand(true);
		}
		else
		{
			if (_iPosture == 1)
			{
				_HumanController.Pawn.ShouldCrouch(true);
			}
			else
			{
				if (_iPosture == 2)
				{
					_HumanController.Pawn.ShouldProne(true);
				}
			}
		}
	}
	*/
}

void UDir_SetPlayerPosture::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetPlayerPosture::DirectionFinish()");
	}
	*/
}

bool UDir_SetPlayerPosture::ProcessParams()
{
	/*
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	_iPosture = int(GetParam(0));
	*/
	return true;
}
