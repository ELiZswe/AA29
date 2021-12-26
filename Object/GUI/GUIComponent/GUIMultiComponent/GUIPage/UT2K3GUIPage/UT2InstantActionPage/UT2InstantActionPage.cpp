// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2InstantActionPage/UT2InstantActionPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"

UUT2InstantActionPage::UUT2InstantActionPage()
{
	UGUIButton* IAPageSpecButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IAPageSpecButton->Caption = "SPECTATE";
	IAPageSpecButton->StyleName = "SquareMenuButton";
	IAPageSpecButton->Hint = "Spectate a Match With These Settings";
	IAPageSpecButton->WinTop = 0.93;
	IAPageSpecButton->WinLeft = 0.758125;
	IAPageSpecButton->WinWidth = 0.12;
	IAPageSpecButton->WinHeight = 0.055;
	//IAPageSpecButton->OnClick=UT2InstantActionPage.SpecButtonClick;
	//IAPageSpecButton->OnKeyEvent=IAPageSpecButton.InternalOnKeyEvent;
	UGUIButton* IAPageBackButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IAPageBackButton->Caption = "BACK";
	IAPageBackButton->StyleName = "SquareMenuButton";
	IAPageBackButton->Hint = "Return to Previous Menu";
	IAPageBackButton->WinTop = 0.93;
	IAPageBackButton->WinWidth = 0.12;
	IAPageBackButton->WinHeight = 0.055;
	//IAPageBackButton->OnClick=UT2InstantActionPage.BackButtonClick;
	//IAPageBackButton->OnKeyEvent=IAPageBackButton.InternalOnKeyEvent;
	UGUIButton* IAPagePlayButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	IAPagePlayButton->Caption = "PLAY";
	IAPagePlayButton->StyleName = "SquareMenuButton";
	IAPagePlayButton->Hint = "Start a Match With These Settings";
	IAPagePlayButton->WinTop = 0.93;
	IAPagePlayButton->WinLeft = 0.88;
	IAPagePlayButton->WinWidth = 0.12;
	IAPagePlayButton->WinHeight = 0.055;
	//IAPagePlayButton->OnClick=UT2InstantActionPage.PlayButtonClick;
	//IAPagePlayButton->OnKeyEvent=IAPagePlayButton.InternalOnKeyEvent;
	UGUITabControl* IAPageTabs = NewObject<UGUITabControl>(UGUITabControl::StaticClass());
	IAPageTabs->TabHeight = 0.04;
	IAPageTabs->WinTop = 0.25;
	IAPageTabs->WinHeight = 48;
	IAPageTabs->bAcceptsInput = true;
	//IAPageTabs->OnActivate=IAPageTabs.InternalOnActivate;
	//IAPageTabs->OnChange=UT2InstantActionPage.TabChange;
	UGUITitleBar* IAPageHeader = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	IAPageHeader->Caption = "Instant Action";
	IAPageHeader->StyleName = "Header";
	IAPageHeader->WinTop = 0.036406;
	IAPageHeader->WinHeight = 46;
	UGUITitleBar* IAPageFooter = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	IAPageFooter->bUseTextHeight = false;
	IAPageFooter->StyleName = "Footer";
	IAPageFooter->WinTop = 0.93;
	IAPageFooter->WinLeft = 0.12;
	IAPageFooter->WinWidth = 0.635;
	IAPageFooter->WinHeight = 0.055;
	MainTabLabel = "Select Map";
	MainTabHint = "Choose the starting map and game type to play...";
	RulesTabLabel = "Game Rules";
	RulesTabHint = "Configure the current game type...";
	MutatorTabLabel = "Mutators";
	MutatorTabHint = "Select and configure any mutators to use...";
	MapListTabLabel = "Map List";
	MapListTabHint = "Configure the list of maps to play...";
	BotConfigTabLabel = "Bot Config";
	BotConfigTabHint = "Configure any bots that will be in the session...";
	PlayerTabLabel = "Player";
	PlayerTabHint = "Configure your UT2003 Avatar...";
	//OnReOpen = UT2InstantActionPage.InternalOnReOpen;
	//OnClose = UT2InstantActionPage.InternalOnClose;
	Controls = { IAPageHeader,IAPageTabs,IAPageFooter,IAPagePlayButton,IAPageBackButton,IAPageSpecButton };
	WinHeight = 1;
}

void UUT2InstantActionPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	FString RulesClass = "";
	Super::InitComponent(MyController, MyOwner);
	MyTabs = GUITabControl(Controls[1]);
	GUITitleBar(Controls[0]).DockedTabs = MyTabs;
	pMain = Tab_InstantActionMain(MyTabs.AddTab(MainTabLabel, "xinterface.Tab_InstantActionMain", , MainTabHint, true));
	pMain.__OnChangeGameType__Delegate = ChangeGameType;
	pMain.__OnChangeCustomBots__Delegate = ChangeCustomBots;
	RulesClass = pMain.GetRulesClass();
	pRules = Tab_InstantActionBaseRules(MyTabs.AddTab(RulesTabLabel, RulesClass, , RulesTabHint));
	pMutators = Tab_InstantActionMutators(MyTabs.AddTab(MutatorTabLabel, "xinterface.Tab_InstantActionMutators", , MutatorTabHint));
	pMapList = Tab_InstantActionMapList(MyTabs.AddTab(MapListTabLabel, "xinterface.Tab_InstantActionMapList", , MapListTabHint));
	pBotConfig = Tab_InstantActionBotConfig(MyTabs.AddTab(BotConfigTabLabel, "xinterface.Tab_InstantActionBotConfig", , BotConfigTabHint));
	pPlayerSetup = Tab_PlayerSettings(MyTabs.AddTab(PlayerTabLabel, "xinterface.Tab_PlayerSettings", , PlayerTabHint));
	if (pBotConfig != None)
	{
		pBotConfig.SetupBotLists(pMain.GetIsTeamGame());
	}
	pMapList.ReadMapList(pMain.GetMapPrefix(), pMain.GetMapListClass());
	MyTabs.bDockPanels = true;
	ChangeCustomBots();
	bSpectate = false;
	*/
}

bool UUT2InstantActionPage::BackButtonClick(UGUIComponent* Sender)
{
	/*
	pPlayerSetup.InternalApply(None);
	Controller.CloseMenu(true);
	*/
	return true;
}

bool UUT2InstantActionPage::PlayButtonClick(UGUIComponent* Sender)
{
	/*
	FString FullURL = "";
	FString GameURL = "";
	FString FirstMap = "";
	FString GameType = "";
	pPlayerSetup.InternalApply(None);
	GameURL = pMain.Play();
	GameURL = GameURL $ pRules.Play();
	GameURL = GameURL $ pMutators.Play();
	GameURL = GameURL $ pMapList.Play();
	if (pMain.LastUseCustomBots)
	{
		GameURL = GameURL $ pBotConfig.Play();
	}
	FirstMap = pMain.MyMapList.List.Get();
	GameType = "?Game=" $ pMain.GetGameClass();
	if (bSpectate)
	{
		GameType = GameType $ "?spectatoronly=1";
	}
	FullURL = FirstMap $ GameType $ GameURL;
	Log("UT2InstantActionPage::PlayButtonClick - Sending [open" @ FullURL $ "] to the console");
	Console(Controller.Master.Console).DelayedConsoleCommand("start" @ FullURL);
	Controller.CloseAll(false);
	*/
	return true;
}

bool UUT2InstantActionPage::SpecButtonClick(UGUIComponent* Sender)
{
	/*
	bSpectate = true;
	PlayButtonClick(Sender);
	*/
	return true;
}

void UUT2InstantActionPage::TabChange(UGUIComponent* Sender)
{
	/*
	if (GUITabButton(Sender) == nullptr)
	{
		return;
	}
	GUITitleBar(Controls[0]).SetCaption(GUITitleBar(Default.Controls[0]).GetCaption() @ "|" @ GUITabButton(Sender).Caption);
	*/
}

void UUT2InstantActionPage::ChangeHint(FString NewHint)
{
	//GUITitleBar(Controls[2]).SetCaption(NewHint);
}

void UUT2InstantActionPage::InternalOnReOpen()
{
}

void UUT2InstantActionPage::ChangeGameType()
{
	/*
	FString RulesClass = "";
	if (pMapList != None)
	{
		pMapList.ReadMapList(pMain.GetMapPrefix(), pMain.GetMapListClass());
	}
	RulesClass = pMain.GetRulesClass();
	pRules = Tab_InstantActionBaseRules(MyTabs.ReplaceTab(pRules.MyButton, RulesTabLabel, RulesClass, , RulesTabHint));
	if (pBotConfig != None)
	{
		pBotConfig.SetupBotLists(pMain.GetIsTeamGame());
	}
	*/
}

void UUT2InstantActionPage::ChangeCustomBots()
{
	/*
	MyTabs.RemoveTab(BotConfigTabLabel);
	if (pMain.LastUseCustomBots)
	{
		MyTabs.AddTab(BotConfigTabLabel, "xinterface.Tab_InstantActionBotConfig", pBotConfig, BotConfigTabHint);
	}
	*/
}

void UUT2InstantActionPage::InternalOnClose(bool bCanceled)
{
	/*
	if (pPlayerSetup.SpinnyDude != None)
	{
		pPlayerSetup.SpinnyDude.Destroy();
	}
	OnClose(bCanceled);
	*/
}