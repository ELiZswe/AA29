// All the original content belonged to the US Army


#include "NetworkEmitter.h"

ANetworkEmitter::ANetworkEmitter()
{
	//bReplicateMovement = false;
	//bSkipActorPropertyReplication = true;
	NetUpdateFrequency = 0.1;
	//bNetNotify = true;
};

/*
replication
{
	reliable if (((Role == ROLE_Authority) && bNetDirty))
		TriggerCount, ResetCount;
}
*/

void ANetworkEmitter::PostNetBeginPlay()
{
	/*
	Super::PostNetBeginPlay();
	Reset();
	UpdateTriggerCount();
	OldResetCount = ResetCount;
	*/
}

void ANetworkEmitter::UpdateTriggerCount()
{
	/*
	int32 i = 0;
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

void ANetworkEmitter::PostNetReceive()
{
	/*
	Super::PostNetReceive();
	UpdateTriggerCount();
	if (bNotFirstCall && (ResetCount > OldResetCount))
	{
		Reset();
	}
	OldResetCount = ResetCount;
	bNotFirstCall = true;
	*/
}

void ANetworkEmitter::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	int32 i = 0;
	if (Level.NetMode != NM_Client)
	{
		NetUpdateTime = (Level.TimeSeconds - 1);
		TriggerCount++;
	}
	if (Level.NetMode != NM_DedicatedServer)
	{
		for (i = 0; i < Emitters.Length; i++)
		{
			if (Emitters[i] != None)
			{
				Emitters[i].Trigger();
			}
		}
	}
	*/
}

void ANetworkEmitter::Reset()
{
	/*
	if (Level.NetMode != NM_Client)
	{
		NetUpdateTime = (Level.TimeSeconds - 1);
		ResetCount++;
		TriggerCount = 0;
	}
	Super::Reset();
	*/
}