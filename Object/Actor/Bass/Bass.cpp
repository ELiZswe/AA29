// All the original content belonged to the US Army

#include "AA29/Object/Actor/Bass/Bass.h"
#include "AA29/Object/Actor/BassLaserAttachment/BassLaserAttachment.h"
#include "AA29/Object/Actor/xEmitter/BassLaserBeam/BassLaserBeam.h"

// Sets default values
ABass::ABass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 100;
	//DrawType = 2
	//Mesh = SkeletalMesh'A_AA2_Objects.seabass'
}


void ABass::BeginPlay()
{
	Super::BeginPlay();
	
}


void ABass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABass::PostBeginPlay()
{
	/*
	LaserAttachment = Spawn('BassLaserAttachment', this, "None", Location);
	AttachToBone(LaserAttachment, 'LazerCon_joint');
	MyBeam = Spawn('BassLaserBeam', Self);
	MyBeam.IlltemperedSeaBass = this;
	LoopAnim('swim_loop');
	*/
}
void ABass::Destroyed()
{
	Super::Destroyed();
	
	if (LaserAttachment != NULL)
	{
		//LaserAttachment->Destroy();
		LaserAttachment = NULL;
	}
	if (MyBeam != NULL)
	{
		//MyBeam->Destroy();
		MyBeam = NULL;
	}
}
