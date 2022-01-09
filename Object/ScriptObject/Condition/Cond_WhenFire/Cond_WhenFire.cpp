// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenFire/Cond_WhenFire.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UCond_WhenFire::UCond_WhenFire()
{

}

void UCond_WhenFire::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UCond_WhenFire::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenFire::ConditionStart()");
	}
	if (_HumanController == nullptr)
	{
		if (_bDebug)
		{
			Log("ERROR Cond_WhenFire::ConditionStart() - _HumanController == nullptr");
		}
		return;
	}
	else
	{
		if (_HumanController.Pawn != nullptr)
		{
			AGP_Pawn(_HumanController.Pawn).SetCurrentFireMonitor(this);
		}
	}
	*/
}

void UCond_WhenFire::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenFire::ConditionFinish()");
	}
	if (_HumanController == nullptr)
	{
		if (_bDebug)
		{
			Log(" ERROR Cond_WhenFire::ConditionStart() - _HumanController == nullptr");
		}
		return;
	}
	else
	{
		if (_HumanController.Pawn != nullptr)
		{
			AGP_Pawn(_HumanController.Pawn).SetCurrentFireMonitor(None);
		}
	}
	*/
}

bool UCond_WhenFire::ProcessParams()
{
	//_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	return true;
}

