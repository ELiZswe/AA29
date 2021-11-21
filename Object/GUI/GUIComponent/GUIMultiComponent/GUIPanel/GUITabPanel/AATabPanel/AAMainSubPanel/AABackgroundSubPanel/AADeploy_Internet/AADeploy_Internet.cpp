// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploy_Internet/AADeploy_Internet.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_PlayerServerSearchPanel/AABrowser_PlayerServerSearchPane.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_UpdateJoinAndPBPanel/AABrowser_UpdateJoinAndPBPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_FilterSetPanel/AABrowser_FilterSetPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AAGUIPanelHideable/AABrowser_FilterAndServerlistPanel/AABrowser_FilterAndServerlistPan.h"

UAADeploy_Internet::UAADeploy_Internet()
{
	UAABrowser_PlayerServerSearchPane* PlayerServerSearch = NewObject<UAABrowser_PlayerServerSearchPane>(UAABrowser_PlayerServerSearchPane::StaticClass());
	//PlayerServerSearch->OnSearch = AADeploy_Internet.InternalOnSearch;
	PlayerServerSearch->WinTop = 0.848985;
	PlayerServerSearch->WinLeft = 0.333;
	PlayerServerSearch->WinWidth = 0.666;
	PlayerServerSearch->WinHeight = 0.060527;
	UAABrowser_UpdateJoinAndPBPanel* UpdateJoinAndPB = NewObject<UAABrowser_UpdateJoinAndPBPanel>(UAABrowser_UpdateJoinAndPBPanel::StaticClass());
	//UpdateJoinAndPB->OnPunkBusterChanged = AADeploy_Internet.InternalOnPunkBusterChanged;
	//UpdateJoinAndPB->OnUpdateServerList = AADeploy_Internet.InternalOnUpdateServerList;
	//UpdateJoinAndPB->OnJoinServer = AADeploy_Internet.InternalOnJoinServer;
	UpdateJoinAndPB->WinTop = 0.905271;
	UpdateJoinAndPB->WinLeft = 0.333;
	UpdateJoinAndPB->WinWidth = 0.666;
	UpdateJoinAndPB->WinHeight = 0.057237;
	UAABrowser_FilterAndServerlistPan* FilterAndServerList = NewObject<UAABrowser_FilterAndServerlistPan>(UAABrowser_FilterAndServerlistPan::StaticClass());
	//FilterAndServerList->OnUpdateServerList = AADeploy_Internet.InternalOnUpdateServerList;
	//FilterAndServerList->OnFiltersChanged = AADeploy_Internet.InternalOnFiltersChanged;
	FilterAndServerList->WinTop = 0.06;
	FilterAndServerList->WinHeight = 0.79;
	UAABrowser_FilterSetPanel* FilterSet = NewObject<UAABrowser_FilterSetPanel>(UAABrowser_FilterSetPanel::StaticClass());
	//FilterSet->OnFilterSetChanged = AADeploy_Internet.InternalOnFilterSetChanged;
	//FilterSet->OnClearFilters = AADeploy_Internet.InternalOnClearFilters;
	//FilterSet->OnShowFilters = AADeploy_Internet.InternalOnShowFilters;
	FilterSet->WinTop = 0.848985;
	FilterSet->WinWidth = 0.333;
	FilterSet->WinHeight = 0.114474;
	UGUILabel* ServerCountLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ServerCountLabel->TextAlign = ETextAlign::TXTA_Center;
	ServerCountLabel->FontScale = EFontScale::FNS_Small;
	ServerCountLabel->StyleName = "TextLabel";
	ServerCountLabel->WinTop = 0.9376;
	ServerCountLabel->WinLeft = 0.023026;
	ServerCountLabel->WinWidth = 0.282237;
	ServerCountLabel->WinHeight = 0.025515;
	ServerCountLabel->RenderWeight = 10;
	ServerCountLabel->bBoundToParent = true;
	ServerCountLabel->bScaleToParent = true;
	FilterAndServerListPanel = FilterAndServerList;
	FilterSetPanel = FilterSet;
	PlayerServerSearchPanel = PlayerServerSearch;
	UpdateJoinAndPBPanel = UpdateJoinAndPB;
	PanelCaptionBase = "AA Browser";
	ServerCount = ServerCountLabel;
	PanelCaption = "AA Browser (MBS)";
}

void UAADeploy_Internet::ShowPanel(bool bShow)
{
	/*
	local bool bShouldRefreshServerList;
	Super::ShowPanel(bShow);
	bShouldRefreshServerList = ((bUseDeploymentModeOnNextShowPanel || Default.bShowOnlyExploreTheArmyServers) || (ShowCount < 3));
	ShowCount++;
	if (bUseDeploymentModeOnNextShowPanel)
	{
		FilterAndServerListPanel.PutIntoDeploymentMode(sDeploymentModeMap);
		sDeploymentModeMap = "";
	}
	bUseDeploymentModeOnNextShowPanel = false;
	if (bShouldRefreshServerList && bShow)
	{
		UpdateJoinAndPBPanel.SetUpdateServerListButtonText("Obtain Server List");
		FilterAndServerListPanel.ClearLists();
		ServerCount.Caption = "";
	}
	if (bShow)
	{
		if ((None != PlayerOwner()) && bShouldRefreshServerList)
		{
			RefreshServerList();
		}
		if ((None == PlayerOwner()) || (!(AGP_HUD(PlayerOwner().myHUD).ServerBrowser ~= "AA Browser")))
		{
			PlayerServerSearchPanel.DisableMe();
		}
		else
		{
			PlayerServerSearchPanel.EnableMe();
		}
	}
	if (None != PlayerOwner())
	{
		PanelCaption = PanelCaptionBase;
		if (AGP_HUD(PlayerOwner().myHUD).ServerBrowser ~= "AA Browser")
		{
			(PanelCaption @ = "(MBS");
		}
		else
		{
			(PanelCaption @ = "(" $ AGP_HUD(PlayerOwner().myHUD).ServerBrowser);
		}
		(PanelCaption $ = Eval(Default.bShowOnlyExploreTheArmyServers, " - Instant Action", "") $ ")");
	}
	h_Header.SetCaption(PanelCaption);
	*/
}

void UAADeploy_Internet::SetExploreTheArmyMode(bool bExploreTheArmy)
{
	//Default.bShowOnlyExploreTheArmyServers = bExploreTheArmy;
}

void UAADeploy_Internet::SetDeploymentModeOnNextShowPanel(FString MapToFilter)
{
	bUseDeploymentModeOnNextShowPanel = true;
	sDeploymentModeMap = MapToFilter;
}

void UAADeploy_Internet::RefreshServerList()
{
	/*
	local FString GameSpyFilter;
	local TArray<FFilterItem> FilterList;
	local FFilterItem ExploreTheArmyFilter;
	GameSpyFilter = FilterAndServerListPanel.GetGameSpyFilterString();
	FilterList = FilterAndServerListPanel.GetDBMBSFilterList();
	ExploreTheArmyFilter.Key = "exploreTheArmy";
	if (Default.bShowOnlyExploreTheArmyServers)
	{
		ExploreTheArmyFilter.Value = "1";
		(GameSpyFilter $ = Eval((Len(GameSpyFilter) > 0), " AND ", "") $ "(explore_the_army = 1)");
	}
	else
	{
		ExploreTheArmyFilter.Value = "0";
		(GameSpyFilter $ = Eval((Len(GameSpyFilter) > 0), " AND ", "") $ "(explore_the_army = 0)");
	}
	FilterList[FilterList.Length] = ExploreTheArmyFilter;
	UpdateServerList(GameSpyFilter, FilterList);
	*/
}

void UAADeploy_Internet::InternalOnFilterSetChanged(int32 NewIndex)
{
	/*
	FilterAndServerListPanel.SetFilterSet(NewIndex);
	Log("--==! InternalOnFilterSetChanged !==--");
	UpdateJoinAndPBPanel.SetUpdateServerListButtonText("Apply Filters");
	UpdateJoinAndPBPanel.ActivateServerListButtonEyecatcher();
	*/
}

void UAADeploy_Internet::InternalOnClearFilters()
{
	/*
	FilterAndServerListPanel.ClearFilterSet();
	UpdateJoinAndPBPanel.SetUpdateServerListButtonText("Obtain Server List");
	*/
}

void UAADeploy_Internet::InternalOnShowFilters()
{
	//FilterAndServerListPanel.ShowFilterSummary();
}

void UAADeploy_Internet::InternalOnFiltersChanged()
{
	//UpdateJoinAndPBPanel.SetUpdateServerListButtonText("Apply Filters");
	//UpdateJoinAndPBPanel.ActivateServerListButtonEyecatcher();
}

void UAADeploy_Internet::InternalOnSearch(FFilterItem filter)
{
	/*
	local TArray<FFilterItem> FilterList;
	FilterList[0] = filter;
	UpdateServerList("", FilterList);
	UpdateJoinAndPBPanel.SetUpdateServerListButtonText("Obtain Server List");
	*/
}

void UAADeploy_Internet::InternalOnPunkBusterChanged(bool PunkBusterEnabled)
{
	/*
	if (PunkBusterEnabled)
	{
		PlayerOwner().Level.PBEnable();
	}
	else
	{
		PlayerOwner().Level.PBDisable();
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "PunkBuster Client", "The PunkBuster Client will be disabled the NEXT TIME upon startup.");
	}
	*/
}

void UAADeploy_Internet::InternalOnUpdateServerList()
{
	//RefreshServerList();
	//UpdateJoinAndPBPanel.SetUpdateServerListButtonText("Update Server List");
}

void UAADeploy_Internet::InternalOnJoinServer()
{
	//FilterAndServerListPanel.JoinCurrentlySelectedServer();
}

void UAADeploy_Internet::CloseEnumerationDialog()
{
	/*
	if (None != AAEnumeratingServersModalDialog(Controller.TopPage()))
	{
		Controller.CloseMenu();
	}
	*/
}

void UAADeploy_Internet::InternalOnUpdateServerListFailed(FString Reason)
{
	/*
	CloseEnumerationDialog();
	Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Internet Servers Failure", Reason);
	*/
}

void UAADeploy_Internet::InternalOnReceivedServer(int32 Index)
{
	/*
	local IpDrv.ServerBrowserBase ServerBrowser;
	local int32 NumServers;
	CloseEnumerationDialog();
	ServerBrowser = AGP_HUD(PlayerOwner().myHUD).GetCurrentServerBrowser();
	if (ServerBrowser != None)
	{
		NumServers = ServerBrowser.GetNumServers();
		ServerCount.Caption = string(NumServers) @ "server" $ Eval((NumServers != 1), "s", "");
	}
	FilterAndServerListPanel.ReceivedServer(Index);
	*/
}

void UAADeploy_Internet::UpdateServerList(FString GameSpyFilterString, TArray<FFilterItem> FilterList)
{
	/*
	local IpDrv.ServerBrowserBase ServerBrowser;
	ServerBrowser = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser();
	if ((PlayerOwner() == None) || (ServerBrowser == None))
	{
		return;
	}
	FilterAndServerListPanel.ClearLists();
	if ((AGP_HUD(PlayerOwner().myHUD).ServerBrowser == "AA Browser") && (None == AAEnumeratingServersModalDialog(Controller.TopPage())))
	{
		Controller.OpenMenu("AGP_Interface.AAEnumeratingServersModalDialog");
	}
	ServerCount.Caption = "";
	ServerBrowser.__OnReceivedServer__Delegate = InternalOnReceivedServer;
	ServerBrowser.__OnUpdateServerListFailed__Delegate = InternalOnUpdateServerListFailed;
	ServerBrowser.SetPublic(true);
	ServerBrowser.SetFilter(GameSpyFilterString);
	ServerBrowser.SetFilterList(FilterList);
	ServerBrowser.UpdateServerList();
	*/
}
