// All the original content belonged to the US Army

#include "AA29/Object/Actor/Patrol/Patrol.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/Bot/AGP_Bot/AGP_Bot.h"

// Sets default values
APatrol::APatrol()
{
 	// Set this AActor* to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BeginPatrolState = "Patrolling";
	//bHidden = true;
}

// Called when the game starts or when spawned
void APatrol::BeginPlay()
{
	//Super::BeginPlay();
}

// Called every frame
void APatrol::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);
}

void APatrol::PostBeginPlay()
{
	int32 i = 0;
	AAGP_Bot* Bot=nullptr;
	/*
	Log("Patrol:PostBeginPlay()");
	Log("Patrol:PostBeginPlay():StartPatrollers.Length=" $ string(StartPatrollers.Length));
	for (i = 0; i < StartPatrollers.Length; i++)
	{
		Bot = AGP_Bot(StartPatrollers[i].Controller);
		if (Bot != None)
		{
			Bot.PatrolPath = Self;
			Bot.GotoState(BeginPatrolState);
			if (bDumbPatrol)
			{
				Bot.bDumb = true;
			}
		}
	}
	*/
}

ANavigationPoint* APatrol::GetNextNode(ANavigationPoint* CurrentNode, APawn* Bot)
{
	return nullptr;    //FAKE   /ELiZ
}

ANavigationPoint* APatrol::GetNode(FVector Location, APawn* Bot)
{
	return nullptr;    //FAKE   /ELiZ
}

void APatrol::Arrived(ANavigationPoint* Destination, APawn* Bot)
{
	AAGP_Bot* Controller = nullptr;
	/*
	DebugLog(DEBUG_AI, "Patrol:Arrived()");
	Controller = AGP_Bot(Bot.Controller);
	if (Controller != None)
	{
		Controller.PauseState(NodePause, 'Idle', 'Patrolling');
	}
	*/
}

