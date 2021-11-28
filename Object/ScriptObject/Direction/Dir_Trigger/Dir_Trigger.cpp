// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_Trigger/Dir_Trigger.h"

UDir_Trigger::UDir_Trigger()
{
	bSupportsMP = true;
	_nNumParamsDefined = 1;
}

void UDir_Trigger::Destroyed()
{
	/*
	Super::Destroyed();
	_Trigger = None;
	*/
}

void UDir_Trigger::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_Trigger::DirectionStart()");
	}
	if (_Trigger != None)
	{
		_Trigger.Trigger(None, _ParentScreenplay.GetHumanController().Pawn);
	}
	*/
}

void UDir_Trigger::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_Trigger::DirectionFinish()");
	}
	*/
}

bool UDir_Trigger::ProcessParams()
{
	/*
	_Trigger = _ParentScreenplay.GetActorByTag(string(GetParam(0)));
	if (_Trigger == None)
	{
		Log("Dir_Trigger::ProcessParams() - could not find Trigger with tag " $ GetParam(0));
		return false;
	}
	*/
	return true;
}