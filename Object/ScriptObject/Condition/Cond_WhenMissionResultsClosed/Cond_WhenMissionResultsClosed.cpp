// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenMissionResultsClosed/Cond_WhenMissionResultsClosed.h"

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
	if (_HumanController != None)
	{
		if (AGP_HUD(_HumanController.myHUD) != None)
		{
			AGP_HUD(_HumanController.myHUD).SetMissionResultTarget(Self);
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
	if (_HumanController != None)
	{
		if (AGP_HUD(_HumanController.myHUD) != None)
		{
			AGP_HUD(_HumanController.myHUD).SetMissionResultTarget(None);
		}
	}
	*/
}

bool UCond_WhenMissionResultsClosed::ProcessParams()
{
	//_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	return true;
}