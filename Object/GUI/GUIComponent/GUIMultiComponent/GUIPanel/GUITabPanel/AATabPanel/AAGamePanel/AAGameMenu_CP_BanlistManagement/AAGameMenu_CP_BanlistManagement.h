// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGamePanel.h"
#include "AAGameMenu_CP_BanlistManagement.generated.h"

class UAAGameMenu_CommandPost;
class UGUILabel;
class UGUIButton;
class UmoComboBox;
class UGUIListBox;

/**
 * 
 */
UCLASS()
class AA29_API UAAGameMenu_CP_BanlistManagement : public UAAGamePanel
{
	GENERATED_BODY()
public:
	UAAGameMenu_CP_BanlistManagement();

	UPROPERTY(EditAnywhere)								int32						iCurrentlySelectedPlayerID;		//var int iCurrentlySelectedPlayerID;
	UPROPERTY(EditAnywhere)								UAAGameMenu_CommandPost*	aagpCommandPost;				//var AAGameMenu_CommandPost aagpCommandPost;
	UPROPERTY(EditAnywhere)								FString						sBanDetailsTitle;				//var localized string sBanDetailsTitle;
	UPROPERTY(EditAnywhere)								FString						sPlayerListBoxTitle;			//var localized string sPlayerListBoxTitle;
	UPROPERTY(EditAnywhere)								FString						sInstructions;					//var localized string sInstructions;
	UPROPERTY(EditAnywhere)								UGUILabel*					guilPlayerDetailsName;			//var() XInterface.GUILabel guilPlayerDetailsName;
	UPROPERTY(EditAnywhere)								UGUILabel*					guilPlayerDetailsTitle;			//var() XInterface.GUILabel guilPlayerDetailsTitle;
	UPROPERTY(EditAnywhere)								UGUIButton*					guibBan;						//var() XInterface.GUIButton guibBan;
	UPROPERTY(EditAnywhere)								UGUIButton*					guibUnbanPlayer;				//var() XInterface.GUIButton guibUnbanPlayer;
	UPROPERTY(EditAnywhere)								UmoComboBox*				mcbBanType;						//var() XInterface.moComboBox mcbBanType;
	UPROPERTY(EditAnywhere)								UmoComboBox*				mcbBanLength;					//var() XInterface.moComboBox mcbBanLength;
	UPROPERTY(EditAnywhere)								UGUIListBox*				guilbBanList;					//var() XInterface.GUIListBox guilbBanList;
	UPROPERTY(EditAnywhere)								UGUILabel*					guilBanListTitle;				//var() XInterface.GUILabel guilBanListTitle;
	UPROPERTY(EditAnywhere)								UGUIListBox*				guilbPlayersList;				//var() XInterface.GUIListBox guilbPlayersList;
	UPROPERTY(EditAnywhere)								UGUILabel*					guilPlayerListTitle;			//var() XInterface.GUILabel guilPlayerListTitle;
	UPROPERTY(EditAnywhere)								UGUILabel*					guilInstructions;				//var() XInterface.GUILabel guilInstructions;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void InitializeDataFields();
	void OnPlayerListDrawItem(UCanvas* Canvas, int32 iItemIndex, float fpX, float fpY, float fpWidth, float fpHeight, bool bSelected, bool bPending);
	void OnSpectatorListDrawItem(UCanvas* Canvas, int32 iItemIndex, float fpX, float fpY, float fpWidth, float fpHeight, bool bSelected, bool bPending);
	void DrawListItem(UGUIListBox* guilb, UCanvas* Canvas, int32 iItemIndex, float fpX, float fpY, float fpWidth, float fpHeight, bool bSelected, bool bPending);
	void RefreshPlayerList();
	void ComparePlayerListItems(FGUIListElem* ElemA, FGUIListElem* ElemB);
	void Timer();
	void IsAdmin();
	bool CanShowPanel();
	bool ButtonClick(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	bool OnPlayerListClick(UGUIComponent* Sender);
	void NotifyCustomParameters(FString sParam1, FString sParam2, FString sParam3);
	void FindPRIFromID(int32 iPlayerID);

};
