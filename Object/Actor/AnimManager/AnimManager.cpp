// All the original content belonged to the US Army

#include "AA29/Object/Actor/AnimManager/AnimManager.h"

// Sets default values
AAnimManager::AAnimManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bAlwaysRelevant = true;
	//bReplicateMovement = false;
}


void AAnimManager::BeginPlay()
{
	Super::BeginPlay();
	
}


void AAnimManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAnimManager::PostNetBeginPlay()
{
	/*
	Enable('PostNetReceive');
	Disable('Tick');
	*/
}

void AAnimManager::PostNetReceive()
{
	/*
	if (IsInState('PawnDead'))
	{
		return;
	}
	if (!IsInState(NewState))
	{
		if (!bDelayStateChange)
		{
			GotoState(NewState);
		}
	}
	*/
}

void AAnimManager::NetChangeState(FName State)
{
	/*
	if (IsInState('PawnDead'))
	{
		return;
	}
	NewState = State;
	if (!bDelayStateChange)
	{
		GotoState(State);
	}
	*/
}

void AAnimManager::BindToPawn(APawn* p)
{
	Pawn = p;
	/*
	bDelayStateChange = false;
	NetChangeState("None");
	*/
}

void AAnimManager::ReleasePawn()
{
	/*
	bDelayStateChange = false;
	NetChangeState("None");
	*/
	Pawn = nullptr;
}

bool AAnimManager::CanPlayDeathAnim()
{
	return false;
}

void AAnimManager::PlayDeathAnim()
{
}
