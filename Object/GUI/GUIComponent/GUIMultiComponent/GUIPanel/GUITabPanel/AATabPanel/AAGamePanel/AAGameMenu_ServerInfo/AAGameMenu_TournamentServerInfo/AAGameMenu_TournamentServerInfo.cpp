// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAGamePanel/AAGameMenu_ServerInfo/AAGameMenu_TournamentServerInfo/AAGameMenu_TournamentServerInfo.h"

UAAGameMenu_TournamentServerInfo::UAAGameMenu_TournamentServerInfo()
{
	//i_Buttons = GUIImage'AGP_Interface.AAGameMenu_TournamentServerInfo.BG2';
	//l_TournamentRoundDelayTime = GUILabel'AGP_Interface.AAGameMenu_TournamentServerInfo.TournamentRoundDelayTimeLabel';
	//l_TournamentRequestDelayTime = GUILabel'AGP_Interface.AAGameMenu_TournamentServerInfo.TournamentRequestDelayTimeLabel';
	//l_TournamentWarmupDuration = GUILabel'AGP_Interface.AAGameMenu_TournamentServerInfo.TournamentWarmupDurationLabel';
	//l_TournamentSwapTime = GUILabel'AGP_Interface.AAGameMenu_TournamentServerInfo.TournamentSwapTimeLabel';
	//l_TournamentSwapLimit = GUILabel'AGP_Interface.AAGameMenu_TournamentServerInfo.TournamentSwapLimitLabel';
	//l_TournamentMercyRule = GUILabel'AGP_Interface.AAGameMenu_TournamentServerInfo.TournamentMercyRuleLabel';
	//l_TournamentOpenAllWeaponClassSlots = GUILabel'AGP_Interface.AAGameMenu_TournamentServerInfo.TournamentOpenAllWeaponClassSlotsLabel';
	//l_TournamentTeamCaptainsAllowed = GUILabel'AGP_Interface.AAGameMenu_TournamentServerInfo.TournamentTeamCaptainsAllowedLabel';
	//l_TournamentTeamPasswordsRequired = GUILabel'AGP_Interface.AAGameMenu_TournamentServerInfo.TournamentTeamPasswordsRequiredLabel';
	//l_TournamentTieSuddenDeath = GUILabel'AGP_Interface.AAGameMenu_TournamentServerInfo.TournamentTieSuddenDeathLabel';
	//l_TournamentEnableRandomTeamAssignments = GUILabel'AGP_Interface.AAGameMenu_TournamentServerInfo.TournamentEnableRandomTeamAssignmentsLabel';
	//l_TournamentShadowsAllowedLabel = GUILabel'AGP_Interface.AAGameMenu_TournamentServerInfo.TournamentShadowsAllowedLabel';
	//b_StartMatch = GUIButton'AGP_Interface.AAGameMenu_TournamentServerInfo.StartMatchButton';
	//b_PauseTournament = GUIButton'AGP_Interface.AAGameMenu_TournamentServerInfo.PauseTournamentButton';
	//b_SwapTeams = GUIButton'AGP_Interface.AAGameMenu_TournamentServerInfo.SwapTeamsButton';
	//b_DiscardRound = GUIButton'AGP_Interface.AAGameMenu_TournamentServerInfo.TossRoundButton';
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
	if (GRI == None)
	{
		Return False;
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