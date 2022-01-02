// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "AA29/AA2_PlayerState.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/SoldierClass.h"
#include "AGP_Pawn.generated.h"

#define printvector(variable)               if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green, FString::Printf(TEXT(#variable ": %s"), *variable.ToCompactString()), false)

class UTeam_Interface;
class ADebugIcon_Interrupt;
class ADebugIcon_Action;
class ADebugIcon_MentalState;
class ADebugSphere;
class ASoldierClass;
class ASoldierRole;
class AAGP_Weapon;
class AThrowWeapon;
class ABaseOptics;
class APowerups;
class AInvContainer;
class ASideEffect;
class ATeam_Interface;
class AProjectile;
class AItemAttachment;
class AVolume;
class AEventlab;
class UScriptObject;
class AAuxCollisionCylinder;
class AAI_Stats;
class AAnimationController;
class AMentalModel;
class ALadderVolume;
class AInfoSource;
class AInventoryAttachment;
class AWeapon;
class AAGP_ObjectiveInventory;

UCLASS()
class AA29_API AAGP_Pawn : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAGP_Pawn();


	UPawnMovementComponent* OurMovementComponent;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))		class UCameraComponent* FirstPersonCameraComponent;
	/** Gun muzzle's offset from the camera location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)			FVector MuzzleOffset;
	UPROPERTY(EditDefaultsOnly, Category = Projectile)							TSubclassOf<class AProjectile> ProjectileClass;


// Relationships		//cmb
	UPROPERTY()																ASoldierRole* TeamRole;								//var SoldierRole TeamRole;						// Squad Leader, Fireteam Leader, or Fireteam Member
	UPROPERTY()																AAGP_Pawn* Leader;									//var AGP_Pawn Leader;							// My leader
	UPROPERTY()																TArray<AAGP_Pawn*> Subordinate;						//var AGP_Pawn Subordinate[8];					// My subordinates
	UPROPERTY()																UTeam_Interface* Team;								//var Team_Interface Team;						// My team
	UPROPERTY()																int32 nSubordinates;								//var int nSubordinates;						// How many subordinates

//AI Stuff dnback
	UPROPERTY()																AAI_Stats* Stats;									//var AI_Stats Stats;
	UPROPERTY()																AInfoSource* perception;							//var InfoSource perception;
	UPROPERTY()																AMentalModel* _mentalModel;							//var MentalModel _mentalModel;
	UPROPERTY()																ABaseOptics* _OpticsDevice;							//var BaseOptics _OpticsDevice;

// Volume monitor values: martin
	UPROPERTY()																AVolume* _CurrentVolume;							//var Volume _CurrentVolume;					// the current volume this pawn is in
	UPROPERTY()																AActor* _CurrentTrigger;							//var Actor _CurrentTrigger;					// the current AGP_Trigger the pawn is in
	UPROPERTY()																UScriptObject* _VolumeMonitor;						//var ScriptObject _VolumeMonitor;				// the script object currently monitoring any volume changes
	UPROPERTY()																UScriptObject* _TriggerMonitor;						//var ScriptObject _TriggerMonitor;				// the script object currently monitoring any AGP_Trigger changes
	UPROPERTY()																UScriptObject* _FriendlyFireMonitor;				//var ScriptObject _FriendlyFireMonitor;		// the script object currently monitoring any friendly fire attacks
	UPROPERTY()																UScriptObject* _FireMonitor;						//var ScriptObject _FireMonitor;				// the script object currently monitoring any the pawn firing a weapon
	UPROPERTY()																UScriptObject* _DeathMonitor;						//var ScriptObject _DeathMonitor;				// the script object currently monitoring if the pawn dies
	UPROPERTY()																UScriptObject* _TriggerMonitor2;					//var ScriptObject _TriggerMonitor2;			// the script object currently monitoring any AGP_Trigger changes
	UPROPERTY()																UScriptObject* _TriggerMonitor3;					//var ScriptObject _TriggerMonitor3;			// the script object currently monitoring any AGP_Trigger changes
	UPROPERTY()																UScriptObject* _TriggerMonitor4;					//var ScriptObject _TriggerMonitor4;			// the script object currently monitoring any AGP_Trigger changes
	UPROPERTY()																AAnimationController* _AnimationMonitor;			//var AnimationController _AnimationMonitor;	// Animation controller pointer for NPC pawns
	UPROPERTY()																bool FirstTime;										//var bool FirstTime;
	UPROPERTY()																bool tween;											//var bool tween;

// Sound effects
	UPROPERTY()																TArray<USoundBase*> sBulletWhip;					//var array<Sound> sBulletWhip;					// sounds to play when a bullet passes nearby
	UPROPERTY()																TArray<USoundBase*> sBulletCrack;					//var array<Sound> sBulletCrack;				// sounds to play when a bullet passes very nearby
	UPROPERTY()																TArray<USoundBase*> sMilesGraze;					//var array<Sound> sMilesGraze;					// sounds to play when a miles trace nearly hits
	UPROPERTY()																TArray<USoundBase*> sParaLanding;					//var array<Sound> sParaLanding;				// sounds to play when a paratrooper lands
	UPROPERTY()																USoundBase* sCrouchToProne;							//var Sound sCrouchToProne;						// body repositioning sounds
	UPROPERTY()																USoundBase* sCrouchToStand;							//var Sound sCrouchToStand;						// body repositioning sounds
	UPROPERTY()																USoundBase* sProneToCrouch;							//var Sound sProneToCrouch;						// body repositioning sounds
	UPROPERTY()																USoundBase* sProneToStand;							//var Sound sProneToStand;						// body repositioning sounds
	UPROPERTY()																USoundBase* sStandToCrouch;							//var Sound sStandToCrouch;						// body repositioning sounds
	UPROPERTY()																USoundBase* sStandToProne;							//var Sound sStandToProne;						// body repositioning sounds
	UPROPERTY()																AThrowWeapon* DesiredGrenade;						//var class<ThrowWeapon> DesiredGrenade;		//agp [cmb] If this is not NONE, FinishSwapHands() know I want a grenade [6/15/2002]
	UPROPERTY()																AAGP_Weapon* DesiredBinoculars;						//var class<AGP_Weapon> DesiredBinoculars;
	UPROPERTY()																AInventory* NextSwap;								//var Inventory NextSwap;
	UPROPERTY()																bool bSimDeadFalling;								//var bool bSimDeadFalling;
	UPROPERTY()																bool bParachuteOutfit;								//var bool bParachuteOutfit;
	UPROPERTY()																bool bClearSplitAnims;								//var bool bClearSplitAnims;
	UPROPERTY()																bool bForceDrawCrosshair;							//var bool bForceDrawCrosshair;					//jabney - allows script to turn on crosshair in single player

//debug
	UPROPERTY()																int32 Test;											//var int Test;
	UPROPERTY()																APlayerController* HController;						//var HumanController HController;
	UPROPERTY()																AAGP_Pawn* Player;									//var AGP_Pawn Player;
	UPROPERTY()																float fHopTimer;									//var float fHopTimer;							//Increments only when not in the air. Decrements by 2.0 every time you jump. Can't jump if below zero.
	
//agp [cmb] Bleeding and healing variables [3/24/2003]
	UPROPERTY()																int32 iLastPercent;									//var int iLastPercent;							//keeps track of last percent to reduce broadcasts
	UPROPERTY()																float fHealPercent;									//var float fHealPercent;						//How close I am to being healed
	UPROPERTY()																float fBleedTimer;									//var float fBleedTimer;						//Used to do bleed damage
	UPROPERTY()																float fHealDivisor;									//var float fHealDivisor;						//Determines how long healing takes (bigger=slower)
	UPROPERTY()																bool bHealingInProgress;							//var bool bHealingInProgress;					//Someone is currently trying to heal me
	UPROPERTY()																bool bHealingInterrupted;							//var bool bHealingInterrupted;					//Healing has temporarily been interrupted
	UPROPERTY()																AAGP_Pawn* Healer;									//var AGP_Pawn Healer;							//This is who is trying to heal me

//agp [rmn] Fireman's Carry Variables
	UPROPERTY()																float fpBleedRate;									//var float fpBleedRate;						
	UPROPERTY()																bool bCanBeCarried;									//var bool bCanBeCarried;						//I can be carried
	UPROPERTY()																bool bSoldierPickupInProgress;						//var bool bSoldierPickupInProgress;			//Someone is currently trying to pick me up
	UPROPERTY()																AAGP_Pawn* Carrier;									//var AGP_Pawn Carrier;							//This is who is trying to carry me
	UPROPERTY()																AAGP_Pawn* Carried;									//var AGP_Pawn Carried;							//This is who is I am carrying

//agp [cmb] Objective give variables [9/16/2004]
	UPROPERTY()																int32 iLastObjectiveGivePercent;					//var int iLastObjectiveGivePercent;			//Keep track of last percent to reduce broadcasts
	UPROPERTY()																float fObjectiveGivePercentage;						//var float fObjectiveGivePercentage;			//How close I am to getting the objective
	UPROPERTY()																AAGP_Pawn* ObjectiveGiver;							//var AGP_Pawn ObjectiveGiver;					//The Pawn who is trying to give me an objective
	UPROPERTY()																bool bPlayedDeathEnd;								//var bool bPlayedDeathEnd;
	UPROPERTY()																EDeathAnim OldDeathAnim;							//var Pawn.EDeathAnim OldDeathAnim;

//agp [cmb] Do a SwapHands() as soon as you land [2/9/2003]
	UPROPERTY()																bool bSwapWhenLanded;								//var bool bSwapWhenLanded;

//agp [cmb] Used by Physics code [10/7/2002]
	UPROPERTY()																FVector LastPhysicsLocation;						//var const FVector LastPhysicsLocation;		//
	UPROPERTY()																float LastSimHitNormalZ;							//var const float LastSimHitNormalZ;				//The last Hit.Normal.Z used by AAGP_Pawn::TickSimulated()
	UPROPERTY()																FVector LastSimLocation;							//var const FVector LastSimLocation;			//The last location used by AAGP_Pawn::TickSimulated() that was on a non-steep slope
	UPROPERTY()																float LastSimExtentZ;								//var const float LastSimExtentZ;					//The last collision height used by AAGP_Pawn::TickSimulated()
	UPROPERTY()																float LastSimLocationZ;								//var const float LastSimLocationZ;					//The last location Z value used by AAGP_Pawn::TickSimulated()
	UPROPERTY()																uint8 LastSimPhysics;								//var const byte LastSimPhysics;					//The last physics state used by AAGP_Pawn::TickSimulated()
	UPROPERTY()																float LastProneAdjust;								//var const float LastProneAdjust;					//The last adjust value set by AAGP_Pawn::MaybeAdjustForProne()
	UPROPERTY()																FRotator LastProneFloorRot;							//var const Object.Rotator LastProneFloorRot;		//The last floor rotation set by AAGP_Pawn::MaybeAdjustForProne()
	UPROPERTY()																uint8 VerifyCylinderCount;							//var const byte VerifyCylinderCount;				//HACK: Used by SetRotation() to make sure the Cylinders don't get out of line
	UPROPERTY()																FObjectRange FloorDistance;							//var const Object.Range FloorDistance;
	UPROPERTY()																float TimeSinceBusyParachutingStarted;				//var float TimeSinceBusyParachutingStarted;		// HACK: This tracks how long since we've entered the BusyParachuting state. See that code for more
	UPROPERTY()																int32 OutOfBounds;									//var int OutOfBounds;
	UPROPERTY()																float TimeOutOfBounds;								//var float TimeOutOfBounds;
	UPROPERTY()																float CurrentZoneTimeToKill;						//var float CurrentZoneTimeToKill;
	UPROPERTY()																bool bOOBIsTrainingVolume;							//var bool bOOBIsTrainingVolume;

// EyeTracking
	UPROPERTY()																float flastYaw;										//var float flastYaw;
	UPROPERTY()																float fStealthBlendTime;							//var float fStealthBlendTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bNewAccuracy;									//var() bool bNewAccuracy;							// Use the new accuracy system. Remove this if we decide to keep the new system.
	UPROPERTY()																bool bActiveBreacherTarget;							//var bool bActiveBreacherTarget;					// This pawn has an active target for a breaching weapon
	UPROPERTY()																bool bActiveDemolitionTarget;						//var bool bActiveDemolitionTarget;					// This pawn has an active target for a demolition weapon
	UPROPERTY()																bool bActiveJavelinTarget;							//var bool bActiveJavelinTarget;
	UPROPERTY()																bool bActiveObjPickupTarget;						//var bool bActiveObjPickupTarget;
	UPROPERTY()																bool bInactiveObjPickupTarget;						//var bool bInactiveObjPickupTarget;
	UPROPERTY()																bool bActiveObjectiveTarget;						//var bool bActiveObjectiveTarget;
	UPROPERTY()																uint8 TargetObjLetter;								//var byte TargetObjLetter;
	UPROPERTY()																bool bActiveCoopESSTarget;							//var bool bActiveCoopESSTarget;
	UPROPERTY()																FString stTargetDescription;						//var string stTargetDescription;
	UPROPERTY()																float fSpeedPenalty;								//var float fSpeedPenalty;
	UPROPERTY()																float CE_PanicValue;								//var float CE_PanicValue;
	UPROPERTY()																float CE_ActivityValue;								//var float CE_ActivityValue;
	UPROPERTY()																bool fInitialAnimationComplete;						//var bool fInitialAnimationComplete;
	UPROPERTY()																float fTimeSinceLastReload;							//var float fTimeSinceLastReload;
	UPROPERTY()																int32 iCEMUpdateCounter;							//var int iCEMUpdateCounter;
	UPROPERTY()																float fpTimeSinceLastCEMUpdate;						//var float fpTimeSinceLastCEMUpdate;
	UPROPERTY()																ADebugSphere* VisionDistActor;						//var DebugSphere VisionDistActor;
	UPROPERTY()																ADebugSphere* AudioDistActor;						//var DebugSphere AudioDistActor;
	UPROPERTY()																ADebugIcon_MentalState* MyDebug_MentalStateIcon;	//var DebugIcon_MentalState MyDebug_MentalStateIcon;
	UPROPERTY()																ADebugIcon_Action* MyDebug_ActionIcon;				//var DebugIcon_Action MyDebug_ActionIcon;
	UPROPERTY()																ADebugIcon_Interrupt* MyDebug_InterruptIcon;		//var DebugIcon_Interrupt MyDebug_InterruptIcon;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)								FName AnimSequence;									//var() name AnimSequence;						// Animation sequence name
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float AnimRate;										//var() float AnimRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float AnimTime;										//var() float AnimTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 AnimChannel;									//var() int AnimChannel;
	UPROPERTY()																FName nmNPCIdleAnim;								//var name nmNPCIdleAnim;
	UPROPERTY()																bool bCanSwapWeapons;								//var bool bCanSwapWeapons;
	UPROPERTY()																bool bAllowSwap;									//var bool bAllowSwap;
	UPROPERTY()																bool bHasCLU;										//var bool bHasCLU;
	UPROPERTY()																float HitQuadrants;									//var float HitQuadrants;
	UPROPERTY()																float FixedHitQuadrants;							//var float FixedHitQuadrants;
	UPROPERTY()																float VehicleExitMPH;								//var float VehicleExitMPH;
	UPROPERTY()																bool bHitByIED;										//var bool bHitByIED;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bDummyPawn;									//var() bool bDummyPawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 rank;											//var() int rank;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								ERank idRank;										//var() ERank idRank;
	UPROPERTY()																bool angleEditor;									//var bool angleEditor;
	UPROPERTY()																int32 boneaxisdirection;							//var int boneaxisdirection;
	UPROPERTY()																int32 boneaxis;										//var int boneaxis;
// Angle Editor Variables
//
	UPROPERTY()																float s1boneangle1R;								//var float s1boneangle1R;
	UPROPERTY()																float s1boneangle1P;								//var float s1boneangle1P;
	UPROPERTY()																float s1boneangle1Y;								//var float s1boneangle1Y;
	UPROPERTY()																float s1boneangle2R;								//var float s1boneangle2R;
	UPROPERTY()																float s1boneangle2P;								//var float s1boneangle2P;
	UPROPERTY()																float s1boneangle2Y;								//var float s1boneangle2Y;
	UPROPERTY()																float s1boneangle3R;								//var float s1boneangle3R;
	UPROPERTY()																float s1boneangle3P;								//var float s1boneangle3P;
	UPROPERTY()																float s1boneangle3Y;								//var float s1boneangle3Y;
	UPROPERTY()																float s2boneangle1R;								//var float s2boneangle1R;
	UPROPERTY()																float s2boneangle1P;								//var float s2boneangle1P;
	UPROPERTY()																float s2boneangle1Y;								//var float s2boneangle1Y;
	UPROPERTY()																float s2boneangle2R;								//var float s2boneangle2R;
	UPROPERTY()																float s2boneangle2P;								//var float s2boneangle2P;
	UPROPERTY()																float s2boneangle2Y;								//var float s2boneangle2Y;
	UPROPERTY()																float s2boneangle3R;								//var float s2boneangle3R;
	UPROPERTY()																float s2boneangle3P;								//var float s2boneangle3P;
	UPROPERTY()																float s2boneangle3Y;								//var float s2boneangle3Y;
	UPROPERTY()																float s3boneangle1R;								//var float s3boneangle1R;
	UPROPERTY()																float s3boneangle1P;								//var float s3boneangle1P;
	UPROPERTY()																float s3boneangle1Y;								//var float s3boneangle1Y;
	UPROPERTY()																float s3boneangle2R;								//var float s3boneangle2R;
	UPROPERTY()																float s3boneangle2P;								//var float s3boneangle2P;
	UPROPERTY()																float s3boneangle2Y;								//var float s3boneangle2Y;
	UPROPERTY()																float s3boneangle3R;								//var float s3boneangle3R;
	UPROPERTY()																float s3boneangle3P;								//var float s3boneangle3P;
	UPROPERTY()																float s3boneangle3Y;								//var float s3boneangle3Y;



	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 UID;											//var() int UID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								ERole idRole;										//var() ERole idRole;
	UPROPERTY()																bool bUseAuxCollision;								//var bool bUseAuxCollision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								AAGP_Weapon* NPC_Weapon;							//var() class<AGP_Weapon> NPC_Weapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 idUnitNumber;									//var() int idUnitNumber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								ETeam idTeam;										//var() Pawn.ETeam idTeam;
	UPROPERTY()																bool relo;											//var bool relo;
	UPROPERTY()																bool hand;											//var bool hand;
	UPROPERTY()																bool tran;											//var bool tran;
	UPROPERTY()																bool bTwoWeapons;									//var bool bTwoWeapons;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bEyeTrack;										//var() bool bEyeTrack;
	UPROPERTY()																FVector OldEyePosition;								//var FVector OldEyePosition;
	UPROPERTY()																FVector NewEyePosition;								//var FVector NewEyePosition;
	UPROPERTY()																float InterpolatedYaw;								//var float InterpolatedYaw;
	UPROPERTY()																float InterpolatedPitch;							//var float InterpolatedPitch;
	UPROPERTY()																bool bGotBulletBuzzed;								//var bool bGotBulletBuzzed;
	UPROPERTY()																bool followmouse;									//var bool	followmouse;						//If set, the bones that bend for pitch will match the pitch angle exactly, otherwise interpolate
	UPROPERTY()																FRotator fInterpolateSpine02;						//var Object.Rotator fInterpolateSpine02;
	UPROPERTY()																FRotator fInterpolateSpine01;						//var Object.Rotator fInterpolateSpine01;
	UPROPERTY()																FRotator fInterpolateHead;							//var Object.Rotator fInterpolateHead;
	UPROPERTY()																bool bNPCMovingToPathNode;							//var bool bNPCMovingToPathNode;
	UPROPERTY()																bool bDoFreezeKarma;								//var bool bDoFreezeKarma;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Karma")			float RagProneProjectileScale;						//var(Karma) float RagProneProjectileScale;		// Amount to scale down the damage effects when shot while prone.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Karma")			float RagDeathUpKick;								//var(Karma) float RagDeathUpKick;				// Amount of upwards kick ragdolls get when they die
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Karma")			float RagSpinScale;									//var(Karma) float RagSpinScale;				// Increase propensity to spin around Z (up).
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Karma")			float RagShootStrength;								//var(Karma) float RagShootStrength;			// How much effect shooting ragdolls has. Be careful!
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Karma")			float RagDeathVel;									//var(Karma) float RagDeathVel;					// How fast ragdoll moves upon death
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Karma")			float RagInvInertia;								//var(Karma) float RagInvInertia;				// Use to work out how much 'spin' ragdoll gets on death.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Karma")			float RagdollLifeSpan;								//var(Karma) float RagdollLifeSpan;				// MAXIMUM time the ragdoll will be around.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Karma")			FString RagdollOverride;							//var(Karma) string RagdollOverride;			// The Karma asset to use as a ragdoll
	UPROPERTY()																float SavedFallSpeed;								//var float SavedFallSpeed;						// agp(jmr) Used to save the fall speed after every fall.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bIsScriptedWalking;							//var() bool bIsScriptedWalking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bIsScripted;									//var() bool bIsScripted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bIsStartsWithWeapon;							//var() bool bIsStartsWithWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bIsPatrolling;									//var() bool bIsPatrolling;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bIsSniper;										//var() bool bIsSniper;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")	int32 KillHealth;									//var(LinkDamage) int KillHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")	FName KillEvent;									//var(LinkDamage) name KillEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")	FName DamageTag;									//var(LinkDamage) name DamageTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LinkDamage")	FName DamageEvent;									//var(LinkDamage) name DamageEvent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 iNPC_GroupID;									//var() int iNPC_GroupID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 iNPC_SmokeGrenade;							//var() int iNPC_SmokeGrenade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 iNPC_StunGrenade;								//var() int iNPC_StunGrenade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 iNPC_FragGrenade;								//var() int iNPC_FragGrenade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bIsBoss;										//var() bool bIsBoss;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bHoldPossition;								//var() bool bHoldPossition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bActorRespawn;									//var() bool bActorRespawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bNPC_Flambe;									//var() bool bNPC_Flambe;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bNPC_Gibletts;									//var() bool bNPC_Gibletts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bNPC_Flies;									//var() bool bNPC_Flies;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bNPC_BloodPool;								//var() bool bNPC_BloodPool;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 iNPC_Grenades;								//var() int iNPC_Grenades;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 iNPC_Clip;									//var() int iNPC_Clip;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float NPC_ShootAccuracy;							//var() float NPC_ShootAccuracy;		// this is a percentage from 1..100%
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float NPC_LikesToThrowGrenade;						//var() float NPC_LikesToThrowGrenade;	// this is a percentage from 1..100%
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float NPC_LikesToAmbient;							//var() float NPC_LikesToAmbient;		// this is a percentage from 1..100%
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float NPC_LikesToTalk;								//var() float NPC_LikesToTalk;			// this is a percentage from 1..100%
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float NPC_LikesToAssault;							//var() float NPC_LikesToAssault;		// this is a percentage from 1..100%
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float NPC_LikesToAmbush;							//var() float NPC_LikesToAmbush;		// this is a percentage from 1..100%
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float NPC_LikesToStand;								//var() float NPC_LikesToStand;			// this is a percentage from 1..100%
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float NPC_LikesToCrouch;							//var() float NPC_LikesToCrouch;		// this is a percentage from 1..100%
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float NPC_LikesToProne;								//var() float NPC_LikesToProne;			// this is a percentage from 1..100%
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float fNPC_Experience;								//var() float fNPC_Experience;			// this is a percentage 0..100
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float fNPC_Agressiveness;							//var() float fNPC_Agressiveness;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float fNPC_BreakingPoint;							//var() float fNPC_BreakingPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float fNPC_Speed;									//var() float fNPC_Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float fNPC_WalkSpeed;								//var() float fNPC_WalkSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float fNPC_RunSpeed;								//var() float fNPC_RunSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 iNPC_ThinkType;								//var() int iNPC_ThinkType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								int32 fNPC_Moral;									//var() int fNPC_Moral;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float fGrenadeAwareTime;							//var() float fGrenadeAwareTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float fGrenadeAwareDistance;						//var() float fGrenadeAwareDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float fHearingDistance;								//var() float fHearingDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								float fVisionDistance;								//var() float fVisionDistance;
	UPROPERTY()																float fpPlayerThreatLevel;							//var float fpPlayerThreatLevel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC_type")		EATypes Actor_t;									//var(NPC_type) Actor.EATypes Actor_t;

	//From Pawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					USoundBase* BreathOutSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					USoundBase* BreathInSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bCanCrouch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bCanClimbLadders = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bCanStrafe = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bCanWalkOffLedges = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bCanPickupInventory = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float GroundSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float WaterSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float AirSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float AccelRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float JumpZ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float AirControl;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float MaxFallSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bCanProne = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bCanSprint = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					uint8 LeanDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float LeanSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FVector LeanOffsetRight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FVector LeanOffsetLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					int32 LeanRollView;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float fWalkSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float fWalkRearPct;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float fRunSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float fRunSidePct;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float fCrouchSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float fFastCrouchSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float fHCrawlSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float fLCrawlSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float fRollTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float CE_RecoveryPenalty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float CE_MeterValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float fMaxGrabHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float fGrabBufferDist;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float fMantleSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float fFallDamageSpd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FVector PrePivot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					int32 SoundRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bBulletPenetration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName TurnRightAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName TurnLeftAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					TArray<FName> MovementAnims;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName IdleChatAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName IdleRestAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName IdleWeaponAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName IdleSwimAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName IdleCrouchAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName CrouchTurnLeftAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName CrouchTurnRightAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName TakeoffStillAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName AirStillAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName DodgeAnims;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName DoubleJumpAnims;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName LandAnims;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName TakeoffAnims;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName AirAnims;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName WalkAnims;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName CrouchAnims;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FName SwimAnims;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					TArray<float> MovementAnimRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FRotator AnimCamRelativeRotation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FVector AnimCamRelativeLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FRotator RotationRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					USkeletalMesh* CustomMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float WalkingPct;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float DrawScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FString MenuName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bPhysicsAnimUpdate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bCleanUp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bDontPossess;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bDisableShadow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					FString HUDText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bCollideActors;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool NPC_DamageOn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float CollisionRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					float CollisionHeight;						//Manually added
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bCollideWorld;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bNPCDisableSkinSwapping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					EUpperBodyAnim UpperBodyAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					bool bAbortMoveIfGoalOccupied;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)					TArray<AInventoryAttachment*> AttachmentList;			//var array<InventoryAttachment> AttachmentList; //agp [cmb] For notifying attachments when the client has been found [6/5/2002]
	UPROPERTY()													EDeathAnim DeathAnim;						//var EDeathAnim DeathAnim;
	UPROPERTY()													bool bNetAlreadyDead;						//var bool bNetAlreadyDead;
	UPROPERTY()													ECommoType CommoState;						//var ECommoType CommoState;
	UPROPERTY()													uint8 _InvSelfHealMedPacks;					//var byte _InvSelfHealMedPacks;
	UPROPERTY()													uint8 _InvMedPacks;							//var byte _InvMedPacks;

//From Pawn
	UPROPERTY()													AWeapon* PendingWeapon;						//var Weapon PendingWeapon;
	UPROPERTY()													AAuxCollisionCylinder* BoneAuxCyl;			//var AuxCollisionCylinder BoneAuxCyl;
	UPROPERTY()													AAuxCollisionCylinder* BackAuxCyl;			//var AuxCollisionCylinder BackAuxCyl;
	UPROPERTY()													AAuxCollisionCylinder* FrontAuxCyl;			//var AuxCollisionCylinder FrontAuxCyl;

	UPROPERTY(Replicated)										bool bIsProne;								//var bool bIsProne;
	UPROPERTY(Replicated)										bool bIsSprinting;							//var bool bIsSprinting;
	UPROPERTY(Replicated)										bool bIsWalking;							//var bool bIsWalking;
	UPROPERTY(Replicated)										bool bIsCrouching;							//var bool bIsWalking;
	UPROPERTY(Replicated)										bool bIsCrouched2;							//var bool bIsWalking;

	UPROPERTY()													bool bWantsToProne;							//var bool bWantsToProne;
	UPROPERTY()													bool bWantsToCrouch;						//var bool bWantsToCrouch;

	UPROPERTY()													bool bInProneTransition;					//var bool bInProneTransition;
	UPROPERTY()													bool bWasProne;								//var bool bWasProne;
	UPROPERTY()													bool bLimitRotation;
	UPROPERTY()													float ProneRadius;							//var float ProneRadius;
	UPROPERTY()													float ProneHeight;							//var float ProneHeight;
	UPROPERTY()													float UnproneTime;							//var const float UnproneTime;
	UPROPERTY()													bool bLockMovement;							//var bool bLockMovement;
	UPROPERTY()													bool bIsDead;								//var bool bIsDead;							// Pawn is dead
	UPROPERTY()													bool bTransitionAnim;						//var bool bTransitionAnim;
	UPROPERTY()													bool bPawnZoomed;							//var bool bPawnZoomed;
	UPROPERTY()													APowerups* SelectedItem;					//var travel Powerups	SelectedItem;		// currently selected inventory item
	UPROPERTY()													EUpperBodyAnim LastUpperBodyAnim;
	UPROPERTY()													EFullBodyAnim FullBodyAnim;
	UPROPERTY()													bool bSteadyFiring;
	UPROPERTY()													float HealthMax;							//var float           HealthMax;
	UPROPERTY()													float SuperHealthMax;						//var float           SuperHealthMax;
	UPROPERTY()													bool bUsingObjective;						//var bool bUsingObjective;
	UPROPERTY()													float fStrength;							//var float fStrength;
	UPROPERTY()													float fSpeed;								//var float fSpeed;
	UPROPERTY()													float fMorale;								//var float fMorale;
	UPROPERTY()													float fCourage;								//var float fCourage;
	UPROPERTY()													float fLoyalty;								//var float fLoyalty;
	UPROPERTY()													float fObedience;							//var float fObedience;
	UPROPERTY()													float fLeadership;							//var float fLeadership;
	UPROPERTY()													float fIntelligence;						//var float fIntelligence;
	UPROPERTY()													float fEndurance;							//var float fEndurance;
	UPROPERTY()													float fAgility;								//var float fAgility;

	UPROPERTY()													TArray<uint8> _InvBinoculars;						//var byte _InvBinoculars;
	UPROPERTY()													TArray<uint8> _InvGrenades;							//var byte _InvGrenades;

	UPROPERTY()													AAA2_PlayerState* PlayerReplicationInfo;	//var PlayerReplicationInfo PlayerReplicationInfo;
	UPROPERTY()													int32 VirtualHealth;						//var int VirtualHealth;
	UPROPERTY()													int32 BleedHealth;							//var int	BleedHealth;
	UPROPERTY()													int32 BleedMax;								//var int BleedMax;
	UPROPERTY()													float fInvWeight;							//var InvContainer _InvTop;				// total weight of carried items in inventory
	UPROPERTY()													FRotator rBaseRotation;						//var Object.Rotator rBaseRotation;
	UPROPERTY()													FRotator rRotationLimits;					//var Object.Rotator rRotationLimits;

	UPROPERTY()													bool bWantsToRollLeft;					//var bool bWantsToRollLeft;
	UPROPERTY()													bool bWantsToRollRight;					//var bool bWantsToRollRight;

	// Inventory Variables [superville and Mike oh my god]
	UPROPERTY()													AInvContainer* _InvTop;						//var InvContainer _InvTop;				// The top of a linked list of all InvContainers spawned by SpawnContainer()
	UPROPERTY()													AInvContainer* _InvHands;					//var InvContainer _InvHands;			// Hands can carry 0-1 items
	UPROPERTY()													AInvContainer* _InvShoulder;				//var InvContainer _InvShoulder;		// Shoulder strap can carry a weapon
	UPROPERTY()													AInvContainer* _InvHolster;					//var InvContainer _InvHolster;			// For pistols
	UPROPERTY()													AInvContainer* _InvUtility;					//var InvContainer _InvUtility;			// For items that don't interact with the other containers.	//agp [cmb] NOTE: I'm not replicating this yet, until I need to [9/2/2004]
	UPROPERTY()													AInvContainer* _InvHip;						//var InvContainer _InvHip;				// agp:aafa [mwd] added container for javelin (02/24/05)
	UPROPERTY()													AInvContainer* _InvAltShoulder;				//var InvContainer _InvAltShoulder;		// agp:aafa [mwd] added container for javelin (02/24/05)
	UPROPERTY()													bool bGuerrillaMesh;
	UPROPERTY()													TArray<AItemAttachment*> IA;				//var array<ItemAttachment> IA;
	UPROPERTY()													bool bWasSprinting;							//var bool bWasSprinting;
	UPROPERTY()													bool bWantsToSprint;						//var bool bWantsToSprint;


	//From Controller
	UPROPERTY()													AActor* TeamClassClass;						//var class<Actor> TeamClassClass;
	UPROPERTY()													AActor* TeamRoleClass;						//var class<Actor> TeamRoleClass;
	UPROPERTY()													APawn* PreviousPawnClass;					//var class<Pawn> PreviousPawnClass;
	UPROPERTY()													APawn* PawnClass;							//var class<Pawn> PawnClass;

	//From Actor
	UPROPERTY()													TArray<UMaterialInstance*> Skins;
	UPROPERTY()													TSubclassOf<AInventory>	Inventory;			//var Inventory             Inventory;     // Inventory chain.
	UPROPERTY()													AEventlab*	EventLab;						//var Actor EventLab;
	UPROPERTY(EditAnywhere, Category = "Movement")				FVector Velocity;							//var(Movement) FVector Velocity;

	bool bClientFriend;

	//Not replicated
	USkeletalMeshComponent* Mesh_1P;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)		TArray<UAnimBlueprintGeneratedClass*> Anim_BP;

	//replicated
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)					TSubclassOf<AWeapon> Weapon;									//var travel Weapon Weapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)					AWeapon* Weapon;									//var travel Weapon Weapon;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)					USkeletalMesh* CustomMesh_1P;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)					USkeletalMeshComponent* Mesh_3P;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)					UAnimationAsset* Anim_1P;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)					UAnimationAsset* Anim_3P;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, replicated)					int32 Health;													//var travel int      Health;         // Health: 100 = normal maximum
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)					TSubclassOf<ASoldierClass> TeamClass;							//var SoldierClass TeamClass;					// Grenadier, Rifleman, Automatic Rifleman, Sniper

	UPROPERTY(EditAnywhere, BlueprintReadWrite, replicated)					float AGP_Direction;												
	UPROPERTY(EditAnywhere, BlueprintReadWrite, replicated)					float AGP_Speed;													

	UFUNCTION()		TArray<UAnimationAsset*> GetAllAnimationOfSkeleton(USkeleton* Skeleton);


	//These is the new ones:
	AAGP_Pawn* Clone();
	virtual void AnimateGrenadeMoving();
	virtual void RemoveParachuteSkins();
	virtual void MatchStarting();
	virtual void ConfigureLinkDamage();
	virtual void ActivateLinkedObjective(APawn* User);
	virtual void SetWeaponRelativeRotation(FRotator rotNew);
	virtual void SetAnimAction(FName NewAction);
	virtual void ClientSetViewRotation(FRotator NewRotation);
	virtual void KNotifySimError();
	virtual void SetupBoneAuxCylinder();
	virtual void PreBeginPlay();
	virtual void PostBeginPlay();
	virtual void AlertAIOfPlayerNoiseTimer();
	virtual void PostBeginNetPlay();
	virtual bool AllowAnimFiring();
	AInvContainer* SpawnContainer(FString class_name);
	void AddContainer(AInvContainer* Add);
	
	virtual void SpawnTeamClass(AActor* actor_class);
	virtual void SpawnTeamRole(AActor* actor_class);
	AMentalModel* getMentalModel();
	AMentalModel* createMentalModel();
	AMentalModel* resetMentalModel();
	virtual void setMentalModel(AMentalModel* set_mm);
	bool ownsMentalModel();
	FRotator GetInterpolatedRotation();
	virtual void LockMovement(bool bLock);
	virtual void LimitRotation(bool bLimit);
	virtual void SetMovementPhysics();
	virtual void SetWalking(bool bNewIsWalking);
	virtual void UpdateGroundspeeds();
	virtual void EndClimbLadder(ALadderVolume* OldLadder);
	void ClimbLadder(ALadderVolume* L);
	bool CanGrabLadder();
	float GetSprintModifier(float DeltaYaw, float DeltaTime, bool bJumped);
	float GetSpeedModifier();
	virtual float GetSpeedModifier_Always();
	virtual void StartMantle(int32 EndPosture, FVector MantleLoc, FRotator BaseRot);
	virtual void EndMantle(int32 EndPosture);

	FRotator GetViewRotation() const;
	bool UseAnimatedEyeRotation();
	FVector EyePosition();
	FRotator EyeRotation();

	virtual void CheckBob(float DeltaTime, FVector Y);
	virtual void AngleEditorCalculate();
	virtual void PlayBoneAnim(FName BoneName);
	virtual void UpdateBoneAnim();
	bool ShouldDrawCrosshair();
	//void StopDriving(Vehicle V);
	virtual void AnimEnd(int32 Channel);
	virtual void PredictUpperBodyAnim();
	virtual void PlayRolling(EFullBodyAnim Anim);
	virtual void PlayProningSound();
	virtual void StartSprint();
	virtual void StopSprint();
	virtual void ResetLean();
	virtual void LeanLeft(bool bFullLeft);
	virtual void LeanRight(bool bFullRight);
	virtual bool CanLean();
	virtual bool CanLeanInAnimationState();
	virtual bool CanHandSignal();
	virtual bool CanCommo();
	bool CanJump();
	bool CanSprint();
	bool DoJump(bool bUpdating);
	virtual bool CanChangePosture(bool bForce, bool bForceUnzoom);
	virtual bool CanCombatRoll(bool bActual);
	virtual void ShouldStand(bool bForce);
	virtual void ShouldCrouch(bool Crouch);
	virtual void EndCrouch(float HeightAdjust);
	virtual void StartCrouch(float HeightAdjust);
	virtual void ShouldProne(bool Prone);
	virtual void EndProne(float HeightAdjust);
	virtual void HidePawn(bool bNewHidePawn);
	virtual void StartProne(float HeightAdjust);
	virtual bool IsSupported();
	virtual bool IsZoomed();
	virtual void SetZoomed(bool bNewZoomed);
	virtual void NPCSetWeaponZoom(bool bZoomWeapon);
	virtual float GetZoomMultiplier();
	bool SetSupported(bool newSupported, bool bForce);
	virtual bool SupportablePosition();
	virtual bool OverRotated(FRotator Desired, FRotator Actual);
	virtual void UpdateParachute(int32 Type);
	virtual void FlareParachute();
	virtual bool HasParachute();
	int32 CheckParachuteLandingFall();
	virtual void ParachuteLanding(bool bFailed);
	virtual void PlayPLF();
	virtual void ChangeAnimation();
	virtual void ClearSplitAnims();
	virtual void UpperBodyAnimComplete();
	virtual void FullBodyAnimComplete();
	virtual void HandSignalSet(FName h_name);
	virtual FName HandSignalGet();
	virtual void PlayHandSignalIndex();
	virtual void PlayHandSignal(FName Anim);
	ABaseWeaponAttachment* GetWeaponAttachment();
	virtual void PlayLanding();
	virtual void PlayFiring(float Rate, FName FiringMode);
	virtual void ClientPlayBulletWhip(FVector HitLocation, bool bCrack, AActor* aShooter);
	virtual bool CanUseWeapon(int32 DesiredAction);
	virtual bool CanMantle(float Height);
	virtual bool PressingAction();
	virtual void AddDefaultInventory();
	AInventory* CreateInventoryFromName(FString InventoryClassName, bool bIndigenous);
	AInventory* CreateInventory(AInventory* InventoryClass, bool bRealInventory, bool bIndigenous);
	bool IsValidInventory(AInventory* InventoryClass, AInventory* out_AltClass);
	FVector CalcDrawOffset(AInventory* Inv);
	virtual void Reload3p(EUpperBodyAnim Anim);
	virtual void GuardWeapon3p(EUpperBodyAnim Anim);
	virtual void Roll3p(EFullBodyAnim Anim);
	virtual void Dive3p(EFullBodyAnim Anim);
	virtual void Parachute3p(EFullBodyAnim Anim);
	virtual void PLF3p(EFullBodyAnim Anim);
	virtual void GrenadeThrow3p(EUpperBodyAnim Anim);
	virtual void WeaponSwap3p(EUpperBodyAnim Anim);
	virtual void SkipWeaponAdjustment(EUpperBodyAnim Anim);
	virtual void WeaponAdjust3p(EUpperBodyAnim Anim);
	virtual void PlayWeaponAdjustAnim();
	virtual void ClientWeaponActionFailed();
	virtual void DoReload();
	virtual void ClientDoReload(int32 iAmmoAmount);
	virtual void ServerReload();
	virtual void ClientReload();
	AAmmunition* ReloadWithThisClip(AAmmunition* newclip);
	virtual void DropSpecificItem(AInventory* Item);
	virtual void DropSpecificItemBehind(AInventory* Item);
	virtual void EmptyInventory(bool bDropObjectives);
	void EmptyContainer(AInvContainer* container, bool bDropObjectives);
	virtual void NextItem();
	AInventory* FindInventoryType(AInventory*  DesiredClass);
	int32 CountInventoryType(AInventory*  DesiredClass);
	virtual bool AddInventory(TSubclassOf<AInventory> NewItem);
	virtual void DeleteInventory(AInventory* Item);
	virtual void ChangedWeapon();
	virtual void ServerChangedWeapon(AWeapon* OldWeapon, AWeapon* W);
	virtual void WeaponChanged();
	virtual FName GetWeaponBoneFor(TSubclassOf<AInventory> i);
	virtual AInvContainer* FindInventoryItem(TSubclassOf<AInventory> p_item);
	virtual AInvContainer* FindInventorySpace(TSubclassOf<AInventory> p_item);
	virtual TSubclassOf<AInventory> getShoulderInventory();
	virtual TSubclassOf<AInventory> getHandsInventory();
	virtual TSubclassOf<AInventory> getHolsterInventory();
	virtual TSubclassOf<AInventory> getHipInventory();
	virtual TSubclassOf<AInventory> getAltShoulderInventory();
	virtual void DiscardInventory();
	virtual void KnowAll(FString S);
	bool CanSwapHands();
	virtual void SwapHands();
	virtual void SwapHip();
	virtual void SwapAltShoulder();
	virtual void DropAndSwap();
	virtual void getItemToPutInHands();
	AInvContainer* GetSwapContainer();
	bool FinishSwapHands();
	virtual bool CanPutInHands(TSubclassOf<AInventory> Item);
	virtual bool CanPutAway(TSubclassOf<AInventory> Item);
	virtual void ItemPutInHands(TSubclassOf<AInventory> Item);
	virtual void ItemPutAway(TSubclassOf<AInventory> Item);

	virtual void PrintInventory();
	virtual void LogInventory();
	virtual AInvContainer* getInvContainerHands();
	virtual AInvContainer* getInvContainerShoulder();
	virtual AInvContainer* getInvContainerHolster();
	virtual AInvContainer* getInvContainerUtility();
	virtual AInvContainer* getInvContainerHip();
	virtual AInvContainer* getInvContainerAltShoulder();
	virtual void GetGrenade(uint8 Index);
	virtual void GetBinoculars();
	virtual void PutAwayHandItem();
	virtual void SwapHolster();
	virtual void RecalcInvWeight();
	virtual void ChangeInventoryWeight(float Weight);
	virtual void SetInventoryWeight(float Weight);
	virtual float GetInventoryWeight();
	bool CanUseAmmo(AInventory* weap, AInventory* Ammo);
	bool CanPickupItem(AInventory* Item, bool bVirtual);
	virtual bool AreHandsEmpty();
	virtual void NotifyOpticsStatusChangingTo(bool bActive);
	virtual void NotifyBinocularsStatusChangingTo(bool bZoom);
	virtual void ToggleOptics();
	virtual void CleanupOptics();
	virtual void DeactivateOptics();
	virtual void ActivateOptics();
	virtual ABaseOptics* GetOpticsDevice();
	virtual void ChangeFireMode();
	virtual void FixJam();
	virtual void ClientTossWeapon(FVector TossVel);
	virtual void TossWeapon(FVector TossVel);
	FVector GetPickupSpawnLocation(APickup* PickupClass);
	bool HaveUnlimitedAmmo();
	float WeaponEffectivenessBonus();
	FRotator BreatheCycle(float DeltaTime);
	virtual EHealthCondition GetHealthCondition();
	virtual EWoundSeverity GetWoundSeverity();
	virtual FString GetHealthString();
	void Landed(const FHitResult& Hit);
	virtual void HitWall(FVector HitNormal, AActor* Wall);
	virtual void ClientSpawnSideEffect(ASideEffect* SideEffectClass, int32 Damage);
	virtual void ServerSpawnSideEffect(ASideEffect*  SideEffectClass, int32 Damage);
	
	//From AA2
	//virtual void TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, Actor.BoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UTexture2D* HitMaterial);

	//Real
	//virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;


	virtual void NotifyShotHit(APawn* instigatedBy, UaDamageType*  DamageType);
	virtual void ClientSetHitQuadrant(FVector HitSource);
	virtual float GetInjuryPenalty(int32 test_health);
	virtual bool IsBleeding();
	virtual bool IsWounded();
	virtual bool PressingSelfHealAction();
	virtual bool IsHealing();
	virtual bool FlashBleeding();
	virtual void BleedTick(float DeltaTime);
	virtual void CheckInventoryOverload();
	bool ReTryHeal();
	virtual void DoBleed(int32 drain);
	virtual float GetBleedTime();
	virtual bool CanHealMe(APawn* H);
	bool IsCarrying();
	bool IsPickingUp();
	virtual bool MustBeCarried();
	virtual bool CanCarryMe(APawn* C);
	bool UsedBy(APawn* User);
	virtual void MedicHealSelf();
	virtual void HealLock(bool bLock, bool bSuppressWeaponMove);
	virtual void HealingInterrupted();
	virtual void HealingCanceled();
	virtual void StopBleeding();
	int32 GetHealScore();
	virtual void SendHealingPercentage();
	virtual void SendHealingComplete();
	AAGP_ObjectiveInventory* GetFirstObjectiveInventory();
	bool CanGiveMeObjective(APawn* p);
	bool IsGivingObjective();
	virtual void ObjectiveGiveTick(float DeltaTime);
	virtual void GiveObjective();
	virtual void ObjectiveGiveCanceled();
	virtual void ResetObjectiveGive();
	virtual void SendObjectiveGivePercentage();
	virtual void SendObjectiveGiveComplete();
	virtual void PickupLock(bool bLock);
	virtual void PickupInterrupted();
	virtual void PickupCanceled();
	virtual void FinishedPickup();
	int32 GetFallingDamage(float fallspeed);
	virtual void SaveFallSpeed(float fallspeed);
	virtual void TakeFallingDamage();
	virtual int32 AbsorbDamage(int32 Damage, UaDamageType* DamageType, FVector HitLocation);
	virtual void AddVelocity(FVector NewVelocity);
	virtual void PlayHit(float Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType*  DamageType, FVector Momentum);
	virtual void PlayTakeHit(FVector HitLoc, int32 Damage, UaDamageType* DamageType);
	bool IsEnemy(APawn* Other);
	bool IsFriend(APawn* Other);
	virtual void ReportCivilianEvent(APawn* Other, float OthersDistance_sq, AController* hcInstigator);
	bool IsReportableCivi(APawn* Other);
	int32 CivilianReportDistance(APawn* Other);
	FName CivilianReportEvent(APawn* Other);
	virtual void SetDeathMonitor(UScriptObject* mon);
	virtual void DropUtilityInventory();
	virtual void DropWeaponsAfterDeath();
	virtual void ClientStopSideEffects();
	void Died(AController* Killer, UaDamageType* DamageType, FVector HitLocation, FVector HitDir, FBoneInfo Bone);
	void PlayDying(UaDamageType DamageType, FVector HitLoc, FVector HitDir, FBoneInfo Bone);
	virtual void CloseEyes();
	virtual void CloseHands();
	virtual void PlayDyingAnimation(UaDamageType* DamageType, FVector HitLoc);
	virtual bool isDead();
	virtual void ClientAlertOutOfBounds(int32 Seconds);
	virtual void OutOfBoundsNotifyKillPlayer();
	virtual void ClientAlertReturnedToCombat();
	virtual void OutOfBoundsCheck();
	virtual void AnimateDead();
	virtual void GetDeathAnimName(bool bEndLoop);
	virtual bool CanTransitionDeath(EDeathAnim NewAnim);
	virtual void SetDeathAnim(EDeathAnim NewAnim);
	virtual void Destroyed();
	virtual bool removeAsLeader();
	virtual void checkTeamSize();
	virtual bool replaceSubordinate(AAGP_Pawn* old_sub, AAGP_Pawn* new_sub);
	virtual bool removeAsSubordinate();
	virtual bool removeSubordinate(AAGP_Pawn* Remove);
	virtual void addSubordinate(AAGP_Pawn* Add);
	virtual void SetCurrentFFMonitor(UScriptObject* mon);
	virtual void SetCurrentFireMonitor(UScriptObject* mon);
	virtual bool CommoCanHandSignal();
	virtual void CommoCycleState();
	virtual void SetCommoState(ECommoType Type);
	virtual void SetCurrentVolumeMonitor(UScriptObject* vol);
	virtual void SetCurrentVolume(AVolume* vol);
	AVolume* GetCurrentVolume();
	virtual void EnterVolume(AVolume* vol);
	virtual void ExitVolume(AVolume* vol);
	virtual void SetCurrentTriggerMonitor(UScriptObject* trig);
	virtual void SetCurrentTriggerMonitor2(UScriptObject* trig);
	virtual void SetCurrentTriggerMonitor3(UScriptObject* trig);
	virtual void SetCurrentTriggerMonitor4(UScriptObject* trig);
	virtual void SetCurrentTrigger(AActor* trig);
	virtual AActor* GetCurrentTrigger();
	virtual void EnterTrigger(AActor* trig);
	virtual void ExitTrigger(AActor* trig);
	virtual void SetAnimationMonitor(AAnimationController* AM);
	virtual void SetAmmoMonitor(UScriptObject* monitor, bool weaponly);
	virtual void SetJammedMonitor(UScriptObject* monitor);
	virtual void InduceJam();
	bool IsOutOfAmmo(bool weaponly);
	int32 getBestAmmoFromWeapon(AWeapon* weap, AAmmunition* AmmoName);
	virtual void CombatEffectivenessEvent(ECombatEffectEvent Event, float DeltaTime);
	virtual float GetPostureComponent();
	float GetWeapEffectivenessComponent();
	float GetFriendlyMorale(float TMBonusRadius);
	float GetMoraleComponent();
	float GetPanicComponent();
	float GetHealthSubcomponent();
	float GetBleedingSubcomponent();
	float GetInjuryFactor();
	float GetMovementFactor();
	float GetWeapQualifyFactor();
	float GetActivityFlag();
	virtual void RecoveryTick(float DeltaTime);
	virtual void UpdateCombatEffectiveness(float DeltaTime);
	virtual bool IsSniperClass(APawn* p);
	float infront(FVector vec, APawn* Who);
	virtual void StealthBlend(float DeltaTime);
	virtual void FastTick(float DeltaTime);
	virtual void Cower(int32 Type);
	virtual void PickIdle(int32 pickOne);
	virtual int32 MoralCheck(float fNPCMoral);
	virtual bool IsHeDead();
	virtual void SetMoveTarget(AActor* NewTarget);
	virtual void NPC_Drop2Prone(int32 Type);
	virtual void NPC_Reload();
	virtual bool NPC_isGotBuzzed();
	virtual int32 NPC_ActorType();
	virtual void NPC_Serpentine(float SerpTime);
	virtual FRotator SwapAxes(FRotator R);
	virtual void EyeTrack();
	virtual void NotifyFire(AAGP_Weapon* W, FString Parms);
	virtual void NotifyTrace(AAGP_Weapon* W, AActor* HitActor, FString Parms);
	virtual void NotifyThrow(AThrowWeapon* W, FString Parms);
	virtual void MatchEnding();
	virtual void DestroyDebugIcons();
	virtual void AttachDebugIcons();
	virtual void CreateVisualHearingDebugSpheres(float fpHearingDistance, float fpVisualDistance);
	ADebugSphere* CreateDebugSphere(bool bVisionSphere);
	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	float GetThreatLevel();
	virtual void NPCAlertPlayerEvent();
	virtual void AltFire(float F);
	virtual bool isKilledByIED();
	virtual bool IsBusy();
	virtual void PlayJumping();
	virtual bool IsPlayerPawn();
	virtual bool IsHumanControlled();

	//myOwn
	UFUNCTION(Client, Reliable)					void Client_Set_Weapon(TSubclassOf<ASoldierClass> SC);
	virtual void PostInitializeComponents() override;
	virtual bool IsLeaning();

	void Client_Set_Weapon_Implementation(TSubclassOf<ASoldierClass> SC);
	
	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const;


protected:
	// Called when the game starts or when spawned

public:	
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* C) override;


	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	virtual void LoadMesh();

};
