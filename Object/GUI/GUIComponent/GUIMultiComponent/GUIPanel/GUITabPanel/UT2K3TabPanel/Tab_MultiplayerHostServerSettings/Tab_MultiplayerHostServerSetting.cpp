// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_MultiplayerHostServerSettings/Tab_MultiplayerHostServerSetting.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moNumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UTab_MultiplayerHostServerSetting::UTab_MultiplayerHostServerSetting()
{
	UmoCheckBox* MPServerAllowBehindView = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	MPServerAllowBehindView->ComponentJustification = EeTextAlign::TXTA_Left;
	MPServerAllowBehindView->CaptionWidth = 0.925;
	MPServerAllowBehindView->Caption = "Allow Behind view";
	//MPServerAllowBehindView->OnCreateComponent=MPServerAllowBehindView.InternalOnCreateComponent;
	MPServerAllowBehindView->Hint = "When selected, the server will allow use of the 'behindview 1' console command.";
	MPServerAllowBehindView->WinTop = 0.476668;
	MPServerAllowBehindView->WinLeft = 0.035742;
	MPServerAllowBehindView->WinWidth = 0.385938;
	MPServerAllowBehindView->WinHeight = 0.04;
	UmoNumericEdit* MPServerWebPort = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	MPServerWebPort->MinValue = 0;
	MPServerWebPort->ComponentJustification = EeTextAlign::TXTA_Left;
	MPServerWebPort->CaptionWidth = 0.65;
	MPServerWebPort->Caption = "Web Admin Port";
	//MPServerWebPort->OnCreateComponent=MPServerWebPort.InternalOnCreateComponent;
	MPServerWebPort->Hint = "The port used to connect to the web admin site.";
	MPServerWebPort->WinTop = 0.859791;
	MPServerWebPort->WinLeft = 0.675156;
	MPServerWebPort->WinWidth = 0.297625;
	MPServerWebPort->WinHeight = 0.06;
	UmoCheckBox* MPServerUseWebAdmin = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	MPServerUseWebAdmin->ComponentJustification = EeTextAlign::TXTA_Left;
	MPServerUseWebAdmin->Caption = "Web Admin";
	//MPServerUseWebAdmin->OnCreateComponent=MPServerUseWebAdmin.InternalOnCreateComponent;
	MPServerUseWebAdmin->Hint = "Enables remote administration via the web.";
	MPServerUseWebAdmin->WinTop = 0.869999;
	MPServerUseWebAdmin->WinLeft = 0.46875;
	MPServerUseWebAdmin->WinWidth = 0.20625;
	MPServerUseWebAdmin->WinHeight = 0.04;
	UmoEditBox* MPServerMOTD4 = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	MPServerMOTD4->CaptionWidth = 0.4;
	MPServerMOTD4->Caption = "MOTD 4";
	//MPServerMOTD4->OnCreateComponent=MPServerMOTD4.InternalOnCreateComponent;
	MPServerMOTD4->Hint = "Players see the message of the day when they join the server.";
	MPServerMOTD4->WinTop = 0.727604;
	MPServerMOTD4->WinLeft = 0.46875;
	MPServerMOTD4->WinHeight = 0.06;
	UmoEditBox* MPServerMOTD3 = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	MPServerMOTD3->CaptionWidth = 0.4;
	MPServerMOTD3->Caption = "MOTD 3";
	//MPServerMOTD3->OnCreateComponent=MPServerMOTD3.InternalOnCreateComponent;
	MPServerMOTD3->Hint = "Players see the message of the day when they join the server.";
	MPServerMOTD3->WinTop = 0.649271;
	MPServerMOTD3->WinLeft = 0.46875;
	MPServerMOTD3->WinHeight = 0.06;
	UmoEditBox* MPServerMOTD2 = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	MPServerMOTD2->CaptionWidth = 0.4;
	MPServerMOTD2->Caption = "MOTD 2";
	//MPServerMOTD2->OnCreateComponent=MPServerMOTD2.InternalOnCreateComponent;
	MPServerMOTD2->Hint = "Players see the message of the day when they join the server.";
	MPServerMOTD2->WinTop = 0.574271;
	MPServerMOTD2->WinLeft = 0.46875;
	MPServerMOTD2->WinHeight = 0.06;
	UmoEditBox* MPServerMOTD1 = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	MPServerMOTD1->CaptionWidth = 0.4;
	MPServerMOTD1->Caption = "MOTD 1";
	//MPServerMOTD1->OnCreateComponent=MPServerMOTD1.InternalOnCreateComponent;
	MPServerMOTD1->Hint = "Players see the message of the day when they join the server.";
	MPServerMOTD1->WinTop = 0.499271;
	MPServerMOTD1->WinLeft = 0.46875;
	MPServerMOTD1->WinHeight = 0.06;
	UmoEditBox* MPServerAdminPW = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	MPServerAdminPW->CaptionWidth = 0.4;
	MPServerAdminPW->Caption = "Admin Password";
	//MPServerAdminPW->OnCreateComponent=MPServerAdminPW.InternalOnCreateComponent;
	MPServerAdminPW->Hint = "The admin password is used to connect to the server as an admin.";
	MPServerAdminPW->WinTop = 0.350938;
	MPServerAdminPW->WinLeft = 0.46875;
	MPServerAdminPW->WinHeight = 0.06;
	UmoEditBox* MPServerAdminEmail = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	MPServerAdminEmail->CaptionWidth = 0.4;
	MPServerAdminEmail->Caption = "Admin Email";
	//MPServerAdminEmail->OnCreateComponent=MPServerAdminEmail.InternalOnCreateComponent;
	MPServerAdminEmail->Hint = "The admin email address will be displayed in the server browser.";
	MPServerAdminEmail->WinTop = 0.282605;
	MPServerAdminEmail->WinLeft = 0.46875;
	MPServerAdminEmail->WinHeight = 0.06;
	UmoEditBox* MPServerAdminName = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	MPServerAdminName->CaptionWidth = 0.4;
	MPServerAdminName->Caption = "Admin Name";
	//MPServerAdminName->OnCreateComponent=MPServerAdminName.InternalOnCreateComponent;
	MPServerAdminName->Hint = "The admin name will be displayed in the server browser.";
	MPServerAdminName->WinTop = 0.217605;
	MPServerAdminName->WinLeft = 0.46875;
	MPServerAdminName->WinHeight = 0.06;
	UmoEditBox* MPServerPW = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	MPServerPW->CaptionWidth = 0.4;
	MPServerPW->Caption = "Game Password";
	//MPServerPW->OnCreateComponent=MPServerPW.InternalOnCreateComponent;
	MPServerPW->Hint = "Players must enter the game password to join your server.";
	MPServerPW->WinTop = 0.122605;
	MPServerPW->WinLeft = 0.46875;
	MPServerPW->WinHeight = 0.06;
	UmoEditBox* MPServerName = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	MPServerName->CaptionWidth = 0.4;
	MPServerName->Caption = "Server Name";
	//MPServerName->OnCreateComponent=MPServerName.InternalOnCreateComponent;
	MPServerName->Hint = "The server name will be displayed in the server browser.";
	MPServerName->WinTop = 0.060938;
	MPServerName->WinLeft = 0.46875;
	MPServerName->WinHeight = 0.06;
	UmoNumericEdit* MPServerMaxSpecs = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	MPServerMaxSpecs->MinValue = 0;
	MPServerMaxSpecs->MaxValue = 64;
	MPServerMaxSpecs->ComponentJustification = EeTextAlign::TXTA_Left;
	MPServerMaxSpecs->CaptionWidth = 0.7;
	MPServerMaxSpecs->Caption = "Max spectator count";
	//MPServerMaxSpecs->OnCreateComponent=MPServerMaxSpecs.InternalOnCreateComponent;
	MPServerMaxSpecs->Hint = "Limits the number of spectators allowed to join the server at once.";
	MPServerMaxSpecs->WinTop = 0.915624;
	MPServerMaxSpecs->WinLeft = 0.035156;
	MPServerMaxSpecs->WinWidth = 0.38125;
	MPServerMaxSpecs->WinHeight = 0.06;
	UmoNumericEdit* MPServerMaxPlayers = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	MPServerMaxPlayers->MinValue = 1;
	MPServerMaxPlayers->MaxValue = 64;
	MPServerMaxPlayers->ComponentJustification = EeTextAlign::TXTA_Left;
	MPServerMaxPlayers->CaptionWidth = 0.7;
	MPServerMaxPlayers->Caption = "Max player count";
	//MPServerMaxPlayers->OnCreateComponent=MPServerMaxPlayers.InternalOnCreateComponent;
	MPServerMaxPlayers->Hint = "Limits the number of players allowed to join the server at once.";
	MPServerMaxPlayers->WinTop = 0.842708;
	MPServerMaxPlayers->WinLeft = 0.035156;
	MPServerMaxPlayers->WinWidth = 0.38125;
	MPServerMaxPlayers->WinHeight = 0.06;
	UmoNumericEdit* MPServerMinPlayers = NewObject<UmoNumericEdit>(UmoNumericEdit::StaticClass());
	MPServerMinPlayers->MinValue = 0;
	MPServerMinPlayers->MaxValue = 64;
	MPServerMinPlayers->ComponentJustification = EeTextAlign::TXTA_Left;
	MPServerMinPlayers->CaptionWidth = 0.7;
	MPServerMinPlayers->Caption = "Min player count";
	//MPServerMinPlayers->OnCreateComponent=MPServerMinPlayers.InternalOnCreateComponent;
	MPServerMinPlayers->Hint = "Bots will join the game if there are fewer players than the minimum.";
	MPServerMinPlayers->WinTop = 0.769792;
	MPServerMinPlayers->WinLeft = 0.035156;
	MPServerMinPlayers->WinWidth = 0.38125;
	MPServerMinPlayers->WinHeight = 0.06;
	UmoCheckBox* MPServerUseCustomBots = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	MPServerUseCustomBots->ComponentJustification = EeTextAlign::TXTA_Left;
	MPServerUseCustomBots->CaptionWidth = 0.925;
	MPServerUseCustomBots->Caption = "Use Custom Bots";
	//MPServerUseCustomBots->OnCreateComponent=MPServerUseCustomBots.InternalOnCreateComponent;
	MPServerUseCustomBots->Hint = "When enabled, you may use the Bot tab to choose bots to play with.";
	MPServerUseCustomBots->WinTop = 0.716252;
	MPServerUseCustomBots->WinLeft = 0.036132;
	MPServerUseCustomBots->WinWidth = 0.385938;
	MPServerUseCustomBots->WinHeight = 0.04;
	//MPServerUseCustomBots->OnChange=Tab_MultiplayerHostServerSettings.UseCustomOnChange;
	UmoCheckBox* MPServerUseDefaults = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	MPServerUseDefaults->ComponentJustification = EeTextAlign::TXTA_Left;
	MPServerUseDefaults->CaptionWidth = 0.925;
	MPServerUseDefaults->Caption = "Use Map Defaults";
	//MPServerUseDefaults->OnCreateComponent=MPServerUseDefaults.InternalOnCreateComponent;
	MPServerUseDefaults->Hint = "Uses the map's default minimum/maximum players settings.";
	MPServerUseDefaults->WinTop = 0.622502;
	MPServerUseDefaults->WinLeft = 0.036132;
	MPServerUseDefaults->WinWidth = 0.385938;
	MPServerUseDefaults->WinHeight = 0.04;
	//MPServerUseDefaults->OnChange=Tab_MultiplayerHostServerSettings.UseMapOnChange;
	UmoComboBox* MPServer_BotSkill = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	MPServer_BotSkill->Caption = "Bot Skill";
	//MPServer_BotSkill->OnCreateComponent=MPServer_BotSkill.InternalOnCreateComponent;
	MPServer_BotSkill->Hint = "Choose the skill of the bots you wish to play with.";
	MPServer_BotSkill->WinTop = 0.547865;
	MPServer_BotSkill->WinLeft = 0.036132;
	MPServer_BotSkill->WinWidth = 0.385938;
	MPServer_BotSkill->WinHeight = 0.06;
	UmoCheckBox* MPServerPlayersMustBeReady = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	MPServerPlayersMustBeReady->ComponentJustification = EeTextAlign::TXTA_Left;
	MPServerPlayersMustBeReady->CaptionWidth = 0.925;
	MPServerPlayersMustBeReady->Caption = "Players Must Be Ready";
	//MPServerPlayersMustBeReady->OnCreateComponent=MPServerPlayersMustBeReady.InternalOnCreateComponent;
	MPServerPlayersMustBeReady->Hint = "When selected, all players will be required to press FIRE before the match begins.";
	MPServerPlayersMustBeReady->WinTop = 0.362085;
	MPServerPlayersMustBeReady->WinLeft = 0.035742;
	MPServerPlayersMustBeReady->WinWidth = 0.385938;
	MPServerPlayersMustBeReady->WinHeight = 0.04;
	UmoCheckBox* MPServerBalanceTeams = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	MPServerBalanceTeams->ComponentJustification = EeTextAlign::TXTA_Left;
	MPServerBalanceTeams->CaptionWidth = 0.925;
	MPServerBalanceTeams->Caption = "Balance Teams";
	//MPServerBalanceTeams->OnCreateComponent=MPServerBalanceTeams.InternalOnCreateComponent;
	MPServerBalanceTeams->Hint = "Assigns teams automatically for players joining the server.";
	MPServerBalanceTeams->WinTop = 0.305835;
	MPServerBalanceTeams->WinLeft = 0.035742;
	MPServerBalanceTeams->WinWidth = 0.385938;
	MPServerBalanceTeams->WinHeight = 0.04;
	UmoCheckBox* MPServerCollectStats = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	MPServerCollectStats->ComponentJustification = EeTextAlign::TXTA_Left;
	MPServerCollectStats->CaptionWidth = 0.925;
	MPServerCollectStats->Caption = "Collect Player Stats";
	//MPServerCollectStats->OnCreateComponent=MPServerCollectStats.InternalOnCreateComponent;
	MPServerCollectStats->Hint = "Publishes player stats from your server on the UT2004 stats website.";
	MPServerCollectStats->WinTop = 0.247502;
	MPServerCollectStats->WinLeft = 0.035742;
	MPServerCollectStats->WinWidth = 0.385938;
	MPServerCollectStats->WinHeight = 0.04;
	UmoCheckBox* MPServerAdvertise = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	MPServerAdvertise->ComponentJustification = EeTextAlign::TXTA_Left;
	MPServerAdvertise->CaptionWidth = 0.925;
	MPServerAdvertise->Caption = "Advertise Server";
	//MPServerAdvertise->OnCreateComponent=MPServerAdvertise.InternalOnCreateComponent;
	MPServerAdvertise->Hint = "Publishes your server to the internet server browser.";
	MPServerAdvertise->WinTop = 0.185002;
	MPServerAdvertise->WinLeft = 0.035742;
	MPServerAdvertise->WinWidth = 0.385938;
	MPServerAdvertise->WinHeight = 0.04;
	UmoCheckBox* MPServerLanGame = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	MPServerLanGame->ComponentJustification = EeTextAlign::TXTA_Left;
	MPServerLanGame->CaptionWidth = 0.925;
	MPServerLanGame->Caption = "Lan Game";
	//MPServerLanGame->OnCreateComponent=MPServerLanGame.InternalOnCreateComponent;
	MPServerLanGame->Hint = "Optimizes network usage for players on a local area network.";
	MPServerLanGame->WinTop = 0.118334;
	MPServerLanGame->WinLeft = 0.035742;
	MPServerLanGame->WinWidth = 0.385938;
	MPServerLanGame->WinHeight = 0.04;
	UmoCheckBox* MPServerDedicated = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	MPServerDedicated->ComponentJustification = EeTextAlign::TXTA_Left;
	MPServerDedicated->CaptionWidth = 0.925;
	MPServerDedicated->Caption = "Dedicated Server";
	//MPServerDedicated->OnCreateComponent=MPServerDedicated.InternalOnCreateComponent;
	MPServerDedicated->Hint = "When this option is enabled, you will run a dedicated server.";
	MPServerDedicated->WinTop = 0.060001;
	MPServerDedicated->WinLeft = 0.035742;
	MPServerDedicated->WinWidth = 0.385938;
	MPServerDedicated->WinHeight = 0.04;
	UGUIImage* MPServerBk1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//MPServerBk1->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	MPServerBk1->ImageColor = FColor(255, 255, 255, 160);
	MPServerBk1->ImageStyle = EImgStyle::ISTY_Stretched;
	MPServerBk1->WinTop = 0.024687;
	MPServerBk1->WinLeft = 0.016758;
	MPServerBk1->WinWidth = 0.426248;
	MPServerBk1->WinHeight = 0.97844;
	UGUIImage* MPServerBk2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//MPServerBk2->Image=Texture'InterfaceContent.Menu.BorderBoxD';
	MPServerBk2->ImageColor = FColor(255, 255, 255, 160);
	MPServerBk2->ImageStyle = EImgStyle::ISTY_Stretched;
	MPServerBk2->WinTop = 0.696041;
	MPServerBk2->WinLeft = 0.016172;
	MPServerBk2->WinWidth = 0.427032;
	MPServerBk2->WinHeight = 0.307188;

	Controls = { MPServerBk1,MPServerBk2,MPServerDedicated,MPServerLanGame,MPServerAdvertise,MPServerCollectStats,MPServerBalanceTeams,MPServerPlayersMustBeReady,MPServer_BotSkill,MPServerUseDefaults,MPServerUseCustomBots,MPServerMinPlayers,MPServerMaxPlayers,MPServerMaxSpecs,MPServerName,MPServerPW,MPServerAdminName,MPServerAdminEmail,MPServerAdminPW,MPServerMOTD1,MPServerMOTD2,MPServerMOTD3,MPServerMOTD4,MPServerUseWebAdmin,MPServerWebPort,MPServerAllowBehindView };
	WinTop = 0.15;
	WinHeight = 0.77;
}

void UTab_MultiplayerHostServerSetting::OnChangeCustomBots(bool Enable)
{
}

void UTab_MultiplayerHostServerSetting::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 Index = 0;
	Super::InitComponent(MyController, MyOwner);
	MyDedicated = moCheckBox(Controls[2]);
	MyDedicated.Checked(bDedicated);
	MyLanGame = moCheckBox(Controls[3]);
	MyLanGame.Checked(bLanPlay);
	MyAdvertise = moCheckBox(Controls[4]);
	MyAdvertise.Checked(Class'IpDrv.MasterServerUplink'.Default.DoUplink);
	MyCollectStats = moCheckBox(Controls[5]);
	MyCollectStats.Checked(bCollectStats);
	MyBalanceTeams = moCheckBox(Controls[6]);
	MyBalanceTeams.Checked(bBalanceTeams);
	MyPlayersMustBeReady = moCheckBox(Controls[7]);
	MyPlayersMustBeReady.Checked(bPlayersMustBeReady);
	MyBotSkill = moComboBox(Controls[8]);
	for (Index = 0; Index < 8; Index++)
	{
		MyBotSkill.addItem(class'XInterface.Tab_InstantActionMain'.Default.DifficultyLevels[Index]);
	}
	MyBotSkill.ReadOnly(true);
	MyBotSkill.SetIndex(BotSkill);
	MyUseDefaultBots = moCheckBox(Controls[9]);
	MyUseDefaultBots.Checked(bUseDefaults);
	MyUseCustomBots = moCheckBox(Controls[10]);
	MyUseCustomBots.Checked(bUseCustomBots);
	MyMinPlayers = moNumericEdit(Controls[11]);
	MyMinPlayers.SetValue(MinPlayers);
	MyMaxPlayers = moNumericEdit(Controls[12]);
	MyMaxPlayers.SetValue(MaxPlayers);
	MyMaxSpecs = moNumericEdit(Controls[13]);
	MyMaxSpecs.SetValue(MaxSpecs);
	MyServerName = moEditBox(Controls[14]);
	MyServerName.SetText(Class'GameReplicationInfo'.Default.ServerName);
	MyServerPasswrd = moEditBox(Controls[15]);
	MyServerPasswrd.SetText(GamePass);
	MyAdminName = moEditBox(Controls[16]);
	MyAdminName.SetText(AdminName);
	MyAdminEmail = moEditBox(Controls[17]);
	MyAdminEmail.SetText(Class'GameReplicationInfo'.Default.AdminEmail);
	MyAdminPasswrd = moEditBox(Controls[18]);
	MyAdminPasswrd.SetText(AdminPass);
	MyAllowBehindView = moCheckBox(Controls[25]);
	MyAllowBehindView.Checked(bAllowBehindView);
	bInitialized = true;
	MyAdminName.MyEditBox.bConvertSpaces = true;
	MyAdminPasswrd.MyEditBox.bConvertSpaces = true;
	MyServerPasswrd.MyEditBox.bConvertSpaces = true;
	*/
}

FString UTab_MultiplayerHostServerSetting::Play()
{
	FString URL = "";
	FString gc = "";
	/*
	local Tab_MultiplayerHostMain pMain;
	bDedicated = MyDedicated.IsChecked();
	bCollectStats = MyCollectStats.IsChecked();
	bBalanceTeams = MyBalanceTeams.IsChecked();
	bPlayersMustBeReady = MyPlayersMustBeReady.IsChecked();
	bLanPlay = MyLanGame.IsChecked();
	BotSkill = MyBotSkill.GetIndex();
	MinPlayers = MyMinPlayers.GetValue();
	MaxPlayers = MyMaxPlayers.GetValue();
	MaxSpecs = MyMaxSpecs.GetValue();
	bUseDefaults = MyUseDefaultBots.IsChecked();
	bUseCustomBots = MyUseCustomBots.IsChecked();
	GamePass = MyServerPasswrd.GetText();
	AdminName = MyAdminName.GetText();
	AdminPass = MyAdminPasswrd.GetText();
	bAllowBehindView = MyAllowBehindView.IsChecked();
	SaveConfig();
	Class'IpDrv.MasterServerUplink'.Default.DoUplink = MyAdvertise.IsChecked();
	Class'IpDrv.MasterServerUplink'.StaticSaveConfig();
	Class'GameReplicationInfo'.Default.ServerName = MyServerName.GetText();
	Class'GameReplicationInfo'.Default.AdminName = AdminName;
	Class'GameReplicationInfo'.Default.AdminEmail = MyAdminEmail.GetText();
	pMain = UT2MultiplayerHostPage(Controller.ActivePage).pMain;
	gc = pMain.GetGameClass();
	URL = URL $ "?GameStats=" $ string(bCollectStats);
	if (pMain.GetIsTeamGame())
	{
		URL = URL $ "?BalanceTeams=" $ string(bBalanceTeams);
	}
	if (bLanPlay)
	{
		URL = URL $ "?LAN";
	}
	if (!bUseDefaults)
	{
		if (!bUseCustomBots)
		{
			URL = URL $ "?MinPlayers=" $ string(MinPlayers);
		}
		URL = URL $ "?MaxPlayers=" $ string(MaxPlayers) $ "?MaxSpectators=" $ string(MaxSpecs);
	}
	else
	{
		URL = URL $ "?bAutoNumBots=True";
	}
	if ((AdminName != "") && (AdminPass != ""))
	{
		URL = URL $ "?AdminName=" $ AdminName $ "?AdminPassword=" $ AdminPass;
	}
	if (GamePass != "")
	{
		URL = URL $ "?GamePassword=" $ GamePass;
	}
	if (bPlayersMustBeReady)
	{
		URL = URL $ "?PlayersMustBeReady=" $ string(bPlayersMustBeReady);
	}
	if (bAllowBehindView)
	{
		URL = URL $ "?AllowBehindview=" $ string(bAllowBehindView);
	}
	URL = URL $ "?difficulty=" $ string(BotSkill);
	*/
	return URL;
}

void UTab_MultiplayerHostServerSetting::UseMapOnChange(UGUIComponent* Sender)
{
	/*
	if (!bInitialized)
	{
		return;
	}
	if (!MyUseDefaultBots.IsChecked())
	{
		MyUseCustomBots.MenuStateChange(0);
		MyMaxPlayers.MenuStateChange(0);
		MyMaxSpecs.MenuStateChange(0);
		if (MyUseCustomBots.IsChecked())
		{
			MyMinPlayers.MenuStateChange(4);
		}
		else
		{
			MyMinPlayers.MenuStateChange(0);
		}
		OnChangeCustomBots(MyUseCustomBots.IsChecked());
	}
	else
	{
		MyUseCustomBots.MenuStateChange(4);
		MyMinPlayers.MenuStateChange(4);
		MyMaxPlayers.MenuStateChange(4);
		MyMaxSpecs.MenuStateChange(4);
		OnChangeCustomBots(false);
	}
	*/
}

void UTab_MultiplayerHostServerSetting::UseCustomOnChange(UGUIComponent* Sender)
{
	/*
	if (!bInitialized)
	{
		return;
	}
	if (MyUseCustomBots.IsChecked())
	{
		MyMinPlayers.MenuStateChange(4);
	}
	else
	{
		MyMinPlayers.MenuStateChange(0);
	}
	OnChangeCustomBots(MyUseCustomBots.IsChecked());
	*/
}

bool UTab_MultiplayerHostServerSetting::UseCustomBots()
{
	//return ((!MyUseDefaultBots.IsChecked()) && MyUseCustomBots.IsChecked());
	return false;     //FAKE   /ELiZ
}