// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenWeaponJams/Cond_WhenWeaponJams.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

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
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		Cast<AAGP_Pawn>(_HumanController.Pawn).SetJammedMonitor(this);
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
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		Cast<AAGP_Pawn>(_HumanController.Pawn).SetJammedMonitor(nullptr);
	}
	*/
}

bool UCond_WhenWeaponJams::ProcessParams()
{
	//_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	return true;
}

void UCond_WhenWeaponJams::update()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenWeaponJams::Update()");
	}
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		if (_bDebug)
		{
			Log("Cond_WhenPlayerOutOfAmmo::Update() calling Notify()");
		}
		Cast<AAGP_Pawn>(_HumanController.Pawn).SetJammedMonitor(nullptr);
		Notify();
	}
	*/
}
