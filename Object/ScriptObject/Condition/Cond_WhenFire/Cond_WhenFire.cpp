// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenFire/Cond_WhenFire.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

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
			Cast<AAGP_Pawn>(_HumanController.Pawn).SetCurrentFireMonitor(this);
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
			Cast<AAGP_Pawn>(_HumanController.Pawn).SetCurrentFireMonitor(nullptr);
		}
	}
	*/
}

bool UCond_WhenFire::ProcessParams()
{
	//_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	return true;
}

