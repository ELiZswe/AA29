// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/UT2K3TabPanel.h"
#include "Tab_InstantActionBotConfig.generated.h"

class UGUIListBox;
class UGUIImage;
class UGUICharacterList;
class UGUIButton;
class UGUILabel;

UCLASS()
class AA29_API UTab_InstantActionBotConfig : public UUT2K3TabPanel
{
	GENERATED_BODY()
public:
	UTab_InstantActionBotConfig();

	UPROPERTY()				UGUIListBox*		MyRedTeam;				//var GUIListBox MyRedTeam;
	UPROPERTY()				UGUIListBox*		MyBlueTeam;				//var GUIListBox MyBlueTeam;
	UPROPERTY()				UGUIImage*			MyPortrait;				//var GUIImage MyPortrait;
	UPROPERTY()				UGUICharacterList*	MyBotList;				//var GUICharacterList MyBotList;
	UPROPERTY()				UGUIButton*			MyBotMaker;				//var GUIButton MyBotMaker;
	UPROPERTY()				UGUILabel*			MyBotName;				//var GUILabel MyBotName;
	UPROPERTY()				bool				bIgnoreListChange;		//var bool bIgnoreListChange;
	UPROPERTY()				bool				bTeamGame;				//var bool bTeamGame;
	UPROPERTY()				bool				bPlaySounds;			//var bool bPlaySounds;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ShowPanel(bool bShow);
	void SetupBotLists(bool bIsTeam);
	FString Play();
	void CharListChange(UGUIComponent* Sender);
	bool RedClickAdd(UGUIComponent* Sender);
	bool BlueClickAdd(UGUIComponent* Sender);
	bool RedClickRemove(UGUIComponent* Sender);
	bool BlueClickRemove(UGUIComponent* Sender);
	void ListChange(UGUIComponent* Sender);
	bool InternalOnClick(UGUIComponent* Sender);
	bool BotInfoClick(UGUIComponent* Sender);
	bool BotConfigClick(UGUIComponent* Sender);
};
