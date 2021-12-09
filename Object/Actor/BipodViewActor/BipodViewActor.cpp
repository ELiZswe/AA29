// All the original content belonged to the US Army


#include "AA29/Object/Actor/BipodViewActor/BipodViewActor.h"

// Sets default values
ABipodViewActor::ABipodViewActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//DrawType = 2;
	//Mesh = SkeletalMesh'A_AA2_ModsUS.acog4x_3p';
	//bBlockZeroExtentTraces = False;
	//bBlockNonZeroExtentTraces = False;
	//bBlockBulletTraces = False;
	//bBlockCoronaTraces = False;
}

// Called when the game starts or when spawned
void ABipodViewActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABipodViewActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

