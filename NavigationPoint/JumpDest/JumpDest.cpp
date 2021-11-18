// All the original content belonged to the US Army


#include "AA29/NavigationPoint/JumpDest/JumpDest.h"

AJumpDest::AJumpDest()
{
	bSpecialForced = true;
}
/*
void AJumpDest::GetPathIndex(AReachSpec* Path)
{
	local int i;
	if (Path == None)
	{
		Return 0;
	}
	for (i = 0; i < 4; i++)
	{
		if (UpstreamPaths[i] == Path)
		{
			Return i;
		}
	}
	Return 0;
}
*/
/*
int32 AJumpDest::SpecialCost(APawn* Other, AReachSpec* Path)
{
	local int Num;
	if (Other.Physics == 4)
	{
		Return 100;
	}
	if (Vehicle(Other) != None)
	{
		Return 10000000;
	}
	Num = GetPathIndex(Path);
	if (Abs(Other.JumpZ / Other.PhysicsVolume.Gravity.Z) >= Abs(NeededJump[Num].Z / CalculatedGravityZ[Num]))
	{
		Return 100;
	}
	return 10000000;
}
	*/
void AJumpDest::DoJump(APawn* Other)
{
	/*
	Other.bWantsToCrouch = False;
	Other.Controller.MoveTarget = Self;
	Other.Controller.Destination = Location;
	Other.bNoJumpAdjust = true;
	if (bForceDoubleJump)
	{
		Other.Velocity = Other.Controller.EAdjustJump(0, Other.Default.GroundSpeed);
	}
	else
	{
		Other.Velocity = Other.Controller.EAdjustJump(0, Other.GroundSpeed);
	}
	Other.Acceleration = vect(0 0 0);
	Other.SetPhysics(2);
	Other.Controller.SetFall();
	Other.DestinationOffset = CollisionRadius;
	*/
}
bool AJumpDest::SuggestMovePreparation(APawn* Other)
{
	/*
	local int Num;
	if (Other.Controller == None)
	{
		Return False;
	}
	Num = GetPathIndex(Other.Controller.CurrentPath);
	if (Abs(Other.JumpZ / Other.PhysicsVolume.Gravity.Z) < Abs(NeededJump[Num].Z / CalculatedGravityZ[Num]))
	{
		Return False;
	}
	DoJump(Other);
	*/
	return false;
}