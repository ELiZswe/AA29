// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/Ambushpoint/Ambushpoint.h"

AAmbushpoint::AAmbushpoint()
{
	SightRadius = 5000;
	//SoundVolume = 128;
	//bObsolete = true;
}

void AAmbushpoint::PreBeginPlay()
{
	/*
	LookDir = 2000 * Vector(Rotation);
	Super::PreBeginPlay();
	*/
}