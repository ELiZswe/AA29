// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "AAMainMenu.generated.h"

class UGUIImage;
class UGUIVertTabControl;
class UGUIButton;
class UGUIImageButton;
class UGUILabel;

UCLASS()
class AA29_API UAAMainMenu : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UAAMainMenu();

	UPROPERTY()					float					SavedPitch;				//var float SavedPitch;
	UPROPERTY()					bool					bAllowClose;			//var bool bAllowClose;
	UPROPERTY(EditAnywhere)		UGUIImage*				i_Background;			//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)		UGUIImage*				i_TabBackground;		//var() automated XInterface.GUIImage i_TabBackground;
	UPROPERTY(EditAnywhere)		UGUIVertTabControl*		c_Tab;					//var() automated GUIVertTabControl c_Tab;
	UPROPERTY(EditAnywhere)		UGUIButton*				b_Quit;					//var() automated XInterface.GUIButton b_Quit;
	UPROPERTY(EditAnywhere)		UGUIImageButton*		ib_AALogo;				//var() automated GUIImageButton ib_AALogo;
	UPROPERTY(EditAnywhere)		UGUIImageButton*		ib_USArmyLogo;			//var() automated GUIImageButton ib_USArmyLogo;
	UPROPERTY(EditAnywhere)		UGUILabel*				l_Version;				//var() automated XInterface.GUILabel l_Version;
	UPROPERTY()					TArray<FString>			PanelClasses;			//var FString PanelClasses[9];
	UPROPERTY()					TArray<FString>			PanelCaptions;			//var localized FString PanelCaptions[9];
	UPROPERTY()					TArray<FString>			PanelHints;				//var localized FString PanelHints[9];

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Opened(UGUIComponent* Sender);
	void HandleParameters(FString Param1, FString Param2);
	void OnClose(bool bCanceled);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	bool InternalOnCanClose(bool bCanceled);
	bool ButtonClick(UGUIComponent* Sender);
	bool NotifyLevelChange();

};
