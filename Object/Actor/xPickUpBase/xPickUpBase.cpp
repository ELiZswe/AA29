// All the original content belonged to the US Army


#include "xPickUpBase.h"

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

// Called when the game starts or when spawned
void AxPickUpBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
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
		myEmitter=Spawn(SpiralEmitter,,,Location + vect(0 0 40));
		SetDrawScale(Default.DrawScale);
	}
	*/
}
void AxPickUpBase::CheckForErrors()
{
	/*
		local Actor HitActor;
		local FVector HitLocation;
		local FVector HitNormal;
		HitActor=Trace(HitLocation,HitNormal,Location - vect(0 0 10),Location,False);
		if (HitActor == None)
		{
			Log(Self $ " FLOATING");
			Return True;
		}
		Return CheckForErrors();
	*/
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
		myPickUp=Spawn(PowerUp,,,Location + SpawnHeight * vect(0 0 1),rot(0 0 0));
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
			//Log("No marker for " $ Self);
		}
	*/
}