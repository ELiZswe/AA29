// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_DisplayMissionResults/Dir_DisplayMissionResults.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"

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
	if (_HumanController != nullptr)
	{
		if (Cast<AAGP_HUD>(_HumanController.myHUD) != nullptr)
		{
			if (Cast<AAGP_HUD>(_HumanController.myHUD).mrFrame != nullptr)
			{
				Cast<AAGP_HUD>(_HumanController.myHUD).OpenMissionResults();
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
	//_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	return true;
}
