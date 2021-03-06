// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenMissionResultsClosed/Cond_WhenMissionResultsClosed.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"

UCond_WhenMissionResultsClosed::UCond_WhenMissionResultsClosed()
{

}

void UCond_WhenMissionResultsClosed::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UCond_WhenMissionResultsClosed::ConditionStart()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenMissionResultsClosed::ConditionStart()");
	}
	if (_HumanController != nullptr)
	{
		if (Cast<AAGP_HUD>(_HumanController.myHUD) != nullptr)
		{
			Cast<AAGP_HUD>(_HumanController.myHUD).SetMissionResultTarget(this);
		}
	}
	*/
}

void UCond_WhenMissionResultsClosed::ConditionFinish()
{
	/*
	if (_bDebug)
	{
		Log("Cond_WhenMissionResultsClosed::ConditionFinish()");
	}
	if (_HumanController != nullptr)
	{
		if (Cast<AAGP_HUD>(_HumanController.myHUD) != nullptr)
		{
			Cast<AAGP_HUD>(_HumanController.myHUD).SetMissionResultTarget(nullptr);
		}
	}
	*/
}

bool UCond_WhenMissionResultsClosed::ProcessParams()
{
	//_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	return true;
}
