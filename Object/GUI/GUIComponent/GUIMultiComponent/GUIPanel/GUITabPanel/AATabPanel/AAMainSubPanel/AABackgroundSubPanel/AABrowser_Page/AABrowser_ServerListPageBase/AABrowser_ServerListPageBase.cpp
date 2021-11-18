// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageBase.h"

UAABrowser_ServerListPageBase::UAABrowser_ServerListPageBase()
{
	/*
	Begin Object Class=GUIButton Name=BrowserFilter
		Caption="FILTERS"
		StyleName="SquareMenuButton"
		Hint="Filters allow more control over which servers will appear in the server browser lists."
		WinTop=0.93
		WinLeft=0.33
		WinWidth=0.15
		WinHeight=0.053476
		RenderWeight=2
		TabOrder=4
		bBoundToParent=True
		OnClick=AABrowser_ServerListPageBase.InternalOnClick
		OnKeyEvent=BrowserFilter.InternalOnKeyEvent
	End Object
	Begin Object Class=GUIButton Name=BrowserRefresh
		Caption="REFRESH"
		StyleName="SquareMenuButton"
		Hint="Refresh server browser lists."
		WinTop=0.852793
		WinLeft=0.01
		WinWidth=0.15
		WinHeight=0.053476
		RenderWeight=2
		TabOrder=0
		bBoundToParent=True
		OnClick=AABrowser_ServerListPageBase.InternalOnClick
		OnKeyEvent=BrowserRefresh.InternalOnKeyEvent
	End Object
	Begin Object Class=GUIButton Name=BrowserSpec
		Caption="SPECTATE"
		StyleName="SquareMenuButton"
		Hint="Spectate the selected server."
		WinTop=0.852793
		WinLeft=0.17
		WinWidth=0.15
		WinHeight=0.053476
		RenderWeight=2
		TabOrder=1
		bBoundToParent=True
		OnClick=AABrowser_ServerListPageBase.InternalOnClick
		OnKeyEvent=BrowserSpec.InternalOnKeyEvent
	End Object
	Begin Object Class=GUIButton Name=BrowserJoin
		Caption="JOIN"
		StyleName="SquareMenuButton"
		Hint="Join the selected server."
		WinTop=0.852793
		WinLeft=0.33
		WinWidth=0.15
		WinHeight=0.053476
		RenderWeight=2
		TabOrder=2
		bBoundToParent=True
		OnClick=AABrowser_ServerListPageBase.InternalOnClick
		OnKeyEvent=BrowserJoin.InternalOnKeyEvent
	End Object
	Begin Object Class=moComboBox Name=BrowserSwitcher
		bReadOnly=True
		ComponentJustification=0
		CaptionWidth=0.27
		Caption="Browser:"
		OnCreateComponent=BrowserSwitcher.InternalOnCreateComponent
		FontScale=0
		Hint="Change the system which locates servers on the Internet."
		WinTop=0.916216
		WinLeft=0.006753
		WinWidth=0.312987
		WinHeight=0.032432
		TabOrder=3
		bBoundToParent=True
		OnChange=AABrowser_ServerListPageBase.InternalOnChange
	End Object
	Begin Object Class=moCheckBox Name=PunkBusterCheckBox
		CaptionWidth=0.9
		Caption="Enable PunkBuster"
		OnCreateComponent=PunkBusterCheckBox.InternalOnCreateComponent
		FontScale=0
		Hint="Check this box to enable PunkBuster."
		WinTop=0.944414
		WinLeft=0.031104
		WinWidth=0.3
		WinHeight=0.053476
		TabOrder=4
		bBoundToParent=True
		bScaleToParent=True
		bStandardized=False
	End Object
	Begin Object Class=moEditBox Name=PasswordBox
		CaptionWidth=0.25
		Caption="Password"
		OnCreateComponent=PasswordBox.InternalOnCreateComponent
		Hint="Enter a Password that you would like to use when joining a server."
		WinTop=0.93
		WinLeft=0.52
		WinWidth=0.45
		WinHeight=0.053476
		TabOrder=5
		bBoundToParent=True
		bScaleToParent=True
		bStandardized=False
	End Object
	Begin Object Class=GUISplitter Name=HorzSplitter
		DefaultPanels="AGP_Interface.AABrowser_ServerListBox"
		DefaultPanels="XInterface.GUISplitter"
		MaxPercentage=0.9
		OnReleaseSplitter=AABrowser_ServerListPageBase.InternalReleaseSplitter
		OnCreateComponent=AABrowser_ServerListPageBase.InternalOnCreateComponent
		IniOption="@Internal"
		WinTop=0.01
		WinLeft=0.01
		WinWidth=0.98
		WinHeight=0.84
		RenderWeight=1
		OnLoadINI=AABrowser_ServerListPageBase.InternalOnLoadINI
	End Object
	Begin Object Class=GUILabel Name=BrowserStatus
		Caption="Ready"
		TextAlign=2
		FontScale=0
		StyleName="TextLabel"
		WinTop=0.86
		WinLeft=0.52
		WinWidth=0.45
		WinHeight=0.053476
		bBoundToParent=True
		bScaleToParent=True
		OnPreDraw=AABrowser_ServerListPageBase.PreDrawStatus
	End Object
	*/
	//sp_Main = GUISplitter'AGP_Interface.AABrowser_ServerListPageBase.HorzSplitter';
	//l_StatusBar = GUILabel'AGP_Interface.AABrowser_ServerListPageBase.BrowserStatus';
	//b_Join = GUIButton'AGP_Interface.AABrowser_ServerListPageBase.BrowserJoin';
	//b_Spectate = GUIButton'AGP_Interface.AABrowser_ServerListPageBase.BrowserSpec';
	//b_Refresh = GUIButton'AGP_Interface.AABrowser_ServerListPageBase.BrowserRefresh';
	//b_Filter = GUIButton'AGP_Interface.AABrowser_ServerListPageBase.BrowserFilter';
	//co_BrowserSwitcher = moComboBox'AGP_Interface.AABrowser_ServerListPageBase.BrowserSwitcher';
	//ch_PunkBuster = moCheckBox'AGP_Interface.AABrowser_ServerListPageBase.PunkBusterCheckBox';
	//ed_Password = moEditBox'AGP_Interface.AABrowser_ServerListPageBase.PasswordBox';
	//RulesListBoxClass = "AGP_Interface.AABrowser_RulesListBox";
	//PlayersListBoxClass = "AGP_Interface.AABrowser_PlayersListBox";
	//MainSplitterPosition = 0.665672;
	//DetailSplitterPosition = 0.460938;

	/*
	HeaderColumnSizes2512(0) = (
		ColumnSizes(0) = 0.08
		ColumnSizes(1) = 0.08
		ColumnSizes(2) = 0.37
		ColumnSizes(3) = 0.25
		ColumnSizes(4) = 0.11
		ColumnSizes(5) = 0.11)
	HeaderColumnSizes2512(1) = (ColumnSizes(0) = 0.4
		ColumnSizes(1) = 0.6)
	HeaderColumnSizes2512(2) = (ColumnSizes(0) = 0.56
		ColumnSizes(1) = 0.22
		ColumnSizes(2) = 0.22)
	*/
	bAllowUpdates = true;
	PingingText = "Pinging Servers ( %NumRec% / %TotalNum% )";
	PingCompleteText = "Pinging Complete! %NumServers% Servers, %NumPlayers% Players";
	BrowserSwitchWarning = "You are about to change your current Browser. This will change the information that is displayed on your screen, change your server filtering capabilities and may result in a change of which game servers show up in the browser. Are you sure you wish to change your Internet game browser?";
	QueryCompleteString = "Query Complete! Received: %NumServers% Servers";
	PanelCaption = "Server Browser";
	IniOption = "@Internal";
	WinHeight = 0.8;
	//OnSaveINI = AABrowser_ServerListPageBase.InternalOnSaveINI;
}

void UAABrowser_ServerListPageBase::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	li_Rules = AABrowser_RulesList(lb_Rules.List);
	li_Players = AABrowser_PlayersList(lb_Players.List);
	if (HeaderColumnSizes2512.Length < 3)
	{
		ResetConfig("HeaderColumnSizes2512");
	}
	lb_Server.HeaderColumnPerc = HeaderColumnSizes2512[0].ColumnSizes;
	lb_Rules.HeaderColumnPerc = HeaderColumnSizes2512[1].ColumnSizes;
	lb_Players.HeaderColumnPerc = HeaderColumnSizes2512[2].ColumnSizes;
	lb_Server.TabOrder = 0;
	lb_Rules.TabOrder = 1;
	lb_Players.TabOrder = 2;
	co_BrowserSwitcher.addItem("AA Browser", , "AA Browser");
	co_BrowserSwitcher.addItem("GameSpy", , "GameSpy");
	ch_PunkBuster.__OnChange__Delegate = Browser.PunkBusterOptionChanged;
	ed_Password.__OnChange__Delegate = Browser.BrowserPasswordChanged;
	*/
}

void UAABrowser_ServerListPageBase::Opened(UGUIComponent* Sender)
{
	/*
	Super::Opened(Sender);
	if ((!bInit) && Controller.bAutoRefreshBrowser)
	{
		Refresh();
	}
	*/
}

void UAABrowser_ServerListPageBase::ShowPanel(bool bShow)
{
	/*
	if (PlayerOwner() == None)
	{
		return;
	}
	Super::ShowPanel(bShow);
	if (bShow)
	{
		if (bInit)
		{
			sp_Main.SplitterUpdatePositions();
			sp_Detail.SplitterUpdatePositions();
			Refresh();
		}
		else
		{
			Refresh();
			li_Server.AutopingServers();
		}
		ch_PunkBuster.SetComponentValue(string(bool(PlayerOwner().Level.PBIsEnabled())));
		ed_Password.SetComponentValue(Browser.sBrowserPassword);
		co_BrowserSwitcher.SetComponentValue(AGP_HUD(HumanController(PlayerOwner()).myHUD).ServerBrowser, true);
	}
	else
	{
		if (!bInit)
		{
			li_Server.OutstandingPings.remove(0, li_Server.OutstandingPings.Length);
		}
	}
	*/
}

void UAABrowser_ServerListPageBase::Refresh()
{
	/*
	Super::Refresh();
	if (li_Server == None)
	{
		InitServerList();
	}
	li_Server.Clear();
	*/
}

void UAABrowser_ServerListPageBase::InitServerList()
{
	/*
	if (li_Server == None)
	{
		li_Server = new (None) class'AGP_Interface.AABrowser_ServersList';
	}
	lb_Server.InitBaseList(li_Server);
	li_Server.__OnChange__Delegate = ServerListChanged;
	*/
}

void UAABrowser_ServerListPageBase::RefreshList()
{
	//li_Server.RePingServers();
}

void UAABrowser_ServerListPageBase::JoinClicked()
{
	//li_Server.Connect(false);
}

void UAABrowser_ServerListPageBase::SpectateClicked()
{
	//li_Server.Connect(true);
}

void UAABrowser_ServerListPageBase::UpdateStatusPingCount()
{
	/*
	local FString StatusText;
	CheckJoinButton(li_Server.IsValid());
	CheckSpectateButton(li_Server.IsValid());
	if (li_Server == None)
	{
		return;
	}
	if (li_Server.NumReceivedPings < li_Server.Servers.Length)
	{
		StatusText = Repl(PingingText, "%NumRec%", string(li_Server.NumReceivedPings));
		StatusText = Repl(StatusText, "%TotalNum%", string(li_Server.Servers.Length));
	}
	else
	{
		StatusText = Repl(QueryCompleteString, "%NumServers%", string(li_Server.Servers.Length));
		StatusText = Repl(StatusText, "%NumPlayers%", string(li_Server.NumPlayers));
	}
	SetFooterCaption(StatusText);
	*/
}

void UAABrowser_ServerListPageBase::CancelPings()
{
	/*
	Browser.Uplink().CancelPings();
	SetFooterCaption(ReadyString);
	*/
}

void UAABrowser_ServerListPageBase::PingServer(int32 ListID, EPingCause PingCause, FServerResponseLine S)
{
	/*
	if (PingCause == 1)
	{
		Browser.Uplink().PingServer(ListID, PingCause, S.IP, S.QueryPort, 3, S);
	}
	else
	{
		Browser.Uplink().PingServer(ListID, PingCause, S.IP, S.QueryPort, 0, S);
	}
	*/
}

void UAABrowser_ServerListPageBase::MousePressed(UGUIComponent* Sender, bool bRepeat)
{
	/*
	bAllowUpdates = false;
	if (GUIVertScrollBar(Sender.MenuOwner) != None)
	{
		GUIVertScrollBar(Sender.MenuOwner).GripPressed(Sender, bRepeat);
	}
	*/
}

void UAABrowser_ServerListPageBase::MouseReleased(UGUIComponent* Sender)
{
	bAllowUpdates = true;
}

void UAABrowser_ServerListPageBase::RefreshCurrentServer()
{
	/*
	local int32 i;
	local int32 j;
	if (Controller.ContextMenu != None)
	{
		return;
	}
	CheckSpectateButton(li_Server.IsValid());
	CheckJoinButton(li_Server.IsValid());
	i = li_Server.CurrentListId();
	if (i < 0)
	{
		return;
	}
	PingServer(i, 1, li_Server.Servers[i]);
	li_Players.Clear();
	for (j = 0; j < li_Server.Servers[i].PlayerInfo.Length; j++)
	{
		li_Players.SortList();
	}
	*/
}

void UAABrowser_ServerListPageBase::ServerListChanged(UGUIComponent* Sender)
{
	/*
	local int32 i;
	local IpDrv.ServerBrowserBase sbBase;
	local ServerBrowserBase.GameSpyServerItem ServerItem;
	Log("AABrowser_ServerListPageBase::ServerListChanged" @ string(Sender));
	if ((!bAllowUpdates) || (Controller.ContextMenu != None))
	{
		return;
	}
	li_Rules.Clear();
	li_Players.Clear();
	CheckSpectateButton(li_Server.IsValid());
	CheckJoinButton(li_Server.IsValid());
	i = li_Server.CurrentListId();
	if (i < 0)
	{
		return;
	}
	sbBase = AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser();
	if (sbBase != None)
	{
		if (li_Server.Index >= 0)
		{
			sbBase.GetSpecificServer(li_Server.Index, ServerItem);
			li_Rules.ItemCount = 16;
			li_Players.ItemCount = ServerItem.NumPlayers;
			sbBase.RefreshSpecificServer(li_Server.Index);
		}
	}
	li_Players.SortList();
	li_Rules.SortList();
	*/
}

void UAABrowser_ServerListPageBase::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if (AABrowser_ServerListBox(NewComp) != None)
	{
		lb_Server = AABrowser_ServerListBox(NewComp);
	}
	else
	{
		if (AABrowser_RulesListBox(NewComp) != None)
		{
			lb_Rules = AABrowser_RulesListBox(NewComp);
		}
		else
		{
			if (AABrowser_PlayersListBox(NewComp) != None)
			{
				lb_Players = AABrowser_PlayersListBox(NewComp);
			}
			else
			{
				if (GUISplitter(NewComp) != None)
				{
					sp_Detail = GUISplitter(NewComp);
					sp_Detail.DefaultPanels[0] = RulesListBoxClass;
					sp_Detail.DefaultPanels[1] = PlayersListBoxClass;
					sp_Detail.WinTop = 0;
					sp_Detail.WinLeft = 0;
					sp_Detail.WinWidth = 1;
					sp_Detail.WinHeight = 1;
					sp_Detail.bNeverFocus = true;
					sp_Detail.bAcceptsInput = true;
					sp_Detail.SplitOrientation = 1;
					sp_Detail.IniOption = "@Internal";
					sp_Detail.__OnCreateComponent__Delegate = InternalOnCreateComponent;
					sp_Detail.__OnLoadINI__Delegate = InternalOnLoadINI;
					sp_Detail.__OnReleaseSplitter__Delegate = InternalReleaseSplitter;
				}
			}
		}
	}
	*/
}

void UAABrowser_ServerListPageBase::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	if (Sender == sp_Main)
	{
		sp_Main.SplitPosition = MainSplitterPosition;
	}
	else
	{
		if (Sender == sp_Detail)
		{
			sp_Detail.SplitPosition = DetailSplitterPosition;
		}
	}
	ch_PunkBuster.SetComponentValue(string(Browser.bPunkBusterEnabled), true);
	*/
}

void UAABrowser_ServerListPageBase::InternalReleaseSplitter(UGUIComponent* Sender, float NewPos)
{
	/*
	if (Sender == sp_Main)
	{
		MainSplitterPosition = NewPos;
		SaveConfig();
	}
	else
	{
		if (Sender == sp_Detail)
		{
			DetailSplitterPosition = NewPos;
			SaveConfig();
		}
	}
	*/
}

FString UAABrowser_ServerListPageBase::InternalOnSaveINI(UGUIComponent* Sender)
{
	/*
	HeaderColumnSizes2512[0].ColumnSizes = lb_Server.HeaderColumnPerc;
	HeaderColumnSizes2512[1].ColumnSizes = lb_Rules.HeaderColumnPerc;
	HeaderColumnSizes2512[2].ColumnSizes = lb_Players.HeaderColumnPerc;
	SaveConfig();
	*/
	return "";
}

bool UAABrowser_ServerListPageBase::IsRefreshAvailable(FString& ButtonCaption)
{
	return true;
}

bool UAABrowser_ServerListPageBase::IsSpectateAvailable(FString& ButtonCaption)
{
	/*
	if ((li_Server != None) && li_Server.IsValid())
	{
		return true;
	}
	*/
	return false;
}

bool UAABrowser_ServerListPageBase::IsJoinAvailable(FString& ButtonCaption)
{
	/*
	if ((li_Server != None) && li_Server.IsValid())
	{
		return true;
	}
	*/
	return false;
}

void UAABrowser_ServerListPageBase::SetProgress(FString Progress)
{
	sProgress = Progress;
}

bool UAABrowser_ServerListPageBase::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (GUIButton(Sender) == None)
	{
		return false;
	}
	if (Sender == b_Join)
	{
		JoinClicked();
		return true;
	}
	if (Sender == b_Spectate)
	{
		SpectateClicked();
		return true;
	}
	if (Sender == b_Refresh)
	{
		RefreshClicked();
		return true;
	}
	if (Sender == b_Filter)
	{
		FilterClicked();
		return true;
	}
	*/
	return false;
}

void UAABrowser_ServerListPageBase::SwitchBrowserConfirm(bool bCancelled)
{
	/*
	if (!bCancelled)
	{
		AGP_HUD(HumanController(PlayerOwner()).myHUD).ServerBrowser = "GameSpy";
		AGP_HUD(HumanController(PlayerOwner()).myHUD).SaveConfig();
		Refresh();
	}
	else
	{
		co_BrowserSwitcher.SetComponentValue("AA Browser", true);
	}
	*/
}

void UAABrowser_ServerListPageBase::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Sender == co_BrowserSwitcher)
	{
		if (!(co_BrowserSwitcher.GetText() ~= "AA Browser"))
		{
			if (!class'AGP_Interface.AABrowserSwitchWarningPage'.Default.Disabled)
			{
				Controller.OpenMenu("AGP_Interface.AABrowserSwitchWarningPage");
				Controller.ActivePage.__OnClose__Delegate = SwitchBrowserConfirm;
			}
			else
			{
				SwitchBrowserConfirm(false);
			}
		}
		else
		{
			AGP_HUD(HumanController(PlayerOwner()).myHUD).ServerBrowser = "AA Browser";
			AGP_HUD(HumanController(PlayerOwner()).myHUD).SaveConfig();
			Refresh();
		}
	}
	*/
}

bool UAABrowser_ServerListPageBase::PreDrawStatus(UCanvas* C)
{
	/*
	if (sProgress != "")
	{
		l_StatusBar.Caption = sProgress;
	}
	else
	{
		l_StatusBar.Caption = "Ready";
	}
	*/
	return false;
}
