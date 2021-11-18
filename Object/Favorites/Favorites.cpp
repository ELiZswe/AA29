// All the original content belonged to the US Army


#include "AA29/Object/Favorites/Favorites.h"

UFavorites::UFavorites()
{

}


void UFavorites::dOnFavoritesOperationComplete(int32 Result, FString Message)
{
}

void UFavorites::OnSuccessfulUpdate()
{
}

bool UFavorites::StringToFavoriteServer(FFavoriteServer& Server, FString IPAddress)
{
	/*
	local InternetLink.IpAddr IpAddr;
	local int Quad;
	local int PortPos;
	Server.IPAddress = "";
	Server.Port = 1716;
	PortPos = InStr(IPAddress, ":");
	if (-1 != PortPos)
	{
		if (PortPos + 1 != Len(IPAddress))
		{
			Server.Port = Mid(IPAddress, PortPos + 1);
		}
		IPAddress = Left(IPAddress, PortPos);
	}
	if (Class'InternetLink'.StringToIpAddr(IPAddress, IpAddr) && Server.Port > 0)
	{
		Quad = IpAddr.Addr >> 24 & 255;
		Server.IPAddress = Quad $ ".";
		Quad = IpAddr.Addr >> 16 & 255;
		Server.IPAddress $ = Quad $ ".";
		Quad = IpAddr.Addr >> 8 & 255;
		Server.IPAddress $ = Quad $ ".";
		Quad = IpAddr.Addr >> 0 & 255;
		Server.IPAddress $ = Quad;
		return true;
	}
	*/
	return false;
}

void UFavorites::NumFavoriteServers()
{
	//Return FavoriteServers.Length;
}

void UFavorites::GetFavoriteServer(int32 Index)
{
	//Return FavoriteServers[Index];
}

void UFavorites::MakeFavoriteServersFilter(FString UserName)
{
	/*
	local array<ServerBrowserBase.FilterItem> FilterList;
	FilterList.Length = 1;
	FilterList[0].Key = "serverListFilter";
	FilterList[0].Value = UserName;
	Return FilterList;
	*/
}

int32 UFavorites::GetIndexOfFavoriteServer(FFavoriteServer Server)
{
	/*
	local int Index;
	for (Index = 0; Index < FavoriteServers.Length; Index++)
	{
		if (Server == FavoriteServers[Index])
		{
			Return Index;
		}
	}
	*/
	return -1;
}

void UFavorites::InternalOnUpdateFavoritesRequestComplete(int32 ResultCode)
{
	/*
	local FString Message;
	if (1 == ResultCode)
	{
		OnSuccessfulUpdate();
	}
	else
	{
		Message = 'CommunicationRequestAdapter'.GetErrorMessage(ResultCode);
	}
	dOnFavoritesOperationComplete(ResultCode, Message);
	__dOnFavoritesOperationComplete__Delegate = None;
	bUpdateInProgress = False;
	*/
}

void UFavorites::InternalOnSuccessfulUpdate_AddServer()
{
	/*
	Assert(Len(PendingServer.IPAddress) > 0 && PendingServer.Port > 0);
	FavoriteServers[FavoriteServers.Length] = PendingServer;
	PendingServer.IPAddress = "";
	PendingServer.Port = 0;
	__OnSuccessfulUpdate__Delegate = None;
	*/
}

void UFavorites::InternalOnSuccessfulUpdate_RemoveServer()
{
	/*
	local int Index;
	Assert(Len(PendingServer.IPAddress) > 0 && PendingServer.Port > 0);
	Index = GetIndexOfFavoriteServer(PendingServer);
	if (-1 != Index)
	{
		FavoriteServers.remove(Index, 1);
	}
	PendingServer.IPAddress = "";
	PendingServer.Port = 0;
	__OnSuccessfulUpdate__Delegate = None;
	*/
}

void UFavorites::InternalOnSuccessfulUpdate_AddBattleBuddy()
{
	/*
	Assert(Len(PendingBuddy) > 0);
	BattleBuddies[BattleBuddies.Length] = PendingBuddy;
	PendingBuddy = "";
	__OnSuccessfulUpdate__Delegate = None;
	*/
}

void UFavorites::InternalOnSuccessfulUpdate_RemoveBattleBuddy()
{
	/*
	local int Index;
	Assert(Len(PendingBuddy) > 0);
	Index = GetIndexOfBattleBuddy(PendingBuddy);
	if (-1 != Index)
	{
		BattleBuddies.remove(Index, 1);
	}
	PendingBuddy = "";
	__OnSuccessfulUpdate__Delegate = None;
	*/
}

void UFavorites::SpawnRequest(AActor* SpawnActor)
{
	/*
	local UpdateFavoritesRequestAdapter UpdateRequest;
	if (bUpdateInProgress)
	{
		Log("Attempting Favorites update while update is in progress.");
	}
	bUpdateInProgress = True;
	UpdateRequest = SpawnActor.Spawn('UpdateFavoritesRequestAdapter');
	UpdateRequest.__dOnUpdateFavoritesRequestComplete__Delegate = InternalOnUpdateFavoritesRequestComplete;
	Return UpdateRequest;
	*/
}

void UFavorites::AddFavoriteServer(FFavoriteServer Server, FString UserName, FString Password, AActor* ActorToSpawnWith)
{
	/*
	local UpdateFavoritesRequestAdapter AddRequest;
	if (-1 == GetIndexOfFavoriteServer(Server))
	{
		PendingServer = Server;
		__OnSuccessfulUpdate__Delegate = InternalOnSuccessfulUpdate_AddServer;
		AddRequest = SpawnRequest(ActorToSpawnWith);
		AddRequest.AddServer(UserName, Password, Server.IPAddress $ ":" $ Server.Port);
	}
	else
	{
		InternalOnUpdateFavoritesRequestComplete(-63);
	}
	*/
}

void UFavorites::RemoveFavoriteServer(FFavoriteServer Server, FString UserName, FString Password, AActor* ActorToSpawnWith)
{
	/*
	local int Index;
	local UpdateFavoritesRequestAdapter RemoveRequest;
	Index = GetIndexOfFavoriteServer(Server);
	if (-1 != Index)
	{
		PendingServer = Server;
		__OnSuccessfulUpdate__Delegate = InternalOnSuccessfulUpdate_RemoveServer;
		RemoveRequest = SpawnRequest(ActorToSpawnWith);
		RemoveRequest.RemoveServer(UserName, Password, Server.IPAddress $ ":" $ Server.Port);
	}
	else
	{
		InternalOnUpdateFavoritesRequestComplete(-64);
	}
	*/
}

void UFavorites::NumBattleBuddies()
{
	//Return BattleBuddies.Length;
}

void UFavorites::GetBattleBuddy(int32 Index)
{
	/*
	if (Index < 0 || Index >= BattleBuddies.Length)
	{
		Return "";
	}
	Return BattleBuddies[Index];
	*/
}

void UFavorites::MakeBattleBuddyFilter(FString UserName)
{
	/*
	local array<ServerBrowserBase.FilterItem> FilterList;
	FilterList.Length = 1;
	FilterList[0].Key = "buddyListFilter";
	FilterList[0].Value = UserName;
	Return FilterList;
	*/
}

int32 UFavorites::GetIndexOfBattleBuddy(FString Buddy)
{
	/*
	local int Index;
	for (Index = 0; Index < BattleBuddies.Length; Index++)
	{
		if (Buddy ~= BattleBuddies[Index])
		{
			Return Index;
		}
	}
	*/
	return -1;
}

void UFavorites::AddBattleBuddy(FString Buddy, FString UserName, FString Password, AActor* ActorToSpawnWith)
{
	/*
	local UpdateFavoritesRequestAdapter AddRequest;
	if (-1 == GetIndexOfBattleBuddy(Buddy))
	{
		PendingBuddy = Buddy;
		__OnSuccessfulUpdate__Delegate = InternalOnSuccessfulUpdate_AddBattleBuddy;
		AddRequest = SpawnRequest(ActorToSpawnWith);
		AddRequest.AddBuddy(UserName, Password, Buddy);
	}
	else
	{
		InternalOnUpdateFavoritesRequestComplete(-53);
	}
	*/
}

void UFavorites::RemoveBattleBuddy(FString Buddy, FString UserName, FString Password, AActor* ActorToSpawnWith)
{
	/*
	local int Index;
	local UpdateFavoritesRequestAdapter RemoveRequest;
	Index = GetIndexOfBattleBuddy(Buddy);
	if (-1 != Index)
	{
		PendingBuddy = Buddy;
		__OnSuccessfulUpdate__Delegate = InternalOnSuccessfulUpdate_RemoveBattleBuddy;
		RemoveRequest = SpawnRequest(ActorToSpawnWith);
		RemoveRequest.RemoveBuddy(UserName, Password, Buddy);
	}
	else
	{
		InternalOnUpdateFavoritesRequestComplete(-54);
	}
	*/
}

void UFavorites::InternalOnGetFavoritesRequestComplete(int32 ResultCode, TArray<FString> BuddyList, TArray<FString> serverList)
{
	/*
	local int Index;
	local FString IPAddress;
	local FString Port;
	if (ResultCode != 1)
	{
		Log("Failed to refresh favorites from server." @ ResultCode);
		BattleBuddies.Length = 0;
		FavoriteServers.Length = 0;
		Return;
	}
	BattleBuddies = BuddyList;
	FavoriteServers.Length = serverList.Length;
	for (Index = 0; Index < serverList.Length; Index++)
	{
		Divide(serverList[Index], ":", IPAddress, Port);
		FavoriteServers[Index].IPAddress = IPAddress;
		FavoriteServers[Index].Port = Port;
	}
	*/
}

void UFavorites::RefreshFavoritesFromServer(FString UserName, FString Password, AActor* ActorToSpawnWith)
{
	/*
	local GetFavoritesRequestAdapter Adapter;
	Adapter = ActorToSpawnWith.Spawn('GetFavoritesRequestAdapter');
	Adapter.__dOnGetFavoritesRequestComplete__Delegate = InternalOnGetFavoritesRequestComplete;
	Adapter.Request(UserName, Password);
	*/
}