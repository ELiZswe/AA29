// All the original content belonged to the US Army

#include "AA29/Object/Actor/EffectLocation/EffectLocation.h"

// Sets default values
AEffectLocation::AEffectLocation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//bHidden = true;
}


void AEffectLocation::BeginPlay()
{
	Super::BeginPlay();
	
}


void AEffectLocation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

