// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Dispatcher/Dispatcher.h"

ADispatcher::ADispatcher()
{
	OutDelays.SetNum(32);
	OutEvents.SetNum(32);
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/GamePlay/S_Dispatcher_Mat.S_Dispatcher_Mat'"), NULL, LOAD_None, NULL);
	//bObsolete = true;
}

/*
State Dispatch
{
Begin:
	for (i=0; i<32; i++)
	{
		if ((OutEvents[i] != "None") && (OutEvents[i] != "None"))
		{
			Sleep(OutDelays[i]);
			TriggerEvent(OutEvents[i],Self,Instigator);
		}
	}
	GotoState("None");
}
*/

void ADispatcher::Trigger(AActor* Other, APawn* EventInstigator)
{
	//Instigator = EventInstigator;
	//GotoState("Dispatch");
}
