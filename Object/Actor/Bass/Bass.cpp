// All the original content belonged to the US Army


#include "Bass.h"

// Sets default values
ABass::ABass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 100;
	//DrawType = 2
	//Mesh = SkeletalMesh'A_AA2_Objects.seabass'
}

// Called when the game starts or when spawned
void ABass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void ABass::PostBeginPlay()
{
	/*
	LaserAttachment = Spawn('BassLaserAttachment', Self, 'None', Location);
	AttachToBone(LaserAttachment, 'LazerCon_joint');
	MyBeam = Spawn('BassLaserBeam', Self);
	MyBeam.IlltemperedSeaBass = Self;
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