// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/NetworkEmitter/NetworkEmitter.h"

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
	if (GetNetMode() != ENetMode::NM_Client)
	{
		NetUpdateTime = (GetWorld()->GetTimeSeconds() - 1);
		TriggerCount++;
	}
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		for (i = 0; i < Emitters.Num(); i++)
		{
			if (Emitters[i] != nullptr)
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
	if (GetNetMode() != ENetMode::NM_Client)
	{
		NetUpdateTime = (GetWorld()->GetTimeSeconds() - 1);
		ResetCount++;
		TriggerCount = 0;
	}
	Super::Reset();
	*/
}
