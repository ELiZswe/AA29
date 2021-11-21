// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_CP_Tournament.generated.h"

class UAAGameMenu_CommandPost;
class UGUILabel;
class UmoCheckBox;
class UmoComboBox;
class UGUIButton;
class UmoNumericEdit;
class UmoEditBox;

UCLASS()
class AA29_API UAAGameMenu_CP_Tournament : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_CP_Tournament();

	UPROPERTY()								UAAGameMenu_CommandPost*	aagpCommandPost;								//var AAGameMenu_CommandPost aagpCommandPost;
	UPROPERTY()								FString						sInstructions;									//var localized string sInstructions;
	UPROPERTY()								int32						iSwitchTimer;									//var int iSwitchTimer;
	UPROPERTY()								UGUILabel*					gulInstructions;								//var() XInterface.GUILabel gulInstructions;
	UPROPERTY()								bool						bTournamentTieScore;							//var bool bTournamentTieScore;
	UPROPERTY()								bool						bTournamentTieSuddenDeath;						//var bool bTournamentTieSuddenDeath;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbTournamentTieBreakingRules;					//var() XInterface.moComboBox mcbTournamentTieBreakingRules;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbTournamentEnableRandomTeamAssignments;		//var() XInterface.moCheckBox mchkbTournamentEnableRandomTeamAssignments;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbTournamentTeamPasswordsRequired;			//var() XInterface.moCheckBox mchkbTournamentTeamPasswordsRequired;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbTournamentTeamCaptainsAllowed;				//var() XInterface.moCheckBox mchkbTournamentTeamCaptainsAllowed;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbTournamentOpenAllWeaponClassSlots;			//var() XInterface.moCheckBox mchkbTournamentOpenAllWeaponClassSlots;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbMercyRule;									//var() XInterface.moCheckBox mchkbMercyRule;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbTournamentRoundDelayTime;					//var() XInterface.moComboBox mcbTournamentRoundDelayTime;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbTournamentRequestDelayTime;					//var() XInterface.moComboBox mcbTournamentRequestDelayTime;
	UPROPERTY(EditAnywhere)					UGUIButton*					guibSwitchServerMode;							//var() XInterface.GUIButton guibSwitchServerMode;
	UPROPERTY(EditAnywhere)					UGUIButton*					guibSaveChanges;								//var() XInterface.GUIButton guibSaveChanges;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbTournamentWarmupDuration;					//var() XInterface.moComboBox mcbTournamentWarmupDuration;
	UPROPERTY(EditAnywhere)					UmoNumericEdit*				mneTournamentSwapTime;							//var() XInterface.moNumericEdit mneTournamentSwapTime;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbTournamentSwapLimit;							//var() XInterface.moComboBox mcbTournamentSwapLimit;
	UPROPERTY(EditAnywhere)					UmoNumericEdit*				mneTournamentPauseLimit;						//var() XInterface.moNumericEdit mneTournamentPauseLimit;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbDisable203Reloads;							//var() XInterface.moCheckBox mchkbDisable203Reloads;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbDisableFlashbangGrenade;					//var() XInterface.moCheckBox mchkbDisableFlashbangGrenade;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbDisableThermiteGrenade;					//var() XInterface.moCheckBox mchkbDisableThermiteGrenade;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbDisableSmokeGrenade;						//var() XInterface.moCheckBox mchkbDisableSmokeGrenade;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbDisableFragGrenade;						//var() XInterface.moCheckBox mchkbDisableFragGrenade;
	UPROPERTY(EditAnywhere)					UmoEditBox*					mebTournamentTeamPassword1;						//var() XInterface.moEditBox mebTournamentTeamPassword1;
	UPROPERTY(EditAnywhere)					UmoEditBox*					mebTournamentTeamPassword0;						//var() XInterface.moEditBox mebTournamentTeamPassword0;
	UPROPERTY(EditAnywhere)					UmoEditBox*					mebTournamentTeamName1;							//var() XInterface.moEditBox mebTournamentTeamName1;
	UPROPERTY(EditAnywhere)					UmoEditBox*					mebTournamentTeamName0;							//var() XInterface.moEditBox mebTournamentTeamName0;
	UPROPERTY(EditAnywhere)					UmoEditBox*					mebTournamentName;								//var() XInterface.moEditBox mebTournamentName;
	UPROPERTY(EditAnywhere)					UmoEditBox*					mebLeagueName;									//var() XInterface.moEditBox mebLeagueName;
	UPROPERTY(EditAnywhere)					UmoEditBox*					mebMatchName;									//var() XInterface.moEditBox mebMatchName;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitializeDataFields();
	bool IsAdmin();
	bool CanShowPanel();
	void InternalOnChange(UGUIComponent* Sender);
	void Timer();
	bool ButtonClick(UGUIComponent* Sender);
	void NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3);
	void UpdateTieBreakingRulesField();
};
