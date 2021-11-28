// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenIntVar/Cond_WhenIntVar.h"

UCond_WhenIntVar::UCond_WhenIntVar()
{
	bSupportsMP = true;
	_nNumParamsDefined = 3;
}

void UCond_WhenIntVar::Destroyed()
{
	Super::Destroyed();
	_IntVar = nullptr;
}

void UCond_WhenIntVar::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenEventSounds::ConditionStart()");
	}
	_IntVar.SetTarget(Self);
	*/
}

void UCond_WhenIntVar::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenEventSounds::ConditionFinish()");
	}
	_IntVar.SetTarget(None);
	*/
}

bool UCond_WhenIntVar::ProcessParams()
{
	/*
	FString sComparison = "";
	_IntVar = AGP_IntVar(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	sComparison = GetParam(1);
	_value = int(GetParam(2));
	if (_IntVar == None)
	{
		if (_bDebug)
		{
			Log("Cond_WhenIntVarIs::ProcessParams() - could not find AGP_IntVar with tag " $ GetParam(0));
		}
		return false;
	}
	switch (sComparison)
	{
	case "EQ":
		_Comparison = 1;
		break;
	case "NEQ":
		_Comparison = 2;
		break;
	case "GT":
		_Comparison = 3;
		break;
	case "GTE":
		_Comparison = 4;
		break;
	case "LT":
		_Comparison = 5;
		break;
	case "LTE":
		_Comparison = 6;
		break;
	default:
		_Comparison = 0;
		return false;
		break;
	}
	*/
	return true;
}

void UCond_WhenIntVar::update()
{
	/*
	int32 iCurrVal = 0;
	if (_bDebug)
	{
		Log("Cond_WhenIntVarIs::Update()");
	}
	if ((_IntVar != None) && (_Comparison != 0))
	{
		iCurrVal = _IntVar.GetValue();
		_bTrue = false;
		switch (_Comparison)
		{
		case 1:
			if (_value == iCurrVal)
			{
				_bTrue = true;
			}
			break;
		case 2:
			if (_value != iCurrVal)
			{
				_bTrue = true;
			}
			break;
		case 3:
			if (_value > iCurrVal)
			{
				_bTrue = true;
			}
			break;
		case 4:
			if (_value >= iCurrVal)
			{
				_bTrue = true;
			}
			break;
		case 5:
			if (_value < iCurrVal)
			{
				_bTrue = true;
			}
			break;
		case 6:
			if (_value <= iCurrVal)
			{
				_bTrue = true;
			}
			break;
		default:
		}
		if (_bTrue)
		{
			Notify();
		}
	}
	*/
}
