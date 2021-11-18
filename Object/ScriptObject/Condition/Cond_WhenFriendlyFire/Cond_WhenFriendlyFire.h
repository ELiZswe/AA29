// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenFriendlyFire.generated.h"

class AHumanController;

UCLASS()
class AA29_API UCond_WhenFriendlyFire : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenFriendlyFire();

	UPROPERTY()										AHumanController* _HumanController;					//var AGP.HumanController _HumanController;
};
