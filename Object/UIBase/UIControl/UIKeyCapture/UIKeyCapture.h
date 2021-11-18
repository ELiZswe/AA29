// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIKeyCapture.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIKeyCapture : public UUIControl
{
	GENERATED_BODY()
public:
	UUIKeyCapture();

	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);

};
