// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2DraftTeam.generated.h"

class UGUIListBox;
class UGUILabel;
class UGUIScrollTextBox;
class UGUICharacterListTeam;
class UGUIButton;
class UGUIGFXButton;
class UGUITitleBar;

UCLASS()
class AA29_API UUT2DraftTeam : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2DraftTeam();

	UPROPERTY()				UGUIListBox*			lboStats;				//var GUIListBox lboStats;
	UPROPERTY()				UGUIListBox*			lboTeamStats;			//var GUIListBox lboTeamStats;
	UPROPERTY()				UGUILabel*				lblMatchData;			//var GUILabel lblMatchData;
	UPROPERTY()				UGUILabel*				lblChoose;				//var GUILabel lblChoose;
	UPROPERTY()				UGUIScrollTextBox*		stbPlayerData;			//var GUIScrollTextBox stbPlayerData;
	UPROPERTY()				UGUICharacterListTeam*	cltMyTeam;				//var GUICharacterListTeam cltMyTeam;
	UPROPERTY()				UGUICharacterListTeam*	cltPortrait;			//var GUICharacterListTeam cltPortrait;
	UPROPERTY()				UGUIButton*				butDraft;				//var GUIButton butDraft;
	UPROPERTY()				UGUIButton*				butRelease;				//var GUIButton butRelease;
	UPROPERTY()				UGUIButton*				butClear;				//var GUIButton butClear;
	UPROPERTY()				UGUIButton*				butEnter;				//var GUIButton butEnter;
	UPROPERTY()				UGUIButton*				butAuto;				//var GUIButton butAuto;
	UPROPERTY()				UGUIGFXButton*			butLeft;				//var GUIGFXButton butLeft;
	UPROPERTY()				UGUIGFXButton*			butRight;				//var GUIGFXButton butRight;
	UPROPERTY()				UGUITitleBar*			MyTitleBar;				//var GUITitleBar MyTitleBar;
	UPROPERTY()				UGUITitleBar*			MyHintBar;				//var GUITitleBar MyHintBar;
	UPROPERTY()				FString					ButtonStyleEnabled;		//var FString ButtonStyleEnabled;
	UPROPERTY()				FString					ButtonStyleDisabled;	//var FString ButtonStyleDisabled;
	UPROPERTY()				FString					ClearConfirmMessage;	//var localized FString ClearConfirmMessage;
	UPROPERTY()				FString					EnterConfirmMessage;	//var localized FString EnterConfirmMessage;
	UPROPERTY()				FString					StatsMessage;			//var localized FString StatsMessage;
	UPROPERTY()				bool					bPlaySounds;			//var bool bPlaySounds;

	void Created();
	bool MyKeyEvent(uint8& Key, uint8& State, float Delta);
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ReloadPortraits();
	void CharListUpdate(UGUIComponent* Sender);
	void CharListChange(UGUIComponent* Sender);
	bool IsOnTeam(FString botname);
	bool IsTeamFull();
	void UpdateDraftable(bool bAffordable);
	void AutoFillTeam();
	bool ButtonClick(UGUIComponent* Sender);
	void ChangeHint(FString NewHint);
	void FinishButtonClick();
	void ClearConfirm(uint8 bButton);
	void EnterConfirm(uint8 bButton);
};
