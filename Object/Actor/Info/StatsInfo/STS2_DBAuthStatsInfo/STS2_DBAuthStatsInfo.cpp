// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/StatsInfo/STS2_DBAuthStatsInfo/STS2_DBAuthStatsInfo.h"
#include "AA29/Object/Actor/Info/GameStatsInfo/STS2_GameStatsInfo/STS2_GameStatsInfo.h"
#include "AA29/Object/Actor/Info/PlayerStatsInfo/STS2_PlayerStatsInfo/STS2_PlayerStatsInfo.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/STSRequestAdapter/STSRequestAdapter.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/Info/GameStatsInfo/GameStatsInfo.h"
#include "AA29/Object/Actor/Info/PlayerStatsInfo/PlayerStatsInfo.h"

ASTS2_DBAuthStatsInfo::ASTS2_DBAuthStatsInfo()
{
	GameStatsClass = Cast<AGameStatsInfo>(ASTS2_GameStatsInfo::StaticClass());				//			ASTS2_GameStatsInfo::StaticClass();
	PlayerStatsClass = Cast<APlayerStatsInfo>(ASTS2_PlayerStatsInfo::StaticClass());		//			ASTS2_PlayerStatsInfo::StaticClass();
}

bool ASTS2_DBAuthStatsInfo::Store()
{
	int32 i = 0;
	ASTSRequestAdapter* RequestAdapter = nullptr;
	ASTS2_PlayerStatsInfo* MyPlayerStats = nullptr;
	ASTS2_GameStatsInfo* MyGameStats = nullptr;
	FPlayerEvents Events;
	MyGameStats = Cast<ASTS2_GameStatsInfo>(GameStats);
	//DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - MyGameStats: " + FString::FromInt(MyGameStats));
	if (MyGameStats->ServerMode == 0)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
		{
			MyGameStats->ServerMode = 4;
		}
		else
		{
			MyGameStats->ServerMode = 3;
		}
	}
	if (MyGameStats != nullptr)
	{
		//DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - ServerMode: " + FString::FromInt(MyGameStats.ServerMode));
		//DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - Map Name: " + MyGameStats.MapName);
	}
	if ((MyGameStats == nullptr) || (!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsOfficialServer()))
	{
		//DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - invalid game state, ignore stats: " + FString::FromInt(MyGameStats) + "  Official server: " + FString::FromInt(Level.IsOfficialServer()));
		return false;
	}
	//DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - Good server, building request adapter for playerstats entries:" + FString::FromInt(PlayerStats.Num()));
	//RequestAdapter = Level.Spawn(ASTSRequestAdapter::StaticClass());
	for (i = 0; i < PlayerStats.Num(); i++)
	{
		MyPlayerStats = Cast<ASTS2_PlayerStatsInfo>(PlayerStats[i]);
		if (MyPlayerStats == nullptr)
		{
			//DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - entry " + FString::FromInt(i) + " does not have any stats");
		}
		else
		{
			//DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - building stats for entry " + FString::FromInt(i) + " -> " + FString::FromInt(MyPlayerStats));
			if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
			{
				Events.PlayerName = "ETATracking";
				Events.Password = "847";
				Events.Password = Events.Password + "sdk1";
			}
			else
			{
				Events.PlayerName = MyPlayerStats->PlayerName;
				//Events.Password = FUnload(MyPlayerStats->EncryptedPassword);
			}
			Events.Quit = MyPlayerStats->Quit;
			Events.TimePlayed = MyPlayerStats->TimePlayed;
			Events.TimeAlive = MyPlayerStats->TimeAlive;
			Events.RoundsStarted = MyPlayerStats->RoundsStarted;
			Events.RoundsWon = MyPlayerStats->RoundsWon;
			Events.RoundsLost = MyPlayerStats->RoundsLost;
			Events.RoundsSurvivedWon = MyPlayerStats->RoundsSurvivedWon;
			Events.RoundsSurvivedLost = MyPlayerStats->RoundsSurvivedLost;
			Events.SecondsAsSQL = MyPlayerStats->SecondsAsSQL;
			Events.SecondsAsFTL = MyPlayerStats->SecondsAsFTL;
			Events.SecondsAsSoldier = MyPlayerStats->SecondsAsSoldier;
			Events.Kills = MyPlayerStats->Kills;
			Events.Deaths = MyPlayerStats->Deaths;
			Events.SecondsLinkedToSQL = MyPlayerStats->SecondsLinkedToSQL;
			Events.SecondsLinkedToFTL = MyPlayerStats->SecondsLinkedToFTL;
			Events.SecondsLinkedToSoldiers = MyPlayerStats->SecondsLinkedToSoldiers;
			Events.UsedMedic = MyPlayerStats->UsedMedic;
			Events.Healed = MyPlayerStats->Healed;
			Events.MedPaksUsed = MyPlayerStats->MedPaksUsed;
			Events.Score = MyPlayerStats->Score;
			Events.ROE = MyPlayerStats->ROE;
			Events.CapturedObjective = MyPlayerStats->CapturedObjective;
			Events.ObjectiveDeaths = MyPlayerStats->ObjectiveDeaths;
			Events.AdminKicked = MyPlayerStats->AdminKicked;
			Events.PBKicked = MyPlayerStats->PBKicked;
			Events.ShotsFiredGrenade = MyPlayerStats->ShotsFiredGrenade;
			Events.ShotsFiredAstRifle = MyPlayerStats->ShotsFiredAstRifle;
			Events.ShotsFiredPistol = MyPlayerStats->ShotsFiredPistol;
			Events.ShotsFiredMG = MyPlayerStats->ShotsFiredMG;
			Events.ShotsFiredRocket = MyPlayerStats->ShotsFiredRocket;
			Events.ShotsFiredSprRifle = MyPlayerStats->ShotsFiredSprRifle;
			Events.HitsGrenade = MyPlayerStats->HitsGrenade;
			Events.HitsAstRifle = MyPlayerStats->HitsAstRifle;
			Events.HitsPistol = MyPlayerStats->HitsPistol;
			Events.HitsMG = MyPlayerStats->HitsMG;
			Events.HitsRocket = MyPlayerStats->HitsRocket;
			Events.HitsSprRifle = MyPlayerStats->HitsSprRifle;
			Events.KillsGrenade = MyPlayerStats->KillsGrenade;
			Events.KillsAstRifle = MyPlayerStats->KillsAstRifle;
			Events.KillsPistol = MyPlayerStats->KillsPistol;
			Events.KillsMG = MyPlayerStats->KillsMG;
			Events.KillsRocket = MyPlayerStats->KillsRocket;
			Events.KillsSprRifle = MyPlayerStats->KillsSprRifle;
			Events.iESSObjectAvailable = MyPlayerStats->iESSObjectAvailable;
			Events.iESSObjectDiscovered = MyPlayerStats->iESSObjectDiscovered;
			Events.iESSObjectExaminedByOtherPlayer = MyPlayerStats->iESSObjectExaminedByOtherPlayer;
			Events.iESSObjectDiscoveryRadioed = MyPlayerStats->iESSObjectDiscoveryRadioed;
			Events.iESSPostRadioExaminedObject = MyPlayerStats->iESSPostRadioExaminedObject;
			Events.iESSNoRadioExaminedObject = MyPlayerStats->iESSNoRadioExaminedObject;
			Events.iESSPostRadioLinkedObjectTaken = MyPlayerStats->iESSPostRadioLinkedObjectTaken;
			Events.iESSNoRadioLinkedObjectTaken = MyPlayerStats->iESSNoRadioLinkedObjectTaken;
			Events.iESSMissionFailureTime = MyPlayerStats->iESSMissionFailureTime;
			Events.iESSMissionSuccessTime = MyPlayerStats->iESSMissionSuccessTime;
			Events.iESSMissionProgressTime = MyPlayerStats->iESSMissionProgressTime;
			Events.iESSMissionTotalPlayers = MyPlayerStats->iESSMissionTotalPlayers;
			Events.iESSMissionSurvivingPlayers = MyPlayerStats->iESSMissionSurvivingPlayers;
			Events.iESSObjectReportedLethal = MyPlayerStats->iESSObjectReportedLethal;
			Events.iESSObjectReportedNonLethal = MyPlayerStats->iESSObjectReportedNonLethal;
			Events.iESSObjectReportableLethal = MyPlayerStats->iESSObjectReportableLethal;
			Events.iESSObjectReportableNonLethal = MyPlayerStats->iESSObjectReportableNonLethal;
			Events.iESSObjectUnreportedLocations = MyPlayerStats->iESSObjectUnreportedLocations;
			Events.iESSObjectReportingErrors = MyPlayerStats->iESSObjectReportingErrors;
			Events.iESSObjectUnnecessaryUse = MyPlayerStats->iESSObjectUnnecessaryUse;
			Events.iESSObjectDistribution = MyPlayerStats->iESSObjectDistribution;
			Events.iESSCombatHeadshots = MyPlayerStats->iESSCombatHeadshots;
			Events.iESSCombatTotalDamage = MyPlayerStats->iESSCombatTotalDamage;
			Events.iESSCombatTotalDamageRange = MyPlayerStats->iESSCombatTotalDamageRange;
			Events.iESSCombatDamageCount = MyPlayerStats->iESSCombatDamageCount;
			Events.iESSCombatEnemyContactTime = MyPlayerStats->iESSCombatEnemyContactTime;
			Events.iESSCombatAIKill = MyPlayerStats->iESSCombatAIKill;
			Events.iESSCombatSurvivingAI = MyPlayerStats->iESSCombatSurvivingAI;
			Events.iESSCombatSurvivingAILocation = MyPlayerStats->iESSCombatSurvivingAILocation;
			Events.iESSPlayerTotalDeathsByAI = MyPlayerStats->iESSPlayerTotalDeathsByAI;
			Events.iESSPlayerTotalDeathsByFriendlyFire = MyPlayerStats->iESSPlayerTotalDeathsByFriendlyFire;
			Events.iESSPlayerTotalDeathsByObject = MyPlayerStats->iESSPlayerTotalDeathsByObject;
			Events.iESSPlayerDeathLocation = MyPlayerStats->iESSPlayerDeathLocation;
			Events.iESSPlayerTotalInjuries = MyPlayerStats->iESSPlayerTotalInjuries;
			Events.iESSPlayerTotalInjuriesByAI = MyPlayerStats->iESSPlayerTotalInjuriesByAI;
			Events.iESSPlayerTotalInjuriesFriendlyFire = MyPlayerStats->iESSPlayerTotalInjuriesFriendlyFire;
			Events.iESSPlayerTotalInjuriesByObject = MyPlayerStats->iESSPlayerTotalInjuriesByObject;
			Events.iESSPlayerInjuryLocation = MyPlayerStats->iESSPlayerInjuryLocation;
			Events.iESSROEFriendlyFireHits = MyPlayerStats->iESSROEFriendlyFireHits;
			Events.iESSROEFriendlyFireDeaths = MyPlayerStats->iESSROEFriendlyFireDeaths;
			Events.iESSROEFriendlyFireHitLocation = MyPlayerStats->iESSROEFriendlyFireHitLocation;
			Events.iESSROEFriendlyFireDeathLocation = MyPlayerStats->iESSROEFriendlyFireDeathLocation;
			Events.iESSROECivilianHits = MyPlayerStats->iESSROECivilianHits;
			Events.iESSROECivilianDeaths = MyPlayerStats->iESSROECivilianDeaths;
			Events.iESSROECivilianDeathsByIED = MyPlayerStats->iESSROECivilianDeathsByIED;
			Events.iESSROECivilianHitMapLocation = MyPlayerStats->iESSROECivilianHitMapLocation;
			Events.iESSROECivilianKillByPlayerMapLocation = MyPlayerStats->iESSROECivilianKillByPlayerMapLocation;
			Events.iESSROECivilianKillByES2MapLocation = MyPlayerStats->iESSROECivilianKillByES2MapLocation;
			/*
			DebugLog(DEBUG_Scoring, "----- Sending Stats Player Slot " + FString::FromInt(i) + " -----");
			DebugLog(DEBUG_Scoring, "PlayerName = " + Events.PlayerName);
			DebugLog(DEBUG_Scoring, "Quit = " + FString::FromInt(Events.Quit));
			DebugLog(DEBUG_Scoring, "TimePlayed = " + FString::FromInt(Events.TimePlayed));
			DebugLog(DEBUG_Scoring, "TimeAlive = " + FString::FromInt(Events.TimeAlive));
			DebugLog(DEBUG_Scoring, "RoundsStarted = " + FString::FromInt(Events.RoundsStarted));
			DebugLog(DEBUG_Scoring, "RoundsWon = " + FString::FromInt(Events.RoundsWon));
			DebugLog(DEBUG_Scoring, "RoundsLost = " + FString::FromInt(Events.RoundsLost));
			DebugLog(DEBUG_Scoring, "RoundsSurvivedWon = " + FString::FromInt(Events.RoundsSurvivedWon));
			DebugLog(DEBUG_Scoring, "RoundsSurvivedLost = " + FString::FromInt(Events.RoundsSurvivedLost));
			DebugLog(DEBUG_Scoring, "SecondsAsSQL = " + FString::FromInt(Events.SecondsAsSQL));
			DebugLog(DEBUG_Scoring, "SecondsAsFTL = " + FString::FromInt(Events.SecondsAsFTL));
			DebugLog(DEBUG_Scoring, "SecondsAsSoldier = " + FString::FromInt(Events.SecondsAsSoldier));
			DebugLog(DEBUG_Scoring, "Kills = " + FString::FromInt(Events.Kills));
			DebugLog(DEBUG_Scoring, "Deaths = " + FString::FromInt(Events.Deaths));
			DebugLog(DEBUG_Scoring, "SecondsLinkedToSQL = " + FString::FromInt(Events.SecondsLinkedToSQL));
			DebugLog(DEBUG_Scoring, "SecondsLinkedToFTL = " + FString::FromInt(Events.SecondsLinkedToFTL));
			DebugLog(DEBUG_Scoring, "SecondsLinkedToSoldiers = " + FString::FromInt(Events.SecondsLinkedToSoldiers));
			DebugLog(DEBUG_Scoring, "UsedMedic = " + FString::FromInt(Events.UsedMedic));
			DebugLog(DEBUG_Scoring, "Healed = " + FString::FromInt(Events.Healed));
			DebugLog(DEBUG_Scoring, "MedPaksUsed = " + FString::FromInt(Events.MedPaksUsed));
			DebugLog(DEBUG_Scoring, "Score = " + FString::FromInt(Events.Score));
			DebugLog(DEBUG_Scoring, "ROE = " + FString::FromInt(Events.ROE));
			DebugLog(DEBUG_Scoring, "CapturedObjective = " + FString::FromInt(Events.CapturedObjective));
			DebugLog(DEBUG_Scoring, "ObjectiveDeaths = " + FString::FromInt(Events.ObjectiveDeaths));
			DebugLog(DEBUG_Scoring, "AdminKicked = " + FString::FromInt(Events.AdminKicked));
			DebugLog(DEBUG_Scoring, "PBKicked = " + FString::FromInt(Events.PBKicked));
			DebugLog(DEBUG_Scoring, "ShotsFiredGrenade = " + FString::FromInt(Events.ShotsFiredGrenade));
			DebugLog(DEBUG_Scoring, "ShotsFiredAstRifle = " + FString::FromInt(Events.ShotsFiredAstRifle));
			DebugLog(DEBUG_Scoring, "ShotsFiredPistol = " + FString::FromInt(Events.ShotsFiredPistol));
			DebugLog(DEBUG_Scoring, "ShotsFiredMG = " + FString::FromInt(Events.ShotsFiredMG));
			DebugLog(DEBUG_Scoring, "ShotsFiredRocket = " + FString::FromInt(Events.ShotsFiredRocket));
			DebugLog(DEBUG_Scoring, "ShotsFiredSprRifle = " + FString::FromInt(Events.ShotsFiredSprRifle));
			DebugLog(DEBUG_Scoring, "HitsGrenade = " + FString::FromInt(Events.HitsGrenade));
			DebugLog(DEBUG_Scoring, "HitsAstRifle = " + FString::FromInt(Events.HitsAstRifle));
			DebugLog(DEBUG_Scoring, "HitsPistol = " + FString::FromInt(Events.HitsPistol));
			DebugLog(DEBUG_Scoring, "HitsMG = " + FString::FromInt(Events.HitsMG));
			DebugLog(DEBUG_Scoring, "HitsRocket = " + FString::FromInt(Events.HitsRocket));
			DebugLog(DEBUG_Scoring, "HitsSprRifle = " + FString::FromInt(Events.HitsSprRifle));
			DebugLog(DEBUG_Scoring, "KillsGrenade = " + FString::FromInt(Events.KillsGrenade));
			DebugLog(DEBUG_Scoring, "KillsAstRifle = " + FString::FromInt(Events.KillsAstRifle));
			DebugLog(DEBUG_Scoring, "KillsPistol = " + FString::FromInt(Events.KillsPistol));
			DebugLog(DEBUG_Scoring, "KillsMG = " + FString::FromInt(Events.KillsMG));
			DebugLog(DEBUG_Scoring, "KillsRocket = " + FString::FromInt(Events.KillsRocket));
			DebugLog(DEBUG_Scoring, "KillsSprRifle = " + FString::FromInt(Events.KillsSprRifle));
			DebugLog(DEBUG_Scoring, "ESS Objects Available: " + FString::FromInt(Events.iESSObjectAvailable));
			DebugLog(DEBUG_Scoring, "ESS Objects Discovered: " + FString::FromInt(Events.iESSObjectDiscovered));
			DebugLog(DEBUG_Scoring, "ESS Objects Examined By Other Players: " + FString::FromInt(Events.iESSObjectExaminedByOtherPlayer));
			DebugLog(DEBUG_Scoring, "ESS Objects Discovery Radioed: " + FString::FromInt(Events.iESSObjectDiscoveryRadioed));
			DebugLog(DEBUG_Scoring, "ESS Objects Post Radio Examined: " + FString::FromInt(Events.iESSPostRadioExaminedObject));
			DebugLog(DEBUG_Scoring, "ESS Objects No Radio Examined: " + FString::FromInt(Events.iESSNoRadioExaminedObject));
			DebugLog(DEBUG_Scoring, "ESS Objects Post Radio Linked Objective Taken: " + FString::FromInt(Events.iESSPostRadioLinkedObjectTaken));
			DebugLog(DEBUG_Scoring, "ESS Objects No Radio Linked Objective Taken: " + FString::FromInt(Events.iESSNoRadioLinkedObjectTaken));
			DebugLog(DEBUG_Scoring, "    ");
			*/
			RequestAdapter->AddPlayerEvents(Events);
		}
	}
	//DebugLog(DEBUG_Scoring, "STS2_DBAuthStatsInfo.Store() - Transmitting stats for map " + MyGameStats.MapName + ", rounds: " + FString::FromInt(MyGameStats.RoundsPlayed) + ", Play Time: " + FString::FromInt(MyGameStats.PlayTime));
	//RequestAdapter.Request(MyGameStats.IP, MyGameStats.Port, MyGameStats.ServerMode, MyGameStats.MapName, "", MyGameStats.RoundsPlayed, MyGameStats.PlayTime);
	return true;
}
