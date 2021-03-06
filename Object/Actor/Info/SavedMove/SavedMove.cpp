// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/SavedMove/SavedMove.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

ASavedMove::ASavedMove()
{

}

void ASavedMove::Clear()
{
	TimeStamp = 0;
	Delta = 0;
	//DoubleClickMove = 0;
	//Acceleration = FVector(0, 0, 0);
	StartVelocity = FVector(0, 0, 0);
	bRun = false;
	bDuck = false;
	bPressedJump = false;
	bDoubleJump = false;
	bDuck = false;
	bPressedJump = false;
	bIsWalking = false;
	bProne = false;
}

void ASavedMove::PostUpdate(APlayerController* p)
{
	/*
	if (p->Pawn != nullptr)
	{
		SavedLocation = p->Pawn.Location;
		SavedVelocity = p->Pawn.Velocity;
		EndBase = p.Pawn.Base;
		if ((EndBase != nullptr) && (!EndBase.bWorldGeometry))
		{
			SavedRelativeLocation = (p.Pawn.Location - EndBase.Location);
		}
	}
	SetActorRotation(p.Rotation);
	*/
}

bool ASavedMove::IsJumpMove()
{
	//return (bPressedJump || (((DoubleClickMove != 0) && (DoubleClickMove != 5)) && (DoubleClickMove != 6)));
	return false;     //FAKE   /EliZ
}

FVector ASavedMove::GetStartLocation()
{
	/*
	if ((Cast<AVehicle>(StartBase) != nullptr) || (Cast<AMover>(StartBase) != nullptr))
	{
		return (StartBase.Location + StartRelativeLocation);
	}
	*/
	return StartLocation;
}

void ASavedMove::SetInitialPosition(APawn* p)
{
	/*
	SavedPhysics = p.Physics;
	StartLocation = p.Location;
	StartVelocity = p.Velocity;
	StartBase = p.Base;
	StartFloor = p.Floor;
	if ((StartBase != nullptr) && (!StartBase.bWorldGeometry))
	{
		StartRelativeLocation = (p.Location - StartBase.Location);
	}
	*/
}

void ASavedMove::SetMoveFor(APlayerController* p, float DeltaTime, FVector NewAccel, EDoubleClickDir InDoubleClick)
{
	/*
	Delta = DeltaTime;
	if (VSize(NewAccel) > float(3072))
	{
		NewAccel = (float(3072) * Normal(NewAccel));
	}
	if (p.Pawn != nullptr)
	{
		SetInitialPosition(p.Pawn);
	}
	Acceleration = NewAccel;
	DoubleClickMove = InDoubleClick;
	if (p.Pawn != nullptr)
	{
		bDuck = p.Pawn.bWantsToCrouch;
		bPressedJump = (p.bPressedJump || bPressedJump);
		bIsWalking = p.Pawn.bIsWalking;
		bProne = p.Pawn.bWantsToProne;
	}
	TimeStamp = GetWorld()->GetTimeSeconds();
	*/
}
