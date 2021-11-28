// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/StatsInfo/STS2_DBAuthStatsInfo/STS2_DBAuthStatsInfo.h"
#include "AA29/Object/Actor/Info/GameStatsInfo/STS2_GameStatsInfo/STS2_GameStatsInfo.h"
#include "AA29/Object/Actor/Info/PlayerStatsInfo/STS2_PlayerStatsInfo/STS2_PlayerStatsInfo.h"

ASTS2_DBAuthStatsInfo::ASTS2_DBAuthStatsInfo()
{
	GameStatsClass = Cast<AGameStatsInfo>(ASTS2_GameStatsInfo::StaticClass());				//			class'AGP.STS2_GameStatsInfo';
	PlayerStatsClass = Cast<APlayerStatsInfo>(ASTS2_PlayerStatsInfo::StaticClass());		//			class'AGP.STS2_PlayerStatsInfo';
}

void ASTS2_DBAuthStatsInfo::Store()
{
	/*
	local int i;
	local DBAuth.STSRequestAdapter RequestAdapter;
	local STS2_PlayerStatsInfo MyPlayerStats;
	local STS2_GameStatsInfo MyGameStats;
	local STSRequestAdapter.PlayerEvents Events;
	MyGameStats = STS2_GameStatsInfo(GameStats);
	DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - MyGameStats: " $ MyGameStats);
	if (MyGameStats.ServerMode == 0)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
		{
			MyGameStats.ServerMode = 4;
		}
		else
		{
			MyGameStats.ServerMode = 3;
		}
	}
	if (MyGameStats != None)
	{
		DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - ServerMode: " $ MyGameStats.ServerMode);
		DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - Map Name: " $ MyGameStats.MapName);
	}
	if (MyGameStats == None || !Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
	{
		DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - invalid game state, ignore stats: " $ MyGameStats $ "  Official server: " $ Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer());
		Return False;
	}
	DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - Good server, building request adapter for playerstats entries:" $ PlayerStats.Length);
	RequestAdapter = Level.Spawn(Class'STSRequestAdapter');
	for (i = 0; i < PlayerStats.Length; i++)
	{
		MyPlayerStats = STS2_PlayerStatsInfo(PlayerStats[i]);
		if (MyPlayerStats == None)
		{
			DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - entry " $ i $ " does not have any stats");
		}
		else
		{
			DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - building stats for entry " $ i $ " -> " $ MyPlayerStats);
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
			{
				Events.PlayerName = "ETATracking";
				Events.Password = "847";
				Events.Password = Events.Password $ "sdk" $ 1;
			}
			else
			{
				Events.PlayerName = MyPlayerStats.PlayerName;
				Events.Password = FUnload(MyPlayerStats.EncryptedPassword);
			}
			Events.Quit = MyPlayerStats.Quit;
			Events.TimePlayed = MyPlayerStats.TimePlayed;
			Events.TimeAlive = MyPlayerStats.TimeAlive;
			Events.RoundsStarted = MyPlayerStats.RoundsStarted;
			Events.RoundsWon = MyPlayerStats.RoundsWon;
			Events.RoundsLost = MyPlayerStats.RoundsLost;
			Events.RoundsSurvivedWon = MyPlayerStats.RoundsSurvivedWon;
			Events.RoundsSurvivedLost = MyPlayerStats.RoundsSurvivedLost;
			Events.SecondsAsSQL = MyPlayerStats.SecondsAsSQL;
			Events.SecondsAsFTL = MyPlayerStats.SecondsAsFTL;
			Events.SecondsAsSoldier = MyPlayerStats.SecondsAsSoldier;
			Events.Kills = MyPlayerStats.Kills;
			Events.Deaths = MyPlayerStats.Deaths;
			Events.SecondsLinkedToSQL = MyPlayerStats.SecondsLinkedToSQL;
			Events.SecondsLinkedToFTL = MyPlayerStats.SecondsLinkedToFTL;
			Events.SecondsLinkedToSoldiers = MyPlayerStats.SecondsLinkedToSoldiers;
			Events.UsedMedic = MyPlayerStats.UsedMedic;
			Events.Healed = MyPlayerStats.Healed;
			Events.MedPaksUsed = MyPlayerStats.MedPaksUsed;
			Events.Score = MyPlayerStats.Score;
			Events.ROE = MyPlayerStats.ROE;
			Events.CapturedObjective = MyPlayerStats.CapturedObjective;
			Events.ObjectiveDeaths = MyPlayerStats.ObjectiveDeaths;
			Events.AdminKicked = MyPlayerStats.AdminKicked;
			Events.PBKicked = MyPlayerStats.PBKicked;
			Events.ShotsFiredGrenade = MyPlayerStats.ShotsFiredGrenade;
			Events.ShotsFiredAstRifle = MyPlayerStats.ShotsFiredAstRifle;
			Events.ShotsFiredPistol = MyPlayerStats.ShotsFiredPistol;
			Events.ShotsFiredMG = MyPlayerStats.ShotsFiredMG;
			Events.ShotsFiredRocket = MyPlayerStats.ShotsFiredRocket;
			Events.ShotsFiredSprRifle = MyPlayerStats.ShotsFiredSprRifle;
			Events.HitsGrenade = MyPlayerStats.HitsGrenade;
			Events.HitsAstRifle = MyPlayerStats.HitsAstRifle;
			Events.HitsPistol = MyPlayerStats.HitsPistol;
			Events.HitsMG = MyPlayerStats.HitsMG;
			Events.HitsRocket = MyPlayerStats.HitsRocket;
			Events.HitsSprRifle = MyPlayerStats.HitsSprRifle;
			Events.KillsGrenade = MyPlayerStats.KillsGrenade;
			Events.KillsAstRifle = MyPlayerStats.KillsAstRifle;
			Events.KillsPistol = MyPlayerStats.KillsPistol;
			Events.KillsMG = MyPlayerStats.KillsMG;
			Events.KillsRocket = MyPlayerStats.KillsRocket;
			Events.KillsSprRifle = MyPlayerStats.KillsSprRifle;
			Events.iESSObjectAvailable = MyPlayerStats.iESSObjectAvailable;
			Events.iESSObjectDiscovered = MyPlayerStats.iESSObjectDiscovered;
			Events.iESSObjectExaminedByOtherPlayer = MyPlayerStats.iESSObjectExaminedByOtherPlayer;
			Events.iESSObjectDiscoveryRadioed = MyPlayerStats.iESSObjectDiscoveryRadioed;
			Events.iESSPostRadioExaminedObject = MyPlayerStats.iESSPostRadioExaminedObject;
			Events.iESSNoRadioExaminedObject = MyPlayerStats.iESSNoRadioExaminedObject;
			Events.iESSPostRadioLinkedObjectTaken = MyPlayerStats.iESSPostRadioLinkedObjectTaken;
			Events.iESSNoRadioLinkedObjectTaken = MyPlayerStats.iESSNoRadioLinkedObjectTaken;
			Events.iESSMissionFailureTime = MyPlayerStats.iESSMissionFailureTime;
			Events.iESSMissionSuccessTime = MyPlayerStats.iESSMissionSuccessTime;
			Events.iESSMissionProgressTime = MyPlayerStats.iESSMissionProgressTime;
			Events.iESSMissionTotalPlayers = MyPlayerStats.iESSMissionTotalPlayers;
			Events.iESSMissionSurvivingPlayers = MyPlayerStats.iESSMissionSurvivingPlayers;
			Events.iESSObjectReportedLethal = MyPlayerStats.iESSObjectReportedLethal;
			Events.iESSObjectReportedNonLethal = MyPlayerStats.iESSObjectReportedNonLethal;
			Events.iESSObjectReportableLethal = MyPlayerStats.iESSObjectReportableLethal;
			Events.iESSObjectReportableNonLethal = MyPlayerStats.iESSObjectReportableNonLethal;
			Events.iESSObjectUnreportedLocations = MyPlayerStats.iESSObjectUnreportedLocations;
			Events.iESSObjectReportingErrors = MyPlayerStats.iESSObjectReportingErrors;
			Events.iESSObjectUnnecessaryUse = MyPlayerStats.iESSObjectUnnecessaryUse;
			Events.iESSObjectDistribution = MyPlayerStats.iESSObjectDistribution;
			Events.iESSCombatHeadshots = MyPlayerStats.iESSCombatHeadshots;
			Events.iESSCombatTotalDamage = MyPlayerStats.iESSCombatTotalDamage;
			Events.iESSCombatTotalDamageRange = MyPlayerStats.iESSCombatTotalDamageRange;
			Events.iESSCombatDamageCount = MyPlayerStats.iESSCombatDamageCount;
			Events.iESSCombatEnemyContactTime = MyPlayerStats.iESSCombatEnemyContactTime;
			Events.iESSCombatAIKill = MyPlayerStats.iESSCombatAIKill;
			Events.iESSCombatSurvivingAI = MyPlayerStats.iESSCombatSurvivingAI;
			Events.iESSCombatSurvivingAILocation = MyPlayerStats.iESSCombatSurvivingAILocation;
			Events.iESSPlayerTotalDeathsByAI = MyPlayerStats.iESSPlayerTotalDeathsByAI;
			Events.iESSPlayerTotalDeathsByFriendlyFire = MyPlayerStats.iESSPlayerTotalDeathsByFriendlyFire;
			Events.iESSPlayerTotalDeathsByObject = MyPlayerStats.iESSPlayerTotalDeathsByObject;
			Events.iESSPlayerDeathLocation = MyPlayerStats.iESSPlayerDeathLocation;
			Events.iESSPlayerTotalInjuries = MyPlayerStats.iESSPlayerTotalInjuries;
			Events.iESSPlayerTotalInjuriesByAI = MyPlayerStats.iESSPlayerTotalInjuriesByAI;
			Events.iESSPlayerTotalInjuriesFriendlyFire = MyPlayerStats.iESSPlayerTotalInjuriesFriendlyFire;
			Events.iESSPlayerTotalInjuriesByObject = MyPlayerStats.iESSPlayerTotalInjuriesByObject;
			Events.iESSPlayerInjuryLocation = MyPlayerStats.iESSPlayerInjuryLocation;
			Events.iESSROEFriendlyFireHits = MyPlayerStats.iESSROEFriendlyFireHits;
			Events.iESSROEFriendlyFireDeaths = MyPlayerStats.iESSROEFriendlyFireDeaths;
			Events.iESSROEFriendlyFireHitLocation = MyPlayerStats.iESSROEFriendlyFireHitLocation;
			Events.iESSROEFriendlyFireDeathLocation = MyPlayerStats.iESSROEFriendlyFireDeathLocation;
			Events.iESSROECivilianHits = MyPlayerStats.iESSROECivilianHits;
			Events.iESSROECivilianDeaths = MyPlayerStats.iESSROECivilianDeaths;
			Events.iESSROECivilianDeathsByIED = MyPlayerStats.iESSROECivilianDeathsByIED;
			Events.iESSROECivilianHitMapLocation = MyPlayerStats.iESSROECivilianHitMapLocation;
			Events.iESSROECivilianKillByPlayerMapLocation = MyPlayerStats.iESSROECivilianKillByPlayerMapLocation;
			Events.iESSROECivilianKillByES2MapLocation = MyPlayerStats.iESSROECivilianKillByES2MapLocation;
			DebugLog(DEBUG_Scoring, "----- Sending Stats Player Slot " $ i $ " -----");
			DebugLog(DEBUG_Scoring, "PlayerName = " $ Events.PlayerName);
			DebugLog(DEBUG_Scoring, "Quit = " $ Events.Quit);
			DebugLog(DEBUG_Scoring, "TimePlayed = " $ Events.TimePlayed);
			DebugLog(DEBUG_Scoring, "TimeAlive = " $ Events.TimeAlive);
			DebugLog(DEBUG_Scoring, "RoundsStarted = " $ Events.RoundsStarted);
			DebugLog(DEBUG_Scoring, "RoundsWon = " $ Events.RoundsWon);
			DebugLog(DEBUG_Scoring, "RoundsLost = " $ Events.RoundsLost);
			DebugLog(DEBUG_Scoring, "RoundsSurvivedWon = " $ Events.RoundsSurvivedWon);
			DebugLog(DEBUG_Scoring, "RoundsSurvivedLost = " $ Events.RoundsSurvivedLost);
			DebugLog(DEBUG_Scoring, "SecondsAsSQL = " $ Events.SecondsAsSQL);
			DebugLog(DEBUG_Scoring, "SecondsAsFTL = " $ Events.SecondsAsFTL);
			DebugLog(DEBUG_Scoring, "SecondsAsSoldier = " $ Events.SecondsAsSoldier);
			DebugLog(DEBUG_Scoring, "Kills = " $ Events.Kills);
			DebugLog(DEBUG_Scoring, "Deaths = " $ Events.Deaths);
			DebugLog(DEBUG_Scoring, "SecondsLinkedToSQL = " $ Events.SecondsLinkedToSQL);
			DebugLog(DEBUG_Scoring, "SecondsLinkedToFTL = " $ Events.SecondsLinkedToFTL);
			DebugLog(DEBUG_Scoring, "SecondsLinkedToSoldiers = " $ Events.SecondsLinkedToSoldiers);
			DebugLog(DEBUG_Scoring, "UsedMedic = " $ Events.UsedMedic);
			DebugLog(DEBUG_Scoring, "Healed = " $ Events.Healed);
			DebugLog(DEBUG_Scoring, "MedPaksUsed = " $ Events.MedPaksUsed);
			DebugLog(DEBUG_Scoring, "Score = " $ Events.Score);
			DebugLog(DEBUG_Scoring, "ROE = " $ Events.ROE);
			DebugLog(DEBUG_Scoring, "CapturedObjective = " $ Events.CapturedObjective);
			DebugLog(DEBUG_Scoring, "ObjectiveDeaths = " $ Events.ObjectiveDeaths);
			DebugLog(DEBUG_Scoring, "AdminKicked = " $ Events.AdminKicked);
			DebugLog(DEBUG_Scoring, "PBKicked = " $ Events.PBKicked);
			DebugLog(DEBUG_Scoring, "ShotsFiredGrenade = " $ Events.ShotsFiredGrenade);
			DebugLog(DEBUG_Scoring, "ShotsFiredAstRifle = " $ Events.ShotsFiredAstRifle);
			DebugLog(DEBUG_Scoring, "ShotsFiredPistol = " $ Events.ShotsFiredPistol);
			DebugLog(DEBUG_Scoring, "ShotsFiredMG = " $ Events.ShotsFiredMG);
			DebugLog(DEBUG_Scoring, "ShotsFiredRocket = " $ Events.ShotsFiredRocket);
			DebugLog(DEBUG_Scoring, "ShotsFiredSprRifle = " $ Events.ShotsFiredSprRifle);
			DebugLog(DEBUG_Scoring, "HitsGrenade = " $ Events.HitsGrenade);
			DebugLog(DEBUG_Scoring, "HitsAstRifle = " $ Events.HitsAstRifle);
			DebugLog(DEBUG_Scoring, "HitsPistol = " $ Events.HitsPistol);
			DebugLog(DEBUG_Scoring, "HitsMG = " $ Events.HitsMG);
			DebugLog(DEBUG_Scoring, "HitsRocket = " $ Events.HitsRocket);
			DebugLog(DEBUG_Scoring, "HitsSprRifle = " $ Events.HitsSprRifle);
			DebugLog(DEBUG_Scoring, "KillsGrenade = " $ Events.KillsGrenade);
			DebugLog(DEBUG_Scoring, "KillsAstRifle = " $ Events.KillsAstRifle);
			DebugLog(DEBUG_Scoring, "KillsPistol = " $ Events.KillsPistol);
			DebugLog(DEBUG_Scoring, "KillsMG = " $ Events.KillsMG);
			DebugLog(DEBUG_Scoring, "KillsRocket = " $ Events.KillsRocket);
			DebugLog(DEBUG_Scoring, "KillsSprRifle = " $ Events.KillsSprRifle);
			DebugLog(DEBUG_Scoring, "ESS Objects Available: " $ Events.iESSObjectAvailable);
			DebugLog(DEBUG_Scoring, "ESS Objects Discovered: " $ Events.iESSObjectDiscovered);
			DebugLog(DEBUG_Scoring, "ESS Objects Examined By Other Players: " $ Events.iESSObjectExaminedByOtherPlayer);
			DebugLog(DEBUG_Scoring, "ESS Objects Discovery Radioed: " $ Events.iESSObjectDiscoveryRadioed);
			DebugLog(DEBUG_Scoring, "ESS Objects Post Radio Examined: " $ Events.iESSPostRadioExaminedObject);
			DebugLog(DEBUG_Scoring, "ESS Objects No Radio Examined: " $ Events.iESSNoRadioExaminedObject);
			DebugLog(DEBUG_Scoring, "ESS Objects Post Radio Linked Objective Taken: " $ Events.iESSPostRadioLinkedObjectTaken);
			DebugLog(DEBUG_Scoring, "ESS Objects No Radio Linked Objective Taken: " $ Events.iESSNoRadioLinkedObjectTaken);
			DebugLog(DEBUG_Scoring, "    ");
			RequestAdapter.AddPlayerEvents(Events);
		}
	}
	DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - Transmitting stats for map " $ MyGameStats.MapName $ ", rounds: " $ MyGameStats.RoundsPlayed $ ", Play Time: " $ MyGameStats.PlayTime);
	RequestAdapter.Request(MyGameStats.IP, MyGameStats.Port, MyGameStats.ServerMode, MyGameStats.MapName, "", MyGameStats.RoundsPlayed, MyGameStats.PlayTime);
	Return True;
	*/
}