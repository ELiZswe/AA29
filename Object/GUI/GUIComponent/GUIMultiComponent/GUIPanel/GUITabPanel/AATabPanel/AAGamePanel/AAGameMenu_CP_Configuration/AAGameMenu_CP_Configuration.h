// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_CP_Configuration.generated.h"

class UAAGameMenu_CommandPost;
class UmoNumericEdit;
class UmoEditBox;
class UGUILabel;
class UGUIButton;
class UmoComboBox;
class UmoCheckBox;


UCLASS()
class AA29_API UAAGameMenu_CP_Configuration : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_CP_Configuration();

	UPROPERTY()								FString						sMOTDTitle;					//var localized string sMOTDTitle;
	UPROPERTY()								FString						sInstructions;				//var localized string sInstructions;
	UPROPERTY()								bool						bNeverAutoBalance;			//var bool bNeverAutoBalance;
	UPROPERTY()								bool						bAutoBalanceBetweenRounds;	//var bool bAutoBalanceBetweenRounds;
	UPROPERTY()								bool						bPlayersBalanceTeams;		//var bool bPlayersBalanceTeams;
	UPROPERTY()								UAAGameMenu_CommandPost*	aagpCommandPost;			//var AAGameMenu_CommandPost aagpCommandPost;
	UPROPERTY(EditAnywhere)					UmoNumericEdit*				mneMaxAdmins;				//var() XInterface.moNumericEdit mneMaxAdmins;
	UPROPERTY(EditAnywhere)					UmoNumericEdit*				mneMaxPlayers;				//var() XInterface.moNumericEdit mneMaxPlayers;
	UPROPERTY(EditAnywhere)					UmoNumericEdit*				mneMOTDDisplayTime;			//var() XInterface.moNumericEdit mneMOTDDisplayTime;
	UPROPERTY(EditAnywhere)					UmoEditBox*					mebMOTD4;					//var() XInterface.moEditBox mebMOTD4;
	UPROPERTY(EditAnywhere)					UmoEditBox*					mebMOTD3;					//var() XInterface.moEditBox mebMOTD3;
	UPROPERTY(EditAnywhere)					UmoEditBox*					mebMOTD2;					//var() XInterface.moEditBox mebMOTD2;
	UPROPERTY(EditAnywhere)					UmoEditBox*					mebMOTD1;					//var() XInterface.moEditBox mebMOTD1;
	UPROPERTY(EditAnywhere)					UGUILabel*					gulMOTDTitle;				//var() XInterface.GUILabel gulMOTDTitle;
	UPROPERTY(EditAnywhere)					UmoNumericEdit*				mneMaxHonor;				//var() XInterface.moNumericEdit mneMaxHonor;
	UPROPERTY(EditAnywhere)					UmoNumericEdit*				mneMinHonor;				//var() XInterface.moNumericEdit mneMinHonor;
	UPROPERTY(EditAnywhere)					UGUIButton*					guibSaveChanges;			//var() XInterface.GUIButton guibSaveChanges;
	UPROPERTY(EditAnywhere)					UGUILabel*					gulInstructions;			//var() XInterface.GUILabel gulInstructions;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbFireMode;				//var() XInterface.moComboBox mcbFireMode;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbAutoBalanceOptions;		//var() XInterface.moComboBox mcbAutoBalanceOptions;
	UPROPERTY(EditAnywhere)					UmoComboBox*				mcbDelayedStartTime;		//var() XInterface.moComboBox mcbDelayedStartTime;
	UPROPERTY(EditAnywhere)					UmoEditBox*					mebGamePassword;			//var() XInterface.moEditBox mebGamePassword;
	UPROPERTY(EditAnywhere)					UmoCheckBox*				mchkbPrivateServer;			//var() XInterface.moCheckBox mchkbPrivateServer;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitializeDataFields();
	void NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3);
	void UpdateDelayedStartSelection(int32 iDelayedStartTime);
	void UpdateAutoBalanceOptions();
	bool IsAdmin();
	bool CanShowPanel();
	void InternalOnChange(UGUIComponent* Sender);
	bool ButtonClick(UGUIComponent* Sender);
};
