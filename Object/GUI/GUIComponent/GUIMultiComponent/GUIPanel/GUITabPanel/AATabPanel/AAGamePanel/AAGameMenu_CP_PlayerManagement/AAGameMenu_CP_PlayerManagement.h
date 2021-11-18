// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_CP_PlayerManagement.generated.h"

class UAAGameMenu_CommandPost;
class UGUIButton;
class UGUILabel;
class UmoEditBox;
class UGUIListBox;
class UmoComboBox;

UCLASS()
class AA29_API UAAGameMenu_CP_PlayerManagement : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_CP_PlayerManagement();

	UPROPERTY()								int32							iCurrentlySelectedPlayerID;				//var int iCurrentlySelectedPlayerID;
	UPROPERTY()								UAAGameMenu_CommandPost*		aagpCommandPost;						//var AAGameMenu_CommandPost aagpCommandPost;
	UPROPERTY()								TArray<FString>					asWeaponAltClassNames;					//var array<String> asWeaponAltClassNames;
	UPROPERTY()								TArray<FString>					asWeaponClassNames;						//var array<String> asWeaponClassNames;
	UPROPERTY()								TArray<FString>					asWeaponForceClassCommand;				//var array<String> asWeaponForceClassCommand;
	UPROPERTY()								TArray<FString>					asWeaponNames;							//var array<String> asWeaponNames;
	UPROPERTY()								FString							sPlayerDetailsTitle;					//var localized string sPlayerDetailsTitle;
	UPROPERTY()								FString							sPlayerListBoxTitle;					//var localized string sPlayerListBoxTitle;
	UPROPERTY()								FString							sInstructions;							//var localized string sInstructions;
	UPROPERTY(EditAnywhere)					UGUIButton*						guibSwapTeams;							//var() XInterface.GUIButton guibSwapTeams;
	UPROPERTY(EditAnywhere)					UGUILabel*						guilPlayerDetailsLocation;				//var() XInterface.GUILabel guilPlayerDetailsLocation;
	UPROPERTY(EditAnywhere)					UGUILabel*						guilPlayerDetailsTeam;					//var() XInterface.GUILabel guilPlayerDetailsTeam;
	UPROPERTY(EditAnywhere)					UGUILabel*						guilPlayerDetailsScore;					//var() XInterface.GUILabel guilPlayerDetailsScore;
	UPROPERTY(EditAnywhere)					UGUILabel*						guilPlayerDetailsName;					//var() XInterface.GUILabel guilPlayerDetailsName;
	UPROPERTY(EditAnywhere)					UGUILabel*						guilPlayerDetailsTitle;					//var() XInterface.GUILabel guilPlayerDetailsTitle;
	UPROPERTY(EditAnywhere)					UGUIButton*						guibChangeWeapon;						//var() XInterface.GUIButton guibChangeWeapon;
	UPROPERTY(EditAnywhere)					UGUIButton*						guibMessagePlayer;						//var() XInterface.GUIButton guibMessagePlayer;
	UPROPERTY(EditAnywhere)					UmoEditBox*						mebPrivateMessage;						//var() XInterface.moEditBox mebPrivateMessage;
	UPROPERTY(EditAnywhere)					UGUIButton*						guibMutePlayer;							//var() XInterface.GUIButton guibMutePlayer;
	UPROPERTY(EditAnywhere)					UGUIButton*						guibKickPlayer;							//var() XInterface.GUIButton guibKickPlayer;
	UPROPERTY(EditAnywhere)					UGUIButton*						guibViewPlayer;							//var() XInterface.GUIButton guibViewPlayer;
	UPROPERTY(EditAnywhere)					UGUILabel*						guilWeaponSelectAMNotice;				//var() XInterface.GUILabel guilWeaponSelectAMNotice;
	UPROPERTY(EditAnywhere)					UmoComboBox*					mcbWeaponSelections;					//var() XInterface.moComboBox mcbWeaponSelections;
	UPROPERTY(EditAnywhere)					UGUIListBox*					guilbSpectatorList;						//var() XInterface.GUIListBox guilbSpectatorList;
	UPROPERTY(EditAnywhere)					UGUILabel*						guilSpectatorListTitle;					//var() XInterface.GUILabel guilSpectatorListTitle;
	UPROPERTY(EditAnywhere)					UGUIListBox*					guilbPlayersList;						//var() XInterface.GUIListBox guilbPlayersList;
	UPROPERTY(EditAnywhere)					UGUILabel*						guilPlayerListTitle;					//var() XInterface.GUILabel guilPlayerListTitle;
	UPROPERTY(EditAnywhere)					UGUILabel*						guilInstructions;						//var() XInterface.GUILabel guilInstructions;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void OnPlayerListDrawItem(UCanvas* Canvas, int32 iItemIndex, float fpX, float fpY, float fpWidth, float fpHeight, bool bSelected, bool bPending);
	void OnSpectatorListDrawItem(UCanvas* Canvas, int32 iItemIndex, float fpX, float fpY, float fpWidth, float fpHeight, bool bSelected, bool bPending);
	void DrawListItem(UGUIListBox* guilb, UCanvas* Canvas, int32 iItemIndex, float fpX, float fpY, float fpWidth, float fpHeight, bool bSelected, bool bPending);
	void RefreshPlayerList();
	void RefreshSpectatorList();
	void ComparePlayerListItems(FGUIListElem ElemA, FGUIListElem ElemB);
	void Timer();
	bool IsAdmin();
	bool CanShowPanel();
	bool ButtonClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	bool OnPlayerListClick(UGUIComponent* Sender);
	void UpdateSelectedPlayerDetails(bool fUpdateWeaponSelection);
	FString GetPlayerWeapon(int32 iPlayerID);
	void FindPRIFromID(int32 iPlayerID);
};
