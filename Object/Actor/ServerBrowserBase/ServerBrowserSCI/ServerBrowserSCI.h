// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"
#include "ServerBrowserSCI.generated.h"

class ATcpLinkSCI;
class AUdpLinkSCI;

UCLASS()
class AA29_API AServerBrowserSCI : public AServerBrowserBase
{
	GENERATED_BODY()
public:
	AServerBrowserSCI();

	UPROPERTY()		TArray<FGameSpyServerItem>				serverList;					//var TArray<ServerBrowserBase.GameSpyServerItem> serverList;
	UPROPERTY()		TArray<FGameSpyPlayerInfo>				PlayerList;					//var TArray<ServerBrowserBase.GameSpyPlayerInfo> PlayerList;
	UPROPERTY()		ATcpLinkSCI*							link;						//var TcpLinkSCI link;
	UPROPERTY()		AUdpLinkSCI*							pinger;						//var UdpLinkSCI pinger;
	UPROPERTY()		FString									filterxml;					//var FString filterxml;
	UPROPERTY()		int32									specificServer;				//var int32 specificServer;
	UPROPERTY()		bool									bNewServerQueryPending;		//var bool bNewServerQueryPending;
	UPROPERTY()		bool									bDisplayWhenDone;			//var bool bDisplayWhenDone;
	UPROPERTY()		int32									responseBytesProcessed;		//var int32 responseBytesProcessed;
	UPROPERTY()		int32									expectedServers;			//var int32 expectedServers;
	UPROPERTY()		bool									bSortSaved;					//var bool bSortSaved;
	UPROPERTY()		FString									sSortField;					//var FString sSortField;
	UPROPERTY()		bool									bSortAscending;				//var bool bSortAscending;

	void PreBeginPlay();
	void Destroyed();
	void DoMasterServerQuery(int32 specific);
	void UpdateServerList();
	void RefreshServerList();
	void RePingAllServers();
	void RefreshSpecificServer(int32 iIndex);
	void GetPlayerInfo(int32 server_index, int32 player_index, FGameSpyPlayerInfo& player_info);
	void GetSpecificServer(int32 Index, FGameSpyServerItem& Item);
	void GameSpyInit();
	void GameSpyClearList();
	int32 cmpfn(int32 one, int32 two);
	void swapfn(int32 one, int32 two);
	void doServerBubbleSort(int32 lo, int32 hi);
	void doServerQuickSort(int32 lo, int32 hi);
	int32 cmpHostnameAscending(int32 one, int32 two);
	int32 cmpMapnameAscending(int32 one, int32 two);
	int32 cmpNumPlayersAscending(int32 one, int32 two);
	int32 cmpPingAscending(int32 one, int32 two);
	int32 cmpHostnameDescending(int32 one, int32 two);
	int32 cmpMapnameDescending(int32 one, int32 two);
	int32 cmpNumPlayersDescending(int32 one, int32 two);
	int32 cmpPingDescending(int32 one, int32 two);
	void doServerListSort(FString sField, bool bAscending, EGameSpyCompareMode eType);
	void GameSpyStatusDone();
	int32 GetProgress();
	void DisplayServerList();
	int32 GetNumServers();
	void SortServers(FString sField, bool bAscending, EGameSpyCompareMode eType);
	void SetFilter(FString sFilter);
	void SetSelectedServer(int32 Index);
	void SetPublic(bool bPublic);
	void parseServerCountResponse(FString responseString);
	bool GetNextXMLBlock(FString& xml, FString& Key, FString& bLock);
	void handleServerProp(FString Key, FString Value, FGameSpyServerItem& Item);
	void parseServerPropertiesXML(FString xml, FGameSpyServerItem& Item);
	void parsePlayerPropertiesXML(FString xml, int32 idx);
	void parsePlayerXML(FString xml, int32 idx);
	void parsePlayersXML(FString xml);
	void parseOneServer(FString oneServer);
	void parseServerListResponse(FString& responseString);
	void parseServerListResponseByValue(FString responseString);
	void doRequestServerList();
	void Tick(float DeltaTime);
	void HandlePings();
	FString GetConnectingMessage();
};
