// All the original content belonged to the US Army

#include "AA29/Object/Actor/DebugIcon/DebugIcon.h"

ADebugIcon::ADebugIcon()
{
	PrimaryActorTick.bCanEverTick = true;
	//bUseDynamicLights = true;
	//bAcceptsProjectors = false;
	//Physics = 5;
	//Texture = nullptr;
	//DrawScale = 0.5;
	//DrawScale3D = (X = 5, Y = 5, Z = 5);
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
	//RotationRate = (Pitch = 0, Yaw = 3000, Roll = 0);
}

void ADebugIcon::BeginPlay()
{
	Super::BeginPlay();
}


void ADebugIcon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

