// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UIListItems.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIListItems : public UUIControl
{
	GENERATED_BODY()
public:
	UUIListItems();

	int32 GetNumItems();
	void Draw(UCanvas* Canvas);
	void DrawItem(UCanvas* Canvas, int32 Position, int32 x_pos, int32 y_pos);
	int32 GetWidth(int32 Index);
	int32 GetHeight(int32 Index);
	void ScaleControl(UCanvas* Canvas);
};
