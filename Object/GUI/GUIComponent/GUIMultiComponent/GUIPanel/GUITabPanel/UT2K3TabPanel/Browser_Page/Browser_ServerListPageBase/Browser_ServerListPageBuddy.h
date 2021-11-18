// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageMS.h"
#include "Browser_ServerListPageBuddy.generated.h"

class UGUISplitter;
class UBrowser_BuddyList;

UCLASS(Config = Game)
class AA29_API UBrowser_ServerListPageBuddy : public UBrowser_ServerListPageMS
{
	GENERATED_BODY()
public:
	UBrowser_ServerListPageBuddy();

	UPROPERTY(config)		TArray<FString>				Buddies;				//var() config TArray<FString> Buddies;
	UPROPERTY()				UGUISplitter*				MainSplit;				//var GUISplitter MainSplit;
	UPROPERTY()				UGUISplitter*				BudSplit;				//var GUISplitter BudSplit;
	UPROPERTY()				UBrowser_BuddyList*			MyBuddyList;			//var Browser_BuddyList MyBuddyList;
	UPROPERTY()				FString						AddBuddyCaption;		//var localized FString AddBuddyCaption;
	UPROPERTY()				FString						RemoveBuddyCaption;		//var localized FString RemoveBuddyCaption;
	UPROPERTY()				bool						BuddyInitialized;		//var bool BuddyInitialized;

	void InitComponent(UGUIController* C, UGUIComponent* O);
	bool MyRefreshClick(UGUIComponent* Sender);
	void RefreshList();
	bool AddBuddyClick(UGUIComponent* Sender);
	bool RemoveBuddyClick(UGUIComponent* Sender);
};
