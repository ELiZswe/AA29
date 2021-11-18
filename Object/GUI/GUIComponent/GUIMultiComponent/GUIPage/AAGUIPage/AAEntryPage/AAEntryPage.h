// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "AAEntryPage.generated.h"

class UBackgroundImage;
class UGUIButton;
class UGUIImageButton;
class UGUILabel;
class UGUIComponent;

UCLASS(Config = Game)
class AA29_API UAAEntryPage : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UAAEntryPage();

	UPROPERTY(EditAnywhere)			UBackgroundImage*			i_Background;			//var() automated XInterface.BackgroundImage i_Background;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_PersonnelJacket;		//var() automated XInterface.GUIButton b_PersonnelJacket;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_Training;				//var() automated XInterface.GUIButton b_Training;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_Deployment;			//var() automated XInterface.GUIButton b_Deployment;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_Settings;				//var() automated XInterface.GUIButton b_Settings;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_Support;				//var() automated XInterface.GUIButton b_Support;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_ParentalControl;		//var() automated XInterface.GUIButton b_ParentalControl;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_Credits;				//var() automated XInterface.GUIButton b_Credits;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_Quit;					//var() automated XInterface.GUIButton b_Quit;
	UPROPERTY(EditAnywhere)			UGUIImageButton*			ib_AALogo;				//var() automated GUIImageButton ib_AALogo;
	UPROPERTY(EditAnywhere)			UGUIImageButton*			ib_USArmyLogo;			//var() automated GUIImageButton ib_USArmyLogo;
	UPROPERTY(EditAnywhere)			UGUIImageButton*			ib_ESRBLogo;			//var() automated GUIImageButton ib_ESRBLogo;
	UPROPERTY(EditAnywhere)			UGUILabel*					l_Version;				//var() automated XInterface.GUILabel l_Version;
	UPROPERTY(EditAnywhere)			UGUILabel*					l_Disclaimer;			//var() automated XInterface.GUILabel l_Disclaimer;
	UPROPERTY(EditAnywhere)			UGUILabel*					l_Notice;				//var() automated XInterface.GUILabel l_Notice;
	UPROPERTY()						UGUIComponent*				selected;				//var UGUIComponent* selected;
	UPROPERTY()						bool						bAllowClose;			//var bool bAllowClose;
	UPROPERTY(EditAnywhere, config)	FString						MenuSong;				//var() config FString MenuSong;
	UPROPERTY()						bool						bNewNews;				//var bool bNewNews;
	UPROPERTY()						float						FadeTime;				//var float FadeTime;
	UPROPERTY()						bool						FadeOut;				//var bool FadeOut;
	UPROPERTY()						FString						NewNewsMsg;				//var localized FString NewNewsMsg;

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
