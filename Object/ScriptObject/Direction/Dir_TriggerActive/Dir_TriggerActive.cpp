// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_TriggerActive/Dir_TriggerActive.h"
#include "AA29/Object/Actor/AGP_Trigger/AGP_Trigger.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"

UDir_TriggerActive::UDir_TriggerActive()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}

void UDir_TriggerActive::Destroyed()
{
	/*
	Super::Destroyed();
	_Trigger = nullptr;
	_AGPTrigger = nullptr;
	*/
}

void UDir_TriggerActive::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_TriggerActive::DirectionStart()");
	}
	if (_Trigger != nullptr)
	{
		_Trigger.SetActive(_bActive);
	}
	else
	{
		if (_AGPTrigger != nullptr)
		{
			_AGPTrigger.SetActive(_bActive);
		}
		else
		{
			if (_bDebug)
			{
				Log("Dir_TriggerActive::DirectionStart() - _Trigger and _AGPTrigger == nullptr");
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
	AActor* A = nullptr;
	/*
	_bActive = bool(GetParam(1));
	A = _ParentScreenplay.GetActorByTag(string(GetParam(0)));
	if (Cast<ATrigger>(A) != nullptr)
	{
		_Trigger = Cast<ATrigger>(A);
	}
	else
	{
		if (Cast<AAGP_Trigger>(A) != nullptr)
		{
			_AGPTrigger = Cast<AAGP_Trigger>(A);
		}
		else
		{
			Log("Dir_TriggerActive::ProcessParams() - could not find Trigger or AGP_Trigger with tag " + GetParam(0));
			return false;
		}
	}
	*/
	return true;
}
