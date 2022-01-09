// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/StatsInfo/STS2_LogStatsInfo/STS2_LogStatsInfo.h"
#include "AA29/Object/Actor/Info/GameStatsInfo/STS2_GameStatsInfo/STS2_GameStatsInfo.h"
#include "AA29/Object/Actor/Info/PlayerStatsInfo/STS2_PlayerStatsInfo/STS2_PlayerStatsInfo.h"

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
		//Log(" IP:" @ MyGameStats.IP);
		//Log(" Port:" @ string(MyGameStats.Port));
		//Log(" ServerMode:" @ string(MyGameStats.ServerMode));
		//Log(" PlayerCount:" @ string(MyPlayerCount));
		//Log(" MapName:" @ MyGameStats.MapName);
		//Log(" TourID:" @ string(MyGameStats.TourID));
		//Log(" MissionID:" @ string(MyGameStats.MissionID));
		//Log(" RoundsPlayed:" @ string(MyGameStats.RoundsPlayed));
		//Log(" GameVersion:" @ MyGameStats.GameVersion);
		//Log(" PlayTime:" @ string(MyGameStats.PlayTime));
	}
	for (i = 0; i < PlayerStats.Num(); i++)
	{
		MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(PlayerStats[i]);
		if (MyPlayerStats != nullptr)
		{
			//Log(" Player Name:" @ MyPlayerStats.PlayerName);
			//Log(" Player Password(Encrypted):" @ MyPlayerStats.EncryptedPassword);
			//Log("  RoundsStarted:" @ string(MyPlayerStats.RoundsStarted));
			//Log("  RoundsWon:" @ string(MyPlayerStats.RoundsWon));
			//Log("  RoundsLost:" @ string(MyPlayerStats.RoundsLost));
			//Log("  RoundsSurvivedWon:" @ string(MyPlayerStats.RoundsSurvivedWon));
			//Log("  RoundsSurvivedLost:" @ string(MyPlayerStats.RoundsSurvivedLost));
			//Log("  SecondsAsSQL:" @ string(MyPlayerStats.SecondsAsSQL));
			//Log("  SecondsAsFTL:" @ string(MyPlayerStats.SecondsAsFTL));
			//Log("  SecondsAsSoldier:" @ string(MyPlayerStats.SecondsAsSoldier));
			//Log("  SecondsLinkedToSQL:" @ string(MyPlayerStats.SecondsLinkedToSQL));
			//Log("  SecondsLinkedToFTL:" @ string(MyPlayerStats.SecondsLinkedToFTL));
			//Log("  SecondsLinkedToSoldiers:" @ string(MyPlayerStats.SecondsLinkedToSoldiers));
			//Log("  Quit:" @ string(MyPlayerStats.Quit));
			//Log("  AdminKicked:" @ string(MyPlayerStats.AdminKicked));
			//Log("  PBKicked:" @ string(MyPlayerStats.PBKicked));
			//Log("  Kills:" @ string(MyPlayerStats.Kills));
			//Log("  Deaths:" @ string(MyPlayerStats.Deaths));
			//Log("  CapturedObjective:" @ string(MyPlayerStats.CapturedObjective));
			//Log("  ObjectiveDeaths:" @ string(MyPlayerStats.ObjectiveDeaths));
			//Log("  Score:" @ string(MyPlayerStats.Score));
			//Log("  ROE:" @ string(MyPlayerStats.ROE));
			//Log("  ShotsFiredGrenade:" @ string(MyPlayerStats.ShotsFiredGrenade));
			//Log("  ShotsFiredAstRifle:" @ string(MyPlayerStats.ShotsFiredAstRifle));
			//Log("  ShotsFiredPistol:" @ string(MyPlayerStats.ShotsFiredPistol));
			//Log("  ShotsFiredMG:" @ string(MyPlayerStats.ShotsFiredMG));
			//Log("  ShotsFiredRocket:" @ string(MyPlayerStats.ShotsFiredRocket));
			//Log("  ShotsFiredSprRifle:" @ string(MyPlayerStats.ShotsFiredSprRifle));
			//Log("  HitsGrenade:" @ string(MyPlayerStats.HitsGrenade));
			//Log("  HitsAstRifle:" @ string(MyPlayerStats.HitsAstRifle));
			//Log("  HitsPistol:" @ string(MyPlayerStats.HitsPistol));
			//Log("  HitsMG:" @ string(MyPlayerStats.HitsMG));
			//Log("  HitsRocket:" @ string(MyPlayerStats.HitsRocket));
			//Log("  HitsSprRifle:" @ string(MyPlayerStats.HitsSprRifle));
			//Log("  KillsGrenade:" @ string(MyPlayerStats.KillsGrenade));
			//Log("  KillsAstRifle:" @ string(MyPlayerStats.KillsAstRifle));
			//Log("  KillsPistol:" @ string(MyPlayerStats.KillsPistol));
			//Log("  KillsMG:" @ string(MyPlayerStats.KillsMG));
			//Log("  KillsRocket:" @ string(MyPlayerStats.KillsRocket));
			//Log("  KillsSprRifle:" @ string(MyPlayerStats.KillsSprRifle));
			//Log("  UsedMedic:" @ string(MyPlayerStats.UsedMedic));
			//Log("  Healed:" @ string(MyPlayerStats.Healed));
			//Log("  MedPaksUsed:" @ string(MyPlayerStats.MedPaksUsed));
			//Log("  TimePlayed:" @ string(MyPlayerStats.TimePlayed));
			//Log("  TimeAlive:" @ string(MyPlayerStats.TimeAlive));
		}
	}
	return true;
}
