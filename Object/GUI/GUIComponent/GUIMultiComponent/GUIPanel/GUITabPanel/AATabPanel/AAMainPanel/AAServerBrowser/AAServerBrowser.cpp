// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AAServerBrowser/AAServerBrowser.h"

UAAServerBrowser::UAAServerBrowser()
{
	bStandardServersOnly = true;
	CurrentGameType = "AGP_Gameplay.AGP_GameTeamObjective";
	InternetSettingsPage = "AGP_Interface.AAInternetSettingsPage";
	InternetOptionsText = "You have not fully configured your internet play options.  It is recommended that you configure a unique player name and review your netspeed setting before joining a multiplayer game.|Would you like to do this now?";
	OfficialSubnets = { "69.25.22.", "64.74.139." };
	PanelClasses = { "AGP_Interface.AADeploy_Missions","AGP_Interface.AABrowser_ServerListPageInternet","AGP_Interface.AABrowser_ServerListPageLAN","AGP_Interface.AABrowser_IRC","AGP_Interface.AADeploy_Services" };
	PanelCaptions = { "Missions", "Internet", "LAN", "Chat", "Services" };
	PanelHints = { "Deploy with teams for online missions",	"Play online missions on servers over the Internet", "View all America's Army servers currently running on your LAN", "America's Army integrated IRC client", "America's Army Services and Server Solutions" };
	PanelCaption = "(\"News\",\"Chat\",\"Favorites\",\"LAN\",\"Buddies\",\"Internet\")";
	bDrawFocusedLast = false;
}

void UAAServerBrowser::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	CreateTabs();
	*/
}

AMasterServerClient* UAAServerBrowser::Uplink()
{
	/*
	if ((MSC == None) && (PlayerOwner() != None))
	{
		MSC = PlayerOwner().Spawn(Class'IpDrv.MasterServerClient');
	}
	*/
	return MSC;
}

void UAAServerBrowser::Opened(UGUIComponent* Sender)
{
	/*
	Super::Opened(Sender);
	bHideNetworkMessage = false;
	if ((tp_Active != None) && (t_Footer != None))
	{
		AABrowser_Footer(t_Footer).UpdateActiveButtons(tp_Active);
	}
	*/
}

void UAAServerBrowser::Closed(UGUIComponent* Sender, bool bCancelled)
{
	/*
	Super::Closed(Sender, bCancelled);
	if (MSC != None)
	{
		MSC.CancelPings();
	}
	SaveConfig();
	*/
}

bool UAAServerBrowser::ComboOnPreDraw(UCanvas* Canvas)
{
	return false;
}

void UAAServerBrowser::InitializeGameTypeCombo(bool ClearFirst)
{
	/*
	local int32 i;
	local int32 j;
	local AABrowser_ServersList ListObj;
	local TArray<CacheManager.MapRecord> Maps;
	co_GameType.MyComboBox.MaxVisibleItems = 10;
	PopulateGameTypes();
	if (ClearFirst)
	{
		co_GameType.MyComboBox.List.Clear();
	}
	j = -1;
	for (i = 0; i < Records.Length; i++)
	{
		Class'CacheManager'.GetMapList(Maps, Records[i].MapPrefix);
		if (Maps.Length == 0)
		{
		}
		ListObj = new (None) class'AGP_Interface.AABrowser_ServersList';
		co_GameType.addItem(Records[i].GameName, ListObj, Records[i].ClassName);
		if (Records[i].ClassName ~= CurrentGameType)
		{
			j = i;
		}
	}
	if (j != -1)
	{
		co_GameType.SetIndex(j);
		SetFilterInfo();
	}
	*/
}

void UAAServerBrowser::BrowserOpened()
{
	/*
	if (!bPlayerVerified)
	{
		CheckPlayerOptions();
	}
	*/
}

void UAAServerBrowser::MOTDVerified(bool bMSVerified)
{
	/*
	EnableMSTabs();
	Verified = bMSVerified;
	*/
}

void UAAServerBrowser::CheckPlayerOptions()
{
	/*
	local PlayerController PC;
	local FString CurrentName;
	PC = PlayerOwner();
	if (PC.PlayerReplicationInfo != None)
	{
		CurrentName = PC.PlayerReplicationInfo.PlayerName;
	}
	else
	{
		CurrentName = PC.GetUrlOption("Name");
	}
	if (((CurrentName ~= "Recruit") || (CurrentName ~= "Player")) || (Class'Player'.Default.ConfiguredInternetSpeed == 9636))
	{
		if (Controller.OpenMenu(Controller.QuestionMenuClass))
		{
			GUIQuestionPage(Controller.ActivePage).SetupQuestion("", 50);
			GUIQuestionPage(Controller.ActivePage).__NewOnButtonClick__Delegate = InternetOptionsConfirm;
		}
	}
	else
	{
		bPlayerVerified = true;
		SaveConfig();
	}
	*/
}

bool UAAServerBrowser::InternetOptionsConfirm(uint8 ButtonMask)
{
	/*
	local XInterface.GUIQuestionPage pg;
	if (bool((ButtonMask & 32)))
	{
		return true;
	}
	if (bool((ButtonMask & 2)))
	{
		bPlayerVerified = true;
		SaveConfig();
		return true;
	}
	pg = GUIQuestionPage(Controller.ActivePage);
	if (pg == None)
	{
		return true;
	}
	if (bool((ButtonMask & 16)))
	{
		if (Controller.ReplaceMenu(InternetSettingsPage))
		{
			Controller.ActivePage.__OnClose__Delegate = InternetOptionsClosed;
		}
		return true;
	}
	*/
	return false;
}

void UAAServerBrowser::InternetOptionsClosed(bool bCancelled)
{
	/*
	bPlayerVerified = true;
	SaveConfig();
	*/
}

void UAAServerBrowser::CreateTabs()
{
	/*
	local int32 i;
	i = 0;
	if (((i < PanelCaptions.Length) && (i < PanelClasses.Length)) && (i < PanelHints.Length))
	{
		if (PanelClasses[i] != "")
		{
			AddTab(PanelCaptions[i], PanelClasses[i], PanelHints[i]);
		}
		i++;
	}
	DisableMSTabs();
	RefreshFooter(AABrowser_Page(c_Tabs.ActiveTab.MyPanel), "false");
	*/
}

void UAAServerBrowser::EnableMSTabs()
{
	/*
	local AABrowser_ServerListPageBuddy BuddyPanel;
	local int32 i;
	i = c_Tabs.TabIndex(PanelCaptions[4]);
	if (i != -1)
	{
		EnableComponent(c_Tabs.TabStack[i]);
		BuddyPanel = AABrowser_ServerListPageBuddy(c_Tabs.TabStack[i].MyPanel);
	}
	i = c_Tabs.TabIndex(PanelCaptions[5]);
	if (i != -1)
	{
		EnableComponent(c_Tabs.TabStack[i]);
	}
	if (BuddyPanel == None)
	{
		return;
	}
	for (i = 0; i < c_Tabs.TabStack.Length; i++)
	{
		if (AABrowser_ServerListPageBase(c_Tabs.TabStack[i].MyPanel) != None)
		{
			if (AABrowser_ServerListPageBase(c_Tabs.TabStack[i].MyPanel).lb_Players != None)
			{
				AABrowser_ServerListPageBase(c_Tabs.TabStack[i].MyPanel).lb_Players.tp_Buddy = BuddyPanel;
			}
		}
	}
	*/
}

void UAAServerBrowser::DisableMSTabs()
{
	/*
	local int32 i;
	Verified = false;
	for (i = 0; i < c_Tabs.TabStack.Length; i++)
	{
		if (AABrowser_ServerListPageBase(c_Tabs.TabStack[i].MyPanel) != None)
		{
			if (AABrowser_ServerListPageBase(c_Tabs.TabStack[i].MyPanel).lb_Players != None)
			{
				AABrowser_ServerListPageBase(c_Tabs.TabStack[i].MyPanel).lb_Players.tp_Buddy = None;
			}
		}
	}
	*/
}

UAABrowser_Page* UAAServerBrowser::AddTab(FString TabCaption, FString PanelClassName, FString TabHint)
{
	UAABrowser_Page* Tab=nullptr;
	/*
	local int32 i;
	if (((TabCaption != "") && (PanelClassName != "")) && (TabHint != ""))
	{
		Tab = AABrowser_Page(c_Tabs.AddTab(TabCaption, PanelClassName, , TabHint));
		if (Tab == None)
		{
			i = 0;
			if (i < c_Tabs.TabStack.Length)
			{
				if (c_Tabs.TabStack[i].Caption ~= TabCaption)
				{
					Tab = AABrowser_Page(c_Tabs.TabStack[i].MyPanel);
				}
				else
				{
					i++;
				}
			}
		}
		if (Tab != None)
		{
			Tab.__RefreshFooter__Delegate = RefreshFooter;
			Tab.__OnOpenConnection__Delegate = ConnectionOpened;
			Tab.__OnCloseConnection__Delegate = ConnectionClosed;
		}
	}
	*/
	return Tab;
}

void UAAServerBrowser::OnAddFavorite(FServerResponseLine Server)
{
}

bool UAAServerBrowser::NotifyLevelChange()
{
	/*
	if (MSC != None)
	{
		MSC.Stop();
		MSC.Destroy();
	}
	MSC = None;
	LevelChanged();
	*/
	return false;
}

void UAAServerBrowser::InternalOnChange(UGUIComponent* Sender)
{
}

void UAAServerBrowser::StandardOptionChanged(UGUIComponent* Sender)
{
	//SetStandardServersOption(moCheckBox(Sender).IsChecked());
}

void UAAServerBrowser::SetStandardServersOption(bool bOnlyStandard)
{
	/*
	if (bOnlyStandard != bStandardServersOnly)
	{
		bStandardServersOnly = bOnlyStandard;
		SaveConfig();
		Refresh();
	}
	*/
}

void UAAServerBrowser::RefreshFooter(UAABrowser_Page* NewActive, FString bPerButtonSizes)
{
	/*
	if (NewActive != None)
	{
		tp_Active = NewActive;
		if (AABrowser_Footer(t_Footer) != None)
		{
			AABrowser_Footer(t_Footer).UpdateActiveButtons(tp_Active);
		}
	}
	if (t_Footer != None)
	{
		t_Footer.SetupButtons(bPerButtonSizes);
	}
	*/
}

void UAAServerBrowser::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	local int32 i;
	if (Sender == co_GameType)
	{
		if (CurrentGameType == "")
		{
			CurrentGameType = S;
			SaveConfig();
			i = co_GameType.FindExtra(CurrentGameType);
			if (i != -1)
			{
				co_GameType.SetIndex(i);
			}
			SetFilterInfo();
		}
	}
	*/
}

void UAAServerBrowser::PopulateGameTypes()
{
	/*
	local TArray<CacheManager.GameRecord> Games;
	local int32 i;
	local int32 j;
	if (Records.Length > 0)
	{
		Records.remove(0, Records.Length);
	}
	Class'CacheManager'.GetGameTypeList(Games);
	for (i = 0; i < Games.Length; i++)
	{
		j = 0;
		if (j < Records.Length)
		{
			if ((Games[i].GameName <= Records[j].GameName) || (Games[i].GameTypeGroup <= Records[j].GameTypeGroup))
			{
				if (Games[i].GameTypeGroup <= Records[j].GameTypeGroup)
				{
				}
				else
				{
				}
			}
			else
			{
				j++;
			}
		}
		Records.insert(j, 1);
		Records[j] = Games[i];
	}
	*/
}

/*
FString UAAServerBrowser::GetDesc(FString Desc)
{
	local int32 i;
	i = InStr(Desc, "|");
	if (i >= 0)
	{
		Desc = Mid(Desc, (i + 1));
	}
	i = InStr(Desc, "|");
	if (i >= 0)
	{
		Desc = Left(Desc, i);
	}
	return Desc;
}
	*/

void UAAServerBrowser::SetFilterInfo(FString NewGameType)
{
	/*
	local class<GameInfo>  GI;
	local class<AccessControl>  AC;
	local class<Mutator>  mut;
	Assert((FilterInfo != None));
	FilterInfo.Clear();
	if (NewGameType == "")
	{
		NewGameType = CurrentGameType;
	}
	GI = class<GameInfo>(DynamicLoadObject(NewGameType, Class'Class'));
	if (GI != None)
	{
		GI.FillPlayInfo(FilterInfo);
		FilterInfo.PopClass();
		AC = class<AccessControl>(DynamicLoadObject(GI.Default.AccessControlClass, Class'Class'));
		if (AC != None)
		{
			AC.FillPlayInfo(FilterInfo);
			FilterInfo.PopClass();
		}
		mut = class<Mutator>(DynamicLoadObject(GI.Default.MutatorClass, Class'Class'));
		if (mut != None)
		{
			mut.FillPlayInfo(FilterInfo);
			FilterInfo.PopClass();
		}
	}
	*/
}

void UAAServerBrowser::JoinClicked()
{
	/*
	if (tp_Active != None)
	{
		tp_Active.JoinClicked();
	}
	*/
}

void UAAServerBrowser::SpectateClicked()
{
	/*
	if (tp_Active != None)
	{
		tp_Active.SpectateClicked();
	}
	*/
}

void UAAServerBrowser::RefreshClicked()
{
	/*
	if (tp_Active != None)
	{
		tp_Active.RefreshClicked();
	}
	*/
}

void UAAServerBrowser::FilterClicked()
{
	/*
	if (tp_Active != None)
	{
		tp_Active.FilterClicked();
	}
	*/
}

void UAAServerBrowser::Refresh()
{
	/*
	local int32 i;
	local FString dummy;
	if (c_Tabs == None)
	{
		return;
	}
	for (i = 0; i < c_Tabs.TabStack.Length; i++)
	{
		if (((c_Tabs.TabStack[i].MenuState != 4) && (AABrowser_Page(c_Tabs.TabStack[i].MyPanel) != None)) && AABrowser_Page(c_Tabs.TabStack[i].MyPanel).IsFilterAvailable(dummy))
		{
			c_Tabs.TabStack[i].MyPanel.Refresh();
		}
	}
	*/
}

int32 UAAServerBrowser::CalculateMaxConnections()
{
	/*
	local int32 i;
	if (Class'UGUIController*'.Default.MaxSimultaneousPings < 1)
	{
		i = Class'Player'.Default.ConfiguredInternetSpeed;
		if (i <= 2600)
		{
			return 10;
		}
		if (i <= 5000)
		{
			return 15;
		}
		if (i <= 10000)
		{
			return 20;
		}
		if (i <= 20000)
		{
			return 35;
		}
	}
	return Min(Class'UGUIController*'.Default.MaxSimultaneousPings, 35);
	*/
	return 0;    //FAKE   /ELiZ
}

int32 UAAServerBrowser::GetMaxConnections(bool bCurrentlyAvailable)
{
	int32 Max=0;
	/*
	Max = CalculateMaxConnections();
	if (bCurrentlyAvailable)
	{
		return (Max - ThreadCount);
	}
	*/
	return Max;
}

void UAAServerBrowser::ConnectionOpened(int32 Num)
{
	/*
	if (Num <= 0)
	{
		Num = 1;
	}
	(ThreadCount += Num);
	*/
}

void UAAServerBrowser::ConnectionClosed(int32 Num)
{
	/*
	if (Num <= 0)
	{
		Num = 1;
	}
	(ThreadCount -= Num);
	if (ThreadCount < 0)
	{
		ThreadCount = 0;
	}
	*/
}

void UAAServerBrowser::ClearServerCache()
{
	/*
	local int32 i;
	i = 0;
	if (i < ServerCache.Length)
	{
		if (ServerCache[i].GameType ~= CurrentGameType)
		{
			ServerCache.remove(i, 1);
		}
		else
		{
			i++;
		}
	}
	*/
}

void UAAServerBrowser::AddToServerCache(FServerResponseLine Entry)
{
	/*
	local int32 i;
	local TArray<FString> IpParts;
	local FString Subnet;
	local FString IP;
	Split(Entry.IP, ".", IpParts);
	i = 0;
	if (i < (IpParts.Length - 1))
	{
		Subnet = Subnet $ IpParts[i] $ ".";
		i++;
	}
	IP = IpParts[(IpParts.Length - 1)];
	for (i = 0; i < 2; i++)
	{
		if (OfficialSubnets[i] ~= Subnet)
		{
			Entry.IP = IP;
			ServerCache.insert(0, 1);
			ServerCache[0].GameType = CurrentGameType;
			ServerCache[0].SRL = Entry;
			ServerCache[0].SubnetIndex = i;
			return;
		}
	}
	*/
}

void UAAServerBrowser::GetFromServerCache(UAABrowser_ServersList* List)
{
	/*
	local int32 i;
	local FServerResponseLine SRL;
	for (i = 0; i < ServerCache.Length; i++)
	{
		if (ServerCache[i].GameType ~= CurrentGameType)
		{
			SRL = ServerCache[i].SRL;
			SRL.IP = OfficialSubnets[ServerCache[i].SubnetIndex] $ SRL.IP;
			SRL.MapName = "Unknown";
			List.MyOnReceivedServer(SRL);
		}
	}
	*/
}

void UAAServerBrowser::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	*/
}
/*
AServerBrowserBase* UAAServerBrowser::SBUplink(bool bLAN)
{
	//return AGP_HUD(HumanController(PlayerOwner()).myHUD).GetCurrentServerBrowser(bLAN);
	return nullptr;    //FAKE  /ELiZ
}
*/

void UAAServerBrowser::PunkBusterOptionChanged(UGUIComponent* Sender)
{
	//SetPunkBusterOption(moCheckBox(Sender).IsChecked());
}

void UAAServerBrowser::SetPunkBusterOption(bool bEnablePunkBuster)
{
	/*
	if (bEnablePunkBuster != bPunkBusterEnabled)
	{
		bPunkBusterEnabled = bEnablePunkBuster;
		SaveConfig();
		if (bPunkBusterEnabled)
		{
			PlayerOwner().Level.PBEnable();
		}
		else
		{
			PlayerOwner().Level.PBDisable();
		}
	}
	*/
}

void UAAServerBrowser::BrowserPasswordChanged(UGUIComponent* Sender)
{
	/*
	SetBrowserPassword(moEditBox(Sender).GetText());
	*/
}

void UAAServerBrowser::SetBrowserPassword(FString sPassword)
{
	/*
	if (sBrowserPassword != sPassword)
	{
		sBrowserPassword = sPassword;
		SaveConfig();
	}
	*/
}

void UAAServerBrowser::IconKeyClicked()
{
	/*
	if (tp_Active != None)
	{
		tp_Active.IconKeyClicked();
	}
	*/
}
