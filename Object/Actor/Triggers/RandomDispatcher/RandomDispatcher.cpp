// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/RandomDispatcher/RandomDispatcher.h"

ARandomDispatcher::ARandomDispatcher()
{
	PendingDelay.SetNum(32);
	PendingEvent.SetNum(32);
	AvailableCounter.SetNum(32);
	AvailableEvent.SetNum(32);
	EventList.SetNum(32);
	//Texture = Texture'GamePlay.S_Dispatcher'
}

/*
State Dispatch
{
	Function DoAvailable(int32 Index)
	{
		int32 c_member = 0;
		FName e_member = "";
		TriggerEvent(AvailableEvent[Index],Self,Instigator);
		e_member=AvailableEvent[Index];
		c_member=(AvailableCounter[Index] - 1);
		i=Index;
		if (i < ((iTotalAvailable + iTotalPending) - 1))
		{
			AvailableEvent[i]=AvailableEvent[(i + 1)];
			AvailableCounter[i]=AvailableCounter[(i + 1)];
			i ++;
		}
		AvailableEvent[i]=e_member;
		AvailableCounter[i]=c_member;
		iTotalAvailable --;
		for (i=0; i<iTotalPending; i++)
		{
			PendingDelay[i] -= fCurrentDelay;
		}
		PendingDelay[iTotalPending]=fUntriggerDelay;
		PendingEvent[iTotalPending]=e_member;
		iTotalPending ++;
		iTotalTargets --;
		fCurrentDelay=fTriggerDelay;
	}
	Function doPending()
	{
		float pending_delay = 0;
		UntriggerEvent(PendingEvent[0],Self,Instigator);
		pending_delay=PendingDelay[0];
		if (AvailableCounter[iTotalAvailable] != 0)
		{
			iTotalAvailable ++;
		}
		else
		{
			i=iTotalAvailable;
			if (i < (iTotalAvailable + iTotalPending))
			{
				AvailableEvent[i]=AvailableEvent[(i + 1)];
				AvailableCounter[i]=AvailableCounter[(i + 1)];
				i ++;
			}
		}
		iTotalPending --;
		for (i=0; i<iTotalPending; i++)
		{
			PendingDelay[i]=(PendingDelay[(i + 1)] - pending_delay);
			PendingEvent[i]=PendingEvent[(i + 1)];
		}
		fCurrentDelay -= pending_delay;
	}
	Function bool PendingReady()
	{
		if (iTotalPending == 0)
		{
			return false;
		}
		if (iTotalAvailable == 0)
		{
			return true;
		}
		if (PendingDelay[0] > fCurrentDelay)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	Function int32 getTarget()
	{
		int32 total = 0;
		int32 Target = 0;
		if (bDistribute == false)
		{
			return Rand(iTotalAvailable);
		}
		else
		{
			total=0;
			for (i=0; i<iTotalAvailable; i++)
			{
				total += AvailableCounter[i];
			}
			Target=(Rand(total) + 1);
			i=0;
			if (Target > 0)
			{
				Target -= AvailableCounter[i];
				i ++;
			}
			i --;
			return i;
		}
	}
	Function printAll()
	{
		Log("RandomDispatcher::prn()	- - - - - -");
		printAvail();
		Log("RandomDispatcher::prn()	 - - ");
		printPend();
		Log("RandomDispatcher::prn()	- - - - - -");
	}
	Function printAvail()
	{
		Log("RandomDispatcher::prn()	Available " + FString::FromInt(iTotalAvailable));
		Log("RandomDispathcer::prn()	" + FString::FromInt(AvailableEvent[0]) + " " + FString::FromInt(AvailableEvent[1]) + " " + FString::FromInt(AvailableEvent[2]) + " " + FString::FromInt(AvailableEvent[3]));
		Log("RandomDispathcer::prn()	Counters: " + FString::FromInt(AvailableCounter[0]) + " " + FString::FromInt(AvailableCounter[1]) + " " + FString::FromInt(AvailableCounter[2]) + " " + FString::FromInt(AvailableCounter[3]));
	}
	Function printPend()
	{
		Log("RandomDispatcher::prn()	Pending " + FString::FromInt(iTotalPending));
		Log("RandomDispatcher::prn()	Events: " + FString::FromInt(PendingEvent[0]) + " " + FString::FromInt(PendingEvent[1]) + " " + FString::FromInt(PendingEvent[2]) + " " + FString::FromInt(PendingEvent[3]));
		Log("RandomDispatcher::prn()	Counters: " + FString::FromInt(PendingDelay[0]) + " " + FString::FromInt(PendingDelay[1]) + " " + FString::FromInt(PendingDelay[2]) + " " + FString::FromInt(PendingDelay[3]));
	}
	Function DispatchComplete()
	{
		if (bDispatchOnceOnly == true)
		{
			GotoState("Disabled");
		}
		else
		{
			GotoState("None");
		}
		Global.t();
	}
Begin:
	iTotalTargets=0;
	for (i=0; i<32; i++)
	{
		if ((EventList[i].Event == "None") || (EventList[i].Event == "None"))
		{
		}
		iTotalTargets += EventList[i].Counter;
		AvailableEvent[i]=EventList[i].Event;
		AvailableCounter[i]=EventList[i].Counter;
	}
	iTotalAvailable=i;
	for (i=0; i<iTotalAvailable; i++)
	{
		if (AvailableCounter[i] == 0)
		{
			j=i;
			if (j < (iTotalAvailable - 1))
			{
				AvailableEvent[j]=AvailableEvent[(j + 1)];
				AvailableCounter[j]=AvailableCounter[(j + 1)];
				j ++;
			}
			iTotalAvailable --;
			i --;
		}
	}
	iTotalPending=0;
	fCurrentDelay=0;
	iTotalEvents=(iTotalTargets * 2);
	for (j=0; j<iTotalEvents; j++)
	{
		if (bPaused)
		{
			j --;
			Sleep(1);
		}
		else
		{
			if (PendingReady() == false)
			{
				Sleep(fCurrentDelay);
				DoAvailable(getTarget());
			}
			else
			{
				Sleep(PendingDelay[0]);
				doPending();
			}
		}
	}
	DispatchComplete();
}
*/

/*
State Disabled
{
	Function EnableDispatcher(bool change_once_flag, bool once)
	{
		if (change_once_flag)
		{
			bDispatchOnceOnly=once;
		}
		GotoState("None");
	}
}
*/

void ARandomDispatcher::DispatchComplete()						//State Dispatch
{
	/*
	if (bDispatchOnceOnly == true)
	{
		GotoState('Disabled');
	}
	else
	{
		GotoState("None");
	}
	Global.t();
	*/
}
void ARandomDispatcher::printPend()								//State Dispatch
{
	/*
	Log("RandomDispatcher::prn()	Pending " + iTotalPending);
	Log("RandomDispatcher::prn()	Events: " + PendingEvent[0] + " " + PendingEvent[1] + " " + PendingEvent[2] + " " + PendingEvent[3]);
	Log("RandomDispatcher::prn()	Counters: " + PendingDelay[0] + " " + PendingDelay[1] + " " + PendingDelay[2] + " " + PendingDelay[3]);
	*/
}
void ARandomDispatcher::printAvail()								//State Dispatch
{
	/*
	Log("RandomDispatcher::prn()	Available " + iTotalAvailable);
	Log("RandomDispathcer::prn()	" + AvailableEvent[0] + " " + AvailableEvent[1] + " " + AvailableEvent[2] + " " + AvailableEvent[3]);
	Log("RandomDispathcer::prn()	Counters: " + AvailableCounter[0] + " " + AvailableCounter[1] + " " + AvailableCounter[2] + " " + AvailableCounter[3]);
	*/
}		
void ARandomDispatcher::printAll()								//State Dispatch
{
	UE_LOG(LogTemp, Warning, TEXT("RandomDispatcher::prn()	- - - - - -"));
	printAvail();
	UE_LOG(LogTemp, Warning, TEXT("RandomDispatcher::prn()	 - - "));
	printPend();
	UE_LOG(LogTemp, Warning, TEXT("RandomDispatcher::prn()	- - - - - -"));
}		
int32 ARandomDispatcher::getTarget()								//State Dispatch
{
	int32 total;
	int32 Target;
	if (bDistribute == false)
	{
		return FMath::RandRange(0,iTotalAvailable);
	}
	else
	{
		total = 0;
		for (i = 0; i < iTotalAvailable; i++)
		{
			total += AvailableCounter[i];
		}
		Target = FMath::RandRange(0,total) + 1;
		i = 0;
		if (Target > 0)
		{
			Target -= AvailableCounter[i];
			i++;
		}
		i--;
		return i;
	}
}
bool ARandomDispatcher::PendingReady()						//State Dispatch
{
	if (iTotalPending == 0)
	{
		return false;
	}
	if (iTotalAvailable == 0)
	{
		return true;
	}
	if (PendingDelay[0] > fCurrentDelay)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void ARandomDispatcher::doPending()									//State Dispatch
{
	float pending_delay = 0;
	/*
	UntriggerEvent(PendingEvent[0],Self,Instigator);
	pending_delay = PendingDelay[0];
	if (AvailableCounter[iTotalAvailable] != 0)
	{
		iTotalAvailable++;
	}
	else
	{
		i = iTotalAvailable;
		if (i < iTotalAvailable + iTotalPending)
		{
			AvailableEvent[i] = AvailableEvent[i + 1];
			AvailableCounter[i] = AvailableCounter[i + 1];
			i++;
		}
	}
	iTotalPending--;
	for (i = 0; i < iTotalPending; i++)
	{
		PendingDelay[i] = PendingDelay[i + 1] - pending_delay;
		PendingEvent[i] = PendingEvent[i + 1];
	}
	fCurrentDelay -= pending_delay;
	*/
}
void ARandomDispatcher::DoAvailable(int32 Index)						//State Dispatch
{
	int32 c_member = 0;
	FName e_member = "";
	/*
	TriggerEvent(AvailableEvent[Index],Self,Instigator);
	e_member = AvailableEvent[Index];
	c_member = AvailableCounter[Index] - 1;
	i = Index;
	if (i < iTotalAvailable + iTotalPending - 1)
	{
		AvailableEvent[i] = AvailableEvent[i + 1];
		AvailableCounter[i] = AvailableCounter[i + 1];
		i++;
	}
	AvailableEvent[i] = e_member;
	AvailableCounter[i] = c_member;
	iTotalAvailable--;
	for (i = 0; i < iTotalPending; i++)
	{
		PendingDelay[i] -= fCurrentDelay;
	}
	PendingDelay[iTotalPending] = fUntriggerDelay;
	PendingEvent[iTotalPending] = e_member;
	iTotalPending++;
	iTotalTargets--;
	fCurrentDelay = fTriggerDelay;
	*/
}
void ARandomDispatcher::EnableDispatcher(bool change_once_flag, bool once)    //State Disabled
{
	
	if (change_once_flag)
	{
		bDispatchOnceOnly = once;
	}
	//GotoState("None");
	
}
void ARandomDispatcher::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	Log("RandomDispatcher::Trigger()	Got triggered by " + Other @ EventInstigator);
	Instigator = EventInstigator;
	GotoState('Dispatch');
	*/
}

