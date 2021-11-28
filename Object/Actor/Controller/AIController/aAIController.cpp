// All the original content belonged to the US Army


#include "aAIController.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"

AaAIController::AaAIController()
{
	bAdjustFromWalls = true;
	//bCanOpenDoors = true;
	//bCanDoSpecial = true;
	//MinHitWall = -0.5;
}


void AaAIController::WaitToSeeEnemy()
{
}
void AaAIController::NotifyFlashBanged(float Duration, float VisIntensity, float AudIntensity)
{
}
void AaAIController::PreBeginPlay()
{
	/*
		PreBeginPlay();
		if (bDeleteMe)
		{
			Return;
		}
		if (Level.Game != None)
		{
			Skill += Level.Game.GameDifficulty;
		}
		Skill=FClamp(Skill,0,3);
	*/
}
void AaAIController::Reset()
{
	bHunting=false;
	bPlannedJump=false;
	Super::Reset();
}
float AaAIController::RateWeapon (AWeapon* W)
{
	return Cast<AWeapon>(W)->GetAIRating() + FMath::FRand() * 0.05;
}
void AaAIController::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
		TriggerScript(Other,EventInstigator);
	*/
}
void AaAIController::WeaponFireAgain(float RefireRate, bool bFinishedFire)
{
	/*
		if (Pawn.PressingFire() && FRand() < RefireRate)
		{
			Pawn.Weapon.BotFire(bFinishedFire);
			Return True;
		}
		StopFiring();
		Return False;
	*/
}
void AaAIController::TriggerScript(AActor* Other, APawn* EventInstigator)
{
	/*
		if (MyScript != None)
		{
			MyScript.Trigger(EventInstigator,Pawn);
			Return True;
		}
		Return False;
	*/
}
/*
void AaAIController::DisplayDebug (UCanvas Canvas, float YL, float YPos)
{
	local int i;
	local string t;
	DisplayDebug(Canvas,YL,YPos);
	Canvas.DrawColor.B=255;
	if (Pawn != None && MoveTarget != None && Pawn.ReachedDestination(MoveTarget))
	{
		Canvas.DrawText("     Skill " $ Skill $ " NAVIGATION MoveTarget " $ GetItemName(MoveTarget) $ "(REACHED) PendingMover " $ PendingMover $ " MoveTimer " $ MoveTimer,False);
	}
	else
	{
		Canvas.DrawText("     Skill " $ Skill $ " NAVIGATION MoveTarget " $ GetItemName(MoveTarget) $ " PendingMover " $ PendingMover $ " MoveTimer " $ MoveTimer,False);
	}
	YPos += YL;
	Canvas.SetPos(4,YPos);
	if (MoveTarget != None && MoveTarget.IsA('NavigationPoint'))
	{
		Canvas.DrawText("     ExtraCost: " $ NavigationPoint(MoveTarget).ExtraCost);
		YPos += YL;
		Canvas.SetPos(4,YPos);
	}
	t="      Destination " $ Destination $ " Focus " $ GetItemName(Focus);
	if (bPreparingMove)
	{
		t=t $ " (Preparing Move)";
	}
	Canvas.DrawText(t,False);
	YPos += YL;
	Canvas.SetPos(4,YPos);
	Canvas.DrawText("      RouteGoal " $ GetItemName(RouteGoal) $ " RouteDist " $ RouteDist,False);
	YPos += YL;
	Canvas.SetPos(4,YPos);
	i=0;
	if (i < 16)
	{
		if (RouteCache[i] == None)
		{
			if (i > 5)
			{
				t=t $ "--" $ GetItemName(RouteCache[i - 1]);
			}
		}
		else
		{
			else
			{
				if (i < 5)
				{
					t=t $ GetItemName(RouteCache[i]) $ "-";
				}
			}
			i ++;
		}
	}
	Canvas.DrawText("RouteCache: " $ t,False);
	YPos += YL;
	Canvas.SetPos(4,YPos);
}
*/
int32 AaAIController::AdjustDesireFor(APickup* p)
{
	return 0;
}
void AaAIController::GetFacingDirection()
{
	/*
		local float strafeMag;
		local FVector Focus2D;
		local FVector Loc2D;
		local FVector Dest2D;
		local FVector Dir;
		local FVector LookDir;
		local FVector Y;
		Focus2D=FocalPoint;
		Focus2D.Z=0;
		Loc2D=Pawn.Location;
		Loc2D.Z=0;
		Dest2D=Destination;
		Dest2D.Z=0;
		LookDir=Normal(Focus2D - Loc2D);
		Dir=Normal(Dest2D - Loc2D);
		strafeMag=LookDir Dot Dir;
		Y=LookDir Cross vect(0 0 1);
		if (Y Dot Dest2D - Loc2D < 0)
		{
			Return 49152 + 16384 * strafeMag;
		}
		else
		{
			Return 16384 - 16384 * strafeMag;
		}
	*/
}
void AaAIController::AdjustView(float DeltaTime)
{
	/*
		local float TargetYaw;
		local float TargetPitch;
		local Object.Rotator OldViewRotation;
		local Object.Rotator ViewRotation;
		AdjustView(DeltaTime);
		if (! Pawn.bUpdateEyeheight)
		{
			Return;
		}
		ViewRotation=Rotation;
		OldViewRotation=Rotation;
		if (Enemy == None)
		{
			ViewRotation.Roll=0;
			if (DeltaTime < 0.2)
			{
				OldViewRotation.Yaw=OldViewRotation.Yaw & 65535;
				OldViewRotation.Pitch=OldViewRotation.Pitch & 65535;
				TargetYaw=Rotation.Yaw & 65535;
				if (Abs(TargetYaw - OldViewRotation.Yaw) > 32768)
				{
					if (TargetYaw < OldViewRotation.Yaw)
					{
						TargetYaw += 65536;
					}
					else
					{
						TargetYaw -= 65536;
					}
				}
				TargetYaw=OldViewRotation.Yaw * 1 - 5 * DeltaTime + TargetYaw * 5 * DeltaTime;
				ViewRotation.Yaw=TargetYaw;
				TargetPitch=Rotation.Pitch & 65535;
				if (Abs(TargetPitch - OldViewRotation.Pitch) > 32768)
				{
					if (TargetPitch < OldViewRotation.Pitch)
					{
						TargetPitch += 65536;
					}
					else
					{
						TargetPitch -= 65536;
					}
				}
				TargetPitch=OldViewRotation.Pitch * 1 - 5 * DeltaTime + TargetPitch * 5 * DeltaTime;
				ViewRotation.Pitch=TargetPitch;
				SetRotation(ViewRotation);
			}
		}
	*/
}
void AaAIController::SetOrders(FName NewOrders, AController* OrderGiver)
{
}
void AaAIController::GetOrderObject()
{
	/*
		Return None;
	*/
}
void AaAIController::GetOrders()
{
	/*
		Return 'None';
	*/
}
/*
void AaAIController::PrepareForMove(ANavigationPoint* Goal, AReachSpec* Path)
{
}
*/
/*
void AaAIController::WaitForMover(AMover* M)
{
		if (Enemy != None && GetWorld()->GetTimeSeconds() - LastSeenTime < 3)
		{
			Focus=Enemy;
		}
		PendingMover=M;
		bPreparingMove=True;
		Pawn.Acceleration=vect(0 0 0);
}
*/
void AaAIController::MoverFinished()
{
	/*
		if (PendingMover.myMarker.ProceedWithMove(Pawn))
		{
			PendingMover=None;
			bPreparingMove=False;
		}
	*/
}
/*
void AaAIController::UnderLift(AMover* M)
{
		local NavigationPoint N;
		bPreparingMove=False;
		PendingMover=None;
		if (MoveTarget == None || MoveTarget.IsA('LiftCenter'))
		{
			N=Level.NavigationPointList;
			if (N != None)
			{
				if (N.IsA('LiftExit') && LiftExit(N).LiftTag == M.Tag && actorReachable(N))
				{
					MoveTarget=N;
					Return;
				}
				N=N.nextNavigationPoint;
			}
		}
}
*/

bool AaAIController::PriorityObjective()
{
	return false;
}
void AaAIController::Startle(AActor* A)
{
}
void AaAIController::NotifyBuzzedByBullet(AActor* aShooter)
{
}
void AaAIController::NotifyTakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, UaDamageType DamageType, FBoneInfo Bone)
{
}
void AaAIController::RestartNPC()
{
}

float AaAIController::Desireability(APickup* p)
{
	/*
	APawn* myPawn = GetController()->GetPawn();
	return p->BotDesireability(myPawn);
	*/
	return 1.0f;    //FAKE /ELiZ
}