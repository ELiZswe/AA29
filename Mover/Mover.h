// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AA29/AA29.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "Mover.generated.h"

class UaDamageType;


UCLASS()
class AA29_API AMover : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMover();

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;


	
	UPROPERTY()																AActor* BreachActor;							//var Actor BreachActor;
	UPROPERTY()																EMoverEncroachType InitialMoverEncroachType;	//var EMoverEncroachType InitialMoverEncroachType;
	UPROPERTY()																ELockingStyle resetLockingStyle;				//var ELockingStyle resetLockingStyle;
	UPROPERTY()																ELockingStyle InitialLockingStyle;				//var ELockingStyle InitialLockingStyle;
	UPROPERTY()																uint8 InitialKeyNum;							//var byte InitialKeyNum;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								ELockingSide LockingSide;						//var() ELockingSide LockingSide;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								ELockingStyle LockingStyle;						//var() ELockingStyle LockingStyle;
	UPROPERTY()																FName Backup_InitialState;						//var name Backup_InitialState;
	UPROPERTY()																bool BACKUP_bHidden;							//var bool BACKUP_bHidden;
	UPROPERTY()																bool bResetting;								//var bool bResetting;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								FName AntiPortalTag;							//var() name AntiPortalTag;
	//UPROPERTY()															TArray<AAntiPortalActor*> AntiPortals;			//var array<AntiPortalActor> AntiPortals;
	UPROPERTY()																int32 StepDirection;							//var int StepDirection;
	UPROPERTY()																uint8 StoppedPosition;							//var byte StoppedPosition;
	UPROPERTY()																int32 ClientUpdate;								//var int ClientUpdate;
	UPROPERTY()																FRotator RealRotation;							//var Object.Rotator RealRotation;
	UPROPERTY()																FVector RealPosition;							//var FVector RealPosition;
	UPROPERTY()																FVector SimInterpolate;							//var FVector SimInterpolate;
	UPROPERTY()																int32 SimOldRotRoll;							//var int SimOldRotRoll;
	UPROPERTY()																int32 SimOldRotYaw;								//var int SimOldRotYaw;
	UPROPERTY()																int32 SimOldRotPitch;							//var int SimOldRotPitch;
	UPROPERTY()																FVector SimOldPos;								//var FVector SimOldPos;
	UPROPERTY()																uint8 ClientStop;								//var byte ClientStop;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bOscillatingLoop;							//var() bool bOscillatingLoop;
	UPROPERTY()																bool bSideADamagedMesh;							//var bool bSideADamagedMesh;
	UPROPERTY()																bool bGotoA;									//var bool bGotoA;
	UPROPERTY()																bool bStopped;									//var bool bStopped;
	UPROPERTY()																bool bInClosing;								//var bool bInClosing;
	UPROPERTY()																bool bInOpening;								//var bool bInOpening;
	UPROPERTY()																bool bJumpLift;									//var bool bJumpLift;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "AI")				bool bNotADoor;									//var(AI) bool bNotADoor;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "AI")				bool bNoAIRelevance;							//var(AI) bool bNoAIRelevance;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "AI")				bool bAutoDoor;									//var(AI) bool bAutoDoor;
	UPROPERTY()																bool bPlayerOnly;								//var bool bPlayerOnly;
	UPROPERTY()																bool bClosed;									//var bool bClosed;
	UPROPERTY()																bool bClientPause;								//var bool bClientPause;
	UPROPERTY()																bool bDelaying;									//var bool bDelaying;
	UPROPERTY()																bool bOpening;									//var bool bOpening;
	UPROPERTY()																ANavigationPoint* myMarker;						//var NavigationPoint myMarker;
	UPROPERTY()																float PhysRate;									//var float PhysRate;
	UPROPERTY()																float PhysAlpha;								//var float PhysAlpha;
	UPROPERTY()																FRotator SavedRot;								//var Object.Rotator SavedRot;
	UPROPERTY()																FRotator OldRot;								//var Object.Rotator OldRot;
	UPROPERTY()																FVector SavedPos;								//var FVector SavedPos;
	UPROPERTY()																FVector OldPrePivot;							//var FVector OldPrePivot;
	UPROPERTY()																FVector OldPos;									//var FVector OldPos;
	UPROPERTY()																FVector BasePos;								//var FVector BasePos;
	UPROPERTY()																FRotator BaseRot;								//var Object.Rotator BaseRot;
	UPROPERTY()																TArray<FRotator> KeyRot;						//var Object.Rotator KeyRot;
	UPROPERTY()																TArray<FVector> KeyPos;							//var FVector KeyPos;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverEvents")	FName LoopEvent;								//var(MoverEvents) name LoopEvent;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverEvents")	FName ClosedEvent;								//var(MoverEvents) name ClosedEvent;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverEvents")	FName ClosingEvent;								//var(MoverEvents) name ClosingEvent;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverEvents")	FName OpenedEvent;								//var(MoverEvents) name OpenedEvent;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverEvents")	FName OpeningEvent;								//var(MoverEvents) name OpeningEvent;
	UPROPERTY()																USoundBase* NextSound;							//var Sound NextSound;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverSounds")	USoundBase* PartialStoppedSound;				//var(MoverSounds) Sound PartialStoppedSound;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverSounds")	USoundBase* PartialClosingSound;				//var(MoverSounds) Sound PartialClosingSound;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverSounds")	USoundBase* PartialOpeningSound;				//var(MoverSounds) Sound PartialOpeningSound;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverSounds")	USoundBase* LockedSound;						//var(MoverSounds) Sound LockedSound;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverSounds")	bool bUsePartialSounds;							//var(MoverSounds) bool bUsePartialSounds;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverSounds")	USoundBase* LoopSound;							//var(MoverSounds) Sound LoopSound;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverSounds")	USoundBase* MoveAmbientSound;					//var(MoverSounds) Sound MoveAmbientSound;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverSounds")	USoundBase* ClosedSound;						//var(MoverSounds) Sound ClosedSound;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverSounds")	USoundBase* ClosingSound;						//var(MoverSounds) Sound ClosingSound;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverSounds")	USoundBase* OpenedSound;						//var(MoverSounds) Sound OpenedSound;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverSounds")	USoundBase* OpeningSound;						//var(MoverSounds) Sound OpeningSound;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bBreaching;								//var bool bBreaching;
	UPROPERTY()																bool bEndOfRound;								//var bool bEndOfRound;
	UPROPERTY()																bool bUseControl;								//var bool bUseControl;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bUseHighlight;								//var() bool bUseHighlight;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bReturnGroupLocked;						//var() bool bReturnGroupLocked;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool DelayTime;									//var() float DelayTime;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "ReturnGroup")	FName ReturnGroup;								//var(ReturnGroup) name ReturnGroup;
	UPROPERTY()																AMover*	Follower;								//var Mover Follower;
	UPROPERTY()																AMover*	Leader;									//var Mover Leader;
	UPROPERTY()																int32 numTriggerEvents;							//var int numTriggerEvents;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								float DamageThreshold;							//var() float DamageThreshold;
	UPROPERTY()																AActor* SavedTrigger;							//var Actor SavedTrigger;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								FName BumpEvent;								//var() name BumpEvent;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								FName PlayerBumpEvent;							//var() name PlayerBumpEvent;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "ReturnGroup")	bool bIsLeader;									//var(ReturnGroup) bool bIsLeader;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bUseShortestRotation;						//var() bool bUseShortestRotation;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bDynamicLightMover;						//var() bool bDynamicLightMover;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bDamageTriggered;							//var() bool bDamageTriggered;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bUseTriggered;								//var() bool bUseTriggered;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bSlave;									//var() bool bSlave;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bTriggerOnceOnly;							//var() bool bTriggerOnceOnly;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bToggleDirection;							//var() bool bToggleDirection;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bUseLockSideForBump;						//var() bool bUseLockSideForBump;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								int32 EncroachDamage;							//var() int EncroachDamage;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								float OtherTime;								//var() float OtherTime;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								float StayOpenTime;								//var() float StayOpenTime;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								float MoveTime;									//var() float MoveTime;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bMoveSlowWhenLow;							//var() bool bMoveSlowWhenLow;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bMoveFastWhenRun;							//var() bool bMoveFastWhenRun;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverTwoWay")	UStaticMesh* SideBDamagedMesh;					//var(MoverTwoWay) StaticMesh SideBDamagedMesh;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverTwoWay")	UStaticMesh* SideADamagedMesh;					//var(MoverTwoWay) StaticMesh SideADamagedMesh;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverTwoWay")	bool bOneWayMover;								//var(MoverTwoWay) bool bOneWayMover;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverTwoWay")	bool bTwoWayMover;								//var(MoverTwoWay) bool bTwoWayMover;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverTwoWay")	uint8 TwoWayKeyB;								//var(MoverTwoWay) const byte TwoWayKeyB;
	UPROPERTY()																uint8 StartKeyNum;								//var byte StartKeyNum;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								uint8 BrushRaytraceKey;							//var() const byte BrushRaytraceKey;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								uint8 WorldRaytraceKey;							//var() const byte WorldRaytraceKey;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								uint8 NumKeys;									//var() const byte NumKeys;
	UPROPERTY()																uint8 PrevKeyNum;								//var byte PrevKeyNum;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								uint8 KeyNum;									//var() byte KeyNum;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								EBumpType BumpType;								//var() EBumpType BumpType;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								EMoverGlideType MoverGlideType;					//var() EMoverGlideType MoverGlideType;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								EMoverEncroachType MoverEncroachType;			//var() EMoverEncroachType MoverEncroachType;


	//From Actor
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bDisplayTargetingInfo;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								FString Group;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bBulletRicochet;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bBulletPenetration;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								FName InitialState;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								float SoundRadius;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								float TransientSoundRadius;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								int32 SoundVolume;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								int32 SoundPitch;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Damage")			bool bInstantGrenBreak;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Damage")			bool bDamageable;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Damage")			float DamageHealth;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Damage")			USoundBase* DamageSound;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Damage")			UStaticMesh* DamagedMesh;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Damage")			FName DamageEvent;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Damage")			bool bBreachable;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Damage")			bool bCheckDamageType;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Damage")			TArray<TSubclassOf<UaDamageType>> DamageTypes;			//var(DamageType) array<class<DamageType> > DamageTypes;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Damage")			FName AttachTag;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Damage")			FName DamageTag;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Damage")			int32 DamagePoints;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "Damage")			int32 DestroyPoints;						//var(LinkDamage) int DestroyPoints;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bFixedRotationDir;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								FRotator RotationRate;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MoverSounds")	USoundBase* AmbientSound;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								FName Physics;
	

	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bInterpolating;			//var bool bInterpolating;
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								bool bCollideActors;			//var bool bInterpolating;


	//Mine
	UPROPERTY(EditAnywhere, BluePrintReadOnly)								EDrawType DrawType;
	
	virtual void BeginPlay();

	void SetKeyPos(int32 Index, FVector V);
	void SetKeyRot(int32 Index, FRotator R);
	bool SelfTriggered();
	
	AActor* SpecialHandling(APawn* Other);
	void StartInterpolation();
	void Timer();
	float AdjustMoveTime(float Seconds);
	void InterpolateTo(uint8 NewKeyNum, float Seconds);
	void SetKeyframe(uint8 NewKeyNum, FVector NewLocation, FRotator NewRotation);
	void KeyFrameReached();
	USoundBase* GetNextSound();
	void FinishNotify();
	void FinishedClosing();
	void ReallyFinishedClosing();
	void FinishedOpening();
	void ReallyFinishedOpening();
	bool AskLeader();
	bool DoFollower();
	void DoOpen();
	void ReallyOpen();
	bool moveToA();
	void DoClose();
	void ReallyDoClose();
	uint8 previousKeyFrame(uint8 ThisKey);
	uint8 nextKeyFrame(uint8 ThisKey);
	
	void PostBeginPlay();
	void Reset();
	void SetResetStatus(bool bNewStatus);
	void MakeGroupStop();
	void ReallyMakeGroupStop();
	void MakeGroupReturn();
	void ReallyMakeGroupReturn();
	bool EncroachingOn(AActor* Other);
	bool UseOneWayLock(APawn* TestPawn);
	bool UsedBy(APawn* User);
	void Bump(AActor* Other);
	void HandleBreachInfo(AActor* NewBreachActor);
	void HandleBreachDamage(int32 NDamage);
	//void TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, AMaterial HitMaterial);
	void DisableTrigger();
	void EnableTrigger();
	void MoverBreached(AActor* ResponsibleActor, APawn* instigatedBy);
	bool DestroyAttachedDoorBreachers();
	bool ExistAttachedDoorBreachers();
	void SetStoppedPosition(uint8 NewPos);
	void MoverLooped();
	void BaseStarted();
	void BaseFinished();
	void UpdatePrecacheStaticMeshes();

	//Mine
	bool IsDamaged();


	//Replicated Door:
protected:
	UPROPERTY(EditAnywhere)													UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere)													USceneComponent* MoverRoot;
	UPROPERTY(ReplicatedUsing = OnRep_ToggleDoor)
		bool bDoorOpen;
	UFUNCTION() void OnRep_ToggleDoor();
	FTimerHandle THDoor;

	UFUNCTION() void RotateDoor();
public:
	void ToggleDoor();

};
