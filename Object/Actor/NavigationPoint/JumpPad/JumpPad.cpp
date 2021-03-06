// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/JumpPad/JumpPad.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

AJumpPad::AJumpPad()
{
	JumpVelocity = FVector(0, 0, 1200);
	JumpZModifier = 1;
	bDestinationOnly = true;
	//bCollideActors = true;
}

void AJumpPad::PostBeginPlay()
{
	ANavigationPoint* N = nullptr;
	Super::PostBeginPlay();
	/*
	ForEach AllActors(ANavigationPoint::StaticClass(), N)
	{
		if ((N != Self) && NearSpot(N.Location))
		{
			(N.ExtraCost += 1000);
		}
	}
	if (JumpVelocity != JumpVelocity)
	{
		Log(string(this) + " has illegal jump velocity " + FString::FromInt(JumpVelocity));
		JumpVelocity = FVector(0, 0, 0);
	}
	BACKUP_JumpVelocity = JumpVelocity;
	*/
}

void AJumpPad::Reset()
{
	JumpVelocity = BACKUP_JumpVelocity;
}

void AJumpPad::Touch(AActor* Other)
{
	/*
	if (((Cast<APawn>(Other) == nullptr) || (Other.Physics == 0)) || (Cast<AVehicle>(Other) != nullptr))
	{
		return;
	}
	PendingTouch = Other.PendingTouch;
	Other.PendingTouch = this;
	*/
}

void AJumpPad::PostTouch(AActor* Other)
{
	APawn* p = nullptr;
	/*
	p = Cast<APawn>(Other);
	if ((((p == nullptr) || (p.Physics == 0)) || (Cast<AVehicle>(Other) != nullptr)) || (p.DrivenVehicle != nullptr))
	{
		return;
	}
	if (Cast<AAIController>(p.Controller) != nullptr)
	{
		p.Controller.MoveTarget = JumpTarget;
		p.Controller.Focus = JumpTarget;
		if (p.Physics != 4)
		{
			p.Controller.MoveTimer = 2;
		}
		p.DestinationOffset = JumpTarget.CollisionRadius;
	}
	if (p.Physics == 1)
	{
		p.SetPhysics(PHYS_Falling);
	}
	p.Velocity = JumpVelocity;
	p.Acceleration = FVector(0, 0, 0);
	if (JumpSound != nullptr)
	{
		p.PlaySound(JumpSound);
	}
	*/
}
