// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "AA29/MyEnums.h"
#include "AGP_GameInfo.generated.h"

class ASoldierClass;
class AHumanController;

UCLASS()
class AA29_API AAGP_GameInfo : public AGameInfo
{
	GENERATED_BODY()
public:
	AAGP_GameInfo();



	UPROPERTY(globalconfig)		bool GoalsbDisableESSScored;					//var globalconfig bool bDisableESS;
	UPROPERTY(globalconfig)		int32 iDelayedRoundStartTimeSeconds;			//var globalconfig int iDelayedRoundStartTimeSeconds;
	UPROPERTY()					USoundBase* sndESSS2Introduction;				//var Sound sndESSS2Introduction;
	UPROPERTY(globalconfig)		FString ServerToursDownloadServer;				//var globalconfig string ServerToursDownloadServer;
	UPROPERTY()					float fpAIDifficultyLevelMentalStateModifer;	//var float fpAIDifficultyLevelMentalStateModifer;
	UPROPERTY()					float fpAIDifficultyLevelMortarSkillModifer;	//var float fpAIDifficultyLevelMortarSkillModifer;
	UPROPERTY()					float fpAIDifficultyLevelWeaponRangeModifer;	//var float fpAIDifficultyLevelWeaponRangeModifer;
	UPROPERTY()					float fpAIDifficultyLevelWeaponAccModifer;		//var float fpAIDifficultyLevelWeaponAccModifer;
	UPROPERTY()					float fpAIDifficultyLevelExperienceModifer;		//var float fpAIDifficultyLevelExperienceModifer;
	UPROPERTY()					float fpAIDifficultyLevelHearingModifer;		//var float fpAIDifficultyLevelHearingModifer;
	UPROPERTY()					float fpAIDifficultyLevelVisionModifer;			//var float fpAIDifficultyLevelVisionModifer;
	UPROPERTY(globalconfig)		bool bOpenAllWeaponClassSlots;					//var globalconfig bool bOpenAllWeaponClassSlots;
	UPROPERTY(globalconfig)		float fpNPCInitialSpawnDelay;					//var globalconfig float fpNPCInitialSpawnDelay;
	UPROPERTY(globalconfig)		float fpNPCSpawnDelay;							//var globalconfig float fpNPCSpawnDelay;
	UPROPERTY()					int32 iAIVehiclesSpawned;						//var int iAIVehiclesSpawned;
	UPROPERTY()					int32 iBTRsSpawned;								//var int iBTRsSpawned;
	UPROPERTY()					int32 iBMPsSpawned;								//var int iBMPsSpawned;
	UPROPERTY()					int32 iT62sSpawned;								//var int iT62sSpawned;
	UPROPERTY()					int32 iNPCSpottersSpawned;						//var int iNPCSpottersSpawned;
	UPROPERTY()					int32 iCivilianNPCsSpawned;						//var int iCivilianNPCsSpawned;
	UPROPERTY()					int32 iMustSpawnNPCsSpawned;					//var int iMustSpawnNPCsSpawned;
	UPROPERTY()					int32 iPlayersSpawned;							//var int iPlayersSpawned;
	UPROPERTY()					int32 iNPCsSpawned;								//var int iNPCsSpawned;
	UPROPERTY()					int32 iNPCPSSpawnIndex;							//var int iNPCPSSpawnIndex;
	//UPROPERTY()				TArray<ANPCPlayerStart*> anpcpsPSToSpawn;		//var array<NPCPlayerStart> anpcpsPSToSpawn;
	UPROPERTY(globalconfig)		bool bAutoAT;									//var globalconfig bool bAutoAT;
	UPROPERTY()					int32 iMaxBTRsToSpawn;							//var int iMaxBTRsToSpawn;
	UPROPERTY()					int32 iMaxBMPsToSpawn;							//var int iMaxBMPsToSpawn;
	UPROPERTY()					int32 iMaxT62sToSpawn;							//var int iMaxT62sToSpawn;
	UPROPERTY()					int32 iMaxAIVehiclesToSpawn;					//var int iMaxAIVehiclesToSpawn;
	UPROPERTY()					int32 iMaxAISpotterNPCsToSpawn;					//var int iMaxAISpotterNPCsToSpawn;
	UPROPERTY()					int32 iMaxAICivilianNPCsToSpawn;				//var int iMaxAICivilianNPCsToSpawn;
	UPROPERTY()					int32 iMaxPlayerVehiclesToSpawn;				//var int iMaxPlayerVehiclesToSpawn;
	UPROPERTY(globalconfig)		float fpMaxNPCToPlayerRatio;					//var globalconfig float fpMaxNPCToPlayerRatio;
	UPROPERTY(globalconfig)		int32 iMaxAINPCsToSpawn;						//var globalconfig int iMaxAINPCsToSpawn;
	UPROPERTY()					bool bDEBUGDisableAIVehicles;					//var bool bDEBUGDisableAIVehicles;
	UPROPERTY()					bool bDEBUGDisablePlayerVehicles;				//var bool bDEBUGDisablePlayerVehicles;
	UPROPERTY(globalconfig)		bool bDisableTakeDamageViewShift;				//var globalconfig bool bDisableTakeDamageViewShift;
	UPROPERTY(globalconfig)		bool bEnableCodeTesting;						//var globalconfig bool bEnableCodeTesting;
	UPROPERTY(globalconfig)		bool bEnableMapTesting;							//var globalconfig bool bEnableMapTesting;
	UPROPERTY()					bool bFakeFail;									//var bool bFakeFail;
	UPROPERTY()					bool fAuthNotAvailableLastAuthAttempt;			//var bool fAuthNotAvailableLastAuthAttempt;
	UPROPERTY()					float NextAuthTime;								//var float NextAuthTime;
	UPROPERTY()					int32 ServerAuthFailures;						//var int ServerAuthFailures;
	UPROPERTY()					int32 MaxAuthConnections;						//var int MaxAuthConnections;
	//UPROPERTY()				TArray<AInternetInfo*> AuthList;				//var array<InternetInfo> AuthList;
	UPROPERTY(globalconfig)		bool bDemoExploreTheArmyMode;					//var globalconfig bool bDemoExploreTheArmyMode;
	UPROPERTY(globalconfig)		EForceGameplayMode ForceGameplay;				//var globalconfig EForceGameplayMode ForceGameplay;
	UPROPERTY()					bool bNoInventory;								//var bool bNoInventory;
	UPROPERTY()					bool bDeadGame;									//var bool bDeadGame;
	//UPROPERTY()				AScreenplay* _Screenplay;						//var Screenplay _Screenplay;
	//UPROPERTY()				AAI_Interface* AI_global;						//var AI_Interface AI_global;

//	virtual void BeginPlay() override;
//	virtual void PreBeginPlay() override;
//	virtual void PostBeginPlay() override;
//	virtual void StartMatch() override;


	void RestartPlayer(AController* aPlayer);

	virtual void PostLogin(APlayerController* NewPlayer) override;

	//void Login(FString Portal, FString Options, FString Error);

	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);


	void FinishPostLogin(APlayerController* NewPlayer);



	void EvaluatePlayerStatus(APlayerController* PC);
	void GetSystemTimeSeconds();
	//void PrecacheGameTextures(ALevelInfo* myLevel);
	//void PrecacheGameStaticMeshes(ALevelInfo* myLevel);
	void DisableQualification();
	void InitLogging();
	void EndLogging(FString Reason);
	void AddAllPlayersToStatsInfo();
	void GetStatForPlayer(AHumanController* HC, FString sStatName);
	bool ShouldIgnoreStats();
	bool IsTrainingMission();
	void UpdateClientsOfCheatAndForceclassStatus();
	void ConfigureESSObjectives();
	void ESSUpdateInitialAvailableStatsPerPlayer(AHumanController* HC, int32 iESSObjectsEnabled);
	void CalculateAIDifficultyValues();
	void TerminateNPCSpawning();
	void NPCSpawnTimer();
	void PreparePlayerForStartMatch(APlayerController* PC);
	void CleanupLevel();
	void AssignStartPoints();
	void AssignClassAndRole();
	void RecordStartMatch();
	void CheckClassWithPlayerStart(AController* PC);
	void IsClassLegal(ASoldierClass* sclass);
	void StartScreenplay();
	bool IsRequireAuthorization();
	void GetTeamClass(AController* C);
	void GetDefaultTeamClass();
	void GetTeamRole(AController* C);
	void GetDefaultTeamRole();
	bool ShouldRespawn(APickup* Other);
	void PickupQuery(APawn* Other, APickup* Item);
	void SetFirstObjective(AActor* Objective);
	void SetSquadTarget(int32 iTeamIndex, uint8 objnum);
	void ScoreAGPObjective(ATeamInfo* Team, AActor* Objective, bool bGameEnded, AAA2_PlayerState*  Scorer, bool bScorerOnly);
	void ScoreDecoMesh(ATeamInfo* Team, AActor Objective, int32 ScorePoints, AAA2_PlayerState*  Scorer, bool bScorerOnly);
	void RecordFriendlyFire(AAA2_PlayerState*  ShooterPRI, APawn* VictimPawn, int32 Score);
	void RestartGame();
	void ApplicationShutdown();
	void GameEnding();
	void FakeRestartGame();
	bool IsMultiPlayer();
	bool IsFriend(APawn* me, APawn* you);
	bool IsTeamFriend(uint8 Team, APawn* you);
	bool IsTeamGame();
	uint8 GetPlayerTeamIndex(AController* C);
	void GetScreenplay();
	bool IsUnlimitedRespawn();
	bool IsAllowRepawn();
	bool IsAllowLateJoin();
	void BanPlayerAccount(APlayerController* Cheater);

	void EnterSpectatorMode(AController* aPlayer);
	bool ShouldSpectate(AAA2_PlayerState*  p);
	bool CanRespawn(AController* C);
	void Killed(AController* Killer, AController* Killed, APawn* KilledPawn, UaDamageType* DamageType);
	void ScoreKill(AController* Killer, AController* Other, UaDamageType* DamageType);
	//void ChangeName(AController* Other, FString S, bool bNameChange);
	void SimulateAuthFailure();
	void SimulateAuthRecovery();
	void GetServerAuthData();
	void GetMapServerInfo();
	void AuthorizeServer();
	void AuthorizeServerNow();
	void SetServerMode(int32 ServerMode, FString ServerModeName);
	void Timer();
	void AuthTransmissionErrorCallback(int32 iReason, FString sMsg, FString sShortMsg);
	void LogServerAuthFailure(int32 ResultCode);
	void AuthAuthenticateServerCallback(int32 ResultCode, int32 ServerMode, FString ServerModeName);
	void BroadcastDeathMessage(AController* Killer, AController* Killed, UaDamageType* DamageType);
	void CheckForNewToursFile();
	void ReceivedToursText(FString Filename, FString TextChunk);
	void OnReceivedCachedTours(FString ReceivedFileName);
	bool ShouldDownloadTours();
	void DisableToursDownload();

};
