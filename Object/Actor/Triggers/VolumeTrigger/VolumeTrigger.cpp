// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/VolumeTrigger/VolumeTrigger.h"

AVolumeTrigger::AVolumeTrigger()
{
	bCollideActors = false;
}

void AVolumeTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	AVolume* V = nullptr;
	/*
	if (Role < 4)
	{
		return;
	}
	ForEach AllActors(Class'Volume', V, Event)
	{
		V.Trigger(Other, EventInstigator);
	}
	*/
}
