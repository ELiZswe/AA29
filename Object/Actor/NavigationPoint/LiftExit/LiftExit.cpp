// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/LiftExit/LiftExit.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "AA29/Object/Actor/NavigationPoint/LiftCenter/LiftCenter.h"

ALiftExit::ALiftExit()
{
	SuggestedKeyFrame = 255;
	bNeverUseStrafing = true;
	bForceNoStrafing = true;
	bSpecialMove = true;
	//Texture = Texture'Engine.S_LiftExit';
}

void ALiftExit::PostBeginPlay()
{
	/*
	PostBeginPlay();
	if (bLiftJumpExit && MyLift != nullptr)
	{
		if (Level.Game.GameDifficulty < 4)
		{
			ExtraCost = 10000000;
		}
		MyLift.bJumpLift = true;
	}
	*/
}

bool ALiftExit::CanBeReachedFromLiftBy(APawn* Other)
{
	float RealJumpZ = 0;
	/*
	if (bLiftJumpExit)
	{
		if (MyLift.Velocity.Z < 100 || MyLift.KeyNum == 0)
		{
			return false;
		}
		RealJumpZ = Other.JumpZ;
		if (!bNoDoubleJump)
		{
			Other.JumpZ = Other.JumpZ * 1.5;
		}
		Other.JumpZ += MyLift.Velocity.Z;
		Other.bWantsToCrouch = false;
		Other.Controller.MoveTarget = this;
		Other.Controller.Destination = Location;
		Other.bNoJumpAdjust = true;
		Other.Velocity = SuggestFallVelocity(Location + FVector(0 0 100), Other->GetActorLocation(), Other.JumpZ, Other.GroundSpeed);
		Other.Acceleration = FVector(0,0,0);
		Other.SetPhysics(2);
		Other.Controller.SetFall();
		Other.DestinationOffset = CollisionRadius;
		Other.JumpZ = RealJumpZ;
		if (!bNoDoubleJump)
		{
			Other.Controller.SetDoubleJump();
		}
		return true;
	}
	return Location.Z < Other.Location.Z + Other.CollisionHeight && Other.LineOfSightTo(this);
	*/
	return false;     //FAKE   /ELiZ
}

bool ALiftExit::SuggestMovePreparation(APawn* Other)
{
	AController* C = nullptr;
	/*
	if ((MyLift == nullptr) || (Other.Controller == nullptr))
	{
		return false;
	}
	if (Other.Physics == 4)
	{
		if (Other.AirSpeed > 0)
		{
			Other.Controller.MoveTimer = (2 + (VSize((Location - Other.Location)) / Other.AirSpeed));
		}
		return false;
	}
	if ((Other.Base == MyLift) || (((Cast<ALiftCenter>(Other.Anchor) != nullptr) && (Cast<ALiftCenter>(Other.Anchor).MyLift == MyLift)) && Other.ReachedDestination(Other.Anchor)))
	{
		if (CanBeReachedFromLiftBy(Other))
		{
			return false;
		}
		Other.DesiredRotation = rotator((Location - Other.Location));
		Other.Controller.WaitForMover(MyLift);
		return true;
	}
	else
	{
		for (C = Level.ControllerList; C != nullptr; C = C.nextController)
		{
			if ((((C.Pawn != nullptr) && (C.PendingMover == MyLift)) && C.SameTeamAs(Other.Controller)) && C.Pawn.ReachedDestination(this))
			{
				Other.DesiredRotation = rotator((Location - Other.Location));
				Other.Controller.WaitForMover(MyLift);
				return true;
			}
		}
	}
	*/
	return false;
}
