// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2InstantActionPage.generated.h"

class UTab_InstantActionMain;
class UTab_InstantActionBaseRules;
class UTab_InstantActionMutators;
class UTab_InstantActionMapList;
class UTab_InstantActionBotConfig;
class UTab_PlayerSettings;
class UGUITabControl;

UCLASS()
class AA29_API UUT2InstantActionPage : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2InstantActionPage();

	UPROPERTY()				UTab_InstantActionMain*				pMain;					//var Tab_InstantActionMain pMain;
	UPROPERTY()				UTab_InstantActionBaseRules*		pRules;					//var Tab_InstantActionBaseRules pRules;
	UPROPERTY()				UTab_InstantActionMutators*			pMutators;				//var Tab_InstantActionMutators pMutators;
	UPROPERTY()				UTab_InstantActionMapList*			pMapList;				//var Tab_InstantActionMapList pMapList;
	UPROPERTY()				UTab_InstantActionBotConfig*		pBotConfig;				//var Tab_InstantActionBotConfig pBotConfig;
	UPROPERTY()				UTab_PlayerSettings*				pPlayerSetup;			//var Tab_PlayerSettings pPlayerSetup;
	UPROPERTY()				UGUITabControl*						MyTabs;					//var GUITabControl MyTabs;
	UPROPERTY()				FString								MainTabLabel;			//var localized FString MainTabLabel;
	UPROPERTY()				FString								MainTabHint;			//var localized FString MainTabHint;
	UPROPERTY()				FString								RulesTabLabel;			//var localized FString RulesTabLabel;
	UPROPERTY()				FString								RulesTabHint;			//var localized FString RulesTabHint;
	UPROPERTY()				FString								MutatorTabLabel;		//var localized FString MutatorTabLabel;
	UPROPERTY()				FString								MutatorTabHint;			//var localized FString MutatorTabHint;
	UPROPERTY()				FString								MapListTabLabel;		//var localized FString MapListTabLabel;
	UPROPERTY()				FString								MapListTabHint;			//var localized FString MapListTabHint;
	UPROPERTY()				FString								BotConfigTabLabel;		//var localized FString BotConfigTabLabel;
	UPROPERTY()				FString								BotConfigTabHint;		//var localized FString BotConfigTabHint;
	UPROPERTY()				FString								PlayerTabLabel;			//var localized FString PlayerTabLabel;
	UPROPERTY()				FString								PlayerTabHint;			//var localized FString PlayerTabHint;
	UPROPERTY()				bool								bSpectate;				//var bool bSpectate;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool BackButtonClick(UGUIComponent* Sender);
	bool PlayButtonClick(UGUIComponent* Sender);
	bool SpecButtonClick(UGUIComponent* Sender);
	void TabChange(UGUIComponent* Sender);
	void ChangeHint(FString NewHint);
	void InternalOnReOpen();
	void ChangeGameType();
	void ChangeCustomBots();
	void InternalOnClose(bool bCanceled);
};
