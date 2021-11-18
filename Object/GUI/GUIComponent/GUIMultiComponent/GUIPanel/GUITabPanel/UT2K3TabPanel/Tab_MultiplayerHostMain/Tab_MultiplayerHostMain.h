// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_MultiplayerHostMain.generated.h"

class UmoComboBox;
class UGUIImage;
class UGUIScrollTextBox;
class UGUIListBox;

UCLASS(Config = Game)
class AA29_API UTab_MultiplayerHostMain : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_MultiplayerHostMain();

	UPROPERTY(config)			FString				LastGameType;			//var config FString LastGameType;
	UPROPERTY(config)			FString				LastMap;				//var config FString LastMap;
	UPROPERTY()					UmoComboBox*		MyGameCombo;			//var moComboBox MyGameCombo;
	UPROPERTY()					UGUIImage*			MyMapImage;				//var GUIImage MyMapImage;
	UPROPERTY()					UGUIScrollTextBox*	MyMapScroll;			//var GUIScrollTextBox MyMapScroll;
	UPROPERTY()					UGUIListBox*		MyFullMapList;			//var GUIListBox MyFullMapList;
	UPROPERTY()					UGUIListBox*		MyCurMapList;			//var GUIListBox MyCurMapList;
	UPROPERTY()					UGUILabel*			MyMapName;				//var GUILabel MyMapName;
	UPROPERTY()					FString				MessageNoInfo;			//var localized FString MessageNoInfo;

	void OnChangeGameType();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	FString Play();
	FString ParseDescStr(FString DescStr, int32 Index);
	FString GetMapPrefix();
	FString GetRulesClass();
	bool GetIsTeamGame();
	FString GetMapListClass();
	FString GetGameClass();
	void ReadMapInfo(FString MapName);
	void ReadMapList(FString MapPrefix, FString MapListClass);
	bool MapAdd(UGUIComponent* Sender);
	bool MapRemove(UGUIComponent* Sender);
	bool MapAll(UGUIComponent* Sender);
	bool MapClear(UGUIComponent* Sender);
	bool MapUp(UGUIComponent* Sender);
	bool MapDown(UGUIComponent* Sender);
	void GameTypeChanged(UGUIComponent* Sender);
	void MapListChange(UGUIComponent* Sender);
	void SelectGameType(FString GameType);
};
