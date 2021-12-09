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

// Called when the game starts or when spawned
void AMultiTimer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
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
	/*
	local int i;
	local name TempName;
	if (i < TimerEvents.Length)
	{
		if (GetWorld()->GetTimeSeconds() - TimerEvents[i].StartTime >= TimerEvents[i].WaitTime)
		{
			TempName = TimerEvents[i].Name;
			if (!TimerEvents[i].bRepeat)
			{
				TimerEvents.remove(i, 1);
			}
			else
			{
				TimerEvents[i].StartTime = GetWorld()->GetTimeSeconds();
				i++;
			}
			if (Hosts.Length != 0)
			{
				NotifyHosts(TempName, Self);
			}
			Self.TimerNotify(TempName, Self);
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
	/*
	local int i;
	for (i = 0; i < Hosts.Length; i++)
	{
		Hosts[i].TimerNotify(TimerName, Self);
	}
	*/
}
void AMultiTimer::SetTimerEvent(FName Name, float Time, bool bRepeat, AActor* Actor)
{
	/*
	local int i;
	local int Index;
	Index = TimerEvents.Length;
	i = 0;
	if (i < TimerEvents.Length)
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
	if (Index == TimerEvents.Length)
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
	local int i;
	for (i = 0; i < Hosts.Length; i++)
	{
		if (Hosts[i] == Host)
		{
			Log("MultiTimer::SetTimerHost(): Error: Actor " $ Host $ " is already a host of this timer: " $ Self);
			Return;
		}
	}
	Hosts[Hosts.Length] = Host;
	*/
}
void AMultiTimer::RemoveTimerHost(AActor* Host)
{
	/*
	local int i;
	if (i < Hosts.Length)
	{
		if (Hosts[i] == Host)
		{
			Hosts.remove(i, 1);
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
	local int i;
	if (i < TimerEvents.Length)
	{
		if (TimerEvents[i].Name == Name)
		{
			TimerEvents.remove(i, 1);
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
	//TimerEvents.remove(0, TimerEvents.Length);
}
bool AMultiTimer::HasTimers()
{
	return TimerEvents.Num() > 0;
}


