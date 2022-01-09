// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"
#include "ServerBrowserDBMBS.generated.h"

class AMBSGetServerListRequestAdapter;

UCLASS()
class AServerBrowserDBMBS : public AServerBrowserBase
{
	GENERATED_BODY()
public:
	AServerBrowserDBMBS();

	UPROPERTY()		TArray<FGameSpyServerItem>				serverList;							//var TArray<ServerBrowserBase.GameSpyServerItem> serverList;
	UPROPERTY()		TArray<FPlayerList>						PlayerLists;						//var TArray<PlayerList> PlayerLists;
	UPROPERTY()		AMBSGetServerListRequestAdapter*		GetServerListRequest;				//var MBSGetServerListRequestAdapter GetServerListRequest;
	UPROPERTY()		TArray<FFilterItem>						FilterList;							//var TArray<ServerBrowserBase.FilterItem> FilterList;
	UPROPERTY()		bool									bSuppressPings;						//var bool bSuppressPings;
	UPROPERTY()		TArray<FOutstandingPing>				OutstandingPings;					//var TArray<OutstandingPing> OutstandingPings;
	UPROPERTY()		int32									MaxSimultaneousAutopings;			//var const config int32 MaxSimultaneousAutopings;
	UPROPERTY()		int32									SimultaneousPingLimit;				//var int32 SimultaneousPingLimit;
	UPROPERTY()		int32									AutopingStartIndex;					//var int32 AutopingStartIndex;


	void PostBeginPlay();
	bool IsSupportsFavorites();
	void UpdateServerList();
	int32 GetUpdateServerListProgressAsByteCount();
	void SetServerList(TArray<FGameSpyServerItem> List);
	void ResetAutoPingSystem();
	FString GetFailureReason(int32 ResultCode);
	void UpdateServerListFailed(int32 ResultCode);
	int32 GetServerIndex(int32 IP, int32 HostPort);
	void SetPlayerList(int32 ServerIP, int32 ServerHostPort, TArray<FGameSpyPlayerInfo> List);
	void GetSpecificServer(int32 Index, FGameSpyServerItem& Item);
	void SuppressPings();
	void UnsuppressPings();
	void RefreshSpecificServer(int32 iIndex);
	void AutopingServers();
	int32 GetOutstandingPingIndex(int32 ServerListIndex);
	int32 AddOutstandingPing(int32 ServerListIndex);
	void PingSpecificServer(int32 ServerListIndex, bool PingImmediately);
	void PingSpecificServerComplete(int32 ServerIP, int32 ServerHostPort);
	void SetPingTime(int32 ServerIP, int32 ServerHostPort, int32 PingTimeMS);
	int32 GetNumServers();
	int32 GetProgress();
	void GetPlayerInfo(int32 ServerIndex, int32 PlayerIndex, FGameSpyPlayerInfo& PlayerInfo);
	void SetFilterList(TArray<FFilterItem> List);
	void SortServers(FString Field, bool Ascending, EGameSpyCompareMode Type);
};
