// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AAGameMenu_WeaponClass/AAGameMenu_WeaponClass.h"
#include "AAGameMenu_TournamentRoster.generated.h"

class UGUIImage;
class UmoComboBox;
class UmoEditBox;
class UmoCheckBox;
class UGUIButton;

UCLASS()
class AA29_API UAAGameMenu_TournamentRoster : public UAAGameMenu_WeaponClass
{
	GENERATED_BODY()
public:
	UAAGameMenu_TournamentRoster();

	UPROPERTY(EditAnywhere)				UGUIImage*			i_TournamentBackgroundTop;		//var() automated XInterface.GUIImage i_TournamentBackgroundTop;
	UPROPERTY(EditAnywhere)				UGUIImage*			i_TournamentBackgroundBottom;	//var() automated XInterface.GUIImage i_TournamentBackgroundBottom;
	UPROPERTY(EditAnywhere)				UmoComboBox*		co_Team;						//var() automated XInterface.moComboBox co_Team;
	UPROPERTY(EditAnywhere)				UmoEditBox*			ed_TeamName;					//var() automated XInterface.moEditBox ed_TeamName;
	UPROPERTY(EditAnywhere)				UmoCheckBox*		ch_TeamCaptain;					//var() automated XInterface.moCheckBox ch_TeamCaptain;
	UPROPERTY(EditAnywhere)				UGUIButton*			b_TeamReady;					//var() automated XInterface.GUIButton b_TeamReady;
	UPROPERTY(EditAnywhere)				UGUIButton*			b_TeamRosterLock;				//var() automated XInterface.GUIButton b_TeamRosterLock;
	UPROPERTY()							FString				LockText;						//var localized FString LockText;
	UPROPERTY()							FString				UnlockText;						//var localized FString UnlockText;
	UPROPERTY()							FString				ReadyText;						//var localized FString ReadyText;
	UPROPERTY()							FString				NotReadyText;					//var localized FString NotReadyText;
	UPROPERTY()							FString				AdminReadyText;					//var localized FString AdminReadyText;
	UPROPERTY()							FString				TeamCaptainHint;				//var localized FString TeamCaptainHint;
	UPROPERTY()							FString				NotTeamCaptainHint;				//var localized FString NotTeamCaptainHint;
	UPROPERTY()							FString				LockHint;						//var localized FString LockHint;
	UPROPERTY()							FString				UnlockHint;						//var localized FString UnlockHint;
	UPROPERTY()							FString				ReadyHint;						//var localized FString ReadyHint;
	UPROPERTY()							FString				NotReadyHint;					//var localized FString NotReadyHint;
	UPROPERTY()							FString				AdminReadyHint;					//var localized FString AdminReadyHint;
	UPROPERTY()							TArray<FString>		TeamNameText;					//var localized FString TeamNameText[2];
	UPROPERTY()							bool				bLocked;						//var bool bLocked;
	UPROPERTY()							bool				bReady;							//var bool bReady;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Refresh();
	bool MyOnPreDraw(UCanvas* C);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void LoadTeams(UGUIComponent* Sender, FString S);
	void RefreshTeamName();
	void LoadTeamName();
	void InternalOnChange(UGUIComponent* Sender);
	bool InternalOnClick(UGUIComponent* Sender);
	void InternalOnLoadTeam(UGUIComponent* Sender, FString S);
	void InternalOnChangeTeam(UGUIComponent* Sender);
	bool CanShowPanel();
	void ShowPanel(bool bShow);
	void RefreshComponents();
	void SetTeam(ATeamInfo* TI);

};
