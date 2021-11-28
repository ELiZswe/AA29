// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_DisplayMissionResults/Dir_DisplayMissionResults.h"

UDir_DisplayMissionResults::UDir_DisplayMissionResults()
{

}

void UDir_DisplayMissionResults::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_DisplayMissionResults::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_DisplayMissionResults::DirectionStart()");
	}
	if (_HumanController != None)
	{
		if (AGP_HUD(_HumanController.myHUD) != None)
		{
			if (AGP_HUD(_HumanController.myHUD).mrFrame != None)
			{
				AGP_HUD(_HumanController.myHUD).OpenMissionResults();
				return;
			}
		}
	}
	if (_bDebug)
	{
		Log("Dir_DisplayMissionResults::DirectionStart() FAILED");
	}
	*/
}

bool UDir_DisplayMissionResults::ProcessParams()
{
	//_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	return true;
}
