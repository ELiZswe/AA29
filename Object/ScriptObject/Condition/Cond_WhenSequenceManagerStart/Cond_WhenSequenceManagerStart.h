// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenSequenceManagerStart.generated.h"

class ASequenceManager;

UCLASS()
class UCond_WhenSequenceManagerStart : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenSequenceManagerStart();

	UPROPERTY()										ASequenceManager* _SequenceManager;					//var AGP_Gameplay.SequenceManager _SequenceManager;

	void Destroyed();
	void ConditionStart();
	void ConditionFinish();
	bool ProcessParams();
};
