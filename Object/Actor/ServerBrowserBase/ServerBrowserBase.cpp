// All the original content belonged to the US Army


#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"

// Sets default values
AServerBrowserBase::AServerBrowserBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//bHidden = true;
}

// Called when the game starts or when spawned
void AServerBrowserBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AServerBrowserBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//const GSERVER_REFRESH_TIMEOUT = 5.0;
//const COLUMN_MAP = 4;
//const COLUMN_GAME = 3;
//const COLUMN_PLAYERS = 2;
//const COLUMN_PING = 1;
//const COLUMN_NAME = 0;

//native Function UpdateServerList();
void AServerBrowserBase::UpdateServerList()
{

}

//native Function RefreshServerList();
void AServerBrowserBase::RefreshServerList()
{

}

//native Function RefreshSpecificServer(int32 iIndex);
void AServerBrowserBase::RefreshSpecificServer(int32 iIndex)
{

}

//native Function RePingAllServers();
void AServerBrowserBase::RePingAllServers()
{

}

//native Function CallServerListThink();
void AServerBrowserBase::CallServerListThink()
{

}

//native Function CallServerListSort(FString sField, bool bAscending, EGameSpyCompareMode Mode);
void AServerBrowserBase::CallServerListSort(FString sField, bool bAscending, EGameSpyCompareMode Mode)
{

}

//native Function CallServerListRemoveServer(FString IP, int32 Port);
void AServerBrowserBase::CallServerListRemoveServer(FString IP, int32 Port)
{

}

//native Function CallServerListClear();
void AServerBrowserBase::CallServerListClear()
{

}

//native Function int32 CallServerListCount();
int32 AServerBrowserBase::CallServerListCount()
{
	return 0;    //FAKE   /ELiZ
}

//native Function GetPlayerInfo(int32 server_index, int32 player_index, GameSpyPlayerInfo& player_info);
void AServerBrowserBase::GetPlayerInfo(int32 server_index, int32 player_index, FGameSpyPlayerInfo& player_info)
{

}

//native Function FString IpAddrToString(int32 Addr, int32 Port);
FString AServerBrowserBase::IpAddrToString(int32 Addr, int32 Port)
{
	return "FAKE";    //FAKE   /ELiZ
}

//native iterator Function AllServers(GameSpyServerItem& Item);
void AServerBrowserBase::AllServers(FGameSpyServerItem& Item)
{

}

//native iterator Function AllServersInRange(GameSpyServerItem& Item, int32 MinRange, int32 MaxRange);
void AServerBrowserBase::AllServersInRange(FGameSpyServerItem& Item, int32 MinRange, int32 MaxRange)
{

}
void AServerBrowserBase::GetSpecificServer(int32 Index, FGameSpyServerItem& Item)
{
}

void AServerBrowserBase::OnReceivedServer(int32 Data)
{
}

void AServerBrowserBase::OnUpdateServerListFailed(FString Reason)
{
}

void AServerBrowserBase::OnReceivedPlayerList(int32 ListLength)
{
}

void AServerBrowserBase::GameSpyInit()
{
}

void AServerBrowserBase::GameSpyClearList()
{
}

void AServerBrowserBase::GameSpyStartRefresh()
{
}

void AServerBrowserBase::GameSpyStatusDone()
{
}

void AServerBrowserBase::OnGameSpyStatusDone()
{
}

int32 AServerBrowserBase::GetProgress()
{
	return 0;    //FAKE   /ELiZ

}

void AServerBrowserBase::DisplayServerList()
{
}

int32 AServerBrowserBase::GetNumServers()
{
	return 0;    //FAKE   /ELiZ
}

void AServerBrowserBase::SortServers(FString sField, bool bAscending, EGameSpyCompareMode eType)
{
}

void AServerBrowserBase::SetFilter(FString sFilter)
{
}

void AServerBrowserBase::SetFilterList(TArray<FFilterItem> List)
{
}

void AServerBrowserBase::SetSelectedServer(int32 Index)
{
}

void AServerBrowserBase::SetPublic(bool bPublic)
{
}

bool AServerBrowserBase::IsSupportsFavorites()
{
	return false;
}

FString AServerBrowserBase::GetConnectingMessage()
{
	return "FAKE";   //FAKE    /ELiZ
}

void AServerBrowserBase::DebugDumpFilterList(TArray<FFilterItem> List)
{
	/*
	int32 Index = 0;
	Log("FilterList with" @ string(List.Length) @ "items.");
	for (Index = 0; Index < List.Length; Index++)
	{
		Log(List[Index].Key @ List[Index].Value);
	}
	*/
}
