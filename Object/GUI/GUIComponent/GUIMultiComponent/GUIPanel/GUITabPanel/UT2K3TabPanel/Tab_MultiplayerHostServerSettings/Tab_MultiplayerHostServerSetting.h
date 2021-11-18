// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_MultiplayerHostServerSetting.generated.h"

class UmoCheckBox;
class UmoEditBox;
class UmoNumericEdit;

/**
 * 
 */
UCLASS(Config = Game)
class AA29_API UTab_MultiplayerHostServerSetting : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_MultiplayerHostServerSetting();

	UPROPERTY(config)			bool				bDedicated;				//var config bool bDedicated;
	UPROPERTY(config)			bool				bLanPlay;				//var config bool bLanPlay;
	UPROPERTY(config)			int32				BotSkill;				//var config int32 BotSkill;
	UPROPERTY(config)			bool				bPlayersMustBeReady;	//var config bool bPlayersMustBeReady;
	UPROPERTY(config)			bool				bUseDefaults;			//var config bool bUseDefaults;
	UPROPERTY(config)			bool				bUseCustomBots;			//var config bool bUseCustomBots;
	UPROPERTY(config)			int32				MinPlayers;				//var config int32 MinPlayers;
	UPROPERTY(config)			int32				MaxPlayers;				//var config int32 MaxPlayers;
	UPROPERTY(config)			int32				MaxSpecs;				//var config int32 MaxSpecs;
	UPROPERTY(config)			bool				bAllowBehindView;		//var config bool bAllowBehindView;
	UPROPERTY(config)			FString				AdminName;				//var config FString AdminName;
	UPROPERTY(config)			FString				AdminPass;				//var config FString AdminPass;
	UPROPERTY(config)			FString				GamePass;				//var config FString GamePass;
	UPROPERTY(config)			bool				bBalanceTeams;			//var config bool bBalanceTeams;
	UPROPERTY(config)			bool				bCollectStats;			//var config bool bCollectStats;
	UPROPERTY()					UmoCheckBox*		MyDedicated;			//var moCheckBox MyDedicated;
	UPROPERTY()					UmoCheckBox*		MyLanGame;				//var moCheckBox MyLanGame;
	UPROPERTY()					UmoCheckBox*		MyAdvertise;			//var moCheckBox MyAdvertise;
	UPROPERTY()					UmoCheckBox*		MyCollectStats;			//var moCheckBox MyCollectStats;
	UPROPERTY()					UmoCheckBox*		MyBalanceTeams;			//var moCheckBox MyBalanceTeams;
	UPROPERTY()					UmoCheckBox*		MyPlayersMustBeReady;	//var moCheckBox MyPlayersMustBeReady;
	UPROPERTY()					UmoCheckBox*		MyAllowBehindView;		//var moCheckBox MyAllowBehindView;
	UPROPERTY()					UmoCheckBox*		MyBotSkill;				//var moComboBox MyBotSkill;
	UPROPERTY()					UmoCheckBox*		MyUseDefaultBots;		//var moCheckBox MyUseDefaultBots;
	UPROPERTY()					UmoCheckBox*		MyUseCustomBots;		//var moCheckBox MyUseCustomBots;
	UPROPERTY()					UmoNumericEdit*		MyMinPlayers;			//var moNumericEdit MyMinPlayers;
	UPROPERTY()					UmoNumericEdit*		MyMaxPlayers;			//var moNumericEdit MyMaxPlayers;
	UPROPERTY()					UmoNumericEdit*		MyMaxSpecs;				//var moNumericEdit MyMaxSpecs;
	UPROPERTY()					UmoEditBox*			MyServerName;			//var moEditBox MyServerName;
	UPROPERTY()					UmoEditBox*			MyServerPasswrd;		//var moEditBox MyServerPasswrd;
	UPROPERTY()					UmoEditBox*			MyAdminName;			//var moEditBox MyAdminName;
	UPROPERTY()					UmoEditBox*			MyAdminEmail;			//var moEditBox MyAdminEmail;
	UPROPERTY()					UmoEditBox*			MyAdminPasswrd;			//var moEditBox MyAdminPasswrd;
	UPROPERTY()					UmoEditBox*			MyMOTD1;				//var moEditBox MyMOTD1;
	UPROPERTY()					UmoEditBox*			MyMOTD2;				//var moEditBox MyMOTD2;
	UPROPERTY()					UmoEditBox*			MyMOTD3;				//var moEditBox MyMOTD3;
	UPROPERTY()					UmoEditBox*			MyMOTD4;				//var moEditBox MyMOTD4;
	UPROPERTY()					UmoCheckBox*		MyUseWebAdmin;			//var moCheckBox MyUseWebAdmin;
	UPROPERTY()					UmoNumericEdit*		MyWebPort;				//var moNumericEdit MyWebPort;
	UPROPERTY()					bool				bInitialized;			//var bool bInitialized;

	void OnChangeCustomBots(bool Enable);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	FString Play();
	void UseMapOnChange(UGUIComponent* Sender);
	void UseCustomOnChange(UGUIComponent* Sender);
	bool UseCustomBots();
};
