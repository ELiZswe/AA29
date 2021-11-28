// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetActor/Dir_SetActor.h"

UDir_SetActor::UDir_SetActor()
{
	bSupportsMP = true;
	_nNumParamsDefined = 2;
}

void UDir_SetActor::Destroyed()
{
	Super::Destroyed();
	_aActor = nullptr;
}

void UDir_SetActor::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SceneJump::DirectionStart()");
	}
	if (_ParentScreenplay != None)
	{
		_ParentScreenplay.SetActor(_iIndex, _aActor);
	}
	*/
}

bool UDir_SetActor::ProcessParams()
{
	/*
	FName nActor = "";
	_iIndex = int(GetParam(0));
	nActor = string(GetParam(1));
	if (nActor == 'None')
	{
		_aActor = None;
	}
	else
	{
		_aActor = _ParentScreenplay.GetActorByTag(nActor);
	}
	*/
	return true;
}
