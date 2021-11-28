// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "PlayerStatsInfo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APlayerStatsInfo : public AAA2_Info
{
	GENERATED_BODY()
public:
	APlayerStatsInfo();

	UPROPERTY()				FString EncryptedPassword;					//var string EncryptedPassword;
	UPROPERTY()				FString PlayerName;							//var string PlayerName;

	void Aggregate();
	void IgnoreStatsThisRound();
	void StatEvent_ScoreChange(int32 DeltaScore);
	void StatEvent_ROEChange(int32 DeltaROE);
	void StatEvent_Kill();
	void StatEvent_Death(FVector KillLocation);
	void StatEvent_Quit();
	void StatEvent_TrainingMissionStart();
	void StatEvent_TrainingMissionSuccess();
	void StatEvent_TrainingMissionFailure();
	void StatEvent_RoundStartedAsMedic();
	void StatEvent_WasHealed();
	void StatEvent_HealedTeammate();
	void StatEvent_RoundStarted();
	void StatEvent_RoundWon();
	void StatEvent_RoundLost();
	void StatEvent_RoundEnded();
	void StatEvent_RoundStartedAsSQL();
	void StatEvent_RoundStartedAsFTL();
	void StatEvent_RoundStartedAsSoldier();
	void StatEvent_ChangedRoleToSQL();
	void StatEvent_ChangedRoleToFTL();
	void StatEvent_LinkedToSQLAndFTL();
	void StatEvent_LinkedToSQL();
	void StatEvent_LinkedToFTL();
	void StatEvent_LinkedToSoldier();
	void StatEvent_Unlinked();
	void StatEvent_KickPlayer();
	void StatEvent_KickPlayerPB();
	void StatEvent_KickPlayerAdmin();
	void StatEvent_CapturedObjective();
	void StatEvent_ObjectiveDeath();
	void StatEvent_ShotFiredMachineGun();
	void StatEvent_ShotFiredAssaultRifle();
	void StatEvent_ShotFiredPistol();
	void StatEvent_ShotFiredGrenade();
	void StatEvent_ShotFiredSniperRifle();
	void StatEvent_ShotFiredRocket();
	void StatEvent_ShotHitMachineGun();
	void StatEvent_ShotHitAssaultRifle();
	void StatEvent_ShotHitPistol();
	void StatEvent_ShotHitGrenade();
	void StatEvent_ShotHitSniperRifle();
	void StatEvent_ShotHitRocket();
	void StatEvent_ShotKilledMachineGun();
	void StatEvent_ShotKilledAssaultRifle();
	void StatEvent_ShotKilledPistol();
	void StatEvent_ShotKilledGrenade();
	void StatEvent_ShotKilledSniperRifle();
	void StatEvent_ShotKilledRocket();
	void StatEvent_ESSObjectAvailable();
	void StatEvent_ESSObjectDiscovered(FVector Location);
	void StatEvent_ESSObjectExaminedByOtherPlayer();
	void StatEvent_ESSObjectDiscoveryRadioed();
	void StatEvent_ESSPostRadioExaminedObject();
	void StatEvent_ESSNoRadioExaminedObject();
	void StatEvent_ESSPostRadioLinkedObjectTaken();
	void StatEvent_ESSNoRadioLinkedObjectTaken();
	void QueryESSObjectAvailable();
	void QueryESSObjectDiscovered();
	void QueryESSObjectExaminedByOtherPlayer();
	void QueryESSObjectDiscoveryRadioed();
	void QueryESSPostRadioExaminedObject();
	void QueryESSNoRadioExaminedObject();
	void QueryESSPostRadioLinkedObjectTaken();
	void QueryESSNoRadioLinkedObjectTaken();
	void QueryCapturedObjectives();
	void QueryCapturedObjectiveDeaths();
	void QueryHealed();
	void QueryUsedMedic();
	void QueryMedPacksUsed();
	void QueryTimePlayedSeconds();
	void QueryTimeAliveSeconds();
	void QueryRoundStarted();
	void QueryRoundsSurvivedWon();
	void QueryRoundsSurvivedLost();
	void QueryShotsFiredMachineGun();
	void QueryShotsFiredAssaultRifle();
	void QueryShotsFiredPistol();
	void QueryShotsFiredGrenade();
	void QueryShotsFiredSniper();
	void QueryShotsFiredRocket();
	void QueryShotsHitMachineGun();
	void QueryShotsHitAssaultRifle();
	void QueryShotsHitPistol();
	void QueryShotsHitGrenade();
	void QueryShotsHitSniper();
	void QueryShotsHitRocket();
	void StatEvent_RoundTotalPlayers(int32 TotalPlayers);
	void StatEvent_RoundPlayersSurviving(int32 PlayersSurviving);
	void StatEvent_ObjectReportedLethal();
	void StatEvent_ObjectReportedNonLethal();
	void StatEvent_ObjectReportableLethal(int32 NumObjects);
	void StatEvent_ObjectReportableNonLethal(int32 NumObjects);
	void StatEvent_ObjectUnreportedLocations(TArray<FVector> UnreportedLocations);
	void StatEvent_ObjectReportingErrors();
	void StatEvent_ObjectUnnecessaryUse();
	void StatEvent_ReportObjectDistribution();
	void StatEvent_CombatHeadshots();
	void StatEvent_CombatTotalDamage(int32 NewDamage);
	void StatEvent_CombatDamageCount();
	void StatEvent_CombatEnemyContactTime(float Seconds);
	void StatEvent_CombatSurvivingAI(int32 NumAIs);
	void StatEvent_PlayerTotalDeathsByAI();
	void StatEvent_PlayerTotalDeathsByFriendlyFire();
	void StatEvent_PlayerTotalDeathsByObject();
	void StatEvent_ReportPlayerDeathLocations();
	void StatEvent_PlayerTotalInjuries(FVector InjuryLocation);
	void StatEvent_PlayerTotalInjuriesByAI(FVector InjuryLocation);
	void StatEvent_PlayerTotalInjuriesByFriendlyFire(FVector InjuryLocation);
	void StatEvent_PlayerTotalInjuriesByObject(FVector InjuryLocation);
	void StatEvent_ReportPlayerInjuryLocations();
	void StatEvent_ROEFriendlyFireHits();
	void StatEvent_ROEFriendlyFireDeaths();
	void StatEvent_ROECivilianHits();
	void StatEvent_ROECivilianDeaths();
	void StatEvent_ROECivilianDeathsByIED();

};
