// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_JumpOnPlayerHealth/Dir_JumpOnPlayerHealth.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

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
	if (_ParentScreenplay == nullptr)
	{
		Log("ERROR: Dir_JumpOnPlayerHealth::DirectionStart() - _ParentScreenplay == nullptr");
		return;
	}
	if (_HumanController == nullptr)
	{
		Log("ERROR: Dir_JumpOnPlayerHealth::DirectionStart() - _HumanController == nullptr");
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
				Log("Dir_JumpOnPlayerHealth::DirectionStart() not in range.  Wanted " + FString::FromInt(_Min) + "<x<" + FString::FromInt(_Max) + " got " + FString::FromInt(Value));
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
	_JumpScene = FString::FromInt(GetParam(2));
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	*/
	return true;
}
