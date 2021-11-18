// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenAGPObjectiveComplete.generated.h"

class AAGP_Objective;

UCLASS()
class AA29_API UCond_WhenAGPObjectiveComplete : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenAGPObjectiveComplete();

	UPROPERTY()										AAGP_Objective* _Objective;					//var AGP.AGP_Objective _Objective;

	void Destroyed();
	void ConditionStart();
	void ConditionFinish();
	bool ProcessParams();

};
