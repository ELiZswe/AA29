// All the original content belonged to the US Army

#include "AA29/Object/Actor/BipodViewActor/BipodViewActor.h"

// Sets default values
ABipodViewActor::ABipodViewActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//DrawType = 2;
	//Mesh = SkeletalMesh'A_AA2_ModsUS.acog4x_3p';
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
}


void ABipodViewActor::BeginPlay()
{
	Super::BeginPlay();
	
}


void ABipodViewActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

