// All the original content belonged to the US Army

#include "AA29/Object/Actor/VehiclePart/VehiclePart.h"

// Sets default values
AVehiclePart::AVehiclePart()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void AVehiclePart::BeginPlay()
{
	Super::BeginPlay();
	
}


void AVehiclePart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVehiclePart::update(float DeltaTime)
{
}

void AVehiclePart::Activate(bool bActive)
{
}

