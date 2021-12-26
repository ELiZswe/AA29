// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2MultiplayerHostPage/UT2MultiplayerHostPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/GUITabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUITitleBar.h"

UUT2MultiplayerHostPage::UUT2MultiplayerHostPage()
{
	UGUIButton* HostBackButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	HostBackButton->Caption = "BACK";
	HostBackButton->StyleName = "SquareMenuButton";
	HostBackButton->Hint = "Cancel Changes and Return to Previous Menu";
	HostBackButton->WinTop = 0.93;
	HostBackButton->WinWidth = 0.12;
	HostBackButton->WinHeight = 0.055;
	//HostBackButton->OnClick=UT2MultiplayerHostPage.BackButtonClick;
	//HostBackButton->OnKeyEvent=HostBackButton.InternalOnKeyEvent;
	UGUIButton* HostPlayButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	HostPlayButton->Caption = "START";
	HostPlayButton->StyleName = "SquareMenuButton";
	HostPlayButton->Hint = "Start the server";
	HostPlayButton->WinTop = 0.93;
	HostPlayButton->WinLeft = 0.88;
	HostPlayButton->WinWidth = 0.12;
	HostPlayButton->WinHeight = 0.055;
	//HostPlayButton->OnClick=UT2MultiplayerHostPage.PlayButtonClick;
	//HostPlayButton->OnKeyEvent=HostPlayButton.InternalOnKeyEvent;
	UGUITabControl* HostTabs = NewObject<UGUITabControl>(UGUITabControl::StaticClass());
	HostTabs->TabHeight = 0.04;
	HostTabs->WinTop = 0.25;
	HostTabs->WinHeight = 48;
	HostTabs->bAcceptsInput = true;
	//HostTabs->OnActivate=HostTabs.InternalOnActivate;
	//HostTabs->OnChange=UT2MultiplayerHostPage.TabChange;
	UGUITitleBar* HostHeader = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	HostHeader->Caption = "Host Multiplayer Game";
	HostHeader->StyleName = "Header";
	HostHeader->WinTop = 0.036406;
	HostHeader->WinHeight = 46;
	UGUITitleBar* HostFooter = NewObject<UGUITitleBar>(UGUITitleBar::StaticClass());
	HostFooter->bUseTextHeight = false;
	HostFooter->StyleName = "Footer";
	HostFooter->WinTop = 0.93;
	HostFooter->WinLeft = 0.12;
	HostFooter->WinWidth = 0.76;
	HostFooter->WinHeight = 0.055;
	MainTabLabel = "Game & Map";
	MainTabHint = "Choose the starting map and game type to play...";
	RulesTabLabel = "Game Rules";
	RulesTabHint = "Configure the current game type...";
	MutatorsTabLabel = "Mutators";
	MutatorsTabHint = "Select and configure any mutators to use...";
	ServerTabLabel = "Server";
	ServerTabHint = "Configure all server specific settings...";
	BotTabLabel = "Bot Config";
	BotTabHint = "Configure any bots that will be in the session...";
	//OnReOpen = UT2MultiplayerHostPage.InternalOnReOpen;
	Controls = { HostHeader,HostTabs,HostFooter,HostPlayButton,HostBackButton };
	WinHeight = 1;
}

void UUT2MultiplayerHostPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	FString RulesClass = "";
	Super::InitComponent(MyController, MyOwner);
	MyTabs = GUITabControl(Controls[1]);
	GUITitleBar(Controls[0]).DockedTabs = MyTabs;
	pMain = Tab_MultiplayerHostMain(MyTabs.AddTab(MainTabLabel, "xinterface.Tab_MultiplayerHostMain", , MainTabHint, true));
	pMain.__OnChangeGameType__Delegate = ChangeGameType;
	RulesClass = pMain.GetRulesClass();
	pRules = Tab_InstantActionBaseRules(MyTabs.AddTab(RulesTabLabel, RulesClass, , RulesTabHint));
	pMutators = Tab_InstantActionMutators(MyTabs.AddTab(MutatorsTabLabel, "xinterface.Tab_InstantActionMutators", , MutatorsTabHint));
	pServer = Tab_MultiplayerHostServerSettings(MyTabs.AddTab(ServerTabLabel, "xinterface.Tab_MultiplayerHostServerSettings", , ServerTabHint));
	pServer.__OnChangeCustomBots__Delegate = ChangeCustomBots;
	pBotConfig = Tab_InstantActionBotConfig(MyTabs.AddTab(BotTabLabel, "xinterface.Tab_InstantActionBotConfig", , BotTabHint));
	if (pBotConfig != None)
	{
		pBotConfig.SetupBotLists(pMain.GetIsTeamGame());
	}
	MyTabs.bDockPanels = true;
	ChangeCustomBots(((!pServer.bUseDefaults) && pServer.bUseCustomBots));
	*/
}

bool UUT2MultiplayerHostPage::BackButtonClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(true);
	return true;
}

bool UUT2MultiplayerHostPage::PlayButtonClick(UGUIComponent* Sender)
{
	/*
	FString FullURL = "";
	FString GameURL = "";
	FString FirstMap = "";
	FString GameType = "";
	GameURL = pMain.Play();
	GameURL = GameURL $ pRules.Play();
	GameURL = GameURL $ pMutators.Play();
	if (pServer.UseCustomBots())
	{
		GameURL = GameURL $ pBotConfig.Play();
	}
	GameURL = GameURL $ pServer.Play();
	if ((pMain.MyCurMapList.List.ItemCount == 0) || (pMain.MyCurMapList.List.Get() == ""))
	{
		if ((pMain.MyCurMapList.List.ItemCount == 0) || (pMain.MyCurMapList.List.getItemAtIndex(0) == ""))
		{
			FirstMap = pMain.MyFullMapList.List.Get();
		}
		else
		{
			FirstMap = pMain.MyCurMapList.List.getItemAtIndex(0);
		}
	}
	else
	{
		FirstMap = pMain.MyCurMapList.List.Get();
	}
	GameType = "?Game=" $ pMain.GetGameClass();
	FullURL = FirstMap $ GameType $ GameURL;
	if (pServer.bDedicated)
	{
		PlayerOwner().ConsoleCommand("RELAUNCH " $ FullURL $ " -server -log=Server.log");
	}
	else
	{
		PlayerOwner().ClientTravel(FullURL $ "?Listen", 0, false);
	}
	Controller.CloseAll(false);
	*/
	return true;
}

void UUT2MultiplayerHostPage::TabChange(UGUIComponent* Sender)
{
	/*
	if (GUITabButton(Sender) == nullptr)
	{
		return;
	}
	GUITitleBar(Controls[0]).SetCaption(GUITitleBar(Default.Controls[0]).GetCaption() @ "|" @ GUITabButton(Sender).Caption);
	*/
}

void UUT2MultiplayerHostPage::ChangeHint(FString NewHint)
{
	//GUITitleBar(Controls[2]).SetCaption(NewHint);
}

void UUT2MultiplayerHostPage::InternalOnReOpen()
{
}

void UUT2MultiplayerHostPage::ChangeGameType()
{
	/*
	FString RulesClass = "";
	RulesClass = pMain.GetRulesClass();
	pRules = Tab_InstantActionBaseRules(MyTabs.ReplaceTab(pRules.MyButton, RulesTabLabel, RulesClass, , RulesTabHint));
	if (pBotConfig != None)
	{
		pBotConfig.SetupBotLists(pMain.GetIsTeamGame());
	}
	*/
}

void UUT2MultiplayerHostPage::ChangeCustomBots(bool Enable)
{
	/*
	MyTabs.RemoveTab(BotTabLabel);
	if (Enable)
	{
		MyTabs.AddTab(BotTabLabel, "xinterface.Tab_InstantActionBotConfig", pBotConfig, BotTabHint);
	}
	*/
}