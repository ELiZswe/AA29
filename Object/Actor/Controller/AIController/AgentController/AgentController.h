// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/aAIController.h"
#include "AgentController.generated.h"

class AThrowWeaponPickup;
class ANavigationPoint;
class AGoal_Interface;
class AAction;
class AMentalModel;

UCLASS()
class AA29_API AAgentController : public AaAIController
{
	GENERATED_BODY()
public:
	AAgentController();

	UPROPERTY()										bool bIsLookingAroundDir;				//var bool bIsLookingAroundDir;
	UPROPERTY()										float fIsLookingTime;					//var float fIsLookingTime;
	UPROPERTY()										float fUpdateFollowPostureTime;			//var float fUpdateFollowPostureTime;
	UPROPERTY()										FVector vUpdateFollowLocation;			//var FVector vUpdateFollowLocation;
	UPROPERTY()										float OldTargetHealth;					//var float OldTargetHealth;
	UPROPERTY()										float fNPC_Experience;					//var float fNPC_Experience;
	UPROPERTY()										int32 NewPitch;							//var int NewPitch;
	UPROPERTY()										FVector MoveDestination;				//var FVector MoveDestination;
	UPROPERTY()										AActor* MoveObject	;					//var Actor MoveObject;
	UPROPERTY()										int32 iWaypoint;						//var int iWaypoint;
	UPROPERTY()										FVector Waypoint;						//var FVector Waypoint;
	UPROPERTY()										float fStartHealth;						//var float fStartHealth;
	UPROPERTY()										float rangeToEnemy;						//var float rangeToEnemy;
	UPROPERTY()										bool enemyCont;							//var Contact enemyCont;
	UPROPERTY()										int32 iNPC_AlertLevel;					//var int iNPC_AlertLevel;
	UPROPERTY()										FVector vFollowDestination;				//var FVector vFollowDestination;
	UPROPERTY()										AThrowWeaponPickup* DangerEntity;		//var ThrowWeaponPickup DangerEntity;
	UPROPERTY()										bool bMoveAroundCanSee;					//var bool bMoveAroundCanSee;
	UPROPERTY()										float fNPC_AttackDelay;					//var float fNPC_AttackDelay;
	UPROPERTY()										float fNPC_LostContactTime;				//var float fNPC_LostContactTime;
	UPROPERTY()										bool bIsDead_Dead;						//var bool bIsDead_Dead;
	UPROPERTY()										bool bIsDead;							//var bool bIsDead;
	UPROPERTY()										float iNPC_You_Say;						//var float iNPC_You_Say;
	UPROPERTY()										float iNPC_I_Say;						//var float iNPC_I_Say;
	UPROPERTY()										float fNPC_LastTalkTime;				//var float fNPC_LastTalkTime;
	UPROPERTY()										float fNPC_TalkFrequency;				//var float fNPC_TalkFrequency;
	UPROPERTY()										bool bNPC_FlambeFX;						//var bool bNPC_FlambeFX;
	UPROPERTY()										bool bNPC_GiblettsFX;					//var bool bNPC_GiblettsFX;
	UPROPERTY()										bool bNPC_FliesFX;						//var bool bNPC_FliesFX;
	UPROPERTY()										bool bNPC_ActorBloodPoolFX;				//var bool bNPC_ActorBloodPoolFX;
	UPROPERTY()										bool bDeadDeadTwitch;					//var bool bDeadDeadTwitch;
	UPROPERTY()										FVector touchLocation;					//var FVector touchLocation;
	UPROPERTY()										bool bTouched;							//var bool bTouched;
	UPROPERTY()										AThrowWeaponPickup* TWP_AvoidFearGrenade;		//var ThrowWeaponPickup TWP_AvoidFearGrenade;
	UPROPERTY()										float fAvoidFearGrenadeTime;			//var float fAvoidFearGrenadeTime;
	UPROPERTY()										AThrowWeaponPickup* FearGrenade;		//var ThrowWeaponPickup FearGrenade;
	UPROPERTY()										float fSingleShotDelayTime;				//var float fSingleShotDelayTime;
	UPROPERTY()										float fSingleShotTime;					//var float fSingleShotTime;
	UPROPERTY()										bool bFireSingleShot;					//var bool bFireSingleShot;
	UPROPERTY()										bool bIsSingleShot;						//var bool bIsSingleShot;
	UPROPERTY()										bool bIsSniper;							//var bool bIsSniper;
	UPROPERTY()										bool bHandSignalsOnly;					//var bool bHandSignalsOnly;
	UPROPERTY()										bool bIsALeader;						//var bool bIsALeader;
	UPROPERTY()										bool bAsleep;							//var bool bAsleep;
	UPROPERTY()										bool bStart;							//var bool bStart;
	UPROPERTY()										bool bCanBeUsed;						//var bool bCanBeUsed;
	UPROPERTY()										bool bAttackDone;						//var bool bAttackDone;
	UPROPERTY()										bool bCower;							//var bool bCower;
	UPROPERTY()										bool bRunning;							//var bool bRunning;
	UPROPERTY()										int32 iNPC_StunGrenade;					//var int iNPC_StunGrenade;
	UPROPERTY()										int32 iNPC_SmokeGrenade;				//var int iNPC_SmokeGrenade;
	UPROPERTY()										int32 iNPC_FragGrenade;					//var int iNPC_FragGrenade;
	UPROPERTY()										float fNPC_GrenadeAttackTime;			//var float fNPC_GrenadeAttackTime;
	UPROPERTY()										float fNPC_ShootAccuracy;				//var float fNPC_ShootAccuracy;
	UPROPERTY()										float fNPC_LikesToThrowGrenade;			//var float fNPC_LikesToThrowGrenade;
	UPROPERTY()										float fNPC_LikesToAmbient;				//var float fNPC_LikesToAmbient;
	UPROPERTY()										float fNPC_LikesToTalk;					//var float fNPC_LikesToTalk;
	UPROPERTY()										float fNPC_LikesToAssault;				//var float fNPC_LikesToAssault;
	UPROPERTY()										float fNPC_LikesToAmbush;				//var float fNPC_LikesToAmbush;
	UPROPERTY()										float fNPC_LikesToStand;				//var float fNPC_LikesToStand;
	UPROPERTY()										float fNPC_LikesToCrouch;				//var float fNPC_LikesToCrouch;
	UPROPERTY()										float fNPC_LikesToProne;				//var float fNPC_LikesToProne;
	UPROPERTY()										float fNPC_AquireAimDistance;			//var float fNPC_AquireAimDistance;
	UPROPERTY()										float fNPC_AquireAimTime;				//var float fNPC_AquireAimTime;
	UPROPERTY()										bool bNPC_DualWeapon;					//var bool bNPC_DualWeapon;
	UPROPERTY()										bool bNPC_RocketOnlyWeapon;				//var bool bNPC_RocketOnlyWeapon;
	UPROPERTY()										float fNPC_ProjectileAimTime;			//var float fNPC_ProjectileAimTime;
	UPROPERTY()										int32 iNPC_AssignedWeapon;				//var int iNPC_AssignedWeapon;
	UPROPERTY()										float fNPC_SearchingTime;				//var float fNPC_SearchingTime;
	UPROPERTY()										FVector InvestigateTrackedPosition;		//var FVector InvestigateTrackedPosition;
	UPROPERTY()										float fNPC_TakingCoverTime;				//var float fNPC_TakingCoverTime;
	UPROPERTY()										float fNPC_InvestigateTime;				//var float fNPC_InvestigateTime;
	UPROPERTY()										APawn* InvestigateObject;				//var Pawn InvestigateObject;
	UPROPERTY()										bool bNPC_GoCheckItOut;					//var bool bNPC_GoCheckItOut;
	UPROPERTY()										FVector EnemyTrackedPosition;			//var FVector EnemyTrackedPosition;
	UPROPERTY()										float fNPC_ReactDelayTime;				//var float fNPC_ReactDelayTime;
	UPROPERTY()										float fNPC_DetectAgainTime;				//var float fNPC_DetectAgainTime;
	UPROPERTY()										float fNPC_OldVisionDistanceChecked;	//var float fNPC_OldVisionDistanceChecked;
	UPROPERTY()										float fNPC_ReloadWeaponTime;			//var float fNPC_ReloadWeaponTime;
	UPROPERTY()										float fNPC_CrouchTime;					//var float fNPC_CrouchTime;
	UPROPERTY()										FVector vNPC_StartLocation;				//var FVector vNPC_StartLocation;
	UPROPERTY()										float fNPC_AttackMoveAroundTime;		//var float fNPC_AttackMoveAroundTime;
	UPROPERTY()										bool bHasWeapon;						//var bool bHasWeapon;
	UPROPERTY()										bool bTookDamage;						//var bool bTookDamage;
	UPROPERTY()										ANavigationPoint* SafeDestN;			//var NavigationPoint SafeDestN;
	UPROPERTY()										bool bGrenadeCheck;						//var bool bGrenadeCheck;
	UPROPERTY()										bool bNewOrder;							//var bool bNewOrder;
	UPROPERTY()										FVector PUserOldPos;					//var FVector PUserOldPos;
	UPROPERTY()										APawn* PToucher;						//var Pawn PToucher;
	UPROPERTY()										APawn* PUser;							//var Pawn PUser;
	UPROPERTY()										AActor* CurrentDestination;				//var Actor CurrentDestination;
	UPROPERTY()										float fWait;							//var float fWait;
	UPROPERTY()										EAction CurrentOrder;					//var EAction CurrentOrder;
	UPROPERTY()										int32 Check;							//var int Check;
	UPROPERTY()										AGoal_Interface* my_goal_decider;		//var Goal_Interface my_goal_decider;
	UPROPERTY()										bool actionFailed;						//var bool actionFailed;
	UPROPERTY()										float actionStarted;					//var float actionStarted;
	UPROPERTY()										AAction* ActiveAction;					//var Action ActiveAction;
	UPROPERTY()										bool ActiveGoal;						//var Goal ActiveGoal;
	UPROPERTY()										EAction CurrentAction;					//var EAction CurrentAction;
	UPROPERTY()										ANavigationPoint* NCoverPlace;			//var NavigationPoint NCoverPlace;
	UPROPERTY()										bool bNoFriendlyFire;					//var bool bNoFriendlyFire;
	UPROPERTY()										int32 iNPC_GroupID;						//var int iNPC_GroupID;
	UPROPERTY()										EATypes Actor_t;						//var Actor.EATypes Actor_t;
	UPROPERTY()										USoundBase* sPilot;						//var Sound sPilot;
	UPROPERTY()										USoundBase* sEnemyLeader;				//var Sound sEnemyLeader;
	UPROPERTY()										USoundBase* sWhisperSquad;				//var Sound sWhisperSquad;
	UPROPERTY()										USoundBase* sShoutSquad;				//var Sound sShoutSquad;
	UPROPERTY()										USoundBase* sWhisperFriendly;			//var Sound sWhisperFriendly;
	UPROPERTY()										USoundBase* sShoutFriendly;				//var Sound sShoutFriendly;
	UPROPERTY()										USoundBase* sWhisperEnemy;				//var Sound sWhisperEnemy;
	UPROPERTY()										USoundBase* sShoutEnemy;				//var Sound sShoutEnemy;

	void CalculatePathToGoal(FVector NewDestination);
	FVector GetNextWaypoint();
	void Reset();
	void Destroyed();
	//void Possess(APawn* aPawn);
	void CreateGoalDecider();
	bool isPassive();
	bool weaponJammed();
	bool weaponOutOfAmmo();
	AMentalModel* getMentalModel();
	void NPC_Walk(float Speed);
	void NPC_TakeCover(bool isProne);
	void NPC_GoToStart();
	void NPC_Investigate();
	void NPC_DeadDead();
	void NPC_DeathFX();
	void Start();
	void Stand();
	void Cower();
	void Suppress(AActor* SuppressionTarget);
	void Attack(float fLen);
	void Idle();
	void Patrol();
	void MovementToward(AActor* new_move_object);
	void MovementTo(FVector NewDestination);
	void Wander();
	void Flee();
	void FixJam();
	void Reload();
	void Recovery(APickup* recovery_pickup);
	void TakeCover(bool goProne);
	void Charge();
	bool AdjustAround(APawn* Other);
	int32 SetPitch(FVector targ);
	bool NeedToTurn(FVector targ);
	void NPC_GiveAmmo();
	int32 NPC_isWeaponInstantHit();
	void NPC_SingleShotReloadTime();
	void NPC_GiveWeapon(int32 whichone);
	void NPC_AmmoCheck();
	void ShootTarget(AActor* NewTarget);
	void NotifyTakeHit(APawn* instigatedBy, FVector HitLocation, int32 Damage, UaDamageType DamageType, FVector Momentum);
	void Killed(AController* Killer, APawn* Other, UaDamageType DamageType);
	void NotifySeePawn();
	void SeePawn(APawn* Seen);
	void SeePlayer(APawn* Seen);
	void SeeMonster(APawn* Seen);
	void HearNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation);
	bool SetEnemy(APawn* NewEnemy);
	bool validEnemy();
	void NPC_ResetToStand();
	FRotator GetViewRotation();
	FRotator NPC_AdjustAim(FVector projStart, int32 aimerror);
	void DoFireEffectSwitchMode();
	void DoFireEffect();
	bool InRange();
	bool InExtendedRange();
	void SetAquireAimTime();
	bool NPC_FriendlyFire();
	bool NearWall(float walldist);
	bool CheckIfShouldCrouch(FVector StartPosition, FVector TargetPosition, float Probability);
	bool CheckIfShouldProne(FVector StartPosition, FVector TargetPosition, float Probability);
	void FireWeapon(bool bSuppressiveFire);
	void registerNotification(AAction* new_action);
	void NotifyComplete();
	bool HandlePickupQuery(APickup* pick);
	bool NPC_isDistanceDetected(float fLen, APawn* p);
	void NPC_UpdateOldVisionDistanceChecked();
	void NPC_AlertYourBuddies(APawn* p);
	bool NPC_CanReactDelayIsDone();
	void NPC_EnemyDetection();
	void NPC_InvestigateThink();
	void NPC_InvestigateForceBuddyToSearch();
	bool LookAround();
	bool NPC_GotBuzzed();
	bool CheckGrenadeAwareTime();
	void SetGrenadeAwareTime(float Time);
	AThrowWeaponPickup* ThreatGrenade();
	void NPC_GiveClip(int32 Num);
	void NPC_SetActorAttributes();
	void NPC_Think();
	bool NPC_CheckIfDead();
	void Timer();
	void BeginPlay();
	bool UsedBy(APawn* User);
	bool isTouched();
	void Touch(AActor* Other);
	ANavigationPoint* ClosestNavPoint();
	ANavigationPoint* FindCoverNode(FVector VPosition);
	ANavigationPoint* FindSafePlaceFrom(FVector InstigatedByLocation, bool bNear, bool bHunting);
	//void TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* AHitMaterial);
	void GrenadeTakeCover(bool bProne);
	float infront(FVector vec, APawn* Who);
	void NPC_PilotSay(int32 Snd, bool Force);
	void NPC_Say(int32 theSound, bool shout, bool forceplay, bool bFriend);
};
