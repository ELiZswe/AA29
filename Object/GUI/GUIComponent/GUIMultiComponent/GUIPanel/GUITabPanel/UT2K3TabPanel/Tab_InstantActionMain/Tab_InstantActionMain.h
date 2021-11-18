// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_InstantActionMain.generated.h"

class UGUILabel;
class UmoNumericEdit;
class UmoCheckBox;
class UmoComboBox;
class UGUIScrollTextBox;
class UGUIImage;
class UmoComboBox;
class UGUIListBox;

UCLASS(Config = Game)
class AA29_API UTab_InstantActionMain : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_InstantActionMain();

	UPROPERTY(config)			FString				LastGameType;			//var config FString LastGameType;
	UPROPERTY(config)			FString				LastMap;				//var config FString LastMap;
	UPROPERTY(config)			int32				LastBotSkill;			//var config int32 LastBotSkill;
	UPROPERTY(config)			int32				LastBotCount;			//var config int32 LastBotCount;
	UPROPERTY(config)			bool				LastUseMapBots;			//var config bool LastUseMapBots;
	UPROPERTY(config)			bool				LastUseCustomBots;		//var config bool LastUseCustomBots;
	UPROPERTY()					UGUIListBox*		MyMapList;				//var GUIListBox MyMapList;
	UPROPERTY()					UmoComboBox*		MyGameCombo;			//var moComboBox MyGameCombo;
	UPROPERTY()					UGUIImage*			MyMapImage;				//var GUIImage MyMapImage;
	UPROPERTY()					UGUIScrollTextBox*	MyMapScroll;			//var GUIScrollTextBox MyMapScroll;
	UPROPERTY()					UmoComboBox*		MyBotSkill;				//var moComboBox MyBotSkill;
	UPROPERTY()					UmoCheckBox*		MyUseMapBots;			//var moCheckBox MyUseMapBots;
	UPROPERTY()					UmoCheckBox*		MyUseCustomBots;		//var moCheckBox MyUseCustomBots;
	UPROPERTY()					UmoNumericEdit*		MyBotCount;				//var moNumericEdit MyBotCount;
	UPROPERTY()					UGUILabel*			MyMapName;				//var GUILabel MyMapName;
	UPROPERTY()					TArray<FString>		DifficultyLevels;		//var localized FString DifficultyLevels[8];
	UPROPERTY()					FString				MessageNoInfo;			//var localized FString MessageNoInfo;

	void OnChangeGameType();
	void OnChangeCustomBots();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SelectGameType(FString GameType);
	FString Play();
	FString ParseDescStr(FString DescStr, int32 Index);
	FString GetMapPrefix();
	FString GetRulesClass();
	FString GetMapListClass();
	bool GetIsTeamGame();
	FString GetGameClass();
	void ReadMapList(FString MapPrefix);
	void ReadMapInfo(FString MapName);
	void GameTypeChanged(UGUIComponent* Sender);
	void MapListChange(UGUIComponent* Sender);
	void BotSkillChanged(UGUIComponent* Sender);
	void ChangeMapBots(UGUIComponent* Sender);
	void ChangeCustomBots(UGUIComponent* Sender);
	bool MapListDblClick(UGUIComponent* Sender);
};
