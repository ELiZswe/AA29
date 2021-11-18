// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenPlayerTriggerChangesB.generated.h"

class AHumanController;

UCLASS()
class AA29_API UCond_WhenPlayerTriggerChangesB : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenPlayerTriggerChangesB();

	UPROPERTY()										bool bWasInTrigger;						//var bool bWasInTrigger;
	UPROPERTY()										bool _bEntry;							//var bool _bEntry;
	UPROPERTY()										FName _TriggerTag;						//var name _TriggerTag;
	UPROPERTY()										AHumanController* _HumanController;		//var AGP.HumanController _HumanController;
};
