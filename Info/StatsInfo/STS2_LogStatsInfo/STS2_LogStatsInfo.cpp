// All the original content belonged to the US Army


#include "AA29/Info/StatsInfo/STS2_LogStatsInfo/STS2_LogStatsInfo.h"
#include "AA29/Info/GameStatsInfo/STS2_GameStatsInfo/STS2_GameStatsInfo.h"
#include "AA29/Info/PlayerStatsInfo/STS2_PlayerStatsInfo/STS2_PlayerStatsInfo.h"

ASTS2_LogStatsInfo::ASTS2_LogStatsInfo()
{
	GameStatsClass = Cast<AGameStatsInfo>(ASTS2_GameStatsInfo::StaticClass());			//			class'AGP.STS2_GameStatsInfo';
	PlayerStatsClass = Cast<APlayerStatsInfo>(ASTS2_PlayerStatsInfo::StaticClass());		//			class'AGP.STS2_PlayerStatsInfo';
}

void ASTS2_LogStatsInfo::IgnoreStatsThisRound()
{
	//DebugLog(DEBUG_Stats, "Would have ignored stats until end of round (stats never ignored for logfile)");
}
bool ASTS2_LogStatsInfo::Store()
{
	/*
	local int i;
	local STS2_GameStatsInfo MyGameStats;
	local STS2_PlayerStatsInfo MyPlayerStats;
	local int MyPlayerCount;
	Log("Store called for STS2_LogStatsInfo...");
	MyGameStats = STS2_GameStatsInfo(GameStats);
	if (MyGameStats != None)
	{
		for (i = 0; i < PlayerStats.Length; i++)
		{
			MyPlayerStats = STS2_PlayerStatsInfo(PlayerStats[i]);
			if (MyPlayerStats != None)
			{
				++MyPlayerCount;
			}
		}
		Log(" IP:" @ MyGameStats.IP);
		Log(" Port:" @ MyGameStats.Port);
		Log(" ServerMode:" @ MyGameStats.ServerMode);
		Log(" PlayerCount:" @ MyPlayerCount);
		Log(" MapName:" @ MyGameStats.MapName);
		Log(" TourID:" @ MyGameStats.TourID);
		Log(" MissionID:" @ MyGameStats.MissionID);
		Log(" RoundsPlayed:" @ MyGameStats.RoundsPlayed);
		Log(" GameVersion:" @ MyGameStats.GameVersion);
		Log(" PlayTime:" @ MyGameStats.PlayTime);
	}
	for (i = 0; i < PlayerStats.Length; i++)
	{
		MyPlayerStats = STS2_PlayerStatsInfo(PlayerStats[i]);
		if (MyPlayerStats != None)
		{
			Log(" Player Name:" @ MyPlayerStats.PlayerName);
			Log(" Player Password(Encrypted):" @ MyPlayerStats.EncryptedPassword);
			Log("  RoundsStarted:" @ MyPlayerStats.RoundsStarted);
			Log("  RoundsWon:" @ MyPlayerStats.RoundsWon);
			Log("  RoundsLost:" @ MyPlayerStats.RoundsLost);
			Log("  RoundsSurvivedWon:" @ MyPlayerStats.RoundsSurvivedWon);
			Log("  RoundsSurvivedLost:" @ MyPlayerStats.RoundsSurvivedLost);
			Log("  SecondsAsSQL:" @ MyPlayerStats.SecondsAsSQL);
			Log("  SecondsAsFTL:" @ MyPlayerStats.SecondsAsFTL);
			Log("  SecondsAsSoldier:" @ MyPlayerStats.SecondsAsSoldier);
			Log("  SecondsLinkedToSQL:" @ MyPlayerStats.SecondsLinkedToSQL);
			Log("  SecondsLinkedToFTL:" @ MyPlayerStats.SecondsLinkedToFTL);
			Log("  SecondsLinkedToSoldiers:" @ MyPlayerStats.SecondsLinkedToSoldiers);
			Log("  Quit:" @ MyPlayerStats.Quit);
			Log("  AdminKicked:" @ MyPlayerStats.AdminKicked);
			Log("  PBKicked:" @ MyPlayerStats.PBKicked);
			Log("  Kills:" @ MyPlayerStats.Kills);
			Log("  Deaths:" @ MyPlayerStats.Deaths);
			Log("  CapturedObjective:" @ MyPlayerStats.CapturedObjective);
			Log("  ObjectiveDeaths:" @ MyPlayerStats.ObjectiveDeaths);
			Log("  Score:" @ MyPlayerStats.Score);
			Log("  ROE:" @ MyPlayerStats.ROE);
			Log("  ShotsFiredGrenade:" @ MyPlayerStats.ShotsFiredGrenade);
			Log("  ShotsFiredAstRifle:" @ MyPlayerStats.ShotsFiredAstRifle);
			Log("  ShotsFiredPistol:" @ MyPlayerStats.ShotsFiredPistol);
			Log("  ShotsFiredMG:" @ MyPlayerStats.ShotsFiredMG);
			Log("  ShotsFiredRocket:" @ MyPlayerStats.ShotsFiredRocket);
			Log("  ShotsFiredSprRifle:" @ MyPlayerStats.ShotsFiredSprRifle);
			Log("  HitsGrenade:" @ MyPlayerStats.HitsGrenade);
			Log("  HitsAstRifle:" @ MyPlayerStats.HitsAstRifle);
			Log("  HitsPistol:" @ MyPlayerStats.HitsPistol);
			Log("  HitsMG:" @ MyPlayerStats.HitsMG);
			Log("  HitsRocket:" @ MyPlayerStats.HitsRocket);
			Log("  HitsSprRifle:" @ MyPlayerStats.HitsSprRifle);
			Log("  KillsGrenade:" @ MyPlayerStats.KillsGrenade);
			Log("  KillsAstRifle:" @ MyPlayerStats.KillsAstRifle);
			Log("  KillsPistol:" @ MyPlayerStats.KillsPistol);
			Log("  KillsMG:" @ MyPlayerStats.KillsMG);
			Log("  KillsRocket:" @ MyPlayerStats.KillsRocket);
			Log("  KillsSprRifle:" @ MyPlayerStats.KillsSprRifle);
			Log("  UsedMedic:" @ MyPlayerStats.UsedMedic);
			Log("  Healed:" @ MyPlayerStats.Healed);
			Log("  MedPaksUsed:" @ MyPlayerStats.MedPaksUsed);
			Log("  TimePlayed:" @ MyPlayerStats.TimePlayed);
			Log("  TimeAlive:" @ MyPlayerStats.TimeAlive);
		}
	}
	*/
	return true;
}