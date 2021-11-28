// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_CheckParachute/Dir_CheckParachute.h"

UDir_CheckParachute::UDir_CheckParachute()
{
	_nNumParamsDefined = 1;
}

void UDir_CheckParachute::Destroyed()
{
	Super::Destroyed();
	_IntVar = nullptr;
	_HumanController = nullptr;
}

void UDir_CheckParachute::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_CheckParachute::DirectionStart()");
	}
	if (_HumanController != None)
	{
		Log("DIR_CheckParachute::setting value.");
		_IntVar.SetValue(Rand(3));
	}
	*/
}

bool UDir_CheckParachute::ProcessParams()
{
	/*
	_IntVar = AGP_IntVar(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_IntVar == None)
	{
		if (_bDebug)
		{
			Log("Dir_CheckParachute::ProcessParams() - could not find AGP_IntVar with tag " $ GetParam(0));
		}
		return false;
	}
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	*/
	return true;
}
