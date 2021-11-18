// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AATeamGamePanel.h"
#include "AAGameMenu_TeamSelect.generated.h"

class UGUIImage;
class UGUILabel;
class UGUIScrollTextBox;
class UmoEditBox;
class UGUIButton;

UCLASS()
class AA29_API UAAGameMenu_TeamSelect : public UAATeamGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_TeamSelect();

	UPROPERTY(EditAnywhere)				UGUIImage*					i_Background;				//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)				TArray<UGUIImage*>			i_Team;						//var() automated XInterface.GUIImage i_Team[2];
	UPROPERTY(EditAnywhere)				TArray<UGUILabel*>			l_TeamName;					//var() automated XInterface.GUILabel l_TeamName[2];
	UPROPERTY(EditAnywhere)				TArray<UGUILabel*>			l_TeamMsg;					//var() automated XInterface.GUILabel l_TeamMsg[2];
	UPROPERTY(EditAnywhere)				TArray<UGUIScrollTextBox*>	lb_Briefing;				//var() automated XInterface.GUIScrollTextBox lb_Briefing[2];
	UPROPERTY(EditAnywhere)				TArray<UmoEditBox*>			ed_Password;				//var() automated XInterface.moEditBox ed_Password[2];
	UPROPERTY(EditAnywhere)				TArray<UGUIButton*>			b_Join;						//var() automated XInterface.GUIButton b_Join[2];
	UPROPERTY(EditAnywhere)				UGUIButton*					b_Auto;						//var() automated XInterface.GUIButton b_Auto;
	UPROPERTY(EditAnywhere)				UGUIButton*					b_Spectate;					//var() automated XInterface.GUIButton b_Spectate;
	UPROPERTY()							FString						JoinText;					//var localized FString JoinText;
	UPROPERTY()							FString						RemainText;					//var localized FString RemainText;
	UPROPERTY()							FString						SpectateText;				//var localized FString SpectateText;
	UPROPERTY()							FString						PlayerText;					//var localized FString PlayerText;
	UPROPERTY()							FString						PlayerPluralText;			//var localized FString PlayerPluralText;
	UPROPERTY()							FString						OnTeam;						//var localized FString OnTeam;
	UPROPERTY()							FString						GoingToTeam;				//var localized FString GoingToTeam;
	UPROPERTY()							FString						LeavingTeam;				//var localized FString LeavingTeam;
	UPROPERTY()							FString						ASAPTeam;					//var localized FString ASAPTeam;
	UPROPERTY()							FString						OnSpectator;				//var localized FString OnSpectator;
	UPROPERTY()							FString						s_JoinHint;					//var localized FString s_JoinHint;
	UPROPERTY()							uint8						lastTeam;					//var uint8 lastTeam;
	UPROPERTY()							uint8						LastDesired;				//var uint8 LastDesired;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	FString BuildMissionBriefing(int32 iTeam);
	bool MyOnPreDraw(UCanvas* C);
	void CheckTeam(uint8 CurrTeam, uint8 CurrDesired);
	bool CheckTeamPassword(int32 TeamNum, FString Password);
	void JoinTeam(int32 i);
	void SpectateTeam(int32 i);
	bool ButtonClick(UGUIComponent* Sender);
	void Timer();
	void ShowPanel(bool bShow);

};
