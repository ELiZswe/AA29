// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenPlayerOutOfAmmo/Cond_WhenPlayerOutOfAmmo.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

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
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		Cast<AAGP_Pawn>(_HumanController.Pawn).SetAmmoMonitor(this, _bWeaponOnly);
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
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		Cast<AAGP_Pawn>(_HumanController.Pawn).SetAmmoMonitor(None, _bWeaponOnly);
	}
	*/
}

bool UCond_WhenPlayerOutOfAmmo::ProcessParams()
{
	/*
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
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
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		if (Cast<AAGP_Pawn>(_HumanController.Pawn).IsOutOfAmmo(_bWeaponOnly))
		{
			if (_bDebug)
			{
				Log("Cond_WhenPlayerOutOfAmmo::Update() calling Notify()");
			}
			Cast<AAGP_Pawn>(_HumanController.Pawn).SetAmmoMonitor(None, _bWeaponOnly);
			Notify();
		}
	}
	*/
}
