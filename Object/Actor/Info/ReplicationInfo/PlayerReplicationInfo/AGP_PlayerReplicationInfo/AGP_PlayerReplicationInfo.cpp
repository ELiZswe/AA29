// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/AGP_PlayerReplicationInfo/AGP_PlayerReplicationInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"

AAGP_PlayerReplicationInfo::AAGP_PlayerReplicationInfo()
{

}

void AAGP_PlayerReplicationInfo::Reset()
{
	Super::Reset();
	Score_Total = 0;
	Score_Leadership = 0;
	Score_Wins = 0;
	Score_Objectives = 0;
	Score_Deaths = 0;
	Score_Kills = 0;
	Score_ROE = 0;
	HasFlag = nullptr;
	bReadyToPlay = false;
	NumLives = 0;
	bOutOfLives = false;
}

FString AAGP_PlayerReplicationInfo::GetSquadName()
{
	return SquadName;
}

bool AAGP_PlayerReplicationInfo::EquivalentName(FString Name)
{
	if (Name.Compare(PlayerName,ESearchCase::IgnoreCase))
	{
		return true;
	}
	else
	{
		/*
		if (FString::ToInt(Name) == PlayerId)
		{
			return true;
		}
		else
		{
			if (Name.Compare(SquadName + PlayerName, ESearchCase::IgnoreCase))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		*/
	}
	return false;     //FAKE   /ELiZ
}

void AAGP_PlayerReplicationInfo::NotifyPromotion(bool bFTL, uint8 yFT)
{
	//PlayerController(GetOwner())->NotifyPromotion(bFTL, yFT);
}

void AAGP_PlayerReplicationInfo::NotifyNoScore(FName Reason)
{
	_cumRounds++;
	//PlayerController(GetOwner())->NotifyNoScore(Reason);
}

void AAGP_PlayerReplicationInfo::NotifyClientMessage(FString Message)
{
	//PlayerController(GetOwner())->ClientMessage(Message);
}

void AAGP_PlayerReplicationInfo::CalculateWeight(float maxScore)
{
	float roe_lim = 0;
	float froe = 0;
	float fscore = 0;
	/*
	fscore = (float((Score_Total * 100)) / maxScore);
	roe_lim = float(Level.Game.GetROELimit());
	froe = ((roe_lim + float(Score_ROE)) / roe_lim);
	froe = float(Min(int(froe), int(0.99)));
	_fWeight = ((froe + float(_iTrust)) + float(int(fscore)));
	*/
}

float AAGP_PlayerReplicationInfo::GetWeight()
{
	return _fWeight;
}

int32 AAGP_PlayerReplicationInfo::GetHonor()
{
	return _iTrust;
}

bool AAGP_PlayerReplicationInfo::HasGroupIcon()
{
	return ((_Group > 0) && (_Group < 20));
}

uint8 AAGP_PlayerReplicationInfo::GetGroup()
{
	return _Group;
}

void AAGP_PlayerReplicationInfo::SetGroup(uint8 newgroup)
{
	_Group = newgroup;
}

void AAGP_PlayerReplicationInfo::SUToggle()
{
	if (SuperUser(false))
	{
		bSUEnabled = (!bSUEnabled);
		NotifyClientMessage("SuperUser set to " +  bSUEnabled ? TEXT("true") : TEXT("false"));
	}
}

bool AAGP_PlayerReplicationInfo::SuperUser(bool bCheckEnabled)
{
	switch (_Group)
	{
	case 1:	//Dev
	case 2:	//ArmyDev
	case 3:	//HomeLAN
	case 7: //SCI
	case 20: //AGA
		if (bCheckEnabled) { return bSUEnabled; }
		else { return true; }
	default:
		return false;
	}
}

bool AAGP_PlayerReplicationInfo::Administrator()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsOfficialServer() && (!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer()))
	{
		if (SuperUser(false))
		{
			return bAdmin;
		}
		else
		{
			return false;
		}
	}
	return bAdmin;
}

int32 AAGP_PlayerReplicationInfo::GetExperience()
{
	return _Experience;
}

int32 AAGP_PlayerReplicationInfo::GetCumRounds()
{
	return _cumRounds;
}

int32 AAGP_PlayerReplicationInfo::GetPlayTime()
{
	return int((GetWorld()->GetTimeSeconds() - float(_LastTimeUpdate)));
}

AController* AAGP_PlayerReplicationInfo::GetController()
{
	return Cast<AController>(GetOwner());
}

void AAGP_PlayerReplicationInfo::ResetPerRound()
{
	APlayerController* PC = nullptr;
	votekick = "";
	bIsMedic = false;
	bCallForMedic = false;
	bGuerrillaPS = false;
	bSpecialForcesPS = false;
	bVIPPS = false;
	/*
	if (Level.Game.Stats != nullptr)
	{
		PC = Cast<APlayerController>(GetOwner());
		if ((PC != nullptr) && (PC->PlayerStatsIndex >= 0))
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ScoreChange((Score_Total - _prevTotal));
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ROEChange((Score_ROE - _prevROE));
		}
	}
	*/
	_prevTotal = Score_Total;
	_prevLeadership = Score_Leadership;
	_prevWins = Score_Wins;
	_prevObjectives = Score_Objectives;
	_prevDeaths = Score_Deaths;
	_prevKills = Score_Kills;
	_prevROE = Score_ROE;
}

int32 AAGP_PlayerReplicationInfo::GetRoundScore_Total()
{
	return (Score_Total - _prevTotal);
}

int32 AAGP_PlayerReplicationInfo::GetRoundScore_Leadership()
{
	return (Score_Leadership - _prevLeadership);
}

int32 AAGP_PlayerReplicationInfo::GetRoundScore_Wins()
{
	return (Score_Wins - _prevWins);
}

int32 AAGP_PlayerReplicationInfo::GetRoundScore_Objectives()
{
	return (Score_Objectives - _prevObjectives);
}

int32 AAGP_PlayerReplicationInfo::GetRoundScore_Deaths()
{
	return (Score_Deaths - _prevDeaths);
}

int32 AAGP_PlayerReplicationInfo::GetRoundScore_Kills()
{
	return (Score_Kills - _prevKills);
}

int32 AAGP_PlayerReplicationInfo::GetRoundScore_ROE()
{
	return (Score_ROE - _prevROE);
}

void AAGP_PlayerReplicationInfo::ClientNotifyLostMedic()
{
	bLostMedic = true;
}

int32 AAGP_PlayerReplicationInfo::GetGoalScore()
{
	return (Score_Wins + Score_Objectives);
}

void AAGP_PlayerReplicationInfo::UpdateScore()
{
	Score_Total = 0;
	Score_Total += FMath::Max(0, Score_Leadership);
	Score_Total += Score_Wins;
	Score_Total += Score_Objectives;
	Score_Total += FMath::Max(0, (Score_Kills + Score_Deaths));
	Score_Total += Score_ROE;
}

void AAGP_PlayerReplicationInfo::PScoreKill()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		Score_Kills += 5;
	}
	else
	{
		Score_Kills += 10;
	}
	UpdateScore();
}

void AAGP_PlayerReplicationInfo::PScoreDeath()
{
	Score_Deaths -= 10;
	UpdateScore();
}

void AAGP_PlayerReplicationInfo::PScoreFF(int32 newscore)
{
	Score_ROE -= newscore;
	Score_Total -= newscore;
}

bool AAGP_PlayerReplicationInfo::CheckROE()
{
	//return ((-Score_ROE) > Level.Game.GetROELimit());
	return false;     //FAKE   /ELiZ
}

void AAGP_PlayerReplicationInfo::ScoreDecoMesh(int32 DestroyPoints)
{
	if (DestroyPoints != 0)
	{
		(Score_Objectives += DestroyPoints);
		(Score_Total += DestroyPoints);
	}
	else
	{
		(Score_Objectives += 20);
		(Score_Total += 20);
	}
}

void AAGP_PlayerReplicationInfo::PScoreObjective(int32 newscore)
{
	if (bWaitingPlayer)
	{
		return;
	}
	if (newscore > 500)
	{
		newscore = 0;
	}
	(Score_Objectives += newscore);
	(Score_Total += newscore);
}

void AAGP_PlayerReplicationInfo::ScoreRound(bool bWon)
{
	if (bWaitingPlayer)
	{
		return;
	}
	_cumRounds++;
	if (bWon)
	{
		Score_Wins += Team->GetWinBonus(!isDead());
		if (!isDead())
		{
			Score_Leadership += CalculateLeaderScore();
		}
	}
	else
	{
		Score_Leadership -= CalculateLeaderPenalty();
	}
	UpdateScore();
}

float AAGP_PlayerReplicationInfo::GetMultiplier()
{
	float fMultiplier = 0;
	int32 OtherTeamSize = 0;
	OtherTeamSize = Team->GetOtherTeam()->Size;
	fMultiplier = ((0.25 * Team->NumAlive(false,0)) + 0.25);
	(fMultiplier *= (OtherTeamSize / Team->Size));
	if (Team->Size != Team->NumAlive(false,0))
	{
		fMultiplier *= ((0.7 * Team->NumAlive(false,0)) / Team->Size);
	}
	return FMath::Max(FMath::FloorToInt(fMultiplier), 1);
}

int32 AAGP_PlayerReplicationInfo::GetSLBonus()
{
	switch (Team->TeamIndex)
	{
	case 0:
		return Cast<AAA2_WorldSettings>(GetWorldSettings())->Score_Team0_SquadLeaderBonusPerSurvivor;
	case 1:
		return Cast<AAA2_WorldSettings>(GetWorldSettings())->Score_Team1_SquadLeaderBonusPerSurvivor;
	default:
		return 0;
	}
}

int32 AAGP_PlayerReplicationInfo::GetFTLBonus()
{
	switch (Team->TeamIndex)
	{
	case 0:
		return Cast<AAA2_WorldSettings>(GetWorldSettings())->Score_Team0_FTLeaderBonusPerSurvivor;
	case 1:
		return Cast<AAA2_WorldSettings>(GetWorldSettings())->Score_Team1_FTLeaderBonusPerSurvivor;
	default:
		return 0;
	}
}

APlayerStart* AAGP_PlayerReplicationInfo::GetPlayerStart()
{
	return Cast<APlayerStart>(Cast<AController>(GetOwner())->StartSpot);
}

int32 AAGP_PlayerReplicationInfo::CalculateLeaderScore()
{
	int32 bonus = 0;
	APlayerStart* PS = nullptr;
	if (IsSquadLeader())
	{
		(bonus += (Team->NumAlive(false,0) * GetSLBonus()));
	}
	else
	{
		if (isTeamLeader())
		{
			(bonus += (Team->NumAlive(true, FT) * GetFTLBonus()));
		}
	}
	/*
	if ((!isDead()) && (Team->NumAlive() > 3))
	{
		PS = PlayerStart(Cast<AController>(GetOwner())->StartSpot);
		if (PS->bSquadLeader)
		{
			(bonus += 20);
		}
		else
		{
			if (PS->bFTLeader)
			{
				(bonus += 10);
			}
		}
	}
	*/
	return bonus;
}

int32 AAGP_PlayerReplicationInfo::CalculateLeaderPenalty()
{
	APlayerStart* PS = nullptr;
	/*
	PS = PlayerStart(Cast<AController>(GetOwner())->StartSpot);
	if (PS->bSquadLeader)
	{
		return 10;
	}
	else
	{
		if (PS->bFTLeader)
		{
			return 5;
		}
	}
	*/
	return 0;      //FAKE  /ELiZ
}

void AAGP_PlayerReplicationInfo::IncrementCumulativeScores()
{
	(_cumTotal += Score_Total);
	(_cumLeadership += Score_Leadership);
	(_cumWins += Score_Wins);
	(_cumObjectives += Score_Objectives);
	(_cumDeaths += Score_Deaths);
	(_cumKills += Score_Kills);
	(_cumROE += Score_ROE);
}

int32 AAGP_PlayerReplicationInfo::CalculateExperience()
{
	int32 newExperience = 0;
	(newExperience += FMath::Max(0, _cumLeadership));
	(newExperience += _cumWins);
	(newExperience += _cumObjectives);
	(newExperience += FMath::Max(0, (_cumKills + _cumDeaths)));
	(newExperience += _cumROE);
	return newExperience;
}

bool AAGP_PlayerReplicationInfo::hasSoldiersCharacter()
{
	return _bSoldiersCharacter;
}

bool AAGP_PlayerReplicationInfo::IsFriend(AAA2_PlayerState* Other, ATeamInfo* otherTeam)
{
	if ((otherTeam == nullptr) && (Other != nullptr))
	{
		otherTeam = Other->Team;
	}
	if ((Team == nullptr) || (otherTeam == nullptr))
	{
		return (Other == this);
	}
	return (Team == otherTeam);
}

bool AAGP_PlayerReplicationInfo::IsEnemy(AAA2_PlayerState* Other, ATeamInfo* otherTeam)
{
	return (!IsFriend(Other, otherTeam));
}

void AAGP_PlayerReplicationInfo::TeamReset()
{
}

FVector AAGP_PlayerReplicationInfo::GetPawnLocation()
{
	FVector loc = FVector(0, 0, 0);
	if (myPawn != nullptr)
	{
		return myPawn->GetActorLocation();
	}
	else
	{
		loc.X = float(LocationX);
		loc.Y = float(LocationY);
		loc.Z = float(LocationZ);
		return loc;
	}
}

void AAGP_PlayerReplicationInfo::ServerSetMyPawn(APawn* new_pawn)
{
	myPawn = new_pawn;
	//DebugLog(DEBUG_Multi, "PlayerReplicationInfo::ServerSetMyPawn()	" + FString::FromInt(new_pawn));
}

void AAGP_PlayerReplicationInfo::WaitingForPawn(AAA2_PlayerState* PRI)
{
	//DebugLog(DEBUG_Spec, "PlayerReplicationInfo::WaitingForPawn()	" + FString::FromInt(this) @ FString::FromInt(PRI));
	if (myPawn != nullptr)
	{
		PRI->FoundWaitingForPawn(myPawn);
	}
	else
	{
		PRI_WaitingForPawn = PRI;
	}
}

void AAGP_PlayerReplicationInfo::FoundWaitingForPawn(APawn* p)
{
	APlayerController* C = nullptr;
	//DebugLog(DEBUG_Spec, "PlayerReplicationInfo::FoundWaitingForPawn()	" + FString::FromInt(this) @ FString::FromInt(p));
	C = Cast<APlayerController>(GetOwner());
	if (C != nullptr)
	{
		//C->FoundWaitingForPawn(p);
	}
}

APawn* AAGP_PlayerReplicationInfo::GetMyPawn()
{
	return myPawn;
}

bool AAGP_PlayerReplicationInfo::isDead()
{
	return ((((bDead || IsSpectator()) || IsOnlyASpectator()) || bWaitingPlayer) || bOutOfLives);
}

bool AAGP_PlayerReplicationInfo::isSpectator()
{
	return (IsSpectator() || IsOnlyASpectator());
}

bool AAGP_PlayerReplicationInfo::IsSquadLeader()
{
	return (GetSquadLeader() == this);
}

bool AAGP_PlayerReplicationInfo::isTeamLeader()
{
	return (GetFTLeader() == this);
}

AAA2_PlayerState* AAGP_PlayerReplicationInfo::GetSquadLeader()
{
	if (Team != nullptr)
	{
		return Team->GetSquadLeader(this);
	}
	else
	{
		return this;
	}
}

AAA2_PlayerState* AAGP_PlayerReplicationInfo::GetFTLeader()
{
	if (Team != nullptr)
	{
		return Team->GetFTLeader(this);
	}
	else
	{
		return this;
	}
}

void AAGP_PlayerReplicationInfo::SubmitPlayerRequest(int32 UnitID, int32 Index)
{
	Team->SubmitPlayerRequest(this, UnitID, Index);
}

void AAGP_PlayerReplicationInfo::RemovePlayerRequest(AAA2_PlayerState* PRI)
{
	if (Team->TeamIndex == 255)
	{
		PRI->Team->RemovePlayerRequest(PRI);
	}
	else
	{
		Team->RemovePlayerRequest(PRI);
	}
}
