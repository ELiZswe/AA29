// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_ServerInfo/AAGameMenu_ServerInfo.h"
#include "AAGameMenu_TournamentServerInfo.generated.h"

class UGUIButton;
class UGUILabel;
class UGUIImage;

UCLASS()
class AA29_API UAAGameMenu_TournamentServerInfo : public UAAGameMenu_ServerInfo
{
	GENERATED_BODY()
public:
	UAAGameMenu_TournamentServerInfo();

	UPROPERTY()								int32 iAdminRestartTimer;								//var int iAdminRestartTimer;
	UPROPERTY(EditAnywhere)					UGUIButton* b_DiscardRound;								//var() XInterface.GUIButton b_DiscardRound;
	UPROPERTY(EditAnywhere)					UGUIButton* b_SwapTeams;								//var() XInterface.GUIButton b_SwapTeams;
	UPROPERTY(EditAnywhere)					UGUIButton* b_PauseTournament;							//var() XInterface.GUIButton b_PauseTournament;
	UPROPERTY(EditAnywhere)					UGUIButton* b_StartMatch;								//var() XInterface.GUIButton b_StartMatch;
	UPROPERTY(EditAnywhere)					UGUIButton* b_StartWarmup;								//var() XInterface.GUIButton b_StartWarmup;
	UPROPERTY(EditAnywhere)					UGUILabel* l_TournamentShadowsAllowedLabel;				//var() XInterface.GUILabel l_TournamentShadowsAllowedLabel;
	UPROPERTY(EditAnywhere)					UGUILabel* l_TournamentEnableRandomTeamAssignments;		//var() XInterface.GUILabel l_TournamentEnableRandomTeamAssignments;
	UPROPERTY(EditAnywhere)					UGUILabel* l_TournamentTieScore;						//var() XInterface.GUILabel l_TournamentTieScore;
	UPROPERTY(EditAnywhere)					UGUILabel* l_TournamentTieSuddenDeath;					//var() XInterface.GUILabel l_TournamentTieSuddenDeath;
	UPROPERTY(EditAnywhere)					UGUILabel* l_TournamentTeamPasswordsRequired;			//var() XInterface.GUILabel l_TournamentTeamPasswordsRequired;
	UPROPERTY(EditAnywhere)					UGUILabel* l_TournamentTeamCaptainsAllowed;				//var() XInterface.GUILabel l_TournamentTeamCaptainsAllowed;
	UPROPERTY(EditAnywhere)					UGUILabel* l_TournamentOpenAllWeaponClassSlots;			//var() XInterface.GUILabel l_TournamentOpenAllWeaponClassSlots;
	UPROPERTY(EditAnywhere)					UGUILabel* l_TournamentMercyRule;						//var() XInterface.GUILabel l_TournamentMercyRule;
	UPROPERTY(EditAnywhere)					UGUILabel* l_TournamentSwapLimit;						//var() XInterface.GUILabel l_TournamentSwapLimit;
	UPROPERTY(EditAnywhere)					UGUILabel* l_TournamentSwapTime;						//var() XInterface.GUILabel l_TournamentSwapTime;
	UPROPERTY(EditAnywhere)					UGUILabel* l_TournamentWarmupDuration;					//var() XInterface.GUILabel l_TournamentWarmupDuration;
	UPROPERTY(EditAnywhere)					UGUILabel* l_TournamentRequestDelayTime;				//var() XInterface.GUILabel l_TournamentRequestDelayTime;
	UPROPERTY(EditAnywhere)					UGUILabel* l_TournamentRoundDelayTime;					//var() XInterface.GUILabel l_TournamentRoundDelayTime;
	UPROPERTY(EditAnywhere)					UGUIImage* i_Buttons;									//var() XInterface.GUIImage i_Buttons;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnPreDraw(UCanvas* C);
	bool InternalOnClick(UGUIComponent* Sender);
	void Timer();
};
