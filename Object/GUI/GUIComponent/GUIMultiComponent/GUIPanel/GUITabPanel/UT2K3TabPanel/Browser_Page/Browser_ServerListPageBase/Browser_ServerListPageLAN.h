// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageBase.h"
#include "Browser_ServerListPageLAN.generated.h"

class ALANQueryClient;

UCLASS()
class AA29_API UBrowser_ServerListPageLAN : public UBrowser_ServerListPageBase
{
	GENERATED_BODY()
public:
	UBrowser_ServerListPageLAN();

	UPROPERTY()				ALANQueryClient*	LQC;						//var IpDrv.LANQueryClient LQC;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void OnCloseBrowser();
	void MyReceivedPingInfo(int32 ServerID, EPingCause PingCause, FServerResponseLine S);
	void PingServer(int32 ListID, EPingCause PingCause, FServerResponseLine S);
	void CancelPings();
	void RefreshList();
};
