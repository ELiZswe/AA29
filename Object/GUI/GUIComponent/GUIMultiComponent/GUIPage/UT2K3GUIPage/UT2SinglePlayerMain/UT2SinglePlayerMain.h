// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "UT2SinglePlayerMain.generated.h"

class UTab_SPPanelBase;
class UGUIButton;
class UGUITabControl;

UCLASS()
class AA29_API UUT2SinglePlayerMain : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UUT2SinglePlayerMain();

	UPROPERTY()					UTab_SPPanelBase*		TP_Profile;					//var Tab_SPPanelBase TP_Profile;
	UPROPERTY()					UTab_SPPanelBase*		TP_Tutorials;				//var Tab_SPPanelBase TP_Tutorials;
	UPROPERTY()					UTab_SPPanelBase*		TP_Qual;					//var Tab_SPPanelBase TP_Qual;
	UPROPERTY()					UTab_SPPanelBase*		TP_Ladder;					//var Tab_SPPanelBase TP_Ladder;
	UPROPERTY()					UTab_SPPanelBase*		TP_Roster;					//var Tab_SPPanelBase TP_Roster;
	UPROPERTY()					UTab_SPPanelBase*		TP_Play;					//var Tab_SPPanelBase TP_Play;
	UPROPERTY()					UGUIButton*				ButtonMenu;					//var GUIButton ButtonMenu;
	UPROPERTY()					UGUIButton*				ButtonPlay;					//var GUIButton ButtonPlay;
	UPROPERTY()					UGUITabControl*			TabC;						//var GUITabControl TabC;
	UPROPERTY()					FString					MessageLadderAvailable;		//var localized FString MessageLadderAvailable;
	UPROPERTY()					FString					MessageLadderComplete;		//var localized FString MessageLadderComplete;
	UPROPERTY()					FString					MessageCreateProfileFirst;	//var localized FString MessageCreateProfileFirst;
	UPROPERTY()					FString					TabNameProfileNew;			//var localized FString TabNameProfileNew;
	UPROPERTY()					FString					TabNameProfileLoad;			//var localized FString TabNameProfileLoad;
	UPROPERTY()					FString					TabNameQualification;		//var localized FString TabNameQualification;
	UPROPERTY()					FString					TabNameLadder;				//var localized FString TabNameLadder;
	UPROPERTY()					FString					TabNameRoster;				//var localized FString TabNameRoster;
	UPROPERTY()					FString					TabNameTutorials;			//var localized FString TabNameTutorials;
	UPROPERTY()					FString					TabHintProfileNew;			//var localized FString TabHintProfileNew;
	UPROPERTY()					FString					TabHintProfileLoad;			//var localized FString TabHintProfileLoad;
	UPROPERTY()					FString					TabHintQualification;		//var localized FString TabHintQualification;
	UPROPERTY()					FString					TabHintLadder;				//var localized FString TabHintLadder;
	UPROPERTY()					FString					TabHintRoster;				//var localized FString TabHintRoster;
	UPROPERTY()					FString					TabHintTutorials;			//var localized FString TabHintTutorials;
	UPROPERTY()					bool					bFinishedPanels;			//var bool bFinishedPanels;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void HandleParameters(FString Param1, FString Param2);
	void PopupButton(uint8 yButton);
	void HandleSpecialEvent(FString SpecialEvent);
	void ChangeHint(FString NewHint);
	bool ButtonClick(UGUIComponent* Sender);
	void TabChange(UGUIComponent* Sender);
	void ResetTitleBar(UGUITabButton* TB);
	void BoxChange(UGUIComponent* Sender);
	void PassThroughProfileUpdated();
	void ProfileUpdated();
};
