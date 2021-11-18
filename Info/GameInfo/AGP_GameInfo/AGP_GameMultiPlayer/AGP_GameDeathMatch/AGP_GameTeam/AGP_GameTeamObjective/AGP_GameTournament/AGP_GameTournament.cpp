// All the original content belonged to the US Army


#include "AGP_GameTournament.h"

AAGP_GameTournament::AAGP_GameTournament()
{

}
/*
void AAGP_GameTournament::PostBeginPlay()
{
	Super::PostBeginPlay();
		DebugLog(DEBUG_Tournament,"*** AGP_GameTournament.PostBeginPlay() *** ");
		DebugLog(DEBUG_Tournament,"Tournament Mode: " $ bTournamentMode);
		DebugLog(DEBUG_Tournament,"Team 0 password: " $ AccessControl.asTeamPasswords[0]);
		DebugLog(DEBUG_Tournament,"Team 1 password: " $ AccessControl.asTeamPasswords[1]);
		DebugLog(DEBUG_Tournament,"Team 0 Name is " $ asTournamentTeamName[0]);
		DebugLog(DEBUG_Tournament,"Team 1 Name is " $ asTournamentTeamName[1]);
		DebugLog(DEBUG_Tournament,"Tournament Swap Time: " $ iTournamentSwapTime);
		DebugLog(DEBUG_Tournament,"Tournament Swap Limit: " $ iTournamentSwapLimit);
		DebugLog(DEBUG_Tournament,"Game Team Captains Allowed" $ bTournamentTeamCaptainsAllowed);
		bCycleMaps=False;
		bAutoBalanceBetweenRounds=False;
		bNeverAutoBalance=True;
		bEnableROEKickTimer=False;
		bEnableROEKick=False;
		bEnableROEKickDeath=False;
		bPlayersBalanceTeams=False;
		bSpectateBodies=False;
		bKickIdlePlayersTimed=False;
		bKickIdleSpectators=False;
		bTournamentMode=True;
		bInPauseNow=False;
		iLastRoundSwappedOn=0;
		GameReplicationInfo.sTournamentState="Setup";
		iSwappingRound=0;
		iTournamentMaxRounds=RoundsPerMatch;
		iTournamentRoundTime=TimeLimit;
		aiTournamentTeamScores[0]=0;
		aiTournamentTeamScores[1]=0;
		if(asTournamentTeamName[0] == "")
		{
			asTournamentTeamName[0]="Home";
		}
		if(asTournamentTeamName[1] == "")
		{
			asTournamentTeamName[1]="Away";
		}
		TournamentAssignRandomTeams();
}
*/
void AAGP_GameTournament::TournamentSetRoundsPerMatch(int32 iNewRounds)
{
	/*
		iTournamentMaxRounds=iNewRounds;
	*/
}
void AAGP_GameTournament::TournamentSetRoundsTimeLimit(int32 iNewTimeLimit)
{
/*
	iTournamentRoundTime=iNewTimeLimit;
	TimeLimit=iNewTimeLimit;
*/
}
void AAGP_GameTournament::TournamentServerINISetTeamName(int32 iTeam, FString sTeamName)
{
/*
	asTournamentTeamName[iTeam]=sTeamName;
	SaveConfig();
*/
}
void AAGP_GameTournament::InitGameReplicationInfo()
{
	/*
		InitGameReplicationInfo();
		TournamentUpdateGameReplicationInfo();
	*/
}
void AAGP_GameTournament::TournamentUpdateGameReplicationInfo()
{
	/*
		GameReplicationInfo.sTournamentName=sTournamentName;
		GameReplicationInfo.sLeagueName=sLeagueName;
		GameReplicationInfo.asTournamentTeamName[0]=asTournamentTeamName[0];
		GameReplicationInfo.asTournamentTeamName[1]=asTournamentTeamName[1];
		TournamentResetMatchData();
	*/
}
void AAGP_GameTournament::TournamentResetMatchData()
{
	/*
		local int i;
		GameReplicationInfo.sTournamentResultsFileName=sTournamentResultsFileName;
		GameReplicationInfo.iTournamentRequestDelayTime=iTournamentRequestDelayTime;
		GameReplicationInfo.iTournamentRequestDelayTime=iTournamentRequestDelayTime;
		GameReplicationInfo.iTournamentRoundDelayTime=iTournamentRoundDelayTime;
		GameReplicationInfo.iTournamentWarmupDuration=iTournamentWarmupDuration;
		GameReplicationInfo.iTournamentSwapTime=iTournamentSwapTime;
		GameReplicationInfo.iTournamentSwapLimit=iTournamentSwapLimit;
		GameReplicationInfo.iTournamentPauseLimit=iTournamentPauseLimit;
		GameReplicationInfo.bTournamentMercyRule=bTournamentMercyRule;
		GameReplicationInfo.bTournamentOpenAllWeaponClassSlots=bTournamentOpenAllWeaponClassSlots;
		GameReplicationInfo.bTournamentTeamCaptainsAllowed=bTournamentTeamCaptainsAllowed;
		GameReplicationInfo.bTournamentTeamPasswordsRequired=bTournamentTeamPasswordsRequired;
		GameReplicationInfo.bTournamentTieSuddenDeath=bTournamentTieSuddenDeath;
		GameReplicationInfo.bTournamentTieScore=bTournamentTieScore;
		GameReplicationInfo.bTournamentEnableRandomTeamAssignments=bTournamentEnableRandomTeamAssignments;
		GameReplicationInfo.bTournamentWarmupJustEnded=False;
		GameReplicationInfo.bTournamentInWarmup=False;
		if(GameReplicationInfo.Teams[0] != None)
		{
			GameReplicationInfo.Teams[0].bTournamentTeamReady=False;
		}
		if(GameReplicationInfo.Teams[1] != None)
		{
			GameReplicationInfo.Teams[1].bTournamentTeamReady=False;
		}
		if(Len(AccessControl.asTeamPasswords[0]) > 1 || Len(AccessControl.asTeamPasswords[1]) > 1)
		{
			GameReplicationInfo.bTournamentTeamPasswordsRequired=True;
		}
		aiTournamentTeamScores[0]=0;
		aiTournamentTeamScores[1]=0;
		for(i=0; i<32; i++)
		{
			atpsTournamentPlayerStats[i].sTeamName="";
			atpsTournamentPlayerStats[i].iTeamIndex=0;
			atpsTournamentPlayerStats[i].sPlayerName="";
			atpsTournamentPlayerStats[i].iKills=0;
			atpsTournamentPlayerStats[i].iDeaths=0;
			atpsTournamentPlayerStats[i].iGoalPoints=0;
			atpsTournamentPlayerStats[i].iLeaderPoints=0;
			atpsTournamentPlayerStats[i].iTotalScore=0;
			atpsTournamentPlayerStats[i].iROE=0;
			atpsTournamentPlayerStats[i].iRoundsPlayed=0;
		}
		for(i=0; i<2; i++)
		{
			attrTournamentFinalResults[i].sTeamName="";
			attrTournamentFinalResults[i].iTotalScore=0;
			attrTournamentFinalResults[i].iTotalWins=0;
			attrTournamentFinalResults[i].iTotalLosses=0;
		}
		Log("Rounds per match: " $ iTournamentMaxRounds);
	*/
}
/*
APlayerController* AAGP_GameTournament:: Login(FString Portal, FString Options, FString Error)
{
	local PlayerController NewPlayer;
	local string InPassword;
	local int i;
	NewPlayer=Login(Portal,Options,Error);
	if(! GameReplicationInfo.bTournamentTeamPasswordsRequired)
	{
		Return NewPlayer;
	}
	if(AccessControl.asTeamPasswords[0] != "" && AccessControl.asTeamPasswords[1] != "" && AccessControl.asTeamPasswords[0] == AccessControl.asTeamPasswords[1])
	{
		Return NewPlayer;
	}
	InPassword=ParseOption(Options,"Password");
	i=0;
	if(i < 2)
	{
		if(InPassword != "" && InPassword == AccessControl.asTeamPasswords[i])
		{
			NewPlayer.PlayerReplicationInfo.DesiredTeam=i;
		}
		else
		{
			i ++;
		}
	}
	Return NewPlayer;
}
*/
void AAGP_GameTournament::Logout(AController* Exiting)
{
	/*
		Logout(Exiting);
		if(PlayerController(Exiting) != None && PlayerController(Exiting).PlayerReplicationInfo.Team != None)
		{
			if(PlayerController(Exiting).PlayerReplicationInfo.bAdmin)
			{
				GameReplicationInfo.Teams[PlayerController(Exiting).PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamCaptainSelected=False;
			}
			else
			{
				if(PlayerController(Exiting).PlayerReplicationInfo.bTournamentTeamCaptain)
				{
					GameReplicationInfo.Teams[PlayerController(Exiting).PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamCaptainSelected=False;
					GameReplicationInfo.Teams[PlayerController(Exiting).PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamRosterLocked=False;
				}
			}
		}
	*/
}
void AAGP_GameTournament::TournamentTeamHasPlayers(int32 iTeamIndex)
{
	/*
		local Controller C;
		C=Level.ControllerList;
		if(C != None)
		{
			if(C.IsA('PlayerController') && PlayerController(C).PlayerReplicationInfo.Team.TeamIndex == iTeamIndex)
			{
				Return True;
			}
			C=C.nextController;
		}
		Return False;
	*/
}
void AAGP_GameTournament::TournamentRequestResetMatch()
{
	/*
		local Controller C;
		if(! TournamentTeamHasPlayers(0) || ! TournamentTeamHasPlayers(1))
		{
			C=Level.ControllerList;
			if(C != None)
			{
				if(HumanController(C) != None && HumanController(C).bPBChecked && PlayerController(C).PlayerReplicationInfo.bAdmin)
				{
					HumanController(PlayerController(C)).NotifyAdminMessage("There are not enough players on both teams.");
				}
				C=C.nextController;
			}
			Return;
		}
		bTournamentRestartPending=True;
		TournamentResetMatchData();
		GameReplicationInfo.bTournamentWarmupJustEnded=True;
		GotoState('MatchOver');
	*/
}
void AAGP_GameTournament::TournamentRequestWarmup()
{
	/*
		local Controller C;
		if(iTournamentWarmupDuration == 0)
		{
			C=Level.ControllerList;
			if(C != None)
			{
				if(HumanController(C) != None && HumanController(C).bPBChecked && PlayerController(C).PlayerReplicationInfo.bTournamentTeamCaptain || PlayerController(C).PlayerReplicationInfo.bAdmin)
				{
					HumanController(PlayerController(C)).NotifyAdminMessage("The Mission Planning round was not enabled for this Tournament.");
				}
				C=C.nextController;
			}
			Return;
		}
		if(! TournamentTeamHasPlayers(0) || ! TournamentTeamHasPlayers(1))
		{
			C=Level.ControllerList;
			if(C != None)
			{
				if(HumanController(C) != None && HumanController(C).bPBChecked && PlayerController(C).PlayerReplicationInfo.bAdmin)
				{
					HumanController(PlayerController(C)).NotifyAdminMessage("There are not enough players on both teams.");
				}
				C=C.nextController;
			}
			Return;
		}
		bTournamentWarmupPending=True;
		TournamentRequestResetMatch();
	*/
}
void AAGP_GameTournament::TournamentPerformRestartMatch()
{
	/*
		local int iIndex;
		local Controller C;
		local PlayerController Player;
		local AGP_Viewpoint VP;
		local string sTeam0Password;
		bTournamentWarmupStarted=False;
		CompleteEndGame();
		VP=GetWinningViewpoint(None);
		C=Level.ControllerList;
		if(C != None)
		{
			if(HumanController(C) != None && HumanController(C).bPBChecked)
			{
				Player=PlayerController(C);
				Player.ClientSetBehindView(True);
				Player.SetViewTarget(VP);
				Player.ClientSetViewTarget(VP);
				Player.ClientGameEnded();
			}
			else
			{
			}
			if(HumanController(C).bPlayerIsReadyToPlay)
			{
				C.GotoState('GameEnded');
			}
			C=C.nextController;
		}
		TournamentResetTeamCaptainsReadyFlag();
		CleanupForMatchEnd();
		iTotalRoundsPlayed=0;
		iTotalRoundsTied=0;
		for(iIndex=0; iIndex<32; iIndex++)
		{
			asTournamentAdministrators[iIndex]="";
			asTournamentSpectators[iIndex]="";
		}
		for(iIndex=0; iIndex<32; iIndex++)
		{
			atpsTournamentPlayerStats[iIndex].sTeamName="";
			atpsTournamentPlayerStats[iIndex].sPlayerName="";
			atpsTournamentPlayerStats[iIndex].iKills=0;
			atpsTournamentPlayerStats[iIndex].iDeaths=0;
			atpsTournamentPlayerStats[iIndex].iGoalPoints=0;
			atpsTournamentPlayerStats[iIndex].iLeaderPoints=0;
			atpsTournamentPlayerStats[iIndex].iTotalScore=0;
			atpsTournamentPlayerStats[iIndex].iROE=0;
			atpsTournamentPlayerStats[iIndex].iRoundsPlayed=0;
		}
		for(iIndex=0; iIndex<2; iIndex++)
		{
			attrTournamentFinalResults[iIndex].sTeamName="";
			attrTournamentFinalResults[iIndex].iTotalScore=0;
			attrTournamentFinalResults[iIndex].iTotalWins=0;
			attrTournamentFinalResults[iIndex].iTotalLosses=0;
		}
		aiTournamentTeamScores[0]=0;
		aiTournamentTeamScores[1]=0;
		iLastRoundSwappedOn=0;
		GameReplicationInfo.asTournamentTeamName[0]=asTournamentTeamName[0];
		GameReplicationInfo.asTournamentTeamName[1]=asTournamentTeamName[1];
		if(bTeamsSwapped)
		{
			sTeam0Password=AccessControl.asTeamPasswords[0];
			AccessControl.asTeamPasswords[0]=AccessControl.asTeamPasswords[1];
			AccessControl.asTeamPasswords[1]=sTeam0Password;
			bTeamsSwapped=False;
		}
		ResetTMMatchScores();
		ResetRoundScores();
		ResetMatchesBeforeCycle();
		ResetDecoMeshes();
		FakeRestartGame();
		bCurrentRoundIsDead=False;
		bTournamentSwapPending=False;
		bTournamentPausePending=False;
		bTournamentRestartPending=False;
		iSwappingRound=0;
		iLastRoundSwappedOn=0;
		bTournamentSuddenDeath=False;
		if(bTournamentWarmupPending)
		{
			bTournamentWarmupPending=False;
			TournamentRequestStartWarmup();
		}
		else
		{
			TournamentRequestRestartMatch();
		}
	*/
}
void AAGP_GameTournament::TournamentGetTeam(uint8 Index)
{
	/*
		Return GetTeam(Index);
	*/
}
void AAGP_GameTournament::TournamentAreAllWeaponClassesAvailable()
{
	/*
		Return bTournamentOpenAllWeaponClassSlots;
	*/
}
void AAGP_GameTournament::TournamentEndedByMercyRule()
{
	/*
		Return bTournamentStatisticallyOver;
	*/
}
void AAGP_GameTournament::TournamentRequestResetTournament()
{
	/*
		RestartGame();
	*/
}
bool AAGP_GameTournament::TournamentIsTournament()
{
	return bTournamentMode;
}
void AAGP_GameTournament::TournamentJoinSpectatorTeam(APlayerController* PC, int32 iTeamIndex)
{
	/*
		if(PC != None && PC.PlayerReplicationInfo.Team.TeamIndex == iTeamIndex)
		{
			DebugLog(DEBUG_Tournament,"Player already a Spectator.");
			PC.PlayerReplicationInfo.DesiredTeam=iTeamIndex;
			Level.Game.RequestChangeTeam(PC,iTeamIndex);
			Return True;
		}
		if(IsInState('PendingMatch') || IsInState('TournamentComplete'))
		{
			if(PC != None && PC.PlayerReplicationInfo.bTournamentTeamCaptain)
			{
				PC.PlayerReplicationInfo.bTournamentTeamCaptain=False;
				GameReplicationInfo.Teams[PC.PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamCaptainSelected=False;
				GameReplicationInfo.Teams[PC.PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamRosterLocked=False;
			}
			PC.PlayerReplicationInfo.DesiredTeam=iTeamIndex;
			Level.Game.ChangeTeam(PC,iTeamIndex);
			Return True;
		}
		else
		{
			Return False;
		}
	*/
}
void AAGP_GameTournament::TournamentJoinTeam(APlayerController* PC, int32 iTeamIndex, FString sPassword)
{
	/*
		DebugLog(DEBUG_Tournament,"AGP_GameTournament::TournamentJoinTeam() entered for " $ iTeamIndex $ " Password: " $ sPassword $ " vs. " $ AccessControl.asTeamPasswords[iTeamIndex]);
		if(GameReplicationInfo.sTournamentState == "Complete")
		{
			HumanController(PC).TournamentCaptainAdminMessage("All players must leave the server to allow it to reset the tournament before you can join a team.");
			Return False;
		}
		if(PC != None && PC.PlayerReplicationInfo.Team.TeamIndex == iTeamIndex)
		{
			DebugLog(DEBUG_Tournament,"Player already on requested team");
			PC.PlayerReplicationInfo.DesiredTeam=iTeamIndex;
			Level.Game.RequestChangeTeam(PC,iTeamIndex);
			Return True;
		}
		if(! GameReplicationInfo.bTournamentTeamPasswordsRequired || GameReplicationInfo.bTournamentTeamPasswordsRequired && AccessControl.asTeamPasswords[iTeamIndex] == "" || AccessControl.asTeamPasswords[iTeamIndex] == sPassword)
		{
			DebugLog(DEBUG_Tournament,"TournamentJoinTeam() success");
			if(IsInState('PendingMatch') || IsInState('TournamentComplete') || PC.PlayerReplicationInfo.Team.TeamIndex == 255)
			{
				if(PC != None && PC.PlayerReplicationInfo.bTournamentTeamCaptain)
				{
					if(PC.PlayerReplicationInfo.bTournamentTeamCaptain && PC.IsA('HumanController'))
					{
						HumanController(PC).TournamentRequestTeamCaptain(PC.PlayerReplicationInfo);
					}
					GameReplicationInfo.Teams[PC.PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamCaptainSelected=False;
					GameReplicationInfo.Teams[PC.PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamRosterLocked=False;
				}
				PC.PlayerReplicationInfo.DesiredTeam=iTeamIndex;
				Level.Game.ChangeTeam(PC,iTeamIndex);
			}
			Return True;
		}
		else
		{
			DebugLog(DEBUG_Tournament,"TournamentJoinTeam() failed");
			Return False;
		}
	*/
}
void AAGP_GameTournament::TournamentGetTeamName(int32 iTeamIndex)
{
	/*
		Return asTournamentTeamName[iTeamIndex];
	*/
}
void AAGP_GameTournament::TournamentSetTeamName(int32 iTeamIndex, FString sTeamName)
{
	/*
		local Controller C;
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.TournamentSetTeamName() entered for " $ iTeamIndex $ " name: " $ sTeamName);
		if(iTeamIndex > 1 || iTeamIndex < 0)
		{
			Return;
		}
		asTournamentTeamName[iTeamIndex]=sTeamName;
		C=Level.ControllerList;
		if(C != None)
		{
			if(C.IsA('HumanController'))
			{
				HumanController(C).NotifyTournamentTeamNameUpdated(iTeamIndex,sTeamName);
			}
			C=C.nextController;
		}
	*/
}
void AAGP_GameTournament::TournamentAssignRandomTeams()
{
	/*
		local string sTeam0Name;
		local string sTeam0Password;
		if(! bTournamentEnableRandomTeamAssignments)
		{
			Return;
		}
		if(Rand(2) == 1)
		{
			DebugLog(DEBUG_Tournament,"AGP_GameTournament::TournamentAssignRandomTeams() - Swapped sides from INI settings");
			sTeam0Name=GameReplicationInfo.asTournamentTeamName[0];
			asTournamentTeamName[0]=asTournamentTeamName[1];
			GameReplicationInfo.asTournamentTeamName[0]=GameReplicationInfo.asTournamentTeamName[1];
			GameReplicationInfo.asTournamentTeamName[1]=sTeam0Name;
			asTournamentTeamName[1]=sTeam0Name;
			sTeam0Password=AccessControl.asTeamPasswords[0];
			AccessControl.asTeamPasswords[0]=AccessControl.asTeamPasswords[1];
			AccessControl.asTeamPasswords[1]=sTeam0Password;
			bTeamsSwapped=True;
		}
	*/
}
void AAGP_GameTournament::TournamentRequestSwapSides()
{
	/*
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.TournamentRequestSwapSides() - Requesting swapping of sides");
		if(GameReplicationInfo.RemainingRounds <= 1)
		{
			Return False;
		}
		bTournamentSwapPending=True;
		BroadcastHandler.Broadcast(Self,"Swapping sides at the end of this round.",'TMStatus');
		Return True;
	*/
}
void AAGP_GameTournament::TournamentChangeTeam(AController* ctrlrPlayer, int32 iTeamIndex)
{
	/*
		local TeamInfo NewTeam;
		if(iTeamIndex == 255 || MustBeSpecTeam(ctrlrPlayer))
		{
			NewTeam=SpecTeam;
		}
		else
		{
			if(iTeamIndex < 2)
			{
				NewTeam=Teams[PickTeam(iTeamIndex,ctrlrPlayer)];
			}
			else
			{
				DebugLog(DEBUG_Tournament,"AGP_GameTeam::ChangeTeam()	Requesting invalid team " $ iTeamIndex);
				Return False;
			}
		}
		DebugLog(DEBUG_Tournament,"AGP_GameTeam::ChangeTeam() " $ ctrlrPlayer $ " is trying to change to " $ iTeamIndex @ NewTeam);
		if(ctrlrPlayer.PlayerReplicationInfo.Team == NewTeam)
		{
			DebugLog(DEBUG_Tournament,"AGP_GameTeam::ChangeTeam() Already on team " $ NewTeam @ ctrlrPlayer @ ctrlrPlayer.PlayerReplicationInfo.PlayerName);
			Return False;
		}
		ctrlrPlayer.StartSpot=None;
		if(ctrlrPlayer.PlayerReplicationInfo.Team != None)
		{
			ctrlrPlayer.PlayerReplicationInfo.Team.RemoveFromTeam(ctrlrPlayer);
		}
		if(NewTeam.AddToTeam(ctrlrPlayer))
		{
			BroadcastLocalizedMessage(GameMessageClass,3,ctrlrPlayer.PlayerReplicationInfo,None,NewTeam);
		}
		Return True;
	*/
}
void AAGP_GameTournament::TournamentAssignClass(AAA2_PlayerState* PRI, int32 iUnitID, int32 iSlotIndex)
{
	/*
		AGP_TeamInfo(PRI.Team).TournamentSubmitPlayerRequest(PRI,iUnitID,iSlotIndex);
		PRI.bWaitingPlayer=False;
	*/
}
void AAGP_GameTournament::SwapSides()
{
	/*
		local Controller C;
		local int iTeam0Score;
		local string sTeam0Name;
		local string sTeam0Password;
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.SwapSides() - Entered");
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.SwapSides() - Current Team 0: " $ GameReplicationInfo.asTournamentTeamName[0] $ " Score: " $ GameReplicationInfo.Teams[0].Score $ " TeamScore: " $ GameReplicationInfo.Teams[0].teamScore);
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.SwapSides() - Current Team 1: " $ GameReplicationInfo.asTournamentTeamName[1] $ " Score: " $ GameReplicationInfo.Teams[1].Score $ " TeamScore: " $ GameReplicationInfo.Teams[1].teamScore);
		iTeam0Score=GameReplicationInfo.Teams[0].teamScore;
		sTeam0Name=GameReplicationInfo.asTournamentTeamName[0];
		GameReplicationInfo.asTournamentTeamName[0]=GameReplicationInfo.asTournamentTeamName[1];
		asTournamentTeamName[0]=asTournamentTeamName[1];
		GameReplicationInfo.asTournamentTeamName[1]=sTeam0Name;
		asTournamentTeamName[1]=sTeam0Name;
		sTeam0Password=AccessControl.asTeamPasswords[0];
		AccessControl.asTeamPasswords[0]=AccessControl.asTeamPasswords[1];
		AccessControl.asTeamPasswords[1]=sTeam0Password;
		bTeamsSwapped=! bTeamsSwapped;
		AGP_TeamInfo(GameReplicationInfo.Teams[0]).teamScore=AGP_TeamInfo(GameReplicationInfo.Teams[1]).teamScore;
		AGP_TeamInfo(GameReplicationInfo.Teams[0]).teamScore=AGP_TeamInfo(GameReplicationInfo.Teams[1]).teamScore;
		AGP_TeamInfo(GameReplicationInfo.Teams[1]).teamScore=iTeam0Score;
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.SwapSides() - After Swap Team 0: " $ GameReplicationInfo.asTournamentTeamName[0] $ " Score: " $ GameReplicationInfo.Teams[0].Score $ " TeamScore: " $ GameReplicationInfo.Teams[0].teamScore);
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.SwapSides() - After Swap Team 1: " $ GameReplicationInfo.asTournamentTeamName[1] $ " Score: " $ GameReplicationInfo.Teams[1].Score $ " TeamScore: " $ GameReplicationInfo.Teams[1].teamScore);
		C=Level.ControllerList;
		if(C != None)
		{
			if(HumanController(C) == None)
			{
			}
			if(HumanController(C) != None && ! HumanController(C).bPBChecked)
			{
			}
			DebugLog(DEBUG_Tournament,"AGP_GameTournament.SwapSides() - Player " $ C.PlayerReplicationInfo.PlayerName $ " on team index: " $ C.PlayerReplicationInfo.Team.TeamIndex);
			if(C.PlayerReplicationInfo.Team.TeamIndex == 0)
			{
				SwapPlayer(HumanController(C),0,1);
			}
			else
			{
				if(C.PlayerReplicationInfo.Team.TeamIndex == 1)
				{
					SwapPlayer(HumanController(C),1,0);
				}
				else
				{
					if(C.PlayerReplicationInfo.Team.TeamIndex == 255)
					{
						DebugLog(DEBUG_Tournament,"AGP_GameTournament.SwapPlayer() - Skipping spectator");
					}
				}
			}
			C=C.nextController;
		}
		bTournamentSwapPending=False;
		C=Level.ControllerList;
		if(C != None)
		{
			if(HumanController(C) != None && HumanController(C).bPBChecked)
			{
				DebugLog(DEBUG_Tournament,"AGP_GameTournament::SwapSides() - Team for player " $ C.PlayerReplicationInfo.PlayerName $ " is now: " $ GameReplicationInfo.asTournamentTeamName[C.PlayerReplicationInfo.Team.TeamIndex]);
				HumanController(C).ClientCloseMenu(False);
				HumanController(C).ClientOpenMenu("AGP_Interface.AAGameMenu",,"Roster");
			}
			C=C.nextController;
		}
		GotoState('SwappingSides');
	*/
}
void AAGP_GameTournament::SwapPlayer(AHumanController* HC, int32 iOldTeam, int32 iNewTeam)
{
	/*
		local int iPreSwapUnitID;
		local int iPreSwapUnitIndex;
		local int iPreSwapRealIndex;
		iPreSwapUnitID=AGP_TeamInfo(HC.PlayerReplicationInfo.Team).GetPlayerUnitID(HC.PlayerReplicationInfo);
		iPreSwapUnitIndex=AGP_TeamInfo(HC.PlayerReplicationInfo.Team).GetPlayerIndex(HC.PlayerReplicationInfo);
		DebugLog(DEBUG_Tournament,"Swapping " $ HC.PlayerReplicationInfo.PlayerName $ " from team index: " $ iOldTeam $ "(" $ GameReplicationInfo.asTournamentTeamName[iOldTeam] $ ") to team " $ iNewTeam $ "(" $ GameReplicationInfo.asTournamentTeamName[iNewTeam] $ ") ");
		DebugLog(DEBUG_Tournament,"SwapPlayer - Unit ID found: " $ iPreSwapUnitID $ " unit index: " $ iPreSwapUnitIndex);
		HC.PlayerReplicationInfo.DesiredTeam=iNewTeam;
		TournamentChangeTeam(HC,iNewTeam);
		AGP_TeamInfo(HC.PlayerReplicationInfo.Team).ClearPlayerRequests(HC.PlayerReplicationInfo);
		AGP_TeamInfo(HC.PlayerReplicationInfo.Team).AddToNoRequestList(HC.PlayerReplicationInfo,False);
		if(iPreSwapUnitID != -1)
		{
			iPreSwapRealIndex=AGP_TeamInfo(HC.PlayerReplicationInfo.Team).GetRealIndex(iPreSwapUnitID,iPreSwapUnitIndex);
			AGP_TeamInfo(HC.PlayerReplicationInfo.Team).AssignPlayerRequest(HC.PlayerReplicationInfo,iPreSwapRealIndex);
			AGP_TeamInfo(GameReplicationInfo.Teams[iNewTeam]).AssignPlayerRequest(HC.PlayerReplicationInfo,iPreSwapRealIndex);
		}
		HC.NotifyTournamentTeamNameUpdated(iNewTeam,GameReplicationInfo.asTournamentTeamName[iNewTeam]);
		DebugLog(DEBUG_Tournament,"Swapped player to desired team " $ HC.PlayerReplicationInfo.DesiredTeam);
	*/
}
void AAGP_GameTournament::TournamentResumeFromPause()
{
	/*
		bEndPauseNow=True;
	*/
}
void AAGP_GameTournament::TournamentRequestPauseTournament()
{
	/*
		bTournamentPausePending=True;
		BroadcastHandler.Broadcast(Self,"The tournament will pause at the end of this round.",'TMStatus');
	*/
}
void AAGP_GameTournament::TournamentPause()
{
	/*
		local Controller C;
		bTournamentSwapPending=False;
		bTournamentPausePending=False;
		bTournamentRestartPending=False;
		bTournamentWarmupPending=False;
		GotoState('TournamentPaused');
		C=Level.ControllerList;
		if(C != None)
		{
			if(HumanController(C) != None && HumanController(C).bPBChecked)
			{
				HumanController(PlayerController(C)).NotifyAdminMessage("The tournament has been paused by request of the team captains or the administrator.");
			}
			C=C.nextController;
		}
	*/
}
void AAGP_GameTournament::TournamentResume()
{
	/*
		DebugLog(DEBUG_Tournament,"AGP_Gameplay.TournamentResume() - initiating resumption of tournament");
		GameReplicationInfo.TournamentCountDownTime=10;
		bTournamentPausePending=False;
	*/
}
void AAGP_GameTournament::TournamentResetTeamCaptainsReadyFlag()
{
	/*
		local Controller C;
		local PlayerController Player;
		C=Level.ControllerList;
		if(C != None)
		{
			if(C.IsA('PlayerController'))
			{
				Player=PlayerController(C);
				if(Player != None)
				{
					Player.PlayerReplicationInfo.Team.bTournamentTeamReady=False;
					Player.PlayerReplicationInfo.Team.bTournamentRequestDeadRound=False;
					Player.PlayerReplicationInfo.bTournamentRestartTournamentRequest=False;
					Player.PlayerReplicationInfo.bTournamentRestartRequest=False;
					Player.PlayerReplicationInfo.bTournamentStartRequest=False;
					Player.PlayerReplicationInfo.bTournamentWarmupRequest=False;
					Player.PlayerReplicationInfo.bTournamentTeamSwapRequest=False;
					Player.PlayerReplicationInfo.bTournamentMatchPauseRequest=False;
				}
			}
			C=C.nextController;
		}
	*/
}
void AAGP_GameTournament::TournamentSwapTeamCaptainSelectedFlag()
{
	/*
		local bool bTempFlag;
		local AGP_TeamInfo Team_1;
		local AGP_TeamInfo Team_2;
		Team_1=AGP_TeamInfo(GameReplicationInfo.Teams[0]);
		Team_2=AGP_TeamInfo(GameReplicationInfo.Teams[1]);
		if(Team_1 == None || Team_2 == None)
		{
			Log("Warning: Teams do not exist!");
			Return;
		}
		else
		{
			bTempFlag=Team_1.bTournamentTeamCaptainSelected;
			Team_1.bTournamentTeamCaptainSelected=Team_2.bTournamentTeamCaptainSelected;
			Team_2.bTournamentTeamCaptainSelected=bTempFlag;
		}
	*/
}
void AAGP_GameTournament::TournamentRequestStartMatch()
{
	/*
		GameReplicationInfo.bTournamentInProgress=False;
		GotoState('StartMatchCountdown');
	*/
}
void AAGP_GameTournament::TournamentRequestRestartMatch()
{
	/*
		GotoState('StartMatchCountdown');
	*/
}
void AAGP_GameTournament::TournamentRequestStartWarmup()
{
	/*
		local Controller C;
		if(! TournamentTeamHasPlayers(0) || ! TournamentTeamHasPlayers(1))
		{
			DebugLog(DEBUG_Tournament,"AGP_GameTournament::TournamentRequestStartWarmup() - No players found");
			C=Level.ControllerList;
			if(C != None)
			{
				if(HumanController(C) != None && HumanController(C).bPBChecked && PlayerController(C).PlayerReplicationInfo.bAdmin)
				{
					HumanController(PlayerController(C)).NotifyAdminMessage("There are not enough players on both teams.");
				}
				C=C.nextController;
			}
			Return;
		}
		bPlayersMustBeReady=False;
		bWaitForNetPlayers=False;
		GotoState('WarmupCountdown');
	*/
}
void AAGP_GameTournament::TournamentIsWarmup()
{
	/*
		Return bTournamentWarmupStarted;
	*/
}
void AAGP_GameTournament::CheckEndGame(AAA2_PlayerState* Winner, FString Reason)
{
	/*
		local Controller C;
		local PlayerController Player;
		local AGP_Viewpoint VP;
		local Vehicle V;
		local Pawn PlayerPawn;
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.CheckEndGame() entered");
		EndTime=GetWorld()->GetTimeSeconds() + 3;
		if(Winner != None)
		{
			GameReplicationInfo.Winner=Winner;
		}
		VP=GetWinningViewpoint(Winner);
		C=Level.ControllerList;
		if(C != None)
		{
			if(HumanController(C) != None && HumanController(C).bPBChecked && HumanController(C).bPlayerIsReadyToPlay)
			{
				Player=PlayerController(C);
				PlayerPawn=Player.Pawn;
				V=Vehicle(PlayerPawn);
				if(V != None)
				{
					Player.Pawn=V.Driver;
					V.Driver=None;
					V.Controller=None;
					Player.Pawn.SetBase(None);
					Player.AcknowledgedPawn=Player.Pawn;
				}
				Player.ClientSetBehindView(True);
				Player.SetViewTarget(VP);
				Player.ClientSetViewTarget(VP);
				if(bTournamentWarmupStarted)
				{
					HumanController(Player).TournamentWarmupClientGameEnded();
				}
				else
				{
					Player.ClientGameEnded();
				}
			}
			if(! bTournamentWarmupStarted)
			{
				if(HumanController(C) != None && HumanController(C).bPlayerIsReadyToPlay)
				{
					C.GotoState('GameEnded');
				}
			}
			C=C.nextController;
		}
		CleanupForMatchEnd();
		Return True;
	*/
}
void AAGP_GameTournament::ShouldIgnoreStats()
{
	/*
		Return bCurrentRoundIsDead;
	*/
}
void AAGP_GameTournament::AddAllPlayersToStatsInfo()
{
}
void AAGP_GameTournament::ResetTMMatchScores()
{
	/*
		local Controller C;
		local PlayerReplicationInfo PRI;
		C=Level.ControllerList;
		if(C != None)
		{
			PRI=C.PlayerReplicationInfo;
			if(PRI == None)
			{
			}
			PRI._cumRounds=0;
			PRI._LastTimeUpdate=GetWorld()->GetTimeSeconds();
			PRI.Score_Total=0;
			PRI.Score_Leadership=0;
			PRI.Score_Wins=0;
			PRI.Score_Objectives=0;
			PRI.Score_Deaths=0;
			PRI.Score_Kills=0;
			PRI.Score_ROE=0;
			PRI.votekick="";
			C=C.nextController;
		}
		ResetRemainingRounds();
	*/
}
void AAGP_GameTournament::StartMatch()
{
	/*
		local Controller C;
		bWaitingToStartMatch=True;
		StartMatch();
		if(bCurrentRoundIsDead || bTournamentWarmupStarted)
		{
			GameReplicationInfo.sTournamentState="Mission Planning";
			DisableObjectivesForMissionPlanning();
		}
		C=Level.ControllerList;
		if(C != None)
		{
			if(HumanController(C) != None && HumanController(C).bPBChecked)
			{
				PlayerController(C).bSuperGodMode=bCurrentRoundIsDead || bTournamentWarmupStarted;
				PlayerController(C).bGodMode=PlayerController(C).bSuperGodMode;
			}
			C=C.nextController;
		}
	*/
}
void AAGP_GameTournament::TournamentAddNameToAdministratorList(FString sPlayerName)
{
	/*
		local int iPlayerIndex;
		local int iFirstBlank;
		iFirstBlank=-1;
		for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
		{
			if(Len(asTournamentAdministrators[iPlayerIndex]) == 0 && iFirstBlank == -1)
			{
				iFirstBlank=iPlayerIndex;
			}
			if(asTournamentAdministrators[iPlayerIndex] == sPlayerName)
			{
				Return;
			}
		}
		if(iFirstBlank == -1)
		{
			Return;
		}
		asTournamentAdministrators[iFirstBlank]=sPlayerName;
	*/
}
void AAGP_GameTournament::TournamentAddNameToSpectatorList(FString sPlayerName)
{
	/*
		local int iPlayerIndex;
		local int iFirstBlank;
		iFirstBlank=-1;
		for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
		{
			if(Len(asTournamentSpectators[iPlayerIndex]) == 0 && iFirstBlank == -1)
			{
				iFirstBlank=iPlayerIndex;
			}
			if(asTournamentSpectators[iPlayerIndex] == sPlayerName)
			{
				Return;
			}
		}
		if(iFirstBlank == -1)
		{
			Return;
		}
		asTournamentSpectators[iFirstBlank]=sPlayerName;
	*/
}
void AAGP_GameTournament::NotifyRoundOver()
{
	/*
		local Controller C;
		local string sTournamentStatusMsg;
		if(bCurrentRoundIsDead)
		{
			GameReplicationInfo.sTournamentState="Live Play";
			TournamentSendMessage("The round did not count because the Team Captains, Admin, or server rules discarded it as a ""Non-Scoring Round"".");
			Log("Current round count: " $ GameReplicationInfo.RemainingRounds);
			C=Level.ControllerList;
			if(C != None)
			{
				if(HumanController(C) != None && HumanController(C).bPBChecked)
				{
					PlayerController(C).bSuperGodMode=False;
					PlayerController(C).bGodMode=False;
				}
				C=C.nextController;
			}
			TimeLimit=iTournamentRoundTime;
			GameReplicationInfo.TimeLimit=TimeLimit;
			Return;
		}
		if(bTournamentWarmupStarted)
		{
			C=Level.ControllerList;
			if(C != None)
			{
				if(HumanController(C) != None && HumanController(C).bPBChecked)
				{
					PlayerController(C).bSuperGodMode=False;
					PlayerController(C).bGodMode=False;
				}
				C=C.nextController;
			}
			RoundsPerMatch=iTournamentMaxRounds;
			GameReplicationInfo.RemainingRounds=RoundsPerMatch;
			TimeLimit=iTournamentRoundTime;
			GameReplicationInfo.TimeLimit=TimeLimit;
			GameReplicationInfo.RoundsPerMatch=RoundsPerMatch;
			ResetTMMatchScores();
			ResetRoundScores();
			bFirstRunAfterWarmup=True;
			GameReplicationInfo.bTournamentWarmupJustEnded=bFirstRunAfterWarmup;
		}
		else
		{
			C=Level.ControllerList;
			if(C != None)
			{
				if(HumanController(C) != None && HumanController(C).bPBChecked)
				{
					TournamentUpdatePlayerStats(PlayerController(C));
				}
				C=C.nextController;
			}
			DebugLog(DEBUG_Tournament,"AGP_GameTournament.NotifyRoundOver() processing for non-warmup tournament round");
			if(WholeMatchOver())
			{
				GotoState('TournamentComplete');
			}
			else
			{
				ResetRoundScores();
				if(GameReplicationInfo.bTournamentInProgress)
				{
					if(GameReplicationInfo.Teams[0].teamScore > GameReplicationInfo.Teams[1].teamScore)
					{
						sTournamentStatusMsg=GameReplicationInfo.asTournamentTeamName[0] $ " team leads the tournament " $ GameReplicationInfo.Teams[0].teamScore $ " to " $ GameReplicationInfo.Teams[1].teamScore $ ".";
					}
					else
					{
						if(GameReplicationInfo.Teams[0].teamScore == GameReplicationInfo.Teams[1].teamScore)
						{
							sTournamentStatusMsg="The tournament is currently tied.";
						}
						else
						{
							sTournamentStatusMsg=GameReplicationInfo.asTournamentTeamName[1] $ " team leads the tournament " $ GameReplicationInfo.Teams[1].teamScore $ " to " $ GameReplicationInfo.Teams[0].teamScore $ ".";
						}
					}
					TournamentSendMessage(sTournamentStatusMsg);
				}
			}
		}
	*/
}
void AAGP_GameTournament::TournamentTransmitResultsToAuthServer()
{
	/*
		local DBAuth.UpdateTournamentResultsRequestAdapter Adapter;
		local string sAdminList;
		local int iPlayerIndex;
		local string ServerIP;
		DebugLog(DEBUG_Auth,"AGP_GameTournament::TournamentTransmitResultsToAuthServer() - Initiating tournament results transmission...");
		for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
		{
			if(Len(asTournamentAdministrators[iPlayerIndex]) > 0)
			{
				sAdminList=sAdminList $ asTournamentAdministrators[iPlayerIndex] $ ";";
			}
		}
		DebugLog(DEBUG_Auth,"AGP_GameTournament::TournamentTransmitResultsToAuthServer() - Initiating tournament results transmission part 2");
		Adapter=Spawn(Class'UpdateTournamentResultsRequestAdapter',Self);
		for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
		{
			if(Len(atpsTournamentPlayerStats[iPlayerIndex].sPlayerName) > 0)
			{
				Adapter.AddPlayer(atpsTournamentPlayerStats[iPlayerIndex].sPlayerName,atpsTournamentPlayerStats[iPlayerIndex].iTeamIndex,atpsTournamentPlayerStats[iPlayerIndex].iTotalScore);
			}
		}
		DebugLog(DEBUG_Auth,"AGP_GameTournament::TournamentTransmitResultsToAuthServer() - Players added");
		if(Class'DBAuth'.Default.GameServerIP != "")
		{
			ServerIP=Class'DBAuth'.Default.GameServerIP;
		}
		else
		{
			ServerIP=Class'InternetLink'.GetLocalIPAsString();
		}
		Adapter.Request(sLeagueName,sTournamentName,sMatchName,attrTournamentFinalResults[0].sTeamName,attrTournamentFinalResults[1].sTeamName,attrTournamentFinalResults[0].iTotalWins,attrTournamentFinalResults[1].iTotalWins,attrTournamentFinalResults[0].iTotalScore,attrTournamentFinalResults[1].iTotalScore,GameReplicationInfo.ServerName,Level.GetLevelName(),sAdminList,iTournamentMaxRounds,iTotalRoundsPlayed,iTournamentRoundTime,ServerIP);
		DebugLog(DEBUG_Auth,"AGP_GameTournament::TournamentTransmitResultsToAuthServer() - Sent to Auth Server");
	*/
}
void AAGP_GameTournament::TournamentResultsAuthCallback(int32 iResultCode)
{
	//DebugLog(DEBUG_Auth,"AGP_GameTournament::TournamentResultsAuthCallback() - Result: " $ iResultCode);
}
void AAGP_GameTournament::TournamentGetConnectedPlayerCount()
{
	/*
		local Controller C;
		local int iPlayersStillConnected;
		iPlayersStillConnected=0;
		C=Level.ControllerList;
		if(C != None)
		{
			if(C.IsA('HumanController') && HumanController(C).bPBChecked)
			{
				iPlayersStillConnected ++;
			}
			C=C.nextController;
		}
		Return iPlayersStillConnected;
	*/
}
void AAGP_GameTournament::TournamentGetConnectedTeam(int32 iTeamIndex)
{
	/*
		local Controller C;
		local int iPlayersStillConnected;
		iPlayersStillConnected=0;
		C=Level.ControllerList;
		if(C != None)
		{
			if(PlayerController(C) != None)
			{
				if(PlayerController(C).PlayerReplicationInfo.Team.TeamIndex == iTeamIndex)
				{
					iPlayersStillConnected ++;
					DebugLog(DEBUG_Tournament,"AGP_GAmeTournament.TournamentGetConnectedTeam(" $ iTeamIndex $ ") players found so far: " $ iPlayersStillConnected);
				}
			}
			C=C.nextController;
		}
		Return iPlayersStillConnected;
	*/
}
void AAGP_GameTournament::ShowCountDown(int32 iTimerLeft, FString sTimerType)
{
	/*
		local string TournamentTimeMessage;
		local int TournamentTimeCounter;
		local int TournamentTimeMinutes;
		local int TournamentTimeSeconds;
		local Controller C;
		TournamentTimeCounter=iTimerLeft;
		TournamentTimeMinutes=TournamentTimeCounter / 60;
		TournamentTimeSeconds=TournamentTimeCounter % 60;
		if(TournamentTimeCounter >= 0)
		{
			if(TournamentTimeMinutes >= 1 && TournamentTimeSeconds == 30 || TournamentTimeSeconds == 0)
			{
				if(TournamentTimeSeconds == 30)
				{
					if(TournamentTimeMinutes == 1)
					{
						TournamentTimeMessage=TournamentTimeMinutes $ " minute " $ TournamentTimeSeconds $ " seconds until " $ sTimerType $ ".";
					}
					else
					{
						TournamentTimeMessage=TournamentTimeMinutes $ " minutes " $ TournamentTimeSeconds $ " seconds until " $ sTimerType $ ".";
					}
				}
				else
				{
					if(TournamentTimeSeconds == 0)
					{
						if(TournamentTimeMinutes == 1)
						{
							TournamentTimeMessage="one minute until " $ sTimerType $ ".";
						}
						else
						{
							TournamentTimeMessage=TournamentTimeMinutes $ " minutes until " $ sTimerType $ ".";
						}
					}
				}
			}
			else
			{
				if(TournamentTimeSeconds == 30 && TournamentTimeMinutes < 1)
				{
					TournamentTimeMessage=TournamentTimeSeconds $ " seconds until " $ sTimerType $ ".";
				}
				else
				{
					if(TournamentTimeSeconds <= 15 && TournamentTimeSeconds > 0 && TournamentTimeMinutes < 1)
					{
						TournamentTimeMessage="" $ sTimerType $ " in: " $ TournamentTimeSeconds;
					}
					else
					{
						if(TournamentTimeSeconds == 0 && TournamentTimeMinutes < 1)
						{
							TournamentTimeMessage=sTimerType;
						}
					}
				}
			}
			if(TournamentTimeMessage != "")
			{
				C=Level.ControllerList;
				if(C != None)
				{
					if(HumanController(C) != None && HumanController(C).bPBChecked)
					{
						HumanController(C).NotifyAdminMessage(TournamentTimeMessage);
					}
					C=C.nextController;
				}
			}
		}
	*/
}
void AAGP_GameTournament::PendingEndGame(AAA2_PlayerState* Winner, FString Reason, int32 _EndTime)
{
	/*
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.PendingEndGame() - Reason: " $ Reason);
		if(bFirstRunAfterWarmup || bTournamentWarmupStarted)
		{
			Reason="EndWarmup";
		}
		PendingEndGame(Winner,Reason,_EndTime);
	*/
}
void AAGP_GameTournament::EndGame(AAA2_PlayerState* Winner, FString Reason)
{
	/*
		local Controller C;
		local PlayerController Player;
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.EndGame() entered for reason: " $ Reason);
		TournamentResetTeamCaptainsReadyFlag();
		if(bCurrentRoundIsDead)
		{
			bGameEnded=True;
			TriggerEvent('EndGame',Self,None);
			EndLogging(Reason);
			C=Level.ControllerList;
			if(C != None)
			{
				if(HumanController(C) != None && HumanController(C).bPBChecked)
				{
					Player=PlayerController(C);
					Player.ClientSetBehindView(True);
					Player.SetViewTarget(Level.ViewpointList);
					Player.ClientSetViewTarget(Level.ViewpointList);
					HumanController(Player).TournamentWarmupClientGameEnded();
				}
				C=C.nextController;
			}
			GotoState('MatchOver');
			Return;
		}
		if(bTournamentWarmupStarted)
		{
			TournamentSendMessage("The tournament begins at the start of the next game.");
		}
		else
		{
			iTotalRoundsPlayed ++;
			EndGame(Winner,Reason);
		}
		bGameEnded=True;
		TriggerEvent('EndGame',Self,None);
		EndLogging(Reason);
		if(bTournamentSwapPending)
		{
			DebugLog(DEBUG_Tournament,"AGP_GameTournament::EndGame() Swapping sides now");
			SwapSides();
			Return;
		}
		if(! CheckEndGame(Winner,Reason))
		{
			bOverTime=True;
			Return;
		}
		if(bTournamentPausePending)
		{
			bGameEnded=False;
			DebugLog(DEBUG_Tournament,"AGP_GameTournament::EndGame() Pausing tournament");
			TournamentPause();
			Return;
		}
		GotoState('MatchOver');
	*/
}
void AAGP_GameTournament::GiveCredit_Wins()
{
	/*
		if(bTournamentWarmupStarted)
		{
			Return False;
		}
		else
		{
			Return True;
		}
	*/
}
void AAGP_GameTournament::NotifyIdlePlayerRounds(AController* C, int32 nIdleRounds, bool bMessage)
{
}
void AAGP_GameTournament::WholeMatchOver()
{
	/*
		local bool bResult;
		local int iWinDelta;
		if(TournamentGetConnectedTeam(0) == 0 && TournamentGetConnectedTeam(1) == 0)
		{
			DebugLog(DEBUG_Tournament,"AGP_GameTournament.WholeMatchOver() - Both teams left");
			sWinningTeamName="";
			sWinningReason=" because both teams quit";
			GameReplicationInfo.Teams[0].teamScore=0;
			GameReplicationInfo.Teams[1].teamScore=0;
			aiTournamentTeamScores[0]=0;
			aiTournamentTeamScores[1]=0;
			Return True;
		}
		else
		{
			if(TournamentGetConnectedTeam(0) == 0)
			{
				DebugLog(DEBUG_Tournament,"AGP_GameTournament.WholeMatchOver() - Team 0 left");
				GameReplicationInfo.Teams[0].teamScore=0;
				GameReplicationInfo.Teams[1].teamScore=1;
				aiTournamentTeamScores[0]=0;
				aiTournamentTeamScores[1]=0;
				sWinningTeamName=GameReplicationInfo.asTournamentTeamName[1];
				sWinningReason=" by forfeit";
				Return True;
			}
			if(TournamentGetConnectedTeam(1) == 0)
			{
				DebugLog(DEBUG_Tournament,"AGP_GameTournament.WholeMatchOver() - Team 1 left");
				GameReplicationInfo.Teams[0].teamScore=1;
				GameReplicationInfo.Teams[1].teamScore=0;
				aiTournamentTeamScores[0]=0;
				aiTournamentTeamScores[1]=0;
				sWinningTeamName=GameReplicationInfo.asTournamentTeamName[0];
				sWinningReason=" by forfeit";
				Return True;
			}
		}
		if(GameReplicationInfo.Teams[0].teamScore > GameReplicationInfo.Teams[1].teamScore)
		{
			iWinDelta=GameReplicationInfo.Teams[0].teamScore - GameReplicationInfo.Teams[1].teamScore;
		}
		else
		{
			iWinDelta=GameReplicationInfo.Teams[1].teamScore - GameReplicationInfo.Teams[0].teamScore;
		}
		if(iWinDelta > GameReplicationInfo.RemainingRounds && bTournamentMercyRule)
		{
			bTournamentStatisticallyOver=True;
			bResult=True;
		}
		else
		{
			bResult=WholeMatchOver();
		}
		if(bResult)
		{
			DebugLog(DEBUG_Tournament,"AGP_GameTournament.WholeMatchOver() - Scores: " $ GameReplicationInfo.Teams[0].teamScore $ " and " $ GameReplicationInfo.Teams[1].teamScore);
			if(GameReplicationInfo.Teams[0].teamScore == GameReplicationInfo.Teams[1].teamScore)
			{
				if(! bTournamentTieSuddenDeath && ! bTournamentTieScore)
				{
					sWinningTeamName="";
					sWinningReason="";
					aiTournamentTeamScores[0]=AGP_TeamInfo(GameReplicationInfo.Teams[0]).GetTotalScore();
					aiTournamentTeamScores[1]=AGP_TeamInfo(GameReplicationInfo.Teams[1]).GetTotalScore();
					Return True;
				}
				else
				{
					if(bTournamentTieScore)
					{
						aiTournamentTeamScores[0]=AGP_TeamInfo(GameReplicationInfo.Teams[0]).GetTotalScore();
						aiTournamentTeamScores[1]=AGP_TeamInfo(GameReplicationInfo.Teams[1]).GetTotalScore();
						if(aiTournamentTeamScores[0] != aiTournamentTeamScores[1])
						{
							if(aiTournamentTeamScores[0] > aiTournamentTeamScores[1])
							{
								sWinningTeamName=GameReplicationInfo.asTournamentTeamName[0];
								sWinningReason="(score broke tie)";
							}
							else
							{
								sWinningTeamName=GameReplicationInfo.asTournamentTeamName[1];
								sWinningReason="(score broke tie)";
							}
							Return True;
						}
						else
						{
							sWinningTeamName="";
							sWinningReason="(total team scores were tied)";
							Return True;
						}
					}
					RoundsPerMatch ++;
					GameReplicationInfo.RoundsPerMatch ++;
					GameReplicationInfo.RemainingRounds ++;
					bTournamentSwapPending=True;
					iLastRoundSwappedOn=-1;
					DebugLog(DEBUG_Tournament,"AGP_GameTournament::WholeMatchOver() - Going to sudden death");
					bTournamentSuddenDeath=True;
					Return False;
				}
			}
			else
			{
				aiTournamentTeamScores[0]=AGP_TeamInfo(GameReplicationInfo.Teams[0]).GetTotalScore();
				aiTournamentTeamScores[1]=AGP_TeamInfo(GameReplicationInfo.Teams[1]).GetTotalScore();
				if(GameReplicationInfo.Teams[0].teamScore > GameReplicationInfo.Teams[1].teamScore)
				{
					sWinningTeamName=GameReplicationInfo.asTournamentTeamName[0];
				}
				else
				{
					sWinningTeamName=GameReplicationInfo.asTournamentTeamName[1];
				}
			}
		}
		Return bResult;
	*/
}
void AAGP_GameTournament::TournamentSendMessage(FString S)
{
	/*
		BroadcastHandler.Broadcast(Self,S,'TMStatus');
		TournamentSendCenteredMessage(S);
	*/
}
void AAGP_GameTournament::TournamentSendCenteredMessage(FString sMsg)
{
	/*
		local Controller C;
		C=Level.ControllerList;
		if(C != None)
		{
			if(HumanController(C) != None && HumanController(C).bPBChecked)
			{
				HumanController(C).NotifyAdminMessage(sMsg);
			}
			C=C.nextController;
		}
	*/
}
void AAGP_GameTournament::TournamentSendTeamCaptainOnlyMessage(FString sMsg)
{
	/*
		local Controller C;
		C=Level.ControllerList;
		if(C != None)
		{
			if(HumanController(C) != None && HumanController(C).bPBChecked)
			{
				if(C.PlayerReplicationInfo.bTournamentTeamCaptain || C.PlayerReplicationInfo.Administrator())
				{
					HumanController(C).TournamentCaptainAdminMessage(sMsg);
				}
			}
			C=C.nextController;
		}
	*/
}
void AAGP_GameTournament::TournamentSendNonTeamCaptainMessages(FString sMsg)
{
	/*
		local Controller C;
		C=Level.ControllerList;
		if(C != None)
		{
			if(HumanController(C) != None && HumanController(C).bPBChecked)
			{
				if(! C.PlayerReplicationInfo.bTournamentTeamCaptain && ! C.PlayerReplicationInfo.Administrator())
				{
					HumanController(C).NotifyAdminMessage(sMsg);
				}
			}
			C=C.nextController;
		}
	*/
}
void AAGP_GameTournament::TournamentGetMaxTeamSize()
{
	/*
		Return MaxTeamSize;
	*/
}
void AAGP_GameTournament::TournamentStatHelperFindPlayerIndex(APlayerController* PC)
{
	/*
		local int iPlayerIndex;
		for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
		{
			if(PC.PlayerReplicationInfo.PlayerName == atpsTournamentPlayerStats[iPlayerIndex].sPlayerName)
			{
				Return iPlayerIndex;
			}
		}
		Return -1;
	*/
}
void AAGP_GameTournament::TournamentUpdatePlayerStats(APlayerController* PC)
{
	/*
		local int iPlayerIndex;
		if(PC.PlayerReplicationInfo.Team.TeamIndex == 255)
		{
			Return;
		}
		iPlayerIndex=TournamentStatHelperFindPlayerIndex(PC);
		if(iPlayerIndex == -1)
		{
			for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
			{
				if(Len(atpsTournamentPlayerStats[iPlayerIndex].sPlayerName) == 0)
				{
				}
			}
			if(iPlayerIndex == 32)
			{
				Return;
			}
		}
		atpsTournamentPlayerStats[iPlayerIndex].sTeamName=GameReplicationInfo.asTournamentTeamName[PC.PlayerReplicationInfo.Team.TeamIndex];
		atpsTournamentPlayerStats[iPlayerIndex].sPlayerName=PC.PlayerReplicationInfo.PlayerName;
		atpsTournamentPlayerStats[iPlayerIndex].iTeamIndex=PC.PlayerReplicationInfo.Team.TeamIndex;
		atpsTournamentPlayerStats[iPlayerIndex].iKills=PC.PlayerReplicationInfo.Score_Kills;
		atpsTournamentPlayerStats[iPlayerIndex].iDeaths=PC.PlayerReplicationInfo.Score_Deaths;
		atpsTournamentPlayerStats[iPlayerIndex].iGoalPoints=PC.PlayerReplicationInfo.Score_Objectives;
		atpsTournamentPlayerStats[iPlayerIndex].iTotalScore=PC.PlayerReplicationInfo.Score_Total;
		atpsTournamentPlayerStats[iPlayerIndex].iROE=PC.PlayerReplicationInfo.Score_ROE;
		atpsTournamentPlayerStats[iPlayerIndex].iRoundsPlayed ++;
	*/
}
void AAGP_GameTournament::TournamentGenerateResults(AHumanController* HC, FString sBaseFileName)
{
	/*
		local string sResults;
		local string sPlayerInfo;
		local string sTieRules;
		local int iTeamIndex;
		local int iPlayerIndex;
		local string sPath;
		local string Message;
		iTotalRoundsTied=GameReplicationInfo.RoundsPerMatch - GameReplicationInfo.Teams[0].teamScore + GameReplicationInfo.Teams[1].teamScore;
		if(HC == None)
		{
			sPath=GetBaseDir() $ "\TournamentResults\";
			CreateDir(sPath);
			DebugLog(DEBUG_Tournament,"AGP_GameTournament::TournamentGenerateResults() - Creating tournament results file " $ sBaseFileName);
			if(! FOpenWrite(sPath $ sBaseFileName))
			{
				Return;
			}
		}
		else
		{
			if(iTotalRoundsPlayed != GameReplicationInfo.RoundsPerMatch && TournamentEndedByMercyRule())
			{
				Message="(ENDEX)";
				HC.TournamentOpenResultsFile(sBaseFileName,Message);
			}
			else
			{
				HC.TournamentOpenResultsFile(sBaseFileName);
			}
		}
		TournamentUpdateTeamResults(0);
		TournamentUpdateTeamResults(1);
		TournamentWriteResults(HC,Chr(13) $ Chr(10) $ "[Statistics]" $ Chr(13) $ Chr(10));
		if(Len(sWinningTeamName) > 0)
		{
			TournamentWriteResults(HC,"OverallWinner=" $ sWinningTeamName $ Chr(13) $ Chr(10));
		}
		else
		{
			TournamentWriteResults(HC,"" $ Chr(13) $ Chr(10));
		}
		TournamentWriteResults(HC,"Team0Name=" $ attrTournamentFinalResults[0].sTeamName $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"Team1Name=" $ attrTournamentFinalResults[1].sTeamName $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"Team0Wins=" $ attrTournamentFinalResults[0].iTotalWins $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"Team1Wins=" $ attrTournamentFinalResults[1].iTotalWins $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"Ties=" $ iTotalRoundsTied $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"TotalTeam0Score=" $ attrTournamentFinalResults[0].iTotalScore $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"TotalTeam1Score=" $ attrTournamentFinalResults[1].iTotalScore $ Chr(13) $ Chr(10));
		for(iTeamIndex=0; iTeamIndex<2; iTeamIndex++)
		{
			TournamentWriteResults(HC,Chr(13) $ Chr(10) $ "[Team" $ iTeamIndex $ "PlayerList]" $ Chr(13) $ Chr(10));
			for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
			{
				if(atpsTournamentPlayerStats[iPlayerIndex].sTeamName == attrTournamentFinalResults[iTeamIndex].sTeamName)
				{
					sPlayerInfo="Player=""" $ atpsTournamentPlayerStats[iPlayerIndex].sPlayerName $ """," $ atpsTournamentPlayerStats[iPlayerIndex].iKills;
					sPlayerInfo=sPlayerInfo $ "," $ atpsTournamentPlayerStats[iPlayerIndex].iDeaths $ "," $ atpsTournamentPlayerStats[iPlayerIndex].iGoalPoints;
					sPlayerInfo=sPlayerInfo $ "," $ atpsTournamentPlayerStats[iPlayerIndex].iLeaderPoints $ "," $ atpsTournamentPlayerStats[iPlayerIndex].iROE;
					sPlayerInfo=sPlayerInfo $ "," $ atpsTournamentPlayerStats[iPlayerIndex].iRoundsPlayed $ "," $ atpsTournamentPlayerStats[iPlayerIndex].iTotalScore;
					TournamentWriteResults(HC,sPlayerInfo $ Chr(13) $ Chr(10));
				}
			}
		}
		TournamentWriteResults(HC,Chr(13) $ Chr(10) $ "[Spectators]" $ Chr(13) $ Chr(10));
		for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
		{
			if(Len(asTournamentSpectators[iPlayerIndex]) > 0)
			{
				TournamentWriteResults(HC,"Spectator=" $ asTournamentSpectators[iPlayerIndex] $ Chr(13) $ Chr(10));
			}
		}
		TournamentWriteResults(HC,Chr(13) $ Chr(10) $ "[Administrators]" $ Chr(13) $ Chr(10));
		for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
		{
			if(Len(asTournamentAdministrators[iPlayerIndex]) > 0)
			{
				TournamentWriteResults(HC,"Administrator=" $ asTournamentAdministrators[iPlayerIndex] $ Chr(13) $ Chr(10));
			}
		}
		TournamentWriteResults(HC,Chr(13) $ Chr(10) $ "[Rules]" $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"ServerName=" $ GameReplicationInfo.ServerName $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"Map=" $ Level.GetLevelName() $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"TournamentRounds=" $ iTournamentMaxRounds $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"RoundLength=" $ iTournamentRoundTime $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"WarmupTime=" $ iTournamentWarmupDuration $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"SwapLimit=" $ iTournamentSwapLimit $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"SwapTime=" $ iTournamentSwapTime $ Chr(13) $ Chr(10));
		if(Level.GRI.bForceShadowsOff)
		{
			TournamentWriteResults(HC,"PlayerShadowsAllowed=False" $ Chr(13) $ Chr(10));
		}
		else
		{
			TournamentWriteResults(HC,"PlayerShadowsAllowed=True" $ Chr(13) $ Chr(10));
		}
		if(bTournamentTieSuddenDeath)
		{
			if(bTournamentTieScore)
			{
				sTieRules="Ties Not Allowed, Score Breaks Ties";
			}
			else
			{
				sTieRules="Ties Not Allowed, Sudden Death Breaks Ties";
			}
		}
		else
		{
			sTieRules="Ties Allowed";
		}
		TournamentWriteResults(HC,"TieRules=" $ sTieRules $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"RequestTime=" $ iTournamentRequestDelayTime $ Chr(13) $ Chr(10));
		if(Len(AccessControl.asTeamPasswords[0]) > 0 || Len(AccessControl.asTeamPasswords[1]) > 0)
		{
			TournamentWriteResults(HC,"TeamPasswordsUsed=Yes" $ Chr(13) $ Chr(10));
		}
		else
		{
			TournamentWriteResults(HC,"TeamPasswordsUsed=No" $ Chr(13) $ Chr(10));
		}
		TournamentWriteResults(HC,"TeamCaptainsAllowed=" $ bTournamentTeamCaptainsAllowed $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"PBEnabled=" $ Level.PBIsEnabled() $ Chr(13) $ Chr(10));
		if(bSpectatePlayersOnly)
		{
			sResults="Players Only,";
		}
		else
		{
			sResults="Viewpoints Allowed,";
		}
		if(bSpectateFirstPersonOnly)
		{
			sResults="First Person Only,";
		}
		else
		{
			sResults="Third Person Allowed,";
		}
		if(bSpectateFriendsOnly)
		{
			sResults="Friends Only,";
		}
		else
		{
			sResults="All Players Allowed,";
		}
		if(bSpectateBodies)
		{
			sResults="Bodies Allowed,";
		}
		else
		{
			sResults="No Bodies,";
		}
		TournamentWriteResults(HC,"SpectatorRules=" $ sResults $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"AllWeaponSlotsOpen=" $ bTournamentOpenAllWeaponClassSlots $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"DeathMessagesShown=" $ bDeathMessages $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"HUDHideAmmoCount=" $ GameReplicationInfo.bHUDHideAmmoCount $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"HUDHideWeaponStatus=" $ GameReplicationInfo.bHUDHideWeaponStatus $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"HUDHideWeapon=" $ GameReplicationInfo.bHUDHideWeapon $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"HUDHideGrenades=" $ GameReplicationInfo.bHUDHideGrenades $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"HUDHideHealth=" $ GameReplicationInfo.bHUDHideHealth $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"HUDHideCombatEffect=" $ GameReplicationInfo.bHUDHideCombatEffect $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"HUDHideOptics=" $ GameReplicationInfo.bHUDHideOptics $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"HUDHideCompass=" $ GameReplicationInfo.bHUDHideCompass $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"HUDHideTimerDisplayed=" $ GameReplicationInfo.bHUDHideTimer $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"HUDHideObjectives=" $ GameReplicationInfo.bHUDHideObjectives $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"HUDHideRadar=" $ GameReplicationInfo.bHUDHideRadar $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"ServerRegion=" $ GameReplicationInfo.ServerRegion $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"MinHonor=" $ MinHonor $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"MaxHonor=" $ MaxHonor $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"MaxPlayers=" $ MaxPlayers $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"MaxAdmins=" $ MaxAdmins $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"MaxSpectators=" $ MaxSpectators $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"RoundDelayTime=" $ iTournamentRoundDelayTime $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"ServerPort=" $ GetServerPort() $ Chr(13) $ Chr(10));
		DebugLog(DEBUG_Auth,"IP Address retrieved: " $ Class'InternetLink'.GetLocalIPAsString());
		TournamentWriteResults(HC,"ServerIP=" $ Class'InternetLink'.GetLocalIPAsString() $ Chr(13) $ Chr(10));
		Switch(ScoreMode)
		{
			case 0:
			TournamentWriteResults(HC,"ScoreMode=SSM_On" $ Chr(13) $ Chr(10));
			break;
			case 1:
			TournamentWriteResults(HC,"ScoreMode=SSM_Off" $ Chr(13) $ Chr(10));
			break;
			case 2:
			TournamentWriteResults(HC,"ScoreMode=SSM_Round" $ Chr(13) $ Chr(10));
			break;
			case 3:
			TournamentWriteResults(HC,"ScoreMode=SSM_Match" $ Chr(13) $ Chr(10));
			break;
			default:
		}
		TournamentWriteResults(HC,"MOTD1=" $ GameReplicationInfo.MOTDLine1 $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"MOTD2=" $ GameReplicationInfo.MOTDLine2 $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"MOTD3=" $ GameReplicationInfo.MOTDLine3 $ Chr(13) $ Chr(10));
		TournamentWriteResults(HC,"MOTD4=" $ GameReplicationInfo.MOTDLine4 $ Chr(13) $ Chr(10));
		if(HC == None)
		{
			FClose();
		}
		else
		{
			HC.TournamentCloseResultsFile();
		}
	*/
}
void AAGP_GameTournament::TournamentUpdateTeamResults(int32 iTeamIndex)
{
	/*
		attrTournamentFinalResults[iTeamIndex].sTeamName=GameReplicationInfo.asTournamentTeamName[iTeamIndex];
		attrTournamentFinalResults[iTeamIndex].iTotalScore=AGP_TeamInfo(GameReplicationInfo.Teams[iTeamIndex]).GetTotalScore();
		attrTournamentFinalResults[iTeamIndex].iTotalWins=AGP_TeamInfo(GameReplicationInfo.Teams[iTeamIndex]).teamScore;
		attrTournamentFinalResults[iTeamIndex].iTotalLosses=iTotalRoundsPlayed - iTotalRoundsTied - AGP_TeamInfo(GameReplicationInfo.Teams[iTeamIndex]).teamScore;
	*/
}
void AAGP_GameTournament::TournamentWriteResults(AHumanController* HC, FString sText)
{
	/*
		if(HC == None)
		{
			FWrite(sText);
		}
		else
		{
			HC.TournamentWriteResultsFile(sText);
		}
	*/
}
void AAGP_GameTournament::TournamentIsDeadRound()
{
	/*
		Return bCurrentRoundIsDead;
	*/
}
void AAGP_GameTournament::TournamentRequestDeadRound()
{
	/*
		local Controller C;
		GameReplicationInfo.sTournamentState="Non-Scoring Round";
		TournamentSendMessage("The team captains or administrator has changed this round to a ""Non-Scoring"" round.");
		C=Level.ControllerList;
		if(C != None)
		{
			if(HumanController(C) != None && HumanController(C).bPBChecked)
			{
				PlayerController(C).bSuperGodMode=True;
				PlayerController(C).bGodMode=True;
			}
			C=C.nextController;
		}
		bCurrentRoundIsDead=True;
	*/
}
void AAGP_GameTournament::CompleteEndGame()
{
	/*
		Log("Complete End Game() entered");
		ResetDecoMeshes();
	*/
}
void AAGP_GameTournament::DisableObjectivesForMissionPlanning()
{
	/*
		local AGP.AGP_Objective agpobj;
		ForEach DynamicActors(Class'AGP_Objective',agpobj)
		{
			Log("Found objective, disabling it: " $ agpobj);
			agpobj.bDisabled=True;
		}
	*/
}
