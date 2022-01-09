// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenTimerEnds.generated.h"

class AAGP_Timer;

UCLASS()
class UCond_WhenTimerEnds : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenTimerEnds();

	UPROPERTY()										FName TimerTag;						//var name TimerTag;
	UPROPERTY()										AAGP_Timer* _timer;					//var AGP_Gameplay.AGP_Timer _timer;

	void Destroyed();
	void ConditionStart();
	void ConditionFinish();
	bool ProcessParams();
};
