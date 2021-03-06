// All the original content belonged to the US Army

#include "AA29/Object/Favorites/Favorites.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/UpdateFavoritesRequestAdapter/UpdateFavoritesRequestAdapter.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/InternetLink.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/GetFavoritesRequestAdapter/GetFavoritesRequestAdapter.h"

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
	FIpAddr IpAddr = FIpAddr({});
	int32 Quad = 0;
	int32 PortPos = 0;
	Server.IPAddress = "";
	Server.Port = 1716;
	/*
	PortPos = InStr(IPAddress, ":");
	if (-1 != PortPos)
	{
		if (PortPos + 1 != Len(IPAddress))
		{
			Server.Port = Mid(IPAddress, PortPos + 1);
		}
		IPAddress = Left(IPAddress, PortPos);
	}
	if (AInternetLink::StaticClass().StringToIpAddr(IPAddress, IpAddr) && Server.Port > 0)
	{
		Quad = IpAddr.Addr >> 24 & 255;
		Server.IPAddress = Quad + ".";
		Quad = IpAddr.Addr >> 16 & 255;
		Server.IPAddress += Quad + ".";
		Quad = IpAddr.Addr >> 8 & 255;
		Server.IPAddress += Quad + ".";
		Quad = IpAddr.Addr >> 0 & 255;
		Server.IPAddress += Quad;
		return true;
	}
	*/
	return false;
}

int32 UFavorites::NumFavoriteServers()
{
	return FavoriteServers.Num();
}

FFavoriteServer UFavorites::GetFavoriteServer(int32 Index)
{
	return FavoriteServers[Index];
}

TArray<FFilterItem> UFavorites::MakeFavoriteServersFilter(FString UserName)
{
	TArray<FFilterItem> FilterList = {};
	FilterList.SetNum(1);
	FilterList[0].Key = "serverListFilter";
	FilterList[0].Value = UserName;
	return FilterList;
}

int32 UFavorites::GetIndexOfFavoriteServer(FFavoriteServer Server)
{
	int32 Index = 0;
	for (Index = 0; Index < FavoriteServers.Num(); Index++)
	{
		/*
		if (Server == FavoriteServers[Index])
		{
			return Index;
		}
		*/
	}
	return -1;
}

void UFavorites::InternalOnUpdateFavoritesRequestComplete(int32 ResultCode)
{
	FString Message = "";
	if (ResultCode == 1)
	{
		OnSuccessfulUpdate();
	}
	else
	{
		//Message = 'CommunicationRequestAdapter'.GetErrorMessage(ResultCode);
	}
	dOnFavoritesOperationComplete(ResultCode, Message);
	//__dOnFavoritesOperationComplete__Delegate = nullptr;
	bUpdateInProgress = false;
}

void UFavorites::InternalOnSuccessfulUpdate_AddServer()
{
	/*
	Assert(Len(PendingServer.IPAddress) > 0 && PendingServer.Port > 0);
	FavoriteServers[FavoriteServers.Num()] = PendingServer;
	PendingServer.IPAddress = "";
	PendingServer.Port = 0;
	__OnSuccessfulUpdate__Delegate = nullptr;
	*/
}

void UFavorites::InternalOnSuccessfulUpdate_RemoveServer()
{
	/*
	int32 Index = 0;
	Assert(Len(PendingServer.IPAddress) > 0 && PendingServer.Port > 0);
	Index = GetIndexOfFavoriteServer(PendingServer);
	if (-1 != Index)
	{
		FavoriteServers.RemoveAt(Index, 1);
	}
	PendingServer.IPAddress = "";
	PendingServer.Port = 0;
	__OnSuccessfulUpdate__Delegate = nullptr;
	*/
}

void UFavorites::InternalOnSuccessfulUpdate_AddBattleBuddy()
{
	/*
	Assert(Len(PendingBuddy) > 0);
	BattleBuddies[BattleBuddies.Num()] = PendingBuddy;
	PendingBuddy = "";
	__OnSuccessfulUpdate__Delegate = nullptr;
	*/
}

void UFavorites::InternalOnSuccessfulUpdate_RemoveBattleBuddy()
{
	int32 Index = 0;
	/*
	Assert(Len(PendingBuddy) > 0);
	Index = GetIndexOfBattleBuddy(PendingBuddy);
	if (-1 != Index)
	{
		BattleBuddies.RemoveAt(Index, 1);
	}
	PendingBuddy = "";
	__OnSuccessfulUpdate__Delegate = nullptr;
	*/
}

AUpdateFavoritesRequestAdapter* UFavorites::SpawnRequest(AActor* SpawnActor)
{
	AUpdateFavoritesRequestAdapter* UpdateRequest = nullptr;
	if (bUpdateInProgress)
	{
		//Log("Attempting Favorites update while update is in progress.");
	}
	bUpdateInProgress = true;
	//UpdateRequest = SpawnActor.Spawn('UpdateFavoritesRequestAdapter');
	//UpdateRequest->__dOnUpdateFavoritesRequestComplete__Delegate = InternalOnUpdateFavoritesRequestComplete;
	return UpdateRequest;
}

void UFavorites::AddFavoriteServer(FFavoriteServer Server, FString UserName, FString Password, AActor* ActorToSpawnWith)
{
	AUpdateFavoritesRequestAdapter* AddRequest = nullptr;
	if (GetIndexOfFavoriteServer(Server) == -1 )
	{
		PendingServer = Server;
		//__OnSuccessfulUpdate__Delegate = InternalOnSuccessfulUpdate_AddServer;
		AddRequest = SpawnRequest(ActorToSpawnWith);
		//AddRequest-aAddServer(UserName, Password, Server.IPAddress + ":" + Server.Port);
	}
	else
	{
		InternalOnUpdateFavoritesRequestComplete(-63);
	}
}

void UFavorites::RemoveFavoriteServer(FFavoriteServer Server, FString UserName, FString Password, AActor* ActorToSpawnWith)
{
	int32 Index = 0;
	AUpdateFavoritesRequestAdapter* RemoveRequest = nullptr;
	Index = GetIndexOfFavoriteServer(Server);
	if (Index != -1)
	{
		PendingServer = Server;
		//__OnSuccessfulUpdate__Delegate = InternalOnSuccessfulUpdate_RemoveServer;
		RemoveRequest = SpawnRequest(ActorToSpawnWith);
		//RemoveRequest.RemoveServer(UserName, Password, Server.IPAddress + ":" + Server.Port);
	}
	else
	{
		InternalOnUpdateFavoritesRequestComplete(-64);
	}
}

int32 UFavorites::NumBattleBuddies()
{
	return BattleBuddies.Num();
}

FString UFavorites::GetBattleBuddy(int32 Index)
{
	if (Index < 0 || Index >= BattleBuddies.Num())
	{
		return "";
	}
	return BattleBuddies[Index];
}

TArray<FFilterItem> UFavorites::MakeBattleBuddyFilter(FString UserName)
{
	TArray<FFilterItem> FilterList;
	FilterList.SetNum(1);
	FilterList[0].Key = "buddyListFilter";
	FilterList[0].Value = UserName;
	return FilterList;
}

int32 UFavorites::GetIndexOfBattleBuddy(FString Buddy)
{
	int32 Index = 0;
	/*
	for (Index = 0; Index < BattleBuddies.Num(); Index++)
	{
		if (Buddy ~= BattleBuddies[Index])
		{
			return Index;
		}
	}
	*/
	return -1;
}

void UFavorites::AddBattleBuddy(FString Buddy, FString UserName, FString Password, AActor* ActorToSpawnWith)
{
	AUpdateFavoritesRequestAdapter* AddRequest = nullptr;
	/*
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
	int32 Index = 0;
	AUpdateFavoritesRequestAdapter* RemoveRequest = nullptr;
	Index = GetIndexOfBattleBuddy(Buddy);
	/*
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
	int32 Index = 0;
	FString IPAddress = "";
	FString Port = "";
	/*
	if (ResultCode != 1)
	{
		Log("Failed to refresh favorites from server." @ ResultCode);
		BattleBuddies.Num() = 0;
		FavoriteServers.Num() = 0;
		return;
	}
	BattleBuddies = BuddyList;
	FavoriteServers.Num() = serverList.Num();
	for (Index = 0; Index < serverList.Num(); Index++)
	{
		Divide(serverList[Index], ":", IPAddress, Port);
		FavoriteServers[Index].IPAddress = IPAddress;
		FavoriteServers[Index].Port = Port;
	}
	*/
}

void UFavorites::RefreshFavoritesFromServer(FString UserName, FString Password, AActor* ActorToSpawnWith)
{
	AGetFavoritesRequestAdapter* Adapter = nullptr;
	/*
	Adapter = ActorToSpawnWith.Spawn('GetFavoritesRequestAdapter');
	Adapter.__dOnGetFavoritesRequestComplete__Delegate = InternalOnGetFavoritesRequestComplete;
	Adapter.Request(UserName, Password);
	*/
}
