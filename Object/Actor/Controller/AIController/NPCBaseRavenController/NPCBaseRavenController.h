// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/AIController/aAIController.h"
#include "NPCBaseRavenController.generated.h"

/**
 * 
 */

class ANPCBaseSoldierController;

UCLASS()
class AA29_API ANPCBaseRavenController : public AaAIController
{
	GENERATED_BODY()
public:
	ANPCBaseRavenController();

	//UPROPERTY()										TArray<AUAVFlightPlanWaypoints> auavfpwpWaypoints;					//var array<UAVFlightPlanWaypoints> auavfpwpWaypoints;
	UPROPERTY()										APawn* pawnLastSeen;												//var Pawn pawnLastSeen;
	UPROPERTY()										FName UsedEvent;													//var name UsedEvent;
	UPROPERTY()										FName ShotdownEvent;												//var name ShotdownEvent;
	UPROPERTY()										int32 iDamageLevelForEvent;											//var int iDamageLevelForEvent;
	UPROPERTY()										FName DamageEvent;													//var name DamageEvent;
	UPROPERTY()										int32 iDesiredTravelSpeed;											//var int iDesiredTravelSpeed;
	UPROPERTY()										bool bResumePathAfterFailure;										//var bool bResumePathAfterFailure;
	UPROPERTY()										bool bMechanicalFailureCrash;										//var bool bMechanicalFailureCrash;
	UPROPERTY()										float fpMechanicalFailureTimer;										//var float fpMechanicalFailureTimer;
	UPROPERTY()										float fpCockpitFailurePossible;										//var float fpCockpitFailurePossible;
	UPROPERTY()										float fpRotorFailurePossible;										//var float fpRotorFailurePossible;
	UPROPERTY()										float fpEngineFailureChance;										//var float fpEngineFailureChance;
	UPROPERTY()										float fpRepairTime;													//var float fpRepairTime;
	UPROPERTY()										float fpLastGroundFireAdjust;										//var float fpLastGroundFireAdjust;
	UPROPERTY()										float fpGroundFireAvoidanceAltitudeBump;							//var float fpGroundFireAvoidanceAltitudeBump;
	//UPROPERTY()										ADebugNPCNavigation* dnpcnDebugTerrainRadarMarker;					//var DebugNPCNavigation dnpcnDebugTerrainRadarMarker;
	UPROPERTY()										FVector vLocationLandingZone;										//var Object.Vector vLocationLandingZone;
	UPROPERTY()										bool bDebugPitchDirectionUp;										//var bool bDebugPitchDirectionUp;
	UPROPERTY()										bool bFollowPatrol;													//var bool bFollowPatrol;
	UPROPERTY()										float fpMaxBackwardSpeed;											//var float fpMaxBackwardSpeed;
	UPROPERTY()										float fpMaxSpeed;													//var float fpMaxSpeed;
	UPROPERTY()										FString sDebugNavMode;												//var string sDebugNavMode;
	UPROPERTY()										FString sDebugCrashStatus;											//var string sDebugCrashStatus;
	UPROPERTY()										FString sDebugFwdAltitude;											//var string sDebugFwdAltitude;
	UPROPERTY()										FString sDebugAltitude2;											//var string sDebugAltitude2;
	UPROPERTY()										FString sDebugAltitude;												//var string sDebugAltitude;
	UPROPERTY()										FString sDebugCollective2;											//var string sDebugCollective2;
	UPROPERTY()										FString sDebugCollective;											//var string sDebugCollective;
	UPROPERTY()										FString sDebugCyclicPitch;											//var string sDebugCyclicPitch;
	UPROPERTY()										FString sDebugNavInfo;												//var string sDebugNavInfo;
	UPROPERTY()										FVector vAdjustedPathNodeLocation;									//var Object.Vector vAdjustedPathNodeLocation;
	UPROPERTY()										FVector vHoverStartLocation;										//var Object.Vector vHoverStartLocation;
	UPROPERTY()										bool bStart;														//var bool bStart;
	UPROPERTY()										TArray<ANPCBaseSoldierController*> anpcbscVehicleSoldiers;			//var array<NPCBaseSoldierController> anpcbscVehicleSoldiers;
	//UPROPERTY()										AFlyingPathNode* npcrpnUnloadPoint;									//var FlyingPathNode npcrpnUnloadPoint;
	//UPROPERTY()										AFlyingPathNode* rpnLastDebuggedNavPoint;							//var FlyingPathNode rpnLastDebuggedNavPoint;
	UPROPERTY()										ANPCBaseSoldierController* npcbscSpawnedPassenger;					//var NPCBaseSoldierController npcbscSpawnedPassenger;
	UPROPERTY()										int32 iPassengerIndex;												//var int iPassengerIndex;
	//UPROPERTY()										TArray<ANPCPlayerStart*> anpcpsSquadPlayerStarts;					//var array<NPCPlayerStart> anpcpsSquadPlayerStarts;
	UPROPERTY()										APawn* TempEnemy;													//var Pawn TempEnemy;
	UPROPERTY()										int32 iCurrentDrivingPathNodeIndex;									//var int iCurrentDrivingPathNodeIndex;
	//UPROPERTY()										TArray<AFlyingPathNode*> apnFlyingPathNodesForPatrol;				//var array<FlyingPathNode> apnFlyingPathNodesForPatrol;
	UPROPERTY()										float fpTerrainAvoidanceAltitudeBump;								//var float fpTerrainAvoidanceAltitudeBump;
	UPROPERTY()										float fpRealAltitude;												//var float fpRealAltitude;
	UPROPERTY()										float fpMinAltitude;												//var float fpMinAltitude;
	UPROPERTY()										int32 iCurrentPathNodeIndex;										//var int iCurrentPathNodeIndex;
	UPROPERTY()										bool bUseAlternatePath;												//var bool bUseAlternatePath;
	UPROPERTY()										int32 iNPCPrimaryOrders;											//var int iNPCPrimaryOrders;
	UPROPERTY()										FName VehicleTag;													//var name VehicleTag;
	UPROPERTY()										bool bTriggerStart;													//var bool bTriggerStart;
	UPROPERTY()										bool bPatrol_NoPathfinding;											//var bool bPatrol_NoPathfinding;
	UPROPERTY()										bool bConvoyLeader;													//var bool bConvoyLeader;
	UPROPERTY()										FName ConvoyTag;													//var name ConvoyTag;
	UPROPERTY()										bool bAutoReversePath;												//var bool bAutoReversePath;
	UPROPERTY()										bool bAscendingNodeDirection;										//var bool bAscendingNodeDirection;
	UPROPERTY()										int32 iStartingPathNodeIndex;										//var int iStartingPathNodeIndex;
	UPROPERTY()										int32 iNPCCurrentOrders;											//var int iNPCCurrentOrders;
	UPROPERTY()										bool bDebugSenses;													//var bool bDebugSenses;
	UPROPERTY()										bool bDebugPath;													//var bool bDebugPath;
	UPROPERTY()										bool bDebugMode;													//var bool bDebugMode;
	UPROPERTY()										bool bRouteBlocked;													//var bool bRouteBlocked;
	//UPROPERTY()										AFlyingPathNode* pnTravelNode;										//var FlyingPathNode pnTravelNode;
	//UPROPERTY()										AFlyingPathNode pnCurrentFlyingPathNode;							//var FlyingPathNode pnCurrentFlyingPathNode;
	UPROPERTY()										AAGP_Pawn* agpPawnNPC;												//var AGP_Pawn agpPawnNPC;
	//UPROPERTY()										APlayerReplicationInfo* priFromNPCPawn;								//var PlayerReplicationInfo priFromNPCPawn;
	UPROPERTY()										float ForcedDestinationDelay;										//var float ForcedDestinationDelay;
	UPROPERTY()										FVector ForcedDestinationLocation;									//var Object.Vector ForcedDestinationLocation;
	//UPROPERTY()										AFlyingPathNode* ForcedDestination;									//var FlyingPathNode ForcedDestination;
	UPROPERTY()										FString sVehicleType;												//var string sVehicleType;
	//UPROPERTY()										AVehicle* agpvVehicle;												//var Vehicle agpvVehicle;
	UPROPERTY()										int32 iActivePatrolPath;											//var int iActivePatrolPath;
	//UPROPERTY()										AVehicle* VehicleClass;												//var class<Vehicle> VehicleClass;
	UPROPERTY()										FString sNPCWaypointTag;											//var string sNPCWaypointTag;
	UPROPERTY()										FString sCallSign;													//var string sCallSign;

	//void DisplayDebug(UCanvas Canvas, float& YL, float& YPos);
	void Land(FVector vLoc);
	void NextWaypoint();
	void TakeOff();
	void Hover();
	void Start();
	void Patrol();
	void GetPathnodeByTagString(FString sTag);
	void PreloadPathNodeList();
	void FindNextDrivingPatrolPathNode();
	void InitVehicle();
	//void Possess(APawn* aPawn);
	//void UnPossess();
	void WatchForMechanicalFailuresTimer();
	void LocationToGrid(FVector vLoc);
	void AdjustPitchForPositionHold();
	void AdjustRollForPositionHold();
	void AdjustForAltitudeHold();
	void GetForwardRealAltitude();
	void GetRealAltitude();
	void HoldSpecificAltitude(float fpDesiredAltitude, bool bDisableVarianceForLanding);
	void AdjustForDesiredSpeed();
	void AdjustToDesiredHeight();
	void TurnedEnough(float fpAngle);
	void AdjustThrottleToDesiredSpeed();
	void StopMovement();
	void DescendToAltitude(float fpTargetHeight);
	void DetermineNextPathNode();
	void DebugDumpRoute();
	void NPCPathLog(FString sLogText);
	void NPCLog(FString sLogText);
	void EnableDebugTerrainRadarTrace();
	void NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType* DamageType, FBoneInfo Bone);

};
