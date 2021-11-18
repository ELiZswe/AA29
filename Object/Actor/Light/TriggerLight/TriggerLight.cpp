// All the original content belonged to the US Army


#include "AA29/Object/Actor/Light/TriggerLight/TriggerLight.h"

ATriggerLight::ATriggerLight()
{
	//bStatic = false;
	//bHidden = false;
	//bDynamicLight = true;
	//RemoteRole = 2;
	//bMovable = true;
}


/*
State TriggerTurnsOn
{
	Function Trigger(Actor Other, Pawn EventInstigator)
	{
		if (SavedTrigger != None)
		{
			SavedTrigger.EndEvent();
		}
		SavedTrigger = Other;
		SavedTrigger.BeginEvent();
		Direction = 1;
		Enable('Tick');
	}
}
State TriggerTurnsOff
{
	Function Trigger(Actor Other, Pawn EventInstigator)
	{
		if (SavedTrigger != None)
		{
			SavedTrigger.EndEvent();
		}
		SavedTrigger = Other;
		SavedTrigger.BeginEvent();
		Direction = -1;
		Enable('Tick');
	}
}
State TriggerToggle
{
	Function Trigger(Actor Other, Pawn EventInstigator)
	{
		if (SavedTrigger != None)
		{
			SavedTrigger.EndEvent();
		}
		SavedTrigger = Other;
		SavedTrigger.BeginEvent();
		Direction *= -1;
		Enable('Tick');
	}
}
State TriggerControl
{
	Function UnTrigger(Actor Other, Pawn EventInstigator)
	{
		if (SavedTrigger != None)
		{
			SavedTrigger.EndEvent();
		}
		SavedTrigger = Other;
		SavedTrigger.BeginEvent();
		if (bInitiallyOn)
		{
			Direction = 1;
		}
		else
		{
			Direction = -1;
		}
		Enable('Tick');
	}
	Function Trigger(Actor Other, Pawn EventInstigator)
	{
		if (SavedTrigger != None)
		{
			SavedTrigger.EndEvent();
		}
		SavedTrigger = Other;
		SavedTrigger.BeginEvent();
		if (bInitiallyOn)
		{
			Direction = -1;
		}
		else
		{
			Direction = 1;
		}
		Enable('Tick');
	}
}
State TriggerPound
{
	Function Trigger(Actor Other, Pawn EventInstigator)
	{
		if (SavedTrigger != None)
		{
			SavedTrigger.EndEvent();
		}
		SavedTrigger = Other;
		SavedTrigger.BeginEvent();
		Direction = 1;
		poundTime = ChangeTime;
		SetTimer(ChangeTime,False);
		Enable('Timer');
		Enable('Tick');
	}
	Function Timer()
	{
		if (poundTime >= RemainOnTime)
		{
			Disable('Timer');
		}
		poundTime += ChangeTime;
		Direction *= -1;
		SetTimer(ChangeTime,False);
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
		if (SavedTrigger != None)
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
			if (SavedTrigger != None)
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