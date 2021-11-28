// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_JumpOnPlayerHealth/Dir_JumpOnPlayerHealth.h"

UDir_JumpOnPlayerHealth::UDir_JumpOnPlayerHealth()
{
	bSupportsMP = true;
	_nNumParamsDefined = 3;
}

void UDir_JumpOnPlayerHealth::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_JumpOnPlayerHealth::DirectionStart()
{
	/*
	int32 Value = 0;
	if (_bDebug)
	{
		Log("Dir_JumpOnPlayerHealth::DirectionStart()");
	}
	if (_ParentScreenplay == None)
	{
		Log("ERROR: Dir_JumpOnPlayerHealth::DirectionStart() - _ParentScreenplay == None");
		return;
	}
	if (_HumanController == None)
	{
		Log("ERROR: Dir_JumpOnPlayerHealth::DirectionStart() - _HumanController == None");
		return;
	}
	else
	{
		Value = _HumanController.Pawn.Health;
		if ((Value >= _Min) && (Value <= _Max))
		{
			if (_bDebug)
			{
				Log("Dir_JumpOnPlayerHealth::DirectionStart() in range, jumping.");
			}
			_ParentScreenplay.SceneJump(_JumpScene);
		}
		else
		{
			if (_bDebug)
			{
				Log("Dir_JumpOnPlayerHealth::DirectionStart() not in range.  Wanted " $ string(_Min) $ "<x<" $ string(_Max) $ " got " $ string(Value));
			}
		}
	}
	*/
}

void UDir_JumpOnPlayerHealth::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_JumpOnPlayerHealth::DirectionFinish()");
	}
	*/
}

bool UDir_JumpOnPlayerHealth::ProcessParams()
{
	/*
	if (_bDebug)
	{
		Log("Dir_JumpOnPlayerHealth::ProcessParams()");
	}
	_Min = int(GetParam(0));
	_Max = int(GetParam(1));
	_JumpScene = string(GetParam(2));
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	*/
	return true;
}
