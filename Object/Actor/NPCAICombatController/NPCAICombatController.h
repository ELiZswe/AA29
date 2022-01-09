// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "NPCAICombatController.generated.h"

class ANPCBaseSoldierController;
class ANPCBaseController;
class ABaseProjectile;
class ANPCSpeechManager;
class AAGP_Pawn;
class AHumanController;

UCLASS()
class ANPCAICombatController : public AActor
{
	GENERATED_BODY()

public:	
	
	ANPCAICombatController();

	UPROPERTY(EditAnywhere, Category = "OrderDebugging")	bool								bDisableCombatController;				//var(OrderDebugging) bool bDisableCombatController;
	UPROPERTY()												TArray<FString>						asOrderNames;							//var FString asOrderNames[9];
	UPROPERTY()												TArray<FString>						asCombatActions;						//var FString asCombatActions[25];
	UPROPERTY()												TArray<FString>						asEvents;								//var FString asEvents[15];
	UPROPERTY(EditAnywhere, Category = "NPCTeamInfo")		int32								iTeamID;								//var(NPCTeamInfo) int32 iTeamID;
	UPROPERTY(EditAnywhere, Category = "NPCTeamInfo")		FString								sTeamName;								//var(NPCTeamInfo) FString sTeamName;
	UPROPERTY(EditAnywhere, Category = "NPCTeamInfo")		bool								bAllowAnarchy;							//var(NPCTeamInfo) bool bAllowAnarchy;
	UPROPERTY(EditAnywhere, Category = "NPCTeamInfo")		int32								iMaxNPCsAtRespawn;						//var(NPCTeamInfo) int32 iMaxNPCsAtRespawn;
	UPROPERTY()												bool								bInAnarchy;								//var bool bInAnarchy;
	UPROPERTY(EditAnywhere, Category = "NPCArmory")			int32								iMaxMortarAttacks;						//var(NPCArmory) int32 iMaxMortarAttacks;
	UPROPERTY(EditAnywhere, Category = "NPCArmory")			float								fpMortarCrewSkill;						//var(NPCArmory) float fpMortarCrewSkill;
	UPROPERTY()												int32								iReinforcementWave;						//var int32 iReinforcementWave;
	UPROPERTY()												int32								iVehicleReinforcementWave;				//var int32 iVehicleReinforcementWave;
	UPROPERTY()												int32								iCurrentTotalLiveMembers;				//var int32 iCurrentTotalLiveMembers;
	UPROPERTY()												bool								bStarted;								//var bool bStarted;
	UPROPERTY()												ANPCSpeechManager*					anpcsmgrSpeechManager;					//var NPCSpeechManager anpcsmgrSpeechManager[10];
	UPROPERTY()												TArray<FNPCPlatoons>				anpcpPlatoons;							//var NPCPlatoons anpcpPlatoons[8];
	UPROPERTY()												TArray<FNPCSquadDetails>			npcsdCommandos;							//var NPCSquadDetails npcsdCommandos;
	UPROPERTY()												TArray<ANPCBaseController*>			anpcbcVehicles;							//var TArray<NPCBaseController> anpcbcVehicles;
	UPROPERTY()												TArray<FEnemyContact>				aecEnemyContacts;						//var TArray<EnemyContact> aecEnemyContacts;
	UPROPERTY()												ABaseProjectile*					bpMortarRoundClass;						//var class<BaseProjectile> bpMortarRoundClass;
	UPROPERTY()												ABaseProjectile*					bpMortarSmokeRoundClass;				//var class<BaseProjectile> bpMortarSmokeRoundClass;
	UPROPERTY()												TArray<FFireMissionInFlight>		afmifActiveRounds;						//var TArray<FireMissionInFlight> afmifActiveRounds;
	UPROPERTY()												TArray<FMortarRangeTable>			amrtMortarData;							//var TArray<MortarRangeTable> amrtMortarData;
	UPROPERTY()												bool								bOfficerAvailable;						//var bool bOfficerAvailable;
	UPROPERTY()												TArray<FOrderQueue>					oqOrdersWaitingDeployment;				//var TArray<OrderQueue> oqOrdersWaitingDeployment;
	UPROPERTY()												TArray<FSupportFireRequestQueue>	asfrqFireMissions;						//var TArray<SupportFireRequestQueue> asfrqFireMissions;
	UPROPERTY()												float								fpPercentCompanyAlive;					//var float fpPercentCompanyAlive;
	UPROPERTY()												int32								iTotalCompanyMembers;					//var int32 iTotalCompanyMembers;
	UPROPERTY()												int32								iTotalLiveMembers;						//var int32 iTotalLiveMembers;
	UPROPERTY()												int32								iAvailableMortarAttacks;				//var int32 iAvailableMortarAttacks;
	UPROPERTY()												bool								bForceReinforcementsNow;				//var bool bForceReinforcementsNow;
	UPROPERTY()												TArray<FReinforcementRespawn>		arrRespawnInformation;					//var TArray<ReinforcementRespawn> arrRespawnInformation;
	UPROPERTY(EditAnywhere, Category = "NPCTeamInfo")		float								fpReinforcementDelayTime;				//var(NPCTeamInfo) float fpReinforcementDelayTime;
	UPROPERTY()												float								fpTimeUntilNextReinforcements;			//var float fpTimeUntilNextReinforcements;
	UPROPERTY()												float								fpTimeUntilNextVehicleReinforcements;	//var float fpTimeUntilNextVehicleReinforcements;
	UPROPERTY(EditAnywhere, Category = "RespawnVehicle")	int32								iVehicleRespawnMinVehicleLevel;			//var(RespawnVehicle) int32 iVehicleRespawnMinVehicleLevel;
	UPROPERTY()												int32								iDeadNPCs;								//var int32 iDeadNPCs;
	UPROPERTY()												TArray<AAGP_Pawn*>					aagppawnDeadNPCs;						//var AGP_Pawn aagppawnDeadNPCs[128];
	
	//From Actor;
	UPROPERTY()												TArray<FString>						ActorHelp;


	bool IsBodyNearLocation(AAGP_Pawn* agppwn);
	void AddDeadBodyLocation(AAGP_Pawn* agppwn);
	FString DetermineCombatActionByState(int32 iOrderIndex, int32 iEventIndex, int32 iNodeIndex, int32 iMentalStateIndex, bool bEnableLogging);
	bool InitializeDecisionGrid(FString sFileName);
	bool InitializeSpeechGrid(FString sFileName);
	FString DetermineSpeechByState(int32 iOrderIndex, int32 iEventIndex, int32 iMentalStateIndex);
	void NotifyDoorBreached(FVector vDoorLocation);
	void NotifyObjectiveAccomplished(AActor* actorObjective);
	void NotifyHelicopterLanding(FVector vPZLocation);
	bool ReportUnderFireSquadAlert(ANPCBaseSoldierController* npcbcReporter, AActor* aShooter);
	void ActivateGarbageCollection();
	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo&, float& YL, float& YPos);
	FString GetVerboseOrders(int32 CurrentOrders);
	void BeginPlay();
	void EndGame();
	void StartAICC();
	void InitializeRespawnInformation();
	void PostBeginPlay();
	void RegisterVehicle(ANPCBaseController* npcbc);
	void RegisterWithCombatController(ANPCBaseSoldierController* npcbc);
	void AdjustNPCOrders(ANPCBaseSoldierController* npcbc, bool bImmediateOrder);
	bool ShouldActivateCombatAction(ANPCBaseSoldierController* npcbcReporter);
	void ProcessCombatAction(ANPCBaseSoldierController* npcbcReporter);
	void TransitionToCombatOrders(ANPCBaseSoldierController* npcbsc);
	void DetermineDecisionOrderPercentEntryAction(ANPCBaseSoldierController* npcbcReporter, int32 iEventIndex);
	void ReportMentalStateChange(ANPCBaseSoldierController* npcbcReporter);
	bool IsOfficerAlive();
	bool IsNewContact(ANPCBaseController* npcbcReporter, APawn* pawnContact, bool bDebug);
	bool IsLostContact(ANPCBaseController* npcbcReporter, APawn* pawnContact);
	bool UpdateContact(ANPCBaseController* npcbcReporter, int32 iContactType, APawn* pawnContact, int32 iThreatLevel);
	void DetermineLostContactAction(int32 iContactIndex);
	void Timer();
	void SpawnLevelReinforcements(int32 iLevel, int32 iCurrentlyAlive);
	void SpawnTriggeredReinforcements(int32 iPlatoonID, int32 iSquadID, int32 iFireteamID, FString sCommand, FVector vLocation);
	void SpawnVehicleLevelReinforcements(int32 iWaveLevel);
	void EnterAnarchyState();
	void ProcessIdleTimer(ANPCBaseSoldierController* npcsc);
	void ProcessOrderQueue();
	void ProcessSupportRequest(FOrderQueue oqEntry);
	void ProcessTeamOrder(FOrderQueue oqEntry);
	void ProcessSoldierOrder(ANPCBaseController* npbc, FOrderQueue oqEntry);
	void AddOrderToQueue(ANPCBaseController* npcbc, int32 iOrderCommand, int32 iTacticalOrder, FString sCombatAction, APawn* pawnTarget);
	bool AddSupportRequestToQueue(ANPCBaseSoldierController* npcbscReporter, int32 iSupportRequest, FVector vSupportLocation, APawn* pawnTarget, bool bSmokeMission);
	float LookupMortarFlightTime(float fpDistanceToTargetMeters);
	void ProcessFireMissions();
	void ProcessInFlightFireMissions();
	void AddFireMissionRequestToQueue(ANPCBaseSoldierController* npcbscSpotter, int32 iSupportType, float fpSkillLevel, FVector vTargetArea, bool bSmokeMission);
	int32 EvaluatePlatoonSquadMembers(FNPCSquadDetails npcsd);
	void IssueOrder(ANPCBaseController* npcbc, int32 iNewOrder);
	float GetLeadershipBonus(ANPCBaseSoldierController* npcbsc);
	float GetThreatAnalysisForTeam(ANPCBaseSoldierController* npcbsc);
	int32 GetOrderForNPC(ANPCBaseController* npcbc);
	void ForceOrderPercent(AHumanController* hcRequesting, FString sOrderName);
	bool ReportActionFailed(ANPCBaseSoldierController* npcbcReporter);
	bool ReportActionComplete(ANPCBaseSoldierController* npcbcReporter);
	bool ReportTimeElapsed(ANPCBaseSoldierController* npcbcReporter);
	bool ReportLostContact(ANPCBaseController* npcbcReporter, APawn* pawnContact);
	bool ReportWounded(ANPCBaseController* npcbcReporter, int32 iContactType, APawn* pawnContact, int32 iThreatLevel);
	bool ReportKilledEnemy(ANPCBaseSoldierController* npcbcReporter, APawn* pawnContact);
	bool ReportFriendDied(ANPCBaseSoldierController* npcbcReporter);
	bool ReportContact(ANPCBaseController* npcbcReporter, int32 iContactType, APawn* pawnContact, int32 iThreatLevel);
	bool ReportHeardNoise(ANPCBaseController* npcbcReporter, FVector vLocation);
	bool ReportHeardGunfire(ANPCBaseController* npcbcReporter, FVector vLocation);
	bool ReportVehicleContact(ANPCBaseController* npcbcReporter, int32 iContactType, APawn* pawnContact, int32 iThreatLevel);
	bool ReportOutOfAmmo(ANPCBaseSoldierController* npcbcReporter);
	bool ReportUnderFire(ANPCBaseSoldierController* npcbcReporter, AActor* aShooter);
	bool ReportGrenadeContact(ANPCBaseSoldierController* npcbcReporter, FVector vLocGrenade);
	bool ReportWeaponJamReload(ANPCBaseSoldierController* npcbcReporter);
	bool ReportNeedToEnterAnarchyState(ANPCBaseSoldierController* npcbcReporter);
	FString DetermineInterruptSpeech(ANPCBaseSoldierController* npcbcReporter);
	float PlayEventAudio(ANPCBaseSoldierController* npcbscReporter, FString sOverrideSpeechType);
	void SetSquadRandomAmbushSet(int32 iPlatoonID, int32 iSquadID, int32 iAmbushSet);
	int32 GetSquadRandomAmbushSet(int32 iPlatoonID, int32 iSquadID);
	void ForceReinforcementsNow();

protected:

public:	
	
	virtual void Tick(float DeltaTime) override;

};
