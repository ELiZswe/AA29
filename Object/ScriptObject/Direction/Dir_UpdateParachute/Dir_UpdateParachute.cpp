// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_UpdateParachute/Dir_UpdateParachute.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UDir_UpdateParachute::UDir_UpdateParachute()
{
	_nNumParamsDefined = 1;
}

void UDir_UpdateParachute::Destroyed()
{
	/*
	Super::Destroyed();
	_HumanController = nullptr;
	*/
}

void UDir_UpdateParachute::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_UpdateParachute::DirectionStart()");
	}
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		_HumanController.Pawn.UpdateParachute(_UpdateValue);
	}
	*/
}

bool UDir_UpdateParachute::ProcessParams()
{
	/*
	_UpdateValue = int(GetParam(0));
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	*/
	return true;
}
