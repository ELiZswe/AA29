// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameDeathMatch/AGP_GameDeathMatch.h"
#include "AA29/AA2_GameState.h"
#include "AA29/Object/Actor/Keypoint/AGP_Viewpoint/AGP_Viewpoint.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/NPCAICombatController/NPCAICombatController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/CommunicationRequestAdapter.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Parachute/Attch_Parachute.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/FixedWeapon/FixedWeapon.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/NPC_Ambient/NPC_Ambient.h"
#include "AA29/Object/Actor/Projectile/Projectile.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/ThrowWeapon.h"
#include "Particles/Emitter.h"

AAGP_GameDeathMatch::AAGP_GameDeathMatch()
{
	bPlayersMustBeReady = true;
	MinNetPlayers = 1;
	NetWait = 4;
	bInitialMatch = true;
	InitialWarmupTime = 30;
	RoundsPerMatch = 8;
	MatchesBeforeCycle = 1;
	bKickIdlePlayersRounds = true;
	IdlePlayerKickRounds = 10;
	CountDown = 3;
	RestartWait = 5;
}

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
	Function Timer()
	{
		AController* p = nullptr;
		bool bReady = false;
		bool bAnyReady0 = false;
		bool bAnyReady1 = false;
		bool bAnyReadyCondition = false;
		APlayerReplicationInfo* PRI = nullptr;
		Super::Timer();
		if (bInitialMatch && (ElapsedTime < InitialWarmupTime))
		{
			ElapsedTime ++;
			return;
		}
		bInitialMatch=false;
		if (bWaitForNetPlayers)
		{
			if (NumPlayers > 0)
			{
				ElapsedTime ++;
			}
			else
			{
				ElapsedTime=0;
			}
			if ((NumPlayers == MaxPlayers) || ((ElapsedTime > NetWait) && (NumPlayers >= MinNetPlayers)))
			{
				bWaitForNetPlayers=false;
				CountDown=Default.CountDown;
				ElapsedTime=0;
			}
		}
		if (bWaitForNetPlayers)
		{
			return;
		}
		SetStartupStage(4);
		bReady=true;
		if (bPlayersMustBeReady || (GetWorld()->GetNetMode() == NM_Standalone))
		{
			for (p=Level.ControllerList; p!=nullptr; p=p.nextController)
			{
				if (p->IsA(AaAIController::StaticClass()))
				{
				}
				PRI=p.PlayerReplicationInfo;
				if ((p.IsInState("ValidatePB") || p.IsInState("ServerAuthorizePlayer")) || p.IsInState("FailedAuthorization"))
				{
				}
				if (p->IsA(APlayerController::StaticClass()) && (PRI != nullptr))
				{
					if (PRI.bReadyToPlay)
					{
						if (IsTeamGame())
						{
							if (PRI.DesiredTeam == 0)
							{
								bAnyReady0=true;
							}
							else
							{
								if (PRI.DesiredTeam == 1)
								{
									bAnyReady1=true;
								}
							}
						}
						else
						{
							bAnyReadyCondition=true;
						}
					}
					else
					{
						bReady=false;
						DebugLog(DEBUG_Multi,"AGP_GameDeathMatch::PendingMatch::Timer()	Player " + FString::FromInt(p) + " is not ready to begin the match");
					}
				}
			}
			if (IsTeamGame())
			{
				if (MinNetPlayers > 1)
				{
					if (Level.bCoOpGame)
					{
						bAnyReadyCondition=bAnyReady0;
					}
					else
					{
						bAnyReadyCondition=(bAnyReady0 && bAnyReady1);
					}
				}
				else
				{
					bAnyReadyCondition=(bAnyReady0 || bAnyReady1);
				}
				DebugLog(DEBUG_Multi,"AGP_GDM::PendingMatch::Timer()	" + FString::FromInt(bReady) @ FString::FromInt(bAnyReadyCondition) @ FString::FromInt(bAnyReady0) @ FString::FromInt(bAnyReady1));
			}
			if (bAnyReadyCondition)
			{
				ElapsedTime ++;
				if (ElapsedTime > (NetWait * 2))
				{
					bReady=true;
				}
			}
			else
			{
				ElapsedTime=0;
				bReady=false;
			}
		}
		if (bReady)
		{
			bReady=ConfirmReady();
		}
		if ((! bReady) && (StartupStage == 5))
		{
			if (Level.ControllerList == nullptr)
			{
				Reset();
			}
			else
			{
				DebugLog(DEBUG_Multi,"AGP_GameDeathMatch::PendingMatch::Timer()	Forcing Match Start");
				bReady=true;
			}
		}
		if (bReady)
		{
			if (CountDown == Default.CountDown)
			{
				SetStartupStage(5);
			}
			CountDown --;
			if (CountDown == 1)
			{
				CompleteEndGame();
			}
			if (CountDown <= 0)
			{
				StartMatch();
			}
		}
	}
	Function EndState()
	{
		DebugLog(DEBUG_Multi,"AGP_GameDeathMatch.PendingMatch.EndState() entered");
		if (WholeMatchOver())
		{
			ResetMatchScores();
		}
		ResetRoundScores();
		UpdateAllClientsScoreMode();
		UpdateScoreboardVisibility();
	}
}
*/

/*
State DelayedMatchInProgress
{
	Function BeginState()
	{
		AController* ctrlIterator = nullptr;
		SetStartupStage(6);
		StartMatch();
		GameReplicationInfo.RemainingTime=iDelayedRoundStartTimeSeconds;
		for (ctrlIterator=Level.ControllerList; ctrlIterator!=nullptr; ctrlIterator=ctrlIterator.nextController)
		{
			if ((Cast<AHumanController>(ctrlIterator) != nullptr) && (Cast<AHumanController>(ctrlIterator).Pawn != nullptr))
			{
				Cast<AHumanController>(ctrlIterator).GotoState("DelayedStart","None");
				Cast<AHumanController>(ctrlIterator).ClientMessage("Mission Preparation Period.  Check your gear while you wait for the 'Move Out' order in " + FString::FromInt(iDelayedRoundStartTimeSeconds) + " seconds.");
				if (IsTournamentMode())
				{
					Cast<AHumanController>(ctrlIterator).ClientCloseMenu(true,true);
				}
				else
				{
					Cast<AHumanController>(ctrlIterator).ClientCloseMenu(false,true);
				}
			}
		}
		GameReplicationInfo.iDelayedStartTimeRemaining=iDelayedRoundStartTimeSeconds;
		SetTimer(1,true);
	}
	Function Timer()
	{
		if (GameReplicationInfo.iDelayedStartTimeRemaining -- <= 0)
		{
			SetCustomTimer(0,false,"DelayedStartCountdownTimer");
			GotoState("MatchInProgress");
		}
		else
		{
			GameReplicationInfo.RemainingTime --;
		}
	}
	Function EndState()
	{
		AController* ctrlIterator = nullptr;
		Broadcast(this," ");
		Broadcast(this,"--- Mission Starting ---");
		Broadcast(this," ");
		for (ctrlIterator=Level.ControllerList; ctrlIterator!=nullptr; ctrlIterator=ctrlIterator.nextController)
		{
			if (Cast<AHumanController>(ctrlIterator) != nullptr)
			{
				Cast<AHumanController>(ctrlIterator).LockPlayer(false,false);
			}
		}
	}
}
*/

/*
State MatchInProgress
{
	Function Timer()
	{
		AController* C = nullptr;
		APlayerController* PC = nullptr;
		Super::Timer();
		if (bPendingEnd)
		{
			if (pendingEndTime == 0)
			{
				DebugLog(DEBUG_Multi,"AGP_GameDeathMatch::MatchInProgress{}::Timer()	Calling EndGame");
				if ((pendingReason == "TeamDead") && (pendingWinner != nullptr))
				{
					if ((Cast<AAGP_TeamInfo>(pendingWinner.Team) != nullptr) && Cast<AGP_TeamInfo>(pendingWinner.Team).TeamDead())
					{
						pendingWinner=nullptr;
					}
				}
				EndGame(pendingWinner,pendingReason);
				pendingEndTime=-1;
			}
			else
			{
				pendingEndTime --;
				RemainingTime --;
				if (RemainingTime <= 0)
				{
					RemainingTime=0;
				}
				GameReplicationInfo.ElapsedTime=ElapsedTime;
				DebugLog(DEBUG_Multi,"AGP_GameDeathMatch::MatchInProgress{}::Timer()	The game will end in " + FString::FromInt(pendingEndTime));
			}
		}
		else
		{
			if ((! bRunOverTime) && (TimeLimit > 0))
			{
				GameReplicationInfo.bStopCountDown=false;
				if (! GameReplicationInfo.bRoundIsSuspended)
				{
					RemainingTime --;
					GameReplicationInfo.RemainingTime=RemainingTime;
					if ((float(RemainingTime) % float(60)) == 0)
					{
						GameReplicationInfo.RemainingMinute=RemainingTime;
					}
					if (RemainingTime <= 0)
					{
						EndGame(nullptr,"TimeLimit");
					}
				}
				else
				{
					if (GameReplicationInfo.SecsTillRoundResume > 0)
					{
						GameReplicationInfo.SecsTillRoundResume -= 1;
						if (GameReplicationInfo.SecsTillRoundResume > 0)
						{
							for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
							{
								PC=Cast<APlayerController>(C);
								if (PC != nullptr)
								{
									PC.ClientMessage("The round will resume in " + FString::FromInt(GameReplicationInfo.SecsTillRoundResume) + " seconds");
								}
							}
						}
						else
						{
							for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
							{
								PC=Cast<APlayerController>(C);
								if (PC != nullptr)
								{
									PC.ClientMessage("The round has resumed!");
								}
							}
							GameReplicationInfo.bRoundIsSuspended=false;
						}
					}
				}
			}
			else
			{
				ElapsedTime ++;
				GameReplicationInfo.ElapsedTime=ElapsedTime;
			}
		}
	}
	Function bool NotifyIdlePlayer(AController* C, float LastMovedTime)
	{
		float IdleTime = 0;
		float IdleLimit = 0;
		bool bSpectator = false;
		bSpectator=C.PlayerReplicationInfo.isDead();
		if (((! bSpectator) && bKickIdlePlayersTimed) || (bSpectator && bKickIdleSpectators))
		{
			IdleTime=(GetWorld()->GetTimeSeconds() - LastMovedTime);
			IdleLimit=float((IdlePlayerKickTime * 60));
			if (IdleTime > IdleLimit)
			{
				Kick(C.PlayerReplicationInfo.PlayerName,"IdleTime");
			}
			else
			{
				if (IdleTime > (IdleLimit - float(20)))
				{
					Cast<AHumanController>(C).NotifyImpendingIdleKick();
					return true;
				}
			}
		}
		return false;
	}
	Function bool TestForIdlePlayers(APlayerReplicationInfo* PRI)
	{
		if (PRI.isDead())
		{
			return bKickIdleSpectators;
		}
		else
		{
			return bKickIdlePlayersTimed;
		}
	}
	Function BeginState()
	{
		APlayerController* PC = nullptr;
		EndVote();
		bPendingEnd=false;
		pendingEndTime=-1;
		if (RoundsPerMatch > 0)
		{
			GameReplicationInfo.RemainingRounds --;
		}
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			ForEach DynamicActors(Class'PlayerController',PC)
			{
				if (IsTournamentMode())
				{
					PC.ClientCloseMenu(true,true);
				}
				else
				{
					PC.ClientCloseMenu(false,true);
					PC.OpenDemoControls();
				}
			}
		}
	}
	Function PendingEndGame(APlayerReplicationInfo* Winner, FString Reason, int32 EndTime)
	{
		pendingWinner=Winner;
		pendingReason=Reason;
		pendingEndTime=EndTime;
		if (pendingEndTime == 0)
		{
			DebugLog(DEBUG_Multi,"AGP_GameDeathMatch::MatchInProgress::PendingEndGame() ");
			if (Level.IsMILES())
			{
				pendingEndTime=6;
			}
			else
			{
				pendingEndTime=3;
			}
		}
		bPendingEnd=true;
		DebugLog(DEBUG_Multi,"AGP_GameDeathMatch()	The game will end in " + FString::FromInt(pendingEndTime));
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
	Function bool WaitForEndOfMatch()
	{
		if (WholeMatchOver() && (ElapsedTime != -1))
		{
			if (ElapsedTime == 5)
			{
				if ((GameReplicationInfo.MatchesBeforeCycle > 0) || (! bCycleMaps))
				{
					OpenWeaponClass();
				}
			}
			if (ElapsedTime < 5)
			{
				if (ElapsedTime == 0)
				{
					GameReplicationInfo.MatchesBeforeCycle --;
				}
				ElapsedTime ++;
				return true;
			}
			else
			{
				ElapsedTime=-1;
				EndTime=GetWorld()->GetTimeSeconds();
				return false;
			}
		}
		return false;
	}
	Function BeginState()
	{
		StopNPCControllers();
		GameReplicationInfo.bStopCountDown=true;
		SetStartupStage(10);
		ElapsedTime=0;
		RemainingTime=0;
		bScoresShownForRound=false;
		GameReplicationInfo.RemainingMinute=0;
		if ((GameReplicationInfo.Teams[0].CheckIf_NoEnemy() || ((! Level.bCoOpGame) && GameReplicationInfo.Teams[1].CheckIf_NoEnemy())) || GameReplicationInfo.Teams[0].CheckIf_SmallGame())
		{
			iDelayTimeForScoreboard=3;
		}
		else
		{
			iDelayTimeForScoreboard=0;
		}
		NotifyRoundOver();
		if (WholeMatchOver() || (ServerAuthFailures != 0))
		{
			AuthorizeServerNow();
		}
		if ((WholeMatchOver() && (Stats != nullptr)) && (Level.IsOfficialServer() || Level.IsLeasedServer()))
		{
			DebugLog(DEBUG_Stats,"Sending STS Stats.");
			DebugLog(DEBUG_Stats,"Initiating stats transmission...");
			Stats.Aggregate();
			Stats.Store();
			DebugLog(DEBUG_Stats,"Destroyng STS Stats object.");
			Stats.Destroy();
			Stats=nullptr;
		}
		else
		{
			DebugLog(DEBUG_Stats,"Not sending STS Stats Stats:" @ FString::FromInt(Stats) @ "official:" @ FString::FromInt(Level.IsOfficialServer()) @ "leased:" @ FString::FromInt(Level.IsLeasedServer()) @ "ETA:" @ FString::FromInt(Level.IsExploreTheArmyServer()));
		}
		UpdateScoreboardVisibility();
	}
	Function bool ShouldShowScores()
	{
		switch(ScoreMode)
		{
			case 3:
			return WholeMatchOver();
			case 0:
			case 2:
			return true;
			default:
			return false;
		}
	}
	Function OpenWeaponClass()
	{
		AController* C = nullptr;
		for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
		{
			if (C->IsA(AaAIController::StaticClass()))
			{
			}
			if ((C.IsInState("ValidatePB") || C.IsInState("ServerAuthorizePlayer")) || C.IsInState("FailedAuthorization"))
			{
				if (C.PlayerReplicationInfo == nullptr)
				{
					DebugLog(DEBUG_Auth,"User still authorizing, skipping end of round scoreboard showing.");
				}
				else
				{
					DebugLog(DEBUG_Auth,"User " + C.PlayerReplicationInfo.PlayerName + " still authorizing, skipping end of round scoreboard showing.");
				}
			}
			else
			{
				if (C->IsA(APlayerController::StaticClass()) && ((Cast<AHumanController>(C) != nullptr) && Cast<AHumanController>(C).bPBChecked))
				{
					Cast<APlayerController>(C).ClientCloseMenu(false,true);
					Cast<APlayerController>(C).ClientOpenMenu("AGP_Interface.AAGameMenu",,"Weapon Class","EnableScores");
				}
			}
		}
	}
	Function Timer()
	{
		FString sRotationMsg = "";
		AController* C = nullptr;
		Timer();
		if (GetWorld()->GetTimeSeconds() < (EndTime + float(iDelayTimeForScoreboard)))
		{
			return;
		}
		if (WaitForEndOfMatch())
		{
			return;
		}
		if (ShouldShowScores() && (! bScoresShownForRound))
		{
			bScoresShownForRound=true;
			for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
			{
				if (C->IsA(AaAIController::StaticClass()))
				{
				}
				if ((C.IsInState("ValidatePB") || C.IsInState("ServerAuthorizePlayer")) || C.IsInState("FailedAuthorization"))
				{
					if (C.PlayerReplicationInfo == nullptr)
					{
						DebugLog(DEBUG_Auth,"User still authorizing, skipping end of round scoreboard showing.");
					}
					else
					{
						DebugLog(DEBUG_Auth,"User " + C.PlayerReplicationInfo.PlayerName + " still authorizing, skipping end of round scoreboard showing.");
					}
				}
				else
				{
					if (C->IsA(AHumanController::StaticClass()) && Cast<AHumanController>(C).bPBChecked)
					{
						Cast<APlayerController>(C).ClientOpenMenu("AGP_Interface.AAGameMenu",,"Score","EnableScores");
					}
				}
			}
		}
		if ((GetWorld()->GetTimeSeconds() > ((EndTime + float(iDelayTimeForScoreboard)) + float(RestartWait))) || (((GetWorld()->GetTimeSeconds() > EndTime) && bCycleMaps) && (GameReplicationInfo.MatchesBeforeCycle == 0)))
		{
			if (bCycleMaps && (GameReplicationInfo.MatchesBeforeCycle == 0))
			{
				if (! bWarningBeforeCycle)
				{
					bWarningBeforeCycle=true;
					iServerCycleWarningTime=10;
				}
				if (bWarningBeforeCycle && (iServerCycleWarningTime > 0))
				{
					for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
					{
						if (Cast<AHumanController>(C) != nullptr)
						{
							if (iServerCycleWarningTime == 10)
							{
								Cast<AHumanController>(C).ClientCloseMenu(true);
							}
							sRotationMsg="The server is changing maps in " + FString::FromInt(iServerCycleWarningTime) + " second";
							if (iServerCycleWarningTime > 1)
							{
								sRotationMsg=sRotationMsg + "s.";
							}
							else
							{
								sRotationMsg=sRotationMsg + ".";
							}
							Cast<AHumanController>(C).NotifyAdminMessage(sRotationMsg);
						}
					}
					iServerCycleWarningTime --;
					return;
				}
				for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
				{
					if (Cast<AHumanController>(C) != nullptr)
					{
						Cast<AHumanController>(C).NotifyAdminMessage("The server is now changing maps.  This may take several minutes for you to reconnect.");
					}
				}
				bChangeLevels=true;
				bInitialMatch=true;
				if (IsRequireAuthorization())
				{
					GotoState("ForceReportLogout");
				}
				else
				{
					RestartGame();
				}
			}
			else
			{
				FakeRestartGame();
			}
		}
	}
}
*/

/*
State ForceReportLogout
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
		Super::Timer();
		DebugLog(DEBUG_Auth,"ForceReportLogout.Timer() running for another: " + FString::FromInt((float(30) - (GetWorld()->GetTimeSeconds() - fReportLogoutsStartTime))) + " seconds");
		if ((GetWorld()->GetTimeSeconds() - fReportLogoutsStartTime) > float(30))
		{
			DebugLog(DEBUG_Auth,"ForceReportLogout.Timer() forcing cleanup of auth managers");
			CleanupRequestAdapters();
			fReportLogoutsStartTime=Level.RealSeconds;
			RestartGame();
		}
	}
	Function CleanupRequestAdapters()
	{
		DBAuth.CommunicationRequestAdapter* A = nullptr;
		DebugLog(DEBUG_Auth,"AGP_GameDeathMatch::ForceReportLogout::CleanupRequestAdapters() Destroying Auth Managers!");
		ForEach AllActors(ACommunicationRequestAdapter::StaticClass(),A)
		{
			DebugLog(DEBUG_Auth,"AGP_GameDeathMatch::ForceReportLogout::CleanupRequestAdapters() " @ FString::FromInt(A));
			A.Destroy();
		}
	}
	Function NotifyReportLogoutStarted()
	{
		bNumReportLogoutsPending ++;
		DebugLog(DEBUG_Auth,"AGP_GameDeathMatch::NotifyReportLogoutStarted() - bNumReportLogoutsPending:" + FString::FromInt(bNumReportLogoutsPending));
	}
	Function NotifyReportLogoutFinished()
	{
		if (bNumReportLogoutsPending > 0)
		{
			bNumReportLogoutsPending --;
		}
		DebugLog(DEBUG_Auth,"AGP_GameDeathMatch::NotifyReportLogoutFinished() - bNumReportLogoutsPending:" + FString::FromInt(bNumReportLogoutsPending));
		if (bNumReportLogoutsPending == 0)
		{
			RestartGame();
		}
	}
	Function BeginState()
	{
		AController* C = nullptr;
		bNumReportLogoutsPending=0;
		bStopLogins=true;
		DebugLog(DEBUG_Auth,"AGP_GameDeathMatch::ForceReportLogout::BeginState() at " + FString::FromInt(GetWorld()->GetTimeSeconds()));
		for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
		{
			if (C->IsA(APlayerController::StaticClass()))
			{
				Cast<APlayerController>(C).ServerUploadTrustAndExperience(1);
			}
		}
		fReportLogoutsStartTime=GetWorld()->GetTimeSeconds();
	}
}
*/

void AAGP_GameDeathMatch::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("AAGP_GameDeathMatch::BeginPlay()"));
	Super::BeginPlay();
}

void AAGP_GameDeathMatch::InitGameReplicationInfo()
{
	/*
		InitGameReplicationInfo();
		GameReplicationInfo.TimeLimit=TimeLimit;
		UpdateScoreboardVisibility();
	*/
}

void AAGP_GameDeathMatch::PostBeginPlay()
{
	bWarningBeforeCycle=false;
	Super::PostBeginPlay();
	//GameReplicationInfo.RemainingTime=RemainingTime;
	//GameReplicationInfo.RoundsPerMatch=RoundsPerMatch;
	//GameReplicationInfo.MatchesBeforeCycle=MatchesBeforeCycle;
	ResetRemainingRounds();
	//UpdateScoreboardVisibility();
}

void AAGP_GameDeathMatch::StartMatch()
{
	
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameDeathMatch::StartMatch()"));
		/*
		if(iDelayedRoundStartTimeSeconds <= 0 || Level.bDelayedSpawnNotAllowed || Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
		{
			GameReplicationInfo.iDelayedStartTimeRemaining=0;
			if(iDelayedRoundStartTimeSeconds > 0 && Level.bDelayedSpawnNotAllowed)
			{
				Log("** Delayed spawning rules overridden by map rules");
			}
			GotoState('MatchInProgress');
			SetStartupStage(6);
			StartMatch();
			return;
		}
		if(iDelayedRoundStartTimeSeconds > 0)
		{
			Log("Beginning delayed start");
			GotoState('DelayedMatchInProgress');
		}
		else
		{
			SetStartupStage(6);
			StartMatch();
		}
	*/
}

void AAGP_GameDeathMatch::PendingEndGame(AAA2_PlayerState* Winner, FString Reason, int32 _EndTime)
{
}

bool AAGP_GameDeathMatch::CheckDontEndGame(FString Reason)
{
	//if(bGameEnded || ! IsInState('MatchInProgress') && ! IsInState('DelayedMatchInProgress'))
	if(bGameEnded)
	{
		return true;
	}
	if(bDeadGame && Reason != "CheatEndGame")
	{
		return true;
	}
	return false;
}

void AAGP_GameDeathMatch::EndGame(AAA2_PlayerState* Winner, FString Reason)
{
	if(CheckDontEndGame(Reason))
	{
		return;
	}
	EndGame(Winner,Reason);
	if(bGameEnded)
	{
		//GotoState('MatchOver');
	}
}
void AAGP_GameDeathMatch::ResetVariables()
{
	RemainingTime=TimeLimit * 60;
	if(GameReplicationInfo != nullptr)
	{
		GameReplicationInfo->RemainingMinute=RemainingTime;
	}
	bWaitForNetPlayers=GetNetMode() != ENetMode::NM_Standalone;
	bPendingEnd=false;
}

void AAGP_GameDeathMatch::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	ResetVariables();
	UpdateScoreboardVisibility();
}

void AAGP_GameDeathMatch::Reset()
{
	Super::Reset();
	ElapsedTime=NetWait - 3;
	ResetVariables();
	SetStartupStage(EStartupStage::STAGE_WaitForEnoughPlayers);
	CountDown=GetDefault<AAGP_GameDeathMatch>()->CountDown;
	//GotoState('PendingMatch');
}

bool AAGP_GameDeathMatch::CheckEndGame(AAA2_PlayerState* Winner, FString Reason)
{
	AController* p = nullptr;
	APlayerController* Player = nullptr;
	AAGP_Viewpoint* VP = nullptr;
	AVehicle* V = nullptr;
	APawn* PlayerPawn = nullptr;
	/*
	EndTime = (GetWorld()->GetTimeSeconds() + 3);
	if (Winner != nullptr)
	{
		GameReplicationInfo.Winner = Winner;
	}
	VP = GetWinningViewpoint(Winner);
	for (p = Level.ControllerList; p != nullptr; p = p.nextController)
	{
		if (p->IsA(AaAIController::StaticClass()))
		{
		}
		if (p->IsA(APlayerController::StaticClass()))
		{
			if ((((Cast<AHumanController>(p).bPBChecked && Cast<AHumanController>(p).bPlayerIsReadyToPlay) && (!p.IsInState("FailedAuthorization"))) && (!p.IsInState("ServerAuthorizePlayer"))) && (!p.IsInState("ValidatePB")))
			{
				Player = Cast<APlayerController>(p);
				PlayerPawn = Player.Pawn;
				V = Vehicle(PlayerPawn);
				if (V != nullptr)
				{
					Player.Pawn = V.Driver;
					V.UnPossessed();
					V.Driver = nullptr;
					V.Controller = nullptr;
					Player.Pawn.SetBase(nullptr);
					Player.AcknowledgedPawn = Player.Pawn;
				}
				Player.ClientSetBehindView(true);
				Player.SetViewTarget(VP);
				Player.ClientSetViewTarget(VP);
				Player.ClientGameEnded();
			}
			else
			{
				if (p.PlayerReplicationInfo != nullptr)
				{
					DebugLog(DEBUG_Auth, "AGP_GameDeathmatch::CheckEndGame() - User " + p.PlayerReplicationInfo.PlayerName + " being skipped - not authorized");
				}
				else
				{
					DebugLog(DEBUG_Auth, "AGP_GameDeathmatch::CheckEndGame() - User being skipped - not authorized");
				}
			}
		}
		else
		{
			DebugLog(DEBUG_Multi, "AGP_GameDeathMatch() - Sending client to GameEnded state");
			if (Cast<AHumanController>(p).bPlayerIsReadyToPlay)
			{
				p.GotoState("GameEnded");
			}
		}
	}
	*/
	CleanupForMatchEnd();
	return true;
}

AAGP_Viewpoint* AAGP_GameDeathMatch::GetWinningViewpoint(AAA2_PlayerState* Winner)
{
	return Cast<AAA2_WorldSettings>(GetWorldSettings())->ViewpointList;
}

bool AAGP_GameDeathMatch::ShouldShowScores()
{
	switch (ScoreMode)
	{
	case EServerScoreMode::SSM_On:
		return true;
	default:
		return false;
	}
}
void AAGP_GameDeathMatch::UpdateScoreboardVisibility()
{
	if(GameReplicationInfo != nullptr)
	{
		GameReplicationInfo->bShouldShowScoreboard=ShouldShowScores();
	}
}

bool AAGP_GameDeathMatch::SetScoreMode(FString NewScoreMode)
{
	bool bResult;
	bResult=Super::SetScoreMode(NewScoreMode);
	UpdateScoreboardVisibility();
	return bResult;
}

void AAGP_GameDeathMatch::CleanupForMatchEnd()
{
	AActor* A = nullptr;
	/*
	ForEach DynamicActors(Class'Actor',A)
	{
		if(A->IsA(APickup::StaticClass()))
		{
			A.MatchEnding();
		}
		else
		{
			if(A->IsA(AEmitter::StaticClass()))
			{
				A.MatchEnding();
			}
			else
			{
				if(A->IsA(APawn::StaticClass()) && ! A->IsA(ANPC_Ambient::StaticClass()))
				{
					A.SetDrawType(0);
				}
				else
				{
					if(A->IsA(AWeapon::StaticClass()) && ! A->IsA(AFixedWeapon::StaticClass()))
					{
						A.Destroy();
					}
					else
					{
						if(A->IsA(AThrowWeapon::StaticClass()))
						{
							A.Destroy();
						}
						else
						{
							if(A->IsA(AProjectile::StaticClass()))
							{
								A.Destroy();
							}
							else
							{
								if(A->IsA(AAttch_Parachute::StaticClass()))
								{
									A.Destroy();
								}
								else
								{
									if(A->IsA(AHumanController::StaticClass()))
									{
										Cast<AHumanController>(A).ClientSetBehindView(false);
										Cast<AHumanController>(A).IdleCheckPerRound(true);
										Cast<AHumanController>(A).CleanOutSavedMoves();
									}
								}
							}
						}
					}
				}
			}
		}
	}
	*/
}

ANavigationPoint* AAGP_GameDeathMatch::FindPlayerStart(AController* Player, uint8 InTeam, FString incomingName)
{
	ANavigationPoint* SpawnPoint = nullptr;
	/*
	UE_LOG(LogTemp, Warning, TEXT(Self + ".FindPlayerStart() - Trying to find player start"));
	SpawnPoint=FindPlayerStart(Player,InTeam,incomingName);
	UE_LOG(LogTemp, Warning, TEXT(Self + ".FindPlayerStart() - Found: " + SpawnPoint));
	if(SpawnPoint != nullptr)
	{
		LastSpawnPoint=SpawnPoint;
	}
	*/
	return SpawnPoint;
}

float AAGP_GameDeathMatch::RatePlayerStart(ANavigationPoint* N, uint8 Team, AController* Player)
{
	ANavigationPoint* LastPlayerSpawnPoint = nullptr;
	APlayerStart* p = nullptr;
	AController* C = nullptr;
	float Score = 0;
	float penalty = 0;
	float Distance = 0;
	bool bVisible = false;
	/*
	p=PlayerStart(N);
	if ((p == nullptr) || (! p.bEnabled))
	{
		return 0;
	}
	Score=p.fBaseScore;
	if ((Player != nullptr) && (Player.StartSpot != nullptr))
	{
		LastPlayerSpawnPoint=Player.StartSpot;
	}
	if ((N == LastSpawnPoint) || (N == LastPlayerSpawnPoint))
	{
		Score -= float(10);
	}
	else
	{
		Score += (float(10) * FMath::FRand());
	}
	for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
	{
		if (C->IsA(AaAIController::StaticClass()))
		{
		}
		if (C.bIsPlayer && (C.Pawn != nullptr))
		{
			Distance=VSize((C.Pawn.Location - N.Location));
			if (Distance < (C.Pawn.CollisionRadius + C.Pawn.CollisionHeight))
			{
				Score -= float(500);
			}
			else
			{
				bVisible=FastTrace(N->GetActorLocation(),C.Pawn.Location);
				penalty=0;
				if (bVisible)
				{
					penalty += 5;
				}
				if ((Distance < float(5000)) && bVisible)
				{
					penalty += (5 - (Distance / float(1000)));
				}
				if (C.Pawn.Region.Zone == N.Region.Zone)
				{
					penalty += 3;
				}
				if (IsTeamFriend(Team,C.Pawn))
				{
					Score += penalty;
				}
				else
				{
					Score -= penalty;
				}
			}
		}
	}
	*/
	return Score;
}

bool AAGP_GameDeathMatch::IsTournamentMode()
{
	return Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer() || bTournamentMode;
}
bool AAGP_GameDeathMatch::IsTeamGame()
{
	return false;
}

int32 AAGP_GameDeathMatch::GetTimeElapsed()
{
	return Cast<AAA2_GameState>(GetWorld()->GetGameState())->TimeLimit * 60 - Cast<AAA2_GameState>(GetWorld()->GetGameState())->RemainingTime;
}

int32 AAGP_GameDeathMatch::GetRoundsPerMatch()
{
	if(Cast<AAA2_GameState>(GetWorld()->GetGameState())->RoundsPerMatch > 0)
	{
		return Cast<AAA2_GameState>(GetWorld()->GetGameState())->RoundsPerMatch;
	}
	else
	{
		return -1;
	}
}
int32 AAGP_GameDeathMatch::GetMatchesBeforeCycle()
{
	if(Cast<AAA2_GameState>(GetWorld()->GetGameState())->MatchesBeforeCycle > 0)
	{
		return Cast<AAA2_GameState>(GetWorld()->GetGameState())->MatchesBeforeCycle;
	}
	else
	{
		return -1;
	}
}
bool AAGP_GameDeathMatch::WholeMatchOver()
{
	return Cast<AAA2_GameState>(GetWorld()->GetGameState())->RemainingRounds == 0;
	return false;
}

void AAGP_GameDeathMatch::ResetRemainingRounds()
{
	Cast<AAA2_GameState>(GetWorld()->GetGameState())->RemainingRounds=GetRoundsPerMatch();
}

void AAGP_GameDeathMatch::ZeroRemainingRounds()
{
	Cast<AAA2_GameState>(GetWorld()->GetGameState())->RemainingRounds=0;
}

void AAGP_GameDeathMatch::ResetMatchesBeforeCycle()
{
	Cast<AAA2_GameState>(GetWorld()->GetGameState())->MatchesBeforeCycle=GetMatchesBeforeCycle();
}

void AAGP_GameDeathMatch::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}

void AAGP_GameDeathMatch::Logout(AController* Exiting)
{
	AController* C = nullptr;
	int32 iPlayersOnServer = 0;
	Super::Logout(Exiting);
	/*
	if ((Stats != nullptr) && (Level.IsOfficialServer() || Level.IsLeasedServer()))
	{
		for (C = Level.ControllerList; C != nullptr; C = C.nextController)
		{
			if ((Cast<AHumanController>(C) != nullptr) && (C != Exiting))
			{
				iPlayersOnServer++;
			}
		}
		if (iPlayersOnServer == 0)
		{
			DebugLog(DEBUG_Stats, "Sending STS Stats after last player leaves server.");
			DebugLog(DEBUG_Stats, "Initiating stats transmission...");
			Stats.Aggregate();
			Stats.Store();
			DebugLog(DEBUG_Stats, "Destroyng STS Stats object.");
			Stats.Destroy();
			Stats = nullptr;
		}
	}
	*/
	if (NumPlayers == 0)
	{
		ResetMatchScores();
	}
}

void AAGP_GameDeathMatch::NotifyIdlePlayerRounds(AController* C, int32 nIdleRounds, bool bMessage)
{
	/*
		FString Message1;
		FString message2;
		Message1=C.PlayerReplicationInfo.PlayerName + " has been idle for " + nIdleRounds + " round";
		if(nIdleRounds > 1)
		{
			Message1=Message1 + "s";
		}
		message2="Type 'votekick " + C.PlayerReplicationInfo.PlayerName + "' to try to kick this Player now";
		if(bKickIdlePlayersRounds)
		{
			if(nIdleRounds == IdlePlayerKickRounds - 1)
			{
				Cast<AHumanController>(C).NotifyImpendingIdleKick(true);
			}
			else
			{
				if(nIdleRounds >= IdlePlayerKickRounds)
				{
					Kick(C.PlayerReplicationInfo.PlayerName,"IdleRounds");
					return;
				}
			}
			Message1=Message1 + " and will be auto-kicked after " + IdlePlayerKickRounds + " rounds";
		}
		if(bMessage)
		{
			Broadcast(this,Message1);
			Broadcast(this,message2);
		}
	*/
}
void AAGP_GameDeathMatch::ResetMatchScores()
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
		PRI.ResetPerRound();
	}
	*/
}

void AAGP_GameDeathMatch::ResetRoundScores()
{
	/*
		AController* C = nullptr;
		AAA2_PlayerState* PRI;
		C=Level.ControllerList;
		if(C != nullptr)
		{
			PRI=C.PlayerReplicationInfo;
			if(PRI == nullptr)
			{
			}
			PRI.ResetPerRound();
			C=C.nextController;
		}
	*/
}
void AAGP_GameDeathMatch::CompleteEndGame()
{
	ResetDecoMeshes();
}
bool AAGP_GameDeathMatch::ShouldSpectate(AAA2_PlayerState* p)
{
	if(bPlayersMustBeReady && ! p->bReadyToPlay)
	{
		return true;
	}
	else
	{
		return Super::ShouldSpectate(p);
	}
}

void AAGP_GameDeathMatch::NotifyRoundOver()
{
}

bool AAGP_GameDeathMatch::ConfirmReady()
{
	return true;
}
void AAGP_GameDeathMatch::StopNPCControllers()
{
	ANPCBaseController* npcbcIterator = nullptr;
	ANPCAICombatController* npcaicc = nullptr;
	/*
	ForEach AllActors(ANPCBaseController::StaticClass(),npcbcIterator)
	{
		npcbcIterator.GameHasEnded();
		npcbcIterator.Destroy();
	}
	ForEach AllActors(ANPCAICombatController::StaticClass(),npcaicc)
	{
		npcaicc.EndGame();
		GOTO JL0050;
JL0050:
	}
	*/
}
void AAGP_GameDeathMatch::ShowTournamentCountDown()
{
	FString TournamentTimeMessage = "";
	int32 TournamentTimeCounter = 0;
	int32 TournamentTimeMinutes = 0;
	int32 TournamentTimeSeconds = 0;
	/*
	TournamentTimeCounter=GameReplicationInfo.TournamentCountDownTime;
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
					TournamentTimeMessage=TournamentTimeMinutes + " minute " + TournamentTimeSeconds + " seconds until tournament starts";
				}
				else
				{
					TournamentTimeMessage=TournamentTimeMinutes + " minutes " + TournamentTimeSeconds + " seconds until tournament starts";
				}
			}
			else
			{
				if(TournamentTimeSeconds == 0)
				{
					if(TournamentTimeMinutes == 1)
					{
						TournamentTimeMessage=TournamentTimeMinutes + " minute until tournament starts";
					}
					else
					{
						TournamentTimeMessage=TournamentTimeMinutes + " minutes until tournament starts";
					}
				}
			}
		}
		else
		{
			if(TournamentTimeSeconds == 30 && TournamentTimeMinutes < 1)
			{
				TournamentTimeMessage=TournamentTimeSeconds + " seconds until tournament starts";
			}
			else
			{
				if(TournamentTimeSeconds <= 10 && TournamentTimeSeconds > 0 && TournamentTimeMinutes < 1)
				{
					TournamentTimeMessage="Tournament Starting In: " + TournamentTimeSeconds;
				}
				else
				{
					if(TournamentTimeSeconds == 0 && TournamentTimeMinutes < 1)
					{
						TournamentTimeMessage="Tournament Starting";
					}
				}
			}
		}
		if(TournamentTimeMessage != "")
		{
			TournamentSendMessage(TournamentTimeMessage);
		}
	}
	*/
}

void AAGP_GameDeathMatch::TournamentServerINISetTeamName(int32 iTeam, FString sTeamName)
{
	/*
	'AGP_GameTournament'.Default.asTournamentTeamName[iTeam]=sTeamName;
	SaveConfig();
	*/
}

FString AAGP_GameDeathMatch::TournamentServerINIGetTeamName(int32 iTeam)
{
	//return 'AGP_GameTournament'.Default.asTournamentTeamName[iTeam];
	return "FAKE";    //FAKE   /ELiZ
}
