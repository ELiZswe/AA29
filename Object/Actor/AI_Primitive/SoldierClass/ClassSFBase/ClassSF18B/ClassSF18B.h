// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassSFBase/ClassSFBase.h"
#include "ClassSF18B.generated.h"

UCLASS()
class AClassSF18B : public AClassSFBase
{
	GENERATED_BODY()
public:
	AClassSF18B();

	virtual void addClassInventory(bool bMaybeSkip) override;
};
