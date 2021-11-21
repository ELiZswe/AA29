// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2MultiplayerHostPage.generated.h"

class UTab_MultiplayerHostMain;
class UTab_InstantActionBaseRules;
class UTab_InstantActionMutators;
class UTab_MultiplayerHostServerSetting;
class UTab_InstantActionBotConfig;
class UGUITabControl;

UCLASS()
class AA29_API UUT2MultiplayerHostPage : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2MultiplayerHostPage();

	UPROPERTY()					UTab_MultiplayerHostMain*			pMain;					//var Tab_MultiplayerHostMain pMain;
	UPROPERTY()					UTab_InstantActionBaseRules*		pRules;					//var Tab_InstantActionBaseRules pRules;
	UPROPERTY()					UTab_InstantActionMutators*			pMutators;				//var Tab_InstantActionMutators pMutators;
	UPROPERTY()					UTab_MultiplayerHostServerSetting*	pServer;				//var Tab_MultiplayerHostServerSettings pServer;
	UPROPERTY()					UTab_InstantActionBotConfig*		pBotConfig;				//var Tab_InstantActionBotConfig pBotConfig;
	UPROPERTY()					UGUITabControl*						MyTabs;					//var GUITabControl MyTabs;
	UPROPERTY()					FString								MainTabLabel;			//var localized FString MainTabLabel;
	UPROPERTY()					FString								MainTabHint;			//var localized FString MainTabHint;
	UPROPERTY()					FString								RulesTabLabel;			//var localized FString RulesTabLabel;
	UPROPERTY()					FString								RulesTabHint;			//var localized FString RulesTabHint;
	UPROPERTY()					FString								MutatorsTabLabel;		//var localized FString MutatorsTabLabel;
	UPROPERTY()					FString								MutatorsTabHint;		//var localized FString MutatorsTabHint;
	UPROPERTY()					FString								ServerTabLabel;			//var localized FString ServerTabLabel;
	UPROPERTY()					FString								ServerTabHint;			//var localized FString ServerTabHint;
	UPROPERTY()					FString								BotTabLabel;			//var localized FString BotTabLabel;
	UPROPERTY()					FString								BotTabHint;				//var localized FString BotTabHint;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool BackButtonClick(UGUIComponent* Sender);
	bool PlayButtonClick(UGUIComponent* Sender);
	void TabChange(UGUIComponent* Sender);
	void ChangeHint(FString NewHint);
	void InternalOnReOpen();
	void ChangeGameType();
	void ChangeCustomBots(bool Enable);
};
