// All the original content belonged to the US Army


#include "AA29/AnimManager/AnimManager.h"

// Sets default values
AAnimManager::AAnimManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bAlwaysRelevant = true;
	//bReplicateMovement = false;
}

// Called when the game starts or when spawned
void AAnimManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
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
		Return;
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
		Return;
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
	bDelayStateChange = False;
	NetChangeState('None');
	*/
}

void AAnimManager::ReleasePawn()
{
	/*
	bDelayStateChange = False;
	NetChangeState('None');
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