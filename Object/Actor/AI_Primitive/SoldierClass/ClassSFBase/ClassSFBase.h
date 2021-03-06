// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/SoldierClass.h"
#include "ClassSFBase.generated.h"

UCLASS()
class AClassSFBase : public ASoldierClass
{
	GENERATED_BODY()
public:
	AClassSFBase();

	TSubclassOf<ASoldierClass> GetAlternateClass();
};
