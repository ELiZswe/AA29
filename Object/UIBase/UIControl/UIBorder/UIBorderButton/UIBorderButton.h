// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UIBorder/UIBorder.h"
#include "UIBorderButton.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIBorderButton : public UUIBorder
{
	GENERATED_BODY()
public:
	UUIBorderButton();

	UPROPERTY()						UMaterialInstance*	_Texture3;						//var Texture _Texture3;
	UPROPERTY()						FString				_sLabel;						//var FString _sLabel;
	UPROPERTY()						int32				_iLabelX;						//var int32 _iLabelX;
	UPROPERTY()						int32				_iLabelY;						//var int32 _iLabelY;
	UPROPERTY()						int32				_iState;						//var int32 _iState;

	void Destroyed();
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetTextureDimensions(FPosition dim);
	void ScaleControl(UCanvas* Canvas);
	void SetLabel(FString Label);
	void SetTexture3(UMaterialInstance* Tex);
};
