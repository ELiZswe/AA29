// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/aAIController.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Keypoint/AIScript/AIScript.h"
#include "AA29/Object/Actor/NavigationPoint/LiftCenter/LiftCenter.h"
#include "AA29/Object/Actor/NavigationPoint/LiftExit/LiftExit.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/ReachSpec/ReachSpec.h"
#include "Engine/Canvas.h"

AaAIController::AaAIController()
{
	bAdjustFromWalls	= true;
	bCanOpenDoors		= true;
	bCanDoSpecial		= true;
	MinHitWall			= -0.5;
}

void AaAIController::WaitToSeeEnemy()
{
}

void AaAIController::NotifyFlashBanged(float Duration, float VisIntensity, float AudIntensity)
{
}

void AaAIController::PreBeginPlay()
{
	Super::PreBeginPlay();
	/*
	if (bDeleteMe)
	{
		return;
	}
	if (Level.Game != nullptr)
	{
		(Skill += Level.Game.GameDifficulty);
	}
	Skill =FMath::Clamp(Skill, 0, 3);
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
	//TriggerScript(Other,EventInstigator);
}

bool AaAIController::WeaponFireAgain(float RefireRate, bool bFinishedFire)
{
	/*
	if (Pawn.PressingFire() && FMath::FRand() < RefireRate)
	{
		Pawn.Weapon.BotFire(bFinishedFire);
		return true;
	}
	StopFiring();
	*/
	return false;
}

bool AaAIController::TriggerScript(AActor* Other, APawn* EventInstigator)
{
	if (MyScript != nullptr)
	{
		//MyScript->Trigger(EventInstigator,Pawn);
		return true;
	}
	return false;
}

void AaAIController::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	int32 i = 0;
	FString t = "";
	/*
	DisplayDebug(Canvas,YL,YPos);
	Canvas.DrawColor.B=255;
	if (Pawn != nullptr && MoveTarget != nullptr && Pawn.ReachedDestination(MoveTarget))
	{
		Canvas.DrawText("     Skill " + Skill + " NAVIGATION MoveTarget " + GetItemName(MoveTarget) + "(REACHED) PendingMover " + PendingMover + " MoveTimer " + MoveTimer,false);
	}
	else
	{
		Canvas.DrawText("     Skill " + Skill + " NAVIGATION MoveTarget " + GetItemName(MoveTarget) + " PendingMover " + PendingMover + " MoveTimer " + MoveTimer,false);
	}
	YPos += YL;
	Canvas.SetPos(4,YPos);
	if (MoveTarget != nullptr && MoveTarget->IsA(ANavigationPoint::StaticClass()))
	{
		Canvas.DrawText("     ExtraCost: " + NavigationPoint(MoveTarget).ExtraCost);
		YPos += YL;
		Canvas.SetPos(4,YPos);
	}
	t="      Destination " + Destination + " Focus " + GetItemName(Focus);
	if (bPreparingMove)
	{
		t=t + " (Preparing Move)";
	}
	Canvas.DrawText(t,false);
	YPos += YL;
	Canvas.SetPos(4,YPos);
	Canvas.DrawText("      RouteGoal " + GetItemName(RouteGoal) + " RouteDist " + RouteDist,false);
	YPos += YL;
	Canvas.SetPos(4,YPos);
	i=0;
	if (i < 16)
	{
		if (RouteCache[i] == nullptr)
		{
			if (i > 5)
			{
				t=t + "--" + GetItemName(RouteCache[i - 1]);
			}
		}
		else
		{
			else
			{
				if (i < 5)
				{
					t=t + GetItemName(RouteCache[i]) + "-";
				}
			}
			i ++;
		}
	}
	Canvas.DrawText("RouteCache: " + t,false);
	YPos += YL;
	Canvas.SetPos(4,YPos);
	*/
}

int32 AaAIController::AdjustDesireFor(APickup* p)
{
	return 0;
}
void AaAIController::GetFacingDirection()
{
	float strafeMag = 0;
	FVector Focus2D = FVector(0, 0, 0);
	FVector Loc2D = FVector(0, 0, 0);
	FVector Dest2D = FVector(0, 0, 0);
	FVector Dir = FVector(0, 0, 0);
	FVector LookDir = FVector(0, 0, 0);
	FVector Y = FVector(0,0,0);
	/*
	Focus2D=FocalPoint;
	Focus2D.Z=0;
	Loc2D=Pawn.Location;
	Loc2D.Z=0;
	Dest2D=Destination;
	Dest2D.Z=0;
	LookDir=Normal(Focus2D - Loc2D);
	Dir=Normal(Dest2D - Loc2D);
	strafeMag=LookDir Dot Dir;
	Y=LookDir Cross FVector(0 0 1);
	if (Y Dot Dest2D - Loc2D < 0)
	{
		return 49152 + 16384 * strafeMag;
	}
	else
	{
		return 16384 - 16384 * strafeMag;
	}
	*/
}

void AaAIController::AdjustView(float DeltaTime)
{
	float TargetYaw = 0;
	float TargetPitch = 0;
	FRotator OldViewRotation = FRotator(0, 0, 0);
	FRotator ViewRotation = FRotator(0,0,0);
	/*
	AdjustView(DeltaTime);
	if (! Pawn.bUpdateEyeheight)
	{
		return;
	}
	ViewRotation=Rotation;
	OldViewRotation=Rotation;
	if (Enemy == nullptr)
	{
		ViewRotation.Roll=0;
		if (DeltaTime < 0.2)
		{
			OldViewRotation.Yaw=OldViewRotation.Yaw & 65535;
			OldViewRotation.Pitch=OldViewRotation.Pitch & 65535;
			TargetYaw=Rotation.Yaw & 65535;
			if (FMath::Abs(TargetYaw - OldViewRotation.Yaw) > 32768)
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
			if (FMath::Abs(TargetPitch - OldViewRotation.Pitch) > 32768)
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
			SetActorRotation(ViewRotation);
		}
	}
	*/
}
void AaAIController::SetOrders(FName NewOrders, AController* OrderGiver)
{
}

AActor* AaAIController::GetOrderObject()
{
	return nullptr;
}

FName AaAIController::GetOrders()
{
	return "None";
}

void AaAIController::PrepareForMove(ANavigationPoint* Goal, UReachSpec* Path)
{
}

void AaAIController::WaitForMover(AMover* M)
{
	/*
	if (Enemy != nullptr && GetWorld()->GetTimeSeconds() - LastSeenTime < 3)
	{
		Focus=Enemy;
	}
	PendingMover=M;
	bPreparingMove=true;
	Pawn.Acceleration=FVector(0,0,0);
	*/
}

void AaAIController::MoverFinished()
{
	/*
		if (PendingMover.myMarker.ProceedWithMove(Pawn))
		{
			PendingMover=nullptr;
			bPreparingMove=false;
		}
	*/
}

void AaAIController::UnderLift(AMover* M)
{
	ANavigationPoint* N = nullptr;
	bPreparingMove = false;
	PendingMover = nullptr;
	if ((MoveTarget == nullptr) || MoveTarget->IsA(ALiftCenter::StaticClass()))
	{
		for (N = Cast<AAA2_WorldSettings>(GetWorldSettings())->NavigationPointList; N != nullptr; N = N->nextNavigationPoint)
		{
			/*
			if ((N->IsA(ALiftExit::StaticClass()) && (Cast<ALiftExit>(N)->LiftTag == M->Tag)) && actorReachable(N))
			{
				MoveTarget = N;
				return;
			}
			*/
		}
	}
}

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
