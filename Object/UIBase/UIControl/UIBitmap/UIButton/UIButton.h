// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIBitmap/UIBitmap.h"
#include "UIButton.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIButton : public UUIBitmap
{
	GENERATED_BODY()
public:
	UUIButton();

	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
};
