// All the original content belonged to the US Army

#include "AA29/Object/Actor/FadeKillVolume/FadeKillVolume.h"

// Sets default values
AFadeKillVolume::AFadeKillVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFadeKillVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFadeKillVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

