// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIScrollbar/UIScrollbar.h"
#include "UIScrollbarH.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIScrollbarH : public UUIScrollbar
{
	GENERATED_BODY()
public:
	UUIScrollbarH();


	void SizeThumb(float percentage);
	void ScaleControl(UCanvas* Canvas);
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
};
