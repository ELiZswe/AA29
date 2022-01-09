// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenPlayerDead/Cond_WhenPlayerDead.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UCond_WhenPlayerDead::UCond_WhenPlayerDead()
{

}

void UCond_WhenPlayerDead::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UCond_WhenPlayerDead::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPlayerDead::ConditionStart()");
	}
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		AGP_Pawn(_HumanController.Pawn).SetDeathMonitor(this);
	}
	*/
}

void UCond_WhenPlayerDead::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenPlayerDead::ConditionFinish()");
	}
	if ((_HumanController != nullptr) && (_HumanController.Pawn != nullptr))
	{
		AGP_Pawn(_HumanController.Pawn).SetDeathMonitor(None);
	}
	*/
}

bool UCond_WhenPlayerDead::ProcessParams()
{
	//_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	return true;
}
