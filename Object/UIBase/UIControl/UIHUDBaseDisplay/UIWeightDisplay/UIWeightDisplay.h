// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDBaseDisplay.h"
#include "UIWeightDisplay.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIWeightDisplay : public UUIHUDBaseDisplay
{
	GENERATED_BODY()
public:
	UUIWeightDisplay();

	void Draw(UCanvas* Canvas);
};
