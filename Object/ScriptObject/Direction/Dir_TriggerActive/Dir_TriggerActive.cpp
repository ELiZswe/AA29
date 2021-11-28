// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_TriggerActive/Dir_TriggerActive.h"

UDir_TriggerActive::UDir_TriggerActive()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}

void UDir_TriggerActive::Destroyed()
{
	/*
	Super::Destroyed();
	_Trigger = None;
	_AGPTrigger = None;
	*/
}

void UDir_TriggerActive::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_TriggerActive::DirectionStart()");
	}
	if (_Trigger != None)
	{
		_Trigger.SetActive(_bActive);
	}
	else
	{
		if (_AGPTrigger != None)
		{
			_AGPTrigger.SetActive(_bActive);
		}
		else
		{
			if (_bDebug)
			{
				Log("Dir_TriggerActive::DirectionStart() - _Trigger and _AGPTrigger == None");
			}
		}
	}
	*/
}

void UDir_TriggerActive::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_TriggerActive::DirectionFinish()");
	}
	*/
}

bool UDir_TriggerActive::ProcessParams()
{
	/*
	local Actor A;
	_bActive = bool(GetParam(1));
	A = _ParentScreenplay.GetActorByTag(string(GetParam(0)));
	if (Trigger(A) != None)
	{
		_Trigger = Trigger(A);
	}
	else
	{
		if (AGP_Trigger(A) != None)
		{
			_AGPTrigger = AGP_Trigger(A);
		}
		else
		{
			Log("Dir_TriggerActive::ProcessParams() - could not find Trigger or AGP_Trigger with tag " $ GetParam(0));
			return false;
		}
	}
	*/
	return true;
}