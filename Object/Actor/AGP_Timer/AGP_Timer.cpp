// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_Timer/AGP_Timer.h"

// Sets default values
AAGP_Timer::AAGP_Timer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bScreenplayOnly = true;
	//bHidden = true;
	//Texture = Texture'T_AA2_Editor.Engine.AGP_Counter';
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
}


void AAGP_Timer::BeginPlay()
{
	Super::BeginPlay();
	
}


void AAGP_Timer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAGP_Timer::Start(float Time)
{
	/*
	if (Level.debugScreenplay)
	{
		Log("AGP_Timer::Start(" + Time + ")");
	}
	_bValid = true;
	SetTimer(Time, false);
	*/
}
void AAGP_Timer::Finish()
{
	/*
	if (Level.debugScreenplay)
	{
		Log("AGP_Timer::Finish()");
	}
	*/
	_bValid = false;
}
void AAGP_Timer::Timer()
{
	/*
	if (Level.debugScreenplay)
	{
		Log("AGP_Timer::Timer()");
	}
	if (_bValid)
	{
		if (Level.debugScreenplay)
		{
			Log("AGP_Timer::Timer() _bValid == true");
		}
		TriggerEvent(Event, this, Instigator);
		if (_Target != nullptr)
		{
			if (Level.debugScreenplay)
			{
				Log("AGP_Timer::Timer() calling _Target.Notify()");
			}
			_Target.Notify();
		}
	}
	*/
}

void AAGP_Timer::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	Instigator = EventInstigator;
	Start(Delay);
	*/
}

float AAGP_Timer::GetTimeTotal()
{
	return TimerRate;
}

float AAGP_Timer::GetTimeExpended()
{
	return TimerCounter;
}

float AAGP_Timer::GetTimeRemaining()
{
	return TimerRate - TimerCounter;
}

