// All the original content belonged to the US Army

#include "AA29/Object/Actor/ServerBrowserBase/GameSpyServerList/GameSpyServerList.h"

AGameSpyServerList::AGameSpyServerList()
{
	//PointerProperty* m_serverlist = NewObject<PointerProperty>(PointerProperty::StaticClass());
	iSelectedServer = -1;
	//RemoteRole = ROLE_None;
	//bAlwaysTick = true;
}

//native Function UpdateServerList();
void AGameSpyServerList::UpdateServerList()
{

}

//native Function RefreshServerList();
void AGameSpyServerList::RefreshServerList()
{

}

//native Function RefreshSpecificServer(int32 iIndex);
void AGameSpyServerList::RefreshSpecificServer(int32 iIndex)
{

}

//native Function RePingAllServers();
void AGameSpyServerList::RePingAllServers()
{

}

//native Function CallServerListThink();
void AGameSpyServerList::CallServerListThink()
{

}

//native Function CallServerListSort(FString sField, bool bAscending, EGameSpyCompareMode Mode);
void AGameSpyServerList::CallServerListSort(FString sField, bool bAscending, EGameSpyCompareMode Mode)
{

}

//native Function CallServerListRemoveServer(FString IP, int32 Port);
void AGameSpyServerList::CallServerListRemoveServer(FString IP, int32 Port)
{

}

//native Function CallServerListClear();
void AGameSpyServerList::CallServerListClear()
{

}

//native Function int32 CallServerListCount();
int32 AGameSpyServerList::CallServerListCount()
{
	return 0;     //FAKE    /EliZ
}

//native Function GetPlayerInfo(int32 server_index, int32 player_index, FGameSpyPlayerInfo& player_info);
void AGameSpyServerList::GetPlayerInfo(int32 server_index, int32 player_index, FGameSpyPlayerInfo& player_info)
{

}

//native iterator Function AllServers(FGameSpyServerItem& Item);
void AGameSpyServerList::AllServers(FGameSpyServerItem& Item)
{

}

//native iterator Function AllServersInRange(FGameSpyServerItem& Item, int32 MinRange, int32 MaxRange);
void AGameSpyServerList::AllServersInRange(FGameSpyServerItem& Item, int32 MinRange, int32 MaxRange)
{

}

//native Function GetSpecificServerNative(int32 Index, FGameSpyServerItem& Item);
void AGameSpyServerList::GetSpecificServerNative(int32 Index, FGameSpyServerItem& Item)
{

}

void AGameSpyServerList::GetSpecificServer(int32 Index, FGameSpyServerItem& Item)
{
	//GetSpecificServerNative(Index, Item);
}

void AGameSpyServerList::GameSpyInit()
{
}

void AGameSpyServerList::GameSpyClearList()
{
}

void AGameSpyServerList::GameSpyStartRefresh()
{
	/*
	bWorking = true;
	SetTimer(0.1, true);
	*/
}

void AGameSpyServerList::GameSpyStatusDone()
{
	/*
	bool bAutoSort = false;
	bWorking = false;
	bAutoSort = false;
	SetTimer(0, false);
	if (HUD(Owner) != None)
	{
		bAutoSort = HUD(Owner).GetAutoSort();
	}
	if (bAutoSort && bSortSaved)
	{
		CallServerListSort(sSortField, bSortAscending, eSortType);
	}
	if (bDisplayWhenDone)
	{
		bDisplayWhenDone = false;
		DisplayServerList();
	}
	OnGameSpyStatusDone();
	*/
}

void AGameSpyServerList::Tick(float DeltaTime)
{
	/*
	if (bWorking)
	{
		CallServerListThink();
	}
	else
	{
		if (iSelectedServer != -1)
		{
			if ((Level.RealSeconds - fLastSelServerUpdate) > 5)
			{
				RefreshSpecificServer(iSelectedServer);
				fLastSelServerUpdate = Level.RealSeconds;
			}
		}
	}
	*/
}

void AGameSpyServerList::Timer()
{
	CallServerListThink();
}

void AGameSpyServerList::DisplayServerList()
{
	/*
	local FGameSpyServerItem Item;
	ForEach AllServers(Item)
	{
		if (Item.bValid != 0)
		{
			Log("GameSpyServer Item - Name:" @ Item.Name @ "IP:" @ string(Item.IP) @ "Port:" @ string(Item.Port) @ "Ping:" @ string(Item.Ping));
		}
		else
		{
			Log("Error: Invalid Server Item");
		}
	}
	*/
}

int32 AGameSpyServerList::GetNumServers()
{
	return CallServerListCount();
}

void AGameSpyServerList::SortServers(FString sField, bool bAscending, EGameSpyCompareMode eType)
{
	/*
	bSortSaved = true;
	sSortField = sField;
	bSortAscending = bAscending;
	eSortType = eType;
	CallServerListSort(sField, bAscending, eType);
	*/
}

void AGameSpyServerList::SetFilter(FString sFilter)
{
	/*
	if (FilterString == "")
	{
		sCurrentFilter = "(gamename = 'armygame') AND (gamever = '" $ string(GetVersionAGPMajor()) $ "." $ string(GetVersionAGPMinor()) $ "." $ string(GetVersionAGPTiny()) $ "." $ string(GetVersionAGPSubTiny()) $ "')";
	}
	else
	{
		sCurrentFilter = FilterString;
	}
	if (sFilter != "")
	{
		if (sCurrentFilter == "")
		{
			sCurrentFilter = sFilter;
		}
		else
		{
			sCurrentFilter = sCurrentFilter $ " AND " $ sFilter;
		}
	}
	Log(" New filter: " $ sCurrentFilter, 'GameSpyServerList');
	*/
}

void AGameSpyServerList::SetSelectedServer(int32 Index)
{
	/*
	if (iSelectedServer != Index)
	{
		iSelectedServer = Index;
		if (iSelectedServer != -1)
		{
			RefreshSpecificServer(iSelectedServer);
			fLastSelServerUpdate = Level.RealSeconds;
		}
	}
	else
	{
		if (iSelectedServer != -1)
		{
			if ((Level.RealSeconds - fLastSelServerUpdate) > 5)
			{
				RefreshSpecificServer(iSelectedServer);
				fLastSelServerUpdate = Level.RealSeconds;
			}
		}
	}
	*/
}

int32 AGameSpyServerList::GetProgress()
{
	return iProgress;
}

void AGameSpyServerList::SetPublic(bool bPublic)
{
	bInternet = bPublic;
}

FString AGameSpyServerList::GetConnectingMessage()
{
	return "Connecting to GameSpy...";
}