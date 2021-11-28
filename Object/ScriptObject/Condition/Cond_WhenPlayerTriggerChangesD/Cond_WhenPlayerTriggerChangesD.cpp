// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenPlayerTriggerChangesD/Cond_WhenPlayerTriggerChangesD.h"

UCond_WhenPlayerTriggerChangesD::UCond_WhenPlayerTriggerChangesD()
{
	_nNumParamsDefined = 2;
}

void UCond_WhenPlayerTriggerChangesD::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UCond_WhenPlayerTriggerChangesD::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPlayerTriggerChangesD::ConditionStart()");
	}
	if ((_HumanController != None) && (_HumanController.Pawn != None))
	{
		AGP_Pawn(_HumanController.Pawn).SetCurrentTriggerMonitor4(Self);
	}
	*/
}

void UCond_WhenPlayerTriggerChangesD::ConditionFinish()
{
	/*
	local ScriptObject soBlank;
	if (_bDebug)
	{
		Log("Cond_WhenPlayerTriggerChangesD::ConditionFinish()");
	}
	if ((_HumanController != None) && (_HumanController.Pawn != None))
	{
		AGP_Pawn(_HumanController.Pawn).SetCurrentTriggerMonitor4(soBlank);
	}
	*/
}

bool UCond_WhenPlayerTriggerChangesD::ProcessParams()
{
	/*
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_TriggerTag = string(GetParam(0));
	_bEntry = bool(GetParam(1));
	if (_TriggerTag == 'None')
	{
		if (_bDebug)
		{
			Log("Cond_WhenPlayerTriggerChangesD::ProcessParams() - could not get Trigger with tag " $ GetParam(0));
		}
		return false;
	}
	*/
	return true;
}

void UCond_WhenPlayerTriggerChangesD::update()
{
	/*
	local Actor trig;
	if (_bDebug)
	{
		Log("Cond_WhenPlayerTriggerChangesD::Update()");
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

