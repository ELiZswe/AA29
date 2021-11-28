// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SetIntVar/Dir_SetIntVar.h"

UDir_SetIntVar::UDir_SetIntVar()
{
	bSupportsMP = true;
	_nNumParamsDefined = 3;
}

void UDir_SetIntVar::Destroyed()
{
	Super::Destroyed();
	_IntVar = nullptr;
}

void UDir_SetIntVar::DirectionStart()
{
	/*
	int32 Value = 0;
	if (_bDebug)
	{
		Log("Dir_SetIntVar::DirectionStart()");
	}
	if (_IntVar == None)
	{
		Log("ERROR: Dir_SetIntVar::DirectionStart() - _IntVar == None");
	}
	else
	{
		Value = _IntVar.GetValue();
		switch (_Operation)
		{
		case 1:
			Value = _value;
			break;
		case 2:
			(Value += _value);
			break;
		case 3:
			(Value -= _value);
			break;
		default:
			return;
			break;
		}
		_IntVar.SetValue(Value);
	}
	*/
}

void UDir_SetIntVar::DirectionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SetIntVar::DirectionStart()");
	}
	*/
}

bool UDir_SetIntVar::ProcessParams()
{
	/*
	FString sOperation = "";
	FName intvartag = "";
	if (_bDebug)
	{
		Log("Dir_StartTimer::ProcessParams()");
	}
	intvartag = string(GetParam(0));
	sOperation = GetParam(1);
	_value = int(GetParam(2));
	_IntVar = AGP_IntVar(_ParentScreenplay.GetActorByTag(intvartag));
	if (_IntVar == None)
	{
		Log("Dir_CreateIntVar::ProcessParams() - could not find _IntVar with tag " $ GetParam(0));
		return false;
	}
	switch (sOperation)
	{
	case "SET":
		_Operation = 1;
		break;
	case "INC":
		_Operation = 2;
		break;
	case "DEC":
		_Operation = 3;
		break;
	case "EQ":
		_Operation = 1;
		break;
	default:
		_Operation = 0;
		return false;
		break;
	}
	*/
	return true;
}
