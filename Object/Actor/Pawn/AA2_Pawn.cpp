// All the original content belonged to the US Army


#include "AA29/Object/Actor/Pawn/AA2_Pawn.h"

// Sets default values
AAA2_Pawn::AAA2_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAA2_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAA2_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAA2_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

