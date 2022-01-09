// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenPlayerTriggerChangesB/Cond_WhenPlayerTriggerChangesB.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UCond_WhenPlayerTriggerChangesB::UCond_WhenPlayerTriggerChangesB()
{
	_nNumParamsDefined = 2;
}

void UCond_WhenPlayerTriggerChangesB::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UCond_WhenPlayerTriggerChangesB::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPlayerTriggerChangesB::ConditionStart(): " @ string(_TriggerTag));
	}
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		AGP_Pawn(_HumanController.Pawn).SetCurrentTriggerMonitor2(this);
	}
	*/
}

void UCond_WhenPlayerTriggerChangesB::ConditionFinish()
{
	/*
	local ScriptObject soBlank;
	if (_bDebug)
	{
		Log("Cond_WhenPlayerTriggerChangesB::ConditionFinish(): " @ string(_TriggerTag));
	}
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		AGP_Pawn(_HumanController.Pawn).SetCurrentTriggerMonitor2(soBlank);
	}
	*/
}

bool UCond_WhenPlayerTriggerChangesB::ProcessParams()
{
	/*
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_TriggerTag = string(GetParam(0));
	_bEntry = bool(GetParam(1));
	if (_TriggerTag == "None")
	{
		if (_bDebug)
		{
			Log("Cond_WhenPlayerTriggerChangesB::ProcessParams() - could not get Trigger with tag " $ GetParam(0));
		}
		return false;
	}
	*/
	return true;
}

void UCond_WhenPlayerTriggerChangesB::update()
{
	/*
	local Actor trig;
	if (_bDebug)
	{
		Log("Cond_WhenPlayerTriggerChangesB::Update()");
	}
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		trig = AGP_Pawn(_HumanController.Pawn).GetCurrentTrigger();
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
