// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AATeamGamePanel/AAGameMenu_CoOpTeamSelect/AAGameMenu_CoOpTeamSelect.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAAGameMenu_CoOpTeamSelect::UAAGameMenu_CoOpTeamSelect()
{
	UGUIButton* SpectateButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SpectateButton->Caption="SPECTATE";
	SpectateButton->StyleName="SquareMenuButton";
	SpectateButton->Hint="Spectate.";
	SpectateButton->WinTop=0.81;
	SpectateButton->WinLeft=0.79;
	SpectateButton->WinWidth=0.15;
	SpectateButton->WinHeight=0.06;
	SpectateButton->TabOrder=5;
	//SpectateButton->OnClick=AAGameMenu_CoOpTeamSelect.ButtonClick;
	//SpectateButton->OnKeyEvent=SpectateButton.InternalOnKeyEvent;
	UGUIButton* Join1 = NewObject<UGUIButton>(UGUIButton::StaticClass());
	Join1->Caption="PLAY COOP";
	Join1->StyleName="SquareMenuButton";
	Join1->Hint="Play Coop Game.";
	Join1->WinTop=0.81;
	Join1->WinLeft=0.62;
	Join1->WinWidth=0.15;
	Join1->WinHeight=0.06;
	Join1->TabOrder=0;
	//Join1->OnClick=AAGameMenu_CoOpTeamSelect.ButtonClick;
	//Join1->OnKeyEvent=Join1.InternalOnKeyEvent;
	UmoEditBox* PasswordEdit1 = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	PasswordEdit1->CaptionWidth=0.2;
	PasswordEdit1->Caption="Password";
	//PasswordEdit1->OnCreateComponent=PasswordEdit1.InternalOnCreateComponent;
	PasswordEdit1->Hint="Click here then enter the team password";
	PasswordEdit1->WinTop=0.81;
	PasswordEdit1->WinLeft=0.35;
	PasswordEdit1->WinWidth=0.25;
	PasswordEdit1->WinHeight=0.06;
	PasswordEdit1->TabOrder=2;
	PasswordEdit1->bStandardized=false;
	UGUIScrollTextBox* TeamScroll1 = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	TeamScroll1->bNoTeletype=true;
	TeamScroll1->bVisibleWhenEmpty=true;
	//TeamScroll1->OnCreateComponent=TeamScroll1.InternalOnCreateComponent;
	TeamScroll1->StyleName="SmallText";
	TeamScroll1->WinTop=0.09;
	TeamScroll1->WinLeft=0.03;
	TeamScroll1->WinWidth=0.94;
	TeamScroll1->WinHeight=0.66;
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
	BG1->WinHeight=0.86;
	UGUILabel* TeamName1 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TeamName1->TextColor=FColor(255, 255, 255, 255);
	TeamName1->TextFont="AAFontLarge";
	TeamName1->WinTop=0.02;
	TeamName1->WinLeft=0.03;
	TeamName1->WinWidth=0.94;
	UGUILabel* TeamMsg1 = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TeamMsg1->TextColor=FColor(255, 255, 255, 255);
	TeamMsg1->TextFont="AAFontMedium";
	TeamMsg1->WinTop=0.32;
	TeamMsg1->WinLeft=0.03;
	TeamMsg1->WinWidth=0.6;
	
	i_Background = MyBackground;
	i_Team = BG1;
	l_TeamName = TeamName1;
	l_TeamMsg = TeamMsg1;
	lb_Briefing = TeamScroll1;
	ed_Password = PasswordEdit1;
	b_Join = Join1;
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
	//OnPreDraw = AAGameMenu_CoOpTeamSelect.MyOnPreDraw;

}


void UAAGameMenu_CoOpTeamSelect::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	FString Directory = "";
	FString File = "";
	local AAGUIController C;
	local GameReplicationInfo GRI;
	Super::InitComponent(MyController, MyOwner);
	C = AAGUIController(MyController);
	GRI = PlayerOwner().GameReplicationInfo;
	Directory = GetBaseDir();
	Directory = Left(Directory, (Len(Directory) - 7));
	(Directory $ = "Briefings\\");
	File = PlayerOwner().Level.GetLevelName();
	if ((GRI == None) || (GRI.Teams[0] == None))
	{
		return;
	}
	if (((PlayerOwner().PlayerReplicationInfo != None) && (PlayerOwner().PlayerReplicationInfo.Team != None)) && (PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == 0))
	{
		b_Join.DisableMe();
	}
	if (PlayerOwner().Level.sAssaultSituationText != "")
	{
		lb_Briefing.SetContent(BuildMissionBriefing(0));
	}
	else
	{
		lb_Briefing.SetContent(C.LoadTextFromFile(Directory $ File $ "_team0.txt"));
	}
	*/
}

FString UAAGameMenu_CoOpTeamSelect::BuildMissionBriefing(int32 iTeam)
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

bool UAAGameMenu_CoOpTeamSelect::MyOnPreDraw(UCanvas* C)
{
	/*
	local PlayerReplicationInfo PRI;
	l_TeamName.Caption = PlayerOwner().Level.TeamName[0];
	if (((HumanController(PlayerOwner()) != None) && HumanController(PlayerOwner()).bTournamentServer) && (HumanController(PlayerOwner()).GetTeamName(0) != ""))
	{
		l_TeamName.Caption = l_TeamName.Caption $ "[" $ HumanController(PlayerOwner()).GetTeamName(0) $ "]";
	}
	if (PlayerOwner().GameReplicationInfo.Teams[0] != None)
	{
		l_TeamName.Caption = l_TeamName.Caption $ " (" $ string(PlayerOwner().GameReplicationInfo.Teams[0].Size);
		if (PlayerOwner().GameReplicationInfo.Teams[0].Size == 1)
		{
			l_TeamName.Caption = l_TeamName.Caption $ " Player";
		}
		else
		{
			l_TeamName.Caption = l_TeamName.Caption $ " Players";
		}
	}
	else
	{
		l_TeamName.Caption = l_TeamName.Caption $ "0 Players";
	}
	l_TeamName.Caption = l_TeamName.Caption $ ")";
	l_TeamName.Caption = l_TeamName.Caption $ " (Coop Game)";
	if ((HumanController(PlayerOwner()) != None) && (!HumanController(PlayerOwner()).bTournamentServer))
	{
		ed_Password.bVisible = false;
		ed_Password.SetHint("");
	}
	if (HumanController(PlayerOwner()) != None)
	{
		PRI = HumanController(PlayerOwner()).PlayerReplicationInfo;
		if ((PRI != None) && PRI.bOnlySpectator)
		{
			b_Join.bVisible = false;
			ed_Password.bVisible = false;
			ed_Password.SetHint("");
		}
	}
	if ((PlayerOwner().PlayerReplicationInfo != None) && PlayerOwner().PlayerReplicationInfo.bOnlySpectator)
	{
		b_Spectate.bVisible = false;
		b_Spectate.DisableMe();
	}
	*/
	return true;
}

void UAAGameMenu_CoOpTeamSelect::CheckTeam(uint8 CurrTeam, uint8 CurrDesired)
{
	/*
	int32 i = 0;
	for (i = 0; i < 2; i++)
	{
		if (CurrTeam == CurrDesired)
		{
			if (i == CurrTeam)
			{
				l_TeamMsg.Caption = OnTeam;
				l_TeamMsg.bVisible = true;
				b_Join.bVisible = false;
				if (HumanController(PlayerOwner()).bTournamentServer)
				{
					ed_Password.bVisible = false;
					ed_Password.SetHint("");
				}
			}
			else
			{
				l_TeamMsg.bVisible = false;
				b_Join.bVisible = true;
				b_Join.Caption = JoinText;
				if (HumanController(PlayerOwner()).bTournamentServer)
				{
					ed_Password.bVisible = true;
					ed_Password.SetHint(s_JoinHint);
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
				l_TeamMsg.bVisible = true;
				l_TeamMsg.Caption = LeavingTeam;
				b_Join.bVisible = true;
				b_Join.Caption = RemainText;
			}
			else
			{
				if (i == CurrDesired)
				{
					if (HumanController(PlayerOwner()).bTournamentServer)
					{
					}
					l_TeamMsg.bVisible = true;
					if (CurrTeam == 255)
					{
						l_TeamMsg.Caption = ASAPTeam;
					}
					else
					{
						l_TeamMsg.Caption = GoingToTeam;
					}
					b_Join.bVisible = false;
				}
				else
				{
					l_TeamMsg.bVisible = false;
					b_Join.bVisible = true;
					b_Join.Caption = JoinText;
					if (HumanController(PlayerOwner()).bTournamentServer)
					{
						ed_Password.bVisible = true;
						ed_Password.SetHint(s_JoinHint);
					}
				}
			}
		}
	}
	*/
}

bool UAAGameMenu_CoOpTeamSelect::CheckTeamPassword(int32 TeamNum, FString Password)
{
	return true;
}

void UAAGameMenu_CoOpTeamSelect::JoinTeam(int32 i)
{
	/*
	if ((PlayerOwner().PlayerReplicationInfo.Team.TeamIndex == 255) && PlayerOwner().PlayerReplicationInfo.bOnlySpectator)
	{
		Controller.OpenMenu("AGP_Interface.AAGenericMessageBox", "Spectators Cannot Play", "You are currently a spectator and cannot join a team without reconnecting to the server.");
		return;
	}
	PlayerOwner().PlayerReplicationInfo.DesiredTeam = 0;
	PlayerOwner().RequestChangeTeam(0);
	AAGameMenu(Controller.ActivePage).SwitchPanel(1);
	*/
}

void UAAGameMenu_CoOpTeamSelect::SpectateTeam()
{
	/*
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

bool UAAGameMenu_CoOpTeamSelect::ButtonClick(UGUIComponent* Sender)
{
	/*
	if (HumanController(PlayerOwner()).bTournamentServer)
	{
		if (PlayerOwner().PlayerReplicationInfo.bAdmin)
		{
			return false;
		}
	}
	if (Sender == b_Join)
	{
		if (HumanController(PlayerOwner()).bTournamentServer)
		{
			if (!CheckTeamPassword(0, ed_Password.GetText()))
			{
				return false;
			}
			HumanController(PlayerOwner()).TournamentJoinTeam(0, ed_Password.GetText());
		}
		else
		{
			JoinTeam(0);
		}
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
			SpectateTeam();
		}
		return true;
	}
	*/
	return false;
}

void UAAGameMenu_CoOpTeamSelect::Timer()
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

void UAAGameMenu_CoOpTeamSelect::ShowPanel(bool bShow)
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
