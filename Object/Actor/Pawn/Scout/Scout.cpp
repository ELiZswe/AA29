// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/Scout/Scout.h"

// Sets default values
AScout::AScout()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//AccelRate = 1;
	//RemoteRole = 0;
	//CollisionRadius = 52;
	//CollisionHeight = 78;
	//bCollideActors = false;
	//bCollideWorld = false;
	//bBlockActors = false;
	//bProjTarget = false;
	//bPathColliding = true;

}

// Called when the game starts or when spawned
void AScout::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScout::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AScout::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AScout::PreBeginPlay()
{
	//Destroy();
}