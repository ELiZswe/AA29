// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenIntVar/Cond_WhenIntVar.h"
#include "AA29/Object/Actor/AGP_IntVar/AGP_IntVar.h"

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
	if (_bDebug)
	{
		//Log("Cond_WhenEventSounds::ConditionStart()");
	}
	_IntVar->SetTarget(this);
}

void UCond_WhenIntVar::ConditionFinish()
{
	if (_bDebug)
	{
		//Log("Cond_WhenEventSounds::ConditionFinish()");
	}
	_IntVar->SetTarget(nullptr);
}

bool UCond_WhenIntVar::ProcessParams()
{
	FString sComparison = "";
	//_IntVar = Cast<AAGP_IntVar>(_ParentScreenplay.GetActorByTag(string(GetParam(0))));
	sComparison = GetParam(1);
	//_value = int(GetParam(2));
	if (_IntVar == nullptr)
	{
		if (_bDebug)
		{
			//Log("Cond_WhenIntVarIs::ProcessParams() - could not find AGP_IntVar with tag " + GetParam(0));
		}
		return false;
	}
	/*
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
	int32 iCurrVal = 0;
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Cond_WhenIntVarIs::Update()"));
	}
	if ((_IntVar != nullptr) && (_Comparison != EComparison::EC_None))
	{
		iCurrVal = _IntVar->GetValue();
		_bTrue = false;
		switch (_Comparison)
		{
			case EComparison::EC_EQ:
				if (_value == iCurrVal)
				{
					_bTrue = true;
				}
				break;
			case EComparison::EC_NEQ:
				if (_value != iCurrVal)
				{
					_bTrue = true;
				}
				break;
			case EComparison::EC_GT:
				if (_value > iCurrVal)
				{
					_bTrue = true;
				}
				break;
			case EComparison::EC_GTE:
				if (_value >= iCurrVal)
				{
					_bTrue = true;
				}
				break;
			case EComparison::EC_LT:
				if (_value < iCurrVal)
				{
					_bTrue = true;
				}
				break;
			case EComparison::EC_LTE:
				if (_value <= iCurrVal)
				{
					_bTrue = true;
				}
				break;
			default:
				break;
		}
		if (_bTrue)
		{
			Notify();
		}
	}
}
