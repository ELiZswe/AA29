// All the original content belonged to the US Army


#include "AA29/Object/Actor/Jav_Target/Jav_Target.h"

// Sets default values
AJav_Target::AJav_Target()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bHidden = true;
	//bHardAttach = true;
	//bProjTarget = true;
}

// Called when the game starts or when spawned
void AJav_Target::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJav_Target::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

