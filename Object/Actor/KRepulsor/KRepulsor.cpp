// All the original content belonged to the US Army


#include "AA29/Object/Actor/KRepulsor/KRepulsor.h"

// Sets default values
AKRepulsor::AKRepulsor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKRepulsor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKRepulsor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	bEnableRepulsion = true;
	CheckDir = FVector(0, 0, -1);
	CheckDist = 50;
	Softness = 0.1;
	PenScale = 1;
	//RemoteRole = 0;
	//bHardAttach = true;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
}

