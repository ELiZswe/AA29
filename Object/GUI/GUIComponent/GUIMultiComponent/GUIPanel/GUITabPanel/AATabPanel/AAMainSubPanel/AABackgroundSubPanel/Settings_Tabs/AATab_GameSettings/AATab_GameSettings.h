// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/Settings_Tabs/Settings_Tabs.h"
#include "AATab_GameSettings.generated.h"

class UmoCheckBox;
class UmoComboBox;
class UmoEditBox;
class UGUIComponent;
class UGUILabel;
class UGUIButton;

UCLASS()
class AA29_API UAATab_GameSettings : public USettings_Tabs
{
	GENERATED_BODY()
public:
	UAATab_GameSettings();

	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_WeaponBob;						//var() automated XInterface.moCheckBox ch_WeaponBob;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_AutoSwitch;						//var() automated XInterface.moCheckBox ch_AutoSwitch;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_Speech;							//var() automated XInterface.moCheckBox ch_Speech;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_LeanToggle;						//var() automated XInterface.moCheckBox ch_LeanToggle;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_WalkZoom;						//var() automated XInterface.moCheckBox ch_WalkZoom;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_AutoAim;							//var() automated XInterface.moCheckBox ch_AutoAim;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_LandShake;						//var() automated XInterface.moCheckBox ch_LandShake;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_DisableServerColorsInBrowser;	//var() automated XInterface.moCheckBox ch_DisableServerColorsInBrowser;
	UPROPERTY(EditAnywhere)			UmoComboBox*	co_BrowserSwitcher;					//var() automated XInterface.moComboBox co_BrowserSwitcher;
	UPROPERTY(EditAnywhere)			FString			sBrowser;							//var FString sBrowser;
	UPROPERTY(EditAnywhere)			UGUIComponent*	LastGameOption;						//var XInterface.GUIComponent LastGameOption;
	UPROPERTY(EditAnywhere)			bool			bAuto;								//var bool bAuto;
	UPROPERTY(EditAnywhere)			bool			bLeanToggle;						//var bool bLeanToggle;
	UPROPERTY(EditAnywhere)			bool			bWalkZoom;							//var bool bWalkZoom;
	UPROPERTY(EditAnywhere)			bool			bBob;								//var bool bBob;
	UPROPERTY(EditAnywhere)			bool			bAim;								//var bool bAim;
	UPROPERTY(EditAnywhere)			bool			bLandShake;							//var bool bLandShake;
	UPROPERTY(EditAnywhere)			bool			bLandShakeD;						//var bool bLandShakeD;
	UPROPERTY(EditAnywhere)			bool			bSpeechRec;							//var bool bSpeechRec;
	UPROPERTY(EditAnywhere)			int32			iGore;								//var int32 iGore;
	UPROPERTY(EditAnywhere)			TArray<FString>	NetSpeedText;						//var localized FString NetSpeedText[4];
	UPROPERTY(EditAnywhere)			FString			StatsURL;							//var localized FString StatsURL;
	UPROPERTY(EditAnywhere)			FString			IDMsg;								//var localized FString IDMsg;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_Warning;							//var() automated XInterface.GUILabel l_Warning;
	UPROPERTY(EditAnywhere)			UGUILabel*		l_ID;								//var() automated XInterface.GUILabel l_ID;
	UPROPERTY(EditAnywhere)			UGUIButton*		b_Stats;							//var() automated XInterface.GUIButton b_Stats;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_TrackStats;						//var() automated XInterface.moCheckBox ch_TrackStats;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_DynNetspeed;						//var() automated XInterface.moCheckBox ch_DynNetspeed;
	UPROPERTY(EditAnywhere)			UmoCheckBox*	ch_Precache;						//var() automated XInterface.moCheckBox ch_Precache;
	UPROPERTY(EditAnywhere)			UmoComboBox*	co_Netspeed;						//var() automated XInterface.moComboBox co_Netspeed;
	UPROPERTY(EditAnywhere)			UmoEditBox*		ed_Name;							//var() automated XInterface.moEditBox ed_Name;
	UPROPERTY(EditAnywhere)			UmoEditBox*		ed_Password;						//var() automated XInterface.moEditBox ed_Password;
	UPROPERTY(EditAnywhere)			int32			iNetspeed;							//var int32 iNetspeed;
	UPROPERTY(EditAnywhere)			int32			iNetSpeedD;							//var int32 iNetSpeedD;
	UPROPERTY(EditAnywhere)			FString			sPassword;							//var FString sPassword;
	UPROPERTY(EditAnywhere)			FString			sName;								//var FString sName;
	UPROPERTY(EditAnywhere)			bool			bStats;								//var bool bStats;
	UPROPERTY(EditAnywhere)			bool			bDynNet;							//var bool bDynNet;
	UPROPERTY(EditAnywhere)			bool			bPrecache;							//var bool bPrecache;
	UPROPERTY(EditAnywhere)			bool			bDisableServerColorsInBrowser;		//var bool bDisableServerColorsInBrowser;
	UPROPERTY(EditAnywhere)			bool			bDisableAutoServerlistRetrieval;	//var bool bDisableAutoServerlistRetrieval;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	FString FormatID(FString Id);
	void ShowPanel(bool bShow);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void SaveSettings();
	void ResetClicked();
	void InternalOnChange(UGUIComponent* Sender);
	bool ValidStatConfig();
	bool OnViewStats(UGUIComponent* Sender);
	void SwitchBrowserConfirm(bool bCancelled);
	void UpdateStatsItems();
};
