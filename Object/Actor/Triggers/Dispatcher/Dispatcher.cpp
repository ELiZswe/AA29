// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Dispatcher/Dispatcher.h"

ADispatcher::ADispatcher()
{

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
