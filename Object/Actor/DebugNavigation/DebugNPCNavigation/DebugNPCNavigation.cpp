// All the original content belonged to the US Army

#include "AA29/Object/Actor/DebugNavigation/DebugNPCNavigation/DebugNPCNavigation.h"

ADebugNPCNavigation::ADebugNPCNavigation()
{
	YawRate = 4096;
	//DrawType = DT_StaticMesh;
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/Editor/TexPropCube.TexPropCube'"), NULL, LOAD_None, NULL);
	//bUseDynamicLights = true;
	//bAcceptsProjectors = false;
	//Physics = PHYS_Rotating;
	//DrawScale3D = FVector(0.15, 0.15, 0.15);
	//Skins(0) = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Editor/Engine/AGP_Location_Mat.AGP_Location_Mat'"), NULL, LOAD_None, NULL);
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

void ADebugNPCNavigation::PostBeginPlay()
{
	UE_LOG(LogTemp, Log, TEXT("DebugNPCNavigation PostBeginPlay() entered"));
	//RotationRate.Yaw = int(YawRate);
}
