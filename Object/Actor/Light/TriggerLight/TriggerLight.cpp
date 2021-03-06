// All the original content belonged to the US Army

#include "AA29/Object/Actor/Light/TriggerLight/TriggerLight.h"
#include "AA29/Object/Actor/Triggers/Trigger/Trigger.h"

ATriggerLight::ATriggerLight()
{
	bStatic = false;
	//bHidden = false;
	bDynamicLight = true;
	//RemoteRole = 2;
	//bMovable = true;
}

/*
State TriggerTurnsOn
{
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.EndEvent();
		}
		SavedTrigger=Other;
		SavedTrigger.BeginEvent();
		Direction=1;
		Enable("Tick");
	}
}
*/

/*
State TriggerTurnsOff
{
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.EndEvent();
		}
		SavedTrigger=Other;
		SavedTrigger.BeginEvent();
		Direction=-1;
		Enable("Tick");
	}
}
*/

/*
State TriggerToggle
{
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.EndEvent();
		}
		SavedTrigger=Other;
		SavedTrigger.BeginEvent();
		(Direction *= float(-1));
		Enable("Tick");
	}
}
*/

/*
State TriggerControl
{
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.EndEvent();
		}
		SavedTrigger=Other;
		SavedTrigger.BeginEvent();
		if (bInitiallyOn)
		{
			Direction=-1;
		}
		else
		{
			Direction=1;
		}
		Enable("Tick");
	}
	Function UnTrigger(AActor* Other, APawn* EventInstigator)
	{
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.EndEvent();
		}
		SavedTrigger=Other;
		SavedTrigger.BeginEvent();
		if (bInitiallyOn)
		{
			Direction=1;
		}
		else
		{
			Direction=-1;
		}
		Enable("Tick");
	}
}
*/

/*
State TriggerPound
{
	Function Timer()
	{
		if (poundTime >= RemainOnTime)
		{
			Disable("Timer");
		}
		(poundTime += ChangeTime);
		(Direction *= float(-1));
		SetTimer(ChangeTime,false);
	}
	Function Cast<ATrigger>(AActor* Other, APawn* EventInstigator)
	{
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.EndEvent();
		}
		SavedTrigger=Other;
		SavedTrigger.BeginEvent();
		Direction=1;
		poundTime=ChangeTime;
		SetTimer(ChangeTime,false);
		Enable("Timer");
		Enable("Tick");
	}
}
*/

void ATriggerLight::BeginPlay()
{
	/*
	InitialBrightness = LightBrightness;
	if (bInitiallyOn)
	{
		Alpha = 1;
		Direction = 1;
	}
	else
	{
		Alpha = 0;
		Direction = -1;
	}
	SetDrawType(0);
	*/
}

void ATriggerLight::Tick(float DeltaTime)
{
	/*
	Alpha += Direction * DeltaTime / ChangeTime;
	if (Alpha > 1)
	{
		Alpha = 1;
		Disable('Tick');
		if (SavedTrigger != nullptr)
		{
			SavedTrigger.EndEvent();
		}
	}
	else
	{
		if (Alpha < 0)
		{
			Alpha = 0;
			Disable('Tick');
			if (SavedTrigger != nullptr)
			{
				SavedTrigger.EndEvent();
			}
		}
	}
	if (!bDelayFullOn)
	{
		LightBrightness = Alpha * InitialBrightness;
	}
	else
	{
		if (Direction > 0 && Alpha != 1 || Alpha == 0)
		{
			LightBrightness = 0;
		}
		else
		{
			LightBrightness = InitialBrightness;
		}
	}
	*/
}
