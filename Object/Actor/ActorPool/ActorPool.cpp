// All the original content belonged to the US Army

#include "AA29/Object/Actor/ActorPool/ActorPool.h"

// Sets default values
AActorPool::AActorPool()
{
	Pool.SetNum(50);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//cPoolClass = AActor::StaticClass();
	//bHidden = true;
}


void AActorPool::BeginPlay()
{
	Super::BeginPlay();
}


void AActorPool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//native Function Init();
void AActorPool::Init()
{

}

//native Function ReleaseActor(int32 Index);
void AActorPool::ReleaseActor(int32 Index)
{

}

//native Function ResetActor(int32 Index);
void AActorPool::ResetActor(int32 Index)
{

}
