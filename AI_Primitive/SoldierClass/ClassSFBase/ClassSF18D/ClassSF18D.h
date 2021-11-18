// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/SoldierClass/ClassSFBase/ClassSFBase.h"
#include "ClassSF18D.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AClassSF18D : public AClassSFBase
{
	GENERATED_BODY()
public:
	AClassSF18D();

	virtual void addClassInventory(bool bMaybeSkip) override;
};
