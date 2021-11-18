// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenSequenceManagerOutOfOrd.generated.h"

//class ASequenceManager;

UCLASS()
class AA29_API UCond_WhenSequenceManagerOutOfOrd : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenSequenceManagerOutOfOrd();

	//UPROPERTY()										ASequenceManager* _SequenceManager;					//var AGP_Gameplay.SequenceManager _SequenceManager;
};
