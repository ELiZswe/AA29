// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIHUDBaseDisplay.generated.h"

UCLASS()
class UUIHUDBaseDisplay : public UUIControl
{
	GENERATED_BODY()
public:
	UUIHUDBaseDisplay();

	void Draw(UCanvas* Canvas);
};
