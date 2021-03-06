// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainPanel/AAServerBrowser/AAServerBrowser.h"
#include "AA29/Object/Actor/Info/MasterServerLink/ServerQueryClient/MasterServerClient/MasterServerClient.h"
#include "AA29/Object/Actor/ServerBrowserBase/ServerBrowserBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUIFooter/ButtonFooter/AABrowser_Footer/AABrowser_Footer.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_Page.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIMultiColumnList/ServerBrowserMCList/AABrowser_ServersList/AABrowser_ServersList.h"
#include "AA29/Object/BrowserFilters/BrowserFilters.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUIFooter/ButtonFooter/ButtonFooter.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUIHeader/GUIHeader.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/PlayInfo/PlayInfo.h"
#include "AA29/Object/Actor/Info/AccessControl/AccessControl.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "AA29/Object/Actor/Info/Mutator/Mutator.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageBuddy.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIQuestionPage/GUIQuestionPage.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/CacheManager/CacheManager.h"
#include "Engine/Canvas.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABrowser_Page/AABrowser_ServerListPageBase/AABrowser_ServerListPageBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"

UAAServerBrowser::UAAServerBrowser()
{
	OfficialSubnets.SetNum(2);
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
	if ((MSC == nullptr) && (PlayerOwner() != nullptr))
	{
		MSC = PlayerOwner().Spawn(AMasterServerClient::StaticClass());
	}
	*/
	return MSC;
}

void UAAServerBrowser::Opened(UGUIComponent* Sender)
{
	/*
	Super::Opened(Sender);
	bHideNetworkMessage = false;
	if ((tp_Active != nullptr) && (t_Footer != nullptr))
	{
		AABrowser_Footer(t_Footer).UpdateActiveButtons(tp_Active);
	}
	*/
}

void UAAServerBrowser::Closed(UGUIComponent* Sender, bool bCancelled)
{
	/*
	Super::Closed(Sender, bCancelled);
	if (MSC != nullptr)
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
	int32 i = 0;
	int32 j = 0;
	UAABrowser_ServersList* ListObj = nullptr;
	TArray<FMapRecord> Maps = {};
	/*
	co_GameType.MyComboBox.MaxVisibleItems = 10;
	PopulateGameTypes();
	if (ClearFirst)
	{
		co_GameType.MyComboBox.List.Clear();
	}
	j = -1;
	for (i = 0; i < Records.Num(); i++)
	{
		UCacheManager::StaticClass().GetMapList(Maps, Records[i].MapPrefix);
		if (Maps.Num() == 0)
		{
		}
		ListObj = new (None) UAABrowser_ServersList::StaticClass();
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
	if (!bPlayerVerified)
	{
		CheckPlayerOptions();
	}
}

void UAAServerBrowser::MOTDVerified(bool bMSVerified)
{
	EnableMSTabs();
	Verified = bMSVerified;
}

void UAAServerBrowser::CheckPlayerOptions()
{
	APlayerController* PC = nullptr;
	FString CurrentName = "";
	/*
	PC = PlayerOwner();
	if (PC.PlayerReplicationInfo != nullptr)
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
	UGUIQuestionPage* pg = nullptr;
	/*
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
	if (pg == nullptr)
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
	bPlayerVerified = true;
	SaveConfig();
}

void UAAServerBrowser::CreateTabs()
{
	/*
	int32 i = 0;
	i = 0;
	if (((i < PanelCaptions.Num()) && (i < PanelClasses.Num())) && (i < PanelHints.Num()))
	{
		if (PanelClasses[i] != "")
		{
			AddTab(PanelCaptions[i], PanelClasses[i], PanelHints[i]);
		}
		i++;
	}
	DisableMSTabs();
	RefreshFooter(Cast<UAABrowser_Page>(c_Tabs.ActiveTab.MyPanel), "false");
	*/
}

void UAAServerBrowser::EnableMSTabs()
{
	UAABrowser_ServerListPageBuddy* BuddyPanel = nullptr;
	/*
	int32 i = 0;
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
	if (BuddyPanel == nullptr)
	{
		return;
	}
	for (i = 0; i < c_Tabs.TabStack.Num(); i++)
	{
		if (Cast<UAABrowser_ServerListPageBase>(c_Tabs.TabStack[i].MyPanel) != nullptr)
		{
			if (Cast<UAABrowser_ServerListPageBase>(c_Tabs.TabStack[i].MyPanel).lb_Players != nullptr)
			{
				AABrowser_ServerListPageBase(c_Tabs.TabStack[i].MyPanel).lb_Players.tp_Buddy = BuddyPanel;
			}
		}
	}
	*/
}

void UAAServerBrowser::DisableMSTabs()
{
	int32 i = 0;
	Verified = false;
	/*
	for (i = 0; i < c_Tabs.TabStack.Num(); i++)
	{
		if (Cast<UAABrowser_ServerListPageBase>(c_Tabs.TabStack[i].MyPanel) != nullptr)
		{
			if (Cast<UAABrowser_ServerListPageBase>(c_Tabs.TabStack[i].MyPanel).lb_Players != nullptr)
			{
				AABrowser_ServerListPageBase(c_Tabs.TabStack[i].MyPanel).lb_Players.tp_Buddy = nullptr;
			}
		}
	}
	*/
}

UAABrowser_Page* UAAServerBrowser::AddTab(FString TabCaption, FString PanelClassName, FString TabHint)
{
	UAABrowser_Page* Tab=nullptr;
	int32 i = 0;
	/*
	if (((TabCaption != "") && (PanelClassName != "")) && (TabHint != ""))
	{
		Tab = AABrowser_Page(c_Tabs.AddTab(TabCaption, PanelClassName, , TabHint));
		if (Tab == nullptr)
		{
			i = 0;
			if (i < c_Tabs.TabStack.Num())
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
		if (Tab != nullptr)
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
	if (MSC != nullptr)
	{
		MSC->Stop();
		MSC->Destroy();
	}
	MSC = nullptr;
	LevelChanged();
	return false;
}

void UAAServerBrowser::InternalOnChange(UGUIComponent* Sender)
{
}

void UAAServerBrowser::StandardOptionChanged(UGUIComponent* Sender)
{
	//SetStandardServersOption(Cast<UmoCheckBox>(Sender).IsChecked());
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
	if (NewActive != nullptr)
	{
		tp_Active = NewActive;
		if (Cast<UAABrowser_Footer>(t_Footer) != nullptr)
		{
			AABrowser_Footer(t_Footer).UpdateActiveButtons(tp_Active);
		}
	}
	if (t_Footer != nullptr)
	{
		t_Footer.SetupButtons(bPerButtonSizes);
	}
	*/
}

void UAAServerBrowser::InternalOnLoadINI(UGUIComponent* Sender, FString S)
{
	/*
	int32 i = 0;
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
	TArray<FGameRecord> Games = {};
	int32 i = 0;
	int32 j = 0;
	/*
	if (Records.Num() > 0)
	{
		Records.RemoveAt(0, Records.Num());
	}
	UCacheManager::StaticClass().GetGameTypeList(Games);
	for (i = 0; i < Games.Num(); i++)
	{
		j = 0;
		if (j < Records.Num())
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
	int32 i = 0;
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
	AGameInfo* GI = nullptr;
	AAccessControl* AC = nullptr;
	AMutator*  mut = nullptr;
	/*
	Assert((FilterInfo != nullptr));
	FilterInfo.Clear();
	if (NewGameType == "")
	{
		NewGameType = CurrentGameType;
	}
	GI = class<GameInfo>(DynamicLoadObject(NewGameType, Class'Class'));
	if (GI != nullptr)
	{
		GI.FillPlayInfo(FilterInfo);
		FilterInfo.PopClass();
		AC = class<AccessControl>(DynamicLoadObject(GI.Default.AccessControlClass, Class'Class'));
		if (AC != nullptr)
		{
			AC.FillPlayInfo(FilterInfo);
			FilterInfo.PopClass();
		}
		mut = class<Mutator>(DynamicLoadObject(GI.Default.MutatorClass, Class'Class'));
		if (mut != nullptr)
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
	if (tp_Active != nullptr)
	{
		tp_Active.JoinClicked();
	}
	*/
}

void UAAServerBrowser::SpectateClicked()
{
	/*
	if (tp_Active != nullptr)
	{
		tp_Active.SpectateClicked();
	}
	*/
}

void UAAServerBrowser::RefreshClicked()
{
	/*
	if (tp_Active != nullptr)
	{
		tp_Active.RefreshClicked();
	}
	*/
}

void UAAServerBrowser::FilterClicked()
{
	/*
	if (tp_Active != nullptr)
	{
		tp_Active.FilterClicked();
	}
	*/
}

void UAAServerBrowser::Refresh()
{
	int32 i = 0;
	FString dummy = "";
	if (c_Tabs == nullptr)
	{
		return;
	}
	/*
	for (i = 0; i < c_Tabs.TabStack.Num(); i++)
	{
		if (((c_Tabs.TabStack[i].MenuState != 4) && (Cast<UAABrowser_Page>(c_Tabs.TabStack[i].MyPanel) != nullptr)) && AABrowser_Page(c_Tabs.TabStack[i].MyPanel).IsFilterAvailable(dummy))
		{
			c_Tabs.TabStack[i].MyPanel.Refresh();
		}
	}
	*/
}

int32 UAAServerBrowser::CalculateMaxConnections()
{
	int32 i = 0;
	/*
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
	return FMath::Min(Class'UGUIController*'.Default.MaxSimultaneousPings, 35);
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
	int32 i = 0;
	i = 0;
	if (i < ServerCache.Num())
	{
		if (ServerCache[i].GameType ~= CurrentGameType)
		{
			ServerCache.RemoveAt(i, 1);
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
	int32 i = 0;
	TArray<FString> IpParts ={};
	FString Subnet = "";
	FString IP = "";
	/*
	Split(Entry.IP, ".", IpParts);
	i = 0;
	if (i < (IpParts.Num() - 1))
	{
		Subnet = Subnet + IpParts[i] + ".";
		i++;
	}
	IP = IpParts[(IpParts.Num() - 1)];
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
	int32 i = 0;
	FServerResponseLine SRL;
	/*
	for (i = 0; i < ServerCache.Num(); i++)
	{
		if (ServerCache[i].GameType ~= CurrentGameType)
		{
			SRL = ServerCache[i].SRL;
			SRL.IP = OfficialSubnets[ServerCache[i].SubnetIndex] + SRL.IP;
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
	//return Cast<AAGP_HUD>(Cast<AHumanController>(PlayerOwner())->myHUD).GetCurrentServerBrowser(bLAN);
	return nullptr;    //FAKE  /ELiZ
}
*/

void UAAServerBrowser::PunkBusterOptionChanged(UGUIComponent* Sender)
{
	//SetPunkBusterOption(Cast<UmoCheckBox>(Sender).IsChecked());
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
	SetBrowserPassword(Cast<UmoEditBox>(Sender).GetText());
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
	if (tp_Active != nullptr)
	{
		tp_Active.IconKeyClicked();
	}
	*/
}
