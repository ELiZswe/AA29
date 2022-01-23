// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Trigger/TimedTrigger/TimedTrigger.h"

ATimedTrigger::ATimedTrigger()
{
	DelaySeconds = 1;
	bCollideActors = false;
}

void ATimedTrigger::Timer()
{
	//TriggerEvent(Event, this, None);
	if (!bRepeating)
	{
		Destroy();
	}
}

void ATimedTrigger::MatchStarting()
{
	//SetTimer(DelaySeconds, bRepeating);
}
