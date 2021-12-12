// All the original content belonged to the US Army


#include "AA29/Object/Actor/NPCHelicopterWoundedPassenger/NPCHelicopterWoundedPassenger.h"

// Sets default values
ANPCHelicopterWoundedPassenger::ANPCHelicopterWoundedPassenger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//DrawType = DT_StaticMesh;
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Character/Wounded/Char_Wounded_Civ_Afr01.Char_Wounded_Civ_Afr01'"), NULL, LOAD_None, NULL);
	//DrawScale = 1.13;
}

// Called when the game starts or when spawned
void ANPCHelicopterWoundedPassenger::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ANPCHelicopterWoundedPassenger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

