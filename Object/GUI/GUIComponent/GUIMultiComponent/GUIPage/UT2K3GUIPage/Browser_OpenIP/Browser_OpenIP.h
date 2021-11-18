// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2K3GUIPage.h"
#include "Browser_OpenIP.generated.h"

class UmoEditBox;
class UBrowser_ServerListPageFavorites;

UCLASS()
class AA29_API UBrowser_OpenIP : public UUT2K3GUIPage
{
	GENERATED_BODY()
public:
	UBrowser_OpenIP();

	UPROPERTY()				UmoEditBox*							MyIpAddress;					//var moEditBox MyIpAddress;
	UPROPERTY()				UBrowser_ServerListPageFavorites*	MyFavoritesPage;				//var Browser_ServerListPageFavorites MyFavoritesPage;

	void InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
};
