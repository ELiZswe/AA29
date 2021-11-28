// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetPlayerPosture/Dir_SetPlayerPosture.h"

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
	if ((_HumanController != None) && (_HumanController.Pawn != None))
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
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_iPosture = int(GetParam(0));
	*/
	return true;
}
