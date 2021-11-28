// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenTargetManagerComplete.generated.h"

class ATargetManager;

UCLASS()
class AA29_API UCond_WhenTargetManagerComplete : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenTargetManagerComplete();

	UPROPERTY()										ATargetManager* _TargetManager;					//var AGP_Gameplay.TargetManager _TargetManager;

	void Destroyed();
	void ConditionStart();
	void ConditionFinish();
	bool ProcessParams();

};
