// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UISliderH.generated.h"

UCLASS()
class UUISliderH : public UUINavControl
{
	GENERATED_BODY()
public:
	UUISliderH();

	UPROPERTY()										int32 _iSliderSize;						//var int _iSliderSize;
	UPROPERTY()										float _fMax;							//var float _fMax;
	UPROPERTY()										float _fMin;							//var float _fMin;
	UPROPERTY()										float _fValue;							//var float _fValue;
	UPROPERTY()										int32 _iState;							//var int _iState;
	UPROPERTY()										int32 _iMouseDragOffset;				//var int _iMouseDragOffset;
	UPROPERTY()										FString _sLabel;						//var string _sLabel;
	UPROPERTY()										FPosition _TexDimThumb;					//var UIBase.Position _TexDimThumb;
	UPROPERTY()										FPosition _TexDimBack;					//var UIBase.Position _TexDimBack;
	UPROPERTY()										UMaterialInstance* _Texture;			//var Texture _Texture;
	UPROPERTY()										int32 _iThumbSize;						//var int _iThumbSize;
	UPROPERTY()										int32 _iThumbPos;						//var int _iThumbPos;
	UPROPERTY()										FPosition _ScaledThumbPos;				//var UIBase.Position _ScaledThumbPos;
	UPROPERTY()										FPosition _ThumbPos;					//var UIBase.Position _ThumbPos;


	void Destroyed();
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetTexture(FString Tex);
	void SetTexDimBack(FPosition dim);
	void SetTexDimThumb(FPosition dim);
	void SetLabel(FString Label);
	void Inc();
	void Dec();
	void Refresh();
	void Accept();
	void UpdateValue();
	void SetValue(float Value);
	void SetMinMax(float Min, float Max);
};
