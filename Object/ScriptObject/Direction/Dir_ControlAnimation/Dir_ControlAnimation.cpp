// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_ControlAnimation/Dir_ControlAnimation.h"

UDir_ControlAnimation::UDir_ControlAnimation()
{
	_nNumParamsDefined = 7;
}

void UDir_ControlAnimation::Destroyed()
{
	Super::Destroyed();
	_Controller = nullptr;
}

void UDir_ControlAnimation::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_ControlAnimation::DirectionStart()");
	}
	if (_Controller != None)
	{
		_Controller.AddInstruction(_Instruction);
	}
	*/
}

bool UDir_ControlAnimation::ProcessParams()
{
	/*
	FString animfunc = "";
	_Controller = AnimationController(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	if (_Controller == None)
	{
		if (_bDebug)
		{
			Log("Dir_ControlAnimation::ProcessParams() - could not find actor with tag " $ GetParam(0));
		}
		return false;
	}
	animfunc = GetParam(1);
	if (animfunc == "PlayAnim")
	{
		_Instruction.Command = 0;
		_Instruction.Sequence = string(GetParam(2));
		_Instruction.Rate = float(GetParam(3));
		_Instruction.Time = float(GetParam(4));
		_Instruction.Channel = int(GetParam(5));
	}
	else
	{
		if (animfunc == "LoopAnim")
		{
			_Instruction.Command = 1;
			_Instruction.Sequence = string(GetParam(2));
			_Instruction.Rate = float(GetParam(3));
			_Instruction.Time = float(GetParam(4));
			_Instruction.Channel = int(GetParam(5));
			_Instruction.LoopNum = int(GetParam(6));
		}
		else
		{
			if (animfunc == "TweenAnim")
			{
				_Instruction.Command = 2;
				_Instruction.Sequence = string(GetParam(2));
				_Instruction.Time = float(GetParam(4));
				_Instruction.Channel = int(GetParam(5));
			}
			else
			{
				if (animfunc == "StopAnimating")
				{
					_Instruction.Command = 3;
				}
				else
				{
					if (animfunc == "FreezeAnimAt")
					{
						_Instruction.Command = 4;
						_Instruction.Time = float(GetParam(4));
						_Instruction.Channel = int(GetParam(5));
					}
					else
					{
						if (animfunc == "ClearAll")
						{
							_Instruction.Command = 5;
						}
						else
						{
							if (_bDebug)
							{
								Log("Dir_ControlAnimation::ProcessParams() - could not find animation func named " $ animfunc);
							}
							return false;
						}
					}
				}
			}
		}
	}
	*/
	return true;
}
