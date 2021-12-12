// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_Trigger/TriggerMultiple/TriggerMultiple.h"
#include "AA29/AA29.h"

ATriggerMultiple::ATriggerMultiple()
{
	//bNoDelete = true;
	//bAcceptsProjectors = false;
	//bMovable = false;
	//CollisionRadius = 22;
	//CollisionHeight = 49;
	//bCollideActors = false;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}

void ATriggerMultiple::PreBeginPlay()
{
	SequenceCounter = StartIndex;
}
void ATriggerMultiple::MatchStarting()
{
	if (bResetEachRound)
	{
		SequenceCounter = StartIndex;
		bHasBeenTriggered = false;
	}
}
void ATriggerMultiple::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	if (bDebug)
	{
		Log("TriggerMultiple::Trigger(): MT is: " $ mT);
	}
	if (bTriggerOnce && bHasBeenTriggered)
	{
		Return;
	}
	bHasBeenTriggered = true;
	if (bInterruptible)
	{
		if (mT != None)
		{
			mT.StopAllTimers();
		}
		else
		{
			mT = Spawn(Class'MultiTimer');
			mT.SetTimerHost(Self);
		}
	}
	else
	{
		if (mT != None)
		{
			if (bDebug)
			{
				Log("TriggerMultiple::Trigger(): returning because we are not interruptible");
			}
			Return;
		}
		else
		{
			mT = Spawn(Class'MultiTimer');
			mT.SetTimerHost(Self);
		}
	}
	GlobalInstigator = EventInstigator;
	if (GlobalDelay > 0)
	{
		SetTimer(GlobalDelay, false);
	}
	else
	{
		Timer();
	}
	*/
}
void ATriggerMultiple::Timer()
{
	if (bDebug)
	{
		UE_LOG(LogTemp, Warning, TEXT("TriggerMultiple::Timer()"));
	}
	switch(TriggerType)
	{
		case ETriggerType::TT_PlayerProximity:
			StandardEvent();
			break;
		case ETriggerType::TT_PawnProximity:
			RandomEvent();
			break;
		case ETriggerType::TT_ClassProximity:
			SequenceEvent();
			break;
		default:
			break;
	}
}
void ATriggerMultiple::StandardEvent()
{
	int32 i;
	for (i = 0; i < EventList.Max(); i++)
	{
		StartEvent(i);
	}
}
void ATriggerMultiple::RandomEvent()
{
	int32 Num;
	Num = FMath::RandRange(0,EventList.Max());
	StartEvent(Num);
}
void ATriggerMultiple::SequenceEvent()
{
	/*
	StartEvent(SequenceCounter);
	SequenceCounter++;
	if (SequenceCounter >= EventList.Max())
	{
		SequenceCounter = 0;
	}
	*/
}
void ATriggerMultiple::StartEvent(int32 Index)
{
	/*
	if (EventList[Index].bDelay)
	{
		mT.StartTimer(EventList[Index].Name, FRand() * EventList[Index].DelayMax - EventList[Index].DelayMin + EventList[Index].DelayMin);
	}
	else
	{
		TriggerEvent(EventList[Index].Name, Self, GlobalInstigator);
	}
	*/
}
/*
void ATriggerMultiple::TimerNotify(FName TimerName, MultiTimer Timer)
{
	
	local int i;
	i = 0;
	if (i < EventList.Length)
	{
		if (TimerName == EventList[i].Name)
		{
			TriggerEvent(EventList[i].Name, Self, GlobalInstigator);
		}
		else
		{
			i++;
		}
	}
	if (mT != None && !mT.HasTimers())
	{
		if (bDebug)
		{
			Log("TriggerMultiple::TimerNotify(): About to call DestroyMT()");
		}
		DestroyMT();
	}
	
}
*/
void ATriggerMultiple::DestroyMT()
{
	/*
	if (bDebug)
	{
		Log("TriggerMultiple::DestroyMT()");
	}
	mT.Destroy();
	mT = None;
	*/
}
void ATriggerMultiple::Destroyed()
{
	DestroyMT();
}
