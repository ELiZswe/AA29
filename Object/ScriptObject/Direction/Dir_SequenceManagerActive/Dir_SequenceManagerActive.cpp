// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_SequenceManagerActive/Dir_SequenceManagerActive.h"
#include "AA29/Object/Actor/Triggers/SequenceManager/SequenceManager.h"

UDir_SequenceManagerActive::UDir_SequenceManagerActive()
{
	_nNumParamsDefined = 2;
}

void UDir_SequenceManagerActive::Destroyed()
{
	Super::Destroyed();
	_SequenceManager = nullptr;
}

void UDir_SequenceManagerActive::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SequenceManagerActive::DirectionStart() " + FString::FromInt(_bActive));
	}
	if (_SequenceManager != nullptr)
	{
		if (_bActive)
		{
			_SequenceManager.EnableSequence();
		}
		else
		{
			_SequenceManager.DisableSequence();
		}
	}
	*/
}

bool UDir_SequenceManagerActive::ProcessParams()
{
	/*
	_SequenceManager = SequenceManager(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	_bActive = bool(GetParam(1));
	*/
	return true;
}
