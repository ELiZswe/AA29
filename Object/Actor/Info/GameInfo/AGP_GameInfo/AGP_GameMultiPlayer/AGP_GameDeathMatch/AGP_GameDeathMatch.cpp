// All the original content belonged to the US Army


#include "AGP_GameDeathMatch.h"
#include "AA29/AA2_GameState.h"


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
			Return;
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
void AAGP_GameDeathMatch::CheckEndGame(AAA2_PlayerState* Winner, FString Reason)
{
	/*
		local Controller p;
		local PlayerController Player;
		local AGP_Viewpoint VP;
		local Vehicle V;
		local Pawn PlayerPawn;
		EndTime=GetWorld()->GetTimeSeconds() + 3;
		if(Winner != None)
		{
			GameReplicationInfo.Winner=Winner;
		}
		VP=GetWinningViewpoint(Winner);
		p=Level.ControllerList;
		if(p != None)
		{
			if(p.IsA('AIController'))
			{
			}
			if(p.IsA('PlayerController'))
			{
				if(HumanController(p).bPBChecked && HumanController(p).bPlayerIsReadyToPlay && ! p.IsInState('FailedAuthorization') && ! p.IsInState('ServerAuthorizePlayer') && ! p.IsInState('ValidatePB'))
				{
					Player=PlayerController(p);
					PlayerPawn=Player.Pawn;
					V=Vehicle(PlayerPawn);
					if(V != None)
					{
						Player.Pawn=V.Driver;
						V.UnPossessed();
						V.Driver=None;
						V.Controller=None;
						Player.Pawn.SetBase(None);
						Player.AcknowledgedPawn=Player.Pawn;
					}
					Player.ClientSetBehindView(True);
					Player.SetViewTarget(VP);
					Player.ClientSetViewTarget(VP);
					Player.ClientGameEnded();
				}
				else
				{
					if(p.PlayerReplicationInfo != None)
					{
						UE_LOG(LogTemp, Warning, TEXT("AGP_GameDeathmatch::CheckEndGame() - User " $ p.PlayerReplicationInfo.PlayerName $ " being skipped - not authorized"));
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("AGP_GameDeathmatch::CheckEndGame() - User being skipped - not authorized"));
					}
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("AGP_GameDeathMatch() - Sending client to GameEnded state"));
				if(HumanController(p).bPlayerIsReadyToPlay)
				{
					p.GotoState('GameEnded');
				}
			}
			p=p.nextController;
		}
		CleanupForMatchEnd();
		return true;
	*/
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
	/*
		local Actor A;
		ForEach DynamicActors(Class'Actor',A)
		{
			if(A.IsA('Pickup'))
			{
				A.MatchEnding();
			}
			else
			{
				if(A.IsA('Emitter'))
				{
					A.MatchEnding();
				}
				else
				{
					if(A.IsA('Pawn') && ! A.IsA('NPC_Ambient'))
					{
						A.SetDrawType(0);
					}
					else
					{
						if(A.IsA('Weapon') && ! A.IsA('FixedWeapon'))
						{
							A.Destroy();
						}
						else
						{
							if(A.IsA('ThrowWeapon'))
							{
								A.Destroy();
							}
							else
							{
								if(A.IsA('Projectile'))
								{
									A.Destroy();
								}
								else
								{
									if(A.IsA('Attch_Parachute'))
									{
										A.Destroy();
									}
									else
									{
										if(A.IsA('HumanController'))
										{
											HumanController(A).ClientSetBehindView(False);
											HumanController(A).IdleCheckPerRound(True);
											HumanController(A).CleanOutSavedMoves();
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
void AAGP_GameDeathMatch::FindPlayerStart(AController* Player, uint8 InTeam, FString incomingName)
{
	/*
		local NavigationPoint SpawnPoint;
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".FindPlayerStart() - Trying to find player start"));
		SpawnPoint=FindPlayerStart(Player,InTeam,incomingName);
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".FindPlayerStart() - Found: " $ SpawnPoint));
		if(SpawnPoint != None)
		{
			LastSpawnPoint=SpawnPoint;
		}
		Return SpawnPoint;
	*/
}

/*
void AAGP_GameDeathMatch::RatePlayerStart(ANavigationPoint* N, uint8 Team, AController* Player)
{
		local NavigationPoint LastPlayerSpawnPoint;
		local PlayerStart p;
		local Controller C;
		local float Score;
		local float penalty;
		local float Distance;
		local bool bVisible;
		p=PlayerStart(N);
		if(p == None || ! p.bEnabled)
		{
			Return 0;
		}
		Score=p.fBaseScore;
		if(Player != None && Player.StartSpot != None)
		{
			LastPlayerSpawnPoint=Player.StartSpot;
		}
		if(N == LastSpawnPoint || N == LastPlayerSpawnPoint)
		{
			Score -= 10;
		}
		else
		{
			Score += 10 * FRand();
		}
		C=Level.ControllerList;
		if(C != None)
		{
			if(C.IsA('AIController'))
			{
			}
			if(C.bIsPlayer && C.Pawn != None)
			{
				Distance=VSize(C.Pawn.Location - N.Location);
				if(Distance < C.Pawn.CollisionRadius + C.Pawn.CollisionHeight)
				{
					Score -= 500;
				}
				else
				{
					bVisible=FastTrace(N.Location,C.Pawn.Location);
					penalty=0;
					if(bVisible)
					{
						penalty += 5;
					}
					if(Distance < 5000 && bVisible)
					{
						penalty += 5 - Distance / 1000;
					}
					if(C.Pawn.Region.Zone == N.Region.Zone)
					{
						penalty += 3;
					}
					if(IsTeamFriend(Team,C.Pawn))
					{
						Score += penalty;
					}
					else
					{
						Score -= penalty;
					}
				}
			}
			C=C.nextController;
		}
		Return Score;
}
*/

bool AAGP_GameDeathMatch::IsTournamentMode()
{
	return Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer() || bTournamentMode;
}
bool AAGP_GameDeathMatch::IsTeamGame()
{
	return false;
}
float AAGP_GameDeathMatch::GetTimeElapsed()
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
	/*
		local Controller C;
		local int iPlayersOnServer;
		Logout(Exiting);
		if(Stats != None && Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer() || Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
		{
			C=Level.ControllerList;
			if(C != None)
			{
				if(HumanController(C) != None && C != Exiting)
				{
					iPlayersOnServer ++;
				}
				C=C.nextController;
			}
			if(iPlayersOnServer == 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Sending STS Stats after last player leaves server."));
				UE_LOG(LogTemp, Warning, TEXT("Initiating stats transmission..."));
				Stats.Aggregate();
				Stats.Store();
				UE_LOG(LogTemp, Warning, TEXT("Destroyng STS Stats object."));
				Stats.Destroy();
				Stats=None;
			}
		}
		if(NumPlayers == 0)
		{
			ResetMatchScores();
		}
	*/
}

void AAGP_GameDeathMatch::NotifyIdlePlayerRounds(AController* C, int32 nIdleRounds, bool bMessage)
{
	/*
		local string Message1;
		local string message2;
		Message1=C.PlayerReplicationInfo.PlayerName $ " has been idle for " $ nIdleRounds $ " round";
		if(nIdleRounds > 1)
		{
			Message1=Message1 $ "s";
		}
		message2="Type 'votekick " $ C.PlayerReplicationInfo.PlayerName $ "' to try to kick this Player now";
		if(bKickIdlePlayersRounds)
		{
			if(nIdleRounds == IdlePlayerKickRounds - 1)
			{
				HumanController(C).NotifyImpendingIdleKick(True);
			}
			else
			{
				if(nIdleRounds >= IdlePlayerKickRounds)
				{
					Kick(C.PlayerReplicationInfo.PlayerName,"IdleRounds");
					Return;
				}
			}
			Message1=Message1 $ " and will be auto-kicked after " $ IdlePlayerKickRounds $ " rounds";
		}
		if(bMessage)
		{
			Broadcast(Self,Message1);
			Broadcast(Self,message2);
		}
	*/
}
void AAGP_GameDeathMatch::ResetMatchScores()
{
	/*
		local Controller C;
		local PlayerReplicationInfo PRI;
		UE_LOG(LogTemp, Warning, TEXT("ResetMatchScores() entered"));
		C=Level.ControllerList;
		if(C != None)
		{
			PRI=C.PlayerReplicationInfo;
			if(PRI == None)
			{
			}
			PRI.ResetScores();
			C=C.nextController;
		}
		ResetRemainingRounds();
	*/
}

void AAGP_GameDeathMatch::ResetRoundScores()
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
	/*
		local AGP.NPCBaseController npcbcIterator;
		local AGP.NPCAICombatController npcaicc;
		ForEach AllActors(Class'NPCBaseController',npcbcIterator)
		{
			npcbcIterator.GameHasEnded();
			npcbcIterator.Destroy();
		}
		ForEach AllActors(Class'NPCAICombatController',npcaicc)
		{
			npcaicc.EndGame();
			GOTO JL0050;
	JL0050:
		}
	*/
}
void AAGP_GameDeathMatch::ShowTournamentCountDown()
{
	/*
		local string TournamentTimeMessage;
		local int TournamentTimeCounter;
		local int TournamentTimeMinutes;
		local int TournamentTimeSeconds;
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
						TournamentTimeMessage=TournamentTimeMinutes $ " minute " $ TournamentTimeSeconds $ " seconds until tournament starts";
					}
					else
					{
						TournamentTimeMessage=TournamentTimeMinutes $ " minutes " $ TournamentTimeSeconds $ " seconds until tournament starts";
					}
				}
				else
				{
					if(TournamentTimeSeconds == 0)
					{
						if(TournamentTimeMinutes == 1)
						{
							TournamentTimeMessage=TournamentTimeMinutes $ " minute until tournament starts";
						}
						else
						{
							TournamentTimeMessage=TournamentTimeMinutes $ " minutes until tournament starts";
						}
					}
				}
			}
			else
			{
				if(TournamentTimeSeconds == 30 && TournamentTimeMinutes < 1)
				{
					TournamentTimeMessage=TournamentTimeSeconds $ " seconds until tournament starts";
				}
				else
				{
					if(TournamentTimeSeconds <= 10 && TournamentTimeSeconds > 0 && TournamentTimeMinutes < 1)
					{
						TournamentTimeMessage="Tournament Starting In: " $ TournamentTimeSeconds;
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
void AAGP_GameDeathMatch::TournamentServerINIGetTeamName(int32 iTeam)
{
	/*
		Return 'AGP_GameTournament'.Default.asTournamentTeamName[iTeam];
	*/
}
