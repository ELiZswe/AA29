// All the original content belonged to the US 

#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "TimerManager.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Net/UnrealNetwork.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/AuxCollisionCylinder/AuxCollisionCylinder.h"
#include "AA29/Object/Actor/Effects/Fragment/Fragment.h"
#include "AA29/Object/Actor/Projectile/Projectile.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "AA29/Object/Actor/AntiPortalActor/AntiPortalActor.h"
#include "AA29/Object/Actor/Decoration/Decoration.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_DoorBreacher_Demo/PickupT_DoorBreacher_Demo.h"

// Sets default values
AMover::AMover()
{
	KeyRot.SetNum(24);
	KeyPos.SetNum(24);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	MoverEncroachType = EMoverEncroachType::ME_ReturnWhenEncroach;
	MoverGlideType = EMoverGlideType::MV_GlideByTime;
	NumKeys = 2;
	TwoWayKeyB = 2;
	MoveTime = 1;
	StayOpenTime = 4;
	bToggleDirection = true;
	bClosed = true;
	StepDirection = 1;
	//bUseDynamicLights = true;
	//bNoDelete = true;
	//bWorldGeometry = false;
	//Physics = 8;
	//RemoteRole = 2;
	NetUpdateFrequency = 1;
	NetPriority = 2.7;
	//InitialState = "BumpOpenTimed";
	//SoundVolume = 228;
	//TransientSoundVolume = 1;
	//CollisionRadius = 0;
	//CollisionHeight = 0;
	//bPathColliding = true;

	MoverRoot = CreateDefaultSubobject<USceneComponent>(TEXT("MoverRoot"));
	RootComponent = MoverRoot;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	bDoorOpen = false;
	KeyRot.SetNum(1);
	KeyPos.SetNum(1);
	KeyRot[0] = FRotator::ZeroRotator;
	KeyPos[0] = FVector::ZeroVector;
}

/*
State OpenTimedMover
{
	Function bool ShouldReTrigger()
	{
		return false;
	}
	Function Reset()
	{
		bEndOfRound=true;
		SetResetStatus(true);
		GotoState(Backup_InitialState,"Close");
	}
	Function BeginState()
	{
		DebugLog(DEBUG_Door,"Mover::OpenTimedMover state entered.");
		EnableTrigger();
	}
Begin:
	if (bTriggerOnceOnly)
	{
		Disable("Trigger");
	}
	bClosed=false;
	bEndOfRound=false;
	DisableTrigger();
	if (DelayTime > 0)
	{
		bDelaying=true;
		Sleep(DelayTime);
	}
	DoOpen();
	FinishInterpolation();
	FinishedOpening();
	Sleep(StayOpenTime);
	if (bTriggerOnceOnly)
	{
		GotoState("WasOpenTimedMover","None");
	}
	DoClose();
	FinishInterpolation();
	FinishedClosing();
	EnableTrigger();
	if (bResetting)
	{
		SetResetStatus(false);
		GotoState(Backup_InitialState,"None");
	}
	Sleep(StayOpenTime);
	if (ShouldReTrigger())
	{
		SavedTrigger=nullptr;
		GotoState("StandOpenTimed","Open");
	}
}
*/

/*
State WasOpenTimedMover
{
	Function Reset()
	{
		SetResetStatus(true);
		GotoState(Backup_InitialState,"Close");
	}
}
*/

/*
State StandOpenTimed extends OpenTimedMover
{
	Function bool ShouldReTrigger()
	{
		int32 i = 0;
		for (i=0; i<Attached.Num(); i++)
		{
			if (CanTrigger(Attached[i]))
			{
				return true;
			}
		}
		return false;
	}
	Function bool CanTrigger(AActor* Other)
	{
		APawn* p = nullptr;
		p=Pawn(Other);
		if ((BumpType != 2) && (p == nullptr))
		{
			return false;
		}
		if ((BumpType == 0) && (! p.IsPlayerPawn()))
		{
			return false;
		}
		if ((BumpType == 1) && (Other.Mass < float(10)))
		{
			return false;
		}
		TriggerEvent(BumpEvent,Self,p);
		return true;
	}
	Function Attach(AActor* Other)
	{
		if (! CanTrigger(Other))
		{
			return;
		}
		SavedTrigger=nullptr;
		GotoState("StandOpenTimed","Open");
	}
	Function DisableTrigger()
	{
		Disable("Attach");
	}
	Function EnableTrigger()
	{
		Enable("Attach");
	}
}
*/

/*
State BumpOpenTimed extends OpenTimedMover
{
	Function Bump(AActor* Other)
	{
		if ((BumpType != 2) && (Cast<APawn>(Other) == nullptr))
		{
			return;
		}
		if ((BumpType == 0) && (! Pawn(Other).IsPlayerPawn()))
		{
			return;
		}
		if ((BumpType == 1) && (Other.Mass < float(10)))
		{
			return;
		}
		if ((bUseLockSideForBump && Other->IsA(APawn::StaticClass())) && (! UseOneWayLock(Cast<APawn>(Other))))
		{
			return;
		}
		Global.PawnShadow(Other);
		SavedTrigger=nullptr;
		Instigator=Pawn(Other);
		Instigator.Controller.WaitForMover(this);
		GotoState("BumpOpenTimed","Open");
	}
	Function DisableTrigger()
	{
		Disable("Bump");
	}
	Function EnableTrigger()
	{
		Enable("Bump");
	}
}
*/

/*
State TriggerOpenTimed extends OpenTimedMover
{
	Function bool SelfTriggered()
	{
		return false;
	}
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		SavedTrigger=Other;
		Instigator=EventInstigator;
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.BeginEvent();
		}
		GotoState("TriggerOpenTimed","Open");
	}
	Function DisableTrigger()
	{
		Disable("Trigger");
	}
	Function EnableTrigger()
	{
		Enable("Trigger");
	}
}
*/

/*
State LoopMove
{
	Function bool SelfTriggered()
	{
		return false;
	}
	Event Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		Disable("Trigger");
		Enable("UnTrigger");
		SavedTrigger=Other;
		Instigator=EventInstigator;
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.BeginEvent();
		}
		bOpening=true;
		PlaySound(OpeningSound,0);
		AmbientSound=MoveAmbientSound;
		GotoState("LoopMove","Running");
	}
	Event UnTrigger(AActor* Other, APawn* EventInstigator)
	{
		Disable("UnTrigger");
		Enable("Trigger");
		SavedTrigger=Other;
		Instigator=EventInstigator;
		GotoState("LoopMove","Stopping");
	}
	Event KeyFrameReached()
	{
	}
	Function BeginState()
	{
		bOpening=false;
		bDelaying=false;
	}
Begin:
	FinishInterpolation();
	InterpolateTo(byte((float(byte((KeyNum + 1))) % float(NumKeys))),MoveTime);
	GotoState("LoopMove","Running");
	FinishInterpolation();
	FinishedOpening();
	UntriggerEvent(Event,Self,Instigator);
	bOpening=false;
}
*/

/*
State TriggerToggle
{
	Function bool SelfTriggered()
	{
		return false;
	}
	Function Reset()
	{
		Global.NetMode();
		if (bOpening || bDelaying)
		{
			bEndOfRound=true;
			SetResetStatus(true);
			GotoState("TriggerToggle","Close");
		}
	}
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		SavedTrigger=Other;
		Instigator=EventInstigator;
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.BeginEvent();
		}
		if ((KeyNum == 0) || (KeyNum < PrevKeyNum))
		{
			GotoState("TriggerToggle","Open");
		}
		else
		{
			GotoState("TriggerToggle","Close");
		}
	}
Begin:
	DebugLog(DEBUG_Door,"Mover::TriggerToggle()::Open Label.");
	bClosed=false;
	bEndOfRound=false;
	if (DelayTime > 0)
	{
		bDelaying=true;
		Sleep(DelayTime);
	}
	DoOpen();
	FinishInterpolation();
	FinishedOpening();
	if (SavedTrigger != nullptr)
	{
		SavedTrigger.EndEvent();
	}
	DebugLog(DEBUG_Door,"Mover::TriggerToggle()::Finished Open Label.");
	DebugLog(DEBUG_Door,"Mover::TriggerToggle()::Close Label.");
	DoClose();
	FinishInterpolation();
	FinishedClosing();
	SetResetStatus(false);
	DebugLog(DEBUG_Door,"Mover::TriggerToggle()::Finished Closing.");
}
*/

/*
State TriggerReset
{
	Function bool SelfTriggered()
	{
		return false;
	}
	Function Reset()
	{
		Global.NetMode();
		if (bOpening || bDelaying)
		{
			SetResetStatus(true);
			GotoState("TriggerReset","End");
		}
	}
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		SavedTrigger=Other;
		Instigator=EventInstigator;
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.BeginEvent();
		}
		GotoState("TriggerReset","Close");
	}
Begin:
	InterpolateTo(0,0);
	FinishInterpolation();
	FinishedClosing();
	SetResetStatus(false);
	bClosed=false;
	if (DelayTime > 0)
	{
		bDelaying=true;
		Sleep(DelayTime);
	}
	DoOpen();
	FinishInterpolation();
	FinishedOpening();
	if (SavedTrigger != nullptr)
	{
		SavedTrigger.EndEvent();
	}
}
*/

/*
State TriggerControl
{
	Function bool SelfTriggered()
	{
		return false;
	}
	Function Reset()
	{
		Global.NetMode();
		if (numTriggerEvents > 0)
		{
			SetResetStatus(true);
			numTriggerEvents=0;
			UnTrigger(nullptr,nullptr);
		}
	}
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		numTriggerEvents ++;
		SavedTrigger=Other;
		Instigator=EventInstigator;
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.BeginEvent();
		}
		if (! bOpening)
		{
			GotoState("TriggerControl","Open");
		}
	}
	Function UnTrigger(AActor* Other, APawn* EventInstigator)
	{
		numTriggerEvents --;
		if (numTriggerEvents <= 0)
		{
			numTriggerEvents=0;
			SavedTrigger=Other;
			Instigator=EventInstigator;
			if (SavedTrigger != nullptr)
			{
				SavedTrigger.BeginEvent();
			}
			GotoState("TriggerControl","Close");
		}
	}
	Function BeginState()
	{
		numTriggerEvents=0;
	}
Begin:
	bClosed=false;
	if (DelayTime > 0)
	{
		bDelaying=true;
		Sleep(DelayTime);
	}
	if (! bOpening)
	{
		DoOpen();
	}
	FinishInterpolation();
	FinishedOpening();
	if (SavedTrigger != nullptr)
	{
		SavedTrigger.EndEvent();
	}
	if (bTriggerOnceOnly)
	{
		GotoState("WasTriggerControl");
	}
	if (bOpening)
	{
		DoClose();
	}
	FinishInterpolation();
	FinishedClosing();
	SetResetStatus(false);
}
*/

/*
State UseControl extends TriggerToggle
{
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		if ((bBreachable && (! bBreaching)) && ExistAttachedDoorBreachers())
		{
			return;
		}
		Instigator=EventInstigator;
		DebugLog(DEBUG_Door,"Mover::UseControl::Trigger()	" + FString::FromInt(this) @ FString::FromInt(bOpening) @ FString::FromInt(bInOpening) @ FString::FromInt(bClosed) @ FString::FromInt(bInClosing) @ FString::FromInt(bStopped));
		if (bStopped)
		{
			if (bInOpening)
			{
				DebugLog(DEBUG_Door,"Mover::UseControl State Cast<ATrigger>()::Door was previously opening, trying to close.");
				NextSound=PartialClosingSound;
				GotoState("UseControl","Close");
			}
			else
			{
				if (bInClosing)
				{
					DebugLog(DEBUG_Door,"Mover::UseControl State Cast<ATrigger>()::Door was previously closing, trying to open.");
					NextSound=PartialOpeningSound;
					GotoState("UseControl","Open");
				}
				else
				{
					DebugLog(DEBUG_Warn,"Mover::UseControl::Trigger()	Don't know what to do when Stop flag is true but inclosing and inopening are both false");
				}
			}
		}
		else
		{
			if (bInOpening || bInClosing)
			{
				DebugLog(DEBUG_Door,"Mover::UseControl State Cast<ATrigger>()::Door was moving, trying to stop it.");
				NextSound=PartialStoppedSound;
				MakeGroupStop();
			}
			else
			{
				if (bOpening)
				{
					DebugLog(DEBUG_Door,"Mover::UseControl State Cast<ATrigger>()::Door was sitting open, trying to close.");
					NextSound=ClosingSound;
					GotoState("UseControl","Close");
				}
				else
				{
					if (bClosed)
					{
						DebugLog(DEBUG_Door,"Mover::UseControl State Cast<ATrigger>()::Door was sitting closed, trying to open.");
						if (bOneWayMover && (! moveToA()))
						{
							DebugLog(DEBUG_Door,"Mover::UseControl::Trigger()	OneWayMover trying to open wrong way: don't do anything");
							return;
						}
						NextSound=OpeningSound;
						GotoState("UseControl","Open");
					}
					else
					{
						DebugLog(DEBUG_Warn,"Mover::UseControl::Trigger()	Don't know what to do when all state flags are false");
					}
				}
			}
		}
	}
}
*/

/*
State TriggerLogicControl extends TriggerControl
{
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		SavedTrigger=Other;
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.BeginEvent();
		}
		GotoState("TriggerLogicControl","Open");
	}
	Function UnTrigger(AActor* Other, APawn* EventInstigator)
	{
		SavedTrigger=Other;
		SavedTrigger.BeginEvent();
		GotoState("TriggerLogicControl","Close");
	}
	Function TakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
	{
		Super::TakeDamage(Damage,instigatedBy,HitLocation,Momentum,DamageType);
		if (bDamageTriggered && (float(Damage) >= DamageThreshold))
		{
			Self.UnTrigger(this,instigatedBy);
		}
	}
}
*/

/*
State WasTriggerControl
{
	Function bool SelfTriggered()
	{
		return false;
	}
	Function Reset()
	{
		Global.NetMode();
		SetResetStatus(true);
		GotoState("TriggerControl","Close");
	}
}
*/

/*
State TriggerPound
{
	Function bool SelfTriggered()
	{
		return false;
	}
	Function Reset()
	{
		Global.NetMode();
		if (numTriggerEvents > 0)
		{
			SetResetStatus(true);
			numTriggerEvents=0;
			UnTrigger(nullptr,nullptr);
		}
	}
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		numTriggerEvents ++;
		SavedTrigger=Other;
		Instigator=EventInstigator;
		GotoState("TriggerPound","Open");
	}
	Function UnTrigger(AActor* Other, APawn* EventInstigator)
	{
		numTriggerEvents --;
		if (numTriggerEvents <= 0)
		{
			numTriggerEvents=0;
			SavedTrigger=nullptr;
			Instigator=nullptr;
			GotoState("TriggerPound","Close");
		}
	}
	Function BeginState()
	{
		numTriggerEvents=0;
	}
Begin:
	if (bTriggerOnceOnly)
	{
		Disable("Trigger");
	}
	bClosed=false;
	if (DelayTime > 0)
	{
		bDelaying=true;
		Sleep(DelayTime);
	}
	DoOpen();
	FinishInterpolation();
	Sleep(OtherTime);
	DoClose();
	FinishInterpolation();
	Sleep(StayOpenTime);
	SetResetStatus(false);
	if (bTriggerOnceOnly)
	{
		GotoState("WasTriggerPound");
	}
	if (SavedTrigger != nullptr)
	{
		JL"Open"
;
	}
}
*/

/*
State WasTriggerPound
{
	Function Reset()
	{
		Global.NetMode();
		SetResetStatus(true);
		GotoState("TriggerPound","Open");
	}
}
*/

/*
State TriggerAdvance
{
	Function bool SelfTriggered()
	{
		return false;
	}
	Function Reset()
	{
		Global.NetMode();
		SetResetStatus(true);
		numTriggerEvents=0;
		GotoState("TriggerAdvance","Close");
	}
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		numTriggerEvents ++;
		SavedTrigger=Other;
		Instigator=EventInstigator;
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.BeginEvent();
		}
		SetStoppedPosition(0);
		SetPhysics(PHYS_MovingBrush);
		AmbientSound=MoveAmbientSound;
		if (! bOpening)
		{
			GotoState("TriggerAdvance","Open");
		}
	}
	Function UnTrigger(AActor* Other, APawn* EventInstigator)
	{
		numTriggerEvents --;
		if (numTriggerEvents <= 0)
		{
			AmbientSound=nullptr;
			numTriggerEvents=0;
			SavedTrigger=Other;
			Instigator=EventInstigator;
			if (SavedTrigger != nullptr)
			{
				SavedTrigger.BeginEvent();
			}
			SetStoppedPosition(1);
			SetPhysics(PHYS_None);
		}
	}
	Function BeginState()
	{
		numTriggerEvents=0;
	}
	Function EndState()
	{
		AmbientSound=nullptr;
	}
Begin:
	if (Physics == 0)
	{
		GotoState("TriggerAdvance","None");
	}
	bClosed=false;
	if (DelayTime > 0)
	{
		bDelaying=true;
		Sleep(DelayTime);
	}
	if (Physics == 0)
	{
		GotoState("TriggerAdvance","None");
	}
	SetStoppedPosition(0);
	DoOpen();
	FinishInterpolation();
	FinishedOpening();
	if (SavedTrigger != nullptr)
	{
		SavedTrigger.EndEvent();
	}
	GotoState("WasTriggerAdvance");
	SetStoppedPosition(0);
	SetPhysics(PHYS_MovingBrush);
	DoClose();
	FinishInterpolation();
	FinishedClosing();
	SetResetStatus(false);
}
*/

/*
State WasTriggerAdvance
{
	Function bool SelfTriggered()
	{
		return false;
	}
	Function Reset()
	{
		Global.NetMode();
		SetResetStatus(true);
		GotoState("TriggerAdvance","Close");
	}
}
*/

/*
State BumpButton
{
	Function Bump(AActor* Other)
	{
		if ((BumpType != 2) && (Cast<APawn>(Other) == nullptr))
		{
			return;
		}
		if ((BumpType == 0) && (! Pawn(Other).IsPlayerPawn()))
		{
			return;
		}
		if ((BumpType == 1) && (Other.Mass < float(10)))
		{
			return;
		}
		Global.PawnShadow(Other);
		SavedTrigger=Other;
		Instigator=Pawn(Other);
		Instigator.Controller.WaitForMover(this);
		GotoState("BumpButton","Open");
	}
	Function BeginEvent()
	{
		bSlave=true;
	}
	Function EndEvent()
	{
		bSlave=false;
		Instigator=nullptr;
		GotoState("BumpButton","Close");
	}
Begin:
	if (bTriggerOnceOnly)
	{
		Disable("Trigger");
	}
	bClosed=false;
	Disable("Bump");
	if (DelayTime > 0)
	{
		bDelaying=true;
		Sleep(DelayTime);
	}
	DoOpen();
	FinishInterpolation();
	FinishedOpening();
	if (bTriggerOnceOnly)
	{
		GotoState("WasBumpButton");
	}
	if (bSlave)
	{
	}
	DoClose();
	FinishInterpolation();
	FinishedClosing();
	SetResetStatus(false);
	Enable("Bump");
}
*/

/*
State WasBumpButton
{
	Function Reset()
	{
		Global.NetMode();
		SetResetStatus(true);
		GotoState("BumpButton","Close");
	}
}
*/

/*
State ConstantLoop
{
	Event KeyFrameReached()
	{
		if (bOscillatingLoop)
		{
			if ((KeyNum == 0) || (KeyNum == (NumKeys - 1)))
			{
				(StepDirection *= float(-1));
				MoverLooped();
			}
			(KeyNum += uint8(StepDirection));
			InterpolateTo(KeyNum,MoveTime);
		}
		else
		{
			InterpolateTo(byte((float(byte((KeyNum + 1))) % float(NumKeys))),MoveTime);
			if (KeyNum == 0)
			{
				MoverLooped();
			}
		}
	}
	Function BeginState()
	{
		bOpening=false;
		bDelaying=false;
	}
Begin:
	InterpolateTo(1,MoveTime);
	FinishInterpolation();
	GotoState("ConstantLoop","Running");
}
*/

/*
State LeadInOutLooper
{
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		if (NumKeys < 3)
		{
			Log("LeadInOutLooper detected with <3 movement keys");
			return;
		}
		InterpolateTo(1,MoveTime);
	}
	Event KeyFrameReached()
	{
		if (KeyNum != 0)
		{
			InterpolateTo(2,MoveTime);
			GotoState("LeadInOutLooping");
		}
	}
	Function BeginState()
	{
		bOpening=false;
		bDelaying=false;
	}
}
*/

/*
State LeadInOutLooping
{
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		InterpolateTo(0,MoveTime);
		GotoState("LeadInOutLooper");
	}
	Event KeyFrameReached()
	{
		if (bOscillatingLoop)
		{
			if ((KeyNum == 1) || (KeyNum == (NumKeys - 1)))
			{
				(StepDirection *= float(-1));
				MoverLooped();
			}
			(KeyNum += uint8(StepDirection));
			InterpolateTo(KeyNum,MoveTime);
		}
		else
		{
			KeyNum ++;
			if (KeyNum == NumKeys)
			{
				KeyNum=1;
				MoverLooped();
			}
			InterpolateTo(KeyNum,MoveTime);
		}
	}
}
*/

/*
State RotatingMover
{
	simulated Function BaseStarted()
	{
		AActor* OldBase = nullptr;
		bFixedRotationDir=true;
		OldBase=Base;
		SetPhysics(PHYS_Rotating);
		SetBase(OldBase);
	}
	simulated Function BaseFinished()
	{
		AActor* OldBase = nullptr;
		OldBase=Base;
		SetPhysics(PHYS_None);
		SetBase(OldBase);
		if (bToggleDirection)
		{
			(RotationRate.Yaw *= float(-1));
			(RotationRate.Pitch *= float(-1));
			(RotationRate.Roll *= float(-1));
		}
	}
	simulated Function BeginState()
	{
		SetTimer(0,false);
	}
}
*/

void AMover::BeginPlay()
{
	
	SetReplicates(true);
	GetWorld()->GetTimerManager().SetTimer(THDoor, this, &AMover::RotateDoor, 0.02, true);
	GetWorld()->GetTimerManager().PauseTimer(THDoor);

	AAntiPortalActor* AntiPortalA = nullptr;
	/*
		if (AntiPortalTag != "None")
		{
			ForEach AllActors('AntiPortalActor',AntiPortalA,AntiPortalTag)
			{
				AntiPortals.Num()=AntiPortals.Num() + 1;
				AntiPortals[AntiPortals.Num() - 1]=AntiPortalA;
			}
		}
		if (GetNetMode() != ENetMode::NM_Standalone)
		{
			if (GetNetMode() == ENetMode::NM_Client && bClientAuthoritative)
			{
				SetTimer(4,true);
			}
			else
			{
				SetTimer(1,true);
			}
			if (Role < 4)
			{
				return;
			}
		}
	*/

	Super::BeginPlay();

	RealPosition=GetActorLocation();
	RealRotation=GetActorRotation();
	//bUseControl=InitialState == 'UseControl';
	if (bOneWayMover)
	{
		bTwoWayMover=false;
	}
		
	KeyNum=FMath::Clamp(int32(KeyNum),int32(0),int32(24 - 1));
		
	//PhysAlpha=0;
	StartKeyNum=KeyNum;

	//Move(BasePos + KeyPos[KeyNum] - Location);
	SetActorRotation(RealRotation + KeyRot[KeyNum]);
	if (! bUsePartialSounds)
	{
		PartialOpeningSound=OpeningSound;
		PartialClosingSound=ClosingSound;
		PartialStoppedSound=nullptr;
	}
	Leader=nullptr;
	Follower= nullptr;
}

/*
void AMover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
*/

void AMover::SetKeyPos(int32 Index, FVector V)
{
	KeyPos[Index]=V;
}
void AMover::SetKeyRot(int32 Index, FRotator R)
{
	KeyRot[Index]=R;
}
bool AMover::SelfTriggered()
{
	return true;
}
AActor* AMover::SpecialHandling(APawn* Other)
{
	AActor* A;
	if (myMarker != nullptr)
	{
		A=myMarker->SpecialHandling(Other);
		if (A == nullptr)
		{
			return myMarker;
		}
		return A;
	}
	return this;
}
void AMover::StartInterpolation()
{
	
		//GotoState("None");
		bInterpolating=true;
		//SetPhysics(0);
	
}
void AMover::Timer()
{
	
		/*
		if (Velocity != FVector(0,0,0))
		{
			if (bClientPause)
			{
				bClientPause=false;
			}
			return;
		}
		*/

		//if (GetNetMode() == ENetMode::NM_Client && ! bClientAuthoritative)
		if (GetNetMode() == ENetMode::NM_Client)
		{
			if (ClientUpdate == 0)
			{
				if (bClientPause)
				{
					/*
					if ((FVector(RealPosition - GetActorLocation()).Size) > 3.0f)
					{
						SetActorLocation(RealPosition);
					}
					else
					{
						RealPosition= GetActorLocation();;
					}
					*/
					SetActorRotation(RealRotation);
					bClientPause=false;
				}
				else
				{
					if (RealPosition != GetActorLocation())
					{
						bClientPause=true;
					}
				}
			}
			else
			{
				bClientPause=false;
			}
		}
		else
		{
			if (bCollideActors)
			{
				if (RealRotation != GetActorRotation())
				{
					RealRotation=GetActorRotation();
				}
				if (RealPosition != GetActorLocation())
				{
					RealPosition=GetActorLocation();
				}
			}
		}
	
}
bool AMover::IsDamaged()
{
	return false;
}

float AMover::AdjustMoveTime(float Seconds)
{
	if (BreachActor != nullptr && IsDamaged())
	{
		return Seconds / 8;
	}
	if (GetInstigator() == nullptr)
	{
		return Seconds;
	}
	//if (bMoveFastWhenRun && !Instigator->bIsWalking)
	if (bMoveFastWhenRun && !Cast<AAGP_Pawn>(GetInstigator())->bIsWalking)
	{
		Seconds /= 2;
	}
	if (bMoveSlowWhenLow)
	{
		//if (Instigator->bIsCrouched)
		if (Cast<AAGP_Pawn>(GetInstigator())->bIsCrouched)
		{
			Seconds *= 2;
		}
		else
		{
			//if (Instigator->bIsProne)
			if (Cast<AAGP_Pawn>(GetInstigator())->bIsProne)
			{
				Seconds *= 4;
			}
		}
	}
	return Seconds;
}
void AMover::InterpolateTo(uint8 NewKeyNum, float Seconds)
{
	/*
		AMover* M;
		Seconds=AdjustMoveTime(Seconds);
		ForEach BasedActors('Mover',M)
		{
			M.BaseStarted();
		}
		NewKeyNum=Clamp(NewKeyNum,0,24 - 1);
		if (NewKeyNum == PrevKeyNum && KeyNum != PrevKeyNum)
		{
			PhysAlpha=1 - PhysAlpha;
			OldPos=BasePos + KeyPos[KeyNum];
			OldRot=BaseRot + KeyRot[KeyNum];
		}
		else
		{
			OldPos=Location;
			OldRot=Rotation;
			PhysAlpha=0;
		}
		if (bResetting)
		{
			Seconds=0.005;
		}
		SetPhysics(8);
		bInterpolating=true;
		PrevKeyNum=KeyNum;
		KeyNum=NewKeyNum;
		PhysRate=1 / FMax(Seconds,0.005);
		ClientUpdate ++;
		SimOldPos=OldPos;
		SimOldRotYaw=OldRot.Yaw;
		SimOldRotPitch=OldRot.Pitch;
		SimOldRotRoll=OldRot.Roll;
		SimInterpolate.X=100 * PhysAlpha;
		SimInterpolate.Y=100 * FMax(0.01,PhysRate);
		SimInterpolate.Z=256 * PrevKeyNum + KeyNum;
		NetUpdateTime=GetWorld()->GetTimeSeconds() - 1;
	*/
}
void AMover::SetKeyframe(uint8 NewKeyNum, FVector NewLocation, FRotator NewRotation)
{
	KeyNum=FMath::Clamp(int32(NewKeyNum),int32(0),int32(24 - 1));
	KeyPos[KeyNum]=NewLocation;
	KeyRot[KeyNum]=NewRotation;
}
void AMover::KeyFrameReached()
{
	uint8 OldKeyNum;
	//AMover* M;
	uint8 GotoKey;
	OldKeyNum=PrevKeyNum;
	PrevKeyNum=KeyNum;
	PhysAlpha=0;
	ClientUpdate --;
	GotoKey=255;

	if (KeyNum > 0 && KeyNum < OldKeyNum)
	{
		GotoKey=previousKeyFrame(KeyNum);
	}
	else
	{
		if (KeyNum < NumKeys - 1 && KeyNum > OldKeyNum)
		{
			GotoKey=nextKeyFrame(KeyNum);
		}
	}
	if (GotoKey == 255)
	{
		AmbientSound=nullptr;
		//NetUpdateTime=GetWorld()->GetTimeSeconds() - 1;
		if (bJumpLift && KeyNum == 1)
		{
			FinishNotify();
		}
		/*
		if (ClientUpdate == 0 && GetNetMode() != ENetMode::NM_Client || bClientAuthoritative)
		{
			RealPosition=GetActorLocation();
			RealRotation=GetActorRotation();
			ForEach BasedActors('Mover',M)
			{
				M.BaseFinished();
			}
		}
		*/
	}
	else
	{
		InterpolateTo(GotoKey,MoveTime);
	}
}
USoundBase* AMover::GetNextSound()
{
	if (bTwoWayMover || bOneWayMover)
	{
		return NextSound;
	}
	else
	{
		if (bStopped)
		{
			return nullptr;
		}
		else
		{
			if (bOpening)
			{
				return OpeningSound;
			}
			else
			{
				return ClosingSound;
			}
		}
	}
}

void AMover::FinishNotify()
{
	/*
	AController* C = nullptr;
	for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
	{
		if ((C.Pawn != nullptr) && (C.PendingMover == this))
		{
			C.MoverFinished();
		}
	}
	*/
}

void AMover::FinishedClosing()
{
	if (AskLeader())
	{
		Leader->FinishedClosing();
	}
	else
	{
		ReallyFinishedClosing();
	}
}
void AMover::ReallyFinishedClosing()
{
	if (DoFollower())
	{
		Follower->ReallyFinishedClosing();
	}
	bInClosing=false;
	if (! bEndOfRound)
	{
		UGameplayStatics::SpawnSoundAttached(ClosedSound, RootComponent, NAME_None, FVector(5, 0, 0), EAttachLocation::KeepRelativeOffset, false, (SoundVolume / 255), (SoundPitch / 64), 0, nullptr, nullptr, true);
		//PlaySound(ClosedSound,0,SoundVolume / 255,false,SoundRadius,SoundPitch / 64);
	}
	//TriggerEvent(ClosedEvent,Self,Instigator);
	if (SavedTrigger != nullptr)
	{
		//SavedTrigger->EndEvent();
	}
	SavedTrigger=nullptr;
	SetInstigator(nullptr);

	if (myMarker != nullptr)
	{
		myMarker->MoverClosed();
	}
	bClosed=true;
	FinishNotify();
	//UntriggerEvent(OpeningEvent,Self,Instigator);
}
void AMover::FinishedOpening()
{
	if (AskLeader())
	{
		Leader->FinishedOpening();
	}
	else
	{
		ReallyFinishedOpening();
	}
}
void AMover::ReallyFinishedOpening()
{
	
	if (DoFollower())
	{
		Follower->ReallyFinishedOpening();
	}
	//DebugLog(DEBUG_Door,"Mover::FinishedOpening()	" + this @ bOpening @ bInOpening @ bClosed @ bInClosing @ bStopped);
	bInOpening=false;

	UGameplayStatics::SpawnSoundAttached(OpenedSound, RootComponent, NAME_None, FVector(5, 0, 0), EAttachLocation::KeepRelativeOffset, false, (SoundVolume / 255), (SoundPitch / 64), 0, nullptr, nullptr, true);
	//PlaySound(OpenedSound,0,SoundVolume / 255,false,SoundRadius,SoundPitch / 64);
	//TriggerEvent(Event,Self,Instigator);
	//TriggerEvent(OpenedEvent,Self,Instigator);
	if (myMarker != nullptr)
	{
		myMarker->MoverOpened();
	}
	FinishNotify();
	
}
bool AMover::AskLeader()
{
	if (! bReturnGroupLocked)
	{
		return false;
	}
	else
	{
		return Leader != this;
	}
}
bool AMover::DoFollower()
{
	if (! bReturnGroupLocked)
	{
		return false;
	}
	else
	{
		return Follower != nullptr;
	}
}
void AMover::DoOpen()
{
	//DebugLog(DEBUG_Door,"Mover::DoOpen()");
	if (AskLeader())
	{
		Leader->SetInstigator(GetInstigator());
		Leader->DoOpen();
	}
	else
	{
		ReallyOpen();
	}
}
void AMover::ReallyOpen()
{
	
		int32 GotoKeyFrame;
		//DebugLog(DEBUG_Door,"Mover::ReallyOpen()");
		if (DoFollower())
		{
			Follower->SetInstigator(GetInstigator());
			Follower->ReallyOpen();
		}
		bClosed=false;
		//DebugLog(DEBUG_Door,"Mover::DoOpen()	" + this @ bOpening @ bInOpening @ bClosed @ bInClosing @ bStopped);
		if (bTwoWayMover)
		{
			if (! bOpening && ! bInOpening && ! bInClosing)
			{
				bGotoA=moveToA();
				//DebugLog(DEBUG_Door,"Mover::DoOpen()	Mover is closed, getting new bGotoA " + bGotoA);
			}
			if (bGotoA)
			{
				//DebugLog(DEBUG_Door,"Mover::DoOpen()	Opening 1");
				GotoKeyFrame=1;
			}
			else
			{
				//DebugLog(DEBUG_Door,"Mover::DoOpen()	Opening 2");
				GotoKeyFrame=TwoWayKeyB;
			}
		}
		else
		{
			//DebugLog(DEBUG_Door,"Mover::DoOpen() Set gotoKeyFrame to 1.");
			GotoKeyFrame=1;
		}
		bInOpening=true;
		bInClosing=false;
		bStopped=false;
		bOpening=true;
		bDelaying=false;
		//DebugLog(DEBUG_Door,"Mover::DoOpen() Interpolating to KeyFrame " + GotoKeyFrame + " over time: " + MoveTime);
		InterpolateTo(GotoKeyFrame,MoveTime);
		MakeNoise(1);

		UGameplayStatics::SpawnSoundAttached(GetNextSound(), RootComponent, NAME_None, FVector(5, 0, 0), EAttachLocation::KeepRelativeOffset,false, (SoundVolume /255),(SoundPitch/64),0, nullptr, nullptr,true);
		//PlaySound(GetNextSound(),0,SoundVolume / 255,false,SoundRadius,SoundPitch / 64);

		/*
		//static class UAudioComponent* SpawnSoundAttached(
		USoundBase* Sound
		USceneComponent* AttachToComponent
		FName AttachPointName
		FVector Location, 
		EAttachLocation::Type LocationType = EAttachLocation::KeepRelativeOffset, 
		bool bStopWhenAttachedToDestroyed = false,
		float VolumeMultiplier = 1.f
		float PitchMultiplier = 1.f
		float StartTime = 0.f
		USoundAttenuation* AttenuationSettings = nullptr, USoundConcurrency* ConcurrencySettings = nullptr, bool bAutoDestroy = true)
		*/

		AmbientSound=MoveAmbientSound;
		//TriggerEvent(OpeningEvent,Self,Instigator);
	
}

/* =================================================================================== *
 * AGP function moveToA
 *	return a bool that indicates which side of the Mover the instigator is on
 *
 * input:
 * output:	true	if on side B
 *			false	if on side A
 * effects:
 * notes:
 * last modified by: cmb
 * =================================================================================== */

bool AMover::moveToA()
{
	FVector Test;
	AActor* TestActor;
	if (BreachActor != nullptr)
	{
		TestActor=BreachActor;
	}
	else
	{
		TestActor=GetInstigator();
	}
	if (TestActor != nullptr)
	{
		Test=GetActorLocation() - TestActor->GetActorLocation();
	}
	
	AActor* A = this;
	AActor* B = GetInstigator();
	if (A != nullptr && B != nullptr)
	{
		FVector aPosRelativeToB = B->GetActorTransform().InverseTransformPosition(A->GetActorLocation());
		return (aPosRelativeToB.Y > 0);
	}
	else
	{
		return false;
	}
}
void AMover::DoClose()
{
	//DebugLog(DEBUG_Door,"Mover::DoClose()");
	if (AskLeader())
	{
		Leader->DoClose();
	}
	else
	{
		ReallyDoClose();
	}
}
void AMover::ReallyDoClose()
{
	if (DoFollower())
	{
		Follower->ReallyDoClose();
	}
	//DebugLog(DEBUG_Door,"Mover::ReallyDoClose()	" + this @ bOpening @ bInOpening @ bClosed @ bInClosing @ bStopped);
	bStopped=false;
	bInClosing=true;
	bInOpening=false;
	bOpening=false;
	bDelaying=false;
	//DebugLog(DEBUG_Door,"Closing to " + FMath::Max(0,KeyNum - 1));
	InterpolateTo(previousKeyFrame(KeyNum),MoveTime);
	if (! bEndOfRound)
	{
		MakeNoise(1);
		UGameplayStatics::SpawnSoundAttached(GetNextSound(), RootComponent, NAME_None, FVector(5, 0, 0), EAttachLocation::KeepRelativeOffset, false, (SoundVolume / 255), (SoundPitch / 64), 0, nullptr, nullptr, true);
		//PlaySound(GetNextSound(),0,SoundVolume / 255,false,SoundRadius,SoundPitch / 64);
	}
	//UntriggerEvent(Event,Self,Instigator);
	AmbientSound=MoveAmbientSound;
	//DebugLog(DEBUG_Door,"Mover::DoClose() triggering Event " + ClosingEvent);
	//TriggerEvent(ClosingEvent,Self,Instigator);
}
uint8 AMover::previousKeyFrame(uint8 ThisKey)
{
	if (bTwoWayMover && ThisKey == TwoWayKeyB)
	{
		return 0;
	}
	return FMath::Max(int32(0),int32(ThisKey - 1));
}
uint8 AMover::nextKeyFrame(uint8 ThisKey)
{
	if (ThisKey >= NumKeys - 1 || bTwoWayMover && ThisKey == TwoWayKeyB - 1)
	{
		return 255;
	}
	return ThisKey + 1;
}

void AMover::PostBeginPlay()
{
	
	//AMover* M;
	//Super::PostBeginPlay();
	if (GetLocalRole() == ENetRole::ROLE_MAX)
	{
		InitialKeyNum=KeyNum;
		InitialLockingStyle=LockingStyle;
		resetLockingStyle=LockingStyle;
		InitialMoverEncroachType=MoverEncroachType;
	}
	RealRotation=GetActorRotation();
	RealPosition=GetActorLocation();
	Backup_InitialState=InitialState;
	//BACKUP_bHidden=bHidden;
	if (! bSlave)
	{
		/*
		ForEach DynamicActors('Mover',M,Tag)
		{
			if (M.bSlave)
			{
				M.GotoState("None");
				M.SetBase(this);
			}
		}
		*/
	}
	if (Leader == nullptr)
	{
		Leader=this;
		/*
		ForEach DynamicActors('Mover',M)
		{
			if (M != this && M.ReturnGroup == ReturnGroup && ReturnGroup != "None")
			{
				M.Leader=Self;
				M.Follower=Follower;
				Follower=M;
				Follower.bReturnGroupLocked=bReturnGroupLocked;
			}
		}
		*/
	}
}
void AMover::Reset()
{
	
	//DebugLog(DEBUG_Door,"Mover::Reset()	Resetting " + this + " to " + InitialKeyNum);
	InterpolateTo(InitialKeyNum,0);
	bOpening     = GetDefault<AMover>()->bOpening;
	bClosed      = GetDefault<AMover>()->bClosed;
	bDelaying    = GetDefault<AMover>()->bDelaying;
	bClientPause = GetDefault<AMover>()->bClientPause;
	bPlayerOnly  = GetDefault<AMover>()->bPlayerOnly;
	bInOpening   = GetDefault<AMover>()->bInOpening;
	bInClosing   = GetDefault<AMover>()->bInClosing;
	bStopped     = GetDefault<AMover>()->bStopped;
	bGotoA       = GetDefault<AMover>()->bGotoA;
	LockingStyle=resetLockingStyle;
	InitialLockingStyle=resetLockingStyle;
	MoverEncroachType=InitialMoverEncroachType;
	BreachActor=nullptr;
	Super::Reset();
}
void AMover::SetResetStatus(bool bNewStatus)
{
	//NetUpdateTime=GetWorld()->GetTimeSeconds() - 1;
	//bHidden=BACKUP_bHidden;
	bResetting=bNewStatus;
	if (Follower != nullptr)
	{
		Follower->SetResetStatus(bNewStatus);
	}
}
void AMover::MakeGroupStop()
{
	if (AskLeader())
	{
		Leader->MakeGroupStop();
	}
	else
	{
		Leader->ReallyMakeGroupStop();
	}
}
void AMover::ReallyMakeGroupStop()
{
		SimInterpolate.Y=0;
		bInterpolating=false;
		//NetUpdateTime=GetWorld()->GetTimeSeconds() - 1;
		bStopped=true;
		AmbientSound=nullptr;
		//GotoState(,"None");
		if (! bEndOfRound)
		{
			UGameplayStatics::SpawnSoundAttached(GetNextSound(), RootComponent, NAME_None, FVector(5, 0, 0), EAttachLocation::KeepRelativeOffset, false, (SoundVolume / 255), (SoundPitch / 64), 0, nullptr, nullptr, true);
			//PlaySound(GetNextSound(),0,SoundVolume / 255,false,SoundRadius,SoundPitch / 64);
		}
		if (Follower != nullptr)
		{
			Follower->ReallyMakeGroupStop();
		}
}
void AMover::MakeGroupReturn()
{
	if (AskLeader())
	{
		Leader->MakeGroupReturn();
	}
	else
	{
		Leader->ReallyMakeGroupReturn();
	}
}
void AMover::ReallyMakeGroupReturn()
{
	bInterpolating=false;
	//NetUpdateTime=GetWorld()->GetTimeSeconds() - 1;
	AmbientSound=nullptr;
	if (KeyNum < PrevKeyNum)
	{
		//GotoState(,'Open');
	}
	else
	{
		//GotoState(,'Close');
	}
	if (Follower != nullptr)
	{
		Follower->ReallyMakeGroupReturn();
	}
}
bool AMover::EncroachingOn(AActor* Other)
{
	/*
		APawn* p;
		if(Cast<AAuxCollisionCylinder>(Other))
		{
			Other=Other->GetOwner();
		}
		if (Other == nullptr)
		{
			return false;
		}
		if (Cast<APawn>(Other) != nullptr && Cast<APawn>(Other)->GetController == nullptr || Other->IsA(ADecoration::StaticClass()))
		{
			Other.TakeDamage(10000,None,Other->GetActorLocation(),FVector(0,0,0),'Crushed');
			return false;
		}
		if (Other->IsA(APickup::StaticClass()))
		{
			if (! Other.bAlwaysRelevant && Other.Owner == nullptr && Cast<APickup>(Other).bDestroyOnMoverEncroach)
			{
				Other->Destroy();
			}
			return false;
		}
		if (Cast<AFragment>(Other) || Cast<AGib>(Other) || Cast<AProjectile>(Other)))
		{
			Other->Destroy();
			return false;
		}
		if (EncroachDamage != 0)
		{
			Other->TakeDamage(EncroachDamage,Instigator,Other->GetActorLocation(),FVector(0,0,0),'Crushed');
		}
		p=Cast<APawn>(Other);
		if (p != nullptr && p->GetController() != nullptr && Cast<AHumanController>(p)->IsPlayerPawn())
		{
			if (PlayerBumpEvent != NAME_None)
			{
				Bump(Other);
			}
			if (p != nullptr && p.Controller != nullptr && p.Base != this && Cast<AHumanController>(p->GetController())->PendingMover == this)
			{
				p.Controller.UnderLift(this);
			}
		}
		if (Leader == nullptr)
		{
			Leader=this;
		}
		if (MoverEncroachType == EMoverEncroachType::ME_StopWhenEncroach)
		{
			Leader->MakeGroupStop();
			return true;
		}
		else
		{
			if (MoverEncroachType == 1)
			{
				Leader->MakeGroupReturn();
				if (Cast<APawn>(Other))
				{
					Cast<APawn>(Other)->PlayMoverHitSound();
				}
				return true;
			}
			else
			{
				if (MoverEncroachType == EMoverEncroachType::ME_CrushWhenEncroach)
				{
					Cast<AHumanController>(Other)->KilledBy(GetInstigator());
					return false;
				}
				else
				{
					if (MoverEncroachType == EMoverEncroachType::ME_IgnoreWhenEncroach)
					{
						return false;
					}
				}
			}
		}
	*/
	return false;    //FAKE   /ELIZ
}
bool AMover::UseOneWayLock(APawn* TestPawn)
{
	if (LockingSide != ELockingSide::SIDE_Both)
	{
		BreachActor=TestPawn;
		if (LockingSide == ELockingSide::SIDE_A && moveToA())
		{
			return true;
		}
		else
		{
			if (LockingSide == ELockingSide::SIDE_B && ! moveToA())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}
bool AMover::UsedBy(APawn* User)
{
	if (bUseControl)
	{
		if (bBreachable || bDamageable && DamageHealth < 0)
		{
			return false;
		}
		if (KeyNum != GetDefault<AMover>()->KeyNum)
		{
			LockingStyle=ELockingStyle::LS_Any;
		}
		else
		{
			LockingStyle=InitialLockingStyle;
		}
		if (LockingStyle == ELockingStyle::LS_LockedForAll)
		{
			UGameplayStatics::SpawnSoundAttached(LockedSound, RootComponent, NAME_None, FVector(5, 0, 0), EAttachLocation::KeepRelativeOffset, false, (SoundVolume / 255), (SoundPitch / 64), 0, nullptr, nullptr, true);
			//PlaySound(LockedSound);
			return false;
		}
		if (LockingStyle == ELockingStyle::LS_Damaged)
		{
			return false;
		}
		else
		{
			if (LockingStyle == ELockingStyle::LS_TeamZero && Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->IsOnTeam(User->GetController(), 0))
			{
				if (UseOneWayLock(User))
				{
					//Trigger(User.Controller,User);
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (LockingStyle == ELockingStyle::LS_TeamOne && Cast<AGameInfo>(UGameplayStatics::GetGameMode(GetWorld()))->IsOnTeam(User->GetController(), 1))
				{
					if (UseOneWayLock(User))
					{
						//Trigger(User.Controller,User);
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					if (LockingStyle == ELockingStyle::LS_Any)
					{
						if (UseOneWayLock(User))
						{
							//Trigger(User.Controller,User);
							return true;
						}
						else
						{
							return false;
						}
					}
				}
			}
		}
	}
	UGameplayStatics::SpawnSoundAttached(LockedSound, RootComponent, NAME_None, FVector(5, 0, 0), EAttachLocation::KeepRelativeOffset, false, (SoundVolume / 255), (SoundPitch / 64), 0, nullptr, nullptr, true);
	//PlaySound(LockedSound);
	return false;
}
void AMover::Bump(AActor* Other)
{
	
	APawn* p;
	p=Cast<APawn>(Other);

	if (bUseTriggered && p != nullptr && ! Cast<AAGP_Pawn>(p)->IsHumanControlled() && Cast<AAGP_Pawn>(p)->IsPlayerPawn() && ! bDelaying && ! bOpening)
	{
		//Trigger(p,p);
		Cast<AHumanController>(Cast<AAGP_Pawn>(p)->GetController())->WaitForMover(this);
	}
	if (BumpType != EBumpType::BT_AnyBump && p == nullptr)
	{
		return;
	}
	if (BumpType == EBumpType::BT_PlayerBump && !Cast<AAGP_Pawn>(p)->IsPlayerPawn())
	{
		return;
	}
	//TriggerEvent(BumpEvent,this,p);
	if (p != nullptr && Cast<AAGP_Pawn>(p)->IsPlayerPawn())
	{
		//TriggerEvent(PlayerBumpEvent,Self,p);
	}
	
}
void AMover::HandleBreachInfo(AActor* NewBreachActor)
{
	BreachActor=NewBreachActor;
	bSideADamagedMesh=moveToA();
	bGotoA=bSideADamagedMesh;
}
void AMover::HandleBreachDamage(int32 NDamage)
{
	
		if (bDamageable || bBreachable && DamageHealth >= 0)
		{
			DamageHealth -= NDamage;
			if (DamageHealth <= 0)
			{
				bDisplayTargetingInfo=false;
				if (DamagedMesh == nullptr)
				{
					if (bSideADamagedMesh)
					{
						if (StaticMesh)
						{
							StaticMesh->SetStaticMesh(SideADamagedMesh);
							//SetStaticMesh(SideADamagedMesh);
						}
					}
					else
					{
						if (StaticMesh)
						{
							StaticMesh->SetStaticMesh(SideBDamagedMesh);
							//SetStaticMesh(SideBDamagedMesh);
						}
					}
				}
				else
				{
					if (StaticMesh)
					{
						StaticMesh->SetStaticMesh(DamagedMesh);
						//SetStaticMesh(DamagedMesh);
					}
					
				}
				//ClientsVerifyMesh(0);
				//DebugLog(DEBUG_Break,"DecoMesh::TakeDamage()	Playing " + DamageSound);
				//TriggerEvent(DamageEvent,Self,Instigator);
				
				UGameplayStatics::SpawnSoundAttached(DamageSound, RootComponent, NAME_None, FVector(5, 0, 0), EAttachLocation::KeepRelativeOffset, false, (SoundVolume / 255), (SoundPitch / 64), 0, nullptr, nullptr, true);
				//PlaySound(DamageSound);
			}
		}
	
}
/*
void AMover::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, AMaterial HitMaterial)
{
	TakeDamage(Damage,instigatedBy,HitLocation,Momentum,DamageType);
	if (bDamageTriggered && ! bBreachable && Damage >= DamageThreshold)
	{
		if (Cast<AAIController>(instigatedBy.Controller) != nullptr && instigatedBy.Controller.Focus == this)
		{
			instigatedBy.Controller.StopFiring();
		}
		Self.Trigger(this,instigatedBy);
		if (Cast<AAIController>(instigatedBy.Controller) != nullptr && instigatedBy.Controller.Target == this)
		{
			instigatedBy.Controller.StopFiring();
		}
	}
	else
	{
		if (bBreachable && IsDamaged() && ShouldTakeDamage(DamageType) && LockingStyle != 3)
		{
			MoverBreached(ResponsibleActor,instigatedBy);
		}
	}
}
*/
void AMover::DisableTrigger()
{
}
void AMover::EnableTrigger()
{
}
void AMover::MoverBreached(AActor* ResponsibleActor, APawn* instigatedBy)
{
	if (! Cast<AMover>(ResponsibleActor))
	{
		BreachActor=ResponsibleActor;
	}
	bStopped=false;
	bInClosing=false;
	bInOpening=false;
	bOpening=false;
	bClosed=true;
	KeyNum=0;
	MoverEncroachType=EMoverEncroachType::ME_CrushWhenEncroach;
	bBreaching=true;
	//Trigger(this,instigatedBy);
	bBreaching=false;
	LockingStyle=ELockingStyle::LS_Damaged;
	bBreachable=false;
}
bool AMover::DestroyAttachedDoorBreachers()
{
	bool bBreachersDestroyed;
	//APickup* PickupIterator;
	bBreachersDestroyed=false;

	/*
	ForEach RadiusActors('Pickup',PickupIterator,150)
	{
		if (PickupIterator->IsA(APickupT_DoorBreacher_Demo::StaticClass()))
		{
			PickupIterator.Destroy();
			LockingStyle=0;
			bBreachable=false;
			bBreachersDestroyed=true;
		}
	}
	*/
	return bBreachersDestroyed;
}
bool AMover::ExistAttachedDoorBreachers()
{
	/*
	APickup* PickupIterator;
	ForEach RadiusActors('Pickup',PickupIterator,150)
	{
		if (PickupIterator->IsA(APickupT_DoorBreacher_Demo::StaticClass()))
		{
			return true;
		}
	}
	*/
	return false;
	
}
void AMover::SetStoppedPosition(uint8 NewPos)
{
	//NetUpdateTime=GetWorld()->GetTimeSeconds() - 1;
	StoppedPosition=NewPos;
}
void AMover::MoverLooped()
{
	//TriggerEvent(LoopEvent,Self,Instigator);
	if (LoopSound != nullptr)
	{
		UGameplayStatics::SpawnSoundAttached(LoopSound, RootComponent, NAME_None, FVector(5, 0, 0), EAttachLocation::KeepRelativeOffset, false, (SoundVolume / 255), (SoundPitch / 64), 0, nullptr, nullptr, true);
		//PlaySound(LoopSound,0,SoundVolume / 255,false,SoundRadius,SoundPitch / 64);
	}
}
void AMover::BaseStarted()
{
}
void AMover::BaseFinished()
{
}
void AMover::UpdatePrecacheStaticMeshes()
{
	if (DrawType == EDrawType::DT_StaticMesh && StaticMesh != nullptr)
	{
		//Level.AddPrecacheStaticMesh(StaticMesh);
	}
}

void AMover::RotateDoor()
{
	FRotator TargetRotation = FRotator::ZeroRotator;
	if (bDoorOpen)
	{
		if (KeyRot.Num() >= 2)
		{
			if (bTwoWayMover)
			{
				bool Side_A = moveToA();
				if (Side_A)
				{
					TargetRotation = (RealRotation + KeyRot[2]);
					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("SideB")));
				}
				else
				{
					TargetRotation = (RealRotation + KeyRot[1]);
					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("SideA")));
				}
			}
			else
			{
				TargetRotation = (RealRotation + KeyRot[1]);
			}
		}
	}
	else
	{
		if (KeyRot.Num() >= 2)
		{
			TargetRotation = (RealRotation+KeyRot[0]);
		}
	}
	FRotator CurrentRotation = this->GetActorRotation();
	float InterpSpeed = 600.0f/ MoveTime;
	FRotator NewRotator = UKismetMathLibrary::RInterpTo_Constant (CurrentRotation, TargetRotation, GetWorld()->GetDeltaSeconds(), InterpSpeed);
	this->SetActorRotation(NewRotator);
	if (NewRotator.Equals(TargetRotation, 0.05f))
	{
		GetWorld()->GetTimerManager().PauseTimer(THDoor);
	}
}

void AMover::OnRep_ToggleDoor()
{
	GetWorld()->GetTimerManager().UnPauseTimer(THDoor);
}

void AMover::ToggleDoor()
{
	if (GetLocalRole() == ROLE_Authority)
	{

		bDoorOpen = !bDoorOpen;
		OnRep_ToggleDoor();
	}
}

void AMover::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AMover, bDoorOpen);
 }
