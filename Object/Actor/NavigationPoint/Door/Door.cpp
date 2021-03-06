// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/Door/Door.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"

ADoor::ADoor()
{
	bInitiallyClosed = true;
	bSpecialMove = true;
	ExtraCost = 100;
	//RemoteRole = 0;
	//Texture = Texture'Engine.S_Door';
}

void ADoor::PostBeginPlay()
{
	FVector dist = FVector(0,0,0);
	/*
	if (DoorTrigger != "None")
	{
		ForEach AllActors('Actor', RecommendedTrigger, DoorTrigger)
		{
		}
		if (RecommendedTrigger != nullptr)
		{
			dist = Location - RecommendedTrigger.Location;
			if (FMath::Abs(dist.Z) < RecommendedTrigger.CollisionHeight)
			{
				dist.Z = 0;
				if (VSize(dist) < RecommendedTrigger.CollisionRadius)
				{
					RecommendedTrigger = nullptr;
				}
			}
		}
	}
	bBlocked = bInitiallyClosed && bBlockedWhenClosed;
	bDoorOpen = !bInitiallyClosed;
	Super::PostBeginPlay();
	*/
}
void ADoor::MoverOpened()
{
	/*
	bBlocked = !bInitiallyClosed && bBlockedWhenClosed;
	bDoorOpen = bInitiallyClosed;
	*/
}
void ADoor::MoverClosed()
{
	/*
	bBlocked = bInitiallyClosed && bBlockedWhenClosed;
	bDoorOpen = !bInitiallyClosed;
	*/
}

AActor* ADoor::SpecialHandling(APawn* Other)
{
	if (MyDoor == nullptr)
	{
		return this;
	}
	if (MyDoor->BumpType == EBumpType::BT_PlayerBump && !Cast<AAGP_Pawn>(Other)->IsPlayerPawn())
	{
		return nullptr;
	}
	/*
	if (bInitiallyClosed == bDoorOpen || MyDoor.bOpening || MyDoor.bDelaying)
	{
		return this;
	}
	if (RecommendedTrigger != nullptr)
	{
		if (Cast<ATrigger>(RecommendedTrigger) != nullptr)
		{
			return RecommendedTrigger.SpecialHandling(Other);
		}
		return RecommendedTrigger;
	}
	*/
	return this;
}

bool ADoor::ProceedWithMove(APawn* Other)
{
	/*
	if (MyDoor.bDamageTriggered && Other.Controller.Focus == MyDoor)
	{
		Other.Controller.StopFiring();
	}
	if (bDoorOpen || !MyDoor.bDamageTriggered)
	{
		return true;
	}
	Other.ShootSpecial(MyDoor);
	MyDoor.Trigger(Other, Other);
	Other.Controller.WaitForMover(MyDoor);
	*/
	return false;
}
bool ADoor::SuggestMovePreparation(APawn* Other)
{
	/*
	if (bDoorOpen)
	{
		return false;
	}
	if (MyDoor.bOpening || MyDoor.bDelaying)
	{
		Other.Controller.WaitForMover(MyDoor);
		return true;
	}
	if (MyDoor.bDamageTriggered)
	{
		Other.ShootSpecial(MyDoor);
		MyDoor.Trigger(Other, Other);
		Other.Controller.WaitForMover(MyDoor);
		return true;
	}
	*/
	return false;
}
