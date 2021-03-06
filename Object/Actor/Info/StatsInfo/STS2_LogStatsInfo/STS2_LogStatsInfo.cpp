// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/StatsInfo/STS2_LogStatsInfo/STS2_LogStatsInfo.h"
#include "AA29/Object/Actor/Info/GameStatsInfo/STS2_GameStatsInfo/STS2_GameStatsInfo.h"
#include "AA29/Object/Actor/Info/PlayerStatsInfo/STS2_PlayerStatsInfo/STS2_PlayerStatsInfo.h"
#include "AA29/Object/Actor/Info/GameStatsInfo/GameStatsInfo.h"
#include "AA29/Object/Actor/Info/PlayerStatsInfo/PlayerStatsInfo.h"

ASTS2_LogStatsInfo::ASTS2_LogStatsInfo()
{
	GameStatsClass = Cast<AGameStatsInfo>(ASTS2_GameStatsInfo::StaticClass());
	PlayerStatsClass = Cast<APlayerStatsInfo>(ASTS2_PlayerStatsInfo::StaticClass());
}

void ASTS2_LogStatsInfo::IgnoreStatsThisRound()
{
	UE_LOG(LogTemp,Log, TEXT("Would have ignored stats until end of round (stats never ignored for logfile)"));
}

bool ASTS2_LogStatsInfo::Store()
{
	int32 i = 0;
	ASTS2_GameStatsInfo* MyGameStats = nullptr;
	ASTS2_PlayerStatsInfo* MyPlayerStats = nullptr;
	int32 MyPlayerCount = 0;
	UE_LOG(LogTemp, Log, TEXT("Store called for STS2_LogStatsInfo..."));
	MyGameStats = Cast<ASTS2_GameStatsInfo>(GameStats);
	if (MyGameStats != nullptr)
	{
		for (i = 0; i < PlayerStats.Num(); i++)
		{
			MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(PlayerStats[i]);
			if (MyPlayerStats != nullptr)
			{
				MyPlayerCount++;
			}
		}
		UE_LOG(LogTemp, Log, TEXT(" IP:%s"), *MyGameStats->IP);
		UE_LOG(LogTemp, Log, TEXT(" Port:%d"), MyGameStats->Port);
		UE_LOG(LogTemp, Log, TEXT(" ServerMode:%d"), MyGameStats->ServerMode);
		UE_LOG(LogTemp, Log, TEXT(" PlayerCount:%d"), MyPlayerCount);
		UE_LOG(LogTemp, Log, TEXT(" MapName:%s"), *MyGameStats->MapName);
		UE_LOG(LogTemp, Log, TEXT(" TourID:%d"), MyGameStats->TourID);
		UE_LOG(LogTemp, Log, TEXT(" MissionID:%d"), MyGameStats->MissionID);
		UE_LOG(LogTemp, Log, TEXT(" RoundsPlayed:%d"), MyGameStats->RoundsPlayed);
		UE_LOG(LogTemp, Log, TEXT(" GameVersion:%s"), *MyGameStats->GameVersion);
		UE_LOG(LogTemp, Log, TEXT(" PlayTime:%d"), MyGameStats->PlayTime);
	}
	for (i = 0; i < PlayerStats.Num(); i++)
	{
		MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(PlayerStats[i]);
		if (MyPlayerStats != nullptr)
		{
			UE_LOG(LogTemp, Log, TEXT(" Player Name:%s"), *MyPlayerStats->PlayerName);
			UE_LOG(LogTemp, Log, TEXT(" Player Password(Encrypted):%s"), *MyPlayerStats->EncryptedPassword);
			UE_LOG(LogTemp, Log, TEXT("  RoundsStarted:%d"), MyPlayerStats->RoundsStarted);
			UE_LOG(LogTemp, Log, TEXT("  RoundsWon:%d"), MyPlayerStats->RoundsWon);
			UE_LOG(LogTemp, Log, TEXT("  RoundsLost:%d"), MyPlayerStats->RoundsLost);
			UE_LOG(LogTemp, Log, TEXT("  RoundsSurvivedWon:%d"), MyPlayerStats->RoundsSurvivedWon);
			UE_LOG(LogTemp, Log, TEXT("  RoundsSurvivedLost:%d"), MyPlayerStats->RoundsSurvivedLost);
			UE_LOG(LogTemp, Log, TEXT("  SecondsAsSQL:%d"), MyPlayerStats->SecondsAsSQL);
			UE_LOG(LogTemp, Log, TEXT("  SecondsAsFTL:%d"), MyPlayerStats->SecondsAsFTL);
			UE_LOG(LogTemp, Log, TEXT("  SecondsAsSoldier:%d"), MyPlayerStats->SecondsAsSoldier);
			UE_LOG(LogTemp, Log, TEXT("  SecondsLinkedToSQL:%d"), MyPlayerStats->SecondsLinkedToSQL);
			UE_LOG(LogTemp, Log, TEXT("  SecondsLinkedToFTL:%d"), MyPlayerStats->SecondsLinkedToFTL);
			UE_LOG(LogTemp, Log, TEXT("  SecondsLinkedToSoldiers:%d"), MyPlayerStats->SecondsLinkedToSoldiers);
			UE_LOG(LogTemp, Log, TEXT("  Quit:%d"), MyPlayerStats->Quit);
			UE_LOG(LogTemp, Log, TEXT("  AdminKicked:%d"), MyPlayerStats->AdminKicked);
			UE_LOG(LogTemp, Log, TEXT("  PBKicked:%d"), MyPlayerStats->PBKicked);
			UE_LOG(LogTemp, Log, TEXT("  Kills:%d"), MyPlayerStats->Kills);
			UE_LOG(LogTemp, Log, TEXT("  Deaths:%d"), MyPlayerStats->Deaths);
			UE_LOG(LogTemp, Log, TEXT("  CapturedObjective:%d"), MyPlayerStats->CapturedObjective);
			UE_LOG(LogTemp, Log, TEXT("  ObjectiveDeaths:%d"), MyPlayerStats->ObjectiveDeaths);
			UE_LOG(LogTemp, Log, TEXT("  Score:%d"), MyPlayerStats->Score);
			UE_LOG(LogTemp, Log, TEXT("  ROE:%d"), MyPlayerStats->ROE);
			UE_LOG(LogTemp, Log, TEXT("  ShotsFiredGrenade:%d"), MyPlayerStats->ShotsFiredGrenade);
			UE_LOG(LogTemp, Log, TEXT("  ShotsFiredAstRifle:%d"), MyPlayerStats->ShotsFiredAstRifle);
			UE_LOG(LogTemp, Log, TEXT("  ShotsFiredPistol:%d"), MyPlayerStats->ShotsFiredPistol);
			UE_LOG(LogTemp, Log, TEXT("  ShotsFiredMG:%d"), MyPlayerStats->ShotsFiredMG);
			UE_LOG(LogTemp, Log, TEXT("  ShotsFiredRocket:%d"), MyPlayerStats->ShotsFiredRocket);
			UE_LOG(LogTemp, Log, TEXT("  ShotsFiredSprRifle:%d"), MyPlayerStats->ShotsFiredSprRifle);
			UE_LOG(LogTemp, Log, TEXT("  HitsGrenade:%d"), MyPlayerStats->HitsGrenade);
			UE_LOG(LogTemp, Log, TEXT("  HitsAstRifle:%d"), MyPlayerStats->HitsAstRifle);
			UE_LOG(LogTemp, Log, TEXT("  HitsPistol:%d"), MyPlayerStats->HitsPistol);
			UE_LOG(LogTemp, Log, TEXT("  HitsMG:%d"), MyPlayerStats->HitsMG);
			UE_LOG(LogTemp, Log, TEXT("  HitsRocket:%d"), MyPlayerStats->HitsRocket);
			UE_LOG(LogTemp, Log, TEXT("  HitsSprRifle:%d"), MyPlayerStats->HitsSprRifle);
			UE_LOG(LogTemp, Log, TEXT("  KillsGrenade:%d"), MyPlayerStats->KillsGrenade);
			UE_LOG(LogTemp, Log, TEXT("  KillsAstRifle:%d"), MyPlayerStats->KillsAstRifle);
			UE_LOG(LogTemp, Log, TEXT("  KillsPistol:%d"), MyPlayerStats->KillsPistol);
			UE_LOG(LogTemp, Log, TEXT("  KillsMG:%d"), MyPlayerStats->KillsMG);
			UE_LOG(LogTemp, Log, TEXT("  KillsRocket:%d"), MyPlayerStats->KillsRocket);
			UE_LOG(LogTemp, Log, TEXT("  KillsSprRifle:%d"), MyPlayerStats->KillsSprRifle);
			UE_LOG(LogTemp, Log, TEXT("  UsedMedic:%d"), MyPlayerStats->UsedMedic);
			UE_LOG(LogTemp, Log, TEXT("  Healed:%d"), MyPlayerStats->Healed);
			UE_LOG(LogTemp, Log, TEXT("  MedPaksUsed:%d"), MyPlayerStats->MedPaksUsed);
			UE_LOG(LogTemp, Log, TEXT("  TimePlayed:%d"), MyPlayerStats->TimePlayed);
			UE_LOG(LogTemp, Log, TEXT("  TimeAlive:%d"), MyPlayerStats->TimeAlive);
		}
	}
	return true;
}
