// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGUIPage.h"
#include "AAGameMenu.generated.h"

class UGUITabControl;
class UGUIImage;
class UGUIComboBox;
class UGUIButton;
class UAAGameMenu_PlayerStats;

UCLASS()
class AA29_API UAAGameMenu : public UAAGUIPage
{
	GENERATED_BODY()
public:
	UAAGameMenu();

	UPROPERTY(EditAnywhere)			UGUITabControl*				c_Tabs;									//var() automated XInterface.GUITabControl c_Tabs;
	UPROPERTY(EditAnywhere)			UGUIImage*					i_Background;							//var() automated XInterface.GUIImage i_Background;
	UPROPERTY(EditAnywhere)			UGUIImage*					i_MidGamePanel;							//var() automated XInterface.GUIImage i_MidGamePanel;
	UPROPERTY(EditAnywhere)			UGUIComboBox*				co_BattleBuddyChoices;					//var() automated XInterface.GUIComboBox co_BattleBuddyChoices;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_BattleBuddyAction;					//var() automated XInterface.GUIButton b_BattleBuddyAction;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_FavoriteServerAction;					//var() automated XInterface.GUIButton b_FavoriteServerAction;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_Settings;								//var() automated XInterface.GUIButton b_Settings;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_Leave;								//var() automated XInterface.GUIButton b_Leave;
	UPROPERTY(EditAnywhere)			UGUIButton*					b_Exit;									//var() automated XInterface.GUIButton b_Exit;
	UPROPERTY()						TArray<FString>				PanelClasses;							//var FString PanelClasses[10];
	UPROPERTY()						TArray<FString>				PanelCaptions;							//var localized FString PanelCaptions[10];
	UPROPERTY()						TArray<FString>				PanelHints;								//var localized FString PanelHints[10];
	UPROPERTY()						TArray<FString>				CoOpPanelClasses;						//var FString CoOpPanelClasses[10];
	UPROPERTY()						TArray<FString>				TournamentPanelClasses;					//var FString TournamentPanelClasses[7];
	UPROPERTY()						TArray<FString>				TournamentPanelCaptions;				//var localized FString TournamentPanelCaptions[7];
	UPROPERTY()						TArray<FString>				TournamentPanelHints;					//var localized FString TournamentPanelHints[7];
	UPROPERTY()						FString						DisconnectCaption;						//var localized FString DisconnectCaption;
	UPROPERTY()						FString						DisconnectHint;							//var localized FString DisconnectHint;
	UPROPERTY()						FString						FavoritesDisabledHint;					//var localized FString FavoritesDisabledHint;
	UPROPERTY()						FString						FavoriteServerAddHint;					//var localized FString FavoriteServerAddHint;
	UPROPERTY()						FString						FavoriteServerRemoveHint;				//var localized FString FavoriteServerRemoveHint;
	UPROPERTY()						FString						BattleBuddyAddHint;						//var localized FString BattleBuddyAddHint;
	UPROPERTY()						FString						BattleBuddyRemoveHint;					//var localized FString BattleBuddyRemoveHint;
	UPROPERTY()						FString						BattleBuddySelectAPlayerDisabledHint;	//var localized FString BattleBuddySelectAPlayerDisabledHint;
	UPROPERTY()						UAAGameMenu_PlayerStats*	aagmpsStats;							//var AAGameMenu_PlayerStats aagmpsStats;
	UPROPERTY()						bool						bPlayerHUD;								//var bool bPlayerHUD;
	UPROPERTY()						int32						NewPlayerQueue;							//var int32 NewPlayerQueue;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void DisableFavoritesUIElements();
	void PopulateBuddyChoices();
	void PrepareBattleBuddyActionButton();
	FFavoriteServer GetThisServer();
	void PrepareFavoriteServerActionButton();
	void OnOpen();
	void OnClose(bool bCanceled);
	void SwitchPanel(int32 NewPanel);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	void HandleParameters(FString Param1, FString Param2);
	void DoBattleBuddyAction();
	void DoFavoriteServerAction();
	bool ButtonClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	void OpenFavoritesOperationDialog(FString Action, FString Message);
	void InternalOnFavoritesOperationComplete(int32 ResultCode, FString Message);
	void NotifyStatsPage(FString sStatRequested, FString sValue);
	bool InternalOnPreDraw(UCanvas* C);
};
