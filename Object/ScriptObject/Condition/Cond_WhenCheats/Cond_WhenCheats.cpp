// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Condition/Cond_WhenCheats/Cond_WhenCheats.h"
#include "AA29/Controller/PlayerController/HumanController/HumanController.h"

UCond_WhenCheats::UCond_WhenCheats()
{

}

void UCond_WhenCheats::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}
void UCond_WhenCheats::ConditionStart()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Cond_WhenFire::ConditionStart()"));
	}
	if (_HumanController == nullptr)
	{
		if (_bDebug)
		{
			UE_LOG(LogTemp, Log, TEXT("ERROR Cond_WhenCheats::ConditionStart() - _HumanController == None"));
		}
		return;
	}
	else
	{
		_HumanController->SetCheatMonitor(this);
	}
}

void UCond_WhenCheats::ConditionFinish()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Cond_WhenFire::ConditionFinish()"));
	}
	if (_HumanController == nullptr)
	{
		if (_bDebug)
		{
			UE_LOG(LogTemp, Log, TEXT("RROR Cond_WhenFire::ConditionStart() - _HumanController == None"));
		}
		return;
	}
	else
	{
		_HumanController->SetCheatMonitor(nullptr);
	}
}

bool UCond_WhenCheats::ProcessParams()
{
	//_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	return true;
}
