// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/RedirectionTrigger/RedirectionTrigger.h"

ARedirectionTrigger::ARedirectionTrigger()
{
	bCollideActors = false;
}

void ARedirectionTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	APawn* p = nullptr;
	/*
	ForEach DynamicActors(Class'Pawn', p, Event)
	{
		if (p.Health > 0)
		{
			p.TriggerEvent(RedirectionEvent, this, p);
		}
	}
	*/
}
