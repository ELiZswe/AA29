// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenWeaponJams/Cond_WhenWeaponJams.h"

UCond_WhenWeaponJams::UCond_WhenWeaponJams()
{

}

void UCond_WhenWeaponJams::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UCond_WhenWeaponJams::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenWeaponJams::ConditionStart()");
	}
	if ((_HumanController != None) && (_HumanController.Pawn != None))
	{
		AGP_Pawn(_HumanController.Pawn).SetJammedMonitor(Self);
	}
	*/
}

void UCond_WhenWeaponJams::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenWeaponJams::ConditionFinish()");
	}
	if ((_HumanController != None) && (_HumanController.Pawn != None))
	{
		AGP_Pawn(_HumanController.Pawn).SetJammedMonitor(None);
	}
	*/
}

bool UCond_WhenWeaponJams::ProcessParams()
{
	//_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	return true;
}

void UCond_WhenWeaponJams::update()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenWeaponJams::Update()");
	}
	if ((_HumanController != None) && (_HumanController.Pawn != None))
	{
		if (_bDebug)
		{
			Log("Cond_WhenPlayerOutOfAmmo::Update() calling Notify()");
		}
		AGP_Pawn(_HumanController.Pawn).SetJammedMonitor(None);
		Notify();
	}
	*/
}