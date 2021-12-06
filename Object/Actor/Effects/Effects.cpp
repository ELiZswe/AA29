// All the original content belonged to the US Army


#include "AA29/Object/Actor/Effects/Effects.h"

// Sets default values
AEffects::AEffects()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bNetTemporary = true;
	//bNetInitialRotation = true;
	//RemoteRole = ROLE_None;
	//bUnlit = true;
	//bGameRelevant = true;
	//CollisionRadius = 0;
	//CollisionHeight = 0;
}

// Called when the game starts or when spawned
void AEffects::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEffects::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

