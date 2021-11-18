// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UISlider.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUISlider : public UUINavControl
{
	GENERATED_BODY()
public:
	UUISlider();

	UPROPERTY()										int32 lastint;						//var int lastint;
	UPROPERTY()										FString lastmod;					//var string lastmod;
	UPROPERTY()										float _fMax;						//var float _fMax;
	UPROPERTY()										float _fMin;						//var float _fMin;
	UPROPERTY()										float _fValue;						//var float _fValue;
	UPROPERTY()										int32 _iState;						//var int _iState;
	UPROPERTY()										int32 _iMouseDragOffset;			//var int _iMouseDragOffset;
	UPROPERTY()										FString _sPropertyName;				//var string _sPropertyName;
	UPROPERTY()										FString _sClassName;				//var string _sClassName;
	UPROPERTY()										FString _sLabel;					//var string _sLabel;
	UPROPERTY()										FPosition _TexDimThumb;				//var UIBase.Position _TexDimThumb;
	UPROPERTY()										FPosition _TexDimBack;				//var UIBase.Position _TexDimBack;
	UPROPERTY()										UMaterialInstance* _Texture;		//var Texture _Texture;
	UPROPERTY()										int32 _iThumbSize;					//var int _iThumbSize;
	UPROPERTY()										int32 _iThumbPos;					//var int _iThumbPos;
	UPROPERTY()										FPosition _ScaledThumbPos;			//var UIBase.Position _ScaledThumbPos;
	UPROPERTY()										FPosition _ThumbPos;				//var UIBase.Position _ThumbPos;

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
	void SetClassName(FString ClassName);
	void SetPropertyName(FString PropName);
	void Refresh();
	void Accept();
	void GetMod();
	void SetMod(FString mod);
	void SetModValue(FString mod, FString s1, FString s2);
	void UpdateValue();
	void SetValue(float Value);
	void SetMinMax(float Min, float Max);
	
};
