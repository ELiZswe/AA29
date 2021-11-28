// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenPlayerTriggerChangesC/Cond_WhenPlayerTriggerChangesC.h"

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
	if ((_HumanController != None) && (_HumanController.Pawn != None))
	{
		AGP_Pawn(_HumanController.Pawn).SetCurrentTriggerMonitor3(Self);
	}
	*/
}

void UCond_WhenPlayerTriggerChangesC::ConditionFinish()
{
	/*
	local ScriptObject soBlank;
	if (_bDebug)
	{
		Log("Cond_WhenPlayerTriggerChangesC::ConditionFinish()");
	}
	if ((_HumanController != None) && (_HumanController.Pawn != None))
	{
		AGP_Pawn(_HumanController.Pawn).SetCurrentTriggerMonitor3(soBlank);
	}
	*/
}

bool UCond_WhenPlayerTriggerChangesC::ProcessParams()
{
	/*
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_TriggerTag = string(GetParam(0));
	_bEntry = bool(GetParam(1));
	if (_TriggerTag == 'None')
	{
		if (_bDebug)
		{
			Log("Cond_WhenPlayerTriggerChangesC::ProcessParams() - could not get Trigger with tag " $ GetParam(0));
		}
		return false;
	}
	*/
	return true;
}

void UCond_WhenPlayerTriggerChangesC::update()
{
	/*
	local Actor trig;
	if (_bDebug)
	{
		Log("Cond_WhenPlayerTriggerChangesC::Update()");
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
