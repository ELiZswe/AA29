// All the original content belonged to the US Army

#include "AA29/Object/Actor/DebugTracerGreen/DebugTracerGreen.h"

// Sets default values
ADebugTracerGreen::ADebugTracerGreen()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//DrawType = DT_StaticMesh;
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/flash/fx_flash_greentracer.fx_flash_greentracer'"), NULL, LOAD_None, NULL);
	//DrawScale = 0.1;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;

}

// Called when the game starts or when spawned
void ADebugTracerGreen::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADebugTracerGreen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

