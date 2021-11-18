// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIScrollbar/UIScrollbar.h"
#include "UIScrollbarV.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIScrollbarV : public UUIScrollbar
{
	GENERATED_BODY()
public:
	UUIScrollbarV();

	UPROPERTY()										int32 _iSavedPos;							//var int _iSavedPos;

	void SizeThumb(float percentage);
	void ScaleControl(UCanvas* Canvas);
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
};
