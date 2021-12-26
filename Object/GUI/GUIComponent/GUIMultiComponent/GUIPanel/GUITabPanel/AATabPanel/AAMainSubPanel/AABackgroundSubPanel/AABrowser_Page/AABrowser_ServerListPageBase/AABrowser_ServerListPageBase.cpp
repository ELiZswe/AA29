// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUISplitter/GUISplitter.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAABrowser_ServerListPageBase::UAABrowser_ServerListPageBase()
{
	UGUIButton* BrowserFilter = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BrowserFilter->Caption = "FILTERS";
	BrowserFilter->StyleName = "SquareMenuButton";
	BrowserFilter->Hint = "Filters allow more control over which servers will appear in the server browser lists.";
	BrowserFilter->WinTop = 0.93;
	BrowserFilter->WinLeft = 0.33;
	BrowserFilter->WinWidth = 0.15;
	BrowserFilter->WinHeight = 0.053476;
	BrowserFilter->RenderWeight = 2;
	BrowserFilter->TabOrder = 4;
	BrowserFilter->bBoundToParent = true;
	//BrowserFilter->OnClick=AABrowser_ServerListPageBase.InternalOnClick;
	//BrowserFilter->OnKeyEvent=BrowserFilter.InternalOnKeyEvent;
	UGUIButton* BrowserRefresh = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BrowserRefresh->Caption = "REFRESH";
	BrowserRefresh->StyleName = "SquareMenuButton";
	BrowserRefresh->Hint = "Refresh server browser lists.";
	BrowserRefresh->WinTop = 0.852793;
	BrowserRefresh->WinLeft = 0.01;
	BrowserRefresh->WinWidth = 0.15;
	BrowserRefresh->WinHeight = 0.053476;
	BrowserRefresh->RenderWeight = 2;
	BrowserRefresh->TabOrder = 0;
	BrowserRefresh->bBoundToParent = true;
	//BrowserRefresh->OnClick=AABrowser_ServerListPageBase.InternalOnClick;
	//BrowserRefresh->OnKeyEvent=BrowserRefresh.InternalOnKeyEvent;
	UGUIButton* BrowserSpec = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BrowserSpec->Caption = "SPECTATE";
	BrowserSpec->StyleName = "SquareMenuButton";
	BrowserSpec->Hint = "Spectate the selected server.";
	BrowserSpec->WinTop = 0.852793;
	BrowserSpec->WinLeft = 0.17;
	BrowserSpec->WinWidth = 0.15;
	BrowserSpec->WinHeight = 0.053476;
	BrowserSpec->RenderWeight = 2;
	BrowserSpec->TabOrder = 1;
	BrowserSpec->bBoundToParent = true;
	//BrowserSpec->OnClick=AABrowser_ServerListPageBase.InternalOnClick;
	//BrowserSpec->OnKeyEvent=BrowserSpec.InternalOnKeyEvent;
	UGUIButton* BrowserJoin = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BrowserJoin->Caption = "JOIN";
	BrowserJoin->StyleName = "SquareMenuButton";
	BrowserJoin->Hint = "Join the selected server.";
	BrowserJoin->WinTop = 0.852793;
	BrowserJoin->WinLeft = 0.33;
	BrowserJoin->WinWidth = 0.15;
	BrowserJoin->WinHeight = 0.053476;
	BrowserJoin->RenderWeight = 2;
	BrowserJoin->TabOrder = 2;
	BrowserJoin->bBoundToParent = true;
	//BrowserJoin->OnClick=AABrowser_ServerListPageBase.InternalOnClick;
	//BrowserJoin->OnKeyEvent=BrowserJoin.InternalOnKeyEvent;
	UmoComboBox* BrowserSwitcher = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	BrowserSwitcher->bReadOnly = true;
	BrowserSwitcher->ComponentJustification = EeTextAlign::TXTA_Left;
	BrowserSwitcher->CaptionWidth = 0.27;
	BrowserSwitcher->Caption = "Browser:";
	//BrowserSwitcher->OnCreateComponent=BrowserSwitcher.InternalOnCreateComponent;
	BrowserSwitcher->FontScale = EFontScale::FNS_Small;
	BrowserSwitcher->Hint = "Change the system which locates servers on the Internet.";
	BrowserSwitcher->WinTop = 0.916216;
	BrowserSwitcher->WinLeft = 0.006753;
	BrowserSwitcher->WinWidth = 0.312987;
	BrowserSwitcher->WinHeight = 0.032432;
	BrowserSwitcher->TabOrder = 3;
	BrowserSwitcher->bBoundToParent = true;
	//BrowserSwitcher->OnChange=AABrowser_ServerListPageBase.InternalOnChange;
	UmoCheckBox* PunkBusterCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	PunkBusterCheckBox->CaptionWidth = 0.9;
	PunkBusterCheckBox->Caption = "Enable PunkBuster";
	//PunkBusterCheckBox->OnCreateComponent=PunkBusterCheckBox.InternalOnCreateComponent;
	PunkBusterCheckBox->FontScale = EFontScale::FNS_Small;
	PunkBusterCheckBox->Hint = "Check this box to enable PunkBuster.";
	PunkBusterCheckBox->WinTop = 0.944414;
	PunkBusterCheckBox->WinLeft = 0.031104;
	PunkBusterCheckBox->WinWidth = 0.3;
	PunkBusterCheckBox->WinHeight = 0.053476;
	PunkBusterCheckBox->TabOrder = 4;
	PunkBusterCheckBox->bBoundToParent = true;
	PunkBusterCheckBox->bScaleToParent = true;
	PunkBusterCheckBox->bStandardized = false;
	UmoEditBox* PasswordBox = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	PasswordBox->CaptionWidth = 0.25;
	PasswordBox->Caption = "Password";
	//PasswordBox->OnCreateComponent=PasswordBox.InternalOnCreateComponent;
	PasswordBox->Hint = "Enter a Password that you would like to use when joining a server.";
	PasswordBox->WinTop = 0.93;
	PasswordBox->WinLeft = 0.52;
	PasswordBox->WinWidth = 0.45;
	PasswordBox->WinHeight = 0.053476;
	PasswordBox->TabOrder = 5;
	PasswordBox->bBoundToParent = true;
	PasswordBox->bScaleToParent = true;
	PasswordBox->bStandardized = false;
	UGUISplitter* HorzSplitter = NewObject<UGUISplitter>(UGUISplitter::StaticClass());
	HorzSplitter->DefaultPanels = "AGP_Interface.AABrowser_ServerListBox";
	HorzSplitter->DefaultPanels = "XInterface.GUISplitter";
	HorzSplitter->MaxPercentage = 0.9;
	//HorzSplitter->OnReleaseSplitter = AABrowser_ServerListPageBase.InternalReleaseSplitter;
	//HorzSplitter->OnCreateComponent=AABrowser_ServerListPageBase.InternalOnCreateComponent;
	HorzSplitter->IniOption = "@Internal";
	HorzSplitter->WinTop = 0.01;
	HorzSplitter->WinLeft = 0.01;
	HorzSplitter->WinWidth = 0.98;
	HorzSplitter->WinHeight = 0.84;
	HorzSplitter->RenderWeight = 1;
	//HorzSplitter->OnLoadINI=AABrowser_ServerListPageBase.InternalOnLoadINI;
	UGUILabel* BrowserStatus = NewObject<UGUILabel>(UGUILabel::StaticClass());
	BrowserStatus->Caption = "Ready";
	BrowserStatus->TextAlign = ETextAlign::TXTA_Right;
	BrowserStatus->FontScale = EFontScale::FNS_Small;
	BrowserStatus->StyleName = "TextLabel";
	BrowserStatus->WinTop = 0.86;
	BrowserStatus->WinLeft = 0.52;
	BrowserStatus->WinWidth = 0.45;
	BrowserStatus->WinHeight = 0.053476;
	BrowserStatus->bBoundToParent = true;
	BrowserStatus->bScaleToParent = true;
	//BrowserStatus->OnPreDraw=AABrowser_ServerListPageBase.PreDrawStatus;
	sp_Main = HorzSplitter;
	l_StatusBar = BrowserStatus;
	b_Join = BrowserJoin;
	b_Spectate = BrowserSpec;
	b_Refresh = BrowserRefresh;
	b_Filter = BrowserFilter;
	co_BrowserSwitcher = BrowserSwitcher;
	ch_PunkBuster = PunkBusterCheckBox;
	ed_Password = PasswordBox;
	RulesListBoxClass = "AGP_Interface.AABrowser_RulesListBox";
	PlayersListBoxClass = "AGP_Interface.AABrowser_PlayersListBox";
	MainSplitterPosition = 0.665672;
	DetailSplitterPosition = 0.460938;
	HeaderColumnSizes2512 = { { { 0.08,0.08,0.37,0.25,0.11,0.11 } },	{ { 0.4,0.6 } },	{ { 0.56,0.22,0.22 } } };
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
	if (PlayerOwner() == nullptr)
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
	if (li_Server == nullptr)
	{
		InitServerList();
	}
	li_Server.Clear();
	*/
}

void UAABrowser_ServerListPageBase::InitServerList()
{
	/*
	if (li_Server == nullptr)
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
	if (li_Server == nullptr)
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
	local FGameSpyServerItem ServerItem;
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
	if (GUIButton(Sender) == nullptr)
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
