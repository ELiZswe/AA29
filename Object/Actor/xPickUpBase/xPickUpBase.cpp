// All the original content belonged to the US Army

#include "AA29/Object/Actor/xPickUpBase/xPickUpBase.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/InventorySpot/InventorySpot.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"

// Sets default values
AxPickUpBase::AxPickUpBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnHeight = 50;
	//DrawType =  2;
	//CullDistance = 7000;
	//bStatic = true;
	//RemoteRole = 0;
	//AmbientGlow = 64;
	//CollisionRadius = 35;
	//CollisionHeight = 35;
	//bProjTarget = true;
}


void AxPickUpBase::BeginPlay()
{
	Super::BeginPlay();
	
}


void AxPickUpBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AxPickUpBase::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	if (PowerUp != nullptr)
	{
		if (GetNetMode() != ENetMode::NM_Client)
		{
			SpawnPickup();
			if (bDelayedSpawn && myPickUp != nullptr)
			{
				if (myPickUp.IsInState('Pickup'))
				{
					myPickUp.GotoState('WaitingForMatch');
				}
				if (myPickUp.myMarker != nullptr)
				{
					myPickUp.myMarker.bSuperPickup=true;
				}
			}
		}
		if (GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			PowerUp.StaticPrecache(Level);
		}
	}
	if (! bHidden && GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		myEmitter=Spawn(SpiralEmitter,,,Location + FVector(0 0 40));
		SetDrawScale(Default.DrawScale);
	}
	*/
}

void AxPickUpBase::CheckForErrors()
{
	AActor* HitActor = nullptr;
	FVector HitLocation = FVector(0,0,0);
	FVector HitNormal = FVector(0, 0, 0);
	//HitActor=Trace(HitLocation,HitNormal,Location - FVector(0 0 10),Location,false);
	if (HitActor == nullptr)
	{
		//Log(Self + " FLOATING");
		//return true;
	}
	//return Super::CheckForErrors();
}

uint8 AxPickUpBase::GetInventoryGroup()
{
	return 0;
}

void AxPickUpBase::TurnOn()
{
}

void AxPickUpBase::SpawnPickup()
{
	/*
		if (PowerUp == nullptr)
		{
			return;
		}
		myPickUp=Spawn(PowerUp,,,Location + SpawnHeight * FVector(0 0 1),FRotator(0 0 0));
		if (myPickUp != nullptr)
		{
			myPickUp.PickUpBase=this;
			myPickUp.Event=Event;
		}
		if (myMarker != nullptr)
		{
			myMarker.markedItem=myPickUp;
			myMarker.ExtraCost=ExtraPathCost;
			if (myPickUp != nullptr)
			{
				myPickUp.myMarker=myMarker;
			}
		}
		else
		{
			//Log("No marker for " + Self);
		}
	*/
}
