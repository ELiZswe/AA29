// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "Browser_AddBuddy.generated.h"

class UBrowser_ServerListPageBuddy;
class UmoEditBox;

UCLASS()
class AA29_API UBrowser_AddBuddy : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UBrowser_AddBuddy();

	UPROPERTY()				UmoEditBox*						MyNewBuddy;					//var moEditBox MyNewBuddy;
	UPROPERTY()				UBrowser_ServerListPageBuddy*	MyBuddyPage;				//var Browser_ServerListPageBuddy MyBuddyPage;

	void InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
};
