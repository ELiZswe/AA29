// All the original content belonged to the US Army


#include "AA29/Info/PlayerStatsInfo/STS2_PlayerStatsInfo/STS2_PlayerStatsInfo.h"

ASTS2_PlayerStatsInfo::ASTS2_PlayerStatsInfo()
{

}

int32 ASTS2_PlayerStatsInfo::QueryCapturedObjectives()
{
	return CapturedObjective;
}
int32 ASTS2_PlayerStatsInfo::QueryCapturedObjectiveDeaths()
{
	return ObjectiveDeaths;
}
int32 ASTS2_PlayerStatsInfo::QueryHealed()
{
	return Healed;
}
int32 ASTS2_PlayerStatsInfo::QueryUsedMedic()
{
	return UsedMedic;
}
int32 ASTS2_PlayerStatsInfo::QueryMedPacksUsed()
{
	return MedPaksUsed;
}
int32 ASTS2_PlayerStatsInfo::QueryTimePlayedSeconds()
{
	return TimePlayed;
}
int32 ASTS2_PlayerStatsInfo::QueryTimeAliveSeconds()
{
	return TimeAlive;
}
int32 ASTS2_PlayerStatsInfo::QueryRoundStarted()
{
	return RoundsStarted;
}
int32 ASTS2_PlayerStatsInfo::QueryRoundsSurvivedWon()
{
	return RoundsSurvivedWon;
}
int32 ASTS2_PlayerStatsInfo::QueryRoundsSurvivedLost()
{
	return RoundsSurvivedLost;
}
int32 ASTS2_PlayerStatsInfo::QueryShotsFiredMachineGun()
{
	return ShotsFiredMG;
}
int32 ASTS2_PlayerStatsInfo::QueryShotsFiredAssaultRifle()
{
	return ShotsFiredAstRifle;
}
int32 ASTS2_PlayerStatsInfo::QueryShotsFiredPistol()
{
	return ShotsFiredPistol;
}
int32 ASTS2_PlayerStatsInfo::QueryShotsFiredGrenade()
{
	return ShotsFiredGrenade;
}
int32 ASTS2_PlayerStatsInfo::QueryShotsFiredSniper()
{
	return ShotsFiredSprRifle;
}
int32 ASTS2_PlayerStatsInfo::QueryShotsFiredRocket()
{
	return ShotsFiredRocket;
}
int32 ASTS2_PlayerStatsInfo::QueryShotsHitMachineGun()
{
	return HitsMG;
}
int32 ASTS2_PlayerStatsInfo::QueryShotsHitAssaultRifle()
{
	return HitsAstRifle;
}
int32 ASTS2_PlayerStatsInfo::QueryShotsHitPistol()
{
	return HitsPistol;
}
int32 ASTS2_PlayerStatsInfo::QueryShotsHitGrenade()
{
	return HitsGrenade;
}
int32 ASTS2_PlayerStatsInfo::QueryShotsHitSniper()
{
	return HitsSprRifle;
}
int32 ASTS2_PlayerStatsInfo::QueryShotsHitRocket()
{
	return HitsRocket;
}
int32 ASTS2_PlayerStatsInfo::QueryESSObjectAvailable()
{
	return iESSObjectAvailable;
}
int32 ASTS2_PlayerStatsInfo::QueryESSObjectDiscovered()
{
	return iESSObjectDiscovered;
}
int32 ASTS2_PlayerStatsInfo::QueryESSObjectExaminedByOtherPlayer()
{
	return iESSObjectExaminedByOtherPlayer;
}
int32 ASTS2_PlayerStatsInfo::QueryESSObjectDiscoveryRadioed()
{
	return iESSObjectDiscoveryRadioed;
}
int32 ASTS2_PlayerStatsInfo::QueryESSPostRadioExaminedObject()
{
	return iESSPostRadioExaminedObject;
}
int32 ASTS2_PlayerStatsInfo::QueryESSNoRadioExaminedObject()
{
	return iESSNoRadioExaminedObject;
}
int32 ASTS2_PlayerStatsInfo::QueryESSPostRadioLinkedObjectTaken()
{
	return iESSPostRadioLinkedObjectTaken;
}
int32 ASTS2_PlayerStatsInfo::QueryESSNoRadioLinkedObjectTaken()
{
	return iESSNoRadioLinkedObjectTaken;
}
void ASTS2_PlayerStatsInfo::StatEvent_ScoreChange(int DeltaScore)
{
	//DebugLog(DEBUG_Stats, PlayerName @ "gained" @ DeltaScore @ "points");
	Score += DeltaScore;
}
void ASTS2_PlayerStatsInfo::StatEvent_ROEChange(int32 DeltaROE)
{
	//DebugLog(DEBUG_Stats, PlayerName @ "accrued" @ DeltaROE @ "ROE");
	ROE += DeltaROE;
}
void ASTS2_PlayerStatsInfo::StatEvent_Kill()
{
	//DebugLog(DEBUG_Stats, PlayerName @ "scored a kill");
	++Kills;
}
void ASTS2_PlayerStatsInfo::StatEvent_Death(FVector KilledLocation)
{
	//DebugLog(DEBUG_Stats, PlayerName @ "scored a death");
	++Deaths;
	bPlayerIsAlive = false;
	if (LastSpawnTime != 0)
	{
		TimeAlive += GetWorld()->GetTimeSeconds() - LastSpawnTime;
	}
	DeathLocations.Add(KilledLocation);
}
void ASTS2_PlayerStatsInfo::StatEvent_Quit()
{
	//DebugLog(DEBUG_Stats, PlayerName @ "quit the server");
	bPlayerQuit = true;
	++Quit;
}
void ASTS2_PlayerStatsInfo::StatEvent_RoundStartedAsMedic()
{
	//DebugLog(DEBUG_Stats, PlayerName @ "started as medic");
	++UsedMedic;
}
void ASTS2_PlayerStatsInfo::StatEvent_WasHealed()
{
	//DebugLog(DEBUG_Stats, PlayerName @ "was healed");
	++Healed;
}
void ASTS2_PlayerStatsInfo::StatEvent_HealedTeammate()
{
	//DebugLog(DEBUG_Stats, PlayerName @ "healed another player with a medpak");
	++MedPaksUsed;
}
void ASTS2_PlayerStatsInfo::StatEvent_RoundStarted()
{
	//DebugLog(DEBUG_Stats, PlayerName @ "started a round");
	bPlayerIsAlive = true;
	bPlayerQuit = false;
	++RoundsStarted;
	LastSpawnTime = GetWorld()->GetTimeSeconds();
}
void ASTS2_PlayerStatsInfo::StatEvent_RoundEnded()
{
	//DebugLog(DEBUG_Stats, "Round ended for" @ PlayerName $ " after playing for " $ GetWorld()->GetTimeSeconds() - LastSpawnTime $ " seconds.");
	ChangePlayerRole(EPlayerRole::PROLE_None);
	ChangeLinkType(ELinkedState::LINKED_None);
}
void ASTS2_PlayerStatsInfo::StatEvent_RoundWon()
{
	//DebugLog(DEBUG_Stats, "Round won by" @ PlayerName);
	++RoundsWon;
	if (bPlayerIsAlive && !bPlayerQuit)
	{
		++RoundsSurvivedWon;
		iESSMissionSuccessTime += GetWorld()->GetTimeSeconds() - LastSpawnTime;
	}
}
void ASTS2_PlayerStatsInfo::StatEvent_RoundLost()
{
	//DebugLog(DEBUG_Stats, "Round lost by" @ PlayerName);
	++RoundsLost;
	if (bPlayerIsAlive && !bPlayerQuit)
	{
		++RoundsSurvivedLost;
		iESSMissionFailureTime += GetWorld()->GetTimeSeconds() - LastSpawnTime;
	}
}
void ASTS2_PlayerStatsInfo::StatEvent_RoundTotalPlayers(int32 TotalPlayers)
{
	//DebugLog(DEBUG_Stats, "Round contained " $ TotalPlayers $ " players");
	iESSMissionTotalPlayers = TotalPlayers;
}
void ASTS2_PlayerStatsInfo::StatEvent_RoundPlayersSurviving(int32 PlayersSurviving)
{
	//DebugLog(DEBUG_Stats, "Round contained " $ PlayersSurviving $ " surviving players");
	iESSMissionSurvivingPlayers = PlayersSurviving;
}
void ASTS2_PlayerStatsInfo::ChangeLinkType(ELinkedState NewLinkedState)
{
	float DeltaTime;
	if (LastLinkChangeTime != 0)
	{
		DeltaTime = GetWorld()->GetTimeSeconds() - LastLinkChangeTime;
		switch(LinkedState)
		{
			case ELinkedState::LINKED_Soldier:
				SecondsLinkedToSoldiers += DeltaTime;
				break;
			case ELinkedState::LINKED_FTL:
				SecondsLinkedToFTL += DeltaTime;
				break;
			case ELinkedState::LINKED_SQL:
				SecondsLinkedToSQL += DeltaTime;
				break;
			case ELinkedState::LINKED_SQL_AND_FTL:
				SecondsLinkedToSQL += DeltaTime;
				SecondsLinkedToFTL += DeltaTime;
				break;
			default:
				break;
		}
	}
	LastLinkChangeTime = GetWorld()->GetTimeSeconds();
	LinkedState = NewLinkedState;
}
void ASTS2_PlayerStatsInfo::ChangePlayerRole(EPlayerRole NewPlayerRole)
{
	float DeltaTime;
	if (LastRoleChangeTime != 0)
	{
		DeltaTime = GetWorld()->GetTimeSeconds() - LastRoleChangeTime;
		switch(PlayerRole)
		{
			case EPlayerRole::PROLE_Soldier:
				SecondsAsSoldier += DeltaTime;
				break;
			case EPlayerRole::PROLE_FTL:
				SecondsAsFTL += DeltaTime;
				break;
			case EPlayerRole::PROLE_SQL:
				SecondsAsSQL += DeltaTime;
				break;
			default:
				break;
		}
	}
	LastRoleChangeTime = GetWorld()->GetTimeSeconds();
	PlayerRole = NewPlayerRole;
}
void ASTS2_PlayerStatsInfo::StatEvent_RoundStartedAsSQL()
{
	//DebugLog(DEBUG_Stats, PlayerName @ "started match as squad leader");
	LastRoleChangeTime = 0;
	ChangePlayerRole(EPlayerRole::PROLE_SQL);
}
void ASTS2_PlayerStatsInfo::StatEvent_RoundStartedAsFTL()
{
	//DebugLog(DEBUG_Stats, PlayerName @ "started match as fireteam leader");
	LastRoleChangeTime = 0;
	ChangePlayerRole(EPlayerRole::PROLE_FTL);
}
void ASTS2_PlayerStatsInfo::StatEvent_RoundStartedAsSoldier()
{
	//DebugLog(DEBUG_Stats, PlayerName @ "started match as soldier");
	LastRoleChangeTime = 0;
	ChangePlayerRole(EPlayerRole::PROLE_Soldier);
}
void ASTS2_PlayerStatsInfo::StatEvent_ChangedRoleToSQL()
{
	if (PlayerRole != EPlayerRole::PROLE_SQL)
	{
		//DebugLog(DEBUG_Stats, PlayerName @ "changed role to squad leader");
		ChangePlayerRole(EPlayerRole::PROLE_SQL);
	}
}
void ASTS2_PlayerStatsInfo::StatEvent_ChangedRoleToFTL()
{
	if (PlayerRole != EPlayerRole::PROLE_FTL)
	{
		//DebugLog(DEBUG_Stats, PlayerName @ "changed role to fireteam leader");
		ChangePlayerRole(EPlayerRole::PROLE_FTL);
	}
}
void ASTS2_PlayerStatsInfo::StatEvent_LinkedToSQLAndFTL()
{
	if (LinkedState != ELinkedState::LINKED_SQL_AND_FTL)
	{
		//DebugLog(DEBUG_Stats, PlayerName @ "is now linked to both SQL and FTL");
		ChangeLinkType(ELinkedState::LINKED_SQL_AND_FTL);
	}
}
void ASTS2_PlayerStatsInfo::StatEvent_LinkedToSQL()
{
	if (LinkedState != ELinkedState::LINKED_SQL)
	{
		//DebugLog(DEBUG_Stats, PlayerName @ "is now linked to the SQL");
		ChangeLinkType(ELinkedState::LINKED_SQL);
	}
}
void ASTS2_PlayerStatsInfo::StatEvent_LinkedToFTL()
{
	if (LinkedState != ELinkedState::LINKED_FTL)
	{
		//DebugLog(DEBUG_Stats, PlayerName @ "is now linked to his FTL");
		ChangeLinkType(ELinkedState::LINKED_FTL);
	}
}
void ASTS2_PlayerStatsInfo::StatEvent_LinkedToSoldier()
{
	if (LinkedState != ELinkedState::LINKED_Soldier)
	{
		//DebugLog(DEBUG_Stats, PlayerName @ "is now only linked to soldiers");
		ChangeLinkType(ELinkedState::LINKED_Soldier);
	}
}
void ASTS2_PlayerStatsInfo::StatEvent_Unlinked()
{
	if (LinkedState != ELinkedState::LINKED_None)
	{
		//DebugLog(DEBUG_Stats, PlayerName @ "is now not linked to anyone");
		ChangeLinkType(ELinkedState::LINKED_None);
	}
}
void ASTS2_PlayerStatsInfo::StatEvent_KickPlayer()
{
	//DebugLog(DEBUG_Stats, PlayerName @ "was kicked through a non-admin, non-PB means");
}
void ASTS2_PlayerStatsInfo::StatEvent_KickPlayerPB()
{
	//DebugLog(DEBUG_Stats, PlayerName @ "was kicked by PunkBuster");
	++PBKicked;
}
void ASTS2_PlayerStatsInfo::StatEvent_KickPlayerAdmin()
{
	//DebugLog(DEBUG_Stats, PlayerName @ "was kicked by an admin");
	++AdminKicked;
}
void ASTS2_PlayerStatsInfo::StatEvent_CapturedObjective()
{
	//DebugLog(DEBUG_Stats, PlayerName @ "captured an objective");
	++CapturedObjective;
}
void ASTS2_PlayerStatsInfo::StatEvent_ObjectiveDeath()
{
	//DebugLog(DEBUG_Stats, PlayerName @ "died while capturing an objective");
	++ObjectiveDeaths;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotHitMachineGun()
{
	//DebugLog(DEBUG_Stats, "Machine gun hit by" @ PlayerName);
	++HitsMG;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotHitAssaultRifle()
{
	//DebugLog(DEBUG_Stats, "Assault rifle hit by" @ PlayerName);
	++HitsAstRifle;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotHitPistol()
{
	//DebugLog(DEBUG_Stats, "Pistol hit by" @ PlayerName);
	++HitsPistol;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotHitGrenade()
{
	//DebugLog(DEBUG_Stats, "Grenade hit by" @ PlayerName);
	++HitsGrenade;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotHitSniperRifle()
{
	//DebugLog(DEBUG_Stats, "Sniper Rifle hit by" @ PlayerName);
	++HitsSprRifle;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotHitRocket()
{
	//DebugLog(DEBUG_Stats, "Rocket hit by" @ PlayerName);
	++HitsRocket;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotKilledMachineGun()
{
	//DebugLog(DEBUG_Stats, "Machine gun kill by" @ PlayerName);
	++KillsMG;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotKilledAssaultRifle()
{
	//DebugLog(DEBUG_Stats, "Assault rifle kill by" @ PlayerName);
	++KillsAstRifle;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotKilledPistol()
{
	//DebugLog(DEBUG_Stats, "Pistol kill by" @ PlayerName);
	++KillsPistol;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotKilledGrenade()
{
	//DebugLog(DEBUG_Stats, "Grenade kill by" @ PlayerName);
	++KillsGrenade;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotKilledSniperRifle()
{
	//DebugLog(DEBUG_Stats, "Sniper Rifle kill by" @ PlayerName);
	++KillsSprRifle;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotKilledRocket()
{
	//DebugLog(DEBUG_Stats, "Rocket kill by" @ PlayerName);
	++KillsRocket;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotFiredMachineGun()
{
	//DebugLog(DEBUG_Stats, "Machine gun fired by" @ PlayerName);
	++ShotsFiredMG;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotFiredAssaultRifle()
{
	//DebugLog(DEBUG_Stats, "Assault rifle fired by" @ PlayerName);
	++ShotsFiredAstRifle;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotFiredPistol()
{
	//DebugLog(DEBUG_Stats, "Pistol fired by" @ PlayerName);
	++ShotsFiredPistol;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotFiredGrenade()
{
	//DebugLog(DEBUG_Stats, "Grenade fired by" @ PlayerName);
	++ShotsFiredGrenade;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotFiredSniperRifle()
{
	//DebugLog(DEBUG_Stats, "Sniper Rifle fired by" @ PlayerName);
	++ShotsFiredSprRifle;
}
void ASTS2_PlayerStatsInfo::StatEvent_ShotFiredRocket()
{
	//DebugLog(DEBUG_Stats, "Rocket fired by" @ PlayerName);
	++ShotsFiredRocket;
}
void ASTS2_PlayerStatsInfo::StatEvent_ESSObjectAvailable()
{
	//DebugLog(DEBUG_Stats, "ESS object available for " @ PlayerName);
	iESSObjectAvailable++;
}
void ASTS2_PlayerStatsInfo::StatEvent_ESSObjectDiscovered(FVector Location)
{
	//DebugLog(DEBUG_Stats, "ESS object discovered by  " @ PlayerName);
	iESSObjectDiscovered++;
	iESSObjectDiscoveredLocations.Add(Location);
}
void ASTS2_PlayerStatsInfo::StatEvent_ESSObjectExaminedByOtherPlayer()
{
	//DebugLog(DEBUG_Stats, "ESS object available for " @ PlayerName);
	iESSObjectExaminedByOtherPlayer++;
}
void ASTS2_PlayerStatsInfo::StatEvent_ESSObjectDiscoveryRadioed()
{
	//DebugLog(DEBUG_Stats, "ESS object discovery radioed by " @ PlayerName);
	iESSObjectDiscoveryRadioed++;
}
void ASTS2_PlayerStatsInfo::StatEvent_ESSPostRadioExaminedObject()
{
	//DebugLog(DEBUG_Stats, "ESS object examined post radio by " @ PlayerName);
	iESSPostRadioExaminedObject++;
}
void ASTS2_PlayerStatsInfo::StatEvent_ESSNoRadioExaminedObject()
{
	//DebugLog(DEBUG_Stats, "ESS object examined no radio by " @ PlayerName);
	iESSNoRadioExaminedObject++;
}
void ASTS2_PlayerStatsInfo::StatEvent_ESSPostRadioLinkedObjectTaken()
{
	//DebugLog(DEBUG_Stats, "ESS object linked objective taken post radio by " @ PlayerName);
	iESSPostRadioLinkedObjectTaken++;
}
void ASTS2_PlayerStatsInfo::StatEvent_ESSNoRadioLinkedObjectTaken()
{
	//DebugLog(DEBUG_Stats, "ESS object linked objective taken no radio by " @ PlayerName);
	iESSNoRadioLinkedObjectTaken++;
}
void ASTS2_PlayerStatsInfo::StatEvent_ObjectReportedLethal()
{
	iESSObjectReportedLethal++;
	//DebugLog(DEBUG_Stats, "ESS: Counting " $ iESSObjectReportedLethal $ " reported lethal ES2 objects");
}
void ASTS2_PlayerStatsInfo::StatEvent_ObjectReportedNonLethal()
{
	iESSObjectReportedNonLethal++;
	//DebugLog(DEBUG_Stats, "ESS: Counting " $ iESSObjectReportedNonLethal $ " reported non-lethal ES2 objects");
}
void ASTS2_PlayerStatsInfo::StatEvent_ObjectReportableLethal(int32 NumObjects)
{
	iESSObjectReportableLethal = NumObjects;
	//DebugLog(DEBUG_Stats, "ESS: Counting " $ iESSObjectReportableLethal $ " reported lethal ES2 objects");
}
void ASTS2_PlayerStatsInfo::StatEvent_ObjectReportableNonLethal(int32 NumObjects)
{
	iESSObjectReportableNonLethal = NumObjects;
	//DebugLog(DEBUG_Stats, "ESS: Counting " $ iESSObjectReportableNonLethal $ " reported non-lethal ES2 objects");
}
void ASTS2_PlayerStatsInfo::StatEvent_ObjectUnreportedLocations(TArray<FVector> UnreportedLocations)
{
	int32 i;
	iESSObjectUnreportedLocations = FString::FromInt(UnreportedLocations.Max());
	for (i = 0; i < UnreportedLocations.Max(); i++)
	{
		iESSObjectUnreportedLocations += FString::FromInt(UnreportedLocations[i].X);
		iESSObjectUnreportedLocations += FString::FromInt(UnreportedLocations[i].Y);
		iESSObjectUnreportedLocations += FString::FromInt(UnreportedLocations[i].Z);
	}
	//DebugLog(DEBUG_Stats, "ESS: Creating a string for " $ UnreportedLocations.Length $ " unreported ES2 object locations");
}
void ASTS2_PlayerStatsInfo::StatEvent_ObjectReportingErrors()
{
	iESSObjectReportingErrors++;
	//DebugLog(DEBUG_Stats, "ESS: Counting " $ iESSObjectReportingErrors $ " ES2 reporting errors");
}
void ASTS2_PlayerStatsInfo::StatEvent_ObjectUnnecessaryUse()
{
	iESSObjectUnnecessaryUse++;
	//DebugLog(DEBUG_Stats, "ESS: Counting " $ iESSObjectUnnecessaryUse $ " unnecessary ES2 reports");
}
void ASTS2_PlayerStatsInfo::StatEvent_ReportObjectDistribution()
{
	int32 i;
	iESSObjectDistribution = FString::FromInt(iESSObjectDiscoveredLocations.Max());
	for (i = 0; i < iESSObjectDiscoveredLocations.Max(); i++)
	{
		iESSObjectDistribution += FString::FromInt(iESSObjectDiscoveredLocations[i].X);
		iESSObjectDistribution += FString::FromInt(iESSObjectDiscoveredLocations[i].Y);
		iESSObjectDistribution += FString::FromInt(iESSObjectDiscoveredLocations[i].Z);
	}
	//DebugLog(DEBUG_Stats, "ESS: Creating a string for " $ iESSObjectDiscoveredLocations.Length $ " reported ES2 object locations");
}
void ASTS2_PlayerStatsInfo::StatEvent_CombatHeadshots()
{
	iESSCombatHeadshots++;
	//DebugLog(DEBUG_Stats, "ESS: Counting " $ iESSCombatHeadshots $ " head shots!");
}
void ASTS2_PlayerStatsInfo::StatEvent_CombatTotalDamage(int NewDamage)
{
	iESSCombatTotalDamage += NewDamage;
	//DebugLog(DEBUG_Stats, "ESS: Currently at " $ iESSCombatTotalDamage $ " total damage!");
}
void ASTS2_PlayerStatsInfo::StatEvent_CombatDamageCount()
{
	iESSCombatDamageCount++;
	//DebugLog(DEBUG_Stats, "ESS: Currently at " $ iESSCombatDamageCount $ " damage instances!");
}
void ASTS2_PlayerStatsInfo::StatEvent_CombatEnemyContactTime(float Seconds)
{
	if (iESSCombatEnemyContactTime == 0)
	{
		iESSCombatEnemyContactTime = Seconds;
		//DebugLog(DEBUG_Stats, "ESS: First enemy contact at " $ iESSCombatEnemyContactTime);
	}
}
void ASTS2_PlayerStatsInfo::StatEvent_CombatSurvivingAI(int NumAIs)
{
	iESSCombatSurvivingAI = NumAIs;
	//DebugLog(DEBUG_Stats, "ESS: Currently counting " $ iESSCombatSurvivingAI $ " surviving AIs");
}
void ASTS2_PlayerStatsInfo::StatEvent_PlayerTotalDeathsByAI()
{
	iESSPlayerTotalDeathsByAI++;
	//DebugLog(DEBUG_Stats, "ESS: Currently counting " $ iESSPlayerTotalDeathsByAI $ " deaths by AI");
}
void ASTS2_PlayerStatsInfo::StatEvent_PlayerTotalDeathsByFriendlyFire()
{
	iESSPlayerTotalDeathsByFriendlyFire++;
	//DebugLog(DEBUG_Stats, "ESS: Currently counting " $ iESSPlayerTotalDeathsByFriendlyFire $ " deaths by friendly fire");
}
void ASTS2_PlayerStatsInfo::StatEvent_PlayerTotalDeathsByObject()
{
	iESSPlayerTotalDeathsByObject++;
	//DebugLog(DEBUG_Stats, "ESS: Currently counting " $ iESSPlayerTotalDeathsByObject $ " deaths by object");
}
void ASTS2_PlayerStatsInfo::StatEvent_ReportPlayerDeathLocations()
{
	int32 i;
	iESSPlayerDeathLocation = FString::FromInt(DeathLocations.Max());
	for (i = 0; i < DeathLocations.Max(); i++)
	{
		iESSPlayerDeathLocation += FString::FromInt(DeathLocations[i].X);
		iESSPlayerDeathLocation += FString::FromInt(DeathLocations[i].Y);
		iESSPlayerDeathLocation += FString::FromInt(DeathLocations[i].Z);
	}
	//DebugLog(DEBUG_Stats, "ESS: Creating a string for " $ DeathLocations.Length $ " death locations");
}
void ASTS2_PlayerStatsInfo::StatEvent_PlayerTotalInjuries(FVector InjuryLocation)
{
	iESSPlayerTotalInjuries++;
	//DebugLog(DEBUG_Stats, "ESS: Currently counting " $ iESSPlayerTotalInjuries $ " injuries");
	InjuryLocations.Add(InjuryLocation);
}
void ASTS2_PlayerStatsInfo::StatEvent_PlayerTotalInjuriesByAI(FVector InjuryLocation)
{
	iESSPlayerTotalInjuriesByAI++;
	StatEvent_PlayerTotalInjuries(InjuryLocation);
	//DebugLog(DEBUG_Stats, "ESS: Currently counting " $ iESSPlayerTotalInjuriesByAI $ " injuries by AI");
}
void ASTS2_PlayerStatsInfo::StatEvent_PlayerTotalInjuriesByFriendlyFire(FVector InjuryLocation)
{
	iESSPlayerTotalInjuriesFriendlyFire++;
	StatEvent_PlayerTotalInjuries(InjuryLocation);
	//DebugLog(DEBUG_Stats, "ESS: Currently counting " $ iESSPlayerTotalInjuriesFriendlyFire $ " injuries by friendly fire");
}
void ASTS2_PlayerStatsInfo::StatEvent_PlayerTotalInjuriesByObject(FVector InjuryLocation)
{
	iESSPlayerTotalInjuriesByObject++;
	StatEvent_PlayerTotalInjuries(InjuryLocation);
	//DebugLog(DEBUG_Stats, "ESS: Currently counting " $ iESSPlayerTotalInjuriesByObject $ " injuries by object");
}
void ASTS2_PlayerStatsInfo::StatEvent_ReportPlayerInjuryLocations()
{
	int32 i;
	iESSPlayerInjuryLocation = FString::FromInt(InjuryLocations.Max());
	for (i = 0; i < InjuryLocations.Max(); i++)
	{
		iESSPlayerInjuryLocation += FString::FromInt(InjuryLocations[i].X);
		iESSPlayerInjuryLocation += FString::FromInt(InjuryLocations[i].Y);
		iESSPlayerInjuryLocation += FString::FromInt(InjuryLocations[i].Z);
	}
	//DebugLog(DEBUG_Stats, "ESS: Creating a string for " $ InjuryLocations.Length $ " injury locations");
}
void ASTS2_PlayerStatsInfo::StatEvent_ROEFriendlyFireHits()
{
	iESSROEFriendlyFireHits++;
	//DebugLog(DEBUG_Stats, "ESS: Currently counting " $ iESSROEFriendlyFireHits $ " friendly fire hits");
}
void ASTS2_PlayerStatsInfo::StatEvent_ROEFriendlyFireDeaths()
{
	iESSROEFriendlyFireDeaths++;
	//DebugLog(DEBUG_Stats, "ESS: Currently counting " $ iESSROEFriendlyFireDeaths $ " friendly fire deaths");
}
void ASTS2_PlayerStatsInfo::StatEvent_ROECivilianHits()
{
	iESSROECivilianHits++;
	//DebugLog(DEBUG_Stats, "ESS: Currently counting " $ iESSROECivilianHits $ " civilian hits");
}
void ASTS2_PlayerStatsInfo::StatEvent_ROECivilianDeaths()
{
	iESSROECivilianDeaths++;
	//DebugLog(DEBUG_Stats, "ESS: Currently counting " $ iESSROECivilianDeaths $ " civilian deaths");
}
void ASTS2_PlayerStatsInfo::StatEvent_ROECivilianDeathsByIED()
{
	iESSROECivilianDeathsByIED++;
	//DebugLog(DEBUG_Stats, "ESS: Currently counting " $ iESSROECivilianDeathsByIED $ " civilian deaths by IED");
}
void ASTS2_PlayerStatsInfo::IgnoreStatsThisRound()
{
}