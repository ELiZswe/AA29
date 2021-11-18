// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageInternet.h"

UAABrowser_ServerListPageInternet::UAABrowser_ServerListPageInternet()
{

}


//const ALL_TOURS = -1;
//const AVERAGE_HONOR_RANGE = 5;

void UAABrowser_ServerListPageInternet::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	FilterString = BuildInitialFilter();
	BuildInitialFilterList();
	if ((PlayerOwner() != None) && PlayerOwner().Level.debugThis(20))
	{
		Class'IpDrv.ServerBrowserBase'.DebugDumpFilterList(FilterList);
	}
	GameTypeChanged(li_Server);
	*/
}

void UAABrowser_ServerListPageInternet::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bShow && bInit)
	{
		bInit = false;
	}
	*/
}

void UAABrowser_ServerListPageInternet::ClearAllLists()
{
	/*
	if (Browser == None)
	{
		return;
	}
	if (li_Server != None)
	{
		li_Server.__OnChange__Delegate = None;
		li_Server.Clear();
	}
	*/
}

void UAABrowser_ServerListPageInternet::GameTypeChanged(UAABrowser_ServersList* NewList)
{
	/*
	if (NewList != None)
	{
		if (li_Server != None)
		{
			li_Server.__OnChange__Delegate = None;
			li_Server.StopPings();
		}
		lb_Server.InitBaseList(NewList);
	}
	InitServerList();
	*/
}

void UAABrowser_ServerListPageInternet::FilterClicked()
{
	/*
	local FString FilterMenuToOpen;
	if (AGP_HUD(HumanController(PlayerOwner()).myHUD).ServerBrowser ~= "GameSpy")
	{
		FilterMenuToOpen = Controller.FilterMenuGamespy;
	}
	else
	{
		FilterMenuToOpen = Controller.FilterMenu;
	}
	if (Controller.OpenMenu(FilterMenuToOpen))
	{
		Controller.ActivePage.__OnClose__Delegate = FiltersClosed;
		if (AAFilterPage(Controller.ActivePage) != None)
		{
			AAFilterPage(Controller.ActivePage).BrowserPage = Self;
		}
		if (AAFilterPageGamespy(Controller.ActivePage) != None)
		{
			AAFilterPageGamespy(Controller.ActivePage).BrowserPage = Self;
		}
		if (li_Server != None)
		{
			li_Server.StopPings();
		}
	}
	*/
}

void UAABrowser_ServerListPageInternet::FiltersClosed(bool bCancelled)
{
	/*
	if (!bCancelled)
	{
		ClearAllLists();
		Refresh();
	}
	else
	{
		if (li_Server != None)
		{
			li_Server.AutopingServers();
		}
	}
	*/
}

void UAABrowser_ServerListPageInternet::Refresh()
{
	/*
	GameTypeChanged(li_Server);
	Super::Refresh();
	RefreshSBList();
	*/
}
void UAABrowser_ServerListPageInternet::RefreshList()
{
	//Super::RefreshList();
}

void UAABrowser_ServerListPageInternet::MyOnGameSpyStatusDone()
{
	/*
	local IpDrv.ServerBrowserBase sbBase;
	if (PlayerOwner() == None)
	{
		return;
	}
	AGP_HUD(HumanController(PlayerOwner()).myHUD).LanServerBrowser = false;
	sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser();
	SetProgress(string(sbBase.GetNumServers()) @ "servers" @ string(sbBase.GetProgress()) $ "% complete");
	*/
}

void UAABrowser_ServerListPageInternet::RefreshSBList()
{
	/*
	local IpDrv.ServerBrowserBase sbBase;
	if (PlayerOwner() == None)
	{
		return;
	}
	AGP_HUD(HumanController(PlayerOwner()).myHUD).LanServerBrowser = false;
	sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser();
	if (sbBase == None)
	{
		return;
	}
	sbBase.__OnReceivedServer__Delegate = li_Server.MyOnReceivedSB;
	sbBase.__OnUpdateServerListFailed__Delegate = li_Server.MyOnUpdateServerListFailed;
	sbBase.__OnGameSpyStatusDone__Delegate = MyOnGameSpyStatusDone;
	sbBase.SetPublic(true);
	sbBase.SetFilter(FilterString);
	sbBase.SetFilterList(FilterList);
	SetProgress("Obtaining servers 0% complete");
	sbBase.UpdateServerList();
	*/
}

void UAABrowser_ServerListPageInternet::SetSBFilter(FString S)
{
	FilterString = S;
}

void UAABrowser_ServerListPageInternet::SetServerBrowserFilterList(TArray<FFilterItem> List)
{
	FilterList = List;
}

FString UAABrowser_ServerListPageInternet::BuildInitialFilter()
{
	FString sFilterString="";
	/*
	if (class'AGP_Interface.AAFilterPageGamespy'.Default.sFilterMap == "ALL")
	{
		sFilterString = "";
	}
	else
	{
		sFilterString = "(mapname = '" $ class'AGP_Interface.AAFilterPageGamespy'.Default.sFilterMap $ "')";
	}
	if (class'AGP_Interface.AAFilterPageGamespy'.Default.bFilterHideFull)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(numplayers != maxplayers)");
	}
	if (class'AGP_Interface.AAFilterPageGamespy'.Default.bFilterHideEmpty)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(numplayers != 0)");
	}
	if (class'AGP_Interface.AAFilterPageGamespy'.Default.bFilterShowOfficial)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(official = 1)");
	}
	if (class'AGP_Interface.AAFilterPageGamespy'.Default.bFilterShowLeased)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(leased = 1)");
	}
	if (class'AGP_Interface.AAFilterPageGamespy'.Default.bFilterHidePassword)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(password = 0)");
	}
	if (class'AGP_Interface.AAFilterPageGamespy'.Default.bFilterShowMiles)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(miles = 1)");
	}
	if (class'AGP_Interface.AAFilterPageGamespy'.Default.bFilterShowCheat)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(cheats = 1)");
	}
	if (class'AGP_Interface.AAFilterPageGamespy'.Default.bFilterShowTournament)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(tournament = 1)");
	}
	if (class'AGP_Interface.AAFilterPageGamespy'.Default.bFilterShowPB)
	{
		(sFilterString $ = NeedAnd(sFilterString) $ "(sv_punkbuster = 1)");
	}
	(sFilterString $ = NeedAnd(sFilterString) $ "(minhonor >= " $ string(class'AGP_Interface.AAFilterPageGamespy'.Default.nFilterMinHonor) $ ") AND (maxhonor <= " $ string(class'AGP_Interface.AAFilterPageGamespy'.Default.nFilterMaxHonor) $ ")");
	*/
	return sFilterString;
}

int32 UAABrowser_ServerListPageInternet::GetTourIndexByName(FString TourName)
{
	/*
	local int32 Index;
	if ((PlayerOwner() == None) || (PlayerOwner().Level == None))
	{
		return -1;
	}
	for (Index = 0; Index < PlayerOwner().Level.iNumTours; Index++)
	{
		if (TourName ~= PlayerOwner().Level.GetTourName(Index))
		{
			return Index;
		}
	}
	*/
	return -1;
}

void UAABrowser_ServerListPageInternet::BuildInitialFilterList()
{
	/*
	local ServerBrowserBase.FilterItem filter;
	local int32 Tour;
	FilterList.Length = 0;
	if (class'AGP_Interface.AAFilterPage'.Default.sFilterBy ~= "servername")
	{
		if (Len(class'AGP_Interface.AAFilterPage'.Default.sFilterServerName) != 0)
		{
			filter.Key = "serverName";
			filter.Value = class'AGP_Interface.AAFilterPage'.Default.sFilterServerName;
			FilterList[FilterList.Length] = filter;
		}
	}
	else
	{
		if (class'AGP_Interface.AAFilterPage'.Default.sFilterBy ~= "PlayerName")
		{
			if (Len(class'AGP_Interface.AAFilterPage'.Default.sFilterPlayerName) != 0)
			{
				filter.Key = "playerName";
				filter.Value = class'AGP_Interface.AAFilterPage'.Default.sFilterPlayerName;
				FilterList[FilterList.Length] = filter;
			}
		}
		else
		{
			if (!(class'AGP_Interface.AAFilterPage'.Default.sFilterMap ~= "ALL"))
			{
				filter.Key = "mapName";
				filter.Value = class'AGP_Interface.AAFilterPage'.Default.sFilterMap;
				FilterList[FilterList.Length] = filter;
			}
			if (class'AGP_Interface.AAFilterPage'.Default.bFilterHideFull)
			{
				filter.Key = "playerCount";
				filter.Value = "<maxPlayers";
				FilterList[FilterList.Length] = filter;
			}
			if (class'AGP_Interface.AAFilterPage'.Default.bFilterHideEmpty)
			{
				filter.Key = "playerCount";
				filter.Value = ">0";
				FilterList[FilterList.Length] = filter;
			}
			if (class'AGP_Interface.AAFilterPage'.Default.bFilterShowOfficial)
			{
				filter.Key = "official";
				filter.Value = "1";
				FilterList[FilterList.Length] = filter;
			}
			if (class'AGP_Interface.AAFilterPage'.Default.bFilterShowLeased)
			{
				filter.Key = "leased";
				filter.Value = "1";
				FilterList[FilterList.Length] = filter;
			}
			if (class'AGP_Interface.AAFilterPage'.Default.bFilterHidePassword)
			{
				filter.Key = "requiresPassword";
				filter.Value = "0";
				FilterList[FilterList.Length] = filter;
			}
			if (class'AGP_Interface.AAFilterPage'.Default.bFilterShowMiles)
			{
				filter.Key = "miles";
				filter.Value = "1";
				FilterList[FilterList.Length] = filter;
			}
			if (class'AGP_Interface.AAFilterPage'.Default.bFilterShowCheat)
			{
				filter.Key = "cheats";
				filter.Value = "1";
				FilterList[FilterList.Length] = filter;
			}
			if (class'AGP_Interface.AAFilterPage'.Default.bFilterShowTournament)
			{
				filter.Key = "tournament";
				filter.Value = "1";
				FilterList[FilterList.Length] = filter;
			}
			if (class'AGP_Interface.AAFilterPage'.Default.bFilterShowPB)
			{
				filter.Key = "punkbuster";
				filter.Value = "1";
				FilterList[FilterList.Length] = filter;
			}
			if (class'AGP_Interface.AAFilterPage'.Default.sFilterHonorBy ~= "Average")
			{
				filter.Key = "averageHonor";
				filter.Value = ">=" $ string(Clamp((class'AGP_Interface.AAFilterPage'.Default.nFilterAverageHonor - 5), 1, 100));
				FilterList[FilterList.Length] = filter;
				filter.Key = "averageHonor";
				filter.Value = "<=" $ string(Clamp((class'AGP_Interface.AAFilterPage'.Default.nFilterAverageHonor + 5), 1, 100));
				FilterList[FilterList.Length] = filter;
			}
			else
			{
				if (class'AGP_Interface.AAFilterPage'.Default.nFilterMinHonor > 1)
				{
					filter.Key = "minHonor";
					filter.Value = ">=" $ string(class'AGP_Interface.AAFilterPage'.Default.nFilterMinHonor);
					FilterList[FilterList.Length] = filter;
				}
				if (class'AGP_Interface.AAFilterPage'.Default.nFilterMaxHonor < 100)
				{
					filter.Key = "maxHonor";
					filter.Value = "<=" $ string(class'AGP_Interface.AAFilterPage'.Default.nFilterMaxHonor);
					FilterList[FilterList.Length] = filter;
				}
			}
			if (!(class'AGP_Interface.AAFilterPage'.Default.sFilterCountry ~= "ALL"))
			{
				filter.Key = "locale";
				filter.Value = class'AGP_Interface.AAFilterPage'.Default.sFilterCountry;
				FilterList[FilterList.Length] = filter;
			}
			Tour = GetTourIndexByName(class'AGP_Interface.AAFilterPage'.Default.sFilterTour);
			if (Tour != -1)
			{
				filter.Key = "tour";
				filter.Value = string(Tour);
				FilterList[FilterList.Length] = filter;
			}
		}
	}
	*/
}

FString UAABrowser_ServerListPageInternet::NeedAnd(FString sFilter)
{
	FString MyString="";
	/*
	if (sFilter != "")
	{
		MyString = " AND ";
	}
	*/
	return MyString;
}
