// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIControl.h"
#include "UITextDisplay.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUITextDisplay : public UUIControl
{
	GENERATED_BODY()
public:
	UUITextDisplay();


	UPROPERTY()										int32 _iFontIndex;				//var int _iFontIndex;
	UPROPERTY()										int32 _iColorIndex;				//var int _iColorIndex;
	UPROPERTY()										bool _bLabelChanged;			//var bool _bLabelChanged;
	UPROPERTY()										FString _sLabel;				//var string _sLabel;
	UPROPERTY()										int32 _iLabelY;					//var int _iLabelY;
	UPROPERTY()										int32 _iLabelX;					//var int _iLabelX;

	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void ScaleControl(UCanvas* Canvas);
	void SetLabel(FString Label);
	FString GetLabel();
	void SetColorIndex(int32 cindex);
	void SetFontIndex(int32 findex);

};
