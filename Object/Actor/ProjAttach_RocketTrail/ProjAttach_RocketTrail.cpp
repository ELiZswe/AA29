// All the original content belonged to the US Army


#include "AA29/Object/Actor/ProjAttach_RocketTrail/ProjAttach_RocketTrail.h"

// Sets default values
AProjAttach_RocketTrail::AProjAttach_RocketTrail()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//DrawType = DT_StaticMesh;
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/misc/fx2_misc_rockettrail.fx2_misc_rockettrail'"), NULL, LOAD_None, NULL);

}

// Called when the game starts or when spawned
void AProjAttach_RocketTrail::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjAttach_RocketTrail::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

