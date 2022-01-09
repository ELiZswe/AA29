// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenPlayerTriggerChanges.generated.h"

class AHumanController;

UCLASS()
class UCond_WhenPlayerTriggerChanges : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenPlayerTriggerChanges();

	UPROPERTY()										bool bWasInTrigger;						//var bool bWasInTrigger;
	UPROPERTY()										bool _bEntry;							//var bool _bEntry;
	UPROPERTY()										FName _TriggerTag;						//var name _TriggerTag;
	UPROPERTY()										AHumanController* _HumanController;		//var AGP.HumanController _HumanController;

	void Destroyed();
	void ConditionStart();
	void ConditionFinish();
	bool ProcessParams();
	void update();
};
