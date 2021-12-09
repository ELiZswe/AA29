// All the original content belonged to the US Army


#include "AA29/Object/Actor/DebugIcon/DebugIcon.h"

// Sets default values
ADebugIcon::ADebugIcon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bUseDynamicLights = true;
	//bAcceptsProjectors = False;
	//Physics = 5;
	//Texture = class'None';
	//DrawScale = 0.5;
	//DrawScale3D = (X = 5, Y = 5, Z = 5);
	//bUnlit = true;
	//bShouldBaseAtStartup = true;
	//bCanTeleport = true;
	//CollisionRadius = 1;
	//CollisionHeight = 1;
	//bBlockZeroExtentTraces = False;
	//bBlockNonZeroExtentTraces = False;
	//bUseCylinderCollision = true;
	//bBlockBulletTraces = False;
	//bBlockCoronaTraces = False;
	//RotationRate = (Pitch = 0, Yaw = 3000, Roll = 0);
}

// Called when the game starts or when spawned
void ADebugIcon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADebugIcon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

