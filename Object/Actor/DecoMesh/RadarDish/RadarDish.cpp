// All the original content belonged to the US Army


#include "RadarDish.h"

ARadarDish::ARadarDish()
{
	//StaticMesh = StaticMesh'M_AA2_Equipment.Radar.equip2_radar_dish001'
	//bNoDelete = true;
	//Physics = 5;
	bFixedRotationDir = true;

	UStaticMesh* SM = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Equipment/Radar/equip2_radar_dish001.equip2_radar_dish001'"), NULL, LOAD_None, NULL);
	if (SM)
	{
		StaticMesh->SetStaticMesh(SM);
	}
}

void ARadarDish::Reset()
{
	bFixedRotationDir = true;
	AmbientSound = SoundSpinning;
}
void ARadarDish::PreBeginPlay()
{
	RotationRate = RDRotationRate;
	SoundSpinning = AmbientSound;
}
void ARadarDish::BeginPlay()
{
	Super::BeginPlay();
	RotationRate = RDRotationRate;
	SoundSpinning = AmbientSound;
}

void ARadarDish::Trigger(AActor* Other, APawn* EventInstigator)
{
	bFixedRotationDir = false;
	AmbientSound = nullptr;
}