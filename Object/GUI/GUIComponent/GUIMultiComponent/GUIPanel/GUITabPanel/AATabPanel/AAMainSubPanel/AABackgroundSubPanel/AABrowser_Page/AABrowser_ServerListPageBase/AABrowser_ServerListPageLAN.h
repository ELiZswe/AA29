// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageBase.h"
#include "AABrowser_ServerListPageLAN.generated.h"

//class ALANQueryClient;

/**
 * 
 */
UCLASS()
class AA29_API UAABrowser_ServerListPageLAN : public UAABrowser_ServerListPageBase
{
	GENERATED_BODY()
public:
	UAABrowser_ServerListPageLAN();

	//UPROPERTY()								ALANQueryClient*			LQC;				//var() IpDrv.LANQueryClient LQC;
	UPROPERTY()								FString						StoredIP;			//var() FString StoredIP;
	UPROPERTY()								FString						StoredPort;			//var() FString StoredPort;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Opened(UGUIComponent* Sender);
	void ShowPanel(bool bShow);
	void Timer();
	void Refresh();
	void RefreshList();
	void ReceivedPingInfo(int32 ServerID, EPingCause PingCause, FServerResponseLine S);
	void CancelPings();
	void PingServer(int32 ListID, EPingCause PingCause, FServerResponseLine S);
	void UpdateStatusPingCount();
	bool HasClient();
	//ALANQueryClient* GetClient();
	void OnDestroyPanel(bool bCancelled);
	void LevelChanged();
	void Free();
	void ClearQueryClient();
	void NetworkErrorClosed(bool bCancelled);
	void CheckFilterButton(bool Available);
	void RefreshSBList();

};
