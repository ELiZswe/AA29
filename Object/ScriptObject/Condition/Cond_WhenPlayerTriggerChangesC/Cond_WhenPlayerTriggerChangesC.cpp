// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenPlayerTriggerChangesC/Cond_WhenPlayerTriggerChangesC.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/ScriptObject/ScriptObject.h"

UCond_WhenPlayerTriggerChangesC::UCond_WhenPlayerTriggerChangesC()
{
	_nNumParamsDefined = 2;
}

void UCond_WhenPlayerTriggerChangesC::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UCond_WhenPlayerTriggerChangesC::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPlayerTriggerChangesC::ConditionStart()");
	}
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		Cast<AAGP_Pawn>(_HumanController.Pawn).SetCurrentTriggerMonitor3(this);
	}
	*/
}

void UCond_WhenPlayerTriggerChangesC::ConditionFinish()
{
	UScriptObject* soBlank = nullptr;
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPlayerTriggerChangesC::ConditionFinish()");
	}
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		Cast<AAGP_Pawn>(_HumanController.Pawn).SetCurrentTriggerMonitor3(soBlank);
	}
	*/
}

bool UCond_WhenPlayerTriggerChangesC::ProcessParams()
{
	/*
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	_TriggerTag = FString::FromInt(GetParam(0));
	_bEntry = bool(GetParam(1));
	if (_TriggerTag == "None")
	{
		if (_bDebug)
		{
			Log("Cond_WhenPlayerTriggerChangesC::ProcessParams() - could not get Trigger with tag " + GetParam(0));
		}
		return false;
	}
	*/
	return true;
}

void UCond_WhenPlayerTriggerChangesC::update()
{
	AActor* trig = nullptr;
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPlayerTriggerChangesC::Update()");
	}
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		trig = Cast<AAGP_Pawn>(_HumanController.Pawn).GetCurrentTrigger();
		if (_bEntry)
		{
			if (trig != nullptr)
			{
				if (trig.Tag == _TriggerTag)
				{
					_bTrue = true;
					Notify();
				}
				else
				{
					_bTrue = false;
				}
			}
		}
		else
		{
			if (trig == nullptr)
			{
				_bTrue = true;
				Notify();
			}
			else
			{
				_bTrue = false;
				if (trig.Tag == _TriggerTag)
				{
					bWasInTrigger = true;
				}
				else
				{
					bWasInTrigger = false;
				}
			}
		}
	}
	*/
}
