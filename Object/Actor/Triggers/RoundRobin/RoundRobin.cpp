// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/RoundRobin/RoundRobin.h"

ARoundRobin::ARoundRobin()
{
	OutEvents.SetNum(16);
	//bObsolete = true;
}

void ARoundRobin::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	TriggerEvent(OutEvents[i], this, EventInstigator);
	i++;
	if (((i >= 16) || (OutEvents[i] == "None")) || (OutEvents[i] == "None"))
	{
		if (bLoop)
		{
			i = 0;
		}
		else
		{
			SetCollision(false, false, false);
		}
	}
	*/
}
