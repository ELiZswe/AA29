// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/Door/Door.h"

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
	/*
	local Object.Vector dist;
	if (DoorTrigger != 'None')
	{
		ForEach AllActors('Actor', RecommendedTrigger, DoorTrigger)
		{
		}
		if (RecommendedTrigger != None)
		{
			dist = Location - RecommendedTrigger.Location;
			if (Abs(dist.Z) < RecommendedTrigger.CollisionHeight)
			{
				dist.Z = 0;
				if (VSize(dist) < RecommendedTrigger.CollisionRadius)
				{
					RecommendedTrigger = None;
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
void ADoor::SpecialHandling(APawn* Other)
{
	/*
	if (MyDoor == None)
	{
		Return Self;
	}
	if (MyDoor.BumpType == 0 && !Other.IsPlayerPawn())
	{
		Return None;
	}
	if (bInitiallyClosed == bDoorOpen || MyDoor.bOpening || MyDoor.bDelaying)
	{
		Return Self;
	}
	if (RecommendedTrigger != None)
	{
		if (Trigger(RecommendedTrigger) != None)
		{
			Return RecommendedTrigger.SpecialHandling(Other);
		}
		Return RecommendedTrigger;
	}
	return this;
	*/
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
		Return True;
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
		Return False;
	}
	if (MyDoor.bOpening || MyDoor.bDelaying)
	{
		Other.Controller.WaitForMover(MyDoor);
		Return True;
	}
	if (MyDoor.bDamageTriggered)
	{
		Other.ShootSpecial(MyDoor);
		MyDoor.Trigger(Other, Other);
		Other.Controller.WaitForMover(MyDoor);
		Return True;
	}
	*/
	return false;
}