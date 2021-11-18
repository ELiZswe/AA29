// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGameMenu/AAGameMenu.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUITabControl/AAGUITabControl/AAGUITabControl.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIComboBox/GUIComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAAGameMenu::UAAGameMenu()
{
	UAAGUITabControl* TabC = NewObject<UAAGUITabControl>(UAAGUITabControl::StaticClass());
	TabC->ButtonStyleName="MainMenuButton";
	TabC->bDockPanels=true;
	TabC->TabHeight=0.05;
	TabC->WinHeight=0.9;
	TabC->RenderWeight=0.49;
	TabC->bBoundToParent=true;
	TabC->bScaleToParent=true;
	//TabC->OnActivate=TabC.InternalOnActivate;
	UGUIComboBox* BattleBuddyChoices = NewObject<UGUIComboBox>(UGUIComboBox::StaticClass());
	BattleBuddyChoices->bReadOnly=true;
	BattleBuddyChoices->WinTop=0.92;
	BattleBuddyChoices->WinLeft=0.01625;
	BattleBuddyChoices->WinWidth=0.21;
	BattleBuddyChoices->bBoundToParent=true;
	//BattleBuddyChoices->OnChange=AAGameMenu.InternalOnChange;
	//BattleBuddyChoices->OnKeyEvent=BattleBuddyChoices.InternalOnKeyEvent;
	UGUIButton* BattleBuddyButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	BattleBuddyButton->Caption="ADD PLAYER AS BATTLE BUDDY";
	BattleBuddyButton->bWrapCaption=true;
	BattleBuddyButton->StyleName="SquareMenuButton";
	BattleBuddyButton->Hint="Click here to add the selected player to your Battle Buddies list.";
	BattleBuddyButton->WinTop=0.92;
	BattleBuddyButton->WinLeft=0.2275;
	BattleBuddyButton->WinWidth=0.15;
	BattleBuddyButton->WinHeight=0.06;
	BattleBuddyButton->bNeverFocus=true;
	//BattleBuddyButton->OnClick=AAGameMenu.ButtonClick;
	//BattleBuddyButton->OnKeyEvent=BattleBuddyButton.InternalOnKeyEvent;
	UGUIButton* FavoriteServerButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	FavoriteServerButton->Caption="ADD SERVER TO FAVORITES";
	FavoriteServerButton->bWrapCaption=true;
	FavoriteServerButton->StyleName="SquareMenuButton";
	FavoriteServerButton->Hint="Click here to add the current server to your Favorites list.";
	FavoriteServerButton->WinTop=0.92;
	FavoriteServerButton->WinLeft=0.37875;
	FavoriteServerButton->WinWidth=0.15;
	FavoriteServerButton->WinHeight=0.06;
	FavoriteServerButton->bNeverFocus=true;
	//FavoriteServerButton->OnClick=AAGameMenu.ButtonClick;
	//FavoriteServerButton->OnKeyEvent=FavoriteServerButton.InternalOnKeyEvent;
	UGUIButton* SettingsButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SettingsButton->Caption="SETTINGS";
	SettingsButton->StyleName="SquareMenuButton";
	SettingsButton->Hint="Click here to adjust game settings.";
	SettingsButton->WinTop=0.92;
	SettingsButton->WinLeft=0.53125;
	SettingsButton->WinWidth=0.15;
	SettingsButton->WinHeight=0.06;
	SettingsButton->bNeverFocus=true;
	//SettingsButton->OnClick=AAGameMenu.ButtonClick;
	//SettingsButton->OnKeyEvent=SettingsButton.InternalOnKeyEvent;
	UGUIButton* LeaveButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	LeaveButton->Caption="LEAVE MISSION";
	LeaveButton->StyleName="SquareMenuButton";
	LeaveButton->Hint="Click here to return to the main menu.";
	LeaveButton->WinTop=0.92;
	LeaveButton->WinLeft=0.68375;
	LeaveButton->WinWidth=0.15;
	LeaveButton->WinHeight=0.06;
	LeaveButton->bNeverFocus=true;
	//LeaveButton->OnClick=AAGameMenu.ButtonClick;
	//LeaveButton->OnKeyEvent=LeaveButton.InternalOnKeyEvent;
	UGUIButton* ExitButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ExitButton->Caption="EXIT GAME";
	ExitButton->StyleName="SquareMenuButton";
	ExitButton->Hint="Click here to exit the game.";
	ExitButton->WinTop=0.92;
	ExitButton->WinLeft=0.835;
	ExitButton->WinWidth=0.15;
	ExitButton->WinHeight=0.06;
	ExitButton->bNeverFocus=true;
	//ExitButton->OnClick=AAGameMenu.ButtonClick;
	//ExitButton->OnKeyEvent=ExitButton.InternalOnKeyEvent;
	UGUIImage* MidGamePanel = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//MidGamePanel->Image=Texture'T_AA2_UI.Menu.backgroundfill';
	MidGamePanel->ImageStyle = EImgStyle::ISTY_Stretched;
	MidGamePanel->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MidGamePanel->WinTop=0.91;
	MidGamePanel->WinLeft=0.01;
	MidGamePanel->WinWidth=0.98;
	MidGamePanel->WinHeight=0.08;
	MidGamePanel->RenderWeight=0;
	MidGamePanel->bBoundToParent=true;
	MidGamePanel->bScaleToParent=true;
	
	c_Tabs = TabC;
	i_MidGamePanel = MidGamePanel;
	co_BattleBuddyChoices = BattleBuddyChoices;
	b_BattleBuddyAction = BattleBuddyButton;
	b_FavoriteServerAction = FavoriteServerButton;
	b_Settings = SettingsButton;
	b_Leave = LeaveButton;
	b_Exit = ExitButton;

	PanelClasses = { "AGP_Interface.AAGameMenu_Score",	"AGP_Interface.AAGameMenu_WeaponClass",	"AGP_Interface.AAGameMenu_TeamSelect",	"AGP_Interface.AAGameMenu_Map",	"AGP_Interface.AAGameMenu_CommandPost",	"AGP_Interface.AAGameMenu_ServerInfo",	"AGP_Interface.AAGameMenu_Help",	"AGP_Interface.AAGameMenu_PlayerStats",	"AGP_Interface.AAGameMenu_SpotterMap",	"AGP_Interface.AAGameMenu_UAVNavigationMap" };
	PanelCaptions = { "Score","Weapon Class","Team","Map","Command Post","Server Info","Help","Match Stats","Spotter","UAV" };
	PanelHints = { "Scoreboard.",	"Select Weapon Class and Loadout.",	"Read Mission Briefing and select Team.",	"View overhead map and objectives.",	"Server Admin Command Post.","Server Info.","Help.","Match statistics (resets each match)","Spotter Grid Map","UAV Flight Planner Map" };
	CoOpPanelClasses = { "AGP_Interface.AAGameMenu_CoOpScore","AGP_Interface.AAGameMenu_WeaponClass","AGP_Interface.AAGameMenu_CoOpTeamSelect","AGP_Interface.AAGameMenu_Map","AGP_Interface.AAGameMenu_CommandPost","AGP_Interface.AAGameMenu_ServerInfo","AGP_Interface.AAGameMenu_Help","AGP_Interface.AAGameMenu_PlayerStats","AGP_Interface.AAGameMenu_SpotterMap","AGP_Interface.AAGameMenu_UAVNavigationMap" };
	TournamentPanelClasses = { "AGP_Interface.AAGameMenu_Score","AGP_Interface.AAGameMenu_TournamentRoster","AGP_Interface.AAGameMenu_TeamSelect","AGP_Interface.AAGameMenu_Map","AGP_Interface.AAGameMenu_CommandPost","AGP_Interface.AAGameMenu_TournamentServerInfo","AGP_Interface.AAGameMenu_Help" };
	TournamentPanelCaptions = { "Score","Roster","Team","Map","Command Post","Tournament","Help" };
	TournamentPanelHints = { "Scoreboard.","Select Tournament Roster.","Read Mission Briefing and select Team.","View overhead map and objectives.","Server Admin Command Post.","Tournament Server Info.","Help." };

	DisconnectCaption = "DISCONNECT";
	DisconnectHint = "Click here to disconnect and return to the main menu.";
	FavoritesDisabledHint = "Favorites functionality is only available when using the AA Browser to join games.";
	FavoriteServerAddHint = "Click here to add the current server to your Favorites list.";
	FavoriteServerRemoveHint = "Click here to remove the current server from  your Favorites list.";
	BattleBuddyAddHint = "Click here to add the selected player to your Battle Buddies list.";
	BattleBuddyRemoveHint = "Click here to remove the selected player from your Battle Buddies list.";
	BattleBuddySelectAPlayerDisabledHint = "A player must be selected before adding to or removing from your Battle Buddies list.";
	bRenderWorld = true;
	bPersistent = true;
	bAllowedAsLast = true;
	WinHeight = 1;
	//OnPreDraw = AAGameMenu.InternalOnPreDraw;
	//OnKeyEvent = AAGameMenu.InternalOnKeyEvent;

}

//const UAVNAVIGATION = 9;
//const SPOTTER = 8;
//const Stats = 7;
//const Help = 6;
//const tournament = 5;
//const SERVER_INFO = 5;
//const COMMAND_POST = 4;
//const Map = 3;
//const TEAM_SELECT = 2;
//const ROSTER = 1;
//const WEAPON_CLASS = 1;
//const ScoreBoard = 0;


void UAAGameMenu::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local PlayerController PC;
	local HumanController HC;
	local GameReplicationInfo GRI;
	Super::InitComponent(MyController, MyOwner);
	PC = PlayerOwner();
	HC = HumanController(PC);
	GRI = PlayerOwner().GameReplicationInfo;
	if (PC.Level.NetMode != NM_Standalone)
	{
		if (PC.Level.bCoOpGame)
		{
			c_Tabs.AddTab(PanelCaptions[0], CoOpPanelClasses[0], , PanelHints[0]);
		}
		else
		{
			c_Tabs.AddTab(PanelCaptions[0], PanelClasses[0], , PanelHints[0]);
		}
		if ((HC != None) && HC.bTournamentServer)
		{
			c_Tabs.AddTab(TournamentPanelCaptions[1], TournamentPanelClasses[1], , TournamentPanelHints[1]);
		}
		else
		{
			c_Tabs.AddTab(PanelCaptions[1], PanelClasses[1], , PanelHints[1]);
		}
		if (PC.Level.bCoOpGame)
		{
			c_Tabs.AddTab(PanelCaptions[2], CoOpPanelClasses[2], , PanelHints[2]);
		}
		else
		{
			c_Tabs.AddTab(PanelCaptions[2], PanelClasses[2], , PanelHints[2]);
		}
		c_Tabs.AddTab(PanelCaptions[3], PanelClasses[3], , PanelHints[3]);
		if ((((HC != None) && (HC.PlayerReplicationInfo != None)) && HC.PlayerReplicationInfo.bIsMortarSpotter) && HC.FDCOnMap())
		{
			c_Tabs.AddTab(PanelCaptions[8], PanelClasses[8], , PanelHints[8]);
		}
		if ((((HC != None) && (HC.PlayerReplicationInfo != None)) && HC.PlayerReplicationInfo.bIsUAVNavigator) && HC.UAVOnMap())
		{
			c_Tabs.AddTab(PanelCaptions[9], PanelClasses[9], , PanelHints[9]);
		}
		if ((HC != None) && HC.bTournamentServer)
		{
			c_Tabs.AddTab(TournamentPanelCaptions[5], TournamentPanelClasses[5], , TournamentPanelHints[5]);
		}
		else
		{
			c_Tabs.AddTab(PanelCaptions[5], PanelClasses[5], , PanelHints[5]);
		}
		aagmpsStats = AAGameMenu_PlayerStats(c_Tabs.AddTab(PanelCaptions[7], PanelClasses[7], , PanelHints[7]));
		aagmpsStats.guipOwner = Self;
		aagmpsStats.InitializeStatRetrieval();
		c_Tabs.AddTab(PanelCaptions[6], PanelClasses[6], , PanelHints[6]);
	}
	else
	{
		c_Tabs.AddTab("Training", "AGP_Interface.AAGameMenu_Training", , "Training Info");
		if (HC.FDCOnMap())
		{
			c_Tabs.AddTab(PanelCaptions[8], PanelClasses[8], , PanelHints[8]);
		}
		if (HC.UAVOnMap())
		{
			c_Tabs.AddTab(PanelCaptions[9], PanelClasses[9], , PanelHints[9]);
		}
		c_Tabs.AddTab(PanelCaptions[3], PanelClasses[3], , PanelHints[3]);
	}
	if (PC.Level.NetMode != NM_Standalone)
	{
		b_Leave.Caption = DisconnectCaption;
		b_Leave.Hint = DisconnectHint;
	}
	if (PC.Level.NetMode == NM_Standalone)
	{
		co_BattleBuddyChoices.SetVisibility(false);
		b_BattleBuddyAction.SetVisibility(false);
		b_FavoriteServerAction.SetVisibility(false);
	}
	if (PC.Level.NetMode != NM_Standalone)
	{
		if (((HC.bIsAuthorizedServer || HC.bOfficialServer) || HC.bLeasedServer) && (!HC.bExploreTheArmyServer))
		{
			PopulateBuddyChoices();
			PrepareBattleBuddyActionButton();
			PrepareFavoriteServerActionButton();
		}
		else
		{
			DisableFavoritesUIElements();
		}
	}
	*/
}

void UAAGameMenu::DisableFavoritesUIElements()
{
	/*
	co_BattleBuddyChoices.DisableMe();
	b_BattleBuddyAction.DisableMe();
	b_BattleBuddyAction.Hint = FavoritesDisabledHint;
	b_FavoriteServerAction.DisableMe();
	b_FavoriteServerAction.Hint = FavoritesDisabledHint;
	*/
}

void UAAGameMenu::PopulateBuddyChoices()
{
	/*
	local FString PlayerName;
	local PlayerReplicationInfo PRI;
	local GameReplicationInfo GRI;
	local int32 Index;
	GRI = PlayerOwner().GameReplicationInfo;
	if (GRI != None)
	{
		co_BattleBuddyChoices.EnableMe();
		for (Index = 0; Index < GRI.PRIArray.Length; Index++)
		{
			PRI = GRI.PRIArray[Index];
			if (PRI != None)
			{
				if (((PRI.bPlayerAdmin || (!PRI.bAdmin)) || (!PRI.bIsSpectator)) && (PRI != PlayerOwner().PlayerReplicationInfo))
				{
					PlayerName = PRI.AuthUserName;
					co_BattleBuddyChoices.addItem(PlayerName);
				}
			}
		}
	}
	*/
}

void UAAGameMenu::PrepareBattleBuddyActionButton()
{
	/*
	local DBAuth.Favorites Favorites;
	local FString CurrentBattleBuddyChoice;
	Favorites = class'AGP_Interface.AABrowser_FavoritesPanel'.Default.Favorites;
	if (Favorites == None)
	{
		b_BattleBuddyAction.DisableMe();
		b_BattleBuddyAction.Hint = FavoritesDisabledHint;
	}
	else
	{
		CurrentBattleBuddyChoice = co_BattleBuddyChoices.GetText();
		if (Len(CurrentBattleBuddyChoice) == 0)
		{
			b_BattleBuddyAction.DisableMe();
			b_BattleBuddyAction.Hint = BattleBuddySelectAPlayerDisabledHint;
		}
		else
		{
			b_BattleBuddyAction.EnableMe();
		}
		if (Favorites.GetIndexOfBattleBuddy(CurrentBattleBuddyChoice) != -1)
		{
			b_BattleBuddyAction.Caption = "REMOVE PLAYER AS BATTLE BUDDY";
			b_BattleBuddyAction.Hint = BattleBuddyRemoveHint;
			BattleBuddyAction = 1;
		}
		else
		{
			b_BattleBuddyAction.Caption = "ADD PLAYER AS BATTLE BUDDY";
			b_BattleBuddyAction.Hint = BattleBuddyAddHint;
			BattleBuddyAction = 0;
		}
	}
	*/
}

FFavoriteServer UAAGameMenu::GetThisServer()
{
	FFavoriteServer Server;
	/*
	local FString AddressURL;
	local int32 nPos;
	AddressURL = PlayerOwner().Level.GetAddressURL();
	nPos = InStr(AddressURL, ":");
	Server.IPAddress = Left(AddressURL, nPos);
	Server.Port = int(Mid(AddressURL, (nPos + 1)));
	*/
	return Server;
}

void UAAGameMenu::PrepareFavoriteServerActionButton()
{
	/*
	local DBAuth.Favorites Favorites;
	local Favorites.FavoriteServer Server;
	Favorites = class'AGP_Interface.AABrowser_FavoritesPanel'.Default.Favorites;
	if (Favorites == None)
	{
		b_FavoriteServerAction.DisableMe();
		b_FavoriteServerAction.Hint = FavoritesDisabledHint;
	}
	else
	{
		b_FavoriteServerAction.EnableMe();
		Server = GetThisServer();
		if (Favorites.GetIndexOfFavoriteServer(Server) != -1)
		{
			b_FavoriteServerAction.Caption = "REMOVE SERVER FROM FAVORITES";
			b_FavoriteServerAction.Hint = FavoriteServerRemoveHint;
			FavoriteServerAction = 1;
		}
		else
		{
			b_FavoriteServerAction.Caption = "ADD SERVER TO FAVORITES";
			b_FavoriteServerAction.Hint = FavoriteServerAddHint;
			FavoriteServerAction = 0;
		}
	}
	*/
}

void UAAGameMenu::OnOpen()
{
	/*
	local AGP_HUD HUD;
	Super::OnOpen();
	HUD = AGP_HUD(PlayerOwner().myHUD);
	bPlayerHUD = HUD.bShowHUD;
	HUD.bShowVersion = true;
	HUD.bShowSpectatorInfo = false;
	HUD.bShowHUD = false;
	*/
}

void UAAGameMenu::OnClose(bool bCanceled)
{
	/*
	local AGP_HUD HUD;
	local PlayerController PC;
	PC = PlayerOwner();
	if ((PC != None) && (PC.Level.Pauser != None))
	{
		PC.SetPause(false);
	}
	Super::OnClose(bCanceled);
	HUD = AGP_HUD(PlayerOwner().myHUD);
	HUD.bShowVersion = false;
	HUD.bShowSpectatorInfo = true;
	HUD.bShowHUD = bPlayerHUD;
	*/
}

void UAAGameMenu::SwitchPanel(int32 NewPanel)
{
	/*
	if ((c_Tabs.ActiveTab.Caption ~= PanelCaptions[NewPanel]) || (c_Tabs.ActiveTab.Caption ~= TournamentPanelCaptions[NewPanel]))
	{
		Controller.CloseMenu();
	}
	else
	{
		if ((HumanController(PlayerOwner()) != None) && HumanController(PlayerOwner()).bTournamentServer)
		{
			c_Tabs.ActivateTabByName(TournamentPanelCaptions[NewPanel], true);
		}
		else
		{
			c_Tabs.ActivateTabByName(PanelCaptions[NewPanel], true);
		}
	}
	*/
}

bool UAAGameMenu::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	if (State == 1)
	{
		switch (Key)
		{
		case 112:
			SwitchPanel(0);
			return true;
		case 113:
			SwitchPanel(1);
			return true;
		case 114:
			SwitchPanel(2);
			return true;
		case 115:
			SwitchPanel(3);
			return true;
		default:
		}
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

void UAAGameMenu::HandleParameters(FString Param1, FString Param2)
{
	//Super::HandleParameters(Param1, Param2);
	//c_Tabs.ActivateTabByName(Param1, true);
}

void UAAGameMenu::DoBattleBuddyAction()
{
	/*
	local DBAuth.Favorites Favorites;
	local FString CurrentBattleBuddyChoice;
	Favorites = class'AGP_Interface.AABrowser_FavoritesPanel'.Default.Favorites;
	if (Favorites != None)
	{
		CurrentBattleBuddyChoice = co_BattleBuddyChoices.GetText();
		switch (BattleBuddyAction)
		{
		case 0:
			OpenFavoritesOperationDialog("Adding Battle Buddy", CurrentBattleBuddyChoice);
			Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
			Favorites.AddBattleBuddy(CurrentBattleBuddyChoice, HumanController(PlayerOwner()).UserName, HumanController(PlayerOwner()).UserPassword, PlayerOwner());
			break;
		case 1:
			OpenFavoritesOperationDialog("Removing Battle Buddy", CurrentBattleBuddyChoice);
			Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
			Favorites.RemoveBattleBuddy(CurrentBattleBuddyChoice, HumanController(PlayerOwner()).UserName, HumanController(PlayerOwner()).UserPassword, PlayerOwner());
			break;
		default:
		}
	}
	*/
}

void UAAGameMenu::DoFavoriteServerAction()
{
	/*
	local DBAuth.Favorites Favorites;
	local Favorites.FavoriteServer Server;
	Favorites = class'AGP_Interface.AABrowser_FavoritesPanel'.Default.Favorites;
	if (Favorites != None)
	{
		Server = GetThisServer();
		switch (FavoriteServerAction)
		{
		case 0:
			OpenFavoritesOperationDialog("Adding Server", Server.IPAddress $ ":" $ string(Server.Port));
			Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
			Favorites.AddFavoriteServer(Server, HumanController(PlayerOwner()).UserName, HumanController(PlayerOwner()).UserPassword, PlayerOwner());
			break;
		case 1:
			OpenFavoritesOperationDialog("Removing Server", Server.IPAddress $ ":" $ string(Server.Port));
			Favorites.__dOnFavoritesOperationComplete__Delegate = InternalOnFavoritesOperationComplete;
			Favorites.RemoveFavoriteServer(Server, HumanController(PlayerOwner()).UserName, HumanController(PlayerOwner()).UserPassword, PlayerOwner());
			break;
		default:
		}
	}
	*/
}

bool UAAGameMenu::ButtonClick(UGUIComponent* Sender)
{
	/*
	if (Sender == b_BattleBuddyAction)
	{
		DoBattleBuddyAction();
	}
	else
	{
		if (Sender == b_FavoriteServerAction)
		{
			DoFavoriteServerAction();
		}
		else
		{
			if (Sender == b_Settings)
			{
				Controller.OpenMenu("AGP_Interface.AAMainMenu", AAGUIController(Controller).GetSettingsPanel());
			}
			else
			{
				if (Sender == b_Leave)
				{
					PlayerOwner().ConsoleCommand("disconnect");
					Controller.CloseMenu();
				}
				else
				{
					if (Sender == b_Exit)
					{
						Controller.OpenMenu("AGP_Interface.AAExitPage");
					}
				}
			}
		}
	}
	*/
	return true;
}

void UAAGameMenu::InternalOnChange(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case co_BattleBuddyChoices:
		PrepareBattleBuddyActionButton();
		break;
	default:
	}
	*/
}

void UAAGameMenu::OpenFavoritesOperationDialog(FString Action, FString Message)
{
	/*
	if (None == AAFavoritesOperationModalDialog(Controller.TopPage()))
	{
		Controller.OpenMenu("AGP_Interface.AAFavoritesOperationModalDialog", Action, Message);
	}
	*/
}

void UAAGameMenu::InternalOnFavoritesOperationComplete(int32 ResultCode, FString Message)
{
	/*
	if (None != AAFavoritesOperationModalDialog(Controller.TopPage()))
	{
		Controller.CloseMenu((1 != ResultCode));
	}
	if (1 != ResultCode)
	{
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Favorites Update Failed", Message);
	}
	else
	{
		PrepareBattleBuddyActionButton();
		PrepareFavoriteServerActionButton();
	}
	*/
}

void UAAGameMenu::NotifyStatsPage(FString sStatRequested, FString sValue)
{
	//aagmpsStats.NotifyStatsPage(sStatRequested, sValue);
}

bool UAAGameMenu::InternalOnPreDraw(UCanvas* C)
{
	/*
	local PlayerController PC;
	local HumanController HC;
	local GameReplicationInfo GRI;
	local PlayerReplicationInfo PRI;
	local FString PlayerName;
	local int32 i;
	local int32 j;
	local bool bAddBuddy;
	local bool bRemoveBuddy;
	local bool bPlayerFound;
	PC = PlayerOwner();
	HC = HumanController(PC);
	GRI = PlayerOwner().GameReplicationInfo;
	bRemoveBuddy = false;
	if (PC.Level.NetMode != NM_Standalone)
	{
		if (((HC.bIsAuthorizedServer || HC.bOfficialServer) || HC.bLeasedServer) && (!HC.bExploreTheArmyServer))
		{
			for (i = 0; i < co_BattleBuddyChoices.ItemCount(); i++)
			{
				bPlayerFound = false;
				for (j = 0; j < GRI.PRIArray.Length; j++)
				{
					if (GRI.PRIArray[j].AuthUserName == co_BattleBuddyChoices.GetItem(i))
					{
						bPlayerFound = true;
					}
				}
				if (!bPlayerFound)
				{
					co_BattleBuddyChoices.RemoveItem(i);
					if (co_BattleBuddyChoices.ItemCount() == 0)
					{
						co_BattleBuddyChoices.Clear();
					}
				}
			}
			if (GRI != None)
			{
				NewPlayerQueue = (GRI.PRIArray.Length - co_BattleBuddyChoices.ItemCount());
			}
			if (NewPlayerQueue > 0)
			{
				for (i = 0; i < GRI.PRIArray.Length; i++)
				{
					PRI = GRI.PRIArray[i];
					if (PRI != None)
					{
						if (((PRI.bPlayerAdmin || (!PRI.bAdmin)) || (!PRI.bIsSpectator)) && (PRI != PlayerOwner().PlayerReplicationInfo))
						{
							bAddBuddy = true;
							for (j = 0; j < co_BattleBuddyChoices.ItemCount(); j++)
							{
								if ((PRI.AuthUserName == "") || (co_BattleBuddyChoices.GetItem(j) == PRI.AuthUserName))
								{
									bAddBuddy = false;
								}
							}
							if (bAddBuddy == true)
							{
								PlayerName = PRI.AuthUserName;
								co_BattleBuddyChoices.addItem(PlayerName);
							}
						}
					}
				}
				NewPlayerQueue;
			}
		}
	}
	return OnDraw(C);
	*/
	return false;    //FAKE   /ELiZ
}