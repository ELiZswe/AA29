// All the original content belonged to the US Army

#include "AA29/Object/Actor/NetworkTrigger/NetworkTrigger.h"

// Sets default values
ANetworkTrigger::ANetworkTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//bHidden = true;
	//bNoDelete = true;
	bAlwaysRelevant = true;
	//bReplicateMovement = false;
	//bSkipActorPropertyReplication = true;
	//bOnlyDirtyReplication = true;
	NetUpdateFrequency = 0.1;
	//bNetNotify = true;
}

// Called when the game starts or when spawned
void ANetworkTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANetworkTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*
replication
{
	reliable if (((Role == ROLE_Authority) && bNetDirty))
		TriggerCount, ResetCount;
}
*/

void ANetworkTrigger::PostNetBeginPlay()
{
	/*
	Super::PostNetBeginPlay();
	DoClientReset();
	UpdateTriggerCount();
	OldResetCount = ResetCount;
	*/
}

void ANetworkTrigger::UpdateTriggerCount()
{
	int32 i = 0;
	/*
	if (TriggerCount > OldTriggerCount)
	{
		for (i = OldTriggerCount; i < TriggerCount; i++)
		{
			Trigger(None, None);
		}
	}
	OldTriggerCount = TriggerCount;
	*/
}

void ANetworkTrigger::PostNetReceive()
{
	/*
	Super::PostNetReceive();
	UpdateTriggerCount();
	if (bNotFirstCall && (ResetCount > OldResetCount))
	{
		DoClientReset();
	}
	OldResetCount = ResetCount;
	bNotFirstCall = true;
	*/
}

void ANetworkTrigger::DoClientReset()
{
	/*
	local Actor A;
	ForEach AllActors(Class'Actor', A, Event)
	{
		A.Reset();
	}
	*/
}

void ANetworkTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	if (Level.NetMode != NM_Client)
	{
		NetUpdateTime = (Level.TimeSeconds - 1);
		TriggerCount++;
	}
	if (Level.NetMode != NM_DedicatedServer)
	{
		TriggerEvent(Event, Other, EventInstigator);
	}
	*/
}

void ANetworkTrigger::Reset()
{
	/*
	if (Level.NetMode != NM_Client)
	{
		NetUpdateTime = (Level.TimeSeconds - 1);
		ResetCount++;
		TriggerCount = 0;
	}
	*/
	Super::Reset();
}
