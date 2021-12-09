// All the original content belonged to the US Army


#include "AA29/Object/Actor/AGP_Trigger/RelayTrigger/RelayTrigger.h"

ARelayTrigger::ARelayTrigger()
{
	RelayTriggerHelp = { "Triggers multiple events when triggered.","Can also trigger one of multiple events at random.","","[bRandomRelay] If true, only one event is triggered.","If false, all events are triggered.","[Delay] Time to delay before triggering event(s).","[Events] Tags of actors to trigger." };
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP_Gameplay/S_RelayTrigger.S_RelayTrigger'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}



void ARelayTrigger::Trigger(AActor* Other, APawn* EventInsigator)
{
	/*
	Instigator = EventInsigator;
	if (Delay > 0)
	{
		SetTimer(Delay, false);
	}
	else
	{
		Timer();
	}
	*/
}
void ARelayTrigger::Timer()
{
	if (bRandomRelay)
	{
		RandomRelay();
	}
	else
	{
		StandardRelay();
	}
}
void ARelayTrigger::RandomRelay()
{
	//TriggerEvent(Events[Rand(Events.Length)], Self, Instigator);
}
void ARelayTrigger::StandardRelay()
{
	/*
	local int i;
	for (i = 0; i < Events.Length; i++)
	{
		TriggerEvent(Events[i], Self, Instigator);
	}
	*/
}
