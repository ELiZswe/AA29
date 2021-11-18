// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenPlayerOutOfAmmo.generated.h"

class AHumanController;

UCLASS()
class AA29_API UCond_WhenPlayerOutOfAmmo : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenPlayerOutOfAmmo();

	UPROPERTY()										AHumanController* _HumanController;		//var AGP.HumanController _HumanController;
	UPROPERTY()										bool _bWeaponOnly;						//var bool _bWeaponOnly;
};
