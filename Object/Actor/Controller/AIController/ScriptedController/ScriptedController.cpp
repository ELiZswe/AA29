// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/ScriptedController/ScriptedController.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedSequence.h"
#include "AA29/Object/ScriptedAction/Action_PLAYANIM/Action_PLAYANIM.h"
#include "AA29/Object/ScriptedAction/LatentScriptedAction/LatentScriptedAction.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"
#include "Engine/Canvas.h"

AScriptedController::AScriptedController()
{
	bUseScriptFacing = true;
	IterationSectionStart = -1;
}

/*
State Scripting
{
	Function DisplayDebug(UCanvas* Canvas, float& YL, float& YPos)
	{
		Super::DisplayDebug(Canvas,YL,YPos);
		Canvas.DrawText("AIScript " + FString::FromInt(SequenceScript) + " ActionNum " + FString::FromInt(ActionNum),false);
		(YPos += YL);
		Canvas.SetPos(4,YPos);
		CurrentAction->DisplayDebug(Canvas,YL,YPos);
	}
	Function UnPossess()
	{
		GetPawn()->UnPossessed();
		if ((GetPawn() != nullptr) && (PendingController != nullptr))
		{
			PendingController.bStasis=false;
			PendingController.Possess(Pawn);
		}
		GetPawn()=nullptr;
		if (! bChangingPawns)
		{
			Destroy();
		}
	}
	Function LeaveScripting()
	{
		UnPossess();
	}
	Function InitForNextAction()
	{
		SequenceScript.SetActions(this);
		if (CurrentAction == nullptr)
		{
			LeaveScripting();
			return;
		}
		MyScript=SequenceScript;
		if (CurrentAnimation == nullptr)
		{
			ClearAnimation();
		}
	}
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		if (CurrentAction->CompleteWhenTriggered())
		{
			CompleteAction();
		}
	}
	Function Timer()
	{
		if (CurrentAction->WaitForPlayer() && CheckIfNearPlayer(CurrentAction->GetDistance()))
		{
			CompleteAction();
		}
		else
		{
			if (CurrentAction->CompleteWhenTimer())
			{
				CompleteAction();
			}
		}
	}
	Function AnimEnd(int32 Channel)
	{
		if (CurrentAction->CompleteOnAnim(Channel))
		{
			CompleteAction();
			return;
		}
		if (Channel == 0)
		{
			if ((CurrentAnimation == nullptr) || (! CurrentAnimation.PawnPlayBaseAnim(this,false)))
			{
				ClearAnimation();
			}
		}
		else
		{
			GetPawn()->AnimEnd(Channel);
		}
	}
	Function LIPSincAnimEnd()
	{
		if (CurrentAction->CompleteOnLIPSincAnim())
		{
			CompleteAction();
			return;
		}
		else
		{
			GetPawn()->LIPSincAnimEnd();
		}
	}
	Function CompleteAction()
	{
		CurrentAction->ActionCompleted();
		ActionNum ++;
		ChangeState("Scripting","Begin");
	}
	Function SetMoveTarget()
	{
		AActor* NextMoveTarget = nullptr;
		Focus=ScriptedFocus;
		NextMoveTarget=CurrentAction->GetMoveTargetFor(this);
		if (NextMoveTarget == nullptr)
		{
			ChangeState("Broken");
			return;
		}
		if (Focus == nullptr)
		{
			Focus=NextMoveTarget;
		}
		MoveTarget=NextMoveTarget;
		if (! actorReachable(MoveTarget))
		{
			MoveTarget=FindPathToward(MoveTarget,false);
			if (MoveTarget == nullptr)
			{
				AbortScript();
				return;
			}
			if (Focus == NextMoveTarget)
			{
				Focus=MoveTarget;
			}
		}
	}
	Function AbortScript()
	{
		LeaveScripting();
	}
	Function bool WeaponFireAgain(float RefireRate, bool bFinishedFire)
	{
		if (bFineWeaponControl)
		{
			return true;
		}
		if (Pawn.bIgnorePlayFiring)
		{
			GetPawn()->bIgnorePlayFiring=false;
			return false;
		}
		if (NumShots < 0)
		{
			bShootTarget=false;
			bShootSpray=false;
			StopFiring();
			return false;
		}
		if ((bShootTarget && (ScriptedFocus != nullptr)) && (! ScriptedFocus.bDeleteMe))
		{
			Target=ScriptedFocus;
			if (((! bShootSpray) && ((Pawn.Weapon.RefireRate() < 0.99) && (! GetPawn()->Weapon.CanAttack(Target)))) || (! GetPawn()->Weapon.BotFire(bFinishedFire,FiringMode)))
			{
				Enable("Tick");
				bPendingShoot=true;
				return false;
			}
			if (NumShots > 0)
			{
				NumShots --;
				if (NumShots == 0)
				{
					NumShots=-1;
				}
			}
			return true;
		}
		StopFiring();
		return false;
	}
	Function Tick(float DeltaTime)
	{
		if (bPendingShoot)
		{
			bPendingShoot=false;
			MayShootTarget();
		}
		if ((! bPendingShoot) && ((CurrentAction == nullptr) || (! CurrentAction->StillTicking(this,DeltaTime))))
		{
			Disable("Tick");
		}
	}
	Function MayShootAtEnemy()
	{
	}
	Function MayShootTarget()
	{
		WeaponFireAgain(0,false);
	}
	Function EndState()
	{
		bUseScriptFacing=true;
		bFakeShot=false;
	}
Begin:
	InitForNextAction();
	if (bBroken)
	{
		ChangeState("Broken");
	}
	if (CurrentAction->TickedAction())
	{
		Enable("Tick");
	}
	if (! bFineWeaponControl)
	{
		if (! bShootTarget)
		{
			bFire=0;
			bAltFire=0;
		}
		else
		{
			GetPawn()->Weapon.RateSelf();
			if (bShootSpray)
			{
				MayShootTarget();
			}
		}
	}
	if (CurrentAction->MoveToGoal())
	{
		GetPawn()->SetMovementPhysics();
		WaitForLanding();
		SetMoveTarget();
		MayShootTarget();
		if ((MoveTarget != nullptr) && (MoveTarget != Pawn))
		{
			MoveToward(MoveTarget,Focus,,,Pawn.bIsWalking);
			if ((MoveTarget != CurrentAction->GetMoveTargetFor(this)) || (! GetPawn()->ReachedDestination(CurrentAction->GetMoveTargetFor(this))))
			{
				JL"KeepMoving"
;
			}
		}
		CompleteAction();
	}
	else
	{
		if (CurrentAction->TurnToGoal())
		{
			GetPawn()->SetMovementPhysics();
			Focus=CurrentAction->GetMoveTargetFor(this);
			if (Focus == nullptr)
			{
				FocalPoint=(Pawn->GetActorLocation() + (float(1000) *  Vector(SequenceScript.Rotation)));
			}
			FinishRotation();
			CompleteAction();
		}
		else
		{
			GetPawn()->Acceleration=FVector(0,0,0);
			Focus=ScriptedFocus;
			if (! bUseScriptFacing)
			{
				FocalPoint=(Pawn->GetActorLocation() + (float(1000) *  Vector(Pawn.Rotation)));
			}
			else
			{
				if (Focus == nullptr)
				{
					MayShootAtEnemy();
					FocalPoint=(Pawn->GetActorLocation() + (float(1000) *  Vector(SequenceScript.Rotation)));
				}
			}
			FinishRotation();
			MayShootTarget();
		}
	}
}
*/

/*
State Broken
{
Begin:
	Warn(string(Pawn) + " Scripted Sequence BROKEN " + FString::FromInt(SequenceScript) + " ACTION " + FString::FromInt(CurrentAction));
	GetPawn()->bPhysicsAnimUpdate=false;
	GetPawn()->StopAnimating();
	if (GetMyPlayer() != nullptr)
	{
		Cast<APlayerController>(GetMyPlayer().Controller).SetViewTarget(Pawn);
	}
}
*/

/* WeaponFireAgain()
Notification from weapon when it is ready to fire (either just finished firing,
or just finished coming up/reloading).
Returns true if weapon should fire.
If it returns false, can optionally set up a weapon change
*/

bool AScriptedController::WeaponFireAgain(float RefireRate, bool bFinishedFire)
{
	/*
	if(State ==Scripting)
	{
		if (bFineWeaponControl)
		{
			return true;
		}
		if (GetPawn()->bIgnorePlayFiring)
		{
			GetPawn()->bIgnorePlayFiring=false;
			return false;
		}
		if (NumShots < 0)
		{
			bShootTarget=false;
			bShootSpray=false;
			StopFiring();
			return false;
		}
		if (bShootTarget && ScriptedFocus != nullptr && ! ScriptedFocus->bDeleteMe)
		{
			Target=ScriptedFocus;
			if (! bShootSpray && GetPawn()->Weapon.RefireRate() < 0.99 && ! GetPawn()->Weapon.CanAttack(Target) || ! GetPawn()->Weapon.BotFire(bFinishedFire,FiringMode))
			{
				//Enable("Tick");
				bPendingShoot=true;
				return false;
			}
			if (NumShots > 0)
			{
				NumShots --;
				if (NumShots == 0)
				{
					NumShots=-1;
				}
			}
			return true;
		}
		StopFiring();
		return false;
	}
	if(State ==Normal)
	{
		return bFineWeaponControl;
	}
	*/
	return false;    //FAKE  /EliZ
}

//native Function Init ();
void AScriptedController::Init()
{
}

void AScriptedController::SetDoubleJump()
{
	bNotifyApex=true;
	bPendingDoubleJump=true;
}

void AScriptedController::NotifyJumpApex()
{
	AActor* HitActor = nullptr;
	FVector HitNormal = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HalfHeight = FVector(0, 0, 0);
	FVector Start = FVector(0,0,0);
	/*
	if (bPendingDoubleJump)
	{
		GetPawn()->bWantsToCrouch=false;
		if (Pawn.CanDoubleJump())
		{
			GetPawn()->DoDoubleJump(false);
		}
		bPendingDoubleJump=false;
	}
	else
	{
		if (bJumpOverWall)
		{
			GetPawn()->Acceleration=Destination - GetPawn()->Location;
			GetPawn()->Acceleration.Z=0;
			HalfHeight=Pawn.GetCollisionExtent();
			HalfHeight.Z *= 0.5;
			Start=Pawn->GetActorLocation() - GetPawn()->CollisionHeight * FVector(0 0 0.5);
			HitActor=Pawn.Trace(HitLocation,HitNormal,Start + 8 * Normal(Pawn.Acceleration),Start,True,HalfHeight);
			if (HitActor != nullptr)
			{
				GetPawn()->bWantsToCrouch=false;
				if (Pawn.CanDoubleJump())
				{
					GetPawn()->DoDoubleJump(false);
				}
			}
		}
	}
	*/
}
void AScriptedController::TakeControlOf(APawn* aPawn)
{
	if (GetPawn() != aPawn)
	{
		aPawn->PossessedBy(this);
		SetPawn(aPawn);
	}
	ChangeState("Scripting");
}

void AScriptedController::SetEnemyReaction(int32 AlertnessLevel)
{
}

void AScriptedController::DestroyPawn()
{
	if (GetPawn() != nullptr)
	{
		GetPawn()->Destroy();
		SetPawn(nullptr);
	}
	Destroy();
}

APawn* AScriptedController::GetMyPlayer()
{
	/*
	if (MyPlayerController == nullptr || MyPlayerController.Pawn == nullptr)
	{
		ForEach DynamicActors(Class'PlayerController',MyPlayerController)
		{
			if (MyPlayerController.Pawn != nullptr)
			{
			}
		}
	}
	if (MyPlayerController == nullptr)
	{
		return nullptr;
	}
	return MyPlayerController.Pawn;
	*/
	return nullptr;    //FAKE   /EliZ
}

APawn* AScriptedController::GetInstigator()
{
	if (GetPawn() != nullptr)
	{
		return GetPawn();
	}
	return GetInstigator();
}

AActor* AScriptedController::GetSoundSource()
{
	if (GetPawn() != nullptr)
	{
		return GetPawn();
	}
	return SequenceScript;
}

bool AScriptedController::CheckIfNearPlayer(float Distance)
{
	APawn* MyPlayer = nullptr;
	MyPlayer=GetMyPlayer();
	//return MyPlayer != nullptr && VSize(Pawn->GetActorLocation() - MyPlayer.Location) < Distance + CollisionRadius + MyPlayer.CollisionRadius && GetPawn()->PlayerCanSeeMe();
	return false;      //FAKE   /EliZ
}

void AScriptedController::ClearScript()
{
	ActionNum=0;
	CurrentAction=nullptr;
	CurrentAnimation=nullptr;
	ScriptedFocus=nullptr;
	//GetPawn()->SetWalking(false);
	//GetPawn()->ShouldCrouch(false);
}

void AScriptedController::SetNewScript(AScriptedSequence* NewScript)
{
	MyScript=NewScript;
	SequenceScript=NewScript;
	Focus=nullptr;
	ClearScript();
	SetEnemyReaction(3);
	SequenceScript->SetActions(this);
}

void AScriptedController::ClearAnimation()
{
	AnimsRemaining=0;
	bControlAnimations=false;
	CurrentAnimation=nullptr;
	//GetPawn()->PlayWaiting();
}

int32 AScriptedController::SetFireYaw(int32 FireYaw)
{
	/*
	FireYaw=FireYaw & 65535;
	if (Pawn.Physics != 0 && GetPawn()->Physics != 13 && Abs(FireYaw - Rotation.Yaw & 65535) > 8192 && Abs(FireYaw - Rotation.Yaw & 65535) < 57343)
	{
		if (ClockwiseFrom_IntInt(FireYaw,Rotation.Yaw))
		{
			FireYaw=Rotation.Yaw + 8192;
		}
		else
		{
			FireYaw=Rotation.Yaw - 8192;
		}
	}
	*/
	return FireYaw;
}

FRotator AScriptedController::AdjustAim(AAmmunition* FiredAmmunition, FVector projStart, int32 aimerror)
{
	FRotator LookDir = FRotator(0,0,0);
	if (Target == nullptr)
	{
		Target=ScriptedFocus;
	}
	if (Target == nullptr)
	{
		Target=Enemy;
		if (Target == nullptr)
		{
			return GetPawn()->GetActorRotation();
		}
	}
	//LookDir=Target->GetActorLocation() - projStart;
	LookDir.Yaw=SetFireYaw(LookDir.Yaw);
	return LookDir;
}

void AScriptedController::Timer()
{
	if (CurrentAction->WaitForPlayer() && CheckIfNearPlayer(CurrentAction->GetDistance()))
	{
		CompleteAction();
	}
	else
	{
		if (CurrentAction->CompleteWhenTimer())
		{
			CompleteAction();
		}
	}
}
void AScriptedController::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (CurrentAction->CompleteWhenTriggered())
	{
		CompleteAction();
	}
}
void AScriptedController::EndState()
{
	bUseScriptFacing=true;
	bFakeShot=false;
}

void AScriptedController::MayShootTarget()
{
	WeaponFireAgain(0,false);
}

void AScriptedController::MayShootAtEnemy()
{
}

void AScriptedController::Tick(float DeltaTime)
{
	if (bPendingShoot)
	{
		bPendingShoot=false;
		MayShootTarget();
	}
	if (! bPendingShoot && CurrentAction == nullptr || ! CurrentAction->StillTicking(this,DeltaTime))
	{
		//Disable("Tick");
	}
}

void AScriptedController::AbortScript()
{
	LeaveScripting();
}

void AScriptedController::SetMoveTarget()
{
	AActor* NextMoveTarget = nullptr;
	Focus=ScriptedFocus;
	NextMoveTarget=CurrentAction->GetMoveTargetFor(this);
	if (NextMoveTarget == nullptr)
	{
		ChangeState("Broken");
		return;
	}
	if (Focus == nullptr)
	{
		Focus=NextMoveTarget;
	}
	MoveTarget=NextMoveTarget;
	if (! actorReachable(MoveTarget))
	{
		MoveTarget=FindPathToward(MoveTarget,false);
		if (MoveTarget == nullptr)
		{
			AbortScript();
			return;
		}
		if (Focus == NextMoveTarget)
		{
			Focus=MoveTarget;
		}
	}
}

void AScriptedController::CompleteAction()
{
	CurrentAction->ActionCompleted();
	ActionNum ++;
	ChangeState("Scripting");
}

void AScriptedController::LIPSincAnimEnd()
{
	if (CurrentAction->CompleteOnLIPSincAnim())
	{
		CompleteAction();
		return;
	}
	else
	{
		//GetPawn()->LIPSincAnimEnd();
	}
}

void AScriptedController::AnimEnd(int32 Channel)
{
	if (CurrentAction->CompleteOnAnim(Channel))
	{
		CompleteAction();
		return;
	}
	if (Channel == 0)
	{
		if (CurrentAnimation == nullptr || ! CurrentAnimation->PawnPlayBaseAnim(this,false))
		{
			ClearAnimation();
		}
	}
	else
	{
		//GetPawn()->AnimEnd(Channel);
	}
}

void AScriptedController::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	DisplayDebug(Canvas,YL,YPos);
	Canvas.DrawText("AIScript " + SequenceScript + " ActionNum " + ActionNum,false);
	YPos += YL;
	Canvas.SetPos(4,YPos);
	CurrentAction->DisplayDebug(Canvas,YL,YPos);
	*/
}

void AScriptedController::InitForNextAction()
{
	SequenceScript->SetActions(this);
	if (CurrentAction == nullptr)
	{
		LeaveScripting();
		return;
	}
	MyScript=SequenceScript;
	if (CurrentAnimation == nullptr)
	{
		ClearAnimation();
	}
}

void AScriptedController::LeaveScripting()
{
	UnPossess();
}

/*

void AScriptedController::UnPossess()
{
		GetPawn()->UnPossessed();
		if (GetPawn() != nullptr && PendingController != nullptr)
		{
			PendingController.bStasis=false;
			PendingController.Possess(Pawn);
		}
		GetPawn()=nullptr;
		if (! bChangingPawns)
		{
			Destroy();
		}
}
*/
