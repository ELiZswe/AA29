// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "NPCBasePreCrewedVehicleControlle.generated.h"

class AAGP_Pawn;
class ANPCBaseSoldierController;
class AAA2_PlayerState;
class AThrowWeapon;
class AAGP_Weapon;
class AThrowWeaponPickup;
class ARoadPathNode;
class ANPCRoadPathNode;

UCLASS()
class AA29_API ANPCBasePreCrewedVehicleControlle : public ANPCBaseController
{
	GENERATED_BODY()
public:
	ANPCBasePreCrewedVehicleControlle();

	UPROPERTY()					bool								bSmokeOnAssault;					//var bool bSmokeOnAssault;
	UPROPERTY()					AActor*								actActorInTheWay;					//var Actor actActorInTheWay;
	UPROPERTY()					bool								DrawDriverInTP;						//var bool DrawDriverInTP;
	UPROPERTY()					float								fpTurretRotation;					//var float fpTurretRotation;
	UPROPERTY()					float								fpTurretMaxVisionCone;				//var float fpTurretMaxVisionCone;
	UPROPERTY()					float								fpAngleToPlayerUU;					//var float fpAngleToPlayerUU;
	UPROPERTY()					float								fpDistanceToLastSeenPawn;			//var float fpDistanceToLastSeenPawn;
	UPROPERTY()					float								fpRawAngleToLastSeenPawn;			//var float fpRawAngleToLastSeenPawn;
	UPROPERTY()					float								fpAngleToLastSeenPawn;				//var float fpAngleToLastSeenPawn;
	UPROPERTY()					float								fpCoAxAngleToTarget;				//var float fpCoAxAngleToTarget;
	UPROPERTY()					float								fpCoAxAimError;						//var float fpCoAxAimError;
	UPROPERTY()					int32								iCoAxRounds;						//var int iCoAxRounds;
	UPROPERTY()					AAGP_Weapon*						wpnCoaxRPK;							//var AGP_Weapon wpnCoaxRPK;
	UPROPERTY()					int32								iTotalCoaxRoundsBurstFired;			//var int iTotalCoaxRoundsBurstFired;
	UPROPERTY()					bool								bHasCoAxMachineGun;					//var bool bHasCoAxMachineGun;
	UPROPERTY()					bool								bPatrol_NoPathfinding;				//var bool bPatrol_NoPathfinding;
	UPROPERTY()					bool								bConvoyLeader;						//var bool bConvoyLeader;
	UPROPERTY()					FName								ConvoyTag;							//var name ConvoyTag;
	UPROPERTY()					AVehicle*							ConvoyLeader;						//var Vehicle ConvoyLeader;
	UPROPERTY()					AVehicle*							MyFollowVehicle;					//var Vehicle MyFollowVehicle;
	UPROPERTY()					FVector								vAssaultLocation;					//var FVector vAssaultLocation;
	UPROPERTY()					TArray<ANPCBaseSoldierController*>	anpcbscVehicleSoldiers;				//var array<NPCBaseSoldierController> anpcbscVehicleSoldiers;
	UPROPERTY()					FName								VehicleTag;							//var name VehicleTag;
	UPROPERTY()					bool								bTriggerStart;						//var bool bTriggerStart;
	UPROPERTY()					ARoadPathNode*						npcrpnUnloadPoint;					//var RoadPathNode npcrpnUnloadPoint;
	UPROPERTY()					ANPCRoadPathNode*					rpnLastDebuggedNavPoint;			//var NPCRoadPathNode rpnLastDebuggedNavPoint;
	UPROPERTY()					ANPCBaseSoldierController*			npcbscSpawnedPassenger;				//var NPCBaseSoldierController npcbscSpawnedPassenger;
	UPROPERTY()					int32								iPassengerIndex;					//var int iPassengerIndex;
	UPROPERTY()					ANPCPlayerStart*					anpcpsSquadPlayerStarts;			//var array<NPCPlayerStart> anpcpsSquadPlayerStarts;
	UPROPERTY()					AThrowWeaponPickup*					twpSmokeGrenadeClass;				//var class<ThrowWeaponPickup> twpSmokeGrenadeClass;
	UPROPERTY()					AThrowWeapon*						MyGrenadeClass;						//var class<ThrowWeapon> MyGrenadeClass;
	UPROPERTY()					FString								MyGrenadeClassA;					//var string MyGrenadeClassA;
	UPROPERTY()					AThrowWeaponPickup*					twpSmokeGrenade;					//var ThrowWeaponPickup twpSmokeGrenade;
	UPROPERTY()					AThrowWeapon*						MyGrenade;							//var ThrowWeapon MyGrenade;
	UPROPERTY()					APawn*								TempEnemy;							//var Pawn TempEnemy;
	UPROPERTY()					int32								iCurrentDrivingPathNodeIndex;		//var int iCurrentDrivingPathNodeIndex;
	UPROPERTY()					int32								iActivePatrolPath;					//var int iActivePatrolPath;
	UPROPERTY()					TArray<FVehiclePatrolPaths>			avppDrivingPathsForPatrols;			//var array<VehiclePatrolPaths> avppDrivingPathsForPatrols;
	UPROPERTY()					FName								nameUnloadLocation;					//var name nameUnloadLocation;
	UPROPERTY()					bool								bUnloadIfDamaged;					//var bool bUnloadIfDamaged;
	UPROPERTY()					float								fpMinDelayBeforeMovingOut;			//var float fpMinDelayBeforeMovingOut;
	UPROPERTY()					bool								bFireWhileUnloading;				//var bool bFireWhileUnloading;
	UPROPERTY()					FName								namePostUnloadState;				//var name namePostUnloadState;
	UPROPERTY()					bool								bIgnoreFogDistance;					//var bool bIgnoreFogDistance;
	UPROPERTY()					bool								bRouteBlocked;						//var bool bRouteBlocked;
	UPROPERTY()					ARoadPathNode*						pnTravelNode;						//var RoadPathNode pnTravelNode;
	UPROPERTY()					ARoadPathNode*						pnCurrentRoadPathNode;				//var RoadPathNode pnCurrentRoadPathNode;
	UPROPERTY()					AAGP_Pawn*							agpPawnNPC;							//var AGP_Pawn agpPawnNPC;
	UPROPERTY()					AAA2_PlayerState*					priFromNPCPawn;						//var PlayerReplicationInfo priFromNPCPawn;
	UPROPERTY()					float								ForcedDestinationDelay;				//var float ForcedDestinationDelay;
	UPROPERTY()					FVector								ForcedDestinationLocation;			//var FVector ForcedDestinationLocation;
	UPROPERTY()					ARoadPathNode*						ForcedDestination;					//var RoadPathNode ForcedDestination;
	UPROPERTY()					FString								sVehicleType;						//var string sVehicleType;
	UPROPERTY()					AVehicle*							agpvVehicle;						//var Vehicle agpvVehicle;
	UPROPERTY()					TArray<AVehicle*>					VehicleClass;						//var class<Vehicle> VehicleClass;

	void AdjustStateByConfidenceLevel();
	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	void DisplayDebugNoSpam(AAGP_HUD* AGPHUD, UCanvas* Canvas, float& YL, float& YPos, FColor NewColor);
	void Start();
	void InitVehicle();
	APathNode* GetPathnodeByTagString(FString sTag);
	void PreloadPathNodeList();
	void NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade);
	void NotifyFlashBanged(float Duration, float VisIntensity, float AudIntensity);
	void NotifyEnemyVehicleSpotted(FVector vLocation);
	ARoadPathNode* FindNextDrivingPatrolPathNode();
	//void Possess(APawn* aPawn);
	//void UnPossess();
	void DelayedExecuteOrder();
	void NotifyTrigger(AActor* Other, APawn* EventInstigator);
	void NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, FVector vSoundLocation);
	void NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard);
	void SeePlayer(APawn* Seen);
	bool CanSeePlayer(FRotator rotView, APawn* Seen);
	void WarnAboutToRunOverTeammate(AController* ctrlTeammate);
	void SeePlayerTimer();
	void Turret_Scan();
	void EnemyNotVisibleTimer();
	void CannotAimAtEnemy();
	void CoaxFiringTimer();
	void CoaxDelay();
	void StartCoaxFiring(bool bStart);
	void ChangeOrders(int32 iNewOrders);
	void FireCoaxWeapon();
	void ForceMoveTo(FName DestinationTag);
	void Timer_CheckEmptyVehicleLocations();
	FVector GetAvoidanceLocation();
	void UnloadPassengers();
	void LocateAssaultLocation();
	void DebugDumpRoute();
	void NPCLog(FString sLogText);
	void DebugMarkNextNode(APathNode* pnNext);
};
