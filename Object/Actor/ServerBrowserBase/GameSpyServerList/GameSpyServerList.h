// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"
#include "GameSpyServerList.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AGameSpyServerList : public AServerBrowserBase
{
	GENERATED_BODY()
public:
	AGameSpyServerList();

	UPROPERTY()		Fpointer	m_serverlist;				//var const transient Fpointer m_serverlist;
	UPROPERTY()		int32		iProgress;					//var int32 iProgress;
	UPROPERTY()		bool		bInternet;					//var bool bInternet;
	UPROPERTY()		bool		bDisplayWhenDone;			//var bool bDisplayWhenDone;
	UPROPERTY()		bool		bWorking;					//var bool bWorking;
	UPROPERTY()		FString		sCurrentFilter;				//var FString sCurrentFilter;
	UPROPERTY()		FString		FilterString;				//var globalconfig FString FilterString;
	UPROPERTY()		bool		bSortSaved;					//var bool bSortSaved;
	UPROPERTY()		FString		sSortField;					//var FString sSortField;
	UPROPERTY()		bool		bSortAscending;				//var bool bSortAscending;
	UPROPERTY()		int32		iSelectedServer;			//var int32 iSelectedServer;
	UPROPERTY()		int32		fLastSelServerUpdate;		//var float fLastSelServerUpdate;

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
	void AllServers(FGameSpyServerItem& Item);
	void AllServersInRange(FGameSpyServerItem& Item, int32 MinRange, int32 MaxRange);
	void GetSpecificServerNative(int32 Index, FGameSpyServerItem& Item);
	void GetSpecificServer(int32 Index, FGameSpyServerItem& Item);
	void GameSpyInit();
	void GameSpyClearList();
	void GameSpyStartRefresh();
	void GameSpyStatusDone();
	void Tick(float DeltaTime);
	void Timer();
	void DisplayServerList();
	int32 GetNumServers();
	void SortServers(FString sField, bool bAscending, EGameSpyCompareMode eType);
	void SetFilter(FString sFilter);
	void SetSelectedServer(int32 Index);
	int32 GetProgress();
	void SetPublic(bool bPublic);
	FString GetConnectingMessage();
};
