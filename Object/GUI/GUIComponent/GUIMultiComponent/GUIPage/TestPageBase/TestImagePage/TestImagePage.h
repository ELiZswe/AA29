// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/TestPageBase/TestPageBase.h"
#include "TestImagePage.generated.h"

class UGUIImage;
class UmoComboBox;
class UGUINumericEdit;
class UGUIButton;
class UGUILabel;

UCLASS(Config = Game)
class AA29_API UTestImagePage : public UTestPageBase
{
	GENERATED_BODY()
public:
	UTestImagePage();

	UPROPERTY(EditAnywhere)			UGUIImage*			i_Test;					//var() automated GUIImage i_Test;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Style;				//var() automated moComboBox co_Style;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Align;				//var() automated moComboBox co_Align;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Select;				//var() automated moComboBox co_Select;
	UPROPERTY(EditAnywhere)			UmoComboBox*		co_Render;				//var() automated moComboBox co_Render;
	UPROPERTY(EditAnywhere)			UGUINumericEdit*	nu_Width;				//var() automated GUINumericEdit nu_Width;
	UPROPERTY(EditAnywhere)			UGUINumericEdit*	nu_Height;				//var() automated GUINumericEdit nu_Height;
	UPROPERTY(EditAnywhere)			UGUINumericEdit*	nu_PortionX1;			//var() automated GUINumericEdit nu_PortionX1;
	UPROPERTY(EditAnywhere)			UGUINumericEdit*	nu_PortionX2;			//var() automated GUINumericEdit nu_PortionX2;
	UPROPERTY(EditAnywhere)			UGUINumericEdit*	nu_PortionY1;			//var() automated GUINumericEdit nu_PortionY1;
	UPROPERTY(EditAnywhere)			UGUINumericEdit*	nu_PortionY2;			//var() automated GUINumericEdit nu_PortionY2;
	UPROPERTY(EditAnywhere)			UGUIButton*			b_Add;					//var() automated GUIButton b_Add;
	UPROPERTY(EditAnywhere)			UGUILabel*			l_ImageSize;			//var() automated GUILabel l_ImageSize;
	UPROPERTY(config)				TArray<FString>		Images;					//var config TArray<FString> Images;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	void InternalOnOpen();
	void InternalOnRendered(UCanvas* C);
	void OnNewImgStyle(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	void OnNewImgAlign(UGUIComponent* Sender);
	void OnNewImgSelect(UGUIComponent* Sender);
	void SetNewImage(FString ImageName);
	UMaterialInstance* LoadTexture(FString TextureFullName);
	void ResizeImage(UGUIComponent* Sender);
	void ChangePortion(UGUIComponent* Sender);
};
