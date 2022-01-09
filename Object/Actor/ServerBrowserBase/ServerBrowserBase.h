// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "ServerBrowserBase.generated.h"

UCLASS()
class AServerBrowserBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AServerBrowserBase();

	void UpdateServerList();
	void RefreshServerList();
	void RefreshSpecificServer(int32 iIndex);
	void RePingAllServers();
	void CallServerListThink();
	void CallServerListSort(FString sField, bool bAscending, EGameSpyCompareMode Mode);
	void CallServerListRemoveServer(FString IP, int32 Port);
	void CallServerListClear();
	int32 CallServerListCount();
	void GetPlayerInfo(int32 server_index, int32 player_index, FGameSpyPlayerInfo& player_info);
	FString IpAddrToString(int32 Addr, int32 Port);
	void AllServers(FGameSpyServerItem& Item);
	void AllServersInRange(FGameSpyServerItem& Item, int32 MinRange, int32 MaxRange);
	void GetSpecificServer(int32 Index, FGameSpyServerItem& Item);
	void OnReceivedServer(int32 Data);
	void OnUpdateServerListFailed(FString Reason);
	void OnReceivedPlayerList(int32 ListLength);
	void GameSpyInit();
	void GameSpyClearList();
	void GameSpyStartRefresh();
	void GameSpyStatusDone();
	void OnGameSpyStatusDone();
	int32 GetProgress();
	void DisplayServerList();
	int32 GetNumServers();
	void SortServers(FString sField, bool bAscending, EGameSpyCompareMode eType);
	void SetFilter(FString sFilter);
	void SetFilterList(TArray<FFilterItem> List);
	void SetSelectedServer(int32 Index);
	void SetPublic(bool bPublic);
	bool IsSupportsFavorites();
	FString GetConnectingMessage();
	void DebugDumpFilterList(TArray<FFilterItem> List);

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
