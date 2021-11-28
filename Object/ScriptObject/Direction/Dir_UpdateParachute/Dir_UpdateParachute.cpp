// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_UpdateParachute/Dir_UpdateParachute.h"

UDir_UpdateParachute::UDir_UpdateParachute()
{
	_nNumParamsDefined = 1;
}

void UDir_UpdateParachute::Destroyed()
{
	/*
	Super::Destroyed();
	_HumanController = None;
	*/
}

void UDir_UpdateParachute::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_UpdateParachute::DirectionStart()");
	}
	if ((_HumanController != None) && (_HumanController.Pawn != None))
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