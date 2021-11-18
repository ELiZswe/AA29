// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_Page.h"
#include "Browser_ServerListPageBase.generated.h"

class UGUITitleBar;
class UBrowser_ServersList;

UCLASS()
class AA29_API UBrowser_ServerListPageBase : public UBrowser_Page
{
	GENERATED_BODY()
public:
	UBrowser_ServerListPageBase();

	UPROPERTY()				UBrowser_ServersList*	MyServersList;		//var Browser_ServersList MyServersList;
	UPROPERTY()				bool					ConnectLAN;			//var bool ConnectLAN;
	UPROPERTY()				UGUITitleBar*			StatusBar;			//var GUITitleBar StatusBar;
	UPROPERTY()				bool					bInitialized;		//var bool bInitialized;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void RefreshList();
	void PingServer(int32 i, EPingCause PingCause, FServerResponseLine S);
	void CancelPings();
	bool BackClick(UGUIComponent* Sender);
	bool RefreshClick(UGUIComponent* Sender);
	bool JoinClick(UGUIComponent* Sender);
	bool SpectateClick(UGUIComponent* Sender);
	bool AddFavoriteClick(UGUIComponent* Sender);
};
