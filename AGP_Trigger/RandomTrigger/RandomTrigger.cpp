// All the original content belonged to the US Army


#include "AA29/AGP_Trigger/RandomTrigger/RandomTrigger.h"

ARandomTrigger::ARandomTrigger()
{
	RandomMinTime = 1;
	RandomMaxTime = 10;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP_Gameplay/S_RandomTrigger.S_RandomTrigger'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}


void ARandomTrigger::BeginPlay()
{
	if (!bTriggerControl || bStartOn)
	{
		_setTimer();
	}
}
void ARandomTrigger::Timer()
{
	//TriggerEvent(Event, this, nullptr);
	if (bOnceOnly)
	{
		_ClearTimer();
	}
	else
	{
		_setTimer();
	}
}
void ARandomTrigger::_setTimer()
{
	//SetTimer(FRand() * RandomMaxTime - RandomMinTime + RandomMinTime, false);
	bRunning = true;
}
void ARandomTrigger::_ClearTimer()
{
	//SetTimer(0, false);
	bRunning = false;
}
void ARandomTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	if (!bTriggerControl)
	{
		return;
	}
	if (bRunning)
	{
		_ClearTimer();
	}
	else
	{
		_setTimer();
	}
}
