// All the original content belonged to the US Army

#include "AA29/Object/Actor/DebugNavigation/DebugNavigation.h"

// Sets default values
ADebugNavigation::ADebugNavigation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void ADebugNavigation::BeginPlay()
{
	Super::BeginPlay();
	
}


void ADebugNavigation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

