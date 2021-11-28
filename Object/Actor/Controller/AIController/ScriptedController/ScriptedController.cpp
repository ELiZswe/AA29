// All the original content belonged to the US Army


#include "ScriptedController.h"

AScriptedController::AScriptedController()
{
	bUseScriptFacing = true;
	IterationSectionStart = -1;
}

/* WeaponFireAgain()
Notification from weapon when it is ready to fire (either just finished firing,
or just finished coming up/reloading).
Returns true if weapon should fire.
If it returns false, can optionally set up a weapon change
*/

void AScriptedController::WeaponFireAgain(float RefireRate, bool bFinishedFire)
{
	/*
		if(State ==Scripting)
		{
			if (bFineWeaponControl)
			{
				Return True;
			}
			if (Pawn.bIgnorePlayFiring)
			{
				Pawn.bIgnorePlayFiring=False;
				Return False;
			}
			if (NumShots < 0)
			{
				bShootTarget=False;
				bShootSpray=False;
				StopFiring();
				Return False;
			}
			if (bShootTarget && ScriptedFocus != None && ! ScriptedFocus.bDeleteMe)
			{
				Target=ScriptedFocus;
				if (! bShootSpray && Pawn.Weapon.RefireRate() < 0.99 && ! Pawn.Weapon.CanAttack(Target) || ! Pawn.Weapon.BotFire(bFinishedFire,FiringMode))
				{
					Enable('Tick');
					bPendingShoot=True;
					Return False;
				}
				if (NumShots > 0)
				{
					NumShots --;
					if (NumShots == 0)
					{
						NumShots=-1;
					}
				}
				Return True;
			}
			StopFiring();
			Return False;
		}
		if(State ==Normal)
		{
			Return bFineWeaponControl;
		}
	*/
}


//native Function Init ();
void AScriptedController::Init()
{
}
void AScriptedController::SetDoubleJump()
{
	/*
		bNotifyApex=True;
		bPendingDoubleJump=True;
	*/
}
void AScriptedController::NotifyJumpApex()
{
	/*
		local Actor HitActor;
		local FVector HitNormal;
		local FVector HitLocation;
		local FVector HalfHeight;
		local FVector Start;
		if (bPendingDoubleJump)
		{
			Pawn.bWantsToCrouch=False;
			if (Pawn.CanDoubleJump())
			{
				Pawn.DoDoubleJump(False);
			}
			bPendingDoubleJump=False;
		}
		else
		{
			if (bJumpOverWall)
			{
				Pawn.Acceleration=Destination - Pawn.Location;
				Pawn.Acceleration.Z=0;
				HalfHeight=Pawn.GetCollisionExtent();
				HalfHeight.Z *= 0.5;
				Start=Pawn.Location - Pawn.CollisionHeight * vect(0 0 0.5);
				HitActor=Pawn.Trace(HitLocation,HitNormal,Start + 8 * Normal(Pawn.Acceleration),Start,True,HalfHeight);
				if (HitActor != None)
				{
					Pawn.bWantsToCrouch=False;
					if (Pawn.CanDoubleJump())
					{
						Pawn.DoDoubleJump(False);
					}
				}
			}
		}
	*/
}
void AScriptedController::TakeControlOf(APawn* aPawn)
{
	/*
		if (Pawn != aPawn)
		{
			aPawn.PossessedBy(Self);
			Pawn=aPawn;
		}
		GotoState('Scripting');
	*/
}
void AScriptedController::SetEnemyReaction(int32 AlertnessLevel)
{
}
void AScriptedController::DestroyPawn()
{
	/*
		if (Pawn != None)
		{
			Pawn.Destroy();
			Pawn=None;
		}
		Destroy();
	*/
}
void AScriptedController::GetMyPlayer()
{
	/*
		if (MyPlayerController == None || MyPlayerController.Pawn == None)
		{
			ForEach DynamicActors(Class'PlayerController',MyPlayerController)
			{
				if (MyPlayerController.Pawn != None)
				{
				}
			}
		}
		if (MyPlayerController == None)
		{
			Return None;
		}
		Return MyPlayerController.Pawn;
	*/
}
void AScriptedController::GetInstigator()
{
	/*
		if (Pawn != None)
		{
			Return Pawn;
		}
		Return Instigator;
	*/
}
void AScriptedController::GetSoundSource()
{
	/*
		if (Pawn != None)
		{
			Return Pawn;
		}
		Return SequenceScript;
	*/
}
void AScriptedController::CheckIfNearPlayer(float Distance)
{
	/*
		local Pawn MyPlayer;
		MyPlayer=GetMyPlayer();
		Return MyPlayer != None && VSize(Pawn.Location - MyPlayer.Location) < Distance + CollisionRadius + MyPlayer.CollisionRadius && Pawn.PlayerCanSeeMe();
	*/
}
void AScriptedController::ClearScript()
{
	/*
		ActionNum=0;
		CurrentAction=None;
		CurrentAnimation=None;
		ScriptedFocus=None;
		Pawn.SetWalking(False);
		Pawn.ShouldCrouch(False);
	*/
}
/*
void AScriptedController::SetNewScript(ScriptedSequence NewScript)
{
		MyScript=NewScript;
		SequenceScript=NewScript;
		Focus=None;
		ClearScript();
		SetEnemyReaction(3);
		SequenceScript.SetActions(Self);
}
*/
void AScriptedController::ClearAnimation()
{
	/*
		AnimsRemaining=0;
		bControlAnimations=False;
		CurrentAnimation=None;
		Pawn.PlayWaiting();
	*/
}
void AScriptedController::SetFireYaw(int32 FireYaw)
{
	/*
		FireYaw=FireYaw & 65535;
		if (Pawn.Physics != 0 && Pawn.Physics != 13 && Abs(FireYaw - Rotation.Yaw & 65535) > 8192 && Abs(FireYaw - Rotation.Yaw & 65535) < 57343)
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
		Return FireYaw;
	*/
}
void AScriptedController::AdjustAim(AAmmunition* FiredAmmunition, FVector projStart, int32 aimerror)
{
	/*
		local Object.Rotator LookDir;
		if (Target == None)
		{
			Target=ScriptedFocus;
		}
		if (Target == None)
		{
			Target=Enemy;
			if (Target == None)
			{
				Return Pawn.Rotation;
			}
		}
		LookDir=Target.Location - projStart;
		LookDir.Yaw=SetFireYaw(LookDir.Yaw);
		Return LookDir;
	*/
}

void AScriptedController::Timer()
{
	/*
		if (CurrentAction.WaitForPlayer() && CheckIfNearPlayer(CurrentAction.GetDistance()))
		{
			CompleteAction();
		}
		else
		{
			if (CurrentAction.CompleteWhenTimer())
			{
				CompleteAction();
			}
		}
	*/
}
void AScriptedController::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
		if (CurrentAction.CompleteWhenTriggered())
		{
			CompleteAction();
		}
	*/
}
void AScriptedController::EndState()
{
	/*
		bUseScriptFacing=True;
		bFakeShot=False;
	*/
}
void AScriptedController::MayShootTarget()
{
	/*
		WeaponFireAgain(0,False);
	*/
}
void AScriptedController::MayShootAtEnemy()
{
}
void AScriptedController::Tick(float DeltaTime)
{
	/*
		if (bPendingShoot)
		{
			bPendingShoot=False;
			MayShootTarget();
		}
		if (! bPendingShoot && CurrentAction == None || ! CurrentAction.StillTicking(Self,DeltaTime))
		{
			Disable('Tick');
		}
	*/
}

void AScriptedController::AbortScript()
{
	LeaveScripting();
}
void AScriptedController::SetMoveTarget()
{
	/*
		local Actor NextMoveTarget;
		Focus=ScriptedFocus;
		NextMoveTarget=CurrentAction.GetMoveTargetFor(Self);
		if (NextMoveTarget == None)
		{
			GotoState('Broken');
			Return;
		}
		if (Focus == None)
		{
			Focus=NextMoveTarget;
		}
		MoveTarget=NextMoveTarget;
		if (! actorReachable(MoveTarget))
		{
			MoveTarget=FindPathToward(MoveTarget,False);
			if (MoveTarget == None)
			{
				AbortScript();
				Return;
			}
			if (Focus == NextMoveTarget)
			{
				Focus=MoveTarget;
			}
		}
	*/
}

void AScriptedController::CompleteAction()
{
	/*
		CurrentAction.ActionCompleted();
		ActionNum ++;
		GotoState('Scripting','Begin');
	*/
}
void AScriptedController::LIPSincAnimEnd()
{
	/*
		if (CurrentAction.CompleteOnLIPSincAnim())
		{
			CompleteAction();
			Return;
		}
		else
		{
			Pawn.LIPSincAnimEnd();
		}
	*/
}
void AScriptedController::AnimEnd(int32 Channel)
{
	/*
		if (CurrentAction.CompleteOnAnim(Channel))
		{
			CompleteAction();
			Return;
		}
		if (Channel == 0)
		{
			if (CurrentAnimation == None || ! CurrentAnimation.PawnPlayBaseAnim(Self,False))
			{
				ClearAnimation();
			}
		}
		else
		{
			Pawn.AnimEnd(Channel);
		}
	*/

}

/*
void AScriptedController::DisplayDebug (UCanvas* Canvas, float &YL, float &YPos)
{
	DisplayDebug(Canvas,YL,YPos);
	Canvas.DrawText("AIScript " $ SequenceScript $ " ActionNum " $ ActionNum,False);
	YPos += YL;
	Canvas.SetPos(4,YPos);
	CurrentAction.DisplayDebug(Canvas,YL,YPos);
}
*/


void AScriptedController::InitForNextAction()
{
	/*
		SequenceScript.SetActions(Self);
		if (CurrentAction == None)
		{
			LeaveScripting();
			Return;
		}
		MyScript=SequenceScript;
		if (CurrentAnimation == None)
		{
			ClearAnimation();
		}
	*/
}
void AScriptedController::LeaveScripting()
{
	UnPossess();
}

/*

void AScriptedController::UnPossess()
{
		Pawn.UnPossessed();
		if (Pawn != None && PendingController != None)
		{
			PendingController.bStasis=False;
			PendingController.Possess(Pawn);
		}
		Pawn=None;
		if (! bChangingPawns)
		{
			Destroy();
		}
}
*/
