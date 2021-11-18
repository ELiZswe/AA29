// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/TestPageBase/TestPageBase.h"
#include "TestGFXButtonPage.generated.h"

class UGUIComboBox;
class UGUIGFXButton;

UCLASS()
class AA29_API UTestGFXButtonPage : public UTestPageBase
{
	GENERATED_BODY()
public:
	UTestGFXButtonPage();

	UPROPERTY()						UGUIGFXButton* Btn;					//var GUIGFXButton Btn;
	UPROPERTY()						UGUIComboBox* ImgStyle;				//var GUIComboBox ImgStyle;
	UPROPERTY()						UGUIComboBox* ImgAlign;				//var GUIComboBox ImgAlign;
	UPROPERTY()						UGUIComboBox* ImgSelect;			//var GUIComboBox ImgSelect;

	void MyOnOpen();
	void OnNewImgStyle(UGUIComponent* Sender);
	void OnNewImgAlign(UGUIComponent* Sender);
	void OnNewImgSelect(UGUIComponent* Sender);
	void OnNewClientBound(UGUIComponent* Sender);
	void SetNewImage(FString ImageName);
	UMaterialInstance* DLOTexture(FString TextureFullName);
};
