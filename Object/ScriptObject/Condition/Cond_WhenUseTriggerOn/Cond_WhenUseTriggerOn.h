// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenUseTriggerOn.generated.h"

class AAGP_UseTrigger;

UCLASS()
class AA29_API UCond_WhenUseTriggerOn : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenUseTriggerOn();

	UPROPERTY()										bool bSwitched;						//var bool bSwitched;
	UPROPERTY()										AAGP_UseTrigger* UseTrigger;		//var AGP.AGP_UseTrigger UseTrigger;

	void Destroyed();
	void ConditionStart();
	void ConditionFinish();
	bool ProcessParams();
};
