// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/UseTrigger/UseTrigger.h"

AUseTrigger::AUseTrigger()
{
	//bObsolete = true;
}

bool AUseTrigger::SelfTriggered()
{
	return true;
}

bool AUseTrigger::UsedBy(APawn* User)
{
	//TriggerEvent(Event, this, User);
	return true;
}

void AUseTrigger::Touch(AActor* Other)
{
	/*
	if (Cast<APawn>(Other) != nullptr)
	{
		if (Message != "")
		{
			Cast<APawn>(Other).ClientMessage(Message);
		}
		if (Cast<AAIController>(Cast<APawn>(Other).Controller) != nullptr)
		{
			UsedBy(Cast<APawn>(Other));
		}
	}
	*/
}
