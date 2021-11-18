// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AADeploy_Favorites/AADeploy_Favorites.h"
UAADeploy_Favorites::UAADeploy_Favorites()
{
	/*
	UGUIButton* AddFavoriteServerButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	AddFavoriteServerButton->Caption="Add Favorite";
	AddFavoriteServerButton->FontScale=0;
	AddFavoriteServerButton->WinTop=0.861274;
	AddFavoriteServerButton->WinLeft=0.168876;
	AddFavoriteServerButton->WinWidth=0.159539;
	AddFavoriteServerButton->WinHeight=0.035;
	AddFavoriteServerButton->OnClick=AADeploy_Favorites.InternalOnClick;
	AddFavoriteServerButton->OnKeyEvent=AddFavoriteServerButton.InternalOnKeyEvent;
	UGUIButton* AddBuddyButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	AddBuddyButton->Caption="Add Buddy";
	AddBuddyButton->FontScale=0;
	AddBuddyButton->WinTop=0.861274;
	AddBuddyButton->WinLeft=0.006579;
	AddBuddyButton->WinWidth=0.159539;
	AddBuddyButton->WinHeight=0.035;
	AddBuddyButton->OnClick=AADeploy_Favorites.InternalOnClick;
	AddBuddyButton->OnKeyEvent=AddBuddyButton.InternalOnKeyEvent;
	UGUIButton* RemoveSelectedButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	RemoveSelectedButton->Caption="Remove Selected";
	RemoveSelectedButton->FontScale=0;
	RemoveSelectedButton->WinTop=0.911483;
	RemoveSelectedButton->WinLeft=0.006579;
	RemoveSelectedButton->WinWidth=0.203947;
	RemoveSelectedButton->WinHeight=0.035;
	RemoveSelectedButton->OnClick=AADeploy_Favorites.InternalOnClick;
	RemoveSelectedButton->OnKeyEvent=RemoveSelectedButton.InternalOnKeyEvent;
	UAABrowser_FavoritesAndServerList* FavoritesAndServerList = NewObject<UAABrowser_FavoritesAndServerList>(UAABrowser_FavoritesAndServerList::StaticClass());
	FavoritesAndServerList->OnUpdateServerList=AADeploy_Favorites.InternalOnUpdateServerList;
	FavoritesAndServerList->WinTop=0.06;
	FavoritesAndServerList->WinHeight=0.79;
	UGUIImage* LowerBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	LowerBackground->Image=Texture'T_AA2_UI.Menu.backgroundfill';
	LowerBackground->ImageStyle=1;
	LowerBackground->ImageRenderStyle=1;
	LowerBackground->WinTop=0.850748;
	LowerBackground->WinHeight=0.111185;
	LowerBackground->RenderWeight=0;
	LowerBackground->bBoundToParent=true;
	LowerBackground->bScaleToParent=true;
	UAABrowser_UpdateJoinAndPBPanel* UpdateJoinAndPB = NewObject<UAABrowser_UpdateJoinAndPBPanel>(UAABrowser_UpdateJoinAndPBPanel::StaticClass());
	UpdateJoinAndPB->HideBorder=true;
	UpdateJoinAndPB->OnPunkBusterChanged=AADeploy_Favorites.InternalOnPunkBusterChanged;
	UpdateJoinAndPB->OnUpdateServerList=AADeploy_Favorites.InternalOnUpdateServerList;
	UpdateJoinAndPB->OnJoinServer=AADeploy_Favorites.InternalOnJoinServer;
	UpdateJoinAndPB->WinTop=0.905271;
	UpdateJoinAndPB->WinLeft=0.333;
	UpdateJoinAndPB->WinWidth=0.666;
	UpdateJoinAndPB->WinHeight=0.057237;
	UGUILabel* ServerCountLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ServerCountLabel->TextAlign=2;
	ServerCountLabel->FontScale=0;
	ServerCountLabel->StyleName="TextLabel";
	ServerCountLabel->WinTop=0.858218;
	ServerCountLabel->WinLeft=0.712168;
	ServerCountLabel->WinWidth=0.282237;
	ServerCountLabel->WinHeight=0.025515;
	ServerCountLabel->RenderWeight=10;
	ServerCountLabel->bBoundToParent=true;
	ServerCountLabel->bScaleToParent=true;
	*/
	//FavoritesAndServerListPanel = AABrowser_FavoritesAndServerListPanel'AGP_Interface.AADeploy_Favorites.FavoritesAndServerList';
	//UpdateJoinAndPBPanel = AABrowser_UpdateJoinAndPBPanel'AGP_Interface.AADeploy_Favorites.UpdateJoinAndPB';
	//LowerBackgroundBorder = GUIImage'AGP_Interface.AADeploy_Favorites.LowerBackground';
	//AddFavoriteServer = GUIButton'AGP_Interface.AADeploy_Favorites.AddFavoriteServerButton';
	//AddBuddy = GUIButton'AGP_Interface.AADeploy_Favorites.AddBuddyButton';
	//RemoveSelected = GUIButton'AGP_Interface.AADeploy_Favorites.RemoveSelectedButton';
	//ServerCount = GUILabel'AGP_Interface.AADeploy_Favorites.ServerCountLabel';
	PanelCaption = "Favorite Servers and Battle Buddies";
}

void UAADeploy_Favorites::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	FavoritesAndServerListPanel.ClearLists();
	ServerCount.Caption = "";
	if (bShow)
	{
		if ((!HumanController(PlayerOwner()).bDisableAutoServerlistRetrieval) && FavoritesAndServerListPanel.IsValidDBMBSFilterList())
		{
			UpdateServerList(FavoritesAndServerListPanel.GetDBMBSFilterList());
		}
	}
	*/
}

void UAADeploy_Favorites::InternalOnPunkBusterChanged(bool PunkBusterEnabled)
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

void UAADeploy_Favorites::InternalOnUpdateServerList()
{
	/*
	if (FavoritesAndServerListPanel.IsValidDBMBSFilterList())
	{
		UpdateServerList(FavoritesAndServerListPanel.GetDBMBSFilterList());
	}
	else
	{
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Cannot obtain server list.", "The selected Favorites list is empty.");
	}
	*/
}

void UAADeploy_Favorites::InternalOnJoinServer()
{
	//FavoritesAndServerListPanel.JoinCurrentlySelectedServer();
}

void UAADeploy_Favorites::CloseEnumerationDialog()
{
	/*
	if (None != AAEnumeratingServersModalDialog(Controller.TopPage()))
	{
		Controller.CloseMenu();
	}
	*/
}

void UAADeploy_Favorites::InternalOnUpdateServerListFailed(FString Reason)
{
	/*
	CloseEnumerationDialog();
	Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Internet Servers Failure", Reason);
	*/
}

void UAADeploy_Favorites::InternalOnReceivedServer(int32 Index)
{
	/*
	local int32 NumServers;
	local IpDrv.ServerBrowserBase ServerBrowser;
	CloseEnumerationDialog();
	ServerBrowser = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser();
	NumServers = ServerBrowser.GetNumServers();
	ServerCount.Caption = string(NumServers) @ "server" $ Eval((NumServers != 1), "s", "");
	FavoritesAndServerListPanel.ReceivedServer(Index);
	*/
}

void UAADeploy_Favorites::UpdateServerList(TArray<FFilterItem> FilterList)
{
	/*
	local IpDrv.ServerBrowserBase ServerBrowser;
	ServerBrowser = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser();
	if (PlayerOwner() == None)
	{
		return;
	}
	if (None == AAEnumeratingServersModalDialog(Controller.TopPage()))
	{
		Controller.OpenMenu("AGP_Interface.AAEnumeratingServersModalDialog");
	}
	ServerCount.Caption = "";
	ServerBrowser.__OnReceivedServer__Delegate = InternalOnReceivedServer;
	ServerBrowser.__OnUpdateServerListFailed__Delegate = InternalOnUpdateServerListFailed;
	ServerBrowser.SetPublic(true);
	ServerBrowser.SetFilterList(FilterList);
	ServerBrowser.UpdateServerList();
	*/
}

bool UAADeploy_Favorites::InternalOnClick(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case AddFavoriteServer:
		if (Controller.OpenMenu("AGP_Interface.AAGetDataMenu", "Add a favorite server"))
		{
			Controller.ActivePage.__OnClose__Delegate = AddFavoriteServerClosed;
		}
		return true;
		break;
	case AddBuddy:
		if (Controller.OpenMenu("AGP_Interface.AAGetDataMenu", "Add a buddy"))
		{
			Controller.ActivePage.__OnClose__Delegate = AddBuddyClosed;
		}
		return true;
		break;
	case RemoveSelected:
		FavoritesAndServerListPanel.RemoveSelected();
		break;
	default:
	}
	*/
	return false;
}

void UAADeploy_Favorites::AddFavoriteServerClosed(bool bCancelled)
{
	if (!bCancelled)
	{
		//FavoritesAndServerListPanel.AddFavoriteServer(AAGetDataMenu(Controller.ActivePage).ed_Data.GetText());
	}
}

void UAADeploy_Favorites::AddBuddyClosed(bool bCancelled)
{
	if (!bCancelled)
	{
		//FavoritesAndServerListPanel.AddBattleBuddy(AAGetDataMenu(Controller.ActivePage).ed_Data.GetText());
	}
}
