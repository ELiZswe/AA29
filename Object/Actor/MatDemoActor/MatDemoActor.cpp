// All the original content belonged to the US Army

#include "AA29/Object/Actor/MatDemoActor/MatDemoActor.h"

// Sets default values
AMatDemoActor::AMatDemoActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//DrawType = 2;
	//bStatic = true;
	//SoundOcclusion = 1;
}


void AMatDemoActor::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMatDemoActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

