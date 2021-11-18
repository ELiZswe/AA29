// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UIClassButton.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUIClassButton : public UUINavControl
{
	GENERATED_BODY()
public:
	UUIClassButton();

	UPROPERTY()										uint8 _yUseAltClass;						//var byte _yUseAltClass;
	UPROPERTY()										bool _bQualified;							//var bool _bQualified;
	UPROPERTY()										bool _bSelected;							//var bool _bSelected;
	UPROPERTY()										int32 _iClassIndex;							//var int _iClassIndex;
	UPROPERTY()										FString _sLabel;							//var string _sLabel;
	UPROPERTY()										bool _bFirstOver;							//var bool _bFirstOver;
	UPROPERTY()										FString _sInfo;								//var string _sInfo;
	UPROPERTY()										int32 _iState;								//var int _iState;
	UPROPERTY()										FPosition _iTexDim;							//var UIBase.Position _iTexDim;
	UPROPERTY()										UMaterialInstance* _tSelect;				//var Texture _tSelect;
	UPROPERTY()										UMaterialInstance* _tOverlay;				//var Texture _tOverlay;
	UPROPERTY()										UMaterialInstance* _tNotQual;				//var Texture _tNotQual;
	UPROPERTY()										UMaterialInstance* _tNotAvail;				//var Texture _tNotAvail;
	UPROPERTY()										UMaterialInstance* _tAltClass3;				//var Texture _tAltClass3;
	UPROPERTY()										UMaterialInstance* _tAltClass2;				//var Texture _tAltClass2;
	UPROPERTY()										UMaterialInstance* _tAltClass1;				//var Texture _tAltClass1;
	UPROPERTY()										UMaterialInstance* _tClass;					//var Texture _tClass;


	void Destroyed();
	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void SetTextureDimensions(FPosition dim);
	void SetClassTexture(FString Tex);
	void SetAltClass1Texture(FString Tex);
	void SetAltClass2Texture(FString Tex);
	void SetAltClass3Texture(FString Tex);
	void SetOverlayTexture(FString Tex);
	void SetNotAvailTexture(FString Tex);
	void SetNotQualTexture(FString Tex);
	void SetSelectTexture(FString Tex);
	UMaterialInstance* GetClassTexture();
	UMaterialInstance* GetOverlayTexture();
	void SetLabel(FString Label);
	void SetClassIndex(int32 Index);
	int32 GetClassIndex();
	void SetUseAltClass(uint8 alt);
	void SetSelected(bool Select);
	void SetQualified(bool qual);
	bool IsQualified();
	bool IsActive();
	bool IsSelected();

};
