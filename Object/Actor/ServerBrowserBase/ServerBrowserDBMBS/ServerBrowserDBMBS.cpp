// All the original content belonged to the US Army

#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserDBMBS/ServerBrowserDBMBS.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/MBSGetServerListRequestAdapter/MBSGetServerListRequestAdapter.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/MBSGetServerInfoRequestAdapter/MBSGetServerInfoRequestAdapter.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/MBSPingServerRequestAdapter/MBSPingServerRequestAdapter.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"
#include "AA29/Object/ServerListSorter/ServerListSorter.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/MBSGetServerInfoRequestAdapter/MBSGetServerInfoRequestAdapter.h"

AServerBrowserDBMBS::AServerBrowserDBMBS()
{
	MaxSimultaneousAutopings = -1;
}

//const INVALID_SERVER_INDEX = -1;
//const MIN_TIME_BETWEEN_PINGS = 120;

void AServerBrowserDBMBS::PostBeginPlay()
{
	/*
	int32 ConfiguredInternetSpeed = 0;
	Super::PostBeginPlay();
	if (MaxSimultaneousAutopings == -1)
	{
		ConfiguredInternetSpeed = Class'Player'.Default.ConfiguredInternetSpeed;
		if (ConfiguredInternetSpeed <= 2600)
		{
			SimultaneousPingLimit = 10;
		}
		else
		{
			if (ConfiguredInternetSpeed <= 5000)
			{
				SimultaneousPingLimit = 15;
			}
			else
			{
				if (ConfiguredInternetSpeed <= 10000)
				{
					SimultaneousPingLimit = 20;
				}
				else
				{
					SimultaneousPingLimit = 35;
				}
			}
		}
	}
	else
	{
		SimultaneousPingLimit = MaxSimultaneousAutopings;
	}
	*/
}

bool AServerBrowserDBMBS::IsSupportsFavorites()
{
	return true;
}

void AServerBrowserDBMBS::UpdateServerList()
{
	/*
	DebugLog(DEBUG_Auth, "ServerBrowserDBMBS::UpdateServerList()");
	if (None == GetServerListRequest)
	{
		GetServerListRequest = Spawn(AMBSGetServerListRequestAdapter::StaticClass(), this);
		GetServerListRequest.SetFilterList(FilterList);
		GetServerListRequest.Request();
	}
	else
	{
		DebugLog(DEBUG_Auth, "ServerBrowserDBMBS::UpdateServerList Deprecating old request to update list.");
		GetServerListRequest.SetOwner(nullptr);
		GetServerListRequest = Spawn(AMBSGetServerListRequestAdapter::StaticClass(), this);
		GetServerListRequest.SetFilterList(FilterList);
		GetServerListRequest.Request();
	}
	*/
}

int32 AServerBrowserDBMBS::GetUpdateServerListProgressAsByteCount()
{
	/*
	if (None != GetServerListRequest)
	{
		return GetServerListRequest.BytesReceived;
	}
	else
	{
		Log("GetUpdateServerListProgressAsByteCount called while not updating a server list!");
	}
	*/
	return 0;
}

void AServerBrowserDBMBS::SetServerList(TArray<FGameSpyServerItem> List)
{
	/*
	DebugLog(DEBUG_Auth, "ServerBrowserDBMBS::SetServerList (" + FString::FromInt(List.Num()) @ "servers)");
	serverList = List;
	PlayerLists.Num() = serverList.Num();
	ResetAutoPingSystem();
	AutopingServers();
	OnReceivedServer(0);
	*/
}

void AServerBrowserDBMBS::ResetAutoPingSystem()
{
	/*
	OutstandingPings.Num() = 0;
	AutopingStartIndex = 0;
	*/
}

FString AServerBrowserDBMBS::GetFailureReason(int32 ResultCode)
{
	/*
	switch (ResultCode)
	{
	case -4:
		return "Failed to connect to AA Browser master server.";
		break;
	default:
		return "Failed to obtain server list from AA Browser server.";
		break;
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

void AServerBrowserDBMBS::UpdateServerListFailed(int32 ResultCode)
{
	/*
	FString Reason = "";
	serverList.Num() = 0;
	PlayerLists.Num() = 0;
	Reason = GetFailureReason(ResultCode);
	OnUpdateServerListFailed(Reason);
	*/
}

int32 AServerBrowserDBMBS::GetServerIndex(int32 IP, int32 HostPort)
{
	/*
	int32 Index = 0;
	for (Index = 0; Index < serverList.Num(); Index++)
	{
		if ((serverList[Index].Port == HostPort) && (serverList[Index].IP == IP))
		{
			return Index;
		}
	}
	*/
	return -1;
}

void AServerBrowserDBMBS::SetPlayerList(int32 ServerIP, int32 ServerHostPort, TArray<FGameSpyPlayerInfo> List)
{
	/*
	int32 ServerIndex = 0;
	DebugLog(DEBUG_Auth, FString::FromInt(List.Num()) @ "players obtained for" @ FString::FromInt(ServerIP) + ":" + FString::FromInt(ServerHostPort));
	ServerIndex = GetServerIndex(ServerIP, ServerHostPort);
	if (-1 != ServerIndex)
	{
		PlayerLists[ServerIndex].players = List;
		serverList[ServerIndex].NumPlayers = List.Num();
		OnReceivedPlayerList(List.Num());
	}
	else
	{
		DebugLog(DEBUG_Auth, "Failed to find server for player list." @ FString::FromInt(ServerIP) + ":" + FString::FromInt(ServerHostPort));
	}
	*/
}

void AServerBrowserDBMBS::GetSpecificServer(int32 Index, FGameSpyServerItem& Item)
{
	/*
	if (Index < serverList.Num())
	{
		Item = serverList[Index];
	}
	*/
}

void AServerBrowserDBMBS::SuppressPings()
{
	bSuppressPings = true;
}

void AServerBrowserDBMBS::UnsuppressPings()
{
	bSuppressPings = false;
}

void AServerBrowserDBMBS::RefreshSpecificServer(int32 iIndex)
{
	AMBSGetServerInfoRequestAdapter* GetServerInfoRequest = nullptr;
	/*
	FString IPAddress = "";
	if (iIndex < serverList.Num())
	{
		PingSpecificServer(iIndex, true);
		GetServerInfoRequest = Spawn(AMBSGetServerInfoRequestAdapter::StaticClass(), this);
		IPAddress = IpAddrToString(serverList[iIndex].IP, 0);
		IPAddress = Left(IPAddress, (Len(IPAddress) - 2));
		GetServerInfoRequest.Request(IPAddress, serverList[iIndex].QueryPort);
	}
	else
	{
		DebugLog(DEBUG_Auth, "ServerBrowserDBMBS::RefreshSpecificServer Ignoring request to update server with out of range index.");
	}
	*/
}

void AServerBrowserDBMBS::AutopingServers()
{
	int32 Index = 0;
	if (bSuppressPings)
	{
		return;
	}
	Index = AutopingStartIndex;
	/*
	if ((Index < serverList.Num()) && (OutstandingPings.Num() < SimultaneousPingLimit))
	{
		if ((9999 == serverList[Index].Ping) && (-1 == GetOutstandingPingIndex(Index)))
		{
			AutopingStartIndex = (Index + 1);
			DebugLog(DEBUG_Auth, "Autopinging" @ IpAddrToString(serverList[Index].IP, serverList[Index].Port) @ FString::FromInt(serverList[Index].Ping) @ FString::FromInt(GetOutstandingPingIndex(Index)));
			PingSpecificServer(Index, true);
		}
		(++Index);
	}
	*/
}

//native Function int32 GetOutstandingPingIndex(int32 ServerListIndex);
int32 AServerBrowserDBMBS::GetOutstandingPingIndex(int32 ServerListIndex)
{
	return 0;     //FAKE   /EliZ
}

int32 AServerBrowserDBMBS::AddOutstandingPing(int32 ServerListIndex)
{
	int32 OutstandingPingsIndex = 0;
	/*
	OutstandingPingsIndex = GetOutstandingPingIndex(ServerListIndex);
	if (OutstandingPingsIndex == -1)
	{
		OutstandingPings.Num() = (OutstandingPings.Num() + 1);
		OutstandingPingsIndex = (OutstandingPings.Num() - 1);
		OutstandingPings[OutstandingPingsIndex].IP = serverList[ServerListIndex].IP;
		OutstandingPings[OutstandingPingsIndex].Port = serverList[ServerListIndex].Port;
		OutstandingPings[OutstandingPingsIndex].TimeOfLastPing = GetWorld()->GetTimeSeconds();
	}
	*/
	return OutstandingPingsIndex;
}

void AServerBrowserDBMBS::PingSpecificServer(int32 ServerListIndex, bool PingImmediately)
{
	/*
	FString IPAddress = "";
	int32 OutstandingPingsIndex = 0;
	if (bSuppressPings)
	{
		return;
	}
	OutstandingPingsIndex = GetOutstandingPingIndex(ServerListIndex);
	if (OutstandingPingsIndex == -1)
	{
		OutstandingPingsIndex = AddOutstandingPing(ServerListIndex);
		PingImmediately = true;
	}
	if (OutstandingPings[OutstandingPingsIndex].Request == nullptr)
	{
		if (PingImmediately || ((GetWorld()->GetTimeSeconds() - OutstandingPings[OutstandingPingsIndex].TimeOfLastPing) > float(120)))
		{
			OutstandingPings[OutstandingPingsIndex].Request = Spawn(AMBSPingServerRequestAdapter::StaticClass(), this);
			IPAddress = IpAddrToString(serverList[ServerListIndex].IP, 0);
			IPAddress = Left(IPAddress, (Len(IPAddress) - 2));
			OutstandingPings[OutstandingPingsIndex].Request.Request(IPAddress, serverList[ServerListIndex].QueryPort, serverList[ServerListIndex].Port);
			OutstandingPings[OutstandingPingsIndex].TimeOfLastPing = GetWorld()->GetTimeSeconds();
		}
	}
	*/
}

void AServerBrowserDBMBS::PingSpecificServerComplete(int32 ServerIP, int32 ServerHostPort)
{
	/*
	int32 Index = 0;
	Index = 0;
	if (((Index < OutstandingPings.Num()) && (OutstandingPings[Index].IP != ServerIP)) && (OutstandingPings[Index].Port != ServerHostPort))
	{
		(++Index);
	}
	if (Index < OutstandingPings.Num())
	{
		OutstandingPings.RemoveAt(Index, 1);
	}
	else
	{
		DebugLog(DEBUG_Auth, "PingSpecificServerComplete called for server not in OutstandingPings list of length" @ FString::FromInt(OutstandingPings.Num()) @ FString::FromInt(ServerIP) + ":" + FString::FromInt(ServerHostPort));
	}
	AutopingServers();
	*/
}

void AServerBrowserDBMBS::SetPingTime(int32 ServerIP, int32 ServerHostPort, int32 PingTimeMS)
{
	/*
	int32 ServerIndex = 0;
	DebugLog(DEBUG_Auth, FString::FromInt(PingTimeMS) @ "ping time measured for" @ IpAddrToString(ServerIP, ServerHostPort));
	ServerIndex = GetServerIndex(ServerIP, ServerHostPort);
	if (-1 != ServerIndex)
	{
		serverList[ServerIndex].Ping = PingTimeMS;
	}
	else
	{
		DebugLog(DEBUG_Auth, "Failed to find server for received ping time." @ IpAddrToString(ServerIP, ServerHostPort));
	}
	PingSpecificServerComplete(ServerIP, ServerHostPort);
	*/
}

int32 AServerBrowserDBMBS::GetNumServers()
{
	//return serverList.Num();
	return 0;     //FAKE   /EliZ
}

int32 AServerBrowserDBMBS::GetProgress()
{
	/*
	if (None == GetServerListRequest)
	{
		return 100;
	}
	else
	{
		return 0;
	}
	*/

	return 0;    //FAKE   /ELiZ
}

void AServerBrowserDBMBS::GetPlayerInfo(int32 ServerIndex, int32 PlayerIndex, FGameSpyPlayerInfo& PlayerInfo)
{
	/*
	if ((ServerIndex < PlayerLists.Num()) && (PlayerIndex < PlayerLists[ServerIndex].players.Num()))
	{
		PlayerInfo = PlayerLists[ServerIndex].players[PlayerIndex];
	}
	else
	{
		PlayerInfo.Name = "";
		PlayerInfo.Enemy = 0;
		PlayerInfo.KIA = 0;
		PlayerInfo.ROE = 0;
		PlayerInfo.Ping = 0;
	}
	*/
}

void AServerBrowserDBMBS::SetFilterList(TArray<FFilterItem> List)
{
	/*
	if (Level.debugThis(20))
	{
		AServerBrowserBase::StaticClass().DebugDumpFilterList(List);
	}
	FilterList = List;
	*/
}

void AServerBrowserDBMBS::SortServers(FString Field, bool Ascending, EGameSpyCompareMode Type)
{
	//UServerListSorter::StaticClass().SortServerList(serverList, Field, Ascending);
	//ResetAutoPingSystem();
}
