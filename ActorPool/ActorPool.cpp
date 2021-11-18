// All the original content belonged to the US Army


#include "AA29/ActorPool/ActorPool.h"

// Sets default values
AActorPool::AActorPool()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//cPoolClass = AActor::StaticClass();
	//bHidden = true;

}

// Called when the game starts or when spawned
void AActorPool::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorPool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//native Function Init();
void AActorPool::Init()
{

}

//native Function ReleaseActor(int Index);
void AActorPool::ReleaseActor(int32 Index)
{

}

//native Function ResetActor(int Index);
void AActorPool::ResetActor(int32 Index)
{

}
