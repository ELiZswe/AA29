// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageMS.h"
#include "AABrowser_ServerListPageBuddy.generated.h"

class UAABrowser_BuddyListBox;
class UAABrowser_BuddyList;

/**
 * 
 */
UCLASS(Config = Game)
class AA29_API UAABrowser_ServerListPageBuddy : public UAABrowser_ServerListPageMS
{
	GENERATED_BODY()
public:
	UAABrowser_ServerListPageBuddy();

	UPROPERTY(EditAnywhere, config)			float						BuddySplitterPosition;		//var() config float BuddySplitterPosition;
	UPROPERTY(EditAnywhere, config)			TArray<FString>				Buddies;					//var() config TArray<FString> Buddies;
	UPROPERTY(EditAnywhere, config)			FString						BuddyListBoxClass;			//var() config FString BuddyListBoxClass;
	UPROPERTY()								UGUISplitter*				sp_Buddy;					//var XInterface.GUISplitter sp_Buddy;
	UPROPERTY()								UAABrowser_BuddyListBox*	lb_Buddy;					//var AABrowser_BuddyListBox lb_Buddy;
	UPROPERTY()								UAABrowser_BuddyList*		li_Buddy;					//var AABrowser_BuddyList li_Buddy;
	UPROPERTY()								FString						AddBuddyCaption;			//var localized FString AddBuddyCaption;
	UPROPERTY()								FString						AddBuddyLabel;				//var localized FString AddBuddyLabel;
	UPROPERTY()								FString						RemoveBuddyCaption;			//var localized FString RemoveBuddyCaption;
	UPROPERTY()								FString						BuddyNameCaption;			//var localized FString BuddyNameCaption;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Opened(UGUIComponent* Sender);
	void ShowPanel(bool bShow);
	void Refresh();
	void BuddyListChanged(UGUIComponent* Sender);
	void AddBuddy(FString NewBuddy);
	void BuddyPageClosed(bool bCancelled);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void InternalOnLoadINI(UGUIComponent* Sender, FString S);
	void InternalReleaseSplitter(UGUIComponent* Sender, float NewPos);
	int32 FindBuddyIndex(FString buddyName);
	void ContextSelect(UGUIContextMenu* Sender, int32 Index);
	
};
