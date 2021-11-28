// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_EnableObjective/Dir_EnableObjective.h"

UDir_EnableObjective::UDir_EnableObjective()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}

void UDir_EnableObjective::Destroyed()
{
	Super::Destroyed();
	_Objective = nullptr;
}

void UDir_EnableObjective::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_EnableObjective::DirectionStart()");
	}
	if (_Objective != None)
	{
		_Objective.SetDisabled((!_bEnabled));
	}
	*/
}

void UDir_EnableObjective::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_EnableObjective::DirectionStart()");
	}
	*/
}

bool UDir_EnableObjective::ProcessParams()
{
	/*
	FName ObjectiveTag = "";
	if (_bDebug)
	{
		Log("Dir_EnableObjective::ProcessParams()");
	}
	ObjectiveTag = string(GetParam(0));
	_bEnabled = bool(GetParam(1));
	_Objective = AGP_Objective(_ParentScreenplay.GetActorByTag(ObjectiveTag));
	if (_Objective == None)
	{
		Log("Dir_EnableObjective::ProcessParams() - could not get AGP_Objective with tag " $ GetParam(0));
		return false;
	}
	*/
	return true;
}
