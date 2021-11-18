// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AAGameMenu_TeamSelect/AAGameMenu_TeamSelect.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAGameMenu_TeamSelect::UAAGameMenu_TeamSelect()
{
	UGUIButton* SpectateButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SpectateButton->Caption="SPECTATE";
	SpectateButton->StyleName="SquareMenuButton";
	SpectateButton->Hint="Spectate.";
	SpectateButton->WinTop=0.81;
	SpectateButton->WinLeft=0.83;
	SpectateButton->WinWidth=0.15;
	SpectateButton->WinHeight=0.06;
	SpectateButton->TabOrder=5;
	//SpectateButton->OnClick=AAGameMenu_TeamSelect.ButtonClick;
	//SpectateButton->OnKeyEvent=SpectateButton.InternalOnKeyEvent;
	UGUIButton* AutoSelectButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	AutoSelectButton->Caption="AUTO SELECT";
	AutoSelectButton->StyleName="SquareMenuButton";
	AutoSelectButton->Hint="Automatically join the team with the fewest players.";
	AutoSelectButton->WinTop=0.81;
	AutoSelectButton->WinLeft=0.02;
	AutoSelectButton->WinWidth=0.15;
	AutoSelectButton->WinHeight=0.06;
	AutoSelectButton->TabOrder=4;
	//AutoSelectButton->OnClick=AAGameMenu_TeamSelect.ButtonClick;
	//AutoSelectButton->OnKeyEvent=AutoSelectButton.InternalOnKeyEvent;
	UmoEditBox* PasswordEdit2 = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	PasswordEdit2->CaptionWidth=0.2;
	PasswordEdit2->Caption="Password";
	//PasswordEdit2->OnCreateComponent=PasswordEdit2.InternalOnCreateComponent;
	PasswordEdit2->Hint="Click here then enter the team password";
	PasswordEdit2->WinTop=0.72;
	PasswordEdit2->WinLeft=0.56;
	PasswordEdit2->WinWidth=0.25;
	PasswordEdit2->WinHeight=0.06;
	PasswordEdit2->TabOrder=3;
	PasswordEdit2->bStandardized=false;
	UmoEditBox* PasswordEdit1 = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	PasswordEdit1->CaptionWidth=0.2;
	PasswordEdit1->Caption="Password";
	//PasswordEdit1->OnCreateComponent=PasswordEdit1.InternalOnCreateComponent;
	PasswordEdit1->Hint="Click here then enter the team password";
	PasswordEdit1->WinTop=0.32;
	PasswordEdit1->WinLeft=0.56;
	PasswordEdit1->WinWidth=0.25;
	PasswordEdit1->WinHeight=0.06;
	PasswordEdit1->TabOrder=2;
	PasswordEdit1->bStandardized=false;
	UGUIButton* Join2 = NewObject<UGUIButton>(UGUIButton::StaticClass());
	Join2->Caption="JOIN";
	Join2->StyleName="SquareMenuButton";
	Join2->Hint="Join this team.";
	Join2->WinTop=0.72;
	Join2->WinLeft=0.82;
	Join2->WinWidth=0.15;
	Join2->WinHeight=0.06;
	Join2->TabOrder=1;
	//Join2->OnClick=AAGameMenu_TeamSelect.ButtonClick;
	//Join2->OnKeyEvent=Join2.InternalOnKeyEvent;
	UGUIButton* Join1 = NewObject<UGUIButton>(UGUIButton::StaticClass());
	Join1->Caption="JOIN";
	Join1->StyleName="SquareMenuButton";
	Join1->Hint="Join this team.";
	Join1->WinTop=0.32;
	Join1->WinLeft=0.82;
	Join1->WinWidth=0.15;
	Join1->WinHeight=0.06;
	Join1->TabOrder=0;
	//Join1->OnClick=AAGameMenu_TeamSelect.ButtonClick;
	//Join1->OnKeyEvent=Join1.InternalOnKeyEvent;
	UGUIScrollTextBox* TeamScroll2 = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	TeamScroll2->bNoTeletype=true;
	TeamScroll2->bVisibleWhenEmpty=true;
	//TeamScroll2->OnCreateComponent=TeamScroll2.InternalOnCreateComponent;
	TeamScroll2->StyleName="SmallText";
	TeamScroll2->WinTop=0.49;
	TeamScroll2->WinLeft=0.03;
	TeamScroll2->WinWidth=0.94;
	TeamScroll2->WinHeight=0.22;
	UGUIScrollTextBox* TeamScroll1 = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	TeamScroll1->bNoTeletype=true;
	TeamScroll1->bVisibleWhenEmpty=true;
	//TeamScroll1->OnCreateComponent=TeamScroll1.InternalOnCreateComponent;
	TeamScroll1->StyleName="SmallText";
	TeamScroll1->WinTop=0.09;
	TeamScroll1->WinLeft=0.03;
	TeamScroll1->WinWidth=0.94;
	TeamScroll1->WinHeight=0.22;
	UGUIImage* MyBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//MyBackground->Image=Texture'T_AA2_UI.Menu.backgroundfill';
	MyBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	MyBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	MyBackground->WinTop=0.01;
	MyBackground->WinLeft=0.01;
	MyBackground->WinWidth=0.98;
	MyBackground->WinHeight=0.88;
	MyBackground->RenderWeight=0;
	MyBackground->bBoundToParent=true;
	MyBackground->bScaleToParent=true;
	UGUIImage* BG1 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//BG1->Image=Texture'T_AA2_UI.Menu.field_translucent';
	BG1->ImageStyle = EImgStyle::ISTY_Stretched;
	BG1->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	BG1->WinTop=0.02;
	BG1->WinLeft=0.02;
	BG1->WinWidth=0.96;
	BG1->WinHeight=0.38;
	UGUIImage* BG2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	//BG2->Image=Texture'T_AA2_UI.Menu.field_translucent';
	BG2->ImageStyle = EImgStyle::ISTY_Stretched;
	BG2->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	BG2->WinTop=0.42;
	BG2->WinLeft=0.02;
	BG2->WinWidth=0.96;
	BG2->WinHeight=0.38;
	UGUILabel* TeamName1 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TeamName1->TextColor=FColor(255, 255, 255, 255);
	TeamName1->TextFont="AAFontLarge";
	TeamName1->WinTop=0.02;
	TeamName1->WinLeft=0.03;
	TeamName1->WinWidth=0.94;
	UGUILabel* TeamName2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TeamName2->TextColor=FColor(255, 255, 255, 255);
	TeamName2->TextFont="AAFontLarge";
	TeamName2->WinTop=0.42;
	TeamName2->WinLeft=0.03;
	TeamName2->WinWidth=0.94;
	UGUILabel* TeamMsg1 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TeamMsg1->TextColor=FColor(255, 255, 255, 255);
	TeamMsg1->TextFont="AAFontMedium";
	TeamMsg1->WinTop=0.32;
	TeamMsg1->WinLeft=0.03;
	TeamMsg1->WinWidth=0.6;
	UGUILabel* TeamMsg2 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TeamMsg2->TextColor=FColor(255, 255, 255, 255);
	TeamMsg2->TextFont="AAFontMedium";
	TeamMsg2->WinTop=0.72;
	TeamMsg2->WinLeft=0.03;
	TeamMsg2->WinWidth=0.6;

	i_Background = MyBackground;
	i_Team = { BG1, BG2 };
	l_TeamName = { TeamName1, TeamName2 };
	l_TeamMsg = { TeamMsg1, TeamMsg2 };
	lb_Briefing = { TeamScroll1,TeamScroll2 };
	ed_Password = { PasswordEdit1, PasswordEdit2 };
	b_Join = { Join1, Join2 };
	b_Auto = AutoSelectButton;
	b_Spectate = SpectateButton;
	JoinText = "JOIN";
	RemainText = "REMAIN";
	SpectateText = "SPECTATE";
	PlayerText = " Player";
	PlayerPluralText = " Players";
	OnTeam = "You are currently on this team";
	GoingToTeam = "You will join this team at the end of the round";
	LeavingTeam = "You will leave this team at the end of the round";
	ASAPTeam = "You will join this team as soon as possible";
	OnSpectator = "You are currently a spectator";
	s_JoinHint = "Click here then enter the team password";
	//OnPreDraw = AAGameMenu_TeamSelect.MyOnPreDraw;
}


void UAAGameMenu_TeamSelect::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	FString Directory = "";
	FString File = "";
	local AAGUIController C;
	local GameReplicationInfo GRI;
	Super::InitComponent(MyController, MyOwner);
	C = AAGUIController(MyController);
	GRI = PlayerOwner().GameReplicationInfo;
	Directory = GetBaseDir();
	Directory = Left(Directory, (Len(Directory) - 7));
	Directory $ = "Briefings\\";
	File = PlayerOwner().Level.GetLevelName();
	if (((GRI == None) || (GRI.Teams[0] == None)) || (GRI.Teams[1] == None))
	{
		return;
	}
	for (i = 0; i < 2; i++)
	{
		if (PlayerOwner().Level.sAssaultSituationText != "")
		{
			lb_Briefing[i].SetContent(BuildMissionBriefing(i));
		}
		else
		{
			lb_Briefing[i].SetContent(C.LoadTextFromFile(Directory $ File $ "_team" $ string(i) $ ".txt"));
		}
	}
	*/
}

FString UAAGameMenu_TeamSelect::BuildMissionBriefing(int32 iTeam)
{
	FString Briefing = "";
	/*
	local PlayerController PC;
	PC = PlayerOwner();
	if (PC != None)
	{
		switch (iTeam)
		{
		case 0:
			Briefing = "1. SITUATION: " $ PC.Level.sAssaultSituationText $ "||";
			Briefing = Briefing $ "2. MISSION: " $ PC.Level.sAssaultMissionText $ "||";
			Briefing = Briefing $ "3. GENERAL INSTRUCTIONS: ||";
			Briefing = Briefing $ "    A. ENEMY FORCES: " $ PC.Level.sAssaultEnemyForcesText $ "||";
			Briefing = Briefing $ "    B. FRIENDLY FORCES: " $ PC.Level.sAssaultFriendlyForcesText $ "||";
			Briefing = Briefing $ "    C. TERRAIN: " $ PC.Level.sAssaultTerrainText $ "||";
			Briefing = Briefing $ "    D. ROE: " $ PC.Level.sAssaultROEText $ "||";
			break;
		case 1:
			Briefing = "1. SITUATION: " $ PC.Level.sDefenseSituationText $ "||";
			Briefing = Briefing $ "2. MISSION: " $ PC.Level.sDefenseMissionText $ "||";
			Briefing = Briefing $ "3. GENERAL INSTRUCTIONS: ||";
			Briefing = Briefing $ "    A. ENEMY FORCES: " $ PC.Level.sDefenseEnemyForcesText $ "||";
			Briefing = Briefing $ "    B. FRIENDLY FORCES: " $ PC.Level.sDefenseFriendlyForcesText $ "||";
			Briefing = Briefing $ "    C. TERRAIN: " $ PC.Level.sDefenseTerrainText $ "||";
			Briefing = Briefing $ "    D. ROE: " $ PC.Level.sDefenseROEText $ "||";
			break;
		default:
		}
	}
	*/
	return Briefing;
}

bool UAAGameMenu_TeamSelect::MyOnPreDraw(UCanvas* C)
{
	/*
	int32 i = 0;
	uint8 TestTeam = 0;
	uint8 TestDesired = 0;
	local PlayerReplicationInfo PRI;
	for (i = 0; i < 2; i++)
	{
		l_TeamName[i].Caption = PlayerOwner().Level.TeamName[i];
		if (((HumanController(PlayerOwner()) != None) && HumanController(PlayerOwner()).bTournamentServer) && (HumanController(PlayerOwner()).GetTeamName(i) != ""))
		{
			l_TeamName[i].Caption = l_TeamName[i].Caption $ "[" $ HumanController(PlayerOwner()).GetTeamName(i) $ "]";
		}
		if (PlayerOwner().GameReplicationInfo.Teams[i] != None)
		{
			l_TeamName[i].Caption = l_TeamName[i].Caption $ " (" $ string(PlayerOwner().GameReplicationInfo.Teams[i].Size);
			if (PlayerOwner().GameReplicationInfo.Teams[i].Size == 1)
			{
				l_TeamName[i].Caption = l_TeamName[i].Caption $ " Player";
			}
			else
			{
				l_TeamName[i].Caption = l_TeamName[i].Caption $ " Players";
			}
		}
		else
		{
			l_TeamName[i].Caption = l_TeamName[i].Caption $ "0 Players";
		}
		l_TeamName[i].Caption = l_TeamName[i].Caption $ ")";
		if ((HumanController(PlayerOwner()) != None) && (!HumanController(PlayerOwner()).bTournamentServer))
		{
			ed_Password[i].bVisible = false;
			ed_Password[i].SetHint("");
		}
		if (HumanController(PlayerOwner()) != None)
		{
			PRI = HumanController(PlayerOwner()).PlayerReplicationInfo;
			if ((PRI != None) && PRI.bOnlySpectator)
			{
				b_Join[i].bVisible = false;
				ed_Password[i].bVisible = false;
				ed_Password[i].SetHint("");
			}
		}
	}
	if ((PlayerOwner().PlayerReplicationInfo != None) && (PlayerOwner().PlayerReplicationInfo.Team != None))
	{
		TestTeam = byte(PlayerOwner().PlayerReplicationInfo.Team.TeamIndex);
		TestDesired = PlayerOwner().PlayerReplicationInfo.DesiredTeam;
	}
	if ((TestTeam != lastTeam) || (TestDesired != LastDesired))
	{
		lastTeam = TestTeam;
		LastDesired = TestDesired;
		CheckTeam(lastTeam, LastDesired);
	}
	if ((PlayerOwner().PlayerReplicationInfo != None) && PlayerOwner().PlayerReplicationInfo.bOnlySpectator)
	{
		b_Spectate.bVisible = false;
		b_Spectate.DisableMe();
		b_Auto.bVisible = false;
		b_Auto.DisableMe();
	}
	if ((HumanController(PlayerOwner()) != None) && HumanController(PlayerOwner()).bTournamentServer)
	{
		b_Auto.bVisible = false;
		b_Auto.DisableMe();
	}
	*/
	return true;
}

void UAAGameMenu_TeamSelect::CheckTeam(uint8 CurrTeam, uint8 CurrDesired)
{
	/*
	int32 i = 0;
	for (i = 0; i < 2; i++)
	{
		if (CurrTeam == CurrDesired)
		{
			if (i == CurrTeam)
			{
				l_TeamMsg[i].Caption = OnTeam;
				l_TeamMsg[i].bVisible = true;
				b_Join[i].bVisible = false;
				if (HumanController(PlayerOwner()).bTournamentServer)
				{
					ed_Password[i].bVisible = false;
					ed_Password[i].SetHint("");
				}
			}
			else
			{
				l_TeamMsg[i].bVisible = false;
				b_Join[i].bVisible = true;
				b_Join[i].Caption = JoinText;
				if (HumanController(PlayerOwner()).bTournamentServer)
				{
					ed_Password[i].bVisible = true;
					ed_Password[i].SetHint(s_JoinHint);
				}
			}
		}
		else
		{
			if (i == CurrTeam)
			{
				if (HumanController(PlayerOwner()).bTournamentServer)
				{
				}
				l_TeamMsg[i].bVisible = true;
				l_TeamMsg[i].Caption = LeavingTeam;
				b_Join[i].bVisible = true;
				b_Join[i].Caption = RemainText;
			}
			else
			{
				if (i == CurrDesired)
				{
					if (HumanController(PlayerOwner()).bTournamentServer)
					{
					}
					l_TeamMsg[i].bVisible = true;
					if (CurrTeam == 255)
					{
						l_TeamMsg[i].Caption = ASAPTeam;
					}
					else
					{
						l_TeamMsg[i].Caption = GoingToTeam;
					}
					b_Join[i].bVisible = false;
				}
				else
				{
					l_TeamMsg[i].bVisible = false;
					b_Join[i].bVisible = true;
					b_Join[i].Caption = JoinText;
					if (HumanController(PlayerOwner()).bTournamentServer)
					{
						ed_Password[i].bVisible = true;
						ed_Password[i].SetHint(s_JoinHint);
					}
				}
			}
		}
	}
	*/
}

bool UAAGameMenu_TeamSelect::CheckTeamPassword(int32 TeamNum, FString Password)
{
	return true;
}

void UAAGameMenu_TeamSelect::JoinTeam(int32 i)
{
	/*
	if ((PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == 255) && PlayerOwner().PlayerReplicationInfo.bOnlySpectator)
	{
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Spectators Cannot Play", "You are currently a spectator and cannot join a team without reconnecting to the server.");
		return;
	}
	if (i != -1)
	{
		PlayerOwner().PlayerReplicationInfo.DesiredTeam = byte(i);
		if (((AAGameMenu(Controller.ActivePage) != None) && (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == 255)) && (PlayerOwner().GameReplicationInfo.Teams[i].Size < PlayerOwner().GameReplicationInfo.Teams[i].MaxSize))
		{
			AAGameMenu(Controller.ActivePage).SwitchPanel(1);
		}
	}
	PlayerOwner().RequestChangeTeam(i);
	*/
}

void UAAGameMenu_TeamSelect::SpectateTeam(int32 i)
{
	/*
	Log("Current team: " $ string(PlayerOwner().PlayerReplicationInfo.Team.TeamIndex));
	Controller.CloseMenu();
	if (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == 255)
	{
		PlayerOwner().RequestChangeTeam(254);
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Entering Spectator Mode", "Now that you have become a spectator you must reconnect if you wish to play on either team.");
	}
	else
	{
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Cannot Join Spectators Now", "You can only switch to spectator mode before joining a team that is playing.");
	}
	*/
}

bool UAAGameMenu_TeamSelect::ButtonClick(UGUIComponent* Sender)
{
	/*
	int32 i = 0;
	if (HumanController(PlayerOwner()).bTournamentServer)
	{
		if (PlayerOwner().PlayerReplicationInfo.bAdmin)
		{
			return false;
		}
	}
	for (i = 0; i < 2; i++)
	{
		if (Sender == b_Join[i])
		{
			if (HumanController(PlayerOwner()).bTournamentServer)
			{
				if (!CheckTeamPassword(i, ed_Password[i].GetText()))
				{
					return false;
				}
				HumanController(PlayerOwner()).TournamentJoinTeam(i, ed_Password[i].GetText());
			}
			else
			{
				JoinTeam(i);
			}
			return true;
		}
	}
	if (Sender == b_Auto)
	{
		PlayerOwner().RequestChangeTeam(-1);
		return true;
	}
	if (Sender == b_Spectate)
	{
		if (HumanController(PlayerOwner()).bTournamentServer)
		{
			HumanController(PlayerOwner()).TournamentJoinSpectatorTeam(255);
			Controller.CloseMenu();
		}
		else
		{
			SpectateTeam(255);
		}
		return true;
	}
	*/
	return false;
}

void UAAGameMenu_TeamSelect::Timer()
{
	/*
	local PlayerReplicationInfo PRI;
	uint8 TestTeam = 0;
	uint8 TestDesired = 0;
	TestTeam = 255;
	TestDesired = 255;
	PRI = PlayerOwner().PlayerReplicationInfo;
	if (PRI != None)
	{
		if (PRI.Team != None)
		{
			TestTeam = byte(PRI.Team.TeamIndex);
		}
		TestDesired = PRI.DesiredTeam;
	}
	if ((TestTeam != lastTeam) || (TestDesired != LastDesired))
	{
		lastTeam = TestTeam;
		LastDesired = TestDesired;
		CheckTeam(lastTeam, LastDesired);
	}
	*/
}

void UAAGameMenu_TeamSelect::ShowPanel(bool bShow)
{
	/*
	Super::ShowPanel(bShow);
	if (bShow)
	{
		CheckTeam(lastTeam, LastDesired);
		SetTimer(0.1, true);
	}
	else
	{
		SetTimer(0, false);
	}
	*/
}
