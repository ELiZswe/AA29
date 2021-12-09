// All the original content belonged to the US Army


#include "RotorBlade.h"

ARotorBlade::ARotorBlade()
{
	PrimaryActorTick.bCanEverTick = true;
	//StaticMesh = StaticMesh'M_AA2_Equipment.Radar.equip2_radar_dish001'
	//bNoDelete = true;
	//Physics = 5;

	UStaticMesh* SM = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Radar/equip2_radar_dish001.equip2_radar_dish001'"), NULL, LOAD_None, NULL);
	if (SM)
	{
		StaticMesh->SetStaticMesh(SM);
	}
}

void ARotorBlade::BeginPlay()
{
	Super::BeginPlay();

}

void ARotorBlade::Reset()
{
	bFixedRotationDir = false;
	AmbientSound = SoundSpinning;
}
void ARotorBlade::PreBeginPlay()
{
	RotationRate = RDRotationRate;
	SoundSpinning = AmbientSound;
}
void ARotorBlade::Timer()
{
	Super::Timer();
	
	
	if (RotationTimer > GetWorld()->GetTimeSeconds())
	{
		RotationRate = RDRotationRate * (GetWorld()->GetTimeSeconds() / RotationTimer);
	}
	else
	{
		RotationRate = RDRotationRate;
	}
	RotatingMovement->RotationRate = RotationRate;
}
void ARotorBlade::Trigger(AActor* Other, APawn* EventInstigator)
{
	bFixedRotationDir = true;
	AmbientSound = nullptr;
	RotationTimer = FullRotationTime + GetWorld()->GetTimeSeconds();
}