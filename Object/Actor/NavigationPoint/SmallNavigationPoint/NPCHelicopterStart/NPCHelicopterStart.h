// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/SmallNavigationPoint.h"
#include "NPCHelicopterStart.generated.h"

class AAGP_Pawn;
class ANPCAICombatController;
class ANPCBaseHelicopterController;
class ASVehicle;
class ANPCPlayerStart;

class ANPCBaseController;
UCLASS()
class ANPCHelicopterStart : public ASmallNavigationPoint
{
	GENERATED_BODY()
public:
	ANPCHelicopterStart();

	UPROPERTY(EditAnywhere, Category = "NPCOrders")					ENPCOrders						enpcoPrimaryOrders;				//var(NPCOrders) Enum  enpcoPrimaryOrders;
	UPROPERTY(EditAnywhere, Category = "NPCVehicleStart")			bool							bDebugInit;						//var(NPCVehicleStart) bool bDebugInit;
	UPROPERTY()														bool							bEnabled;						//var bool bEnabled;
	UPROPERTY(EditAnywhere, Category = "NPCTeamID")					int32							iTeamID;						//var(NPCTeamID) int32 iTeamID;
	UPROPERTY(EditAnywhere, Category = "NPCController")				bool							bDummyHelicopter;				//var(NPCController) bool bDummyHelicopter;
	UPROPERTY(EditAnywhere, Category = "NPCController")				ANPCBaseHelicopterController*	ControllerClass;				//var(NPCController) class<NPCBaseHelicopterController> ControllerClass;
	UPROPERTY(EditAnywhere, Category = "NPCController")				ASVehicle*						VehicleClass;					//var(NPCController) class<SVehicle> VehicleClass;
	UPROPERTY(EditAnywhere, Category = "NPCController")				bool							DrawDriverInTP;					//var(NPCController) bool DrawDriverInTP;
	UPROPERTY(EditAnywhere, Category = "NPCController")				int32							iNPCTeamID;						//var(NPCController) int32 iNPCTeamID;
	UPROPERTY(EditAnywhere, Category = "NPCController")				float							fNPCExperience;					//var(NPCController) float fNPCExperience;
	UPROPERTY(EditAnywhere, Category = "NPCController")				int32							iMinThreatLevel;				//var(NPCController) int32 iMinThreatLevel;
	UPROPERTY(EditAnywhere, Category = "NPCController")				bool							bDebugMode;						//var(NPCController) bool bDebugMode;
	UPROPERTY(EditAnywhere, Category = "NPCController")				bool							bDebugSenses;					//var(NPCController) bool bDebugSenses;
	UPROPERTY(EditAnywhere, Category = "NPCController")				FName							ControllerTag;					//var(NPCController) FName ControllerTag;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				bool							bSpawnAsReserve;				//var(NPCNavigation) bool bSpawnAsReserve;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				int32							iReinforcementWave;				//var(NPCNavigation) int32 iReinforcementWave;
	UPROPERTY(EditAnywhere, Category = "NPCOrders")					int32							iRespawnsAllowed;				//var(NPCNavigation) int32 iRespawnsAllowed;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				FName							ConvoyTag;						//var(NPCNavigation) FName ConvoyTag;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				bool							ConvoyLeader;					//var(NPCNavigation) bool ConvoyLeader;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				bool							Patrol_NoPathfinding;			//var(NPCNavigation) bool Patrol_NoPathfinding;
	UPROPERTY(EditAnywhere, Category = "HelicopterFailures")		float							fpEngineFailureChance;			//var(HelicopterFailures) float fpEngineFailureChance;
	UPROPERTY(EditAnywhere, Category = "HelicopterFailures")		float							fpRotorFailurePossible;			//var(HelicopterFailures) float fpRotorFailurePossible;
	UPROPERTY(EditAnywhere, Category = "HelicopterFailures")		float							fpCockpitFailurePossible;		//var(HelicopterFailures) float fpCockpitFailurePossible;
	UPROPERTY(EditAnywhere, Category = "HelicopterFailures")		float							fpRepairTime;					//var(HelicopterFailures) float fpRepairTime;
	UPROPERTY(EditAnywhere, Category = "HelicopterCrew")			bool							bIncludeCoPilot;				//var(HelicopterCrew) bool bIncludeCoPilot;
	UPROPERTY(EditAnywhere, Category = "HelicopterCrew")			bool							bIncludeCrewchief;				//var(HelicopterCrew) bool bIncludeCrewchief;
	UPROPERTY(EditAnywhere, Category = "HelicopterCrew")			bool							bIncludeLoadMaster;				//var(HelicopterCrew) bool bIncludeLoadMaster;
	UPROPERTY(EditAnywhere, Category = "HelicopterCrew")			bool							bIncludeRearwardWounded;		//var(HelicopterCrew) bool bIncludeRearwardWounded;
	UPROPERTY(EditAnywhere, Category = "HelicopterCrew")			bool							bIncludeForwardWounded;			//var(HelicopterCrew) bool bIncludeForwardWounded;
	UPROPERTY(EditAnywhere, Category = "HelicopterPickup")			bool							bRequirePZVolume;				//var(HelicopterPickup) bool bRequirePZVolume;
	UPROPERTY(EditAnywhere, Category = "HelicopterPickup")			float							fpMaxDistanceSmokeFromPZ;		//var(HelicopterPickup) float fpMaxDistanceSmokeFromPZ;
	UPROPERTY(EditAnywhere, Category = "NPCPassengerSquadMembers")	TArray<FName>					anameSquadPlayerStartsTag;		//var(NPCPassengerSquadMembers) TArray<FName> anameSquadPlayerStartsTag;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				FName							VehicleTag;						//var(NPCNavigation) FName VehicleTag;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				bool							bTriggerStartVehicle;			//var(NPCNavigation) bool bTriggerStartVehicle;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				FString							sNPCWaypointTag;				//var(NPCNavigation) FString sNPCWaypointTag;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				bool							bMustSpawn;						//var(NPCNavigation) bool bMustSpawn;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				int32							iStartingPathNodeIndex;			//var(NPCNavigation) int32 iStartingPathNodeIndex;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				bool							bStartAndSpawnAtRandomNode;		//var(NPCNavigation) bool bStartAndSpawnAtRandomNode;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				int32							bUseRandomStartingNode;			//var(NPCNavigation) bool bUseRandomStartingNode;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				int32							bAscendingNodeDirection;		//var(NPCNavigation) bool bAscendingNodeDirection;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				bool							bAutoReversePath;				//var(NPCNavigation) bool bAutoReversePath;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				float							fpChanceOfSpawning;				//var(NPCNavigation) float fpChanceOfSpawning;
	UPROPERTY(EditAnywhere, Category = "NPCNavigation")				bool							bDebugPath;						//var(NPCNavigation) bool bDebugPath;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")			AAGP_Pawn*						PawnSpawnClass;					//var(NPCPawnOptions) class<AGP_Pawn> PawnSpawnClass;
	UPROPERTY(EditAnywhere, Category = "NPCPawnOptions")			FName							PawnTag;						//var(NPCPawnOptions) FName PawnTag;
	UPROPERTY(EditAnywhere, Category = "NPCController")				int32							iPlatoonID;						//var(NPCController) int32 iPlatoonID;
	UPROPERTY(EditAnywhere, Category = "NPCController")				int32							iSquadID;						//var(NPCController) int32 iSquadID;
	UPROPERTY(EditAnywhere, Category = "NPCController")				int32							iFireteamID;					//var(NPCController) int32 iFireteamID;
	UPROPERTY(EditAnywhere, Category = "NPCEvents")					FName							DamageEvent;					//var(NPCEvents) FName DamageEvent;
	UPROPERTY(EditAnywhere, Category = "NPCEvents")					FName							ShotdownEvent;					//var(NPCEvents) FName ShotdownEvent;
	UPROPERTY(EditAnywhere, Category = "NPCEvents")					FName							UsedEvent;						//var(NPCEvents) FName UsedEvent;
	UPROPERTY(EditAnywhere, Category = "NPCEvents")					FName							PlayersboardedEvent;			//var(NPCEvents) FName PlayersboardedEvent;
	UPROPERTY(EditAnywhere, Category = "NPCEvents")					int32							iDamageLevelForEvent;			//var(NPCEvents) int32 iDamageLevelForEvent;
	UPROPERTY()														ANPCAICombatController*			npcaiccEnemyCombatController;	//var NPCAICombatController npcaiccEnemyCombatController;

	void Reset();
	void BeginPlay();
	bool ShouldUseStartSpot();
	void CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn);
	ANPCBaseHelicopterController* CreateNPC();
	ANPCPlayerStart* FindNPCPlayerStartByTag(FString sTagToFind);
	void FindEnemyAICC();
};
