// All the original content belonged to the US Army

#include "AA29/Object/Actor/DebugNPCTargetArea/DebugNPCTargetArea.h"

ADebugNPCTargetArea::ADebugNPCTargetArea()
{
	PrimaryActorTick.bCanEverTick = true;
	YawRate = 4096;
	//DrawType = DT_StaticMesh;
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/Editor/TexPropCube.TexPropCube'"), NULL, LOAD_None, NULL);
	//bUseDynamicLights = true;
	//bAcceptsProjectors = false;
	//Physics = PHYS_Rotating;
	//LifeSpan = 60;
	//DrawScale3D = FVector(0.15, 0.15, 0.15);
	//Skins(0) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Attachments/us-soldier/Target_Mat.Target_Mat'"), NULL, LOAD_None, NULL);
	//bUnlit = true;
	//bShouldBaseAtStartup = true;
	//bCanTeleport = true;
	//CollisionRadius = 1;
	//CollisionHeight = 1;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bUseCylinderCollision = true;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
	//bFixedRotationDir = true;
	//RotationRate = FRotator(0, 50, 0);
}


void ADebugNPCTargetArea::BeginPlay()
{
	Super::BeginPlay();
}


void ADebugNPCTargetArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADebugNPCTargetArea::PostBeginPlay()
{
	UE_LOG(LogTemp, Log, TEXT("DebugNPCTargetArea PostBeginPlay() entered"));
	//RotationRate.Yaw = int(YawRate);
}
