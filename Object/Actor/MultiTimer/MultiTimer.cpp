// All the original content belonged to the US Army

#include "AA29/Object/Actor/MultiTimer/MultiTimer.h"

// Sets default values
AMultiTimer::AMultiTimer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//bHidden = true;
	//bAcceptsProjectors = false;
	//bMovable = false;
	//CollisionRadius = 1;
	//CollisionHeight = 1;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
}


void AMultiTimer::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMultiTimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ProcessTimerEvents();
}

void AMultiTimer::TimerNotify(FName TimerName, AMultiTimer* Timer)
{
}

void AMultiTimer::ProcessTimerEvents()
{
	int32 i = 0;
	FName TempName = "";
	/*
	if (i < TimerEvents.Num())
	{
		if (GetWorld()->GetTimeSeconds() - TimerEvents[i].StartTime >= TimerEvents[i].WaitTime)
		{
			TempName = TimerEvents[i].Name;
			if (!TimerEvents[i].bRepeat)
			{
				TimerEvents.RemoveAt(i, 1);
			}
			else
			{
				TimerEvents[i].StartTime = GetWorld()->GetTimeSeconds();
				i++;
			}
			if (Hosts.Num() != 0)
			{
				NotifyHosts(TempName, this);
			}
			Self.TimerNotify(TempName, this);
		}
		else
		{
			i++;
		}
	}
	*/
}

void AMultiTimer::NotifyHosts(FName TimerName, AMultiTimer* Timer)
{
	int32 i = 0;
	for (i = 0; i < Hosts.Num(); i++)
	{
		//Hosts[i]->TimerNotify(TimerName, this);
	}
}

void AMultiTimer::SetTimerEvent(FName Name, float Time, bool bRepeat, AActor* Actor)
{
	int32 i = 0;
	int32 Index = 0;
	/*
	Index = TimerEvents.Num();
	i = 0;
	if (i < TimerEvents.Num())
	{
		if (TimerEvents[i].Name == Name)
		{
			Index = i;
		}
		else
		{
			i++;
		}
	}
	if (Index == TimerEvents.Num())
	{
		TimerEvents.insert(Index, 1);
	}
	TimerEvents[Index].Name = Name;
	TimerEvents[Index].StartTime = GetWorld()->GetTimeSeconds();
	TimerEvents[Index].WaitTime = Time;
	TimerEvents[Index].bRepeat = bRepeat;
	*/
}
void AMultiTimer::SetTimerHost(AActor* Host)
{
	/*
	int32 i = 0;
	for (i = 0; i < Hosts.Num(); i++)
	{
		if (Hosts[i] == Host)
		{
			Log("MultiTimer::SetTimerHost(): Error: Actor " + Host + " is already a host of this timer: " + Self);
			return;
		}
	}
	Hosts[Hosts.Num()] = Host;
	*/
}
void AMultiTimer::RemoveTimerHost(AActor* Host)
{
	/*
	int32 i = 0;
	if (i < Hosts.Num())
	{
		if (Hosts[i] == Host)
		{
			Hosts.RemoveAt(i, 1);
		}
		else
		{
			i++;
		}
	}
	*/
}
void AMultiTimer::StartTimer(FName Name, float Time, bool bRepeat)
{
	SetTimerEvent(Name, Time, bRepeat,nullptr);
}
void AMultiTimer::StopTimer(FName Name)
{
	/*
	int32 i = 0;
	if (i < TimerEvents.Num())
	{
		if (TimerEvents[i].Name == Name)
		{
			TimerEvents.RemoveAt(i, 1);
		}
		else
		{
			i++;
		}
	}
	*/
}
void AMultiTimer::StopAllTimers()
{
	//TimerEvents.RemoveAt(0, TimerEvents.Num());
}
bool AMultiTimer::HasTimers()
{
	return TimerEvents.Num() > 0;
}

