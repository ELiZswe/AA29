// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AATeamGamePanel.h"
#include "AAGameMenu_CoOpTeamSelect.generated.h"

class UGUIButton;
class UmoEditBox;
class UGUIScrollTextBox;
class UGUILabel;
class UGUIImage;

UCLASS()
class AA29_API UAAGameMenu_CoOpTeamSelect : public UAATeamGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_CoOpTeamSelect();


	UPROPERTY(EditAnywhere)			UGUIImage*			i_Background;		//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)			UGUIImage*			i_Team;				//var() automated XInterface.GUIImage i_Team;
	UPROPERTY(EditAnywhere)			UGUILabel*			l_TeamName;			//var() automated XInterface.GUILabel l_TeamName;
	UPROPERTY(EditAnywhere)			UGUILabel*			l_TeamMsg;			//var() automated XInterface.GUILabel l_TeamMsg;
	UPROPERTY(EditAnywhere)			UGUIScrollTextBox*	lb_Briefing;		//var() automated XInterface.GUIScrollTextBox lb_Briefing;
	UPROPERTY(EditAnywhere)			UmoEditBox*			ed_Password;		//var() automated XInterface.moEditBox ed_Password;
	UPROPERTY(EditAnywhere)			UGUIButton*			b_Join;				//var() automated XInterface.GUIButton b_Join;
	UPROPERTY(EditAnywhere)			UGUIButton*			b_Spectate;			//var() automated XInterface.GUIButton b_Spectate;
	UPROPERTY()						FString				JoinText;			//var localized FString JoinText;
	UPROPERTY()						FString				RemainText;			//var localized FString RemainText;
	UPROPERTY()						FString				SpectateText;		//var localized FString SpectateText;
	UPROPERTY()						FString				PlayerText;			//var localized FString PlayerText;
	UPROPERTY()						FString				PlayerPluralText;	//var localized FString PlayerPluralText;
	UPROPERTY()						FString				OnTeam;				//var localized FString OnTeam;
	UPROPERTY()						FString				GoingToTeam;		//var localized FString GoingToTeam;
	UPROPERTY()						FString				LeavingTeam;		//var localized FString LeavingTeam;
	UPROPERTY()						FString				ASAPTeam;			//var localized FString ASAPTeam;
	UPROPERTY()						FString				OnSpectator;		//var localized FString OnSpectator;
	UPROPERTY()						FString				s_JoinHint;			//var localized FString s_JoinHint;
	UPROPERTY()						FString				lastTeam;			//var uint8 lastTeam;
	UPROPERTY()						FString				LastDesired;		//var uint8 LastDesired;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	FString BuildMissionBriefing(int32 iTeam);
	bool MyOnPreDraw(UCanvas* C);
	void CheckTeam(uint8 CurrTeam, uint8 CurrDesired);
	bool CheckTeamPassword(int32 TeamNum, FString Password);
	void JoinTeam(int32 i);
	void SpectateTeam();
	bool ButtonClick(UGUIComponent* Sender);
	void Timer();
	void ShowPanel(bool bShow);
};
