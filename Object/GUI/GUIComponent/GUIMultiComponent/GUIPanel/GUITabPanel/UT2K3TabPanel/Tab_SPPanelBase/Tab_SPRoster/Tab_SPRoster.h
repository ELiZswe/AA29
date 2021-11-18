// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_SPPanelBase/Tab_SPPanelBase.h"
#include "Tab_SPRoster.generated.h"

class UGUIPanel;
class UGUIGFXButton;
class UGUILabel;
class UGUIComboBox;
class UGUIButton;
class UGUILabel;
class UGUIListBox;
class UGUIImage;
class UGUIScrollTextBox;
class UGUICharacterListTeam;

UCLASS()
class AA29_API UTab_SPRoster : public UTab_SPPanelBase
{
	GENERATED_BODY()
public:
	UTab_SPRoster();

	UPROPERTY()			TArray<UGUIPanel*>		pnlMates;				//var TArray<GUIPanel> pnlMates;
	UPROPERTY()			TArray<UGUIGFXButton*>	imgMates;				//var TArray<GUIGFXButton> imgMates;
	UPROPERTY()			TArray<UGUILabel*>		lblMates;				//var TArray<GUILabel> lblMates;
	UPROPERTY()			TArray<UGUIComboBox*>	cboMates;				//var TArray<GUIComboBox> cboMates;
	UPROPERTY()			TArray<UGUIButton*>		btnMates;				//var TArray<GUIButton> btnMates;
	UPROPERTY()			TArray<UGUILabel*>		lblNA;					//var TArray<GUILabel> lblNA;
	UPROPERTY()			UGUIListBox*			lboStats;				//var GUIListBox lboStats;
	UPROPERTY()			UGUIListBox*			lboTeamStats;			//var GUIListBox lboTeamStats;
	UPROPERTY()			UGUIImage*				imgPortrait;			//var GUIImage imgPortrait;
	UPROPERTY()			UGUILabel*				lblMatchData;			//var GUILabel lblMatchData;
	UPROPERTY()			UGUIScrollTextBox*		stbPlayerData;			//var GUIScrollTextBox stbPlayerData;
	UPROPERTY()			UGUICharacterListTeam*	cltMyTeam;				//var GUICharacterListTeam cltMyTeam;
	UPROPERTY()			FString					MessageNoInfo;			//var localized FString MessageNoInfo;
	UPROPERTY()			FString					PreStatsMessage;		//var localized FString PreStatsMessage;
	UPROPERTY()			FString					PostStatsMessage;		//var localized FString PostStatsMessage;

	void Created();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool CanShowPanel();
	void OnProfileUpdated();
	void OnMatchUpdated(int32 iLadder, int32 iMatch);
	bool ClickLineup(UGUIComponent* Sender);
	bool FixLineup(UGUIComponent* Sender);
	void UpdateMatchInfo();
	void ReloadPortraits();
	void CharListClick(UGUIComponent* Sender);
	void ChangePortraits();
	void BuildTeamStats(UGUIListBox* teambox);
	void PositionChange(UGUIComponent* Sender);
};
