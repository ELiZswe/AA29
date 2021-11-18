// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UITextButton.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUITextButton : public UUINavControl
{
	GENERATED_BODY()
public:
	UUITextButton();


	UPROPERTY()										bool _bLabelChanged;			//var bool _bLabelChanged;
	UPROPERTY()										bool _bFirstOver;				//var bool _bFirstOver;
	UPROPERTY()										int32 _iState;					//var int _iState;
	UPROPERTY()										int32 _iLabelY;					//var int _iLabelY;
	UPROPERTY()										int32 _iLabelX;					//var int _iLabelX;
	UPROPERTY()										FString _sLabel;				//var string _sLabel;

	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void ScaleControl(UCanvas* Canvas);
	void SetLabel(FString Label);
};
