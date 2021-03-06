// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/TriggeredCondition/TriggeredCondition.h"

ATriggeredCondition::ATriggeredCondition()
{
	bCollideActors = false;
}

void ATriggeredCondition::PostBeginPlay()
{
	// Super::PostBeginPlay();
	bInitialValue = bEnabled;
}

void ATriggeredCondition::Reset()
{
	bEnabled = bInitialValue;
}

void ATriggeredCondition::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (bToggled)
	{
		bEnabled = (!bEnabled);
	}
	else
	{
		bEnabled = (!bInitialValue);
	}
}

void ATriggeredCondition::UnTrigger(AActor* Other, APawn* EventInstigator)
{
	if (bTriggerControlled)
	{
		bEnabled = bInitialValue;
	}
}
