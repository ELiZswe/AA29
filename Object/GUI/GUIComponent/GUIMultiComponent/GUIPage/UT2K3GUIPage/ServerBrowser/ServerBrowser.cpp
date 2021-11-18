// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/ServerBrowser/ServerBrowser.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageMS.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_MOTD/Browser_MOTD.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageMSCustom.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageFavorites.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageLAN.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_ServerListPageBase/Browser_ServerListPageBuddy.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_Prefs/Browser_Prefs.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Browser_Page/Browser_IRC/Browser_IRC.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"

UServerBrowser::UServerBrowser()
{
	UGUITabControl* ServerBrowserTabs = NewObject<UGUITabControl>(UGUITabControl::StaticClass());
	ServerBrowserTabs->bDockPanels = true;
	ServerBrowserTabs->TabHeight = 0.04;
	ServerBrowserTabs->WinTop = 0.25;
	ServerBrowserTabs->WinHeight = 48;
	ServerBrowserTabs->bAcceptsInput = true;
	//ServerBrowserTabs->OnActivate=ServerBrowserTabs.InternalOnActivate;
	UBrowser_MOTD* MyMOTDPage = NewObject<UBrowser_MOTD>(UBrowser_MOTD::StaticClass());
	MyMOTDPage->PageCaption = "News";
	UBrowser_ServerListPageMS* MyDMServerListPage = NewObject<UBrowser_ServerListPageMS>(UBrowser_ServerListPageMS::StaticClass());
	MyDMServerListPage->GameType = "xDeathMatch";
	MyDMServerListPage->PageCaption = "DM";
	UBrowser_ServerListPageMS* MyTDMServerListPage = NewObject<UBrowser_ServerListPageMS>(UBrowser_ServerListPageMS::StaticClass());
	MyTDMServerListPage->GameType = "xTeamGame";
	MyTDMServerListPage->PageCaption = "Team DM";
	UBrowser_ServerListPageMS* MyCTFServerListPage = NewObject<UBrowser_ServerListPageMS>(UBrowser_ServerListPageMS::StaticClass());
	MyCTFServerListPage->GameType = "xCTFGame";
	MyCTFServerListPage->PageCaption = "CTF";
	UBrowser_ServerListPageMS* MyBRServerListPage = NewObject<UBrowser_ServerListPageMS>(UBrowser_ServerListPageMS::StaticClass());
	MyBRServerListPage->GameType = "xBombingRun";
	MyBRServerListPage->PageCaption = "Bombing Run";
	UBrowser_ServerListPageMS* MyDomServerListPage = NewObject<UBrowser_ServerListPageMS>(UBrowser_ServerListPageMS::StaticClass());
	MyDomServerListPage->GameType = "xDoubleDom";
	MyDomServerListPage->PageCaption = "Double Dom";
	UBrowser_ServerListPageMSCustom* MyCustomServerListPage = NewObject<UBrowser_ServerListPageMSCustom>(UBrowser_ServerListPageMSCustom::StaticClass());
	MyCustomServerListPage->PageCaption = "Custom";
	UBrowser_ServerListPageFavorites* MyFavoritesPage = NewObject<UBrowser_ServerListPageFavorites>(UBrowser_ServerListPageFavorites::StaticClass());
	MyFavoritesPage->PageCaption = "Favorites";
	UBrowser_ServerListPageLAN* MyLANPage = NewObject<UBrowser_ServerListPageLAN>(UBrowser_ServerListPageLAN::StaticClass());
	MyLANPage->PageCaption = "LAN";
	UBrowser_ServerListPageBuddy* MyBuddiesPage = NewObject<UBrowser_ServerListPageBuddy>(UBrowser_ServerListPageBuddy::StaticClass());
	MyBuddiesPage->GameType = "xBombingRun";
	MyBuddiesPage->PageCaption = "Buddies";
	UBrowser_Prefs* MyPrefsPage = NewObject<UBrowser_Prefs>(UBrowser_Prefs::StaticClass());
	MyPrefsPage->PageCaption = "Filter";
	UBrowser_IRC* MyIRCPage = NewObject<UBrowser_IRC>(UBrowser_IRC::StaticClass());
	MyIRCPage->PageCaption = "Chat";
	UGUITitleBar* ServerBrowserHeader = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	ServerBrowserHeader->Caption = "Server Browser";
	ServerBrowserHeader->StyleName = "Header";
	ServerBrowserHeader->WinTop = 0.036406;
	ServerBrowserHeader->WinHeight = 46;
	MOTDPage = MyMOTDPage;
	DMServerListPage = MyDMServerListPage;
	TDMServerListPage = MyTDMServerListPage;
	CTFServerListPage = MyCTFServerListPage;
	BRServerListPage = MyBRServerListPage;
	DomServerListPage = MyDomServerListPage;
	CustomServerListPage = MyCustomServerListPage;
	FavoritesPage = MyFavoritesPage;
	LANPage = MyLANPage;
	PrefsPage = MyPrefsPage;
	BuddiesPage = MyBuddiesPage;
	IRCPage = MyIRCPage;
	MutantTypeName = "Mutant";
	InvasionTypeName = "Invasion";
	LMSTypeName = "Last Man Standing";
	MutantType = "xMutantGame";
	InvasionType = "Invasion";
	LMSType = "xLastManStanding";
	//MaxGamespeed = 200;
	bCheckResolution = true;
	bPersistent = true;
	Controls = { ServerBrowserHeader,ServerBrowserTabs };
	WinHeight = 1;
}

void UServerBrowser::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	GUITitleBar(Controls[0]).DockedTabs = GUITabControl(Controls[1]);
	__OnClose__Delegate = InternalOnClose;
	if (!bCreatedStandardTabs)
	{
		AddBrowserPage(MOTDPage);
		AddBrowserPage(PrefsPage);
		AddBrowserPage(IRCPage);
		AddBrowserPage(LANPage);
		AddBrowserPage(FavoritesPage);
		bCreatedStandardTabs = true;
	}
	*/
}

bool UServerBrowser::HaveBonusPack()
{
	/*
	local Object Test;
	Test = DynamicLoadObject("BonusPack.xMutantGame", Class'Class');
	if (Test == None)
	{
		return false;
	}
	Test = DynamicLoadObject("SkaarjPack.Invasion", Class'Class');
	if (Test == None)
	{
		return false;
	}
	*/
	return true;
}

bool UServerBrowser::HaveCustomGameTypes()
{
	/*
	FString Entry = "";
	FString Desc = "";
	int32 Index = 0;
	Index = 0;
	PlayerOwner().GetNextIntDesc("GameInfo", Index, Entry, Desc);
	if (Entry != "")
	{
		Desc = Entry $ "|" $ Desc;
		if (!class'XInterface.Browser_ServerListPageMSCustom'.IsStandardGameType(Desc))
		{
			return true;
		}
		Index++;
		PlayerOwner().GetNextIntDesc("GameInfo", Index, Entry, Desc);
	}
	*/
	return false;
}

void UServerBrowser::MOTDVerified(bool bMSVerified)
{
	/*
	local Browser_ServerListPageMS NewPage;
	if (bCreatedQueryTabs)
	{
		return;
	}
	bCreatedQueryTabs = true;
	AddBrowserPage(BuddiesPage);
	AddBrowserPage(DMServerListPage);
	AddBrowserPage(TDMServerListPage);
	if (!PlayerOwner().Level.IsDemoBuild())
	{
		AddBrowserPage(DomServerListPage);
	}
	AddBrowserPage(CTFServerListPage);
	AddBrowserPage(BRServerListPage);
	if (HaveBonusPack())
	{
		NewPage = new (None) class'XInterface.Browser_ServerListPageMS';
		NewPage.GameType = InvasionType;
		NewPage.PageCaption = InvasionTypeName;
		AddBrowserPage(NewPage);
		NewPage = new (None) class'XInterface.Browser_ServerListPageMS';
		NewPage.GameType = LMSType;
		NewPage.PageCaption = LMSTypeName;
		AddBrowserPage(NewPage);
		NewPage = new (None) class'XInterface.Browser_ServerListPageMS';
		NewPage.GameType = MutantType;
		NewPage.PageCaption = MutantTypeName;
		AddBrowserPage(NewPage);
	}
	if (HaveCustomGameTypes())
	{
		AddBrowserPage(CustomServerListPage);
	}
	*/
}

void UServerBrowser::AddBrowserPage(UBrowser_Page* NewPage)
{
	/*
	local GUITabControl TabC;
	NewPage.Browser = Self;
	TabC = GUITabControl(Controls[1]);
	TabC.AddTab(NewPage.PageCaption, "", NewPage);
	*/
}

void UServerBrowser::OnAddFavorite(FServerResponseLine Server)
{
}

void UServerBrowser::InternalOnClose(bool bCanceled)
{
	/*
	int32 i = 0;
	local GUITabControl TabC;
	TabC = GUITabControl(Controls[1]);
	for (i = 0; i < TabC.TabStack.Length; i++)
	{
		Browser_Page(TabC.TabStack[i].MyPanel).OnCloseBrowser();
	}
	OnClose(bCanceled);
	*/
}