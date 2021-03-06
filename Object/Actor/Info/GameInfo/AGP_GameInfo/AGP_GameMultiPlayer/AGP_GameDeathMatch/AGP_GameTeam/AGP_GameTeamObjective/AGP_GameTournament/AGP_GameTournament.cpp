// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameDeathMatch/AGP_GameTeam/AGP_GameTeamObjective/AGP_GameTournament/AGP_GameTournament.h"
#include "AA29/Object/Actor/Keypoint/AGP_Viewpoint/AGP_Viewpoint.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/UpdateTournamentResultsRequestAdapter/UpdateTournamentResultsRequestAd.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/InternetLink.h"
#include "AA29/Object/DBAuth/DBAuth.h"

AAGP_GameTournament::AAGP_GameTournament()
{
	attrTournamentFinalResults.SetNum(2);
	atpsTournamentPlayerStats.SetNum(32);
	asTournamentSpectators.SetNum(32);
	asTournamentAdministrators.SetNum(32);
	aiTournamentTeamScores.SetNum(2);
	asTournamentTeamName.SetNum(2);

}

static const uint8 TMMAXSPECTATORS = 32;
static const uint8 TMMAXADMINS = 32;
static const uint8 TMMAXTEAMS = 2;
static const uint8 TMMAXPLAYERS = 32;



/*
auto State PendingMatch
{
	Function CheckScore(APlayerReplicationInfo* Scorer)
	{
	}
	Function EndGame(APlayerReplicationInfo* Winner, FString Reason)
	{
	}
	Function PendingEndGame(APlayerReplicationInfo* Winner, FString Reason, int32 EndTime)
	{
	}
	Function BeginState()
	{
		bInPauseNow=false;
		TournamentResetTeamCaptainsReadyFlag();
		GameReplicationInfo.bTournamentInProgress=false;
	}
	Function Timer()
	{
		Global.PRI();
		if (bTournamentReadyToContinue)
		{
			bTournamentReadyToContinue=true;
			SetStartupStage(5);
			return;
		}
	}
	Function TournamentTeamsReady()
	{
		DebugLog(DEBUG_Tournament,"AGP_GameTournament::PendingMatch::TournamentTeamsReady() entered");
		if (iTournamentWarmupDuration > 0)
		{
			DebugLog(DEBUG_Tournament,"Starting mission planning round");
			TournamentRequestStartWarmup();
		}
		else
		{
			TournamentRequestStartMatch();
		}
	}
	Function bool TournamentAreRosterClassesLocked()
	{
		return false;
	}
}
*/

/*
State SwappingSides
{
	Function EndState()
	{
		DebugLog(DEBUG_Tournament,"AGP_GameTournament::Zdes::EndState()");
		iLastRoundSwappedOn=iSwappingRound;
		TournamentSendMessage("This round is a Mission Planning round following teams swapping sides.");
		bTournamentSwapPending=false;
		bCurrentRoundIsDead=true;
	}
	Function BeginState()
	{
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.SwappingSides.BeginState() entered");
		GameReplicationInfo.sTournamentState="Swapping Sides";
		TournamentResetTeamCaptainsReadyFlag();
		TournamentSwapTeamCaptainSelectedFlag();
		bEndPauseNow=false;
		bInPauseNow=true;
		GameReplicationInfo.TournamentCountDownTime=iTournamentSwapTime;
	}
	Function Timer()
	{
		Global.PRI();
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.SwappingSides.Timer() entered: " + FString::FromInt(iTournamentSwapTime) + " Countdown Timer: " + FString::FromInt(GameReplicationInfo.TournamentCountDownTime));
		if ((iTournamentSwapTime > 0) || bEndPauseNow)
		{
			if (GameReplicationInfo.TournamentCountDownTime -- == 0)
			{
				GameReplicationInfo.sTournamentState="Mission Planning";
				if (bTournamentSuddenDeath)
				{
					ShowCountDown(GameReplicationInfo.TournamentCountDownTime,"Tournament now entering Mission Planning prior to Sudden Death round");
				}
				else
				{
					ShowCountDown(GameReplicationInfo.TournamentCountDownTime,"Tournament entering Mission Planning round prior to resuming.");
				}
				bTournamentSwapPending=false;
				bTournamentPausePending=false;
				bTournamentRestartPending=false;
				bTournamentWarmupPending=false;
				iLastRoundSwappedOn=(GameReplicationInfo.RoundsPerMatch - GameReplicationInfo.RemainingRounds);
				TimeLimit=iTournamentWarmupDuration;
				GameReplicationInfo.TimeLimit=iTournamentWarmupDuration;
				RemainingTime=(iTournamentWarmupDuration * 60);
				GameReplicationInfo.RemainingTime=RemainingTime;
				ElapsedTime=0;
				bWaitingToStartMatch=true;
				bPlayersMustBeReady=false;
				bWaitForNetPlayers=false;
				bGameEnded=false;
				ResetRoundScores();
				ResetDecoMeshes();
				FakeRestartGame();
				SetStartupStage(5);
				StartMatch();
				DebugLog(DEBUG_Tournament,"AGP_GameTournament::SwappingSides::Timer() - called start match()");
			}
			else
			{
				if ((iTournamentSwapTime - GameReplicationInfo.TournamentCountDownTime) > 2)
				{
					if (bTournamentSuddenDeath)
					{
						ShowCountDown(GameReplicationInfo.TournamentCountDownTime,"Tournament entering Mission Planning round prior to Sudden Death");
					}
					else
					{
						ShowCountDown(GameReplicationInfo.TournamentCountDownTime,"Tournament entering Mission Planning round");
					}
				}
			}
		}
	}
	Function TournamentTeamsReady()
	{
		bEndPauseNow=true;
		bTournamentSwapPending=false;
		TournamentResetTeamCaptainsReadyFlag();
		if (GameReplicationInfo.TournamentCountDownTime > 10)
		{
			GameReplicationInfo.TournamentCountDownTime=10;
		}
	}
}
*/

/*
State TournamentPaused
{
	Function Timer()
	{
		FString sTimeLeftInPauseMessage = "";
		Global.PRI();
		iTournamentPauseLength ++;
		GameReplicationInfo.TournamentCountDownTime --;
		if (((iTournamentPauseLimit > 0) && (GameReplicationInfo.TournamentCountDownTime <= 10)) || bEndPauseNow)
		{
			DebugLog(DEBUG_Tournament,"Ending pause state with countdown: " + FString::FromInt(GameReplicationInfo.TournamentCountDownTime));
			GameReplicationInfo.sTournamentState="Live Play";
			if (GameReplicationInfo.TournamentCountDownTime <= 0)
			{
				ShowCountDown(GameReplicationInfo.TournamentCountDownTime,"Tournament resuming  in Mission Planning round.");
				TimeLimit=iTournamentRoundTime;
				GameReplicationInfo.TimeLimit=iTournamentWarmupDuration;
				RemainingTime=(iTournamentWarmupDuration * 60);
				GameReplicationInfo.RemainingTime=RemainingTime;
				ElapsedTime=0;
				bWaitingToStartMatch=true;
				bPlayersMustBeReady=false;
				bWaitForNetPlayers=false;
				bGameEnded=false;
				ResetRoundScores();
				ResetDecoMeshes();
				FakeRestartGame();
				bCurrentRoundIsDead=true;
				TournamentSendMessage("This round is a Mission Planning round following the Tournament \"Pause\".");
				SetStartupStage(5);
				StartMatch();
				return;
			}
			else
			{
				ShowCountDown(GameReplicationInfo.TournamentCountDownTime,"Tournament resumes in Mission Planning round");
			}
		}
		else
		{
			if ((iTournamentPauseLimit > 0) && (iTournamentPauseLength >= (iTournamentPauseLimit - 10)))
			{
				DebugLog(DEBUG_Tournament,"AGP_GameTournament::TournamentPaused:Timer() - Near end of pause timer: " + FString::FromInt(GameReplicationInfo.TournamentCountDownTime));
			}
			else
			{
				if ((float(iTournamentPauseLength) % float(10)) == 0)
				{
					if (iTournamentPauseLimit > 0)
					{
						sTimeLeftInPauseMessage=" The Pause will end automatically in " + FString::FromInt((iTournamentPauseLimit - iTournamentPauseLength)) + " second";
						if ((iTournamentPauseLimit - iTournamentPauseLength) > 1)
						{
							sTimeLeftInPauseMessage=sTimeLeftInPauseMessage + "s";
						}
						sTimeLeftInPauseMessage=sTimeLeftInPauseMessage + ".";
					}
					DebugLog(DEBUG_Tournament,"AGP_GameTournament.TournamentPaused.Timer() - Time left: " + FString::FromInt((iTournamentPauseLimit - iTournamentPauseLength)));
					TournamentSendTeamCaptainOnlyMessage("The tournament is still paused.  Use the 'Ready' button on the 'Roster' page to signal you are ready to resume play." + sTimeLeftInPauseMessage);
					TournamentSendNonTeamCaptainMessages("The tournament is still paused.  Team Captains or the Administrator can resume the tournament at any time. " + sTimeLeftInPauseMessage);
				}
			}
		}
	}
	Function TournamentTeamsReady()
	{
		DebugLog(DEBUG_Tournament,"TournamentTeamsReady() entered while paused");
		bEndPauseNow=true;
		GameReplicationInfo.TournamentCountDownTime=10;
	}
	Function bool TournamentAreRosterClassesLocked()
	{
		return false;
	}
	Function EndState()
	{
		DebugLog(DEBUG_Tournament,"AGP_GameTournament::TournamentPaused.EndState() - ending pause state, rounds per match at " + FString::FromInt(RoundsPerMatch));
	}
	Function BeginState()
	{
		FString sTimeLeftInPauseMessage = "";
		DebugLog(DEBUG_Tournament,"AGP_GameTournament::TournamentPaused.BeginState() - starting pause state, rounds per match at " + FString::FromInt(RoundsPerMatch));
		bEndPauseNow=false;
		GameReplicationInfo.sTournamentState="Paused";
		TournamentResetTeamCaptainsReadyFlag();
		if (iTournamentPauseLimit > 0)
		{
			sTimeLeftInPauseMessage=" The Pause will end automatically in " + FString::FromInt((iTournamentPauseLimit - iTournamentPauseLength)) + " second";
			if ((iTournamentPauseLimit - iTournamentPauseLength) > 1)
			{
				sTimeLeftInPauseMessage=sTimeLeftInPauseMessage + "s";
			}
			sTimeLeftInPauseMessage=sTimeLeftInPauseMessage + ".";
		}
		TournamentSendTeamCaptainOnlyMessage("The tournament has been paused.  Use the 'Ready' button on the 'Roster' page to signal you are ready to resume play." + sTimeLeftInPauseMessage);
		TournamentSendNonTeamCaptainMessages("The tournament has been paused.  Team Captains or the Administrator can resume the tournament at any time. " + sTimeLeftInPauseMessage);
		iTournamentPauseLength=0;
		if (iTournamentPauseLimit > 0)
		{
			GameReplicationInfo.TournamentCountDownTime=iTournamentPauseLimit;
			RemainingTime=iTournamentPauseLimit;
			GameReplicationInfo.RemainingTime=RemainingTime;
		}
		else
		{
			GameReplicationInfo.TournamentCountDownTime=0;
			RemainingTime=0;
			GameReplicationInfo.RemainingTime=RemainingTime;
		}
	}
}
*/

/*
State StartMatchCountdown
{
	Function TournamentRequestWarmup()
	{
	}
	Function TournamentRequestResetMatch()
	{
	}
	Function TournamentRequestRestartMatch()
	{
	}
	Function BeginState()
	{
		TournamentResetTeamCaptainsReadyFlag();
		GameReplicationInfo.TournamentCountDownTime=10;
		RemainingTime=10;
		GameReplicationInfo.RemainingTime=10;
	}
	Function Timer()
	{
		Global.PRI();
		if (GameReplicationInfo.TournamentCountDownTime -- <= 0)
		{
			GameReplicationInfo.sTournamentState="Live Play";
			RoundsPerMatch=iTournamentMaxRounds;
			GameReplicationInfo.RemainingRounds=iTournamentMaxRounds;
			GameReplicationInfo.RoundsPerMatch=iTournamentMaxRounds;
			TimeLimit=iTournamentRoundTime;
			GameReplicationInfo.TimeLimit=iTournamentRoundTime;
			RemainingTime=(iTournamentRoundTime * 60);
			ElapsedTime=0;
			bWaitingToStartMatch=true;
			bPlayersMustBeReady=false;
			bWaitForNetPlayers=false;
			bGameEnded=false;
			ResetTMMatchScores();
			ResetRoundScores();
			ResetDecoMeshes();
			FakeRestartGame();
			SetStartupStage(5);
			Log("****************************");
			Log("****************************");
			Log(string(this) + "." + FString::FromInt(GetStateName()) + ".Timer() in live play, starting match");
			Log("****************************");
			Log("****************************");
			StartMatch();
		}
		else
		{
			ShowCountDown(GameReplicationInfo.TournamentCountDownTime,"Tournament starting");
		}
	}
}
*/

/*
State WarmupCountdown
{
	Function TournamentRequestWarmup()
	{
	}
	Function TournamentRequestResetMatch()
	{
	}
	Function TournamentRequestRestartMatch()
	{
	}
	Function BeginState()
	{
		AController* C = nullptr;
		GameReplicationInfo.sTournamentState="Mission Planning";
		TournamentResetTeamCaptainsReadyFlag();
		GameReplicationInfo.TournamentCountDownTime=iRoundDelayTimeCounter;
		RemainingTime=iRoundDelayTimeCounter;
		GameReplicationInfo.RemainingTime=iRoundDelayTimeCounter;
		for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
		{
			if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
			{
				Cast<APlayerController>(C).bSuperGodMode=true;
				Cast<APlayerController>(C).bGodMode=true;
			}
		}
	}
	Function Timer()
	{
		AController* C = nullptr;
		Global.PRI();
		if (TournamentGetConnectedPlayerCount() <= 0)
		{
			TournamentRequestResetTournament();
			return;
		}
		if (GameReplicationInfo.TournamentCountDownTime -- <= 0)
		{
			CompleteEndGame();
			ResetTMMatchScores();
			ResetRoundScores();
			SetStartupStage(5);
			bPlayersMustBeReady=false;
			bWaitForNetPlayers=false;
			bGameEnded=false;
			RoundsPerMatch=1;
			GameReplicationInfo.RoundsPerMatch=1;
			TimeLimit=iTournamentWarmupDuration;
			bTournamentWarmupStarted=true;
			GameReplicationInfo.bTournamentInWarmup=true;
			GameReplicationInfo.RemainingRounds=RoundsPerMatch;
			GameReplicationInfo.TimeLimit=TimeLimit;
			RemainingTime=(iTournamentWarmupDuration * 60);
			GameReplicationInfo.RemainingTime=RemainingTime;
			GameReplicationInfo.sTournamentState="Mission Planning";
			StartMatch();
			if (Stats != nullptr)
			{
				Stats.IgnoreStatsThisRound();
			}
			BroadcastHandler.Broadcast(this,"This is the mission planning round.","TMStatus");
			for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
			{
				if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
				{
					Cast<AHumanController>(C).NotifyAdminMessage("Use the mission planning round to visit as much of the map as possible.");
				}
			}
		}
		else
		{
			ShowCountDown(GameReplicationInfo.TournamentCountDownTime,"Mission planning starts");
		}
	}
}
*/

/*
State MatchInProgress
{
	Function BeginState()
	{
		Super::BeginState();
		GameReplicationInfo.bTournamentInProgress=true;
		GameReplicationInfo.asTournamentTeamName[0]=asTournamentTeamName[0];
		GameReplicationInfo.asTournamentTeamName[1]=asTournamentTeamName[1];
	}
	Function Timer()
	{
		if (bFirstRunAfterWarmup)
		{
			GameReplicationInfo.sTournamentState="Live Play";
			TournamentSendMessage("The tournament has officially begun - this round is live!");
			bFirstRunAfterWarmup=false;
			GameReplicationInfo.bTournamentWarmupJustEnded=bFirstRunAfterWarmup;
		}
		Super::Timer();
	}
	Function bool TestForIdlePlayers(APlayerReplicationInfo* PRI)
	{
		return false;
	}
	Function bool TournamentAreRosterClassesLocked()
	{
		if (bTournamentWarmupStarted)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	Function TournamentTeamsReady()
	{
		if (bTournamentWarmupStarted || bCurrentRoundIsDead)
		{
			TournamentEndCurrentRound();
		}
	}
	Function TournamentEndCurrentRound()
	{
		RemainingTime=0;
	}
	Function EndState()
	{
		DebugLog(DEBUG_Tournament,"AGP_GameTournament::MatchInProgress::EndState() entered");
	}
}
*/

/*
State TournamentStartup
{
	Function Timer()
	{
		Global.PRI();
		StartMatch();
	}
}
*/

/*
State MatchOver
{
	Function CheckScore(APlayerReplicationInfo* Scorer)
	{
	}
	Function EndGame(APlayerReplicationInfo* Winner, FString Reason)
	{
	}
	Function PendingEndGame(APlayerReplicationInfo* Winner, FString Reason, int32 EndTime)
	{
	}
	Function Timer()
	{
		FString sCurrentScore = "";
		AController* C = nullptr;
		Global.PRI();
		if ((++ iDelayScoreboardDisplayTime) < 4)
		{
			return;
		}
		if (bShowScoresOnClients)
		{
			bShowScoresOnClients=false;
			DebugLog(DEBUG_Tournament,"AGP_GameTournament::MatchOver::Timer() telling all PCs to show game score");
			for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
			{
				if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
				{
					if (C.PlayerReplicationInfo.Administrator())
					{
						TournamentAddNameToAdministratorList(C.PlayerReplicationInfo.PlayerName);
					}
					if ((C.PlayerReplicationInfo.Administrator() == false) && C.PlayerReplicationInfo.bOnlySpectator)
					{
						TournamentAddNameToSpectatorList(C.PlayerReplicationInfo.PlayerName);
					}
					Cast<APlayerController>(C).ClientOpenMenu("AGP_Interface.AAGameMenu",,"Score","EnableScores");
				}
			}
		}
		if (bTournamentForcedRestartPending)
		{
			if (iTournamentForcedRestartTimer ++== 5)
			{
				TournamentRequestResetTournament();
			}
			return;
		}
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.MatchOver.Timer() entered (time limit: " + FString::FromInt(iTournamentRoundDelayTime) + ")");
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.MatchOver.Timer() entered " + FString::FromInt(iRoundDelayTimeCounter) + " vs. required delay: " + FString::FromInt(iTournamentRoundDelayTime));
		iSwappingRound=(GameReplicationInfo.RoundsPerMatch - GameReplicationInfo.RemainingRounds);
		DebugLog(DEBUG_Tournament,"AGP_GameTournament::MatchOver.BeginState() - Swapping round: " + FString::FromInt(iTournamentSwapLimit) + " vs. current round: " + FString::FromInt(iSwappingRound));
		if (GameReplicationInfo.RemainingRounds > 0)
		{
			DebugLog(DEBUG_Tournament,"AGP_GameTournament::MatchOver.BeginState() - Swapping round: " + FString::FromInt(iSwappingRound) + " last round swapped: " + FString::FromInt(iLastRoundSwappedOn));
			if ((iLastRoundSwappedOn != iSwappingRound) && (! bJustEndedDeadRound))
			{
				if (((iSwappingRound < 0) || ((iSwappingRound > 0) && ((float(iSwappingRound) % float(iTournamentSwapLimit)) == 0))) || bTournamentSwapPending)
				{
					iLastRoundSwappedOn=iSwappingRound;
					bTournamentSwapPending=false;
					bTournamentPausePending=false;
					bTournamentRestartPending=false;
					bTournamentWarmupPending=false;
					ResetRoundScores();
					ResetDecoMeshes();
					FakeRestartGame();
					iSwappingRound=0;
					DebugLog(DEBUG_Tournament,"AGP_GameTournament::MatchOver.BeginState() - Swapping criteria hit, setting swap pending flag");
					TournamentSendTeamCaptainOnlyMessage("Swapping Sides - Adjust your roster accordingly.");
					TournamentSendNonTeamCaptainMessages("Swapping Sides - Rosters may be adjusted.");
					SwapSides();
					return;
				}
			}
		}
		if (bTournamentPausePending)
		{
			DebugLog(DEBUG_Tournament,"AGP_GameTournament::MatchOver::Timer() - Pause pending, entering pause state");
			CleanupLevel();
			ResetDecoMeshes();
			FakeRestartGame();
			TournamentPause();
			return;
		}
		DebugLog(DEBUG_Tournament,"AGP_GameTournament::MatchOver::Timer() Round Delay Time Counter " + FString::FromInt(iRoundDelayTimeCounter) + " vs Delay Time: " + FString::FromInt(iTournamentRoundDelayTime));
		if (iRoundDelayTimeCounter ++ >= iTournamentRoundDelayTime)
		{
			DebugLog(DEBUG_Tournament,"AGP_GameTournament::MatchOver::Timer() - About to try to restart");
			TimeLimit=iTournamentRoundTime;
			GameReplicationInfo.TimeLimit=iTournamentRoundTime;
			RemainingTime=(iTournamentRoundTime * 60);
			GameReplicationInfo.RemainingTime=RemainingTime;
			ElapsedTime=0;
			bPlayersMustBeReady=false;
			bWaitForNetPlayers=false;
			bGameEnded=false;
			ResetRoundScores();
			CleanupLevel();
			ResetDecoMeshes();
			FakeRestartGame();
			SetStartupStage(5);
			StartMatch();
			bJustEndedDeadRound=false;
			return;
		}
		else
		{
			if (TournamentGetConnectedPlayerCount() <= 0)
			{
				TournamentRequestResetTournament();
				return;
			}
			if ((iTournamentRoundDelayTime - iRoundDelayTimeCounter) > 0)
			{
				if (Cast<AAGP_TeamInfo>(GameReplicationInfo.Teams[0]).teamScore == Cast<AGP_TeamInfo>(GameReplicationInfo.Teams[1]).teamScore)
				{
					sCurrentScore="Match Tied. ";
				}
				else
				{
					if (Cast<AAGP_TeamInfo>(GameReplicationInfo.Teams[0]).teamScore > Cast<AGP_TeamInfo>(GameReplicationInfo.Teams[1]).teamScore)
					{
						sCurrentScore=GameReplicationInfo.asTournamentTeamName[0] + " leads " + FString::FromInt(Cast<AAGP_TeamInfo>(GameReplicationInfo.Teams[0]).teamScore) + "-" + FString::FromInt(Cast<AAGP_TeamInfo>(GameReplicationInfo.Teams[1]).teamScore) + ".";
					}
					else
					{
						sCurrentScore=GameReplicationInfo.asTournamentTeamName[1] + " leads " + FString::FromInt(Cast<AAGP_TeamInfo>(GameReplicationInfo.Teams[1]).teamScore) + "-" + FString::FromInt(Cast<AAGP_TeamInfo>(GameReplicationInfo.Teams[0]).teamScore) + ".";
					}
				}
				TournamentSendCenteredMessage(sCurrentScore + "  Next round continues in " + FString::FromInt((iTournamentRoundDelayTime - iRoundDelayTimeCounter)) + " seconds.");
				GameReplicationInfo.sTournamentState="Between Rounds";
			}
			else
			{
				GameReplicationInfo.sTournamentState="Live Play";
				if (bTournamentSuddenDeath)
				{
					TournamentSendCenteredMessage("Tournament continuing (Sudden Death).");
				}
				else
				{
					TournamentSendCenteredMessage("Tournament continuing now.");
				}
			}
		}
	}
	Function BeginState()
	{
		DebugLog(DEBUG_Tournament,"AGP_GameTournament::MatchOver::BeginState() entered");
		Log(string(this) + "." + FString::FromInt(GetStateName()) + ".BeginState() - pause request flag: " + FString::FromInt(bTournamentPausePending));
		iDelayScoreboardDisplayTime=0;
		TournamentResetTeamCaptainsReadyFlag();
		if ((! bTournamentWarmupStarted) && ShouldShowScores())
		{
			bShowScoresOnClients=true;
		}
		UpdateScoreboardVisibility();
		if (GameReplicationInfo.bTournamentInWarmup)
		{
			GameReplicationInfo.bTournamentInWarmup=false;
			if ((! TournamentTeamHasPlayers(0)) || (! TournamentTeamHasPlayers(1)))
			{
				bTournamentForcedRestartPending=true;
				TournamentSendTeamCaptainOnlyMessage("All of one team has left during Mission Planning, the server is resetting.");
				TournamentSendNonTeamCaptainMessages("All of one team has left during Mission Planning, the server is resetting.");
				return;
			}
		}
		GameReplicationInfo.bStopCountDown=true;
		SetStartupStage(10);
		ElapsedTime=0;
		RemainingTime=0;
		GameReplicationInfo.RemainingMinute=0;
		if (bTournamentRestartPending)
		{
			ResetDecoMeshes();
			FakeRestartGame();
			if (! bTournamentWarmupPending)
			{
				NotifyRoundOver();
			}
			bTournamentRestartPending=false;
			TournamentPerformRestartMatch();
			return;
		}
		if (bCurrentRoundIsDead)
		{
			Log("Current round dead, skipping scoring, etc.");
			NotifyRoundOver();
			iRoundDelayTimeCounter=0;
			bCurrentRoundIsDead=false;
			EndTime=GetWorld()->GetTimeSeconds();
			GameReplicationInfo.RemainingRounds ++;
			bJustEndedDeadRound=true;
			ResetDecoMeshes();
			CleanupLevel();
			return;
		}
		NotifyRoundOver();
		if (WholeMatchOver() || (ServerAuthFailures != 0))
		{
			bTournamentPausePending=false;
			AuthorizeServerNow();
		}
		SetTimer(1,true);
		iRoundDelayTimeCounter=0;
		EndTime=GetWorld()->GetTimeSeconds();
		if (bTournamentWarmupStarted)
		{
			RoundsPerMatch=iTournamentMaxRounds;
			GameReplicationInfo.RemainingRounds=iTournamentMaxRounds;
			GameReplicationInfo.RoundsPerMatch=iTournamentMaxRounds;
			ResetDecoMeshes();
			FakeRestartGame();
			DebugLog(DEBUG_Tournament,"AGP_GameTournament.MatchOver.Timer() - about to call StartMatchCountdown");
			bTournamentWarmupStarted=false;
			GotoState("StartMatchCountdown");
			return;
		}
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.MatchOver.BeginState() ending");
	}
}
*/

/*
State TournamentComplete
{
	Function TournamentTeamsReady()
	{
		bTournamentForcedRestartPending=true;
		TournamentSendTeamCaptainOnlyMessage("The Admin or Team Captains have requested to restart the tournament.");
		TournamentSendNonTeamCaptainMessages("The Admin or Team Captains have requested to restart the tournament.");
	}
	Function BeginState()
	{
		FString sResults = "";
		FString sCleanedServerName = "";
		int32 iCharIndex = 0;
		int32 iChar = 0;
		for (iCharIndex=0; iCharIndex<Len(GameReplicationInfo.ServerName); iCharIndex++)
		{
			iChar=Asc(Mid(GameReplicationInfo.ServerName,iCharIndex,1));
			if ((((((iChar >= 65) && (iChar <= 90)) || ((iChar >= 97) && (iChar <= 122))) || ((iChar >= 48) && (iChar <= 57))) || (iChar == 30)) || (iChar == 95))
			{
				sCleanedServerName $= Chr(iChar);
			}
		}
		sResultsBaseFileName=sCleanedServerName + "_" + GetSystemTimeForFileName() + ".txt";
		GameReplicationInfo.sTournamentResultsFileName=sResultsBaseFileName;
		GameReplicationInfo.sTournamentState="Complete";
		GameReplicationInfo.bTournamentInProgress=false;
		TournamentGenerateResults(nullptr,sResultsBaseFileName);
		iEndOfTournamentDelayBeforeResultsShown=0;
		if (sWinningTeamName == "")
		{
			sResults="The match ended in a tie" + sWinningReason + ".";
		}
		else
		{
			sResults="" + sWinningTeamName + " team has won the match" + sWinningReason + ".";
		}
		TournamentSendTeamCaptainOnlyMessage(sResults);
		TournamentSendNonTeamCaptainMessages(sResults);
		if (bRequireAuthorization && (Level.IsOfficialServer() || Level.IsLeasedServer()))
		{
			TournamentTransmitResultsToAuthServer();
		}
		iDelayScoreboardDisplayTime=0;
		SetTimer(1,true);
	}
	Function Timer()
	{
		AController* C = nullptr;
		Global.PRI();
		if ((++ iDelayScoreboardDisplayTime) == 8)
		{
			DebugLog(DEBUG_Tournament,"AGP_GameTournament::MatchOver::Timer() telling all PCs to show game score");
			for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
			{
				if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
				{
					if (C.PlayerReplicationInfo.Administrator())
					{
						TournamentAddNameToAdministratorList(C.PlayerReplicationInfo.PlayerName);
					}
					if ((C.PlayerReplicationInfo.Administrator() == false) && C.PlayerReplicationInfo.bOnlySpectator)
					{
						TournamentAddNameToSpectatorList(C.PlayerReplicationInfo.PlayerName);
					}
					Cast<APlayerController>(C).ClientOpenMenu("AGP_Interface.AAGameMenu",,"Score","EnableScores");
				}
			}
		}
		if (bTournamentForcedRestartPending && (iEndOfTournamentDelayBeforeResultsShown > 3))
		{
			if (iTournamentForcedRestartTimer ++== 5)
			{
				TournamentRequestResetTournament();
			}
			return;
		}
		if (iEndOfTournamentDelayBeforeResultsShown ++== 3)
		{
			for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
			{
				if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
				{
					TournamentGenerateResults(Cast<AHumanController>(C),sResultsBaseFileName);
					if (Cast<AHumanController>(C).bPlayerIsReadyToPlay)
					{
						Cast<AHumanController>(C).GotoState("GameEnded");
					}
				}
			}
		}
		if (TournamentGetConnectedPlayerCount() <= 0)
		{
			TournamentRequestResetTournament();
		}
	}
}
*/

/*
void AAGP_GameTournament::PostBeginPlay()
{
	Super::PostBeginPlay();
		DebugLog(DEBUG_Tournament,"*** AGP_GameTournament.PostBeginPlay() *** ");
		DebugLog(DEBUG_Tournament,"Tournament Mode: " + bTournamentMode);
		DebugLog(DEBUG_Tournament,"Team 0 password: " + AccessControl.asTeamPasswords[0]);
		DebugLog(DEBUG_Tournament,"Team 1 password: " + AccessControl.asTeamPasswords[1]);
		DebugLog(DEBUG_Tournament,"Team 0 Name is " + asTournamentTeamName[0]);
		DebugLog(DEBUG_Tournament,"Team 1 Name is " + asTournamentTeamName[1]);
		DebugLog(DEBUG_Tournament,"Tournament Swap Time: " + iTournamentSwapTime);
		DebugLog(DEBUG_Tournament,"Tournament Swap Limit: " + iTournamentSwapLimit);
		DebugLog(DEBUG_Tournament,"Game Team Captains Allowed" + bTournamentTeamCaptainsAllowed);
		bCycleMaps=false;
		bAutoBalanceBetweenRounds=false;
		bNeverAutoBalance=true;
		bEnableROEKickTimer=false;
		bEnableROEKick=false;
		bEnableROEKickDeath=false;
		bPlayersBalanceTeams=false;
		bSpectateBodies=false;
		bKickIdlePlayersTimed=false;
		bKickIdleSpectators=false;
		bTournamentMode=true;
		bInPauseNow=false;
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
		int32 i = 0;
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
		GameReplicationInfo.bTournamentWarmupJustEnded=false;
		GameReplicationInfo.bTournamentInWarmup=false;
		if(GameReplicationInfo.Teams[0] != nullptr)
		{
			GameReplicationInfo.Teams[0].bTournamentTeamReady=false;
		}
		if(GameReplicationInfo.Teams[1] != nullptr)
		{
			GameReplicationInfo.Teams[1].bTournamentTeamReady=false;
		}
		if(Len(AccessControl.asTeamPasswords[0]) > 1 || Len(AccessControl.asTeamPasswords[1]) > 1)
		{
			GameReplicationInfo.bTournamentTeamPasswordsRequired=true;
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
		Log("Rounds per match: " + iTournamentMaxRounds);
	*/
}

/*
APlayerController* AAGP_GameTournament::Login(FString Portal, FString Options, FString& Error)
{
	APlayerController* NewPlayer = nullptr;
	FString InPassword = "";
	int32 i = 0;
	NewPlayer=Login(Portal,Options,Error);
	if(! GameReplicationInfo.bTournamentTeamPasswordsRequired)
	{
		return NewPlayer;
	}
	if(AccessControl.asTeamPasswords[0] != "" && AccessControl.asTeamPasswords[1] != "" && AccessControl.asTeamPasswords[0] == AccessControl.asTeamPasswords[1])
	{
		return NewPlayer;
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
	return NewPlayer;
}
*/

void AAGP_GameTournament::Logout(AController* Exiting)
{
	/*
		Logout(Exiting);
		if(Cast<APlayerController>(Exiting) != nullptr && PlayerController(Exiting).PlayerReplicationInfo.Team != nullptr)
		{
			if(Cast<APlayerController>(Exiting).PlayerReplicationInfo.bAdmin)
			{
				GameReplicationInfo.Teams[PlayerController(Exiting).PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamCaptainSelected=false;
			}
			else
			{
				if(Cast<APlayerController>(Exiting).PlayerReplicationInfo.bTournamentTeamCaptain)
				{
					GameReplicationInfo.Teams[PlayerController(Exiting).PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamCaptainSelected=false;
					GameReplicationInfo.Teams[PlayerController(Exiting).PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamRosterLocked=false;
				}
			}
		}
	*/
}

bool AAGP_GameTournament::TournamentTeamHasPlayers(int32 iTeamIndex)
{
	AController* C = nullptr;
	/*
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (C->IsA(APlayerController::StaticClass()) && (Cast<APlayerController>(C).PlayerReplicationInfo.Team.TeamIndex == iTeamIndex))
		{
			return true;
		}
	}
	*/
	return false;

}
void AAGP_GameTournament::TournamentRequestResetMatch()
{
	AController* C = nullptr;
	/*
	if ((!TournamentTeamHasPlayers(0)) || (!TournamentTeamHasPlayers(1)))
	{
		for (C = Level.ControllerList; C != nullptr; C = C.nextController)
		{
			if (((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked) && PlayerController(C).PlayerReplicationInfo.bAdmin)
			{
				Cast<AHumanController>(Cast<APlayerController>(C)).NotifyAdminMessage("There are not enough players on both teams.");
			}
		}
		return;
	}
	bTournamentRestartPending = true;
	TournamentResetMatchData();
	GameReplicationInfo.bTournamentWarmupJustEnded = true;
	GotoState("MatchOver");
	*/
}

void AAGP_GameTournament::TournamentRequestWarmup()
{
	AController* C = nullptr;
	if (iTournamentWarmupDuration == 0)
	{
		/*
		for (C = Level.ControllerList; C != nullptr; C = C.nextController)
		{
			if (((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked) && (Cast<APlayerController>(C).PlayerReplicationInfo.bTournamentTeamCaptain || PlayerController(C).PlayerReplicationInfo.bAdmin))
			{
				Cast<AHumanController>(Cast<APlayerController>(C)).NotifyAdminMessage("The Mission Planning round was not enabled for this Tournament.");
			}
		}
		*/
		return;
	}
	if ((!TournamentTeamHasPlayers(0)) || (!TournamentTeamHasPlayers(1)))
	{
		/*
		for (C = Level.ControllerList; C != nullptr; C = C.nextController)
		{
			if (((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked) && PlayerController(C).PlayerReplicationInfo.bAdmin)
			{
				Cast<AHumanController>(Cast<APlayerController>(C)).NotifyAdminMessage("There are not enough players on both teams.");
			}
		}
		*/
		return;
	}
	bTournamentWarmupPending = true;
	TournamentRequestResetMatch();
}

void AAGP_GameTournament::TournamentPerformRestartMatch()
{
	int32 iIndex = 0;
	AController* C = nullptr;
	APlayerController* Player = nullptr;
	AAGP_Viewpoint* VP = nullptr;
	FString sTeam0Password = "";
	bTournamentWarmupStarted = false;
	CompleteEndGame();
	VP = GetWinningViewpoint(nullptr);
	/*
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
		{
			Player = Cast<APlayerController>(C);
			Player.ClientSetBehindView(true);
			Player.SetViewTarget(VP);
			Player.ClientSetViewTarget(VP);
			Player.ClientGameEnded();
		}
		else
		{
		}
		if (Cast<AHumanController>(C).bPlayerIsReadyToPlay)
		{
			C.GotoState("GameEnded");
		}
	}
	TournamentResetTeamCaptainsReadyFlag();
	CleanupForMatchEnd();
	iTotalRoundsPlayed = 0;
	iTotalRoundsTied = 0;
	for (iIndex = 0; iIndex < 32; iIndex++)
	{
		asTournamentAdministrators[iIndex] = "";
		asTournamentSpectators[iIndex] = "";
	}
	for (iIndex = 0; iIndex < 32; iIndex++)
	{
		atpsTournamentPlayerStats[iIndex].sTeamName = "";
		atpsTournamentPlayerStats[iIndex].sPlayerName = "";
		atpsTournamentPlayerStats[iIndex].iKills = 0;
		atpsTournamentPlayerStats[iIndex].iDeaths = 0;
		atpsTournamentPlayerStats[iIndex].iGoalPoints = 0;
		atpsTournamentPlayerStats[iIndex].iLeaderPoints = 0;
		atpsTournamentPlayerStats[iIndex].iTotalScore = 0;
		atpsTournamentPlayerStats[iIndex].iROE = 0;
		atpsTournamentPlayerStats[iIndex].iRoundsPlayed = 0;
	}
	for (iIndex = 0; iIndex < 2; iIndex++)
	{
		attrTournamentFinalResults[iIndex].sTeamName = "";
		attrTournamentFinalResults[iIndex].iTotalScore = 0;
		attrTournamentFinalResults[iIndex].iTotalWins = 0;
		attrTournamentFinalResults[iIndex].iTotalLosses = 0;
	}
	aiTournamentTeamScores[0] = 0;
	aiTournamentTeamScores[1] = 0;
	iLastRoundSwappedOn = 0;
	GameReplicationInfo.asTournamentTeamName[0] = asTournamentTeamName[0];
	GameReplicationInfo.asTournamentTeamName[1] = asTournamentTeamName[1];
	if (bTeamsSwapped)
	{
		sTeam0Password = AccessControl.asTeamPasswords[0];
		AccessControl.asTeamPasswords[0] = AccessControl.asTeamPasswords[1];
		AccessControl.asTeamPasswords[1] = sTeam0Password;
		bTeamsSwapped = false;
	}
	ResetTMMatchScores();
	ResetRoundScores();
	ResetMatchesBeforeCycle();
	ResetDecoMeshes();
	FakeRestartGame();
	bCurrentRoundIsDead = false;
	bTournamentSwapPending = false;
	bTournamentPausePending = false;
	bTournamentRestartPending = false;
	iSwappingRound = 0;
	iLastRoundSwappedOn = 0;
	bTournamentSuddenDeath = false;
	if (bTournamentWarmupPending)
	{
		bTournamentWarmupPending = false;
		TournamentRequestStartWarmup();
	}
	else
	{
		TournamentRequestRestartMatch();
	}
	*/
}

ATeamInfo* AAGP_GameTournament::TournamentGetTeam(uint8 Index)
{
	return GetTeam(Index);
}

bool AAGP_GameTournament::TournamentAreAllWeaponClassesAvailable()
{
	return bTournamentOpenAllWeaponClassSlots;
}

bool AAGP_GameTournament::TournamentEndedByMercyRule()
{
	return bTournamentStatisticallyOver;
}

void AAGP_GameTournament::TournamentRequestResetTournament()
{
	RestartGame();
}

bool AAGP_GameTournament::TournamentIsTournament()
{
	return bTournamentMode;
}

bool AAGP_GameTournament::TournamentJoinSpectatorTeam(APlayerController* PC, int32 iTeamIndex)
{
	/*
	if(PC != nullptr && PC.PlayerReplicationInfo.Team.TeamIndex == iTeamIndex)
	{
		DebugLog(DEBUG_Tournament,"Player already a Spectator.");
		PC.PlayerReplicationInfo.DesiredTeam=iTeamIndex;
		Level.Game.RequestChangeTeam(PC,iTeamIndex);
		return true;
	}
	if(IsInState('PendingMatch') || IsInState('TournamentComplete'))
	{
		if(PC != nullptr && PC.PlayerReplicationInfo.bTournamentTeamCaptain)
		{
			PC.PlayerReplicationInfo.bTournamentTeamCaptain=false;
			GameReplicationInfo.Teams[PC.PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamCaptainSelected=false;
			GameReplicationInfo.Teams[PC.PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamRosterLocked=false;
		}
		PC.PlayerReplicationInfo.DesiredTeam=iTeamIndex;
		Level.Game.ChangeTeam(PC,iTeamIndex);
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AAGP_GameTournament::TournamentJoinTeam(APlayerController* PC, int32 iTeamIndex, FString sPassword)
{
	/*
	DebugLog(DEBUG_Tournament,"AGP_GameTournament::TournamentJoinTeam() entered for " + iTeamIndex + " Password: " + sPassword + " vs. " + AccessControl.asTeamPasswords[iTeamIndex]);
	if(GameReplicationInfo.sTournamentState == "Complete")
	{
		Cast<AHumanController>(PC).TournamentCaptainAdminMessage("All players must leave the server to allow it to reset the tournament before you can join a team.");
		return false;
	}
	if(PC != nullptr && PC.PlayerReplicationInfo.Team.TeamIndex == iTeamIndex)
	{
		DebugLog(DEBUG_Tournament,"Player already on requested team");
		PC.PlayerReplicationInfo.DesiredTeam=iTeamIndex;
		Level.Game.RequestChangeTeam(PC,iTeamIndex);
		return true;
	}
	if(! GameReplicationInfo.bTournamentTeamPasswordsRequired || GameReplicationInfo.bTournamentTeamPasswordsRequired && AccessControl.asTeamPasswords[iTeamIndex] == "" || AccessControl.asTeamPasswords[iTeamIndex] == sPassword)
	{
		DebugLog(DEBUG_Tournament,"TournamentJoinTeam() success");
		if(IsInState('PendingMatch') || IsInState('TournamentComplete') || PC.PlayerReplicationInfo.Team.TeamIndex == 255)
		{
			if(PC != nullptr && PC.PlayerReplicationInfo.bTournamentTeamCaptain)
			{
				if(PC.PlayerReplicationInfo.bTournamentTeamCaptain && PC->IsA(AHumanController::StaticClass()))
				{
					Cast<AHumanController>(PC).TournamentRequestTeamCaptain(PC.PlayerReplicationInfo);
				}
				GameReplicationInfo.Teams[PC.PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamCaptainSelected=false;
				GameReplicationInfo.Teams[PC.PlayerReplicationInfo.Team.TeamIndex].bTournamentTeamRosterLocked=false;
			}
			PC.PlayerReplicationInfo.DesiredTeam=iTeamIndex;
			Level.Game.ChangeTeam(PC,iTeamIndex);
		}
		return true;
	}
	else
	{
		DebugLog(DEBUG_Tournament,"TournamentJoinTeam() failed");
		return false;
	}
	*/
	return false;    //ELiZ  //FAKE
}

FString AAGP_GameTournament::TournamentGetTeamName(int32 iTeamIndex)
{
	return asTournamentTeamName[iTeamIndex];
}

void AAGP_GameTournament::TournamentSetTeamName(int32 iTeamIndex, FString sTeamName)
{
	AController* C = nullptr;
	/*
	DebugLog(DEBUG_Tournament, "AGP_GameTournament.TournamentSetTeamName() entered for " + FString::FromInt(iTeamIndex) + " name: " + sTeamName);
	if ((iTeamIndex > 1) || (iTeamIndex < 0))
	{
		return;
	}
	asTournamentTeamName[iTeamIndex] = sTeamName;
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (C->IsA(AHumanController::StaticClass()))
		{
			Cast<AHumanController>(C).NotifyTournamentTeamNameUpdated(iTeamIndex, sTeamName);
		}
	}
	*/
}

void AAGP_GameTournament::TournamentAssignRandomTeams()
{
	/*
		FString sTeam0Name;
		FString sTeam0Password;
		if(! bTournamentEnableRandomTeamAssignments)
		{
			return;
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
			bTeamsSwapped=true;
		}
	*/
}

bool AAGP_GameTournament::TournamentRequestSwapSides()
{
	/*
	DebugLog(DEBUG_Tournament,"AGP_GameTournament.TournamentRequestSwapSides() - Requesting swapping of sides");
	if(GameReplicationInfo.RemainingRounds <= 1)
	{
		return false;
	}
	bTournamentSwapPending=true;
	BroadcastHandler.Broadcast(this,"Swapping sides at the end of this round.",'TMStatus');
	*/
	return true;
}

bool AAGP_GameTournament::TournamentChangeTeam(AController* ctrlrPlayer, int32 iTeamIndex)
{
	ATeamInfo* NewTeam = nullptr;
	/*
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
			DebugLog(DEBUG_Tournament,"AGP_GameTeam::ChangeTeam()	Requesting invalid team " + iTeamIndex);
			return false;
		}
	}
	DebugLog(DEBUG_Tournament,"AGP_GameTeam::ChangeTeam() " + ctrlrPlayer + " is trying to change to " + iTeamIndex @ NewTeam);
	if(ctrlrPlayer.PlayerReplicationInfo.Team == NewTeam)
	{
		DebugLog(DEBUG_Tournament,"AGP_GameTeam::ChangeTeam() Already on team " + NewTeam @ ctrlrPlayer @ ctrlrPlayer.PlayerReplicationInfo.PlayerName);
		return false;
	}
	ctrlrPlayer.StartSpot=nullptr;
	if(ctrlrPlayer.PlayerReplicationInfo.Team != nullptr)
	{
		ctrlrPlayer.PlayerReplicationInfo.Team.RemoveFromTeam(ctrlrPlayer);
	}
	if(NewTeam.AddToTeam(ctrlrPlayer))
	{
		BroadcastLocalizedMessage(GameMessageClass,3,ctrlrPlayer.PlayerReplicationInfo,None,NewTeam);
	}
	*/
	return true;
}

void AAGP_GameTournament::TournamentAssignClass(AAA2_PlayerState* PRI, int32 iUnitID, int32 iSlotIndex)
{
	/*
		AGP_TeamInfo(PRI.Team).TournamentSubmitPlayerRequest(PRI,iUnitID,iSlotIndex);
		PRI.bWaitingPlayer=false;
	*/
}
void AAGP_GameTournament::SwapSides()
{
	AController* C = nullptr;
	int32 iTeam0Score = 0;
	FString sTeam0Name = "";
	FString sTeam0Password = "";
	/*
	DebugLog(DEBUG_Tournament, "AGP_GameTournament.SwapSides() - Entered");
	DebugLog(DEBUG_Tournament, "AGP_GameTournament.SwapSides() - Current Team 0: " + GameReplicationInfo.asTournamentTeamName[0] + " Score: " + FString::FromInt(GameReplicationInfo.Teams[0].Score) + " TeamScore: " + FString::FromInt(GameReplicationInfo.Teams[0].teamScore));
	DebugLog(DEBUG_Tournament, "AGP_GameTournament.SwapSides() - Current Team 1: " + GameReplicationInfo.asTournamentTeamName[1] + " Score: " + FString::FromInt(GameReplicationInfo.Teams[1].Score) + " TeamScore: " + FString::FromInt(GameReplicationInfo.Teams[1].teamScore));
	iTeam0Score = GameReplicationInfo.Teams[0].teamScore;
	sTeam0Name = GameReplicationInfo.asTournamentTeamName[0];
	GameReplicationInfo.asTournamentTeamName[0] = GameReplicationInfo.asTournamentTeamName[1];
	asTournamentTeamName[0] = asTournamentTeamName[1];
	GameReplicationInfo.asTournamentTeamName[1] = sTeam0Name;
	asTournamentTeamName[1] = sTeam0Name;
	sTeam0Password = AccessControl.asTeamPasswords[0];
	AccessControl.asTeamPasswords[0] = AccessControl.asTeamPasswords[1];
	AccessControl.asTeamPasswords[1] = sTeam0Password;
	bTeamsSwapped = (!bTeamsSwapped);
	AGP_TeamInfo(GameReplicationInfo.Teams[0]).teamScore = Cast<AGP_TeamInfo>(GameReplicationInfo.Teams[1]).teamScore;
	AGP_TeamInfo(GameReplicationInfo.Teams[0]).teamScore = Cast<AGP_TeamInfo>(GameReplicationInfo.Teams[1]).teamScore;
	AGP_TeamInfo(GameReplicationInfo.Teams[1]).teamScore = iTeam0Score;
	DebugLog(DEBUG_Tournament, "AGP_GameTournament.SwapSides() - After Swap Team 0: " + GameReplicationInfo.asTournamentTeamName[0] + " Score: " + FString::FromInt(GameReplicationInfo.Teams[0].Score) + " TeamScore: " + FString::FromInt(GameReplicationInfo.Teams[0].teamScore));
	DebugLog(DEBUG_Tournament, "AGP_GameTournament.SwapSides() - After Swap Team 1: " + GameReplicationInfo.asTournamentTeamName[1] + " Score: " + FString::FromInt(GameReplicationInfo.Teams[1].Score) + " TeamScore: " + FString::FromInt(GameReplicationInfo.Teams[1].teamScore));
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (Cast<AHumanController>(C) == nullptr)
		{
		}
		if ((Cast<AHumanController>(C) != nullptr) && (!HumanController(C).bPBChecked))
		{
		}
		DebugLog(DEBUG_Tournament, "AGP_GameTournament.SwapSides() - Player " + C.PlayerReplicationInfo.PlayerName + " on team index: " + FString::FromInt(C.PlayerReplicationInfo.Team.TeamIndex));
		if (C.PlayerReplicationInfo.Team.TeamIndex == 0)
		{
			SwapPlayer(Cast<AHumanController>(C), 0, 1);
		}
		else
		{
			if (C.PlayerReplicationInfo.Team.TeamIndex == 1)
			{
				SwapPlayer(Cast<AHumanController>(C), 1, 0);
			}
			else
			{
				if (C.PlayerReplicationInfo.Team.TeamIndex == 255)
				{
					DebugLog(DEBUG_Tournament, "AGP_GameTournament.SwapPlayer() - Skipping spectator");
				}
			}
		}
	}
	bTournamentSwapPending = false;
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
		{
			DebugLog(DEBUG_Tournament, "AGP_GameTournament::SwapSides() - Team for player " + C.PlayerReplicationInfo.PlayerName + " is now: " + GameReplicationInfo.asTournamentTeamName[C.PlayerReplicationInfo.Team.TeamIndex]);
			Cast<AHumanController>(C).ClientCloseMenu(false);
			Cast<AHumanController>(C).ClientOpenMenu("AGP_Interface.AAGameMenu", , "Roster");
		}
	}
	GotoState("SwappingSides");
	*/
}

void AAGP_GameTournament::SwapPlayer(AHumanController* HC, int32 iOldTeam, int32 iNewTeam)
{
	/*
		int32 iPreSwapUnitID;
		int32 iPreSwapUnitIndex;
		int32 iPreSwapRealIndex;
		iPreSwapUnitID=AGP_TeamInfo(HC.PlayerReplicationInfo.Team).GetPlayerUnitID(HC.PlayerReplicationInfo);
		iPreSwapUnitIndex=AGP_TeamInfo(HC.PlayerReplicationInfo.Team).GetPlayerIndex(HC.PlayerReplicationInfo);
		DebugLog(DEBUG_Tournament,"Swapping " + HC.PlayerReplicationInfo.PlayerName + " from team index: " + iOldTeam + "(" + GameReplicationInfo.asTournamentTeamName[iOldTeam] + ") to team " + iNewTeam + "(" + GameReplicationInfo.asTournamentTeamName[iNewTeam] + ") ");
		DebugLog(DEBUG_Tournament,"SwapPlayer - Unit ID found: " + iPreSwapUnitID + " unit index: " + iPreSwapUnitIndex);
		HC.PlayerReplicationInfo.DesiredTeam=iNewTeam;
		TournamentChangeTeam(HC,iNewTeam);
		AGP_TeamInfo(HC.PlayerReplicationInfo.Team).ClearPlayerRequests(HC.PlayerReplicationInfo);
		AGP_TeamInfo(HC.PlayerReplicationInfo.Team).AddToNoRequestList(HC.PlayerReplicationInfo,false);
		if(iPreSwapUnitID != -1)
		{
			iPreSwapRealIndex=AGP_TeamInfo(HC.PlayerReplicationInfo.Team).GetRealIndex(iPreSwapUnitID,iPreSwapUnitIndex);
			AGP_TeamInfo(HC.PlayerReplicationInfo.Team).AssignPlayerRequest(HC.PlayerReplicationInfo,iPreSwapRealIndex);
			AGP_TeamInfo(GameReplicationInfo.Teams[iNewTeam]).AssignPlayerRequest(HC.PlayerReplicationInfo,iPreSwapRealIndex);
		}
		HC.NotifyTournamentTeamNameUpdated(iNewTeam,GameReplicationInfo.asTournamentTeamName[iNewTeam]);
		DebugLog(DEBUG_Tournament,"Swapped player to desired team " + HC.PlayerReplicationInfo.DesiredTeam);
	*/
}
void AAGP_GameTournament::TournamentResumeFromPause()
{
	/*
		bEndPauseNow=true;
	*/
}
void AAGP_GameTournament::TournamentRequestPauseTournament()
{
	/*
		bTournamentPausePending=true;
		BroadcastHandler.Broadcast(this,"The tournament will pause at the end of this round.",'TMStatus');
	*/
}
void AAGP_GameTournament::TournamentPause()
{
	AController* C = nullptr;
	bTournamentSwapPending = false;
	bTournamentPausePending = false;
	bTournamentRestartPending = false;
	bTournamentWarmupPending = false;
	/*
	GotoState("TournamentPaused");
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
		{
			Cast<AHumanController>(Cast<APlayerController>(C)).NotifyAdminMessage("The tournament has been paused by request of the team captains or the administrator.");
		}
	}
	*/
}

void AAGP_GameTournament::TournamentResume()
{
	/*
		DebugLog(DEBUG_Tournament,"AGP_Gameplay.TournamentResume() - initiating resumption of tournament");
		GameReplicationInfo.TournamentCountDownTime=10;
		bTournamentPausePending=false;
	*/
}

void AAGP_GameTournament::TournamentResetTeamCaptainsReadyFlag()
{
	AController* C = nullptr;
	APlayerController* Player = nullptr;
	/*
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (C->IsA(APlayerController::StaticClass()))
		{
			Player = Cast<APlayerController>(C);
			if (Player != nullptr)
			{
				Player.PlayerReplicationInfo.Team.bTournamentTeamReady = false;
				Player.PlayerReplicationInfo.Team.bTournamentRequestDeadRound = false;
				Player.PlayerReplicationInfo.bTournamentRestartTournamentRequest = false;
				Player.PlayerReplicationInfo.bTournamentRestartRequest = false;
				Player.PlayerReplicationInfo.bTournamentStartRequest = false;
				Player.PlayerReplicationInfo.bTournamentWarmupRequest = false;
				Player.PlayerReplicationInfo.bTournamentTeamSwapRequest = false;
				Player.PlayerReplicationInfo.bTournamentMatchPauseRequest = false;
			}
		}
	}
	*/
}

void AAGP_GameTournament::TournamentSwapTeamCaptainSelectedFlag()
{
	bool bTempFlag = false;
	AAGP_TeamInfo* Team_1 = nullptr;
	AAGP_TeamInfo* Team_2 = nullptr;
	Team_1=Cast<AAGP_TeamInfo>(GameReplicationInfo->Teams[0]);
	Team_2=Cast<AAGP_TeamInfo>(GameReplicationInfo->Teams[1]);
	if(Team_1 == nullptr || Team_2 == nullptr)
	{
		//Log("Warning: Teams do not exist!");
		return;
	}
	else
	{
		bTempFlag=Team_1->bTournamentTeamCaptainSelected;
		Team_1->bTournamentTeamCaptainSelected=Team_2->bTournamentTeamCaptainSelected;
		Team_2->bTournamentTeamCaptainSelected=bTempFlag;
	}
}

void AAGP_GameTournament::TournamentRequestStartMatch()
{
	/*
	GameReplicationInfo.bTournamentInProgress=false;
	GotoState('StartMatchCountdown');
	*/
}
void AAGP_GameTournament::TournamentRequestRestartMatch()
{
	//GotoState('StartMatchCountdown');
}

void AAGP_GameTournament::TournamentRequestStartWarmup()
{
	AController* C = nullptr;
	if ((!TournamentTeamHasPlayers(0)) || (!TournamentTeamHasPlayers(1)))
	{
		/*
		DebugLog(DEBUG_Tournament, "AGP_GameTournament::TournamentRequestStartWarmup() - No players found");
		for (C = Level.ControllerList; C != nullptr; C = C.nextController)
		{
			if (((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked) && PlayerController(C).PlayerReplicationInfo.bAdmin)
			{
				Cast<AHumanController>(Cast<APlayerController>(C)).NotifyAdminMessage("There are not enough players on both teams.");
			}
		}
		*/
		return;
	}
	bPlayersMustBeReady = false;
	bWaitForNetPlayers = false;
	//GotoState("WarmupCountdown");
}

bool AAGP_GameTournament::TournamentIsWarmup()
{
	return bTournamentWarmupStarted;
}

bool AAGP_GameTournament::CheckEndGame(AAA2_PlayerState* Winner, FString Reason)
{
	AController* C = nullptr;
	APlayerController* Player = nullptr;
	AAGP_Viewpoint* VP = nullptr;
	AVehicle* V = nullptr;
	APawn* PlayerPawn = nullptr;
	/*
	DebugLog(DEBUG_Tournament, "AGP_GameTournament.CheckEndGame() entered");
	EndTime = (GetWorld()->GetTimeSeconds() + 3);
	if (Winner != nullptr)
	{
		GameReplicationInfo.Winner = Winner;
	}
	VP = GetWinningViewpoint(Winner);
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked) && Cast<AHumanController>(C).bPlayerIsReadyToPlay)
		{
			Player = Cast<APlayerController>(C);
			PlayerPawn = Player.Pawn;
			V = Vehicle(PlayerPawn);
			if (V != nullptr)
			{
				Player.Pawn = V.Driver;
				V.Driver = nullptr;
				V.Controller = nullptr;
				Player.Pawn.SetBase(nullptr);
				Player.AcknowledgedPawn = Player.Pawn;
			}
			Player.ClientSetBehindView(true);
			Player.SetViewTarget(VP);
			Player.ClientSetViewTarget(VP);
			if (bTournamentWarmupStarted)
			{
				Cast<AHumanController>(Player).TournamentWarmupClientGameEnded();
			}
			else
			{
				Player.ClientGameEnded();
			}
		}
		if (!bTournamentWarmupStarted)
		{
			if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPlayerIsReadyToPlay)
			{
				C.GotoState("GameEnded");
			}
		}
	}
	*/
	CleanupForMatchEnd();
	return true;
}

bool AAGP_GameTournament::ShouldIgnoreStats()
{
	return bCurrentRoundIsDead;
}

void AAGP_GameTournament::AddAllPlayersToStatsInfo()
{
}

void AAGP_GameTournament::ResetTMMatchScores()
{
	AController* C = nullptr;
	AAA2_PlayerState* PRI = nullptr;
	/*
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		PRI = C.PlayerReplicationInfo;
		if (PRI == nullptr)
		{
		}
		PRI._cumRounds = 0;
		PRI._LastTimeUpdate = int(GetWorld()->GetTimeSeconds());
		PRI.Score_Total = 0;
		PRI.Score_Leadership = 0;
		PRI.Score_Wins = 0;
		PRI.Score_Objectives = 0;
		PRI.Score_Deaths = 0;
		PRI.Score_Kills = 0;
		PRI.Score_ROE = 0;
		PRI.votekick = "";
	}
	*/
	ResetRemainingRounds();
}

void AAGP_GameTournament::StartMatch()
{
	AController* C = nullptr;
	bWaitingToStartMatch = true;
	Super::StartMatch();
	/*
	if (bCurrentRoundIsDead || bTournamentWarmupStarted)
	{
		GameReplicationInfo.sTournamentState = "Mission Planning";
		DisableObjectivesForMissionPlanning();
	}
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
		{
			Cast<APlayerController>(C).bSuperGodMode = (bCurrentRoundIsDead || bTournamentWarmupStarted);
			Cast<APlayerController>(C).bGodMode = Cast<APlayerController>(C).bSuperGodMode;
		}
	}
	*/
}
void AAGP_GameTournament::TournamentAddNameToAdministratorList(FString sPlayerName)
{
	int32 iPlayerIndex = 0;
	int32 iFirstBlank = 0;
	iFirstBlank = -1;
	/*
	for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
	{
		if(Len(asTournamentAdministrators[iPlayerIndex]) == 0 && iFirstBlank == -1)
		{
			iFirstBlank=iPlayerIndex;
		}
		if(asTournamentAdministrators[iPlayerIndex] == sPlayerName)
		{
			return;
		}
	}
	if(iFirstBlank == -1)
	{
		return;
	}
	asTournamentAdministrators[iFirstBlank]=sPlayerName;
	*/
}

void AAGP_GameTournament::TournamentAddNameToSpectatorList(FString sPlayerName)
{
	int32 iPlayerIndex = 0;
	int32 iFirstBlank = 0;
	iFirstBlank = -1;
	/*
	for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
	{
		if(Len(asTournamentSpectators[iPlayerIndex]) == 0 && iFirstBlank == -1)
		{
			iFirstBlank=iPlayerIndex;
		}
		if(asTournamentSpectators[iPlayerIndex] == sPlayerName)
		{
			return;
		}
	}
	if(iFirstBlank == -1)
	{
		return;
	}
	asTournamentSpectators[iFirstBlank]=sPlayerName;
	*/
}

void AAGP_GameTournament::NotifyRoundOver()
{
	AController* C = nullptr;
	FString sTournamentStatusMsg = "";
	/*
	if (bCurrentRoundIsDead)
	{
		GameReplicationInfo.sTournamentState = "Live Play";
		TournamentSendMessage("The round did not count because the Team Captains, Admin, or server rules discarded it as a \"Non-Scoring Round\".");
		Log("Current round count: " + FString::FromInt(GameReplicationInfo.RemainingRounds));
		for (C = Level.ControllerList; C != nullptr; C = C.nextController)
		{
			if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
			{
				Cast<APlayerController>(C).bSuperGodMode = false;
				Cast<APlayerController>(C).bGodMode = false;
			}
		}
		TimeLimit = iTournamentRoundTime;
		GameReplicationInfo.TimeLimit = TimeLimit;
		return;
	}
	if (bTournamentWarmupStarted)
	{
		for (C = Level.ControllerList; C != nullptr; C = C.nextController)
		{
			if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
			{
				Cast<APlayerController>(C).bSuperGodMode = false;
				Cast<APlayerController>(C).bGodMode = false;
			}
		}
		RoundsPerMatch = iTournamentMaxRounds;
		GameReplicationInfo.RemainingRounds = RoundsPerMatch;
		TimeLimit = iTournamentRoundTime;
		GameReplicationInfo.TimeLimit = TimeLimit;
		GameReplicationInfo.RoundsPerMatch = RoundsPerMatch;
		ResetTMMatchScores();
		ResetRoundScores();
		bFirstRunAfterWarmup = true;
		GameReplicationInfo.bTournamentWarmupJustEnded = bFirstRunAfterWarmup;
	}
	else
	{
		for (C = Level.ControllerList; C != nullptr; C = C.nextController)
		{
			if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
			{
				TournamentUpdatePlayerStats(Cast<APlayerController>(C));
			}
		}
		DebugLog(DEBUG_Tournament, "AGP_GameTournament.NotifyRoundOver() processing for non-warmup tournament round");
		if (WholeMatchOver())
		{
			GotoState("TournamentComplete");
		}
		else
		{
			ResetRoundScores();
			if (GameReplicationInfo.bTournamentInProgress)
			{
				if (GameReplicationInfo.Teams[0].teamScore > GameReplicationInfo.Teams[1].teamScore)
				{
					sTournamentStatusMsg = GameReplicationInfo.asTournamentTeamName[0] + " team leads the tournament " + FString::FromInt(GameReplicationInfo.Teams[0].teamScore) + " to " + FString::FromInt(GameReplicationInfo.Teams[1].teamScore) + ".";
				}
				else
				{
					if (GameReplicationInfo.Teams[0].teamScore == GameReplicationInfo.Teams[1].teamScore)
					{
						sTournamentStatusMsg = "The tournament is currently tied.";
					}
					else
					{
						sTournamentStatusMsg = GameReplicationInfo.asTournamentTeamName[1] + " team leads the tournament " + FString::FromInt(GameReplicationInfo.Teams[1].teamScore) + " to " + FString::FromInt(GameReplicationInfo.Teams[0].teamScore) + ".";
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
	AUpdateTournamentResultsRequestAd* Adapter = nullptr;
	FString sAdminList = "";
	int32 iPlayerIndex = 0;
	FString ServerIP = "";
	/*
	DebugLog(DEBUG_Auth,"AGP_GameTournament::TournamentTransmitResultsToAuthServer() - Initiating tournament results transmission...");
	for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
	{
		if(Len(asTournamentAdministrators[iPlayerIndex]) > 0)
		{
			sAdminList=sAdminList + asTournamentAdministrators[iPlayerIndex] + ";";
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
	if(UDBAuth::StaticClass().Default.GameServerIP != "")
	{
		ServerIP=UDBAuth::StaticClass().Default.GameServerIP;
	}
	else
	{
		ServerIP=AInternetLink::StaticClass().GetLocalIPAsString();
	}
	Adapter.Request(sLeagueName,sTournamentName,sMatchName,attrTournamentFinalResults[0].sTeamName,attrTournamentFinalResults[1].sTeamName,attrTournamentFinalResults[0].iTotalWins,attrTournamentFinalResults[1].iTotalWins,attrTournamentFinalResults[0].iTotalScore,attrTournamentFinalResults[1].iTotalScore,GameReplicationInfo.ServerName,Level.GetLevelName(),sAdminList,iTournamentMaxRounds,iTotalRoundsPlayed,iTournamentRoundTime,ServerIP);
	DebugLog(DEBUG_Auth,"AGP_GameTournament::TournamentTransmitResultsToAuthServer() - Sent to Auth Server");
	*/
}

void AAGP_GameTournament::TournamentResultsAuthCallback(int32 iResultCode)
{
	//DebugLog(DEBUG_Auth,"AGP_GameTournament::TournamentResultsAuthCallback() - Result: " + iResultCode);
}

int32 AAGP_GameTournament::TournamentGetConnectedPlayerCount()
{
	AController* C = nullptr;
	int32 iPlayersStillConnected = 0;
	iPlayersStillConnected = 0;
	/*
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (C->IsA(AHumanController::StaticClass()) && Cast<AHumanController>(C).bPBChecked)
		{
			iPlayersStillConnected++;
		}
	}
	*/
	return iPlayersStillConnected;
}

int32 AAGP_GameTournament::TournamentGetConnectedTeam(int32 iTeamIndex)
{
	AController* C = nullptr;
	int32 iPlayersStillConnected = 0;
	iPlayersStillConnected = 0;
	/*
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (Cast<APlayerController>(C) != nullptr)
		{
			if (Cast<APlayerController>(C).PlayerReplicationInfo.Team.TeamIndex == iTeamIndex)
			{
				iPlayersStillConnected++;
				DebugLog(DEBUG_Tournament, "AGP_GAmeTournament.TournamentGetConnectedTeam(" + FString::FromInt(iTeamIndex) + ") players found so far: " + FString::FromInt(iPlayersStillConnected));
			}
		}
	}
	*/
	return iPlayersStillConnected;

}
void AAGP_GameTournament::ShowCountDown(int32 iTimerLeft, FString sTimerType)
{
	FString TournamentTimeMessage = "";
	int32 TournamentTimeCounter = 0;
	int32 TournamentTimeMinutes = 0;
	int32 TournamentTimeSeconds = 0;
	AController* C = nullptr;
	TournamentTimeCounter = iTimerLeft;
	TournamentTimeMinutes = (TournamentTimeCounter / 60);
	/*
	TournamentTimeSeconds = int((float(TournamentTimeCounter) % float(60)));
	if (TournamentTimeCounter >= 0)
	{
		if ((TournamentTimeMinutes >= 1) && ((TournamentTimeSeconds == 30) || (TournamentTimeSeconds == 0)))
		{
			if (TournamentTimeSeconds == 30)
			{
				if (TournamentTimeMinutes == 1)
				{
					TournamentTimeMessage = FString::FromInt(TournamentTimeMinutes) + " minute " + FString::FromInt(TournamentTimeSeconds) + " seconds until " + sTimerType + ".";
				}
				else
				{
					TournamentTimeMessage = FString::FromInt(TournamentTimeMinutes) + " minutes " + FString::FromInt(TournamentTimeSeconds) + " seconds until " + sTimerType + ".";
				}
			}
			else
			{
				if (TournamentTimeSeconds == 0)
				{
					if (TournamentTimeMinutes == 1)
					{
						TournamentTimeMessage = "one minute until " + sTimerType + ".";
					}
					else
					{
						TournamentTimeMessage = FString::FromInt(TournamentTimeMinutes) + " minutes until " + sTimerType + ".";
					}
				}
			}
		}
		else
		{
			if ((TournamentTimeSeconds == 30) && (TournamentTimeMinutes < 1))
			{
				TournamentTimeMessage = FString::FromInt(TournamentTimeSeconds) + " seconds until " + sTimerType + ".";
			}
			else
			{
				if (((TournamentTimeSeconds <= 15) && (TournamentTimeSeconds > 0)) && (TournamentTimeMinutes < 1))
				{
					TournamentTimeMessage = "" + sTimerType + " in: " + FString::FromInt(TournamentTimeSeconds);
				}
				else
				{
					if ((TournamentTimeSeconds == 0) && (TournamentTimeMinutes < 1))
					{
						TournamentTimeMessage = sTimerType;
					}
				}
			}
		}
		if (TournamentTimeMessage != "")
		{
			for (C = Level.ControllerList; C != nullptr; C = C.nextController)
			{
				if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
				{
					Cast<AHumanController>(C).NotifyAdminMessage(TournamentTimeMessage);
				}
			}
		}
	}
	*/
}

void AAGP_GameTournament::PendingEndGame(AAA2_PlayerState* Winner, FString Reason, int32 _EndTime)
{
	/*
	DebugLog(DEBUG_Tournament,"AGP_GameTournament.PendingEndGame() - Reason: " + Reason);
	if(bFirstRunAfterWarmup || bTournamentWarmupStarted)
	{
		Reason="EndWarmup";
	}
	PendingEndGame(Winner,Reason,_EndTime);
	*/
}

void AAGP_GameTournament::EndGame(AAA2_PlayerState* Winner, FString Reason)
{
	AController* C = nullptr;
	APlayerController* Player = nullptr;
	/*
	DebugLog(DEBUG_Tournament, "AGP_GameTournament.EndGame() entered for reason: " + Reason);
	TournamentResetTeamCaptainsReadyFlag();
	if (bCurrentRoundIsDead)
	{
		bGameEnded = true;
		TriggerEvent("EndGame", this, nullptr);
		EndLogging(Reason);
		for (C = Level.ControllerList; C != nullptr; C = C.nextController)
		{
			if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
			{
				Player = Cast<APlayerController>(C);
				Player.ClientSetBehindView(true);
				Player.SetViewTarget(Level.ViewpointList);
				Player.ClientSetViewTarget(Level.ViewpointList);
				Cast<AHumanController>(Player).TournamentWarmupClientGameEnded();
			}
		}
		GotoState("MatchOver");
		return;
	}
	if (bTournamentWarmupStarted)
	{
		TournamentSendMessage("The tournament begins at the start of the next game.");
	}
	else
	{
		iTotalRoundsPlayed++;
		Super::EndGame(Winner, Reason);
	}
	bGameEnded = true;
	TriggerEvent("EndGame", this, nullptr);
	EndLogging(Reason);
	if (bTournamentSwapPending)
	{
		DebugLog(DEBUG_Tournament, "AGP_GameTournament::EndGame() Swapping sides now");
		SwapSides();
		return;
	}
	if (!CheckEndGame(Winner, Reason))
	{
		bOverTime = true;
		return;
	}
	if (bTournamentPausePending)
	{
		bGameEnded = false;
		DebugLog(DEBUG_Tournament, "AGP_GameTournament::EndGame() Pausing tournament");
		TournamentPause();
		return;
	}
	GotoState("MatchOver");
	*/
}

bool AAGP_GameTournament::GiveCredit_Wins()
{
	if(bTournamentWarmupStarted)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void AAGP_GameTournament::NotifyIdlePlayerRounds(AController* C, int32 nIdleRounds, bool bMessage)
{
}

bool AAGP_GameTournament::WholeMatchOver()
{
	bool bResult = false;
	int32 iWinDelta = 0;
	/*
	if(TournamentGetConnectedTeam(0) == 0 && TournamentGetConnectedTeam(1) == 0)
	{
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.WholeMatchOver() - Both teams left");
		sWinningTeamName="";
		sWinningReason=" because both teams quit";
		GameReplicationInfo.Teams[0].teamScore=0;
		GameReplicationInfo.Teams[1].teamScore=0;
		aiTournamentTeamScores[0]=0;
		aiTournamentTeamScores[1]=0;
		return true;
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
			return true;
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
			return true;
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
		bTournamentStatisticallyOver=true;
		bResult=true;
	}
	else
	{
		bResult=WholeMatchOver();
	}
	if(bResult)
	{
		DebugLog(DEBUG_Tournament,"AGP_GameTournament.WholeMatchOver() - Scores: " + GameReplicationInfo.Teams[0].teamScore + " and " + GameReplicationInfo.Teams[1].teamScore);
		if(GameReplicationInfo.Teams[0].teamScore == GameReplicationInfo.Teams[1].teamScore)
		{
			if(! bTournamentTieSuddenDeath && ! bTournamentTieScore)
			{
				sWinningTeamName="";
				sWinningReason="";
				aiTournamentTeamScores[0]=AGP_TeamInfo(GameReplicationInfo.Teams[0]).GetTotalScore();
				aiTournamentTeamScores[1]=AGP_TeamInfo(GameReplicationInfo.Teams[1]).GetTotalScore();
				return true;
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
						return true;
					}
					else
					{
						sWinningTeamName="";
						sWinningReason="(total team scores were tied)";
						return true;
					}
				}
				RoundsPerMatch ++;
				GameReplicationInfo.RoundsPerMatch ++;
				GameReplicationInfo.RemainingRounds ++;
				bTournamentSwapPending=true;
				iLastRoundSwappedOn=-1;
				DebugLog(DEBUG_Tournament,"AGP_GameTournament::WholeMatchOver() - Going to sudden death");
				bTournamentSuddenDeath=true;
				return false;
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
	*/
	return bResult;
}

void AAGP_GameTournament::TournamentSendMessage(FString S)
{
	//BroadcastHandler.Broadcast(this,S,'TMStatus');
	TournamentSendCenteredMessage(S);
}

void AAGP_GameTournament::TournamentSendCenteredMessage(FString sMsg)
{
	AController* C = nullptr;
	/*
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
		{
			Cast<AHumanController>(C).NotifyAdminMessage(sMsg);
		}
	}
	*/
}

void AAGP_GameTournament::TournamentSendTeamCaptainOnlyMessage(FString sMsg)
{
	AController* C = nullptr;
	/*
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
		{
			if (C.PlayerReplicationInfo.bTournamentTeamCaptain || C.PlayerReplicationInfo.Administrator())
			{
				Cast<AHumanController>(C).TournamentCaptainAdminMessage(sMsg);
			}
		}
	}
	*/
}

void AAGP_GameTournament::TournamentSendNonTeamCaptainMessages(FString sMsg)
{
	AController* C = nullptr;
	/*
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
		{
			if ((!C.PlayerReplicationInfo.bTournamentTeamCaptain) && (!C.PlayerReplicationInfo.Administrator()))
			{
				Cast<AHumanController>(C).NotifyAdminMessage(sMsg);
			}
		}
	}
	*/
}

int32 AAGP_GameTournament::TournamentGetMaxTeamSize()
{
	return MaxTeamSize;
}

int32 AAGP_GameTournament::TournamentStatHelperFindPlayerIndex(APlayerController* PC)
{
	int32 iPlayerIndex = 0;
	/*
	for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
	{
		if(PC.PlayerReplicationInfo.PlayerName == atpsTournamentPlayerStats[iPlayerIndex].sPlayerName)
		{
			return iPlayerIndex;
		}
	}
	*/
	return -1;
}

void AAGP_GameTournament::TournamentUpdatePlayerStats(APlayerController* PC)
{
	int32 iPlayerIndex = 0;
	/*
	if(PC.PlayerReplicationInfo.Team.TeamIndex == 255)
	{
		return;
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
			return;
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
	FString sResults = "";
	FString sPlayerInfo = "";
	FString sTieRules = "";
	int32 iTeamIndex = 0;
	int32 iPlayerIndex = 0;
	FString sPath = "";
	FString Message = "";
	/*
	iTotalRoundsTied=GameReplicationInfo.RoundsPerMatch - GameReplicationInfo.Teams[0].teamScore + GameReplicationInfo.Teams[1].teamScore;
	if(HC == nullptr)
	{
		sPath=GetBaseDir() + "\TournamentResults\";
		CreateDir(sPath);
		DebugLog(DEBUG_Tournament,"AGP_GameTournament::TournamentGenerateResults() - Creating tournament results file " + sBaseFileName);
		if(! FOpenWrite(sPath + sBaseFileName))
		{
			return;
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
	TournamentWriteResults(HC,Chr(13) + Chr(10) + "[Statistics]" + Chr(13) + Chr(10));
	if(Len(sWinningTeamName) > 0)
	{
		TournamentWriteResults(HC,"OverallWinner=" + sWinningTeamName + Chr(13) + Chr(10));
	}
	else
	{
		TournamentWriteResults(HC,"" + Chr(13) + Chr(10));
	}
	TournamentWriteResults(HC,"Team0Name=" + attrTournamentFinalResults[0].sTeamName + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"Team1Name=" + attrTournamentFinalResults[1].sTeamName + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"Team0Wins=" + attrTournamentFinalResults[0].iTotalWins + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"Team1Wins=" + attrTournamentFinalResults[1].iTotalWins + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"Ties=" + iTotalRoundsTied + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"TotalTeam0Score=" + attrTournamentFinalResults[0].iTotalScore + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"TotalTeam1Score=" + attrTournamentFinalResults[1].iTotalScore + Chr(13) + Chr(10));
	for(iTeamIndex=0; iTeamIndex<2; iTeamIndex++)
	{
		TournamentWriteResults(HC,Chr(13) + Chr(10) + "[Team" + iTeamIndex + "PlayerList]" + Chr(13) + Chr(10));
		for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
		{
			if(atpsTournamentPlayerStats[iPlayerIndex].sTeamName == attrTournamentFinalResults[iTeamIndex].sTeamName)
			{
				sPlayerInfo="Player=""" + atpsTournamentPlayerStats[iPlayerIndex].sPlayerName + """," + atpsTournamentPlayerStats[iPlayerIndex].iKills;
				sPlayerInfo=sPlayerInfo + "," + atpsTournamentPlayerStats[iPlayerIndex].iDeaths + "," + atpsTournamentPlayerStats[iPlayerIndex].iGoalPoints;
				sPlayerInfo=sPlayerInfo + "," + atpsTournamentPlayerStats[iPlayerIndex].iLeaderPoints + "," + atpsTournamentPlayerStats[iPlayerIndex].iROE;
				sPlayerInfo=sPlayerInfo + "," + atpsTournamentPlayerStats[iPlayerIndex].iRoundsPlayed + "," + atpsTournamentPlayerStats[iPlayerIndex].iTotalScore;
				TournamentWriteResults(HC,sPlayerInfo + Chr(13) + Chr(10));
			}
		}
	}
	TournamentWriteResults(HC,Chr(13) + Chr(10) + "[Spectators]" + Chr(13) + Chr(10));
	for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
	{
		if(Len(asTournamentSpectators[iPlayerIndex]) > 0)
		{
			TournamentWriteResults(HC,"Spectator=" + asTournamentSpectators[iPlayerIndex] + Chr(13) + Chr(10));
		}
	}
	TournamentWriteResults(HC,Chr(13) + Chr(10) + "[Administrators]" + Chr(13) + Chr(10));
	for(iPlayerIndex=0; iPlayerIndex<32; iPlayerIndex++)
	{
		if(Len(asTournamentAdministrators[iPlayerIndex]) > 0)
		{
			TournamentWriteResults(HC,"Administrator=" + asTournamentAdministrators[iPlayerIndex] + Chr(13) + Chr(10));
		}
	}
	TournamentWriteResults(HC,Chr(13) + Chr(10) + "[Rules]" + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"ServerName=" + GameReplicationInfo.ServerName + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"Map=" + Level.GetLevelName() + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"TournamentRounds=" + iTournamentMaxRounds + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"RoundLength=" + iTournamentRoundTime + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"WarmupTime=" + iTournamentWarmupDuration + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"SwapLimit=" + iTournamentSwapLimit + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"SwapTime=" + iTournamentSwapTime + Chr(13) + Chr(10));
	if(Level.GRI.bForceShadowsOff)
	{
		TournamentWriteResults(HC,"PlayerShadowsAllowed=False" + Chr(13) + Chr(10));
	}
	else
	{
		TournamentWriteResults(HC,"PlayerShadowsAllowed=True" + Chr(13) + Chr(10));
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
	TournamentWriteResults(HC,"TieRules=" + sTieRules + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"RequestTime=" + iTournamentRequestDelayTime + Chr(13) + Chr(10));
	if(Len(AccessControl.asTeamPasswords[0]) > 0 || Len(AccessControl.asTeamPasswords[1]) > 0)
	{
		TournamentWriteResults(HC,"TeamPasswordsUsed=Yes" + Chr(13) + Chr(10));
	}
	else
	{
		TournamentWriteResults(HC,"TeamPasswordsUsed=No" + Chr(13) + Chr(10));
	}
	TournamentWriteResults(HC,"TeamCaptainsAllowed=" + bTournamentTeamCaptainsAllowed + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"PBEnabled=" + Level.PBIsEnabled() + Chr(13) + Chr(10));
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
	TournamentWriteResults(HC,"SpectatorRules=" + sResults + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"AllWeaponSlotsOpen=" + bTournamentOpenAllWeaponClassSlots + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"DeathMessagesShown=" + bDeathMessages + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"HUDHideAmmoCount=" + GameReplicationInfo.bHUDHideAmmoCount + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"HUDHideWeaponStatus=" + GameReplicationInfo.bHUDHideWeaponStatus + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"HUDHideWeapon=" + GameReplicationInfo.bHUDHideWeapon + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"HUDHideGrenades=" + GameReplicationInfo.bHUDHideGrenades + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"HUDHideHealth=" + GameReplicationInfo.bHUDHideHealth + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"HUDHideCombatEffect=" + GameReplicationInfo.bHUDHideCombatEffect + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"HUDHideOptics=" + GameReplicationInfo.bHUDHideOptics + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"HUDHideCompass=" + GameReplicationInfo.bHUDHideCompass + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"HUDHideTimerDisplayed=" + GameReplicationInfo.bHUDHideTimer + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"HUDHideObjectives=" + GameReplicationInfo.bHUDHideObjectives + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"HUDHideRadar=" + GameReplicationInfo.bHUDHideRadar + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"ServerRegion=" + GameReplicationInfo.ServerRegion + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"MinHonor=" + MinHonor + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"MaxHonor=" + MaxHonor + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"MaxPlayers=" + MaxPlayers + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"MaxAdmins=" + MaxAdmins + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"MaxSpectators=" + MaxSpectators + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"RoundDelayTime=" + iTournamentRoundDelayTime + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"ServerPort=" + GetServerPort() + Chr(13) + Chr(10));
	DebugLog(DEBUG_Auth,"IP Address retrieved: " + AInternetLink::StaticClass().GetLocalIPAsString());
	TournamentWriteResults(HC,"ServerIP=" + AInternetLink::StaticClass().GetLocalIPAsString() + Chr(13) + Chr(10));
	switch(ScoreMode)
	{
		case 0:
		TournamentWriteResults(HC,"ScoreMode=SSM_On" + Chr(13) + Chr(10));
		break;
		case 1:
		TournamentWriteResults(HC,"ScoreMode=SSM_Off" + Chr(13) + Chr(10));
		break;
		case 2:
		TournamentWriteResults(HC,"ScoreMode=SSM_Round" + Chr(13) + Chr(10));
		break;
		case 3:
		TournamentWriteResults(HC,"ScoreMode=SSM_Match" + Chr(13) + Chr(10));
		break;
		default:
	}
	TournamentWriteResults(HC,"MOTD1=" + GameReplicationInfo.MOTDLine1 + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"MOTD2=" + GameReplicationInfo.MOTDLine2 + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"MOTD3=" + GameReplicationInfo.MOTDLine3 + Chr(13) + Chr(10));
	TournamentWriteResults(HC,"MOTD4=" + GameReplicationInfo.MOTDLine4 + Chr(13) + Chr(10));
	if(HC == nullptr)
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
	attrTournamentFinalResults[iTeamIndex].iTotalLosses=iTotalRoundsPlayed - iTotalRoundsTied - Cast<AGP_TeamInfo>(GameReplicationInfo.Teams[iTeamIndex]).teamScore;
	*/
}
void AAGP_GameTournament::TournamentWriteResults(AHumanController* HC, FString sText)
{
	/*
	if(HC == nullptr)
	{
		FWrite(sText);
	}
	else
	{
		HC.TournamentWriteResultsFile(sText);
	}
	*/
}

bool AAGP_GameTournament::TournamentIsDeadRound()
{
	return bCurrentRoundIsDead;
}

void AAGP_GameTournament::TournamentRequestDeadRound()
{
	AController* C = nullptr;
	/*
	GameReplicationInfo.sTournamentState = "Non-Scoring Round";
	TournamentSendMessage("The team captains or administrator has changed this round to a \"Non-Scoring\" round.");
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked)
		{
			Cast<APlayerController>(C).bSuperGodMode = true;
			Cast<APlayerController>(C).bGodMode = true;
		}
	}
	*/
	bCurrentRoundIsDead = true;
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
	AAGP_Objective* agpobj = nullptr;
	/*
	ForEach DynamicActors(AAGP_Objective::StaticClass(),agpobj)
	{
		Log("Found objective, disabling it: " + agpobj);
		agpobj.bDisabled=true;
	}
	*/
}
