// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Condition/Cond_WhenAGPObjectiveComplete/Cond_WhenAGPObjectiveComplete.h"
#include "AA29/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"

UCond_WhenAGPObjectiveComplete::UCond_WhenAGPObjectiveComplete()
{
	_nNumParamsDefined = 1;
}

void UCond_WhenAGPObjectiveComplete::Destroyed()
{
	Super::Destroyed();
	_Objective = nullptr;
}
void UCond_WhenAGPObjectiveComplete::ConditionStart()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Cond_WhenAGPObjectiveComplete::ConditionStart()"));
	}
	//_Objective->SetTarget(this);
}
void UCond_WhenAGPObjectiveComplete::ConditionFinish()
{
	if (_bDebug)
	{
		UE_LOG(LogTemp, Log, TEXT("Cond_WhenAGPObjectiveComplete::ConditionFinish()"));
	}
	_Objective->SetTarget(nullptr);
}
bool UCond_WhenAGPObjectiveComplete::ProcessParams()
{
	//_Objective = AGP_Objective(_ParentScreenplay.GetActorByTag(GetParam(0)));
	if (_Objective == nullptr)
	{
		if (_bDebug)
		{
			UE_LOG(LogTemp, Log, TEXT("Cond_WhenAGPObjectiveComplete::ProcessParams() - could not find Objective with tag %s"), *GetParam(0));
		}
		return false;
	}
	return true;
}
