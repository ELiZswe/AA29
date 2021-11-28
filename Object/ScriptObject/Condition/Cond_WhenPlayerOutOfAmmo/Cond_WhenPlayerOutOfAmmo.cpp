// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenPlayerOutOfAmmo/Cond_WhenPlayerOutOfAmmo.h"

UCond_WhenPlayerOutOfAmmo::UCond_WhenPlayerOutOfAmmo()
{
	_nNumParamsDefined = 1;
}

void UCond_WhenPlayerOutOfAmmo::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UCond_WhenPlayerOutOfAmmo::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPlayerOutOfAmmo::ConditionStart()");
	}
	if ((_HumanController != None) && (_HumanController.Pawn != None))
	{
		AGP_Pawn(_HumanController.Pawn).SetAmmoMonitor(Self, _bWeaponOnly);
	}
	*/
}

void UCond_WhenPlayerOutOfAmmo::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPlayerOutOfAmmo::ConditionFinish()");
	}
	if ((_HumanController != None) && (_HumanController.Pawn != None))
	{
		AGP_Pawn(_HumanController.Pawn).SetAmmoMonitor(None, _bWeaponOnly);
	}
	*/
}

bool UCond_WhenPlayerOutOfAmmo::ProcessParams()
{
	/*
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_bWeaponOnly = bool(GetParam(0));
	*/
	return true;
}

void UCond_WhenPlayerOutOfAmmo::update()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPlayerOutOfAmmo::Update()");
	}
	if ((_HumanController != None) && (_HumanController.Pawn != None))
	{
		if (AGP_Pawn(_HumanController.Pawn).IsOutOfAmmo(_bWeaponOnly))
		{
			if (_bDebug)
			{
				Log("Cond_WhenPlayerOutOfAmmo::Update() calling Notify()");
			}
			AGP_Pawn(_HumanController.Pawn).SetAmmoMonitor(None, _bWeaponOnly);
			Notify();
		}
	}
	*/
}
