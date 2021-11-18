// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageBase.h"
#include "Browser_ServerListPageMS.generated.h"

class AMasterServerClient;

UCLASS()
class AA29_API UBrowser_ServerListPageMS : public UBrowser_ServerListPageBase
{
	GENERATED_BODY()
public:
	UBrowser_ServerListPageMS();

	UPROPERTY()				FString					GameType;							//var() FString GameType;
	UPROPERTY()				AMasterServerClient*	MSC;								//var() IpDrv.MasterServerClient MSC;
	UPROPERTY()				bool					bStarted;							//var() bool bStarted;
	UPROPERTY()				FString					QueryFinHead;						//var localized FString QueryFinHead;
	UPROPERTY()				FString					QueryFinTail;						//var localized FString QueryFinTail;
	UPROPERTY()				FString					PingRecvString;						//var localized FString PingRecvString;
	UPROPERTY()				FString					MustUpgradeString;					//var localized FString MustUpgradeString;
	UPROPERTY()				FString					RefreshFinHead;						//var localized FString RefreshFinHead;
	UPROPERTY()				FString					RefreshFinMid;						//var localized FString RefreshFinMid;
	UPROPERTY()				FString					RefreshFinTail;						//var localized FString RefreshFinTail;
	UPROPERTY()				FString					RePingServersCaption;				//var localized FString RePingServersCaption;
	UPROPERTY()				FString					RefreshCaption;						//var localized FString RefreshCaption;


	void AddQueryTerm(FString Key, FString GameType, EQueryType QueryType);
	void RefreshList();
	void ShowPanel(bool bShow);
	void OnCloseBrowser();
	void PingServer(int32 ListID, EPingCause PingCause, FServerResponseLine S);
	void CancelPings();
	void UpdateStatusPingCount();
	void MyReceivedPingInfo(int32 ServerID, EPingCause PingCause, FServerResponseLine S);
	void MyPingTimeout(int32 ListID, EPingCause PingCause);
	void MyQueryFinished(EResponseInfo ResponseInfo, int32 Info);
	bool MyRePing(UGUIComponent* Sender);
	bool MyRefreshClick(UGUIComponent* Sender);
	void InitComponent(UGUIController* C, UGUIComponent* O);

};
