// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameDeathMatch/AGP_GameTeam/AGP_GameTeam.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/AGP_Character_NPC.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_ESSObjective.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassJavelin/ClassJavelin.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassSniperBase/ClassSniper/ClassSniper.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassSniperBase/ClassSniper24_US/ClassSniper24_US.h"
#include "AA29/Object/Actor/Controller/AIController/aAIController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Keypoint/AGP_Viewpoint/AGP_Viewpoint.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/AA2_GameState.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"
#include "AA29/Object/Actor/PSSet/PSSet.h"
#include "AA29/Object/Actor/Info/LocalMessage/CommoLocalMessage/CommoEventRadio/CommoEventRadio.h"
#include "AA29/Object/DamageType/Suicided/Suicided.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBasePreCrewedVehicleController/NPCBasePreCrewedVehicleControlle.h"

AAGP_GameTeam::AAGP_GameTeam()
{
	ForcePSSetTeamSlot.SetNum(32);
	ForcePSSetTag.SetNum(32);
	CurrentPSSet.SetNum(2);
	FFScoreLimit = 400;
	MaxTeamSize = 13;
	bNeverAutoBalance = true;
	bTeamGame = true;
	ScoreBoardType = "AGP_Gameplay.AGP_ScoreBoardTeamDM";
	GameName = "AGP Game - Team DeathMatch";
	Teams.SetNum(2);
}
void AAGP_GameTeam::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("AAGP_GameTeam::BeginPlay()"));
	Super::BeginPlay();
}

void AAGP_GameTeam::FindPSSets()
{
	/*
		APSSet* Set;
		int32 j = 0;
		int32 i = 0;
		ForEach AllActors(APSSet::StaticClass(),Set)
		{
			if (Set.Team >= 0 && Set.Team < 2 && Set.SetTag != "None" && Set.SetTag != "None")
			{
				PSSets[PSSets.Num()]=Set;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::FindPSSets()	Found useless set (" @ Set @ ") Team(" @ Set.Team @ ") SetTag(" @ Set.SetTag @ ")"));
			}
		}
		if (ForcePSSetTag[0] != "None")
		{
			for (j=0; j<31; j++)
			{
				if (ForcePSSetTag[j] != "None")
				{
					for (i=0; i<PSSets.Num(); i++)
					{
						if (PSSets[i].SetTag != ForcePSSetTag[j] && PSSets[i].Team == ForcePSSetTeamSlot[j])
						{
							PSSets->Remove(i,1);
						}
					}
				}
			}
		}
	*/
}

void AAGP_GameTeam::PostBeginPlay()
{
	Super::PostBeginPlay();
	SetupTeams();
	if (bNeverAutoBalance && bPlayersBalanceTeams || bAutoBalanceBetweenRounds)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::PostBeginPlay()	bNeverAutoBalance is set! Other auto-balance settings are being ignored!"));
	}
	FindPSSets();
}

void AAGP_GameTeam::LogPlayerStart(APlayerController* PC)
{
	AAA2_PlayerState* PRI = nullptr;
	FString sclass = "";
	/*
	if (PC.StartSpot->IsA(AAGP_PlayerStart::StaticClass()))
	{
		sclass=Cast<AAGP_PlayerStart>(PC.StartSpot).SpawnClass;
	}
	PRI=PC.PlayerReplicationInfo;
	if (PRI != nullptr && PRI.Team != nullptr && PRI.Team.TeamIndex >= 0 && PRI.Team.TeamIndex <= 1)
	{
		LogFileWrite("ScriptLog","PStart:" + PRI.PlayerName + ":" + Level.TeamName[PRI.Team.TeamIndex] + ":" + sclass + ":" + PRI.IsSquadLeader() + ":" + PRI.isTeamLeader());
	}
	*/
}

void AAGP_GameTeam::LogPlayerFinish(APlayerController* PC)
{
	AAA2_PlayerState* PRI = nullptr;
	/*
	PRI=PC.PlayerReplicationInfo;
	LogFileWrite("ScriptLog","PFinish:" + PRI.PlayerName + ":" + PRI.Score_Total);
	*/
}

void AAGP_GameTeam::SetupTeams()
{
	int32 i = 0;
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::SetupTeams() Creating teams"));
	for (i=0; i<2; i++)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && i > 0)
		{
		}

		UWorld* const World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();
			Teams[i] = GetWorld()->SpawnActor<AAGP_TeamInfo>(FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
			Teams[i]->TeamIndex = i;
			Cast<AAA2_GameState>(GetWorld()->GetGameState())->Teams[i] = Teams[i];
			Teams[i]->SetupTeam();
		}
	}
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		Teams[0]->otherTeam=Teams[1];
		Teams[1]->otherTeam=Teams[0];
	}
	UWorld* const World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();
		SpecTeam = GetWorld()->SpawnActor<AAGP_TeamInfo>(FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
		SpecTeam->TeamIndex = 255;
		SpecTeam->bSpectatorTeam = true;

		Cast<AAA2_GameState>(GetWorld()->GetGameState())->SpecTeam = SpecTeam;
	}

}
void AAGP_GameTeam::MaybeAutoBalanceTeams()
{
	bool bDoIt;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		return;
	}
	if (bDeadGame || bNeverAutoBalance)
	{
		return;
	}
	bDoIt=bAutoBalanceBetweenRounds;
	if (! bDoIt)
	{
		if (Teams[0]->Size == 0 || Teams[1]->Size == 0)
		{
			bDoIt=true;
		}
	}
	if (bDoIt)
	{
		AutoBalanceTeams();
	}
}
void AAGP_GameTeam::AutoBalanceTeams()
{
	AController* Swap;
	AAGP_TeamInfo* SmallTeam;
	AAGP_TeamInfo* BigTeam;
	if (GetSmallerTeamIndex(0) == 1)
	{
		SmallTeam=Teams[1];
		BigTeam=Teams[0];
	}
	else
	{
		SmallTeam=Teams[0];
		BigTeam=Teams[1];
	}
	if (SwapAPlayer(BigTeam,SmallTeam))
	{
		Swap=BigTeam->GetSwapPlayer();
		if (Swap == nullptr)
		{
			//UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::AutoBalanceTeams() Got NULL player from " + BigTeam));
		}
		BigTeam->RemoveFromTeam(Swap);
		SmallTeam->AddToTeam(Swap);
		Cast<AHumanController>(Swap)->PlayerReplicationInfo->DesiredTeam=SmallTeam->TeamIndex;
		//UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::AutoBalanceTeam() Moving " + Swap.GetHumanReadableName() + " from " + BigTeam + " to " + SmallTeam));
		if (Swap->IsA(AHumanController::StaticClass()))
		{
			Cast<AHumanController>(Swap)->SetStartupStage(EStartupStage::STAGE_Autobalance);
		}
	}
}

bool AAGP_GameTeam::SwapAPlayer(ATeamInfo* Big, ATeamInfo* Small)
{
	float nrBig;
	float nrSmall;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		return false;
	}
	nrBig   = (Big->Size - 1) / Big->MaxSize;
	nrSmall = (Small->Size + 1) / Small->MaxSize;
	//UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::SwapAPlayer() " + nrBig @ nrSmall));
	if (nrBig - nrSmall >= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::SwapAPlayer()	SWAPPING!"));
		return true;
	}
	return false;
}
int32 AAGP_GameTeam::GetSmallerTeamIndex(int32 prefer)
{
	TArray<float> rsize;
	int32 i = 0;
	rsize.SetNum(2);
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		return 0;
	}
	for (i=0; i<2; i++)
	{
		rsize[i]=Teams[i]->Size / Teams[i]->MaxSize;
	}
	if (rsize[0] == rsize[1] && prefer == 0 || prefer == 1)
	{
		return prefer;
	}
	else
	{
		if (rsize[0] < rsize[1])
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

bool AAGP_GameTeam::ValidSet(APSSet* NewSet, uint8 Team)
{
	int32 i = 0;
	int32 j = 0;
	//UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ValidSet() - Team: " + Team + " PSSet: " + NewSet));
	if (NewSet->Team != Team)
	{
		//UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ValidSet() - NewSet.Team: " + NewSet.Team + " Team: " + Team + " Exiting function."));
		return false;
	}
	if (bForcePSSet)
	{
		if (NewSet->bUseAsDefault)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	for (i=0; i<=Team; i++)
	{
		if (CurrentPSSet[i] == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GAmeTeam::ValidSet() - Team causing None: %s"),i);
		}
		else
		{
			for (j=0; j<CurrentPSSet[i]->RestrictedEnemySets.Max(); j++)
			{
				if (CurrentPSSet[i] != nullptr && CurrentPSSet[i]->RestrictedEnemySets[j] == NewSet->SetTag)
				{
					//UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ValidSet() - returning false for " + CurrentPSSet[i]));
					return false;
				}
			}
			if (CurrentPSSet[i] != nullptr && CurrentPSSet[i]->RequiredEnemySet != "None" && CurrentPSSet[i]->RequiredEnemySet != "None")
			{
				//UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ValidSet() - RequiredEnemySet: " + CurrentPSSet[i].RequiredEnemySet + " NewSet.SetTag: " + NewSet.SetTag));
				return CurrentPSSet[i]->RequiredEnemySet == NewSet->SetTag;
			}
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ValidSet() - Returning true."));
	return true;
}

void AAGP_GameTeam::FindCurrentSets()
{
	int32 Index = 0;
	int32 i = 0;
	int32 j = 0;
	TArray<APSSet*> TeamSet;
	for (i=0; i<2; i++)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && i > 0)
		{
		}
		CurrentPSSet[i]=nullptr;
	}
	for (i=0; i<2; i++)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && i > 0)
		{
		}
		for (j=0; j<PSSets.Max(); j++)
		{
			if (ValidSet(PSSets[j],i))
			{
				TeamSet[TeamSet.Max()]=PSSets[j];
			}
		}
		if (TeamSet.Max() > 0)
		{
			Index=FMath::RandRange(0,TeamSet.Max()-1);
			CurrentPSSet[i]=TeamSet[Index];
			LastPSSet[i]=CurrentPSSet[i];
			//UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::FindCurrentSets()	Team(" @ i @ Level.TeamName[i] @ ") using PSSet(" @ CurrentPSSet[i].SetTag @ ")"));
			//TeamSet.Remove (0,TeamSet.Max());
		}
		else
		{
			if (PSSets.Max() > 0)
			{
				if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
				{
					UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::FindCurrentSets()	Could not find a legal set for team (%d)"),i);
				}
			}
		}
	}
}

void AAGP_GameTeam::AssignStartPoints()
{
	int32 i = 0;
	Super::AssignStartPoints();
	FindCurrentSets();
	for (i=0; i<2; i++)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && i > 0)
		{
		}
		Teams[i]->FindPSStartIndexes(CurrentPSSet[i]);
		Teams[i]->AssignStartPoints();
	}
}
void AAGP_GameTeam::AssignClassAndRole()
{
	int32 i = 0;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugObjective)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::AssignClassAndRole()"));
	}
	for (i=0; i<2; i++)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && i > 0)
		{
		}
		Teams[i]->TeamReset();
		Teams[i]->AssignClassAndRole();
	}
}
void AAGP_GameTeam::RecordStartMatch()
{
	int32 i = 0;
	for (i=0; i<2; i++)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && i > 0)
		{
		}
		Teams[i]->RecordStartMatch();
	}
}
void AAGP_GameTeam::CheckClassWithPlayerStart(AController* PC)
{
	if (PC != nullptr && Cast<AHumanController>(PC)->PlayerReplicationInfo != nullptr && Cast<AHumanController>(PC)->PlayerReplicationInfo->Team != nullptr && Cast<AHumanController>(PC)->PlayerReplicationInfo->Team->IsA(AAGP_TeamInfo::StaticClass()))
	{
		Cast<AAGP_TeamInfo>(Cast<AHumanController>(PC)->PlayerReplicationInfo->Team)->AssignTeamClassAndRole(PC);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::CheckClassWithPlayerStart failed due to illegal controller/team."));
	}
}

AAGP_PlayerStart* AAGP_GameTeam::FindPlayerStart(AController* Player, uint8 InTeam, FString incomingName)
{
	//UE_LOG(LogTemp, Warning, TEXT(Self + ".FindPlayerStart() - Trying to find player start"));
	if (Player != nullptr && Player->StartSpot != nullptr && bWaitingToStartMatch)
	{
		//UE_LOG(LogTemp, Warning, TEXT(Self + ".FindPlayerStart() - Using player's old start: " + Player.StartSpot));
		//UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::FindPlayerStart() Returning preselected " + Player.StartSpot));
		//return Player->StartSpot;
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT(AGP_GameTeam::FindPlayerStart() No spawn point for player" @ Player @ Player.StartSpot @ bWaitingToStartMatch));
		return nullptr;
	}

	return nullptr;
}

float AAGP_GameTeam::RatePlayerStart(ANavigationPoint* N, uint8 Team, AController* Player)
{
	APlayerStart* p = nullptr;
	AAGP_PlayerStart* APS = nullptr;
	float Score = 0;
	float Distance = 0;
	AHumanController* HC = nullptr;
	AController* C = nullptr;
	p = Cast<APlayerStart>(N);
	/*
	if (((p == nullptr) || (!p->bEnabled)) || (p->TeamNumber != Team))
	{
		return 0;
	}
	if (p->IsA(AAGP_PlayerStart::StaticClass()))
	{
		APS = Cast<AAGP_PlayerStart>(N);
		if ((!APS->CanSpawn()) && (!IsUnlimitedRespawn()))
		{
			return 0;
		}
		Score = APS->GetScore();
		HC = Cast<AHumanController>(Player);
		if (HC != nullptr)
		{
			if (((!HC->PlayerReplicationInfo->bQualifiedSniper) && (APS->GetSpawnClass() == AClassSniper24_US::StaticClass())) || (APS->GetSpawnClass() == AClassSniper::StaticClass()))
			{
				return 0;
			}
			if ((!HC->PlayerReplicationInfo>bQualifiedJavelin) && (APS->GetSpawnClass() == AClassJavelin::StaticClass()))
			{
				return 0;
			}
		}
		if ((HC != nullptr) && (HC->DesiredTeamClass == APS->GetSpawnClass()))
		{
			Score *= 2;
		}
	}
	else
	{
		//Score = Super::RatePlayerStart(N, Team, Player);
	}
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (C->IsA(AaAIController::StaticClass()))
		{
		}
		if (C == Player)
		{
		}
		if (C->bIsPlayer && (C->StartSpot != nullptr))
		{
			if (C->StartSpot == N)
			{
				return 0;
			}
			Distance = VSize((C.StartSpot.Location - N.Location));
			if (Distance < (AAGP_Pawn::StaticClass().Default.CollisionRadius + AAGP_Pawn::StaticClass().Default.CollisionHeight))
			{
				return 0;
			}
		}
	}
	*/
	return Score;
}

uint8 AAGP_GameTeam::PickTeam(uint8 Num, AController* C)
{
	ATeamInfo* NewTeam = nullptr;
	if (Num == 255)
	{
		return 255;
	}
	if (Num < 2)
	{
		NewTeam=Teams[Num];
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		NewTeam=Teams[0];
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::PickTeam() Co-Op adding you to %d"), NewTeam->TeamIndex);
		return NewTeam->TeamIndex;
	}
	if (bNeverAutoBalance && NewTeam != nullptr)
	{
		return NewTeam->TeamIndex;
	}
	if (bPlayersBalanceTeams)
	{
		NewTeam=Teams[GetSmallerTeamIndex(Num)];
	}
	if (NewTeam == nullptr || NewTeam->Size >= MaxTeamSize || NewTeam->Size >= NewTeam->MaxSize)
	{
		//UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::PickTeam() Could not grant request. Placing on smaller team. " + NewTeam @ NewTeam.Size @ MaxTeamSize @ NewTeam.MaxSize));
		NewTeam=Teams[GetSmallerTeamIndex(Num)];
	}
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::PickTeam() Adding you to %d"), NewTeam->TeamIndex);
	return NewTeam->TeamIndex;
}

void AAGP_GameTeam::CompleteEndGame()
{
	AController* p = nullptr;
	AAA2_PlayerStart* PRI = nullptr;
	Super::CompleteEndGame();
	/*
	for (p = Level.ControllerList; p != nullptr; p = p.nextController)
	{
		if (p->IsA(AaAIController::StaticClass()))
		{
		}
		if (p.PlayerReplicationInfo == nullptr)
		{
		}
		PRI = p.PlayerReplicationInfo;
		if ((PRI == nullptr) || p->IsA(AaAIController::StaticClass()))
		{
		}
		if (PRI.Team.TeamIndex == 255)
		{
			if ((p.IsInState("ValidatePB") || p.IsInState("ServerAuthorizePlayer")) || p.IsInState("FailedAuthorization"))
			{
			}
			if (PRI.bOnlySpectator)
			{
			}
			ChangeTeam(p, GetSmallerTeamIndex());
			if (PRI.Team.TeamIndex == 255)
			{
				DebugLog(DEBUG_Multi, "AGP_GameTeam::CompleteEndGame()	Player was unable to leave SpecTeam!" + FString::FromInt(p) @ PRI.GetHumanReadableName());
			}
			PRI.DesiredTeam = uint8(PRI.Team.TeamIndex);
		}
	}
	*/
	MaybeAutoBalanceTeams();
}

void AAGP_GameTeam::EndGame(AAA2_PlayerState* Winner, FString Reason)
{
	int32 win = 0;
	int32 lose = 0;
	int32 TeamIndex = 0;
	int32 lostindex = 0;
	bool bFoundWinner = false;
	bool bTeam0Dead = false;
	bool bTeam1Dead = false;
	AController* ctrlIterator = nullptr;
	int32 i = 0;
	int32 NumAIs = 0;
	int32 NumLethalObjects = 0;
	int32 NumNonLethalObjects = 0;
	int32 PlayersSurviving = 0;
	TArray<FVector> ReportedESSLocations = {};
	TArray<FVector> UnreportedESSLocations = {};
	AAGP_Character_NPC* NPC = nullptr;
	AController* p = nullptr;
	AAGP_ESSObjective* ESSObject = nullptr;
	if (CheckDontEndGame(Reason))
	{
		return;
	}
	if (Winner != nullptr)
	{
		//DebugLog(DEBUG_Multi, "AGP_GameTeam::EndGame.   Reason=" + Reason + " and Winner=" + Winner.PlayerName);
	}
	else
	{
		//DebugLog(DEBUG_Multi, "AGP_GameTeam::EndGame.   Reason=" + Reason + " and Winner= none");
	}
	bFoundWinner = false;
	/*
	if (Reason == "TeamDead")
	{
		bTeam0Dead = Teams[0].TeamDead();
		if (Level.bCoOpGame)
		{
			bTeam1Dead = true;
			ctrlIterator = Level.ControllerList;
			if (ctrlIterator != nullptr)
			{
				if (ctrlIterator->IsA(ANPCBaseSoldierController::StaticClass()))
				{
					if (ctrlIterator.IsInState("Surrender") || ctrlIterator.IsInState("Dead"))
					{
					}
					if ((ctrlIterator.Pawn != nullptr) && (ctrlIterator.Pawn.Health > 0))
					{
						bTeam1Dead = false;
					}
				}
				else
				{
					ctrlIterator = ctrlIterator.nextController;
				}
			}
		}
		else
		{
			bTeam1Dead = Teams[1].TeamDead();
		}
		if (bTeam0Dead && bTeam1Dead)
		{
			lose = ACommoEventRadio::StaticClass().Default.MsgSquadDead;
		}
		else
		{
			win = ACommoEventRadio::StaticClass().Default.MsgEnemyDead;
			lose = ACommoEventRadio::StaticClass().Default.MsgSquadDead;
			if (bTeam0Dead)
			{
				TeamIndex = 1;
			}
			else
			{
				TeamIndex = 0;
			}
			bFoundWinner = true;
		}
	}
	else
	{
		if ((Reason == "Objective") && (Winner != nullptr))
		{
			win = ACommoEventRadio::StaticClass().Default.MsgMissionCompleted;
			lose = ACommoEventRadio::StaticClass().Default.MsgMissionFailed;
			TeamIndex = Winner.Team.TeamIndex;
			bFoundWinner = true;
		}
		else
		{
			if ((Reason == "ObjectiveImpossible") && (Winner != nullptr))
			{
				win = ACommoEventRadio::StaticClass().Default.MsgMissionCompleted;
				lose = ACommoEventRadio::StaticClass().Default.MsgMissionImpossible;
				TeamIndex = Winner.Team.TeamIndex;
				bFoundWinner = true;
			}
			else
			{
				if ((Reason == "ObjectiveImpossible") && (Winner == nullptr))
				{
					lose = ACommoEventRadio::StaticClass().Default.MsgMissionImpossible;
				}
				else
				{
					if (Reason == "TimeLimit")
					{
						lose = ACommoEventRadio::StaticClass().Default.MsgMissionFailed;
					}
					else
					{
						if (Reason == "NoScore")
						{
							lose = ACommoEventRadio::StaticClass().Default.MsgMissionImpossible;
						}
						else
						{
							if (Reason == "NoWinner")
							{
								lose = ACommoEventRadio::StaticClass().Default.MsgMissionImpossible;
								TeamIndex = Winner.Team.TeamIndex;
							}
							else
							{
								if (Reason == "EndWarmup")
								{
									lose = ACommoEventRadio::StaticClass().Default.MsgMissionFailed;
								}
								else
								{
									DebugLog(DEBUG_Warn, "AGP_GameTeam::EndGame() Unknown Reason/Winner " + Reason @ FString::FromInt(Winner));
									if (Winner != nullptr)
									{
										win = ACommoEventRadio::StaticClass().Default.MsgMissionCompleted;
										lose = ACommoEventRadio::StaticClass().Default.MsgMissionFailed;
										TeamIndex = Winner.Team.TeamIndex;
										bFoundWinner = true;
									}
									else
									{
										lose = ACommoEventRadio::StaticClass().Default.MsgMissionFailed;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (bFoundWinner)
	{
		if (TeamIndex == 0)
		{
			lostindex = 1;
		}
		else
		{
			lostindex = 0;
		}
		BroadcastHandler.BroadcastLocalizedTeamByIndex(byte(TeamIndex), this, ACommoEventRadio::StaticClass(), win);
		BroadcastHandler.BroadcastLocalizedTeamByIndex(byte(lostindex), this, ACommoEventRadio::StaticClass(), lose);
		if ((!Level.bCoOpGame) || (TeamIndex == 0))
		{
			Teams[TeamIndex].ScoreRound(true);
		}
		if ((!Level.bCoOpGame) || (lostindex == 0))
		{
			Teams[lostindex].ScoreRound(false);
		}
	}
	else
	{
		BroadcastHandler.AllowBroadcastLocalized(this, ACommoEventRadio::StaticClass(), lose);
		if (Reason == "NoWinner")
		{
			if ((!Level.bCoOpGame) || (TeamIndex == 0))
			{
				Teams[TeamIndex].ScoreRound(false);
			}
		}
		else
		{
			if (Reason != "NoScore")
			{
				Teams[0].ScoreRound(false);
				if (!Level.bCoOpGame)
				{
					Teams[1].ScoreRound(false);
				}
			}
		}
	}
	for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
	{
		if (ctrlIterator->IsA(APlayerController::StaticClass()))
		{
			LogPlayerFinish(Cast<APlayerController>(ctrlIterator));
		}
	}
	LogFileWrite("ServerStatus", "Round:Ended");
	LogFileWrite("ServerStatus", "RoundWinner:" + FString::FromInt(TeamIndex));
	LogFileWrite("ServerStatus", "RoundTime:" + FString::FromInt(GetTimeElapsed()));
	LogFileWrite("ServerStatus", "RoundWonBy:" + Reason, true);
	if (IsRequireAuthorization() && (!bDisableQualification))
	{
		DoAuthenticationCheckOnWinningTeam(Winner);
	}
	if ((Level.Game.Stats != nullptr) && (Level.Game.Stats.GameStats != nullptr))
	{
		Log("Recording round ended stat");
		for (i = 0; i < Level.Game.Stats.PlayerStats.Num(); i++)
		{
			if (Level.Game.Stats.PlayerStats[i] != nullptr)
			{
				Level.Game.Stats.PlayerStats[i].StatEvent_RoundEnded();
				ForEach AllActors(AAGP_ESSObjective::StaticClass(), ESSObject)
				{
					if (ESSObject.bDangerous)
					{
						NumLethalObjects++;
					}
					else
					{
						NumNonLethalObjects++;
					}
					if (((ESSObject.ctrlrESSReporter == nullptr) || (Cast<APlayerController>(ESSObject.ctrlrESSReporter) == nullptr)) || (Cast<APlayerController>(ESSObject.ctrlrESSReporter).PlayerStatsIndex != i))
					{
						UnreportedESSLocations.insert(UnreportedESSLocations.Num(), 1);
						UnreportedESSLocations[(UnreportedESSLocations.Num() - 1)] = ESSObject.Location;
					}
				}
				Level.Game.Stats.PlayerStats[i].StatEvent_ObjectReportableLethal(NumLethalObjects);
				Level.Game.Stats.PlayerStats[i].StatEvent_ObjectReportableNonLethal(NumNonLethalObjects);
				Level.Game.Stats.PlayerStats[i].StatEvent_ObjectUnreportedLocations(UnreportedESSLocations);
				Level.Game.Stats.PlayerStats[i].StatEvent_ReportObjectDistribution();
				Level.Game.Stats.PlayerStats[i].StatEvent_ReportPlayerDeathLocations();
				Level.Game.Stats.PlayerStats[i].StatEvent_ReportPlayerInjuryLocations();
				ForEach AllActors(AAGP_Character_NPC::StaticClass(), NPC)
				{
					NumAIs++;
				}
				Level.Game.Stats.PlayerStats[i].StatEvent_CombatSurvivingAI(NumAIs);
				Level.Game.Stats.PlayerStats[i].StatEvent_RoundTotalPlayers(NumPlayers);
				for (p = Level.ControllerList; p != nullptr; p = p.nextController)
				{
					if (((Cast<AHumanController>(p) != nullptr) && (p.Pawn != nullptr)) && (!p.Pawn.bIsDead))
					{
						PlayersSurviving++;
					}
				}
				Level.Game.Stats.PlayerStats[i].StatEvent_RoundPlayersSurviving(PlayersSurviving);
			}
		}
		Level.Game.Stats.GameStats.StatEvent_RoundEnd();
	}
	*/
	Super::EndGame(Winner, Reason);
}

AAGP_Viewpoint* AAGP_GameTeam::GetWinningViewpoint(AAA2_PlayerState* Winner)
{
	bool bTeam0=false;
	bool bTeam1 = false;
	AAGP_Viewpoint* VP;
	if (Winner != nullptr && Winner->Team != nullptr)
	{
		if (Winner->Team->TeamIndex == 0)
		{
			bTeam0=true;
		}
		else
		{
			if (Winner->Team->TeamIndex == 1)
			{
				bTeam1=true;
			}
		}
	}

	for (VP = Cast<AAA2_WorldSettings>(GetWorldSettings())->ViewpointList; VP != nullptr; VP = VP->NextViewpoint)
	{
		switch(VP->EndGameViewpoint)
		{
		case  EEndGameViewpoint::EEGV_Always:
				return VP;
		case EEndGameViewpoint::EEGV_Team0Won:
				if (bTeam0)
				{
					return VP;
				}
				break;
		case EEndGameViewpoint::EEGV_Team1Won:
				if (bTeam1)
				{
					return VP;
				}
				break;
		case EEndGameViewpoint::EEGV_NoTeamWon:
				if (! bTeam0 && ! bTeam1)
				{
					return VP;
				}
				break;
			default:
				break;
		}
	}
	return Cast<AAA2_WorldSettings>(GetWorldSettings())->ViewpointList;
}

void AAGP_GameTeam::DoAuthenticationCheckOnWinningTeam(AAA2_PlayerState* Winner)
{
	AHumanController* HC;
	AAGP_TeamInfo* winteam;
	int32 i = 0;
	int32 iRetVal;
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::DoAuthenticationCheckOnWinningTeam() entered"));
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->CheatsDisabled())
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::DoAuthenticationCheckOnWinningTeam()	Can't authenticate on a cheat server!"));
		return;
	}
	if (Winner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::DoAuthenticationCheckOnWinningTeam() no winner"));
		return;
	}
	if (Teams[0]->Size < 1 || Teams[1]->Size < 1 && !Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::DoAuthenticationCheckOnWinningTeam() teams too small"));
		return;
	}
	winteam=Cast<AAGP_TeamInfo>(Winner->Team);
	for (i=0; i< winteam->TeamList.Max();i++)
	{
		HC=Cast<AHumanController>(winteam->TeamList[i]->GetOwner());
		if (HC != nullptr)
		{
			//if (HC.IsInState('ValidatePB') || HC.IsInState('ServerAuthorizePlayer') || HC.IsInState('FailedAuthorization'))
			//{
			//}
			iRetVal = Cast<AAA2_WorldSettings>(GetWorldSettings())->DidPlayerCompleteNewMission(HC);
			if (iRetVal == 1)
			{
				UE_LOG(LogTemp, Warning, TEXT("Signalling update to player's mission complete status."));
				HC->NotifyAuthServerOfMPMissionComplete();
			}
		}
	}
}

void AAGP_GameTeam::ResetMatchScores()
{
	int32 i = 0;
	Super::ResetMatchScores();
	for (i=0; i<2; i++)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && i > 0)
		{
		}
		Teams[i]->ResetScores();
	}
}
void AAGP_GameTeam::CheckScore(AAA2_PlayerState* Scorer)
{
	int32 i = 0;
	bool anydead = false;
	AAGP_PlayerStart* APS = nullptr;
	bool foundlegalstart = false;
	bool bAIDead = false;
	bool bPlayersDead = false;
	ANPCBaseSoldierController* npcbscIterator = nullptr;
	AHumanController* hcIterator = nullptr;
	AController* ctrlrIterator = nullptr;
	APawn* TestPawn = nullptr;
	/*
	if ((!IsInState("MatchInProgress")) && (!IsInState("DelayedMatchInProgress")))
	{
		return;
	}
	if (Level.bCoOpGame)
	{
		DebugLog(DEBUG_AI, FString::FromInt(this) + ".CheckScore() - Testing for live players on team 0: " + FString::FromInt(Teams[0].TeamDead()));
		bAIDead = true;
		bPlayersDead = true;
		for (ctrlrIterator = Level.ControllerList; ctrlrIterator != nullptr; ctrlrIterator = ctrlrIterator.nextController)
		{
			if (!ctrlrIterator->IsA(AHumanController::StaticClass()))
			{
			}
			hcIterator = Cast<AHumanController>(ctrlrIterator);
			TestPawn = hcIterator.Pawn;
			if ((TestPawn != nullptr) && (Cast<AVehicle>(TestPawn) != nullptr))
			{
				TestPawn = Vehicle(TestPawn).Driver;
			}
			if ((((TestPawn != nullptr) && (TestPawn.Health > 0)) && (!TestPawn.IsInState("Dead"))) && (!TestPawn.IsInState("Dying")))
			{
				DebugLog(DEBUG_AI, FString::FromInt(this) + ".CheckScore() - found live players");
				bPlayersDead = false;
			}
			else
			{
				hcIterator.PlayerReplicationInfo.bDead = true;
			}
		}
		for (ctrlrIterator = Level.ControllerList; ctrlrIterator != nullptr; ctrlrIterator = ctrlrIterator.nextController)
		{
			if (!ctrlrIterator->IsA(ANPCBaseSoldierController::StaticClass()))
			{
			}
			npcbscIterator = Cast<ANPCBaseSoldierController>(ctrlrIterator);
			if (npcbscIterator.IsInState("Surrender") || npcbscIterator.IsInState("Dead"))
			{
			}
			if ((npcbscIterator.Pawn != nullptr) && (npcbscIterator.Pawn.Health > 0))
			{
				DebugLog(DEBUG_AI, FString::FromInt(this) + ".CheckScore() - Found at least one AI soldier left alive: " + FString::FromInt(npcbscIterator.Tag));
				bAIDead = false;
			}
		}
		if (bAIDead && (!bPlayersDead))
		{
			DebugLog(DEBUG_AI, FString::FromInt(this) + ".CheckScore() - AI Dead, players aren't and win, end of game");
			PendingEndGame(Teams[0].GetSquadLeader(), "TeamDead");
		}
		else
		{
			if ((!bAIDead) && bPlayersDead)
			{
				DebugLog(DEBUG_AI, FString::FromInt(this) + ".CheckScore() - AI alive, players aren't, AI wins, end of game");
				PendingEndGame(nullptr, "TeamDead");
			}
			else
			{
				if ((!bPlayersDead) && (!bAIDead))
				{
					DebugLog(DEBUG_AI, FString::FromInt(this) + ".CheckScore() - everyone still alive!");
				}
			}
		}
		Super::CheckScore(Scorer);
		return;
	}
	anydead = false;
	for (i = 0; i < 2; i++)
	{
		if (Teams[i].TeamDead())
		{
			DebugLog(DEBUG_Multi, "AGP_GameTeam::CheckScore team" @ FString::FromInt(i) @ "tests dead.");
			if (Level.bAllowRespawn)
			{
				DebugLog(DEBUG_Multi, "AGP_GameTeam::CheckScore  allowsrespawn.");
				if (!Level.bUnlimitedRespawn)
				{
					foundlegalstart = false;
					ForEach AllActors(AAGP_PlayerStart::StaticClass(), APS)
					{
						if ((APS.IsEnabled() && (APS.NumSpawnsRemaining() > 0)) && (APS.GetTeamID() == i))
						{
							foundlegalstart = true;
						}
						else
						{
						}
					}
					DebugLog(DEBUG_Multi, "AGP_GameTeam::CheckScore foundlegal=" @ FString::FromInt(foundlegalstart));
					if (!foundlegalstart)
					{
						anydead = true;
						DebugLog(DEBUG_Multi, "AGP_GameTeamObjective::CheckScore() Team " + FString::FromInt(i) + " reported dead");
					}
				}
			}
			else
			{
				anydead = true;
				DebugLog(DEBUG_Multi, "AGP_GameTeamObjective::CheckScore() Team " + FString::FromInt(i) + " reported dead");
			}
		}
	}
	if (anydead)
	{
		DebugLog(DEBUG_Multi, "AGP_GameTeamObjective::CheckScore()	Anydead=" + FString::FromInt(anydead));
		if (Teams[0].TeamDead() && Teams[1].TeamDead())
		{
			PendingEndGame(nullptr, "TeamDead");
		}
		else
		{
			if (Teams[0].TeamDead())
			{
				PendingEndGame(Teams[1].GetSquadLeader(), "TeamDead");
			}
			else
			{
				PendingEndGame(Teams[0].GetSquadLeader(), "TeamDead");
			}
		}
	}
	*/
	Super::CheckScore(Scorer);
}

void AAGP_GameTeam::CheckFriendlyFireLimit(AAA2_PlayerState* Scorer)
{
	
	//APlayerController* PC;
	if (bEnableROEKickTimer)
	{
		if (GetTimeElapsed() < (8 + 10 * FMath::FRand()))
		{
			Scorer->Score_ROE=FMath::Min(Scorer->Score_ROE,- FFScoreLimit);
		}
	}
	if (bEnableROEKick)
	{
		if (Scorer->Score_ROE <= - FFScoreLimit)
		{
			if (bEnableROEKickDeath == false)
			{
				//Kick(Scorer.PlayerName,"ROE");
			}
			else
			{
				/*
				PC=Cast<APlayerController>(Scorer->GetController());
				if (PC != nullptr && PC->GetPawn() != nullptr && ! PC->GetPawn()->isDead())
				{
					PC->ClientMessage("You have been killed due to ROE violations!");
					PC->Pawn->Health=0;
					PC->Pawn->Died(nullptr,ASuicided::StaticClass(),PC.Pawn.Location);
				}
				*/
			}
		}
	}
	
}

bool AAGP_GameTeam::CanRespawn(AController* C)
{
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->bAllowRespawn)
	{
		return false;
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bUnlimitedRespawn)
	{
		return true;
	}
	if (FindPlayerStart(C,0,"") == nullptr)
	{
		return false;
	}
	return true;
}

void AAGP_GameTeam::ScoreKill(AController* Killer, AController* Other, UaDamageType* DamageType)
{
	AAGP_TeamInfo* kTeam = nullptr;
	AAGP_TeamInfo* oTeam = nullptr;
	/*
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ScoreKill() entered, coop flag: " + Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame));
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		DebugLog(DEBUG_CoOpScoring,"AGP_GameTeam::ScoreKill() in CoOp game");
		if (GetTimeElapsed() < 30 && Killer != Other)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ScoreKill() in CoOp game - player died really quick, disabling idle check"));
			if (Other != nullptr && Other->IsA(AHumanController::StaticClass()))
			{
				Cast<AHumanController>(Other).bTestedIdleRounds=true;
			}
		}
		if (Killer != nullptr && Killer->IsA(AaAIController::StaticClass()))
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ScoreKill() in CoOp game - AI killed player or another AI"));
			if (Other != nullptr && Other.PlayerReplicationInfo != nullptr)
			{
				Other.PlayerReplicationInfo.PScoreDeath();
			}
			CheckScore(nullptr);
			return;
		}
		if (Killer == Other)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ScoreKill() in CoOp game - player killed self "));
			if (Other != nullptr && Other.PlayerReplicationInfo != nullptr)
			{
				Other.PlayerReplicationInfo.PScoreDeath();
			}
			CheckScore(nullptr);
			return;
		}
		if (Other != nullptr && Other->IsA(APlayerController::StaticClass()) && Killer != nullptr && Killer->IsA(APlayerController::StaticClass()) && Killer != Other)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ScoreKill() in CoOp game - player killed teammate, performing ROE tests"));
			if (Other.PlayerReplicationInfo != nullptr)
			{
				Other.PlayerReplicationInfo.PScoreDeath();
			}
			Killer.PlayerReplicationInfo.PScoreFF(Class'Pawn'.Default.Health * 0.4);
			CheckFriendlyFireLimit(Killer.PlayerReplicationInfo);
			CheckScore(nullptr);
			return;
		}
		if (Other != nullptr && Other->IsA(AaAIController::StaticClass()))
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ScoreKill() in CoOp game - player " + Killer + " killed AI " + Other));
			if (Killer.PlayerReplicationInfo != nullptr && class<Crushed>(DamageType) == nullptr)
			{
				if (Other->IsA(ANPCBasePreCrewedVehicleControlle::StaticClass()))
				{
					DebugLog(DEBUG_CoOpScoring,"AGP_GameTeam::ScoreKill() - vehicle kill");
					Killer.PlayerReplicationInfo.PScoreAIVehicleKill();
				}
				else
				{
					DebugLog(DEBUG_CoOpScoring,"AGP_GameTeam::ScoreKill() - NPC kill");
					Killer.PlayerReplicationInfo.PScoreKill();
				}
			}
			if (GetTimeElapsed() < 30 && Killer != Other && Other->IsA(AHumanController::StaticClass()))
			{
				Cast<AHumanController>(Other).bTestedIdleRounds=true;
			}
			CheckScore(Killer.PlayerReplicationInfo);
			return;
		}
	}
	if (Other != nullptr && Other.PlayerReplicationInfo != nullptr)
	{
		oTeam=AGP_TeamInfo(Other.PlayerReplicationInfo.Team);
	}
	if (Killer.PlayerReplicationInfo != nullptr)
	{
		kTeam=AGP_TeamInfo(Killer.PlayerReplicationInfo.Team);
	}
	if (Other != nullptr && Other.PlayerReplicationInfo != nullptr)
	{
		Other.PlayerReplicationInfo.PScoreDeath();
	}
	if (Killer == nullptr || Other == nullptr)
	{
		GOTO JL07AE;
	}
	if (Killer == Other)
	{
		GOTO JL07AE;
	}
	if (Other.PlayerReplicationInfo != nullptr && Killer.PlayerReplicationInfo != nullptr && Killer.PlayerReplicationInfo.Team != Other.PlayerReplicationInfo.Team && DamageType.Default.bNoKillScore)
	{
		GOTO JL07AE;
	}
	if (Other.PlayerReplicationInfo != nullptr && Killer.PlayerReplicationInfo != nullptr && Killer.PlayerReplicationInfo.Team == Other.PlayerReplicationInfo.Team)
	{
		Killer.PlayerReplicationInfo.PScoreFF(Class'Pawn'.Default.Health * 0.4);
		CheckFriendlyFireLimit(Killer.PlayerReplicationInfo);
	}
	else
	{
		if (DamageType == nullptr || ! DamageType.Default.bNoKillScore)
		{
			if (Killer.PlayerReplicationInfo != nullptr)
			{
				Killer.PlayerReplicationInfo.PScoreKill();
JL07AE:
			}
		}
	}
	if (GetTimeElapsed() < 30 && Killer != Other)
	{
		if (Other != nullptr && Other->IsA(AHumanController::StaticClass()))
		{
			Cast<AHumanController>(Other).bTestedIdleRounds=true;
		}
	}
	if (Killer.PlayerReplicationInfo != nullptr)
	{
		CheckScore(Killer.PlayerReplicationInfo);
	}
	*/
}

void AAGP_GameTeam::RecordFriendlyFire(AAA2_PlayerState* ShooterPRI, APawn* VictimPawn, int32 FFScore)
{
	/*
	if (FFScore <= 0)
	{
		return;
	}
	if (ShooterPRI != nullptr && VictimPawn != nullptr && VictimPawn.Controller.bIsPlayer)
	{
		Broadcast(this,ShooterPRI.GetHumanReadableName() @ "Attacked Teammate " + VictimPawn.OwnerName + "!",'Event');
	}
	else
	{
		if (ShooterPRI != nullptr && VictimPawn != nullptr)
		{
			Broadcast(this,ShooterPRI.GetHumanReadableName() @ "committed an ROE violation!",'Event');
		}
	}
	if (ShooterPRI != nullptr)
	{
		BroadcastHandler.BroadcastLocalized(this,PlayerController(ShooterPRI.Owner),ACommoEventRadio::StaticClass(),0);
	}
	ShooterPRI.PScoreFF(FFScore);
	CheckFriendlyFireLimit(ShooterPRI);
	*/
}
void AAGP_GameTeam::NotifyKilled(AController* Killer, AController* Killed, APawn* KilledPawn)
{
	/*
	if (Killed == nullptr || Killed.PlayerReplicationInfo == nullptr)
	{
		return;
	}
	AGP_TeamInfo(Killed.PlayerReplicationInfo.Team).NotifyKilled(Killer,Killed,KilledPawn);
	NotifyKilled(Killer,Killed,KilledPawn);
	*/
}
void AAGP_GameTeam::EnterSpectatorMode(AController* aPlayer)
{
	/*
	EnterSpectatorMode(aPlayer);
	if (aPlayer.PlayerReplicationInfo.DesiredTeam != aPlayer.PlayerReplicationInfo.Team.TeamIndex)
	{
		RequestChangeTeam(aPlayer,aPlayer.PlayerReplicationInfo.DesiredTeam);
	}
	*/
}

void AAGP_GameTeam::RequestChangeTeam(AController* Other, int32 Num)
{
	bool bForceNotify = false;
	AAA2_PlayerState* PRI = nullptr;
	/*
	PRI=Other.PlayerReplicationInfo;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		if (Num != 254)
		{
			Num=0;
		}
	}
	if (PRI != nullptr)
	{
		if (IsTournamentMode())
		{
			Cast<APlayerController>(Other).ClientCloseMenu();
			if (Num != 254 && Num != 255)
			{
				Cast<AHumanController>(Other).TeamMessage(None,"You cannot change teams in tournament mode",'Center');
			}
			return;
		}
		if (! PRI.bReadyToPlay || PRI.Team.TeamIndex != Num)
		{
			bForceNotify=true;
		}
		if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
		{
			CheckScore(nullptr);
		}
		PRI.bReadyToPlay=true;
		if (Num == -1)
		{
			Num=GetAutoRequest(PRI.Team.TeamIndex);
		}
		if (Num == 254)
		{
			PRI.bOnlySpectator=true;
			PRI.bIsSpectator=true;
			PRI.DesiredTeam=255;
			NumSpectators ++;
			NumPlayers --;
		}
		else
		{
			PRI.DesiredTeam=Num;
		}
		UE_LOG(LogTemp, Warning, TEXT("Setting desired team: " @ Num));
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
		{
			CheckScore(nullptr);
		}
		if (PRI.DesiredTeam != 255 && PRI.DesiredTeam != 254 && PRI.Team.TeamIndex != 255)
		{
			Cast<APlayerController>(Other).ClientCloseMenu();
		}
		if (PRI.Team == SpecTeam)
		{
			ChangeTeam(Other,PRI.DesiredTeam);
		}
		Cast<AHumanController>(Other).NotifyPendingTeamChange(PRI.DesiredTeam,bForceNotify);
	}
	*/
}

int32 AAGP_GameTeam::GetAutoRequest(int32 curr)
{
	ATeamInfo* SmallTeam;
	ATeamInfo* BigTeam;
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		return 0;
	}
	else
	{
		SmallTeam=Teams[GetSmallerTeamIndex(curr)];
		BigTeam=SmallTeam->GetOtherTeam();
	}
	if (curr == 255 || SwapAPlayer(BigTeam,SmallTeam))
	{
		return SmallTeam->TeamIndex;
	}
	else
	{
		return curr;
	}
}

bool AAGP_GameTeam::MustBeSpecTeam(AController* Other)
{
	AHumanController* HC = nullptr;
	HC = Cast<AHumanController>(Other);
	if (HC != nullptr)
	{
		/*
		if (HC.IsInState('FailedAuthorization') || HC.IsInState('ServerAuthorizePlayer') || HC.IsInState('ValidatePB') || HC.PlayerReplicationInfo.bOnlySpectator)
		{
			return true;
		}
		*/
	}
	return false;
}

bool AAGP_GameTeam::ChangeTeam(AController* Other, int32 Num, bool bNewTeam)
{
	ATeamInfo* NewTeam = nullptr;
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		if (Num == 1)
		{
			Num=0;
		}
	}
	if (Num == 255 || MustBeSpecTeam(Other))
	{
		NewTeam=SpecTeam;
	}
	else
	{
		if (Num < 2)
		{
			NewTeam=Teams[PickTeam(Num,Other)];
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ChangeTeam()	Requesting invalid team " + Num));
			return false;
		}
	}
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		if (NewTeam != SpecTeam)
		{
			MaxTeamSize=NewTeam.MaxSize;
			if (MaxTeamSize > MaxPlayers)
			{
				MaxTeamSize=MaxPlayers;
			}
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ChangeTeam() MaxTeamSize for coop is: " + MaxTeamSize + " MaxPlayers: " + MaxPlayers));
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ChangeTeam() " + Other + " is trying to change to " + Num @ NewTeam));
	if (NewTeam != SpecTeam)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ChangeTeam() NewTeam: " + NewTeam + " for " + Other + ", New Team Size: " + NewTeam.Size + " MaxTeamSize: " + MaxTeamSize));
		if (NewTeam.Size >= MaxTeamSize || NewTeam.Size >= NewTeam.MaxSize)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ChangeTeam() Tried to change to full team. " + NewTeam @ Other @ Other.PlayerReplicationInfo.PlayerName));
			return false;
		}
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ChangeTeam() " + NewTeam @ Other @ "-" @ Other.PlayerReplicationInfo.Team));
		if (Other.PlayerReplicationInfo.Team == NewTeam)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::ChangeTeam() Already on team " + NewTeam @ Other @ Other.PlayerReplicationInfo.PlayerName));
			return false;
		}
		if (Other.PlayerReplicationInfo.Team == SpecTeam)
		{
			LogFileWrite("DevNet","Joined:" + NewTeam.TeamIndex + ":" + Other.PlayerReplicationInfo.PlayerName);
		}
		else
		{
			LogFileWrite("DevNet","Changed:" + NewTeam.TeamIndex + ":" + Other.PlayerReplicationInfo.PlayerName);
		}
	}
	Other.StartSpot=nullptr;
	if (Other.PlayerReplicationInfo.Team != nullptr)
	{
		Other.PlayerReplicationInfo.Team.RemoveFromTeam(Other);
	}
	if (NewTeam.AddToTeam(Other))
	{
		UE_LOG(LogTemp, Warning, TEXT(Self + ".ChangeTeam() broadcasting join"));
		BroadcastLocalizedMessage(GameMessageClass,3,Other.PlayerReplicationInfo,None,NewTeam);
	}
	UE_LOG(LogTemp, Warning, TEXT(Self + ".ChangeTeam() done"));
	*/
	return true;
}

void AAGP_GameTeam::Logout(AController* Exiting)
{
	/*
	Logout(Exiting);
	if (Exiting.PlayerReplicationInfo.Team != nullptr)
	{
		Exiting.PlayerReplicationInfo.Team.RemoveFromTeam(Exiting);
	}
	*/
}

void AAGP_GameTeam::FillSwapRequests()
{
	int32 i = 0;
	TArray<int32> max_size = { 0,0 };
	bool bCheck = false;
	TArray<AController*> SwapList0;
	TArray<AController*> SwapList1;
	AAA2_PlayerState* PRI = nullptr;
	AController* C = nullptr;
	AController* C0 = nullptr;
	AController* c1 = nullptr;
	/*
	if (Level.bCoOpGame)
	{
		return;
	}
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (C->IsA(AaAIController::StaticClass()))
		{
		}
		PRI = C.PlayerReplicationInfo;
		if (PRI.DesiredTeam != PRI.Team.TeamIndex)
		{
			switch (PRI.DesiredTeam)
			{
			case 0:
				SwapList0[SwapList0.Num()] = C;
				break;
			case 1:
				SwapList1[SwapList1.Num()] = C;
				break;
			default:
				ChangeTeam(C, PRI.DesiredTeam);
				break;
			}
		}
	}
	if ((SwapList0.Num() == 0) && (SwapList1.Num() == 0))
	{
		return;
	}
	for (i = 0; i < 2; i++)
	{
		max_size[i] = FMath::Min(MaxTeamSize, Teams[i].MaxSize);
	}
	bCheck = true;
	if (bCheck)
	{
		bCheck = false;
		if ((SwapList0.Num() > 0) && (Teams[0].Size < max_size[0]))
		{
			C = RemoveBest(SwapList0);
			ChangeTeam(C, 0);
			bCheck = true;
		}
		if ((SwapList1.Num() > 0) && (Teams[1].Size < max_size[1]))
		{
			C = RemoveBest(SwapList1);
			ChangeTeam(C, 1);
			bCheck = true;
		}
	}
	RemoveNotOnTeam(SwapList0, Teams[1]);
	RemoveNotOnTeam(SwapList1, Teams[0]);
	if ((SwapList0.Num() > 0) && (SwapList1.Num() > 0))
	{
		C0 = RemoveBest(SwapList0);
		c1 = RemoveBest(SwapList1);
		Teams[0].RemoveFromTeam(c1);
		Teams[1].RemoveFromTeam(C0);
		ChangeTeam(C0, 0);
		ChangeTeam(c1, 1);
	}
	for (i = 0; i < SwapList0.Num(); i++)
	{
		SwapList0[i].PlayerReplicationInfo.DesiredTeam = uint8(SwapList0[i].PlayerReplicationInfo.Team.TeamIndex);
	}
	for (i = 0; i < SwapList1.Num(); i++)
	{
		SwapList1[i].PlayerReplicationInfo.DesiredTeam = uint8(SwapList1[i].PlayerReplicationInfo.Team.TeamIndex);
	}
	*/
}
void AAGP_GameTeam::RemoveNotOnTeam(TArray<AController*>& SwapList, ATeamInfo* Team)
{
	/*
	int32 i = 0;
	for (i=0; i<SwapList.Num(); i++)
	{
		if (SwapList[i].PlayerReplicationInfo.Team != Team)
		{
			SwapList->Remove(i,1);
			i --;
		}
	}
	*/
}

AController* AAGP_GameTeam::RemoveBest(TArray<AController*>& SwapList)
{
	int32 i = 0;
	int32 Best = 0;
	AController* CBest = nullptr;
	/*
	if (SwapList.Num() == 0)
	{
		return nullptr;
	}
	Best=0;
	for (i=1; i<SwapList.Num(); i++)
	{
		if (SwapList[i].PlayerReplicationInfo.GetWeight() > SwapList[Best].PlayerReplicationInfo.GetWeight())
		{
			Best=i;
		}
	}
	CBest=SwapList[Best];
	SwapList->Remove(Best,1);
	*/
	return CBest;
}

void AAGP_GameTeam::NotifyRoundOver()
{
	Super::NotifyRoundOver();
	FillSwapRequests();
	if (WholeMatchOver())
	{
		Teams[0]->MatchEndReset();
		Teams[1]->MatchEndReset();
	}
}
bool AAGP_GameTeam::ConfirmReady()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		return Teams[0]->ConfirmReady() && Teams[0]->Size > 0;
	}
	else
	{
		return Teams[0]->ConfirmReady() && Teams[1]->ConfirmReady() && Teams[0]->Size + Teams[1]->Size > 0;
	}
}

bool AAGP_GameTeam::CanSpectate(APlayerController* Viewer, bool bOnlySpectator, AActor* ViewTarget)
{
	APawn* p = nullptr;
	AAGP_Viewpoint* V = nullptr;
	AController* C = nullptr;
	/*
	if (ViewTarget == nullptr)
	{
		return false;
	}
	if (Viewer.PlayerReplicationInfo == nullptr)
	{
		return false;
	}
	if (Viewer.PlayerReplicationInfo.bAdmin && Viewer.PlayerReplicationInfo.bOnlySpectator)
	{
		return true;
	}
	else
	{
		if (Viewer.PlayerReplicationInfo.SuperUser(true))
		{
			return true;
		}
	}
	if (ViewTarget->IsA(AAGP_Pawn::StaticClass()) && Cast<AAGP_Pawn>(ViewTarget).Controller != nullptr && Cast<AAGP_Pawn>(ViewTarget).Controller->IsA(ANPCBaseController::StaticClass()))
	{
		return ! bSpectateFriendsOnly;
	}
	p=Pawn(ViewTarget);
	if (p != nullptr && p.PlayerReplicationInfo != nullptr)
	{
		C=p.Controller;
		if (C.IsInState('Manning_Turret'))
		{
			return false;
		}
		if (bSpectateFriendsOnly)
		{
			if (p.PlayerReplicationInfo.bReadyToPlay)
			{
				return Viewer.PlayerReplicationInfo.IsFriend(p.PlayerReplicationInfo);
			}
			else
			{
				if (bSpectateBodies)
				{
					return p.isDead();
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			return true;
		}
	}
	if (bSpectatePlayersOnly)
	{
		return false;
	}
	V=AGP_Viewpoint(ViewTarget);
	if (V != nullptr)
	{
		if (! V.bSpectatorViewpoint)
		{
			return false;
		}
		else
		{
			if (bSpectateFriendsOnly && V.bFriendlyOnly)
			{
				return Viewer.PlayerReplicationInfo.IsFriend(None,Teams[V.TeamNumber]);
			}
			else
			{
				return true;
			}
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::CanSpectate() Unknown ViewTarget " + ViewTarget));
	*/
	return true;
}

bool AAGP_GameTeam::IsSpectatePlayersOnly()
{
	return bSpectatePlayersOnly;
}
bool AAGP_GameTeam::IsSpectateFirstPersonOnly()
{
	return bSpectateFirstPersonOnly;
}
bool AAGP_GameTeam::IsSpectateBodies()
{
	return bSpectateBodies;
}

bool AAGP_GameTeam::IsFriend(APawn* me, APawn* you)
{
	if (me == you)
	{
		return true;
	}
	return Cast<AAGP_Pawn>(me)->PlayerReplicationInfo->Team == Cast<AAGP_Pawn>(you)->PlayerReplicationInfo->Team;
}

bool AAGP_GameTeam::IsTeamFriend(uint8 Team, APawn* you)
{
	return Cast<AAGP_Pawn>(you)->PlayerReplicationInfo->Team->TeamIndex == Team;
}

bool AAGP_GameTeam::IsTeamGame()
{
	return true;
}

ATeamInfo* AAGP_GameTeam::GetTeam(uint8 Index)
{
	switch (Index)
	{
	case 0:
	case 1:
		return Teams[Index];
	case 255:
		return SpecTeam;
	default:
		return nullptr;
	}
}

ATeamInfo* AAGP_GameTeam::GetOtherTeam(uint8 Index)
{
	switch (Index)
	{
	case 0:
		return Teams[1];
	case 1:
		return Teams[0];
	default:
		return nullptr;
	}
}
uint8 AAGP_GameTeam::GetPlayerTeamIndex(AController* C)
{
	if (C == nullptr)
	{
		return 255;
	}
	if (C->IsA(AaAIController::StaticClass()))
	{
		return 2;
	}
	return Cast<AHumanController>(C)->PlayerReplicationInfo->Team->TeamIndex;
}

int32 AAGP_GameTeam::GetROELimit()
{
	return FFScoreLimit;
}

void AAGP_GameTeam::SetROEKickTimer(bool bEnabled)
{
	bEnableROEKickTimer=bEnabled;
	SaveConfig();
}

void AAGP_GameTeam::SetROEKick(bool bEnabled)
{
	bEnableROEKick=bEnabled;
	SaveConfig();
}

void AAGP_GameTeam::SetROEKickDead(bool bEnabled)
{
	bEnableROEKickDeath=bEnabled;
	SaveConfig();
}

void AAGP_GameTeam::TournamentSetPlayerTeamByString(FString S)
{
	AController* C = nullptr;
	FString PlayerName = "";
	FString s_team = "";
	int32 Team = 0;
	int32 pos = 0;
	bool bFound = false;
	/*
	pos=InStr(S," ");
	if (pos > -1)
	{
		PlayerName=Left(S,pos);
		s_team=Right(S,Len(S) - pos - 1);
		Team=s_team;
	}
	C=Level.ControllerList;
	if (C != nullptr)
	{
		if (C->IsA(AaAIController::StaticClass()))
		{
		}
		if (C.PlayerReplicationInfo.PlayerName ~= PlayerName)
		{
			C.PlayerReplicationInfo.DesiredTeam=Team;
			ChangeTeam(C,Team);
			bFound=true;
		}
		else
		{
			C=C.nextController;
		}
	}
	if (! bFound)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::TournamentSetPlayerTeamByString()	Could not find (" + PlayerName + ")"));
	}
	*/
}

void AAGP_GameTeam::TournamentSetPlayerClassByString(FString S)
{
	AController* C = nullptr;
	FString PlayerName = "";
	FString s_class = "";
	FString s_unit = "";
	FString s_index = "";
	int32 iUnit = 0;
	int32 iIndex = 0;
	int32 pos = 0;
	bool bFound = false;
	AAGP_TeamInfo* my_team = nullptr;
	/*
	pos=InStr(S," ");
	if (pos > -1)
	{
		PlayerName=Left(S,pos);
		s_class=Right(S,Len(S) - pos - 1);
		pos=InStr(s_class," ");
		s_unit=Left(s_class,pos);
		s_index=Right(s_class,Len(s_class) - pos - 1);
		iUnit=s_unit;
		iIndex=s_index;
	}
	C=Level.ControllerList;
	if (C != nullptr)
	{
		if (C->IsA(AaAIController::StaticClass()))
		{
		}
		if (C.PlayerReplicationInfo.PlayerName ~= PlayerName)
		{
			my_team=AGP_TeamInfo(C.PlayerReplicationInfo.Team);
			if (my_team.TeamIndex != 255)
			{
				my_team.TournamentSubmitPlayerRequest(C.PlayerReplicationInfo,iUnit,iIndex);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::TournamentSetPlayerClassByString() Can't set class before joining a team"));
			}
			bFound=true;
		}
		else
		{
			C=C.nextController;
		}
	}
	if (! bFound)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::TournamentSetPlayerClassByString()	Could not find (" @ PlayerName @ ")"));
	}
	*/
}

void AAGP_GameTeam::TournamentSetPlayerTeam(AAA2_PlayerState* PRI, FString SetPlayerName, int32 SetTeamID)
{
	AController* C = nullptr;
	bool bInValidParams = false;
	bool bFound = false;
	/*
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::TournamentSetPlayerTeam Part 1 SetPlayerName =" + SetPlayerName + " SetTeamID = " + SetTeamID));
	if (SetTeamID != 0 && SetTeamID != 1)
	{
		bInValidParams=true;
	}
	if (! bInValidParams)
	{
		C=Level.ControllerList;
		if (C != nullptr)
		{
			if (C->IsA(AaAIController::StaticClass()))
			{
			}
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::TournamentSetPlayerTeam SetPlayerName =" + SetPlayerName + " SetTeamID = " + SetTeamID));
			if (C.PlayerReplicationInfo.GetHumanReadableName() ~= SetPlayerName)
			{
				if (C.PlayerReplicationInfo.Team.TeamIndex == SetTeamID)
				{
					PRI.NotifyClientMessage("Player " + SetPlayerName + " already on team " + SetTeamID);
				}
				else
				{
					C.PlayerReplicationInfo.DesiredTeam=SetTeamID;
					if (ChangeTeam(C,SetTeamID))
					{
						UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::TournamentSetPlayerTeam Added =" + C.PlayerReplicationInfo.GetHumanReadableName() + " To team " + SetTeamID));
						PRI.NotifyClientMessage("Player " + SetPlayerName + " added to team " + SetTeamID);
					}
					else
					{
						PRI.NotifyClientMessage("Unable to add Player " + SetPlayerName + " to team " + SetTeamID);
					}
				}
				bFound=true;
			}
			else
			{
				C=C.nextController;
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::TournamentSetPlayerTeam() Invalid TeamID(" + SetTeamID + ")"));
		PRI.NotifyClientMessage("Unable to add Player " + SetPlayerName + " to team " + SetTeamID);
	}
	if (! bFound)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::TournamentSetPlayerTeam() Could not find PlayerID(" + SetPlayerName + ")"));
		PRI.NotifyClientMessage("Unable to add Player " + SetPlayerName + " to team " + SetTeamID);
	}
	*/
}

void AAGP_GameTeam::TournamentSetPlayerClass(AAA2_PlayerState* PRI, FString SetPlayerName, int32 SetUnitSlot, int32 SetPlayerClass)
{
	AController* C = nullptr;
	bool bFound = false;
	AAGP_TeamInfo* current_team = nullptr;
	/*
	C=Level.ControllerList;
	if (C != nullptr)
	{
		if (C->IsA(AaAIController::StaticClass()))
		{
		}
		if (C.PlayerReplicationInfo.GetHumanReadableName() ~= SetPlayerName)
		{
			current_team=AGP_TeamInfo(C.PlayerReplicationInfo.Team);
			if (current_team.TeamIndex == 255)
			{
				UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::TournamentSetPlayerClass()	Can't set class before joining a team"));
			}
			else
			{
				if (! PRI.bAdmin && current_team.TeamIndex != PRI.Team.TeamIndex)
				{
					PRI.NotifyClientMessage("Player " @ SetPlayerName @ " is not on your team.");
				}
				else
				{
					if (current_team.TournamentSubmitPlayerRequest(C.PlayerReplicationInfo,SetUnitSlot,SetPlayerClass))
					{
						PRI.NotifyClientMessage("Player " @ SetPlayerName @ " added to unit " @ SetUnitSlot @ " class " @ SetPlayerClass);
					}
					else
					{
						PRI.NotifyClientMessage("Unable to add Player " @ SetPlayerName @ " to unit " @ SetUnitSlot @ " class " @ SetPlayerClass);
					}
				}
			}
			bFound=true;
		}
		else
		{
			C=C.nextController;
		}
	}
	if (! bFound)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeam::TournamentSetPlayerClass() Could not find Player: (" @ SetPlayerName @ ")"));
		PRI.NotifyClientMessage("Unable to add Player " @ SetPlayerName @ " to unit " @ SetUnitSlot @ " class " @ SetPlayerClass);
	}
	*/
}
