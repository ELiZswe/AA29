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
	if (Pawn(Other) != nullptr)
	{
		if (Message != "")
		{
			Pawn(Other).ClientMessage(Message);
		}
		if (AIController(Pawn(Other).Controller) != nullptr)
		{
			UsedBy(Pawn(Other));
		}
	}
	*/
}