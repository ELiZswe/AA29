// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Trigger/ZoneTrigger/ZoneTrigger.h"

AZoneTrigger::AZoneTrigger()
{

}

void AZoneTrigger::Touch(AActor* Other)
{
	/*
	local ZoneInfo Z;
	if (IsRelevant(Other))
	{
		if (Event != "None")
		{
			ForEach AllActors(Class'ZoneInfo', Z)
			{
				if (Z.ZoneTag == Event)
				{
					Z.Trigger(Other, Other.Instigator);
				}
			}
		}
		if (Message != "")
		{
			Other.Instigator.ClientMessage(Message);
		}
		if (bTriggerOnceOnly)
		{
			SetCollision(false);
		}
	}
	*/
}

void AZoneTrigger::UnTouch(AActor* Other)
{
	/*
	local ZoneInfo Z;
	if (IsRelevant(Other))
	{
		if (Event != "None")
		{
			ForEach AllActors(Class'ZoneInfo', Z)
			{
				if (Z.ZoneTag == Event)
				{
					Z.UnTrigger(Other, Other.Instigator);
				}
			}
		}
	}
	*/
}


