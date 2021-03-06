// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/JumpDest/JumpDest.h"
#include "AA29/Object/ReachSpec/ReachSpec.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

AJumpDest::AJumpDest()
{
	CalculatedGravityZ.SetNum(8);
	NeededJump.SetNum(8);
	bSpecialForced = true;
	UpstreamPaths.SetNum(8);
}

int32 AJumpDest::GetPathIndex(UReachSpec* Path)
{
	int32 i = 0;
	if (Path == nullptr)
	{
		return 0;
	}
	for (i = 0; i < 4; i++)
	{
		if (UpstreamPaths[i] == Path)
		{
			return i;
		}
	}
	return 0;
}

int32 AJumpDest::SpecialCost(APawn* Other, UReachSpec* Path)
{
	int32 Num = 0;
	/*
	if (Other.Physics == 4)
	{
		return 100;
	}
	if (Cast<AVehicle>(Other) != nullptr)
	{
		return 10000000;
	}
	Num = GetPathIndex(Path);
	if (FMath::Abs(Other.JumpZ / Other.PhysicsVolume.Gravity.Z) >= Abs(NeededJump[Num].Z / CalculatedGravityZ[Num]))
	{
		return 100;
	}
	*/
	return 10000000;
}

void AJumpDest::DoJump(APawn* Other)
{
	/*
	Other.bWantsToCrouch = false;
	Other.Controller.MoveTarget = this;
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
	Other.Acceleration = FVector(0,0,0);
	Other.SetPhysics(2);
	Other.Controller.SetFall();
	Other.DestinationOffset = CollisionRadius;
	*/
}
bool AJumpDest::SuggestMovePreparation(APawn* Other)
{
	/*
	int32 Num;
	if (Other.Controller == nullptr)
	{
		return false;
	}
	Num = GetPathIndex(Other.Controller.CurrentPath);
	if (FMath::Abs(Other.JumpZ / Other.PhysicsVolume.Gravity.Z) < Abs(NeededJump[Num].Z / CalculatedGravityZ[Num]))
	{
		return false;
	}
	DoJump(Other);
	*/
	return false;
}
