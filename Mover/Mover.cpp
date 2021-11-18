// All the original content belonged to the US 


#include "Mover.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Info/GameInfo/GameInfo.h"
#include "TimerManager.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AMover::AMover()
{
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

void AMover::BeginPlay()
{
	
	SetReplicates(true);
	GetWorld()->GetTimerManager().SetTimer(THDoor, this, &AMover::RotateDoor, 0.02, true);
	GetWorld()->GetTimerManager().PauseTimer(THDoor);


	/*
		local AntiPortalActor AntiPortalA;
		if (AntiPortalTag != 'None')
		{
			ForEach AllActors('AntiPortalActor',AntiPortalA,AntiPortalTag)
			{
				AntiPortals.Length=AntiPortals.Length + 1;
				AntiPortals[AntiPortals.Length - 1]=AntiPortalA;
			}
		}
		if (GetNetMode() != ENetMode::NM_Standalone)
		{
			if (GetNetMode() == ENetMode::NM_Client && bClientAuthoritative)
			{
				SetTimer(4,True);
			}
			else
			{
				SetTimer(1,True);
			}
			if (Role < 4)
			{
				Return;
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
// Called every frame
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
	
		//GotoState('None');
		bInterpolating=true;
		//SetPhysics(0);
	
}
void AMover::Timer()
{
	
		/*
		if (Velocity != vect(0 0 0))
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
		bInterpolating=True;
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
		local Controller C;
		C=Level.ControllerList;
		if (C != None)
		{
			if (C.Pawn != None && C.PendingMover == Self)
			{
				C.MoverFinished();
			}
			C=C.nextController;
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
		//PlaySound(ClosedSound,0,SoundVolume / 255,False,SoundRadius,SoundPitch / 64);
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
	//DebugLog(DEBUG_Door,"Mover::FinishedOpening()	" $ Self @ bOpening @ bInOpening @ bClosed @ bInClosing @ bStopped);
	bInOpening=false;

	UGameplayStatics::SpawnSoundAttached(OpenedSound, RootComponent, NAME_None, FVector(5, 0, 0), EAttachLocation::KeepRelativeOffset, false, (SoundVolume / 255), (SoundPitch / 64), 0, nullptr, nullptr, true);
	//PlaySound(OpenedSound,0,SoundVolume / 255,False,SoundRadius,SoundPitch / 64);
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
		//DebugLog(DEBUG_Door,"Mover::DoOpen()	" $ Self @ bOpening @ bInOpening @ bClosed @ bInClosing @ bStopped);
		if (bTwoWayMover)
		{
			if (! bOpening && ! bInOpening && ! bInClosing)
			{
				bGotoA=moveToA();
				//DebugLog(DEBUG_Door,"Mover::DoOpen()	Mover is closed, getting new bGotoA " $ bGotoA);
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
		//DebugLog(DEBUG_Door,"Mover::DoOpen() Interpolating to KeyFrame " $ GotoKeyFrame $ " over time: " $ MoveTime);
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
 *	Return a bool that indicates which side of the Mover the instigator is on
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
	//DebugLog(DEBUG_Door,"Mover::ReallyDoClose()	" $ Self @ bOpening @ bInOpening @ bClosed @ bInClosing @ bStopped);
	bStopped=false;
	bInClosing=true;
	bInOpening=false;
	bOpening=false;
	bDelaying=false;
	//DebugLog(DEBUG_Door,"Closing to " $ Max(0,KeyNum - 1));
	InterpolateTo(previousKeyFrame(KeyNum),MoveTime);
	if (! bEndOfRound)
	{
		MakeNoise(1);
		UGameplayStatics::SpawnSoundAttached(GetNextSound(), RootComponent, NAME_None, FVector(5, 0, 0), EAttachLocation::KeepRelativeOffset, false, (SoundVolume / 255), (SoundPitch / 64), 0, nullptr, nullptr, true);
		//PlaySound(GetNextSound(),0,SoundVolume / 255,False,SoundRadius,SoundPitch / 64);
	}
	//UntriggerEvent(Event,Self,Instigator);
	AmbientSound=MoveAmbientSound;
	//DebugLog(DEBUG_Door,"Mover::DoClose() triggering Event " $ ClosingEvent);
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
				M.GotoState('None');
				M.SetBase(Self);
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
			if (M != Self && M.ReturnGroup == ReturnGroup && ReturnGroup != 'None')
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
	
	//DebugLog(DEBUG_Door,"Mover::Reset()	Resetting " $ Self $ " to " $ InitialKeyNum);
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
		//GotoState(,'None');
		if (! bEndOfRound)
		{
			UGameplayStatics::SpawnSoundAttached(GetNextSound(), RootComponent, NAME_None, FVector(5, 0, 0), EAttachLocation::KeepRelativeOffset, false, (SoundVolume / 255), (SoundPitch / 64), 0, nullptr, nullptr, true);
			//PlaySound(GetNextSound(),0,SoundVolume / 255,False,SoundRadius,SoundPitch / 64);
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
		if (Cast<APawn>(Other) != nullptr && Cast<APawn>(Other)->GetController == nullptr || Other.IsA('Decoration'))
		{
			Other.TakeDamage(10000,None,Other.Location,vect(0 0 0),'Crushed');
			return false;
		}
		if (Other.IsA('Pickup'))
		{
			if (! Other.bAlwaysRelevant && Other.Owner == None && Pickup(Other).bDestroyOnMoverEncroach)
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
			Other->TakeDamage(EncroachDamage,Instigator,Other.Location,vect(0 0 0),'Crushed');
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
				p.Controller.UnderLift(Self);
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
				//DebugLog(DEBUG_Break,"DecoMesh::TakeDamage()	Playing " $ DamageSound);
				//TriggerEvent(DamageEvent,Self,Instigator);
				
				UGameplayStatics::SpawnSoundAttached(DamageSound, RootComponent, NAME_None, FVector(5, 0, 0), EAttachLocation::KeepRelativeOffset, false, (SoundVolume / 255), (SoundPitch / 64), 0, nullptr, nullptr, true);
				//PlaySound(DamageSound);
			}
		}
	
}
/*
void AMover::TakeDamage (int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, AMaterial HitMaterial)
{
	TakeDamage(Damage,instigatedBy,HitLocation,Momentum,DamageType);
	if (bDamageTriggered && ! bBreachable && Damage >= DamageThreshold)
	{
		if (AIController(instigatedBy.Controller) != None && instigatedBy.Controller.Focus == Self)
		{
			instigatedBy.Controller.StopFiring();
		}
		Self.Trigger(Self,instigatedBy);
		if (AIController(instigatedBy.Controller) != None && instigatedBy.Controller.Target == Self)
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
	//Trigger(Self,instigatedBy);
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
		if (PickupIterator.IsA('PickupT_DoorBreacher_Demo'))
		{
			PickupIterator.Destroy();
			LockingStyle=0;
			bBreachable=False;
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
		if (PickupIterator.IsA('PickupT_DoorBreacher_Demo'))
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
		//PlaySound(LoopSound,0,SoundVolume / 255,False,SoundRadius,SoundPitch / 64);
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
