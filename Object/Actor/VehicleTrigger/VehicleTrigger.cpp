// All the original content belonged to the US Army


#include "AA29/Object/Actor/VehicleTrigger/VehicleTrigger.h"

// Sets default values
AVehicleTrigger::AVehicleTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVehicleTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVehicleTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

