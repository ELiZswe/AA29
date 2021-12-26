// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_ServerInfo/AAGameMenu_TournamentServerInfo/AAGameMenu_TournamentServerInfo.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UAAGameMenu_TournamentServerInfo::UAAGameMenu_TournamentServerInfo()
{
	UGUIButton* TossRoundButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	TossRoundButton->Caption = "Discard Round";
	TossRoundButton->StyleName = "SquareMenuButton";
	TossRoundButton->Hint = "Press to discard this round and treat it as a \"Non-Scoring\" round.";
	TossRoundButton->WinTop = 0.81;
	TossRoundButton->WinLeft = 0.74;
	TossRoundButton->WinWidth = 0.19;
	TossRoundButton->WinHeight = 0.06;
	//TossRoundButton->OnClick=AAGameMenu_TournamentServerInfo.InternalOnClick;
	//TossRoundButton->OnKeyEvent=TossRoundButton.InternalOnKeyEvent;
	UGUIButton* SwapTeamsButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	SwapTeamsButton->Caption = "Swap";
	SwapTeamsButton->StyleName = "SquareMenuButton";
	SwapTeamsButton->Hint = "Press to swap teams.";
	SwapTeamsButton->WinTop = 0.81;
	SwapTeamsButton->WinLeft = 0.52;
	SwapTeamsButton->WinWidth = 0.19;
	SwapTeamsButton->WinHeight = 0.06;
	//SwapTeamsButton->OnClick=AAGameMenu_TournamentServerInfo.InternalOnClick;
	//SwapTeamsButton->OnKeyEvent=SwapTeamsButton.InternalOnKeyEvent;
	UGUIButton* PauseTournamentButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	PauseTournamentButton->Caption = "Pause";
	PauseTournamentButton->StyleName = "SquareMenuButton";
	PauseTournamentButton->Hint = "Press to Pause Tournament.";
	PauseTournamentButton->WinTop = 0.81;
	PauseTournamentButton->WinLeft = 0.3;
	PauseTournamentButton->WinWidth = 0.19;
	PauseTournamentButton->WinHeight = 0.06;
	//PauseTournamentButton->OnClick=AAGameMenu_TournamentServerInfo.InternalOnClick;
	//PauseTournamentButton->OnKeyEvent=PauseTournamentButton.InternalOnKeyEvent;
	UGUIButton* StartMatchButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	StartMatchButton->Caption = "Start Match";
	StartMatchButton->StyleName = "SquareMenuButton";
	StartMatchButton->Hint = "Click here to start or restart the tournament.";
	StartMatchButton->WinTop = 0.81;
	StartMatchButton->WinLeft = 0.08;
	StartMatchButton->WinWidth = 0.19;
	StartMatchButton->WinHeight = 0.06;
	//StartMatchButton->OnClick=AAGameMenu_TournamentServerInfo.InternalOnClick;
	//StartMatchButton->OnKeyEvent=StartMatchButton.InternalOnKeyEvent;
	UGUIImage* BG2 = NewObject<UGUIImage>(UGUIImage::StaticClass());
	BG2->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucen_Mat.field_translucen_Mat'"), NULL, LOAD_None, NULL);
	BG2->ImageStyle = EImgStyle::ISTY_Stretched;
	BG2->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	BG2->WinTop = 0.8;
	BG2->WinLeft = 0.02;
	BG2->WinWidth = 0.96;
	BG2->WinHeight = 0.08;
	UGUILabel* TournamentRoundDelayTimeLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TournamentRoundDelayTimeLabel->TextColor = FColor(255, 255, 255, 255);
	TournamentRoundDelayTimeLabel->TextFont = "AAFontMedium";
	TournamentRoundDelayTimeLabel->WinTop = 0.4;
	TournamentRoundDelayTimeLabel->WinLeft = 0.1;
	TournamentRoundDelayTimeLabel->WinWidth = 0.8;
	UGUILabel* TournamentRequestDelayTimeLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TournamentRequestDelayTimeLabel->TextColor = FColor(255, 255, 255, 255);
	TournamentRequestDelayTimeLabel->TextFont = "AAFontMedium";
	TournamentRequestDelayTimeLabel->WinTop = 0.43;
	TournamentRequestDelayTimeLabel->WinLeft = 0.1;
	TournamentRequestDelayTimeLabel->WinWidth = 0.8;
	UGUILabel* TournamentWarmupDurationLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TournamentWarmupDurationLabel->TextColor = FColor(255, 255, 255, 255);
	TournamentWarmupDurationLabel->TextFont = "AAFontMedium";
	TournamentWarmupDurationLabel->WinTop = 0.46;
	TournamentWarmupDurationLabel->WinLeft = 0.1;
	TournamentWarmupDurationLabel->WinWidth = 0.8;
	UGUILabel* TournamentSwapTimeLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TournamentSwapTimeLabel->TextColor = FColor(255, 255, 255, 255);
	TournamentSwapTimeLabel->TextFont = "AAFontMedium";
	TournamentSwapTimeLabel->WinTop = 0.49;
	TournamentSwapTimeLabel->WinLeft = 0.1;
	TournamentSwapTimeLabel->WinWidth = 0.8;
	UGUILabel* TournamentSwapLimitLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TournamentSwapLimitLabel->TextColor = FColor(255, 255, 255, 255);
	TournamentSwapLimitLabel->TextFont = "AAFontMedium";
	TournamentSwapLimitLabel->WinTop = 0.52;
	TournamentSwapLimitLabel->WinLeft = 0.1;
	TournamentSwapLimitLabel->WinWidth = 0.8;
	UGUILabel* TournamentMercyRuleLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TournamentMercyRuleLabel->TextColor = FColor(255, 255, 255, 255);
	TournamentMercyRuleLabel->TextFont = "AAFontMedium";
	TournamentMercyRuleLabel->WinTop = 0.55;
	TournamentMercyRuleLabel->WinLeft = 0.1;
	TournamentMercyRuleLabel->WinWidth = 0.8;
	UGUILabel* TournamentOpenAllWeaponClassSlotsLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TournamentOpenAllWeaponClassSlotsLabel->TextColor = FColor(255, 255, 255, 255);
	TournamentOpenAllWeaponClassSlotsLabel->TextFont = "AAFontMedium";
	TournamentOpenAllWeaponClassSlotsLabel->WinTop = 0.58;
	TournamentOpenAllWeaponClassSlotsLabel->WinLeft = 0.1;
	TournamentOpenAllWeaponClassSlotsLabel->WinWidth = 0.8;
	UGUILabel* TournamentTeamCaptainsAllowedLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TournamentTeamCaptainsAllowedLabel->TextColor = FColor(255, 255, 255, 255);
	TournamentTeamCaptainsAllowedLabel->TextFont = "AAFontMedium";
	TournamentTeamCaptainsAllowedLabel->WinTop = 0.61;
	TournamentTeamCaptainsAllowedLabel->WinLeft = 0.1;
	TournamentTeamCaptainsAllowedLabel->WinWidth = 0.8;
	UGUILabel* TournamentTeamPasswordsRequiredLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TournamentTeamPasswordsRequiredLabel->TextColor = FColor(255, 255, 255, 255);
	TournamentTeamPasswordsRequiredLabel->TextFont = "AAFontMedium";
	TournamentTeamPasswordsRequiredLabel->WinTop = 0.64;
	TournamentTeamPasswordsRequiredLabel->WinLeft = 0.1;
	TournamentTeamPasswordsRequiredLabel->WinWidth = 0.8;
	UGUILabel* TournamentTieSuddenDeathLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TournamentTieSuddenDeathLabel->TextColor = FColor(255, 255, 255, 255);
	TournamentTieSuddenDeathLabel->TextFont = "AAFontMedium";
	TournamentTieSuddenDeathLabel->WinTop = 0.67;
	TournamentTieSuddenDeathLabel->WinLeft = 0.1;
	TournamentTieSuddenDeathLabel->WinWidth = 0.8;
	UGUILabel* TournamentEnableRandomTeamAssignmentsLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TournamentEnableRandomTeamAssignmentsLabel->TextColor = FColor(255, 255, 255, 255);
	TournamentEnableRandomTeamAssignmentsLabel->TextFont = "AAFontMedium";
	TournamentEnableRandomTeamAssignmentsLabel->WinTop = 0.7;
	TournamentEnableRandomTeamAssignmentsLabel->WinLeft = 0.1;
	TournamentEnableRandomTeamAssignmentsLabel->WinWidth = 0.8;
	UGUILabel* TournamentShadowsAllowedLabel = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TournamentShadowsAllowedLabel->TextColor = FColor(255, 255, 255, 255);
	TournamentShadowsAllowedLabel->TextFont = "AAFontMedium";
	TournamentShadowsAllowedLabel->WinTop = 0.73;
	TournamentShadowsAllowedLabel->WinLeft = 0.1;
	TournamentShadowsAllowedLabel->WinWidth = 0.8;
	i_Buttons = BG2;
	l_TournamentRoundDelayTime = TournamentRoundDelayTimeLabel;
	l_TournamentRequestDelayTime = TournamentRequestDelayTimeLabel;
	l_TournamentWarmupDuration = TournamentWarmupDurationLabel;
	l_TournamentSwapTime = TournamentSwapTimeLabel;
	l_TournamentSwapLimit = TournamentSwapLimitLabel;
	l_TournamentMercyRule = TournamentMercyRuleLabel;
	l_TournamentOpenAllWeaponClassSlots = TournamentOpenAllWeaponClassSlotsLabel;
	l_TournamentTeamCaptainsAllowed = TournamentTeamCaptainsAllowedLabel;
	l_TournamentTeamPasswordsRequired = TournamentTeamPasswordsRequiredLabel;
	l_TournamentTieSuddenDeath = TournamentTieSuddenDeathLabel;
	l_TournamentEnableRandomTeamAssignments = TournamentEnableRandomTeamAssignmentsLabel;
	l_TournamentShadowsAllowedLabel = TournamentShadowsAllowedLabel;
	b_StartMatch = StartMatchButton;
	b_PauseTournament = PauseTournamentButton;
	b_SwapTeams = SwapTeamsButton;
	b_DiscardRound = TossRoundButton;

}

void UAAGameMenu_TournamentServerInfo::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	i_Info.WinHeight = 0.77;
	*/
}

bool UAAGameMenu_TournamentServerInfo::InternalOnPreDraw(UCanvas* C)
{
	/*
	local int i;
	local GameReplicationInfo GRI;
	local AGP.HumanController HC;
	local int minutes;
	local int Seconds;
	local string MapName;
	local string GameRound;
	local string GameStatus;
	local string GameTimer;
	InternalOnPreDraw(C);
	if (PlayerOwner() != None)
	{
		GRI = PlayerOwner().GameReplicationInfo;
	}
	if (GRI == nullptr)
	{
		return false;
	}
	HC = HumanController(PlayerOwner());
	MapName = PlayerOwner().Level.GetLevelNamePrivate();
	if (GRI != None)
	{
		if (HC.GameReplicationInfo.sTournamentState == "Setup")
		{
			GameRound = "Pre-Tournament Setup";
		}
		else
		{
			if (HC.GameReplicationInfo.sTournamentState == "Mission Planning" && GRI.RoundsPerMatch - GRI.RemainingRounds == GRI.RoundsPerMatch && GRI.RoundsPerMatch == 1)
			{
				GameRound = "Tournament Mission Planning";
			}
			else
			{
				if (HC.GameReplicationInfo.sTournamentState == "Mission Planning")
				{
					GameRound = "Mission Planning, Rounds Completed" @ GRI.RoundsPerMatch - GRI.RemainingRounds - 1 $ "/" $ GRI.RoundsPerMatch;
				}
				else
				{
					if (HC.GameReplicationInfo.sTournamentState == "Non-Scoring Round")
					{
						GameRound = "Non-Scoring Round, Rounds Completed" @ GRI.RoundsPerMatch - GRI.RemainingRounds - 1 $ "/" $ GRI.RoundsPerMatch;
					}
					else
					{
						if (HC.GameReplicationInfo.sTournamentState == "Swapping Sides")
						{
							GameRound = "Swapping Sides, Rounds Completed" @ GRI.RoundsPerMatch - GRI.RemainingRounds $ "/" $ GRI.RoundsPerMatch;
						}
						else
						{
							if (HC.GameReplicationInfo.sTournamentState == "Complete")
							{
								GameRound = "Tournament Complete after " @ GRI.RoundsPerMatch - GRI.RemainingRounds $ " rounds";
							}
							else
							{
								GameRound = "Current Round:" @ GRI.RoundsPerMatch - GRI.RemainingRounds $ "/" $ GRI.RoundsPerMatch;
							}
						}
					}
				}
			}
		}
	}
	if (HC != None && HC.bTournamentServer && !GRI.bTournamentInProgress)
	{
		if (GRI.sTournamentState != "")
		{
			GameStatus = "( " $ GRI.sTournamentState $ " )";
		}
		else
		{
			GameStatus = " ";
		}
		if (GRI.TournamentCountDownTime >= 0)
		{
			minutes = GRI.TournamentCountDownTime / 60;
			Seconds = GRI.TournamentCountDownTime % 60;
		}
		else
		{
			minutes = 0;
			Seconds = 0;
		}
	}
	else
	{
		if (GRI.RemainingTime >= 0)
		{
			minutes = GRI.RemainingTime / 60;
			Seconds = GRI.RemainingTime % 60;
		}
		else
		{
			minutes = GRI.ElapsedTime / 60;
			Seconds = GRI.ElapsedTime % 60;
		}
	}
	GameTimer = TwoDigitString(minutes) $ ":" $ TwoDigitString(Seconds);
	l_Game.Caption = MapName @ "-" @ GameRound @ GameTimer;
	if (HC != None && HC.bTournamentServer)
	{
		for (i = 0; i < 2; i++)
		{
			l_Teams[i].Caption = PlayerOwner().Level.TeamName[i];
			if (HC.GetTeamName(i) != "")
			{
				l_Teams[i].Caption $ = "[" $ HC.GetTeamName(i) $ "]";
			}
			l_Teams[i].Caption $ = " " $ GRI.Teams[i].teamScore $ "/" $ GRI.RoundsPerMatch;
		}
		l_TournamentRoundDelayTime.Caption = "Delay Time Between Rounds: " $ GRI.iTournamentRoundDelayTime $ " seconds";
		l_TournamentRequestDelayTime.Caption = "Minimum Time Between Team Captain Requests: " $ GRI.iTournamentRequestDelayTime $ " seconds";
		l_TournamentWarmupDuration.Caption = "Mission Planning Length: " $ GRI.iTournamentWarmupDuration $ " minutes";
		l_TournamentSwapTime.Caption = "Time Allowed for Managing Roster After Swap: " $ GRI.iTournamentSwapTime $ " seconds";
		l_TournamentSwapLimit.Caption = "Rounds to complete before swapping: " $ GRI.iTournamentSwapLimit;
		l_TournamentMercyRule.Caption = "ENDEX (End when team statistically eliminated): " $ GRI.bTournamentMercyRule;
		l_TournamentOpenAllWeaponClassSlots.Caption = "Open All Weapon Class Slots: " $ GRI.bTournamentOpenAllWeaponClassSlots;
		l_TournamentTeamCaptainsAllowed.Caption = "Team Captains Allowed: " $ GRI.bTournamentTeamCaptainsAllowed;
		l_TournamentTeamPasswordsRequired.Caption = "Team Passwords Required: " $ GRI.bTournamentTeamPasswordsRequired;
		if (GRI.bTournamentTieSuddenDeath && !GRI.bTournamentTieScore)
		{
			l_TournamentTieSuddenDeath.Caption = "Tie-Breaking Rules: Sudden Death";
		}
		else
		{
			if (!GRI.bTournamentTieSuddenDeath && GRI.bTournamentTieScore)
			{
				l_TournamentTieSuddenDeath.Caption = "Tie-Breaking Rules: Use Team Scoring";
			}
			else
			{
				l_TournamentTieSuddenDeath.Caption = "Tie-Breaking Rules: Ties allowed";
			}
		}
		l_TournamentEnableRandomTeamAssignments.Caption = "Teams assigned randomly on server startup: " $ GRI.bTournamentEnableRandomTeamAssignments;
		if (PlayerOwner().Level.GRI.bForceShadowsOff)
		{
			l_TournamentShadowsAllowedLabel.Caption = "Player shadows are disabled for all players";
		}
		else
		{
			l_TournamentShadowsAllowedLabel.Caption = "Player shadows are enabled for all players";
		}
	}
	if (PlayerOwner().PlayerReplicationInfo.bAdmin || PlayerOwner().PlayerReplicationInfo.bTournamentTeamCaptain)
	{
		EnableComponent(b_StartWarmup);
		EnableComponent(b_StartMatch);
		EnableComponent(b_PauseTournament);
		if (HC.GameReplicationInfo.sTournamentState == "Live Play")
		{
			EnableComponent(b_DiscardRound);
			EnableComponent(b_SwapTeams);
			EnableComponent(b_PauseTournament);
		}
		else
		{
			DisableComponent(b_SwapTeams);
			DisableComponent(b_DiscardRound);
			DisableComponent(b_PauseTournament);
		}
		if (iAdminRestartTimer == 0)
		{
			if (HC.GameReplicationInfo.sTournamentState != "Setup")
			{
				b_StartMatch.Caption = "Restart Tournament";
				b_StartMatch.Hint = "Click here to start or restart the tournament.";
			}
			else
			{
				b_StartMatch.Caption = "Start Tournament";
			}
		}
	}
	else
	{
		DisableComponent(b_StartWarmup);
		DisableComponent(b_StartMatch);
		DisableComponent(b_PauseTournament);
		DisableComponent(b_SwapTeams);
		DisableComponent(b_DiscardRound);
	}
	*/
	return true;
}

bool UAAGameMenu_TournamentServerInfo::InternalOnClick(UGUIComponent* Sender)
{
	/*
	local AGP.HumanController HC;
	HC = HumanController(PlayerOwner());
	if (Sender == b_DiscardRound)
	{
		if (HC != None && HC.bTournamentServer)
		{
			if (HC.PlayerReplicationInfo.bTournamentTeamCaptain || HC.PlayerReplicationInfo.bAdmin)
			{
				if (HC.GameReplicationInfo.sTournamentState == "Live Play")
				{
					HC.TournamentRequestDeadRound();
				}
				return true;
			}
		}
	}
	if (Sender == b_StartWarmup)
	{
		if (HC != None && HC.bTournamentServer)
		{
			if (HC.PlayerReplicationInfo.bTournamentTeamCaptain || HC.PlayerReplicationInfo.bAdmin)
			{
				HC.TournamentRequestStartWarmup();
			}
		}
	}
	else
	{
		if (Sender == b_StartMatch)
		{
			if (HC != None && HC.bTournamentServer)
			{
				Log("Restart TM pressed");
				if (HC.PlayerReplicationInfo.bTournamentTeamCaptain || HC.PlayerReplicationInfo.bAdmin)
				{
					if (HC.PlayerReplicationInfo.bAdmin)
					{
						Log("Restart TM pressed by admin");
						if (iAdminRestartTimer > 0)
						{
							Log("Cancel TM restart pressed");
							HumanController(PlayerOwner()).ConsoleCommand("admin message Admin has cancelled the Tournament Restart command.");
							b_StartMatch.Caption = "Restart Tournament";
							SetTimer(0, False);
							iAdminRestartTimer = 0;
							return true;
						}
						else
						{
							Log("Restart TM pressed, initating timer");
							b_StartMatch.Caption = "Cancel Restart In 10";
							iAdminRestartTimer = 10;
							SetTimer(1, True);
							return true;
						}
					}
					else
					{
						HC.TournamentRestartMatch();
					}
				}
			}
		}
		else
		{
			if (Sender == b_PauseTournament)
			{
				if (HC != None && HC.bTournamentServer)
				{
					if (HC.PlayerReplicationInfo.bTournamentTeamCaptain || HC.PlayerReplicationInfo.bAdmin)
					{
						HC.TournamentRequestPauseTournament();
					}
				}
			}
			else
			{
				if (Sender == b_SwapTeams)
				{
					if (HC != None && HC.bTournamentServer)
					{
						if (HC.PlayerReplicationInfo.bTournamentTeamCaptain || HC.PlayerReplicationInfo.bAdmin)
						{
							HC.TournamentRequestSwapSides();
						}
					}
				}
			}
		}
	}
	*/
	return true;
}

void UAAGameMenu_TournamentServerInfo::Timer()
{
	/*
	Log("Restart TM Timer: " $ iAdminRestartTimer);
	if (--iAdminRestartTimer == 0)
	{
		SetTimer(0, False);
		b_StartMatch.DisableMe();
		HumanController(PlayerOwner()).TournamentRestartMatch();
		Return;
	}
	HumanController(PlayerOwner()).ConsoleCommand("admin message Tournament Restarting by Admin command in " $ iAdminRestartTimer $ " seconds.");
	b_StartMatch.Caption = "Cancel Restart In " $ iAdminRestartTimer;
	*/
}