// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "AA29/AA29.h"
#include "AA2_Controller.generated.h"

class AMover;
class ANavigationPoint;
class AVehicle;
class UReachSpec;
class AAA2_PlayerState;
class AAvoidMarker;
class AProjectile;
class AWeapon;
class APathNode;
class APickup;
class UaDamageType;
class AAmmunition;
class AInventory;

UCLASS(Config = Game)
class AA29_API AAA2_Controller : public AController
{
	GENERATED_BODY()
public:
		AAA2_Controller();

		UPROPERTY()										int32					PlayerNum;							//var const int32 PlayerNum;
		UPROPERTY()										float					SightCounter;						//var float SightCounter;
		UPROPERTY()										float					FovAngle;							//var float FovAngle;
		UPROPERTY(globalconfig)							float					Handedness;							//var globalconfig float Handedness;
		UPROPERTY()										bool					bIsPlayer;							//var bool bIsPlayer;
		UPROPERTY()										bool					bGodMode;							//var bool bGodMode;
		UPROPERTY()										bool					bSuperGodMode;						//var bool bSuperGodMode;
		UPROPERTY()										bool					bLOSflag;							//var const bool bLOSflag;
		UPROPERTY()										bool					bAdvancedTactics;					//var bool bAdvancedTactics;
		UPROPERTY()										bool					bCanOpenDoors;						//var bool bCanOpenDoors;
		UPROPERTY()										bool					bCanDoSpecial;						//var bool bCanDoSpecial;
		UPROPERTY()										bool					bAdjusting;							//var bool bAdjusting;
		UPROPERTY()										bool					bPreparingMove;						//var bool bPreparingMove;
		UPROPERTY()										bool					bControlAnimations;					//var bool bControlAnimations;
		UPROPERTY()										bool					bEnemyInfoValid;					//var bool bEnemyInfoValid;
		UPROPERTY()										bool					bNotifyApex;						//var bool bNotifyApex;
		UPROPERTY()										bool					bUsePlayerHearing;					//var bool bUsePlayerHearing;
		UPROPERTY()										bool					bJumpOverWall;						//var bool bJumpOverWall;
		UPROPERTY()										bool					bEnemyAcquired;						//var bool bEnemyAcquired;
		UPROPERTY()										bool					bSoaking;							//var bool bSoaking;
		UPROPERTY()										bool					bHuntPlayer;						//var bool bHuntPlayer;
		UPROPERTY()										bool					bAllowedToTranslocate;				//var bool bAllowedToTranslocate;
		UPROPERTY()										bool					bAllowedToImpactJump;				//var bool bAllowedToImpactJump;
		UPROPERTY()										bool					bAdrenalineEnabled;					//var bool bAdrenalineEnabled;
		UPROPERTY()										bool					bNotifyFallingHitWall;				//var bool bNotifyFallingHitWall;
		UPROPERTY()										bool					bSlowerZAcquire;					//var bool bSlowerZAcquire;
		UPROPERTY()										bool					bInDodgeMove;						//var bool bInDodgeMove;
		UPROPERTY()										bool					bVehicleTransition;					//var bool bVehicleTransition;
		UPROPERTY()										bool					bForceStrafe;						//var bool bForceStrafe;
		UPROPERTY()										bool					bNotifyPostLanded;					//var bool bNotifyPostLanded;
		UPROPERTY()										bool					bIgnoreSetTargetRotation;			//var bool bIgnoreSetTargetRotation;
		UPROPERTY()										int32					CurrentTeam;						//var int32 CurrentTeam;
		UPROPERTY()										bool					bPatrolling;						//var bool bPatrolling;
		UPROPERTY()										bool					bUnlimitedAmmo;						//var bool bUnlimitedAmmo;
		UPROPERTY()										bool					bPerfectAccuracy;					//var bool bPerfectAccuracy;
		UPROPERTY()										bool					bFriendlyFireOff;					//var bool bFriendlyFireOff;
		UPROPERTY()										bool					bInvisible;							//var bool bInvisible;
		UPROPERTY()										bool					bNoWeaponPenalty;					//var bool bNoWeaponPenalty;
		UPROPERTY()										bool					bNativeBonus;						//var bool bNativeBonus;
		UPROPERTY()										bool					bSmoothedView;						//var bool bSmoothedView;
		UPROPERTY()										uint8					bRun;								//var input uint8 bRun;
		UPROPERTY()										uint8					bDuck;								//var input uint8 bDuck;
		UPROPERTY()										uint8					bFire;								//var input uint8 bFire;
		UPROPERTY()										uint8					bAltFire;							//var input uint8 bAltFire;
		UPROPERTY()										uint8					bVoiceTalk;							//var input uint8 bVoiceTalk;
		UPROPERTY()										FVector					AdjustLoc;							//var Vector AdjustLoc;
		UPROPERTY()										AController*			nextController;						//var const Controller nextController;
		UPROPERTY()										float					Stimulus;							//var float Stimulus;
		UPROPERTY()										float					MoveTimer;							//var float MoveTimer;
		UPROPERTY()										AActor*					MoveTarget;							//var Actor MoveTarget;
		UPROPERTY()										FVector					Destination;						//var Vector Destination;
		UPROPERTY()										FVector					FocalPoint;							//var Vector FocalPoint;
		UPROPERTY()										AActor*					Focus;								//var Actor Focus;
		UPROPERTY()										float					FocusLead;							//var float FocusLead;
		UPROPERTY()										AMover*					PendingMover;						//var Mover PendingMover;
		UPROPERTY()										TArray<AActor*>			GoalList;							//var Actor GoalList[4];
		UPROPERTY()										ANavigationPoint*		home;								//var NavigationPoint home;
		UPROPERTY()										float					MinHitWall;							//var float MinHitWall;
		UPROPERTY()										float					RespawnPredictionTime;				//var float RespawnPredictionTime;
		UPROPERTY()										float					DodgeToGoalPct;						//var float DodgeToGoalPct;
		UPROPERTY()										int32					AcquisitionYawRate;					//var int32 AcquisitionYawRate;
		UPROPERTY()										float					DodgeLandZ;							//var float DodgeLandZ;
		UPROPERTY()										AVehicle*				LastBlockingVehicle;				//var Vehicle LastBlockingVehicle;
		UPROPERTY()										APawn*					Enemy;								//var Pawn Enemy;
		UPROPERTY()										AActor*					Target;								//var Actor Target;
		UPROPERTY()										FVector					LastSeenPos;						//var Vector LastSeenPos;
		UPROPERTY()										FVector					LastSeeingPos;						//var Vector LastSeeingPos;
		UPROPERTY()										float					LastSeenTime;						//var float LastSeenTime;
		UPROPERTY()										FString					VoiceType;							//var FString VoiceType;
		UPROPERTY()										float					OldMessageTime;						//var float OldMessageTime;
		UPROPERTY()										TArray<AActor*>			RouteCache;							//var Actor RouteCache[62];
		UPROPERTY()										UReachSpec*				CurrentPath;						//var ReachSpec CurrentPath;
		UPROPERTY()										UReachSpec*				NextRoutePath;						//var ReachSpec NextRoutePath;
		UPROPERTY()										FVector					CurrentPathDir;						//var Vector CurrentPathDir;
		UPROPERTY()										AActor*					RouteGoal;							//var Actor RouteGoal;
		UPROPERTY()										float					RouteDist;							//var float RouteDist;
		UPROPERTY()										float					LastRouteFind;						//var float LastRouteFind;
		UPROPERTY()										FVector					DirectionHint;						//var Vector DirectionHint;
		UPROPERTY()										APathNode*				pnCurrentlyOccupiedPathNode;		//var PathNode pnCurrentlyOccupiedPathNode;
		UPROPERTY(EditAnywhere)							AAA2_PlayerState*		PlayerReplicationInfoClass;			//var() class<PlayerReplicationInfo> PlayerReplicationInfoClass;
		UPROPERTY()										float					PlayerReplicationInfo;				//var PlayerReplicationInfo PlayerReplicationInfo;
		UPROPERTY()										APawn*					PawnClass;							//var class<Pawn> PawnClass;
		UPROPERTY()										APawn*					PreviousPawnClass;					//var class<Pawn> PreviousPawnClass;
		UPROPERTY()										AActor*					TeamRoleClass;						//var class<Actor> TeamRoleClass;
		UPROPERTY()										AActor*					TeamClassClass;						//var class<Actor> TeamClassClass;
		UPROPERTY()										float					GroundPitchTime;					//var float GroundPitchTime;
		UPROPERTY()										FVector					ViewX;								//var Vector ViewX;
		UPROPERTY()										FVector					ViewY;								//var Vector ViewY;
		UPROPERTY()										FVector					ViewZ;								//var Vector ViewZ;
		UPROPERTY()										ANavigationPoint*		StartSpot;							//var NavigationPoint StartSpot;
		UPROPERTY()										FVector					MonitorStartLoc;					//var Vector MonitorStartLoc;
		UPROPERTY()										APawn*					MonitoredPawn;						//var Pawn MonitoredPawn;
		UPROPERTY()										float					MonitorMaxDistSq;					//var float MonitorMaxDistSq;
		UPROPERTY()										TArray<AAvoidMarker*>	FearSpots;							//var AvoidMarker FearSpots[2];
		UPROPERTY()										float					SWarningDelaykill;					//var float WarningDelay;
		UPROPERTY()										AProjectile*			WarningProjectile;					//var Projectile WarningProjectile;
		UPROPERTY()										APawn*					ShotTarget;							//var Pawn ShotTarget;
		UPROPERTY()										AActor*					LastFailedReach;					//var const Actor LastFailedReach;
		UPROPERTY()										float					FailedReachTime;					//var const float FailedReachTime;
		UPROPERTY()										FVector					FailedReachLocation;				//var const Vector FailedReachLocation;
		UPROPERTY()										float					Adrenaline;							//var float Adrenaline;
		UPROPERTY()										float					AdrenalineMax;						//var float AdrenalineMax;
		UPROPERTY()										AWeapon*				LastPawnWeapon;						//var class<Weapon> LastPawnWeapon;
		UPROPERTY()										int32					ScanOffset_Yaw;						//var int32 ScanOffset_Yaw;
		UPROPERTY()										int32					ScanOffset_Pitch;					//var int32 ScanOffset_Pitch;
		UPROPERTY()										AActor*					actLastWeaponCollisionActor;		//var Actor actLastWeaponCollisionActor;
		UPROPERTY()										float					fpTimeOfLastWeaponCollisionTest;	//var float fpTimeOfLastWeaponCollisionTest;

		//Already In UE4 Controller
		//UPROPERTY()										APawn* Pawn;								//var Pawn Pawn;

		/*
		replication
		{
			reliable if ((bNetDirty && (Role == ROLE_Authority)))
				Pawn, PlayerReplicationInfo;
			reliable if (((bNetDirty && (Role == ROLE_Authority)) && bNetOwner))
				bAdrenalineEnabled, PawnClass, Adrenaline;
			reliable if ((RemoteRole == ROLE_AutonomousProxy))
				ClientSetWeapon, ClientSwitchToBestWeapon, ClientRoundEnded, ClientGameEnded, ClientDying, ClientSetRotation, ClientSetLocation;
			reliable if ((((!bDemoRecording) || (bClientDemoRecording && bClientDemoNetFunc)) && (Role == ROLE_Authority)))
				ClientVoiceMessage;
			reliable if ((Role < ROLE_Authority))
				SetPawnClass, SendVoiceMessage;
			reliable if ((Role < ROLE_Authority))
				ServerReStartPlayer;
		}
		*/

		void LIPSincAnimEnd();
		void DestinationOccupied();
		void ClientSetPMessage(int32 messID);
		void NotifyComplete();
		void CleanUp();
		bool ShouldRenderWeapon();
		bool HandlePickupQuery(APickup* pick);
		void UpdateRotation(float DeltaTime, float maxPitch);
		void MoveTo(FVector NewDestination, AActor* ViewFocus, bool bShouldWalk);
		void MoveToward(AActor* NewTarget, AActor* ViewFocus, float DestinationOffset, bool bUseStrafing, bool bShouldWalk);
		void FinishRotation();
		bool CanSee(APawn* Other);
		AActor* FindPathTo(FVector aPoint);
		AActor* FindPathToward(AActor* anActor, bool bWeightDetours);
		AActor* FindPathToIntercept(APawn* p, AActor* RouteGoal, bool bWeightDetours);
		AActor* FindPathTowardNearest(ANavigationPoint* GoalClass, bool bWeightDetours);
		ANavigationPoint* FindRandomDest();
		FVector EAdjustJump(float BaseZ, float XYSpeed);
		bool pointReachable(FVector aPoint);
		bool actorReachable(AActor* anActor);
		bool PickWallAdjust(FVector HitNormal);
		void WaitForLanding();
		AActor* FindBestInventoryPath(float& MinWeight);
		AActor* FindBestSuperPickup(float MaxDist);
		void AddController();
		void RemoveController();
		APawn* PickTarget(float& bestAim, float& bestDist, FVector FireDir, FVector projStart, float MaxRange);
		AActor* PickAnyTarget(float& bestAim, float& bestDist, FVector FireDir, FVector projStart);
		bool InLatentExecution(int32 LatentActionNumber);
		void StopWaiting();
		void EndClimbLadder();
		bool CanMakePathTo(AActor* A);
		bool PbCanPlayerJoin();
		void WeaponCollision(AActor* actorColliding);
		void MayFall();
		void MayDodgeToMoveTarget();
		void MissedDodge();
		void PendingStasis();
		void AwardAdrenaline(float Amount);
		bool NeedsAdrenaline();

		FRotator GetViewRotation();
		void Reset();
		bool AvoidCertainDeath();
		void ClientSetLocation(FVector NewLocation, FRotator NewRotation);
		void ClientSetRotation(FRotator NewRotation);
		void ClientDying(UaDamageType* DamageType, FVector HitLocation, FVector HitDir, FBoneInfo Bone);
		void AIHearSound(AActor* Actor, int32 Id, USoundBase* S, FVector SoundLocation, FVector Parameters, bool Attenuate);
		void SoakStop(FString problem);

		void WasKilledBy(AController* Other);
		AWeapon* GetLastWeapon();
		void PawnDied(APawn* p);
		void Restart();
		void LongFall();
		bool NotifyPhysicsVolumeChange(APhysicsVolume* NewVolume);
		bool NotifyHeadVolumeChange(APhysicsVolume* NewVolume);
		bool NotifyLanded(FVector HitNormal);
		void NotifyPostLanded();
		bool NotifyHitWall(FVector HitNormal, AActor* Wall);
		void NotifyFallingHitWall(FVector HitNormal, AActor* Wall);
		bool NotifyBump(AActor* Other);
		void NotifyHitMover(FVector HitNormal, AMover* Wall);
		void NotifyJumpApex();
		void NotifyMissedJump();
		void SetDoubleJump();
		void NotifyAddInventory(AInventory* NewItem);
		void NotifyTakeHit(APawn* instigatedBy, FVector HitLocation, int32 Damage, UaDamageType* DamageType, FVector Momentum);
		void SetFall();
		void PawnIsInPain(APhysicsVolume* PainVolume);
		void PreBeginPlay();
		void PostBeginPlay();
		void InitPlayerReplicationInfo();
		int32 GetTeamNum();
		bool SameTeamAs(AController* C);
		void HandlePickup(APickup* pick);
		void Destroyed();
		bool AllowDetourTo(ANavigationPoint* N);
		void AdjustView(float DeltaTime);
		bool WantsSmoothedView();
		
		void ClientGameEnded();
		void RoundHasEnded();
		void ClientRoundEnded();
		void RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly);
		int32 GetFacingDirection();
		uint8 GetMessageIndex(FName PhraseName);
		void SendMessage(AAA2_PlayerState* Recipient, FName messagetype, uint8 MessageID, float Wait, FName BroadcastType);
		bool AllowVoiceMessage(FName messagetype);
		void SendVoiceMessage(AAA2_PlayerState* Sender, AAA2_PlayerState* Recipient, FName messagetype, uint8 MessageID, FName BroadcastType);
		void ClientVoiceMessage(AAA2_PlayerState* Sender, AAA2_PlayerState* Recipient, FName messagetype, uint8 MessageID);
		void BotVoiceMessage(FName messagetype, uint8 MessageID, AController* Sender);
		bool WouldReactToNoise(float Loudness, AActor* NoiseMaker);
		bool WouldReactToSeeing(APawn* Seen);
		FVector AdjustToss(float TSpeed, FVector Start, FVector End, bool bNormalize);
		void PrepareForMove(ANavigationPoint* Goal, UReachSpec* Path);
		void WaitForMover(AMover* M);
		void MoverFinished();
		void UnderLift(AMover* M);
		void StopMoving();
		void FearThisSpot(AAvoidMarker* aSpot);
		float Desireability(APickup* p);
		float SuperDesireability(APickup* p);
		void SetupSpecialPathAbilities();
		void HearNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation);
		void HearBulletImpactNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation);
		void SeePlayer(APawn* Seen);
		void SeeMonster(APawn* Seen);
		void EnemyNotVisible();
		void DamageShake(int32 Damage);
		void ShakeView(FVector shRotMag, FVector shRotRate, float shRotTime, FVector shOffsetMag, FVector shOffsetRate, float shOffsetTime);
		void NotifyKilled(AController* Killer, AController* Killed, APawn* Other);
		void damageAttitudeTo(APawn* Other, float Damage);
		float AdjustDesireFor(APickup* p);
		bool FireWeaponAt(AActor* A);
		void StopFiring();
		float RateWeapon(AWeapon* W);
		float WeaponPreference(AWeapon* W);
		FRotator AdjustAim(AAmmunition* FiredAmmunition, FVector projStart, int32 aimerror);
		void InstantWarnTarget(AActor* Target, FFireProperties FiredAmmunition, FVector FireDir);
		void ReceiveWarning(APawn* shooter, float projSpeed, FVector FireDir);
		void WarnAboutToRunOverTeammate(AController* ctrlTeammate);
		void ReceiveProjectileWarning(AProjectile* Proj);
		void DelayedWarning();
		void SwitchToBestWeapon();
		void ClientSwitchToBestWeapon();
		void ClientSetWeapon(AWeapon* WeaponClass);
		void SetPawnClass(FString inClass, FString inCharacter);
		void SetPawnFemale();
		bool CheckFutureSight(float DeltaTime);
		void ChangedWeapon();
		void ServerReStartPlayer();
		void ServerGivePawn();
		void MonitoredPawnAlert();
		void StartMonitoring(APawn* p, float MaxDist);
		bool AutoTaunt();
		bool DontReuseTaunt(int32 t);
		FString ParseChatPercVar(FString Cmd);
		int32 getReportNPCDistance();

		//void Possess(APawn* aPawn);
		//void UnPossess();
		//bool LineOfSightTo(AActor* Other);
		//void DisplayDebug(UCanvas* Canvas, float& YL, float& YPos);
		//FString GetHumanReadableName();
		//void GameHasEnded();
};
