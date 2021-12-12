// All the original content belonged to the US Army

#include "AA29/Object/Actor/debugTracer/debugTracer.h"

// Sets default values
AdebugTracer::AdebugTracer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//DrawType = DT_StaticMesh;
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/flash/fx_flash_tracer.fx_flash_tracer'"), NULL, LOAD_None, NULL);
	//DrawScale = 0.1;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
}

// Called when the game starts or when spawned
void AdebugTracer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AdebugTracer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

