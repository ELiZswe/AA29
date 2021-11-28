// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/aAIController.h"
#include "NPCBaseHelicopterController.generated.h"

/**
 * 
 */
class AHumanController;
//class ADebugNPCNavigation;
class ANPCPlayerStart;
class AFlyingPathNode;
class AAGP_Pawn;
//class APlayerReplicationInfo;
//class ANPCAICombatController;
//class AVehicle;
//class ANPCHelicopterWoundedPassenger;

UCLASS()
class AA29_API ANPCBaseHelicopterController : public AaAIController
{
	GENERATED_BODY()
public:
	ANPCBaseHelicopterController();

	UPROPERTY()										TArray<USoundBase*> asndQueue;							//var array<Sound> asndQueue;
	UPROPERTY()										USoundBase* sndTakingGenericFire;						//var Sound sndTakingGenericFire;
	UPROPERTY()										USoundBase* sndTakingVehicleFire;						//var Sound sndTakingVehicleFire;
	UPROPERTY()										USoundBase* sndTakingInfantryFire ;						//var Sound sndTakingInfantryFire;
	UPROPERTY()										USoundBase* sndPZNotSecureGeneric ;						//var Sound sndPZNotSecureGeneric;
	UPROPERTY()										USoundBase* sndPZNotSecureVehicleFire ;					//var Sound sndPZNotSecureVehicleFire;
	UPROPERTY()										USoundBase* sndPZNotSecureInfantryFire ;				//var Sound sndPZNotSecureInfantryFire;
	UPROPERTY()										USoundBase* sndBadPZ ;									//var Sound sndBadPZ;
	UPROPERTY()										USoundBase* sndCallGreenSmoke;							//var Sound sndCallGreenSmoke;
	UPROPERTY()										USoundBase* sndPZOnWayPartFour;							//var Sound sndPZOnWayPartFour;
	UPROPERTY()										USoundBase* sndPZOnWayPartThree;						//var Sound sndPZOnWayPartThree;
	UPROPERTY()										USoundBase* sndPZOnWayPartTwo;							//var Sound sndPZOnWayPartTwo;
	UPROPERTY()										USoundBase* sndPZOnWayPartOne;							//var Sound sndPZOnWayPartOne;
	UPROPERTY()										USoundBase* sndRepairsComplete;							//var Sound sndRepairsComplete;
	UPROPERTY()										USoundBase* sndRepairing;								//var Sound sndRepairing;
	UPROPERTY()										USoundBase* sndMayday;									//var Sound sndMayday;
	UPROPERTY()										USoundBase* sndHelicopterSpotted;						//var Sound sndHelicopterSpotted;
	UPROPERTY()										USoundBase* sndCarSpotted;								//var Sound sndCarSpotted;
	UPROPERTY()										USoundBase* sndMortarTeamSpotted;						//var Sound sndMortarTeamSpotted;
	UPROPERTY()										USoundBase* sndT62Spotted;								//var Sound sndT62Spotted;
	UPROPERTY()										USoundBase* sndTankSpotted;								//var Sound sndTankSpotted;
	UPROPERTY()										USoundBase* sndInfantrySpotted;							//var Sound sndInfantrySpotted;
	UPROPERTY()										USoundBase* sndBTRSpotted;								//var Sound sndBTRSpotted;
	UPROPERTY()										USoundBase* sndBMPSpotted;								//var Sound sndBMPSpotted;
	UPROPERTY()										USoundBase* asndNumbersAgitated;						//var Sound asndNumbersAgitated;
	UPROPERTY()										USoundBase* asndNumbers;								//var Sound asndNumbers;
	UPROPERTY()										USoundBase* sndByA;										//var Sound sndByA;
	UPROPERTY()										USoundBase* sndBy;										//var Sound sndBy;
	UPROPERTY()										USoundBase* sndHelicopterBGNoise;						//var Sound sndHelicopterBGNoise;
	UPROPERTY()										USoundBase* sndOver;									//var Sound sndOver;
	UPROPERTY()										USoundBase* sndNone;									//var Sound sndNone;
	UPROPERTY()										USoundBase* sndRadioPopOut;								//var Sound sndRadioPopOut;
	UPROPERTY()										USoundBase* sndRadioPopIn;								//var Sound sndRadioPopIn;
	UPROPERTY()										bool bBadPickupZone;									//var bool bBadPickupZone;
	UPROPERTY()										float fpMaxDistanceSmokeFromPZ;							//var float fpMaxDistanceSmokeFromPZ;
	UPROPERTY()										bool bRequirePZVolume;									//var bool bRequirePZVolume;
	UPROPERTY()										AHumanController* humctlrPlayerCallingForPickup;		//var HumanController humctlrPlayerCallingForPickup;
	UPROPERTY()										int32 iPlayersToPickupCount;							//var int iPlayersToPickupCount;
	UPROPERTY()										int32 iDamageSinceLandingStarted;						//var int iDamageSinceLandingStarted;
	UPROPERTY()										APawn* pawnLastSeen;									//var Pawn pawnLastSeen;
	UPROPERTY()										float fpTimeSinceLastContactReport;						//var float fpTimeSinceLastContactReport;
	UPROPERTY()										float fpTimeSinceLastTakingFireMessage;					//var float fpTimeSinceLastTakingFireMessage;
	UPROPERTY()										FName PlayersboardedEvent;								//var name PlayersboardedEvent;
	UPROPERTY()										FName UsedEvent;										//var name UsedEvent;
	UPROPERTY()										FName ShotdownEvent;									//var name ShotdownEvent;
	UPROPERTY()										int32 iDamageLevelForEvent;								//var int iDamageLevelForEvent;
	UPROPERTY()										FName DamageEvent;										//var name DamageEvent;
	UPROPERTY()										int32 iDesiredTravelSpeed;								//var int iDesiredTravelSpeed;
	UPROPERTY()										bool bIncludeForwardWounded;							//var bool bIncludeForwardWounded;
	UPROPERTY()										bool bIncludeRearwardWounded;							//var bool bIncludeRearwardWounded;
	UPROPERTY()										bool bIncludeLoadMaster;								//var bool bIncludeLoadMaster;
	UPROPERTY()										bool bIncludeCrewchief;									//var bool bIncludeCrewchief;
	UPROPERTY()										bool bIncludeCoPilot;									//var bool bIncludeCoPilot;
	UPROPERTY()										bool bResumePathAfterFailure;							//var bool bResumePathAfterFailure;
	UPROPERTY()										bool bMechanicalFailureCrash;							//var bool bMechanicalFailureCrash;
	UPROPERTY()										float fpMechanicalFailureTimer;							//var float fpMechanicalFailureTimer;
	UPROPERTY()										float fpCockpitFailurePossible;							//var float fpCockpitFailurePossible;
	UPROPERTY()										float fpRotorFailurePossible;							//var float fpRotorFailurePossible;
	UPROPERTY()										float fpEngineFailureChance;							//var float fpEngineFailureChance;
	UPROPERTY()										float fpRepairTime;										//var float fpRepairTime;
	UPROPERTY()										float fpLastGroundFireAdjust;							//var float fpLastGroundFireAdjust;
	UPROPERTY()										float fpGroundFireAvoidanceAltitudeBump;				//var float fpGroundFireAvoidanceAltitudeBump;
	//UPROPERTY()										ADebugNPCNavigation* dnpcnDebugTerrainRadarMarker;		//var DebugNPCNavigation dnpcnDebugTerrainRadarMarker;
	UPROPERTY()										FVector vLocationLandingZone;							//var Object.Vector vLocationLandingZone;
	UPROPERTY()										bool bDebugPitchDirectionUp;							//var bool bDebugPitchDirectionUp;
	UPROPERTY()										bool DrawDriverInTP;									//var bool DrawDriverInTP;
	UPROPERTY()										bool bFollowPatrol;										//var bool bFollowPatrol;
	UPROPERTY()										float fpMaxBackwardSpeed;								//var float fpMaxBackwardSpeed;
	UPROPERTY()										float fpMaxSpeed;										//var float fpMaxSpeed;
	UPROPERTY()										FString sDebugNavMode;									//var string sDebugNavMode;
	UPROPERTY()										FString sDebugCrashStatus;								//var string sDebugCrashStatus;
	UPROPERTY()										FString sDebugFwdAltitude;								//var string sDebugFwdAltitude;
	UPROPERTY()										FString sDebugAltitude2;								//var string sDebugAltitude2;
	UPROPERTY()										FString sDebugAltitude;									//var string sDebugAltitude;
	UPROPERTY()										FString sDebugCollective2;								//var string sDebugCollective2;
	UPROPERTY()										FString sDebugCollective;								//var string sDebugCollective;
	UPROPERTY()										FString sDebugCyclicPitch;								//var string sDebugCyclicPitch;
	UPROPERTY()										FString sDebugNavInfo;									//var string sDebugNavInfo;
	UPROPERTY()										FVector vAdjustedPathNodeLocation;						//var Object.Vector vAdjustedPathNodeLocation;
	UPROPERTY()										FVector vHoverStartLocation;							//var Object.Vector vHoverStartLocation;
	UPROPERTY()										bool bStart;											//var bool bStart;
	UPROPERTY()										float anpcbscVehicleSoldiers;							//var array<NPCBaseSoldierController> anpcbscVehicleSoldiers;
	UPROPERTY()										float SknpcrpnUnloadPointill;							//var FlyingPathNode npcrpnUnloadPoint;
	UPROPERTY()										float rpnLastDebuggedNavPoint;							//var FlyingPathNode rpnLastDebuggedNavPoint;
	UPROPERTY()										float npcbscSpawnedPassenger;							//var NPCBaseSoldierController npcbscSpawnedPassenger;
	UPROPERTY()										int32 iPassengerIndex;									//var int iPassengerIndex;
	UPROPERTY()										TArray<ANPCPlayerStart*>anpcpsSquadPlayerStarts;		//var array<NPCPlayerStart> anpcpsSquadPlayerStarts;
	UPROPERTY()										APawn* TempEnemy;										//var Pawn TempEnemy;
	UPROPERTY()										int32 iCurrentDrivingPathNodeIndex;						//var int iCurrentDrivingPathNodeIndex;
	UPROPERTY()										TArray<AFlyingPathNode*> apnFlyingPathNodesForPatrol;	//var array<FlyingPathNode> apnFlyingPathNodesForPatrol;
	UPROPERTY()										float fpTerrainAvoidanceAltitudeBump;					//var float fpTerrainAvoidanceAltitudeBump;
	UPROPERTY()										float fpMinAltitude;									//var float fpMinAltitude;
	UPROPERTY()										int32 iCurrentPathNodeIndex;							//var int iCurrentPathNodeIndex;
	UPROPERTY()										bool bUseAlternatePath;									//var bool bUseAlternatePath;
	UPROPERTY()										int32 iNPCPrimaryOrders;								//var int iNPCPrimaryOrders;
	UPROPERTY()										FName VehicleTag;										//var name VehicleTag;
	UPROPERTY()										bool bTriggerStart;										//var bool bTriggerStart;
	UPROPERTY()										bool bPatrol_NoPathfinding;								//var bool bPatrol_NoPathfinding;
	UPROPERTY()										bool bConvoyLeader;										//var bool bConvoyLeader;
	UPROPERTY()										FName ConvoyTag;										//var name ConvoyTag;
	UPROPERTY()										bool bAutoReversePath;									//var bool bAutoReversePath;
	UPROPERTY()										bool bAscendingNodeDirection;							//var bool bAscendingNodeDirection;
	UPROPERTY()										int32 iStartingPathNodeIndex;							//var int iStartingPathNodeIndex;
	UPROPERTY()										int32 iNPCCurrentOrders;								//var int iNPCCurrentOrders;
	UPROPERTY()										bool bDebugSenses;										//var bool bDebugSenses;
	UPROPERTY()										bool bDebugPath;										//var bool bDebugPath;
	UPROPERTY()										bool bDebugMode;										//var bool bDebugMode;
	UPROPERTY()										bool bRouteBlocked;										//var bool bRouteBlocked;
	UPROPERTY()										bool bDummyHelicopter;									//var bool bDummyHelicopter;
	UPROPERTY()										FRotator rotDummyRotation;								//var Object.Rotator rotDummyRotation;
	UPROPERTY()										AFlyingPathNode* pnTravelNode;							//var FlyingPathNode pnTravelNode;
	UPROPERTY()										AFlyingPathNode* pnCurrentFlyingPathNode;				//var FlyingPathNode pnCurrentFlyingPathNode;
	UPROPERTY()										AAGP_Pawn* agpPawnNPC			;						//var AGP_Pawn agpPawnNPC;
	//UPROPERTY()										APlayerReplicationInfo* priFromNPCPawn;					//var PlayerReplicationInfo priFromNPCPawn;
	UPROPERTY()										float ForcedDestinationDelay;							//var float ForcedDestinationDelay;
	UPROPERTY()										FVector ForcedDestinationLocation;						//var Object.Vector ForcedDestinationLocation;
	UPROPERTY()										AFlyingPathNode* ForcedDestination;						//var FlyingPathNode ForcedDestination;
	UPROPERTY()										FString sVehicleType;									//var string sVehicleType;
	//UPROPERTY()										ANPCHelicopterWoundedPassenger* anpchwpForwardWounded;	//var NPCHelicopterWoundedPassenger anpchwpForwardWounded;
	//UPROPERTY()										ANPCHelicopterWoundedPassenger* anpchwpRearwardWounded;	//var NPCHelicopterWoundedPassenger anpchwpRearwardWounded;
	UPROPERTY()										AAGP_Pawn* agpCoPilot;									//var AGP_Pawn agpCoPilot;
	UPROPERTY()										AAGP_Pawn* agpCrewLoadMaster;							//var AGP_Pawn agpCrewLoadMaster;
	UPROPERTY()										AAGP_Pawn* agpCrewChief;								//var AGP_Pawn agpCrewChief;
	//UPROPERTY()										AVehicle* agpvVehicle;									//var Vehicle agpvVehicle;
	UPROPERTY()										int32 iActivePatrolPath;								//var int iActivePatrolPath;
	//UPROPERTY()										AVehicle* VehicleClass;									//var class<Vehicle> VehicleClass;
	UPROPERTY()										FString sNPCWaypointTag;								//var string sNPCWaypointTag;
	UPROPERTY()										FString sCallSign;										//var string sCallSign;
	//UPROPERTY()										ANPCAICombatController* npcaiccEnemyCombatController;	//var NPCAICombatController npcaiccEnemyCombatController;

	//void DisplayDebug(UCanvas Canvas, float& YL, float& YPos);
	void Land(FVector vLoc, AController* ctrlOwner);
	void NextWaypoint();
	void TakeOff();
	void Hover();
	void Start();
	void Patrol();
	void SignalPoppingSmoke();
	void InitVehicle();
	void GetPathnodeByTagString(FString sTag);
	void PreloadPathNodeList();
	void FindNextDrivingPatrolPathNode();
	//void Possess(APawn* aPawn);
	void AttachPlayer(APawn* pawnPlayer);
	//void UnPossess();
	void WatchForMechanicalFailuresTimer();
	void TransmitAudioRadioMessage(USoundBase* sndAudioMessage);
	void PlayAudioRadioMessage(USoundBase* sndAudioMessage);
	void PlayNextQueuedSoundTimer();
	void TransmitRadioMessage(FString sMsg);
	void TransmitAudioLocationRadioMessage(FVector vLoc, bool bAgitated);
	void TransmitAudioRadioNumber(int32 iNumber, bool bAgitated);
	void LocationToGrid(FVector vLoc);
	void AdjustPitchForPositionHold();
	void AdjustRollForPositionHold();
	void AdjustForAltitudeHold();
	void GetForwardRealAltitude();
	void GetRealAltitude();
	void HoldSpecificAltitude(float fpDesiredAltitude, bool bDisableVarianceForLanding);
	void AdjustForDesiredSpeed();
	void AdjustToDesiredHeight();
	void DescendToAltitude(float fpTargetHeight);
	void SeeMonster(APawn* Seen);
	void DetermineNextPathNode();
	void DebugDumpRoute();
	void NPCPathLog(FString sLogText);
	void NPCLog(FString sLogText);
	void Destroyed();
	void CleanupCrew();
	void EnableDebugTerrainRadarTrace();
	void NotifyTakeDamage(int32 Damage32, APawn* instigatedBy, FVector HitLocation, UaDamageType DamageType, FBoneInfo Bone);

};
