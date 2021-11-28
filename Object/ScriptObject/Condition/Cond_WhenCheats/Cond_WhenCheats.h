// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenCheats.generated.h"

class AHumanController;

UCLASS()
class AA29_API UCond_WhenCheats : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenCheats();

	UPROPERTY()										AHumanController* _HumanController;					//var AGP.HumanController _HumanController;

	void Destroyed();
	void ConditionStart();
	void ConditionFinish();
	bool ProcessParams();
};
