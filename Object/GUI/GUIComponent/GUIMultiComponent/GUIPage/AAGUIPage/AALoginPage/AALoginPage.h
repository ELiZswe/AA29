// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "AALoginPage.generated.h"

class UBackgroundImage;
class UGUIBorder;
class UGUIImage;
class UGUIImageButton;
class UGUILabel;
class UGUIComponent;
class UGUIButton;

UCLASS(Config = Game)
class AA29_API UAALoginPage : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UAALoginPage();

	UPROPERTY(EditAnywhere)		UBackgroundImage*	i_Background;			//var() automated XInterface.BackgroundImage i_Background;
	UPROPERTY(EditAnywhere)		UGUIBorder*			h_PageHeader;			//var() automated XInterface.GUIBorder h_PageHeader;
	UPROPERTY(EditAnywhere)		UGUIImage*			i_PageBackground;		//var() automated XInterface.GUIImage i_PageBackground;
	UPROPERTY(EditAnywhere)		UGUIButton*			b_Quit;					//var() automated XInterface.GUIButton b_Quit;
	UPROPERTY(EditAnywhere)		UGUIImageButton*	ib_AALogo;				//var() automated GUIImageButton ib_AALogo;
	UPROPERTY(EditAnywhere)		UGUIImageButton*	ib_USArmyLogo;			//var() automated GUIImageButton ib_USArmyLogo;
	UPROPERTY(EditAnywhere)		UGUIImageButton*	ib_ESRBLogo;			//var() automated GUIImageButton ib_ESRBLogo;
	UPROPERTY(EditAnywhere)		UGUILabel*			l_Version;				//var() automated XInterface.GUILabel l_Version;
	UPROPERTY(EditAnywhere)		UGUILabel*			l_Disclaimer;			//var() automated XInterface.GUILabel l_Disclaimer;
	UPROPERTY(EditAnywhere)		UGUILabel*			l_Notice;				//var() automated XInterface.GUILabel l_Notice;
	UPROPERTY(EditAnywhere)		UGUIComponent*		selected;				//var UGUIComponent* selected;
	UPROPERTY()					bool				bAllowClose;			//var bool bAllowClose;
	UPROPERTY()					bool				bNewNews;				//var bool bNewNews;
	UPROPERTY()					float				FadeTime;				//var float FadeTime;
	UPROPERTY()					bool				FadeOut;				//var bool FadeOut;
	UPROPERTY()					FString				NewNewsMsg;				//var localized FString NewNewsMsg;
	UPROPERTY()					FString				LoginSuccessMsg;		//var localized FString LoginSuccessMsg;
	UPROPERTY()					FString				LoginFailureMsg;		//var localized FString LoginFailureMsg;
	UPROPERTY(EditAnywhere)		FString				PageCaption;			//var() localized FString PageCaption;
	UPROPERTY(config)			FColor				GreenColor;				//var config Color GreenColor;
	UPROPERTY(config)			FColor				RedColor;				//var config Color RedColor;
	UPROPERTY(config)			FColor				GoldColor;				//var config Color GoldColor;
	UPROPERTY(config)			FColor				BlueColor;				//var config Color BlueColor;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Reopened();
	void Opened(UGUIComponent* Sender);
	void InternalOnOpen();
	void OnClose(bool bCancelled);
	bool internalKeyEvent(uint8& Key, uint8& State, float Delta);
	bool CanClose(bool bCancelled);
	bool ButtonClick(UGUIComponent* Sender);
	bool NotifyLevelChange();
};
