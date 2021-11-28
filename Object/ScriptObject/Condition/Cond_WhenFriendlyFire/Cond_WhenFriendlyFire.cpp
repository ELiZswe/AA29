// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenFriendlyFire/Cond_WhenFriendlyFire.h"

UCond_WhenFriendlyFire::UCond_WhenFriendlyFire()
{

}

void UCond_WhenFriendlyFire::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UCond_WhenFriendlyFire::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenFriendlyFire::ConditionStart()");
	}
	if (_HumanController == None)
	{
		if (_bDebug)
		{
			Log("ERROR Cond_WhenFriendlyFire::ConditionStart() - _HumanController == None");
		}
		return;
	}
	else
	{
		if (_HumanController.Pawn != None)
		{
			AGP_Pawn(_HumanController.Pawn).SetCurrentFFMonitor(Self);
		}
	}
	*/
}

void UCond_WhenFriendlyFire::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenFriendlyFire::ConditionFinish()");
	}
	if (_HumanController == None)
	{
		if (_bDebug)
		{
			Log("ERROR Cond_WhenFriendlyFire::ConditionStart() - _HumanController == None");
		}
		return;
	}
	else
	{
		if (_HumanController.Pawn != None)
		{
			AGP_Pawn(_HumanController.Pawn).SetCurrentFFMonitor(None);
		}
	}
	*/
}

bool UCond_WhenFriendlyFire::ProcessParams()
{
	//_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	return true;
}

