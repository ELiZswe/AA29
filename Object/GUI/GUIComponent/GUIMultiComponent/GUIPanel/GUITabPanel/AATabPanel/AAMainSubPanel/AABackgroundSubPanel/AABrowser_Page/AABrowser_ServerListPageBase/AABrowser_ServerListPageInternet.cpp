// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageInternet.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/AABrowser_ServersList/AABrowser_ServersList.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/FilterPageBase/FilterPage/AAFilterPage/AAFilterPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/FilterPageBase/FilterPage/AAFilterPageGamespy/AAFilterPageGamespy.h"

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
	if ((PlayerOwner() != nullptr) && PlayerOwner().Level.debugThis(20))
	{
		AServerBrowserBase::StaticClass().DebugDumpFilterList(FilterList);
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
	if (Browser == nullptr)
	{
		return;
	}
	if (li_Server != nullptr)
	{
		li_Server.__OnChange__Delegate = nullptr;
		li_Server.Clear();
	}
	*/
}

void UAABrowser_ServerListPageInternet::GameTypeChanged(UAABrowser_ServersList* NewList)
{
	/*
	if (NewList != nullptr)
	{
		if (li_Server != nullptr)
		{
			li_Server.__OnChange__Delegate = nullptr;
			li_Server.StopPings();
		}
		lb_Server.InitBaseList(NewList);
	}
	InitServerList();
	*/
}

void UAABrowser_ServerListPageInternet::FilterClicked()
{
	FString FilterMenuToOpen = "";
	/*
	if (Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).ServerBrowser ~= "GameSpy")
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
		if (Cast<UAAFilterPage>(Controller.ActivePage) != nullptr)
		{
			AAFilterPage(Controller.ActivePage).BrowserPage = this;
		}
		if (Cast<UAAFilterPageGamespy>(Controller.ActivePage) != nullptr)
		{
			AAFilterPageGamespy(Controller.ActivePage).BrowserPage = this;
		}
		if (li_Server != nullptr)
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
		if (li_Server != nullptr)
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
	AServerBrowserBase* sbBase = nullptr;
	/*
	if (PlayerOwner() == nullptr)
	{
		return;
	}
	Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).LanServerBrowser = false;
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser();
	SetProgress(string(sbBase.GetNumServers()) @ "servers" @ FString::FromInt(sbBase.GetProgress()) + "% complete");
	*/
}

void UAABrowser_ServerListPageInternet::RefreshSBList()
{
	AServerBrowserBase* sbBase = nullptr;
	/*
	if (PlayerOwner() == nullptr)
	{
		return;
	}
	Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).LanServerBrowser = false;
	sbBase = Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser();
	if (sbBase == nullptr)
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
	if (UAAFilterPageGamespy::StaticClass().Default.sFilterMap == "ALL")
	{
		sFilterString = "";
	}
	else
	{
		sFilterString = "(mapname = '" + UAAFilterPageGamespy::StaticClass().Default.sFilterMap + "')";
	}
	if (UAAFilterPageGamespy::StaticClass().Default.bFilterHideFull)
	{
		(sFilterString += NeedAnd(sFilterString) + "(numplayers != maxplayers)");
	}
	if (UAAFilterPageGamespy::StaticClass().Default.bFilterHideEmpty)
	{
		(sFilterString += NeedAnd(sFilterString) + "(numplayers != 0)");
	}
	if (UAAFilterPageGamespy::StaticClass().Default.bFilterShowOfficial)
	{
		(sFilterString += NeedAnd(sFilterString) + "(official = 1)");
	}
	if (UAAFilterPageGamespy::StaticClass().Default.bFilterShowLeased)
	{
		(sFilterString += NeedAnd(sFilterString) + "(leased = 1)");
	}
	if (UAAFilterPageGamespy::StaticClass().Default.bFilterHidePassword)
	{
		(sFilterString += NeedAnd(sFilterString) + "(password = 0)");
	}
	if (UAAFilterPageGamespy::StaticClass().Default.bFilterShowMiles)
	{
		(sFilterString += NeedAnd(sFilterString) + "(miles = 1)");
	}
	if (UAAFilterPageGamespy::StaticClass().Default.bFilterShowCheat)
	{
		(sFilterString += NeedAnd(sFilterString) + "(cheats = 1)");
	}
	if (UAAFilterPageGamespy::StaticClass().Default.bFilterShowTournament)
	{
		(sFilterString += NeedAnd(sFilterString) + "(tournament = 1)");
	}
	if (UAAFilterPageGamespy::StaticClass().Default.bFilterShowPB)
	{
		(sFilterString += NeedAnd(sFilterString) + "(sv_punkbuster = 1)");
	}
	(sFilterString += NeedAnd(sFilterString) + "(minhonor >= " + FString::FromInt(UAAFilterPageGamespy::StaticClass().Default.nFilterMinHonor) + ") AND (maxhonor <= " + FString::FromInt(UAAFilterPageGamespy::StaticClass().Default.nFilterMaxHonor) + ")");
	*/
	return sFilterString;
}

int32 UAABrowser_ServerListPageInternet::GetTourIndexByName(FString TourName)
{
	int32 Index = 0;
	/*
	if ((PlayerOwner() == nullptr) || (PlayerOwner().Level == nullptr))
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
	FFilterItem filter;
	int32 Tour = 0;
	/*
	FilterList.Num() = 0;
	if (UAAFilterPage::StaticClass().Default.sFilterBy ~= "servername")
	{
		if (Len(UAAFilterPage::StaticClass().Default.sFilterServerName) != 0)
		{
			filter.Key = "serverName";
			filter.Value = UAAFilterPage::StaticClass().Default.sFilterServerName;
			FilterList[FilterList.Num()] = filter;
		}
	}
	else
	{
		if (UAAFilterPage::StaticClass().Default.sFilterBy ~= "PlayerName")
		{
			if (Len(UAAFilterPage::StaticClass().Default.sFilterPlayerName) != 0)
			{
				filter.Key = "playerName";
				filter.Value = UAAFilterPage::StaticClass().Default.sFilterPlayerName;
				FilterList[FilterList.Num()] = filter;
			}
		}
		else
		{
			if (!(UAAFilterPage::StaticClass().Default.sFilterMap ~= "ALL"))
			{
				filter.Key = "mapName";
				filter.Value = UAAFilterPage::StaticClass().Default.sFilterMap;
				FilterList[FilterList.Num()] = filter;
			}
			if (UAAFilterPage::StaticClass().Default.bFilterHideFull)
			{
				filter.Key = "playerCount";
				filter.Value = "<maxPlayers";
				FilterList[FilterList.Num()] = filter;
			}
			if (UAAFilterPage::StaticClass().Default.bFilterHideEmpty)
			{
				filter.Key = "playerCount";
				filter.Value = ">0";
				FilterList[FilterList.Num()] = filter;
			}
			if (UAAFilterPage::StaticClass().Default.bFilterShowOfficial)
			{
				filter.Key = "official";
				filter.Value = "1";
				FilterList[FilterList.Num()] = filter;
			}
			if (UAAFilterPage::StaticClass().Default.bFilterShowLeased)
			{
				filter.Key = "leased";
				filter.Value = "1";
				FilterList[FilterList.Num()] = filter;
			}
			if (UAAFilterPage::StaticClass().Default.bFilterHidePassword)
			{
				filter.Key = "requiresPassword";
				filter.Value = "0";
				FilterList[FilterList.Num()] = filter;
			}
			if (UAAFilterPage::StaticClass().Default.bFilterShowMiles)
			{
				filter.Key = "miles";
				filter.Value = "1";
				FilterList[FilterList.Num()] = filter;
			}
			if (UAAFilterPage::StaticClass().Default.bFilterShowCheat)
			{
				filter.Key = "cheats";
				filter.Value = "1";
				FilterList[FilterList.Num()] = filter;
			}
			if (UAAFilterPage::StaticClass().Default.bFilterShowTournament)
			{
				filter.Key = "tournament";
				filter.Value = "1";
				FilterList[FilterList.Num()] = filter;
			}
			if (UAAFilterPage::StaticClass().Default.bFilterShowPB)
			{
				filter.Key = "punkbuster";
				filter.Value = "1";
				FilterList[FilterList.Num()] = filter;
			}
			if (UAAFilterPage::StaticClass().Default.sFilterHonorBy ~= "Average")
			{
				filter.Key = "averageHonor";
				filter.Value = ">=" + FString::FromInt(Clamp((UAAFilterPage::StaticClass().Default.nFilterAverageHonor - 5), 1, 100));
				FilterList[FilterList.Num()] = filter;
				filter.Key = "averageHonor";
				filter.Value = "<=" + FString::FromInt(Clamp((UAAFilterPage::StaticClass().Default.nFilterAverageHonor + 5), 1, 100));
				FilterList[FilterList.Num()] = filter;
			}
			else
			{
				if (UAAFilterPage::StaticClass().Default.nFilterMinHonor > 1)
				{
					filter.Key = "minHonor";
					filter.Value = ">=" + FString::FromInt(UAAFilterPage::StaticClass().Default.nFilterMinHonor);
					FilterList[FilterList.Num()] = filter;
				}
				if (UAAFilterPage::StaticClass().Default.nFilterMaxHonor < 100)
				{
					filter.Key = "maxHonor";
					filter.Value = "<=" + FString::FromInt(UAAFilterPage::StaticClass().Default.nFilterMaxHonor);
					FilterList[FilterList.Num()] = filter;
				}
			}
			if (!(UAAFilterPage::StaticClass().Default.sFilterCountry ~= "ALL"))
			{
				filter.Key = "locale";
				filter.Value = UAAFilterPage::StaticClass().Default.sFilterCountry;
				FilterList[FilterList.Num()] = filter;
			}
			Tour = GetTourIndexByName(UAAFilterPage::StaticClass().Default.sFilterTour);
			if (Tour != -1)
			{
				filter.Key = "tour";
				filter.Value = FString::FromInt(Tour);
				FilterList[FilterList.Num()] = filter;
			}
		}
	}
	*/
}

FString UAABrowser_ServerListPageInternet::NeedAnd(FString sFilter)
{
	FString MyString="";
	if (sFilter != "")
	{
		MyString = " AND ";
	}
	return MyString;
}
