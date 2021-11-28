// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenPlayerTriggerChanges/Cond_WhenPlayerTriggerChanges.h"

UCond_WhenPlayerTriggerChanges::UCond_WhenPlayerTriggerChanges()
{
	_bDebug = true;
	_nNumParamsDefined = 2;
}

void UCond_WhenPlayerTriggerChanges::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UCond_WhenPlayerTriggerChanges::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPlayerTriggerChanges::ConditionStart(): " @ string(_TriggerTag));
	}
	if ((_HumanController != None) && (_HumanController.Pawn != None))
	{
		AGP_Pawn(_HumanController.Pawn).SetCurrentTriggerMonitor(Self);
	}
	*/
}

void UCond_WhenPlayerTriggerChanges::ConditionFinish()
{
	/*
	local ScriptObject soBlank;
	if (_bDebug)
	{
		Log("Cond_WhenPlayerTriggerChanges::ConditionFinish(): " @ string(_TriggerTag));
	}
	if ((_HumanController != None) && (_HumanController.Pawn != None))
	{
		AGP_Pawn(_HumanController.Pawn).SetCurrentTriggerMonitor(soBlank);
	}
	*/
}

bool UCond_WhenPlayerTriggerChanges::ProcessParams()
{
	/*
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_TriggerTag = string(GetParam(0));
	_bEntry = bool(GetParam(1));
	if (_TriggerTag == 'None')
	{
		if (_bDebug)
		{
			Log("Dir_StartTimer::ProcessParams() - could not get Trigger with tag " $ GetParam(0));
		}
		return false;
	}
	*/
	return true;
}

void UCond_WhenPlayerTriggerChanges::update()
{
	/*
	local Actor trig;
	if (_bDebug)
	{
		Log("Cond_WhenPlayerTriggerChanges::Update()");
	}
	if ((_HumanController != None) && (_HumanController.Pawn != None))
	{
		trig = AGP_Pawn(_HumanController.Pawn).GetCurrentTrigger();
		if (_bEntry)
		{
			if (trig != None)
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
			if (trig == None)
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

