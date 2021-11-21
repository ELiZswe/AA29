// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_CP_Rules.generated.h"

class UAAGameMenu_CommandPost;
class UGUILabel;
class UmoCheckBox;
class UmoComboBox;
class UGUIButton;
class UmoNumericEdit;

UCLASS()
class AA29_API UAAGameMenu_CP_Rules : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_CP_Rules();

	UPROPERTY()								int32						iIdlePlayerKickRounds;					//var int iIdlePlayerKickRounds;
	UPROPERTY()								bool						bKickIdlePlayersRounds;					//var bool bKickIdlePlayersRounds;
	UPROPERTY()								int32						iIdlePlayerKickMinutes;					//var int iIdlePlayerKickMinutes;
	UPROPERTY()								bool						bKickIdlePlayersTimed;					//var bool bKickIdlePlayersTimed;
	UPROPERTY()								bool						bEnableROEKick;							//var bool bEnableROEKick;
	UPROPERTY()								bool						bROEKickDeath;							//var bool bROEKickDeath;
	UPROPERTY()								bool						bSpectateFriendsOnly;					//var bool bSpectateFriendsOnly;
	UPROPERTY()								bool						bSpectateFirstPersonOnly;				//var bool bSpectateFirstPersonOnly;
	UPROPERTY()								bool						bSpectatePlayersOnly;					//var bool bSpectatePlayersOnly;
	UPROPERTY()								UAAGameMenu_CommandPost*	aagpCommandPost;						//var AAGameMenu_CommandPost aagpCommandPost;
	UPROPERTY()								FString						sHUDOptionsTitle;						//var localized string sHUDOptionsTitle;
	UPROPERTY()								FString						sInstructions;							//var localized string sInstructions;
	UPROPERTY(EditAnywhere)					UGUILabel*					gulROEKickOptionsTitle;					//var() XInterface.GUILabel gulROEKickOptionsTitle;
	UPROPERTY(EditAnywhere)					UGUILabel*					gulHUDOptionsTitle;						//var() XInterface.GUILabel gulHUDOptionsTitle;
	UPROPERTY(EditAnywhere)					UGUILabel*					gulInstructions;						//var() XInterface.GUILabel gulInstructions;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbHUDHideOptics;						//var() XInterface.moCheckBox mchkbHUDHideOptics;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbHUDHideRadar;						//var() XInterface.moCheckBox mchkbHUDHideRadar;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbHUDHideTimer;						//var() XInterface.moCheckBox mchkbHUDHideTimer;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbHUDHideCEM;						//var() XInterface.moCheckBox mchkbHUDHideCEM;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbHUDHideHealth;						//var() XInterface.moCheckBox mchkbHUDHideHealth;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbHUDHideGrenades;					//var() XInterface.moCheckBox mchkbHUDHideGrenades;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbHUDHideWeaponSelection;			//var() XInterface.moCheckBox mchkbHUDHideWeaponSelection;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbHUDHideWeaponStatus;				//var() XInterface.moCheckBox mchkbHUDHideWeaponStatus;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbHUDHideAmmoCount;					//var() XInterface.moCheckBox mchkbHUDHideAmmoCount;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbIdleKickRounds;						//var() XInterface.moComboBox mcbIdleKickRounds;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbIdleKickMinutes;						//var() XInterface.moComboBox mcbIdleKickMinutes;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbESSDisable;						//var() XInterface.moCheckBox mchkbESSDisable;
	UPROPERTY(EditAnywhere)					UGUIButton*					guibSaveChanges;						//var() XInterface.GUIButton guibSaveChanges;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbROEKickTimer;						//var() XInterface.moCheckBox mchkbROEKickTimer;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbROEKick;								//var() XInterface.moComboBox mcbROEKick;
	UPROPERTY(EditAnywhere)					UmoNumericEdit*				mneROELimit;							//var() XInterface.moNumericEdit mneROELimit;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbScoreboardMode;						//var() XInterface.moComboBox mcbScoreboardMode;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbChatLoggingLevel;					//var() XInterface.moComboBox mcbChatLoggingLevel;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbDisableAllClientShadows;			//var() XInterface.moCheckBox mchkbDisableAllClientShadows;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbOpenAllWeaponSlots;				//var() XInterface.moCheckBox mchkbOpenAllWeaponSlots;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbEnableDeathMessages;				//var() XInterface.moCheckBox mchkbEnableDeathMessages;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbSpectatingMode;						//var() XInterface.moComboBox mcbSpectatingMode;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbTimeLimit;							//var() XInterface.moComboBox mcbTimeLimit;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbRoundsPerMatch;						//var() XInterface.moComboBox mcbRoundsPerMatch;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				sInsmchkbEnableCheatstructions;			//var() XInterface.moCheckBox mchkbEnableCheats;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbEnableCheats;						//var() automated XInterface.moCheckBox mchkbEnableCheats;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitializeDataFields();
	bool IsAdmin();
	bool CanShowPanel();
	void InternalOnChange(UGUIComponent* Sender);
	bool ButtonClick(UGUIComponent* Sender);
	void NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3);
	void UpdateIdlePlayerOptions();
	void UpdateROEKickOptions();
	void UpdateSpectatingRulesField();

};
