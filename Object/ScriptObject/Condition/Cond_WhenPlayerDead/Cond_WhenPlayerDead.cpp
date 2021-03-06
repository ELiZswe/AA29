// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenPlayerDead/Cond_WhenPlayerDead.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

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
		Cast<AAGP_Pawn>(_HumanController.Pawn).SetDeathMonitor(this);
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
		Cast<AAGP_Pawn>(_HumanController.Pawn).SetDeathMonitor(nullptr);
	}
	*/
}

bool UCond_WhenPlayerDead::ProcessParams()
{
	//_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	return true;
}
