// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/LiftExit/LiftExit.h"

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
	if (bLiftJumpExit && MyLift != None)
	{
		if (Level.Game.GameDifficulty < 4)
		{
			ExtraCost = 10000000;
		}
		MyLift.bJumpLift = true;
	}
	*/
}
void ALiftExit::CanBeReachedFromLiftBy(APawn* Other)
{
	/*
	local float RealJumpZ;
	if (bLiftJumpExit)
	{
		if (MyLift.Velocity.Z < 100 || MyLift.KeyNum == 0)
		{
			Return False;
		}
		RealJumpZ = Other.JumpZ;
		if (!bNoDoubleJump)
		{
			Other.JumpZ = Other.JumpZ * 1.5;
		}
		Other.JumpZ += MyLift.Velocity.Z;
		Other.bWantsToCrouch = False;
		Other.Controller.MoveTarget = Self;
		Other.Controller.Destination = Location;
		Other.bNoJumpAdjust = true;
		Other.Velocity = SuggestFallVelocity(Location + vect(0 0 100), Other.Location, Other.JumpZ, Other.GroundSpeed);
		Other.Acceleration = vect(0 0 0);
		Other.SetPhysics(2);
		Other.Controller.SetFall();
		Other.DestinationOffset = CollisionRadius;
		Other.JumpZ = RealJumpZ;
		if (!bNoDoubleJump)
		{
			Other.Controller.SetDoubleJump();
		}
		Return True;
	}
	Return Location.Z < Other.Location.Z + Other.CollisionHeight && Other.LineOfSightTo(Self);
	*/
}
bool ALiftExit::SuggestMovePreparation(APawn* Other)
{
	/*
	local Controller C;
	if (MyLift == None || Other.Controller == None)
	{
		Return False;
	}
	if (Other.Physics == 4)
	{
		if (Other.AirSpeed > 0)
		{
			Other.Controller.MoveTimer = 2 + VSize(Location - Other.Location) / Other.AirSpeed;
		}
		Return False;
	}
	if (Other.Base == MyLift || LiftCenter(Other.Anchor) != None && LiftCenter(Other.Anchor).MyLift == MyLift && Other.ReachedDestination(Other.Anchor))
	{
		if (CanBeReachedFromLiftBy(Other))
		{
			Return False;
		}
		Other.DesiredRotation = Location - Other.Location;
		Other.Controller.WaitForMover(MyLift);
		Return True;
	}
	else
	{
		C = Level.ControllerList;
		if (C != None)
		{
			if (C.Pawn != None && C.PendingMover == MyLift && C.SameTeamAs(Other.Controller) && C.Pawn.ReachedDestination(Self))
			{
				Other.DesiredRotation = Location - Other.Location;
				Other.Controller.WaitForMover(MyLift);
				Return True;
			}
			C = C.nextController;
		}
	}
	*/
	return false;
}