// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/SoldierClass/SoldierClass.h"
#include "ClassSFBase.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AClassSFBase : public ASoldierClass
{
	GENERATED_BODY()
public:
	AClassSFBase();

	virtual UClass* GetAlternateClass() override;
};
