// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_JumpOnIntVar/Dir_JumpOnIntVar.h"

UDir_JumpOnIntVar::UDir_JumpOnIntVar()
{
	bSupportsMP = true;
	_nNumParamsDefined = 4;
}

void UDir_JumpOnIntVar::Destroyed()
{
	Super::Destroyed();
	_IntVar = nullptr;
}

void UDir_JumpOnIntVar::DirectionStart()
{
	/*
	int32 Value = 0;
	if (_bDebug)
	{
		Log("Dir_JumpOnIntVar::DirectionStart()");
	}
	if (_IntVar == None)
	{
		Log("ERROR: Dir_JumpOnIntVar::DirectionStart() - _IntVar == None");
		return;
	}
	if (_ParentScreenplay == None)
	{
		Log("ERROR: Dir_JumpOnIntVar::DirectionStart() - _ParentScreenplay == None");
		return;
	}
	Value = _IntVar.GetValue();
	if ((Value >= _Min) && (Value <= _Max))
	{
		if (_bDebug)
		{
			Log("Dir_JumpOnIntVar::DirectionStart() in range, jumping.");
		}
		_ParentScreenplay.SceneJump(_JumpScene);
	}
	else
	{
		if (_bDebug)
		{
			Log("Dir_JumpOnIntVar::DirectionStart() not in range.  Wanted " $ string(_Min) $ "<x<" $ string(_Max) $ " got " $ string(Value));
		}
	}
	*/
}

void UDir_JumpOnIntVar::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_JumpOnIntVar::DirectionFinish()");
	}
	*/
}

bool UDir_JumpOnIntVar::ProcessParams()
{
	/*
	if (_bDebug)
	{
		Log("Dir_JumpOnIntVar::ProcessParams()");
	}
	_IntVar = AGP_IntVar(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	_Min = int(GetParam(1));
	_Max = int(GetParam(2));
	_JumpScene = string(GetParam(3));
	*/
	return true;
}